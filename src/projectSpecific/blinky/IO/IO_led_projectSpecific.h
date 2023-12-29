#ifndef __IO_LED_PROJECTSPECIFIC_H__
#define __IO_LED_PROJECTSPECIFIC_H__

// #include "HW_GPIO_generated.h"
#include "IO_led.h"

enum IO_LED_ID
{
    IO_LED_NUCLEO_LED,
    IO_LED_COUNT
};

// setup the config to be loaded during init
static const IO_led_individualData IO_led_projectSpecific_config[IO_LED_COUNT] =
{
    [IO_led_NUCLEO_LED] =
    {
        .gpio = HW_GPIO_NUCLEO_LED
    }
};


#endif // __IO_LED_PROJECTSPECIFIC_H__
