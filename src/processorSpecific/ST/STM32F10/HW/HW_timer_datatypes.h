
#ifndef __HW_TIMER_DATATYPES_H__
#define __HW_TIMER_DATATYPES_H__

#include "stm32f10x.h"

typedef struct
{
    TIM_TypeDef* peripheral;
    uint16_t channel;
    uint32_t increment_time_us;
    bool     delay_start;
} HW_Timer_Data;

#endif // __HW_TIMER_DATATYPES_H__