
// C Standard Includes
#include "stdbool.h"

// ST includes

// Project Includes
#include "HW_timer_datatypes.h"
#include "HW_timer_projectSpecific.h"

const HW_Timer_Data hw_timer_config[HW_TIMER_COUNT] =
{
    [HW_TIMER_SYSTEM_CLK] =
    {
        .peripheral = TIM2,
        .increment_time_us = 1000u,
        .delay_start = false,
    },
};