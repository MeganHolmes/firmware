// C Includes
#include <stdbool.h>
#include <stdint.h>
// #include <stdlib.h>

// RTOS Includes
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

// Project Includes
#include "universal_include.h"
#include "RTOS_task.h"

// Defines


/* Dimensions of the buffer that the task being created will use as its stack.
NOTE:  This is the number of words the stack will hold, not the number of
bytes.  For example, if each stack item is 32-bits, and this is set to 100,
then 400 bytes (100 * 32-bits) will be allocated. */
#define STACK_SIZE 1024

static const uint16_t RTOS_task_1ms_frequency = 1u / portTICK_PERIOD_MS;
static const uint16_t RTOS_task_10ms_frequency = 10u / portTICK_PERIOD_MS;
static const uint16_t RTOS_task_100ms_frequency = 100u / portTICK_PERIOD_MS;
static const uint16_t RTOS_task_1000ms_frequency = 1000u / portTICK_PERIOD_MS;

static StaticTask_t xTaskBuffer;
static StackType_t xStack[ STACK_SIZE ];

// Function Declarations
void RTOS_task_1ms(void *args);
void RTOS_task_10ms(void *args);
void RTOS_task_100ms(void *args);
void RTOS_task_1000ms(void *args);

// Function definitions

int main(void)
{
    RTOS_task_init();

    // xTaskCreate(RTOS_task_1ms, "RTOS_task_1ms", STACK_DEPTH, (void*)&RTOS_task_1ms_frequency,
    //             configMAX_PRIORITIES-1, NULL);
    // xTaskCreate(RTOS_task_10ms, "RTOS_task_10ms", STACK_DEPTH, (void*)&RTOS_task_10ms_frequency,
    //             configMAX_PRIORITIES-2, NULL);
    // xTaskCreate(RTOS_task_100ms, "RTOS_task_100ms", STACK_DEPTH, (void*)&RTOS_task_100ms_frequency,
    //             configMAX_PRIORITIES-3, NULL);
    xTaskCreateStatic(RTOS_task_1000ms, "RTOS_task_1000ms", STACK_SIZE, (void*)&RTOS_task_1000ms_frequency,
                configMAX_PRIORITIES-4, xStack, &xTaskBuffer);

    // BaseType_t xTaskCreate( TaskFunction_t pxTaskCode,
    //                         const char * const pcName, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
    //                         const configSTACK_DEPTH_TYPE usStackDepth,
    //                         void * const pvParameters,
    //                         UBaseType_t uxPriority,
    //                         TaskHandle_t * const pxCreatedTask ) PRIVILEGED_FUNCTION;

                    // TaskHandle_t xTaskCreateStatic( TaskFunction_t pxTaskCode,
                    //                 const char * const pcName, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                    //                 const uint32_t ulStackDepth,
                    //                 void * const pvParameters,
                    //                 UBaseType_t uxPriority,
                    //                 StackType_t * const puxStackBuffer,
                    //                 StaticTask_t * const pxTaskBuffer ) PRIVILEGED_FUNCTION;

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

// Below function is copied from https://github.com/aws/amazon-freertos/blob/a126b0c55795be5986f86d4f6ef73bc5ed091c29/demos/demo_runner/aws_demo.c#L73

/* configUSE_STATIC_ALLOCATION is set to 1, so the application must provide an
 * implementation of vApplicationGetIdleTaskMemory() to provide the memory that is
 * used by the Idle task. */
void vApplicationGetIdleTaskMemory( StaticTask_t ** ppxIdleTaskTCBBuffer,
                                    StackType_t ** ppxIdleTaskStackBuffer,
                                    uint32_t * pulIdleTaskStackSize )
{
    /* If the buffers to be provided to the Idle task are declared inside this
     * function then they must be declared static - otherwise they will be allocated on
     * the stack and so not exists after this function exits. */
    static StaticTask_t xIdleTaskTCB;
    static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle
     * task's state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task's stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
     * Note that, as the array is necessarily of type StackType_t,
     * configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

// TODO: Do something useful here
void vApplicationStackOverflowHook( TaskHandle_t xTask,
                                    char * pcTaskName )
{
    UNUSED(xTask);
    UNUSED(pcTaskName);
    uint64_t time_stuck = 0;

    while (true)
    {
        time_stuck++;
    }
}

void RTOS_task_1ms(void *args)
{
    UNUSED(args);

    while(true)
    {
        RTOS_task_HW_1ms();
        RTOS_task_IO_1ms();
        RTOS_task_app_1ms();
    }
}

void RTOS_task_10ms(void *args)
{
    UNUSED(args);

    while(true)
    {
        RTOS_task_HW_10ms();
        RTOS_task_IO_10ms();
        RTOS_task_app_10ms();
    }
}

void RTOS_task_100ms(void *args)
{
    UNUSED(args);

    while(true)
    {
        RTOS_task_HW_100ms();
        RTOS_task_IO_100ms();
        RTOS_task_app_100ms();
    }
}

void RTOS_task_1000ms(void *args)
{
    const uint16_t run_frequency_ms = *(uint16_t*)args;
    uint32_t task_last_wake_time = xTaskGetTickCount();

    while(true)
    {
        RTOS_task_HW_1000ms();
        RTOS_task_IO_1000ms();
        RTOS_task_app_1000ms();

        vTaskDelayUntil(&task_last_wake_time, run_frequency_ms);
    }
}