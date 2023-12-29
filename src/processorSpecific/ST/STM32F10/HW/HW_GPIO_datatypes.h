
#ifndef __HW_GPIO_DATATYPES_H__
#define __HW_GPIO_DATATYPES_H__

#include "stm32f10x.h"

typedef struct
{
    GPIO_InitTypeDef pinData;
    GPIO_TypeDef* port;
    BitAction defaultState;
} HW_GPIO_Data;

#endif // __HW_GPIO_DATATYPES_H__