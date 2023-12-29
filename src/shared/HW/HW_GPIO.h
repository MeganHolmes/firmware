
#ifndef __HW_GPIO_H__
#define __HW_GPIO_H__

// C includes
#include <stdint.h>
#include <stdbool.h>

// Project Includes
#include "HW_GPIO_datatypes.h"
#include "HW_GPIO_projectSpecific.h"

// Public Functions

void HW_GPIO_Init(void);
void HW_GPIO_setEnableStatus(HW_GPIO_Pin pinID, bool enable);
bool HW_GPIO_isEnabled(HW_GPIO_Pin pinID);
GPIO_TypeDef* HW_GPIO_getPortForGPIOID(HW_GPIO_Pin pinID);

#endif // __HW_GPIO_H__
