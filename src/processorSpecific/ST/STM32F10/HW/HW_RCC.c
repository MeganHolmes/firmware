
// C Standard Includes
#include "stdbool.h"

// ST Includes
#include "stm32f10x_rcc.h"

// Project Includes
#include "cDefs.h"
#include "HW_RCC.h"
#include "HW_GPIO_projectSpecific.h"
#include "HW_GPIO.h"
#include "HW_ST_type_convert.h"

// Defines

// Private Function Declarations
bool HW_RCC_enablePeripherals(void);
bool HW_RCC_enableGPIOs(void);

// Function Definitions

bool HW_RCC_Init(void)
{
    bool error_detected = false;

    error_detected |= HW_RCC_enablePeripherals();

    return error_detected;
}


bool HW_RCC_enablePeripherals(void)
{
    bool error_detected = false;

#if FEATURE_GPIO
    error_detected |= HW_RCC_enableGPIOs();
#endif // FEATURE_GPIO

    return error_detected;
}

#if FEATURE_GPIO
bool HW_RCC_enableGPIOs(void)
{
    bool error_detected = false;

    for (uint8_t pinIdx = 0; pinIdx < HW_GPIO_COUNT; pinIdx++)
    {
        GPIO_TypeDef* port = HW_GPIO_getPortForGPIOID(pinIdx);
        uint32_t rcc_gpio_periph = HW_ST_type_convert_gpioTypedefToRccAPB2Periph((uint32_t)port);
        if (rcc_gpio_periph == 0u)
        {
            error_detected = true;
            break;
        }

        RCC_APB2PeriphClockCmd(rcc_gpio_periph, ENABLE);
    }

    return error_detected;
}
#endif // FEATURE_GPIO