
// C Standard Includes
#include <stdbool.h>

// ST Includes
#include "stm32f10x_rtc.h"

// Project Includes
#include "HW_RCC.h"


// Defines

// Private Function Declarations
void HW_timer_configure_and_start_rtc();

// Function Definitions

void HW_timer_init(void)
{
    HW_timer_configure_and_start_rtc();
}

void HW_timer_configure_and_start_rtc(void)
{
    const uint32_t sysclk_hz = HW_RCC_get_sysclk_hz();
    const uint32_t prescaler_for_1ms = 1; //(1000*128) / sysclk_hz;

    PWR_BackupAccessCmd(ENABLE);
    RTC_SetPrescaler(prescaler_for_1ms);
    PWR_BackupAccessCmd(DISABLE);
}

uint32_t HW_timer_get_system_time_ms(void)
{
    return RTC_GetCounter();
}
