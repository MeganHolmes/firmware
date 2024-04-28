// C Standard Includes
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// Project Includes
#include "HW_RCC.h"
#include "HW_GPIO.h"
#include "app_heartbeat.h"

#define TEST_STACK_SIZE 128U

static uint32_t testarr[TEST_STACK_SIZE];


int main(void)
{
    bool error_present = false;

    error_present |= HW_RCC_init();
    HW_GPIO_init();

    uint64_t counter = 0;

    // This exists to ensure mem functions aren't broken
    memset(testarr, 0x00, TEST_STACK_SIZE*sizeof(uint32_t));

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
