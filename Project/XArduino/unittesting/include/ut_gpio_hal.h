/** @file ut_gpio_hal.h
 *  @brief Declaration of GPIO driver unit testing function and data.
 *
 *  This file is generated from scripts. This is the header file for 
 *  the definition of GPIO driver unit testing.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * -------------------------------- INFORMATION --------------------------------
 * - Be generated on Mmm DD, YYYY
 * -----------------------------------------------------------------------------
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
#define NAME(x) #x

/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Unions, Pointers, Others
 ******************************************************************************/

/*******************************************************************************
 * 5. Global, Static, Constant, Extern Variables and Extern Functions
 ******************************************************************************/

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void Test_RunTestcase(void);
void Test_Gpio_GetPortBase(Enum_Gpio_Port_Typedef port_enum, uint8_t* expected);
void Test_Gpio_CommandPullUpResistorSetting(Enum_Command_Typedef cmd_enum, uint8_t expected, uint8_t mask);
void Test_Gpio_PinMode(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_Gpio_DDRxDirection_Typedef direction_enum, uint8_t expected, uint8_t mask);
void Test_Gpio_DigitalWrite(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_IOValue_Typedef value_enum, uint8_t expected, uint8_t mask);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _UT_GPIO_HAL_H */

/** End of File ***************************************************************/

