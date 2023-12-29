#ifndef __IO_led_H__
#define __IO_led_H__

// C Standard Includes
#include <stdint.h>
#include <stdbool.h>

// Project Includes
// #include "HW_GPIO_generated.h"
#include "IO_led_projectSpecific.h"

// Defines
#define IO_led_ENABLED  1
#define IO_led_DISABLED 0

// Typedefs
typedef uint32_t IO_led_ID;

typedef struct
{
    HW_GPIO_Pin gpio;
} IO_led_individualData;


void IO_led_init(void);
void IO_led_setEnableStatus(IO_led_ID ledID, bool enable);
void IO_led_setBlinkPeriod(IO_led_ID ledID, uint32_t period);
void IO_led_setBlinkDutyCycle(IO_led_ID ledID, uint32_t dutyCycle);

uint32_t IO_led_getBlinkPeriod(IO_led_ID ledID);
uint32_t IO_led_getBlinkDutyCycle(IO_led_ID ledID);
bool IO_led_isLedEnabled(IO_led_ID ledID);

#endif // __IO_led_H__
