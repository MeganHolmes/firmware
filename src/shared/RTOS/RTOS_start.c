// C Includes
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

// RTOS Includes
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

// Project Includes
#include "universal_include.h"
#include "RTOS_task.h"

// Defines

#define STACK_DEPTH 128
static const uint16_t RTOS_task_1ms_frequency = 1u;
static const uint16_t RTOS_task_10ms_frequency = 10u;
static const uint16_t RTOS_task_100ms_frequency = 100u;
static const uint16_t RTOS_task_1000ms_frequency = 1000u;

int main(void)
{
    RTOS_task_init();

    xTaskCreate(RTOS_task_1ms, "RTOS_task_1ms", STACK_DEPTH, (void*)&RTOS_task_1ms_frequency,
                configMAX_PRIORITIES-1, NULL);
    xTaskCreate(RTOS_task_10ms, "RTOS_task_10ms", STACK_DEPTH, (void*)&RTOS_task_10ms_frequency,
                configMAX_PRIORITIES-2, NULL);
    xTaskCreate(RTOS_task_100ms, "RTOS_task_100ms", STACK_DEPTH, (void*)&RTOS_task_100ms_frequency,
                configMAX_PRIORITIES-3, NULL);
    xTaskCreate(RTOS_task_1000ms, "RTOS_task_1000ms", STACK_DEPTH, (void*)&RTOS_task_1000ms_frequency,
                configMAX_PRIORITIES-4, NULL);

    // Start the scheduler.
    vTaskStartScheduler();

    // This should never be reached; the FreeRTOS scheduler
    // should be in charge of the program's execution after starting.
    while (1) {}
    return 0;

}

void vAssertCalled( unsigned long ulLine, const char * const pcFileName )
{
volatile uint32_t ulSetToNonZeroInDebuggerToContinue = 0;

    /* Parameters are not used. */
    ( void ) ulLine;
    ( void ) pcFileName;

    taskENTER_CRITICAL();
    {
        /* You can step out of this function to debug the assertion by using
        the debugger to set ulSetToNonZeroInDebuggerToContinue to a non-zero
        value. */
        while( ulSetToNonZeroInDebuggerToContinue == 0 )
        {
        }
    }
    taskEXIT_CRITICAL();
}