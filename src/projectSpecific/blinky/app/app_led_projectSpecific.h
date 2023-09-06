#ifndef __APP_LED_PROJECTSPECIFIC_H__
#define __APP_LED_PROJECTSPECIFIC_H__

#include "HW_GPIO_generated.h"
#include "app_led.h"

enum APP_LED_ID
{
    APP_LED_NUCLEO_LED,
    APP_LED_COUNT
};

// setup the config to be loaded during init
static const app_led_individualData app_led_projectSpecific_config[APP_LED_COUNT] =
{
    [APP_LED_NUCLEO_LED] =
    {
        .gpio = HW_GPIO_NUCLEO_LED
    }
};


#endif // __APP_LED_PROJECTSPECIFIC_H__
