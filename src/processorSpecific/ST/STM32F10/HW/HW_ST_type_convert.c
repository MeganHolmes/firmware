// C Includes
#include <stdint.h>

// ST Includes
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"

// Function Definitions

uint32_t HW_ST_type_convert_gpioTypedefToRccAPB2Periph(uint32_t gpio)
{
    uint32_t converted_ret = 0u;

    switch (gpio)
    {
        case (uint32_t)GPIOA:
        {
            converted_ret = RCC_APB2Periph_GPIOA;
            break;
        }
        case (uint32_t)GPIOB:
        {
            converted_ret = RCC_APB2Periph_GPIOB;
            break;
        }
        case (uint32_t)GPIOC:
        {
            converted_ret = RCC_APB2Periph_GPIOC;
            break;
        }
        case (uint32_t)GPIOD:
        {
            converted_ret = RCC_APB2Periph_GPIOD;
            break;
        }
        case (uint32_t)GPIOE:
        {
            converted_ret = RCC_APB2Periph_GPIOE;
            break;
        }
        case (uint32_t)GPIOF:
        {
            converted_ret = RCC_APB2Periph_GPIOF;
            break;
        }
        case (uint32_t)GPIOG:
        {
            converted_ret = RCC_APB2Periph_GPIOG;
            break;
        }
        default:
        {
            converted_ret = 0u;
            break;
        }
    }

    return converted_ret;
}

uint32_t HW_ST_type_convert_timerTypedefToRccAPBPeriph(TIM_TypeDef* timer)
{
    uint32_t converted_ret = 0u;

    // pointers are not permitted as case values :(
    if (timer == TIM1)
    {
        converted_ret = RCC_APB2Periph_TIM1;
    }
    else if (timer == TIM2)
    {
        converted_ret = RCC_APB1Periph_TIM2;
    }
    else if (timer == TIM3)
    {
        converted_ret = RCC_APB1Periph_TIM3;
    }
    else if (timer == TIM4)
    {
        converted_ret = RCC_APB1Periph_TIM4;
    }
    else if (timer == TIM5)
    {
        converted_ret = RCC_APB1Periph_TIM5;
    }
    else if (timer == TIM6)
    {
        converted_ret = RCC_APB1Periph_TIM6;
    }
    else if (timer == TIM7)
    {
        converted_ret = RCC_APB1Periph_TIM7;
    }
    else if (timer == TIM8)
    {
        converted_ret = RCC_APB2Periph_TIM8;
    }
    else if (timer == TIM9)
    {
        converted_ret = RCC_APB2Periph_TIM9;
    }
    else if (timer == TIM10)
    {
        converted_ret = RCC_APB2Periph_TIM10;
    }
    else if (timer == TIM11)
    {
        converted_ret = RCC_APB2Periph_TIM11;
    }
    else if (timer == TIM12)
    {
        converted_ret = RCC_APB1Periph_TIM12;
    }
    else if (timer == TIM13)
    {
        converted_ret = RCC_APB1Periph_TIM13;
    }
    else if (timer == TIM14)
    {
        converted_ret = RCC_APB1Periph_TIM14;
    }
    else if (timer == TIM15)
    {
        converted_ret = RCC_APB2Periph_TIM15;
    }
    else if (timer == TIM16)
    {
        converted_ret = RCC_APB2Periph_TIM16;
    }
    else if (timer == TIM17)
    {
        converted_ret = RCC_APB2Periph_TIM17;
    }

    return converted_ret;
}
