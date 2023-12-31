

// Project Includes
#include "app_heartbeat.h"
#include "HW_GPIO.h"
#include "featureDefines.h"

// Defines

extern HW_GPIO_Pin heartbeat_led_config;

// Private function declarations

void app_heartbeat_led(void);

// Function Definitions

void app_heartbeat_run(void)
{

#if FEATURE_LED_HEARTBEAT
    app_heartbeat_led();
#ifndef HEARTBEAT_OUTPUT_DEFINED
#define HEARTBEAT_OUTPUT_DEFINED 1U
#endif // HEARTBEAT_OUTPUT_DEFINED
#endif // FEATURE_LED_HEARTBEAT

}

void app_heartbeat_led(void)
{
    HW_GPIO_togglePin(heartbeat_led_config);
}


#ifndef HEARTBEAT_OUTPUT_DEFINED
#error "At least one heartbeat feature must be enabled for app_heartbeat"
#endif