
#ifndef __HW_TIMER_H__
#define __HW_TIMER_H__

// C includes
#include <stdint.h>
#include <stdbool.h>

// Project Includes
#include "HW_timer_projectSpecific.h"

// Public Functions

void HW_timer_init(void);
uint32_t HW_timer_get_system_time_ms(void);
void HW_timer_start_timer(HW_TIMER_IDX timerIdx);

#endif // __HW_GPIO_H__
