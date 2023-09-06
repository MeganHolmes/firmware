
// C Standard Includes
#include <stdint.h>
#include <stdbool.h>

// Project Includes
// #include "HW_GPIO.h"
// #include "app_led.h"
// #include "app_led_heartbeat.h"

#include "stm32f10x_gpio.h"

int main(void)
{
    // HW_GPIO_init();
    // app_led_init();
    uint64_t counter = 0;
    while (true)
    {
        counter++;

        if (counter % 1000000 == 0)
        {
            GPIO_WriteBit(GPIOA, GPIO_Pin_5, !GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_5));
        }
    }
}
