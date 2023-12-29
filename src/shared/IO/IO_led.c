

// Includes
#include "IO_led.h"

typedef struct
{
    IO_led_individualData led[IO_led_COUNT];
} IO_led_data;

static IO_led_data IO_led;

void IO_led_init(void)
{
    for (uint32_t ledID = 0; ledID < IO_led_COUNT; ledID++)
    {
        IO_led.led[ledID].gpio = IO_led_projectSpecific_config[ledID].gpio;
    }
}

void IO_led_setEnableStatus(IO_led_ID ledID, bool enable)
{

}

void IO_led_setBlinkPeriod(IO_led_ID ledID, uint32_t period)
{

}

void IO_led_setBlinkDutyCycle(IO_led_ID ledID, uint32_t dutyCycle)
{

}

uint32_t IO_led_getBlinkPeriod(IO_led_ID ledID)
{
    return 0;
}

uint32_t IO_led_getBlinkDutyCycle(IO_led_ID ledID)
{
    return 0;
}

bool IO_led_isLedEnabled(IO_led_ID ledID)
{
    return false;
}
