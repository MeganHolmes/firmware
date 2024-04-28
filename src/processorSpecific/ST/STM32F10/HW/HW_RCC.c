
// C Standard Includes
#include "stdbool.h"

// ST Includes
#include "stm32f10x_rcc.h"

// Project Includes
#include "featureDefines.h"
#include "HW_RCC.h"
#include "HW_GPIO_projectSpecific.h"
#include "HW_GPIO.h"
#include "HW_ST_type_convert.h"

// Defines

// Private Function Declarations
static bool HW_RCC_enablePeripherals(void);
static bool HW_RCC_enableGPIOs(void);

#if FEATURE_RTC
static void HW_RCC_enableRTC(void);
#endif // FEATURE_RTC

// Function Definitions

bool HW_RCC_init(void)
{
    bool error_detected = false;

    RCC->CR |= RCC_CR_HSION;

    while (!(RCC->CR & RCC_CR_HSIRDY))
            ; // wait for the HSIREADY flag

    RCC->CR |= RCC_CR_PLLON;

    while (!(RCC->CR & RCC_CR_PLLRDY))
        ; // wait for the PLLRDY flag

    RCC->CFGR 	|= RCC_CFGR_SW_PLL;

    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL))
        ; // wait for PLL to be CLK

    error_detected |= HW_RCC_enablePeripherals();

    return error_detected;
}

uint32_t HW_RCC_get_sysclk_hz(void)
{
    RCC_ClocksTypeDef clocks;
    RCC_GetClocksFreq(&clocks);
    return clocks.SYSCLK_Frequency;
}

uint32_t HW_RCC_get_pclk1_hz(void)
{
    RCC_ClocksTypeDef clocks;
    RCC_GetClocksFreq(&clocks);
    return clocks.PCLK1_Frequency;
}

static bool HW_RCC_enablePeripherals(void)
{
    bool error_detected = false;

#if FEATURE_RTC
    HW_RCC_enableRTC();
#endif // FEATURE_RTC

#if FEATURE_GPIO
    error_detected |= HW_RCC_enableGPIOs();
#endif // FEATURE_GPIO

    return error_detected;
}

#if FEATURE_GPIO
static bool HW_RCC_enableGPIOs(void)
{
    bool error_detected = false;

    for (uint8_t pinIdx = 0; pinIdx < HW_GPIO_COUNT; pinIdx++)
    {
        GPIO_TypeDef* port = HW_GPIO_getPortForGPIOID(pinIdx);
        uint32_t rcc_gpio_periph = HW_ST_type_convert_gpioTypedefToRccAPB2Periph((uint32_t)port);
        if (rcc_gpio_periph == 0u)
        {
            error_detected = true;
            break;
        }

        RCC_APB2PeriphClockCmd(rcc_gpio_periph, ENABLE);
    }

    return error_detected;
}
#endif // FEATURE_GPIO

#if FEATURE_RTC
static void HW_RCC_enableRTC(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP, ENABLE);
    PWR_BackupAccessCmd(ENABLE);
    RCC_LSICmd(ENABLE);
    RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);
    RCC_RTCCLKCmd(ENABLE);
    PWR_BackupAccessCmd(DISABLE);
}
#endif // FEATURE_RTC