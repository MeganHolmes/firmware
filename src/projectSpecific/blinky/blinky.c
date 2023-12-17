
// C Standard Includes
#include <stdint.h>
#include <stdbool.h>

// Project Includes
// #include "HW_GPIO.h"
// #include "app_led.h"
// #include "app_led_heartbeat.h"

// #include "stm32f10x_gpio.h"

int main(void)
{
    // HW_GPIO_init();
    // app_led_init();
    uint64_t counter = 0;
    // GPIO_InitTypeDef gpio_init;
    // GPIO_StructInit(&gpio_init);
    // gpio_init.GPIO_Mode = GPIO_Mode_Out_PP;

    // GPIO_Init(GPIOA, &gpio_init);
    // GPIO_Init(GPIOB, &gpio_init);
    // GPIO_Init(GPIOC, &gpio_init);
    // GPIO_Init(GPIOD, &gpio_init);
    // GPIO_Init(GPIOE, &gpio_init);
    // GPIO_Init(GPIOF, &gpio_init);
    // GPIO_Init(GPIOG, &gpio_init);
    while (true)
    {
        counter++;

    //     // if (counter > 100000000 == 0)
    //     {
    //         GPIO_WriteBit(GPIOA, GPIO_Pin_All, Bit_SET);
    //         GPIO_WriteBit(GPIOB, GPIO_Pin_All, Bit_SET);
    //         GPIO_WriteBit(GPIOC, GPIO_Pin_All, Bit_SET);
    //         GPIO_WriteBit(GPIOD, GPIO_Pin_All, Bit_SET);
    //         GPIO_WriteBit(GPIOE, GPIO_Pin_All, Bit_SET);
    //         GPIO_WriteBit(GPIOF, GPIO_Pin_All, Bit_SET);
    //         GPIO_WriteBit(GPIOG, GPIO_Pin_All, Bit_SET);
    //     }
    }
}
