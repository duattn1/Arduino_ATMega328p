/** @file ut_gpio_hal.h
 *  @brief Function prototypes for unit test of GPIO driver.
 *
 *  This file is generated from scripts. This is the header file for 
 *  the unit test definition of GPIO driver.
 *
 *  @author 	Tran Nhat Duat (duattn)
 *  @version 	V1.0
 */

#ifndef _UT_GPIO_HAL_H
#define _UT_GPIO_HAL_H

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include <stdlib.h>
#include <stdbool.h>
#include "unity.h"
#include "ut_base.h"
#include "gpio_hal.h"
#include "usart_hal.h"

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/

/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/

/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Pointers, Others
 ******************************************************************************/

/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void Test_RunAll(void);
void Test_Gpio_GetPortBase(Enum_Gpio_Port_Typedef port_enum, uint8_t* expected);
void Test_Gpio_CommandPullUpResistorSetting(Enum_Command_Typedef cmd_enum, uint8_t expected, uint8_t mask);
void Test_Gpio_PinMode(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_Gpio_DDRxDirection_Typedef direction_enum, uint8_t expected, uint8_t mask);
void Test_Gpio_DigitalWrite(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_IOValue_Typedef value_enum, uint8_t expected, uint8_t mask);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* _UT_GPIO_HAL_H */

/** End of File ***************************************************************/

