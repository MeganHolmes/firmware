

// Includes
#include "app_led.h"

typedef struct
{
    app_led_individualData led[APP_LED_COUNT];
} app_led_data;

static app_led_data app_led;

void app_led_init(void)
{
    for (uint32_t ledID = 0; ledID < APP_LED_COUNT; ledID++)
    {
        app_led.led[ledID].gpio = app_led_projectSpecific_config[ledID].gpio;
    }
}

void app_led_setEnableStatus(APP_LED_ID ledID, bool enable)
{

}

void app_led_setBlinkPeriod(APP_LED_ID ledID, uint32_t period)
{

}

void app_led_setBlinkDutyCycle(APP_LED_ID ledID, uint32_t dutyCycle)
{

}

uint32_t app_led_getBlinkPeriod(APP_LED_ID ledID)
{
    return 0;
}

uint32_t app_led_getBlinkDutyCycle(APP_LED_ID ledID)
{
    return 0;
}

bool app_led_isLedEnabled(APP_LED_ID ledID)
{
    return false;
}
