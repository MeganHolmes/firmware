
// // C Standard Includes

// // ST Includes
// #include "stm32f10x_gpio.h"

// // Project Includes
// #include "HW_GPIO_generated.h"
// #include "HW_GPIO.h"

// // Defines
// typedef struct
// {
//     HW_GPIO_Data pin[HW_GPIO_COUNT];
// } HW_GPIO_privateData;

// static HW_GPIO_privateData gpioData;


// void HW_GPIO_Init(void)
// {
//     for (int pinIdx = 0; pinIdx < HW_GPIO_COUNT; pinIdx++)
//     {
//         // TODO: I am pretty sure there is a pointer error here.
//         GPIO_Init(gpioData.pin[pinIdx].port, &gpioData.pin[pinIdx].pinData);
//         GPIO_WriteBit(gpioData.pin[pinIdx].port, gpioData.pin[pinIdx].pinData.GPIO_Pin, gpioData.pin[pinIdx].defaultState);
//     }
// }

// void HW_GPIO_setEnableStatus(HW_GPIO_Pin pinID, bool enable)
// {

// }
