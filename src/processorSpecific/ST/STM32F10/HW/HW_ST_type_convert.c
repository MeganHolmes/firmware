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

    if (timer == TIM1)
    {
        converted_ret = RCC_APB2ENR_TIM1EN;
    }
    else if (timer == TIM2)
    {
        converted_ret = RCC_APB1ENR_TIM2EN;
    }
    else if (timer == TIM3)
    {
        converted_ret = RCC_APB1ENR_TIM3EN;
    }
    else if (timer == TIM4)
    {
        converted_ret = RCC_APB1ENR_TIM4EN;
    }

    return converted_ret;
}
