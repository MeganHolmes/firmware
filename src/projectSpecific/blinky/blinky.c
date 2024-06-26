// C Standard Includes
#include <stdint.h>
#include <stdbool.h>

// Project Includes
#include "HW_RCC.h"
#include "HW_GPIO.h"
#include "app_heartbeat.h"


int main(void)
{
    bool error_present = false;

    error_present |= HW_RCC_init();
    HW_GPIO_init();

    uint64_t counter = 0;

    while (true)
    {
        counter++;

        if (counter >= 1000000) // This isn't 1 second but for this demo it doesn't matter
        {
            app_heartbeat_run();
            counter = 0;
        }
    }
}
