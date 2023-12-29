// C Standard Includes
#include <stdint.h>
#include <stdbool.h>

// Project Includes
#include "HW_RCC.h"
#include "HW_GPIO.h"
// #include "app_led.h"
// #include "app_led_heartbeat.h"

int main(void)
{
    bool error_present = false;

    error_present |= HW_RCC_Init();
    HW_GPIO_Init();

    volatile uint64_t counter = 0;
    volatile bool pin_is_on = false;

    // RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    // GPIOA->CRL = 0x22222222; // All GPIOs are output push-pull at 2MHz
    // GPIOA->CRH = 0x22222222; // All GPIOs are output push-pull at 2MHz

    while (true)
    {
        counter++;

        if (counter >= 1000000)
        {
            if (pin_is_on)
            {
                // GPIOA->BSRR = 0xFFFF; // RESET
                pin_is_on = false;
            }
            else
            {
                // GPIOA->BRR = 0xFFFF; // Set
                pin_is_on = true;
            }
            HW_GPIO_setEnableStatus(HW_GPIO_NUCLEO_LED, pin_is_on);
            counter = 0;
        }
    }
}
