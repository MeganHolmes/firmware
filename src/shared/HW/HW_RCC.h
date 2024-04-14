#ifndef __HW_RCC_H__
#define __HW_RCC_H__

// C includes

// Project Includes

// Public Functions

bool HW_RCC_init(void);
uint32_t HW_RCC_get_sysclk_hz(void);
uint32_t HW_RCC_get_pclk1_hz(void);

#endif // __HW_RCC_H__
