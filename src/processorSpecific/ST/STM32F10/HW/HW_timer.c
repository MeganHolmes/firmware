
// C Standard Includes
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

// ST Includes
#include "stm32f10x.h"

// Project Includes
#include "HW_RCC.h"
#include "HW_timer.h"
#include "HW_timer_datatypes.h"
#include "HW_ST_type_convert.h"
#include "featureDefines.h"
#include "HW_timer_projectSpecific.h"


// Defines
#define MAX_VALUE_16_BIT 65535

#define MICROSECONDS_TO_HZ(us) 1000000 / us

#define TIM_UIF 0x01

#define TIM_CKD_DIV1 0x000
#define TIM_CKD_DIV2 0x100
#define TIM_CKD_DIV4 0x200

// Static data
static uint16_t system_timer_overflow_count = 0u;

extern HW_Timer_Data hw_timer_config[HW_TIMER_COUNT];


// Private Function Declarations
#if FEATURE_RTC
static void HW_timer_configure_rtc();
#endif
static bool hw_timer_calculatePrescalerAndDivider(const uint32_t input_frequency_hz, const uint32_t output_frequency_hz, uint16_t* prescaler, uint16_t* divider);

// Function Definitions

void HW_timer_init(void)
{
#if FEATURE_RTC
    HW_timer_configure_rtc();
#endif

    for (uint8_t timerIdx = 0; timerIdx < HW_TIMER_COUNT; timerIdx++)
    {
        // Enable the RCC clock for each timer being used
        if (HW_ST_TYPE_CONVERT_IS_TIMER_APB1(hw_timer_config[timerIdx].peripheral))
        {
            RCC->APB1ENR |= HW_ST_type_convert_timerTypedefToRccAPBPeriph(hw_timer_config[timerIdx].peripheral);
        }
        else
        {
            RCC->APB2ENR |= HW_ST_type_convert_timerTypedefToRccAPBPeriph(hw_timer_config[timerIdx].peripheral);
        }

        // Calculate the timer parameters
        const uint32_t input_frequency = HW_RCC_get_pclk1_hz();
        uint16_t prescaler = 1u;
        uint16_t divider = TIM_CKD_DIV1;
        const uint32_t output_frequency = MICROSECONDS_TO_HZ(hw_timer_config[timerIdx].increment_time_us);

        hw_timer_calculatePrescalerAndDivider(input_frequency, output_frequency, &prescaler, &divider);

        hw_timer_config[timerIdx].peripheral->CR1 |= 1u;
        hw_timer_config[timerIdx].peripheral->CR1 |= divider;
        hw_timer_config[timerIdx].peripheral->PSC |= prescaler;
        hw_timer_config[timerIdx].peripheral->ARR |= 0xffff;

        if (false == hw_timer_config[timerIdx].delay_start)
        {
            HW_timer_start_timer(timerIdx);
        }
    }
}

static bool hw_timer_calculatePrescalerAndDivider(const uint32_t input_frequency_hz, const uint32_t output_frequency_hz, uint16_t* prescaler, uint16_t* divider)
{
    bool error_detected = false;

    const uint32_t scale = input_frequency_hz / output_frequency_hz;
    uint8_t divider_raw = 1;
    *prescaler = MAX_VALUE_16_BIT;

    // Divider should be rounded up.
    divider_raw = scale / *prescaler;
    divider_raw += (0u != scale % *prescaler);

    // 1,2, and 4 are only valid values
    divider_raw += (3u == divider_raw);

    double integer_component = 0.0f;
    const float remainder = (float)modf((float)scale / (float)divider_raw, &integer_component);

    *prescaler = (remainder < 0.5f) ? (uint16_t)integer_component : (uint16_t)integer_component+1;

    switch(divider_raw)
    {
        case 1u:
        {
            *divider = TIM_CKD_DIV1;
            break;
        }
        case 2u:
        {
            *divider = TIM_CKD_DIV2;
            break;
        }
        case 4u:
        {
            *divider = TIM_CKD_DIV4;
            break;
        }
        default:
        {
            error_detected = true;
        }
    }

    return error_detected;
}

void HW_timer_start_timer(HW_TIMER_IDX timerIdx)
{
    hw_timer_config[timerIdx].peripheral->CR1 |= 1u;
}

uint32_t HW_timer_get_system_time_ms(void)
{
    uint32_t system_time = 0u;
#if FEATURE_RTC
    system_time = RTC_GetCounter();
#else
    const bool interrupt_set = hw_timer_config[HW_TIMER_SYSTEM_CLK].peripheral->SR & 1u;

    if (interrupt_set)
    {
        system_timer_overflow_count++;
        hw_timer_config[HW_TIMER_SYSTEM_CLK].peripheral->SR &= ~TIM_UIF; // clear interrupt
    }

    system_time = system_timer_overflow_count*MAX_VALUE_16_BIT + hw_timer_config[HW_TIMER_SYSTEM_CLK].peripheral->CNT;
#endif
    return system_time;
}

#if FEATURE_RTC
static void HW_timer_configure_rtc(void)
{
    const uint32_t sysclk_hz = HW_RCC_get_sysclk_hz();
    const uint32_t prescaler_for_1ms = 1; //(1000*128) / sysclk_hz;

    PWR_BackupAccessCmd(ENABLE);
    RTC_SetPrescaler(prescaler_for_1ms);
    PWR_BackupAccessCmd(DISABLE);
}
#endif // FEATURE_RTC