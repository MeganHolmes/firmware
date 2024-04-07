// This file is a poor-woman's RTOS. Bringing up FreeRTOS for the first time is challenging (but worth it) and my job is in crunch right now.
// This makes troubleshooting RTOS issues not very motivating, so to unblock myself I made this simple executor. I plan to complete the RTOS
// bringup after job crunch is over and morale after work hours is higher.

// System Includes
#include <stdbool.h>
#include <stdint.h>

// Project Includes
#include "featureDefines.h"

#include "HW_RCC.h"
#include "HW_timer.h"
#include "HW_GPIO.h"

#include "app_heartbeat.h"

// Defines
#define TIME_10MS 10u
#define TIME_100MS 100u
#define TIME_1000MS 1000u

// Enums

// Structs
typedef struct
{
    uint64_t last_10ms_timestamp;
    uint64_t last_100ms_timestamp;
    uint64_t last_1000ms_timestamp;
}IO_taskExecutor_data;


// Define private data
static IO_taskExecutor_data IO_taskExecutor_private_data;

// Private function declarations

bool IO_taskExecutor_HW_init(void);
void IO_taskExecutor_IO_init(void);
void IO_taskExecutor_app_init(void);

void IO_taskExecutor_1ms(void);
void IO_taskExecutor_10ms(void);
void IO_taskExecutor_100ms(void);
void IO_taskExecutor_1000ms(void);

void IO_taskExecutor_HW_1ms(void);
void IO_taskExecutor_HW_10ms(void);
void IO_taskExecutor_HW_100ms(void);
void IO_taskExecutor_HW_1000ms(void);

void IO_taskExecutor_IO_1ms(void);
void IO_taskExecutor_IO_10ms(void);
void IO_taskExecutor_IO_100ms(void);
void IO_taskExecutor_IO_1000ms(void);

void IO_taskExecutor_app_1ms(void);
void IO_taskExecutor_app_10ms(void);
void IO_taskExecutor_app_100ms(void);
void IO_taskExecutor_app_1000ms(void);


// Function Definitions

int main(void)
{
    IO_taskExecutor_HW_init();
    IO_taskExecutor_IO_init();
    IO_taskExecutor_app_init();

    while (true)
    {
        // Assume 1ms always needs to run.
        IO_taskExecutor_1ms();

        volatile uint32_t current_time = HW_timer_get_system_time_ms();

        if (TIME_10MS <= (current_time - IO_taskExecutor_private_data.last_10ms_timestamp))
        {
            IO_taskExecutor_private_data.last_10ms_timestamp = current_time;
            IO_taskExecutor_10ms();
        }

        if (TIME_100MS <= (current_time - IO_taskExecutor_private_data.last_100ms_timestamp))
        {
            IO_taskExecutor_private_data.last_100ms_timestamp = current_time;
            IO_taskExecutor_100ms();
        }

        if (TIME_1000MS <= (current_time - IO_taskExecutor_private_data.last_1000ms_timestamp))
        {
            IO_taskExecutor_private_data.last_1000ms_timestamp = current_time;
            IO_taskExecutor_1000ms();
        }
    }

    return 1;
}

bool IO_taskExecutor_HW_init(void)
{
    bool error_present = false;

#if FEATURE_RCC
    error_present |= HW_RCC_init();
#endif

#if FEATURE_TIMER
    HW_timer_init();
#endif

#if FEATURE_GPIO
    HW_GPIO_init();
#endif

    return error_present;
}

void IO_taskExecutor_IO_init(void)
{

}

void IO_taskExecutor_app_init(void)
{

}


void IO_taskExecutor_1ms(void)
{
    IO_taskExecutor_HW_1ms();
    IO_taskExecutor_IO_1ms();
    IO_taskExecutor_app_1ms();
}

void IO_taskExecutor_10ms(void)
{
    IO_taskExecutor_HW_10ms();
    IO_taskExecutor_IO_10ms();
    IO_taskExecutor_app_10ms();
}

void IO_taskExecutor_100ms(void)
{
    IO_taskExecutor_HW_100ms();
    IO_taskExecutor_IO_100ms();
    IO_taskExecutor_app_100ms();
}

void IO_taskExecutor_1000ms(void)
{
    IO_taskExecutor_HW_1000ms();
    IO_taskExecutor_IO_1000ms();
    IO_taskExecutor_app_1000ms();
}


void IO_taskExecutor_HW_1ms(void)
{

}

void IO_taskExecutor_HW_10ms(void)
{

}

void IO_taskExecutor_HW_100ms(void)
{

}

void IO_taskExecutor_HW_1000ms(void)
{

}


void IO_taskExecutor_IO_1ms(void)
{

}

void IO_taskExecutor_IO_10ms(void)
{

}

void IO_taskExecutor_IO_100ms(void)
{

}

void IO_taskExecutor_IO_1000ms(void)
{

}


void IO_taskExecutor_app_1ms(void)
{

}

void IO_taskExecutor_app_10ms(void)
{

}

void IO_taskExecutor_app_100ms(void)
{

}

void IO_taskExecutor_app_1000ms(void)
{
#if FEATURE_HEARTBEAT
    app_heartbeat_run();
#endif
}
