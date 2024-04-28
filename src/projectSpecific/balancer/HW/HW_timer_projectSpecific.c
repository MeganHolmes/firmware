
// C Standard Includes
#include "stdbool.h"

// ST includes
#include "stm32f10x_tim.h"

// Project Includes
#include "HW_timer_datatypes.h"
#include "HW_timer_projectSpecific.h"

const HW_Timer_Data hw_timer_config[HW_TIMER_COUNT] =
{
    [HW_TIMER_SYSTEM_CLK] =
    {
        .peripheral = TIM2,
        .channel = TIM_Channel_1,
        .increment_time_us = 1000u,
        .delay_start = false,
    },
};