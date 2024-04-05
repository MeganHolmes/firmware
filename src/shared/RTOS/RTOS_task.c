// C includes
#include <stdbool.h>
#include <stdlib.h>

// Project includes
#include "universal_include.h"
#include "featureDefines.h"
#include "HW_GPIO.h"
#include "HW_RCC.h"
#include "app_heartbeat.h"

// Defines

// Function declarations
bool RTOS_task_HW_init(void);
void RTOS_task_IO_init(void);
void RTOS_task_app_init(void);

// Function definitions

void RTOS_task_init(void)
{
    // Important note: This function runs before the RTOS starts.
    RTOS_task_HW_init();
    RTOS_task_IO_init();
    RTOS_task_app_init();
}

bool RTOS_task_HW_init(void)
{
    bool error_present = false;

    // NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4 );

#if FEATURE_RCC
    error_present |= HW_RCC_Init();
#endif

#if FEATURE_GPIO
    HW_GPIO_Init();
#endif

    return error_present;
}

void RTOS_task_IO_init(void)
{

}

void RTOS_task_app_init(void)
{

}

void RTOS_task_HW_1ms(void)
{

}

void RTOS_task_IO_1ms(void)
{

}

void RTOS_task_app_1ms(void)
{

}

void RTOS_task_HW_10ms(void)
{

}

void RTOS_task_IO_10ms(void)
{

}

void RTOS_task_app_10ms(void)
{

}

void RTOS_task_HW_100ms(void)
{

}

void RTOS_task_IO_100ms(void)
{

}

void RTOS_task_app_100ms(void)
{

}

void RTOS_task_HW_1000ms(void)
{

}

void RTOS_task_IO_1000ms(void)
{

}

void RTOS_task_app_1000ms(void)
{
#if FEATURE_HEARTBEAT
    app_heartbeat_run();
#endif
}
