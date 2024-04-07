
#ifndef __HW_TIMER_H__
#define __HW_TIMER_H__

// C includes
#include <stdint.h>
#include <stdbool.h>

// Project Includes

// Public Functions

void HW_timer_init(void);
uint32_t HW_timer_get_system_time_ms(void);

#endif // __HW_GPIO_H__
