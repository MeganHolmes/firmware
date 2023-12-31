// Project Includes
#include "HW_GPIO_projectSpecific.h"

const HW_GPIO_Data hw_gpio_config[HW_GPIO_COUNT] =
{
    [HW_GPIO_NUCLEO_LED] =
    {
        .pinData =
        {
            .GPIO_Pin = GPIO_Pin_5,
            .GPIO_Speed = GPIO_Speed_2MHz,
            .GPIO_Mode = GPIO_Mode_Out_PP,
        },
        .port = GPIOA,
        .defaultState = Bit_SET,
    },
};