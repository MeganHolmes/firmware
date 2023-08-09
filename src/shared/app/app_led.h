#ifndef __APP_LED_H__
#define __APP_LED_H__

// Includes
#include <stdint.h>
#include <stdbool.h>


// Defines
#define APP_LED_ENABLED 1
#define APP_LED_DISABLED 0

// Typedefs
typedef uint32_t APP_LED_ID;

typedef struct
{
    IO_GPIO gpio;
    uint32_t blinkPeriod;
    uint32_t blinkDutyCycle;
    bool enabled;
} app_led_data;

void app_led_init();
void app_led_setEnableStatus(APP_LED_ID ledID, bool enable);
void app_led_setBlinkPeriod(APP_LED_ID ledID, uint32_t period);
void app_led_setBlinkDutyCycle(APP_LED_ID ledID, uint32_t dutyCycle);

uint32_t app_led_getBlinkPeriod(APP_LED_ID ledID);
uint32_t app_led_getBlinkDutyCycle(APP_LED_ID ledID);
bool app_led_isLedEnabled(APP_LED_ID ledID);

#endif // __APP_LED_H__
