#ifndef __APP_LED_H__
#define __APP_LED_H__

// C Standard Includes
#include <stdint.h>
#include <stdbool.h>

// Project Includes
#include "HW_GPIO_generated.h"
#include "app_led_projectSpecific.h"

// Defines
#define APP_LED_ENABLED  1
#define APP_LED_DISABLED 0

// Typedefs
typedef uint32_t APP_LED_ID;

typedef struct
{
    HW_GPIO_Pin gpio;
} app_led_individualData;


void app_led_init(void);
void app_led_setEnableStatus(APP_LED_ID ledID, bool enable);
void app_led_setBlinkPeriod(APP_LED_ID ledID, uint32_t period);
void app_led_setBlinkDutyCycle(APP_LED_ID ledID, uint32_t dutyCycle);

uint32_t app_led_getBlinkPeriod(APP_LED_ID ledID);
uint32_t app_led_getBlinkDutyCycle(APP_LED_ID ledID);
bool app_led_isLedEnabled(APP_LED_ID ledID);

#endif // __APP_LED_H__
