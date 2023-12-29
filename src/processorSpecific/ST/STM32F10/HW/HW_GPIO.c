
// C Standard Includes

// ST Includes
#include "stm32f10x_gpio.h"

// Project Includes
#include "HW_GPIO.h"

// Defines
extern HW_GPIO_Data hw_gpio_config[HW_GPIO_COUNT];

// Function Definitions

void HW_GPIO_Init(void)
{
    for (uint8_t pinIdx = 0; pinIdx < HW_GPIO_COUNT; pinIdx++)
    {
        // Below pointer cast is to silence warning about hw_gpio_config being a const.
        GPIO_Init(hw_gpio_config[pinIdx].port, (GPIO_InitTypeDef*) &hw_gpio_config[pinIdx].pinData);
        GPIO_WriteBit(hw_gpio_config[pinIdx].port, hw_gpio_config[pinIdx].pinData.GPIO_Pin, hw_gpio_config[pinIdx].defaultState);
    }
}

void HW_GPIO_setEnableStatus(HW_GPIO_Pin pinID, bool enable)
{
    GPIO_WriteBit(hw_gpio_config[pinID].port, hw_gpio_config[pinID].pinData.GPIO_Pin, (BitAction) enable);
}

GPIO_TypeDef* HW_GPIO_getPortForGPIOID(HW_GPIO_Pin pinID)
{
    return hw_gpio_config[pinID].port;
}