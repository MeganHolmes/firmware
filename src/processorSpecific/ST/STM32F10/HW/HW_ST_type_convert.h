#ifndef __HW_ST_TYPE_CONVERSIONS_H__
#define __HW_ST_TYPE_CONVERSIONS_H__

// Includes
#include <stdint.h>

// Defines
#define HW_ST_TYPE_CONVERT_IS_TIMER_APB1(PERIPH) (((PERIPH) == TIM1) || \
                                                  ((PERIPH) == TIM8) || \
                                                  ((PERIPH) == TIM9) || \
                                                  ((PERIPH) == TIM10)|| \
                                                  ((PERIPH) == TIM15)|| \
                                                  ((PERIPH) == TIM16)|| \
                                                  ((PERIPH) == TIM17))

// Function Declarations

uint32_t HW_ST_type_convert_gpioTypedefToRccAPB2Periph(uint32_t gpio);
uint32_t HW_ST_type_convert_timerTypedefToRccAPBPeriph(TIM_TypeDef* timer);


#endif // __HW_ST_TYPE_CONVERSIONS_H__