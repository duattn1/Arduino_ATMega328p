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
#include "unity.h"
#include "ut_base.h"
#include "gpio_hal.h"

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/

/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/

/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Pointers, Others
 ******************************************************************************/
typedef struct {
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum;
	Enum_Gpio_DDRxDirection_Typedef direction_enum;
	uint8_t expected;
	uint8_t mask;
} Struct_PinModeTestData_Typedef;
/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void Test_Gpio_GetPortBase_TC1(void);
void Test_Gpio_GetPortBase_TC2(void);
void Test_Gpio_GetPortBase_TC3(void);
void Test_Gpio_CommandPullUpResistorSetting_TC1(void);
void Test_Gpio_CommandPullUpResistorSetting_TC2(void);
void Test_Gpio_PinMode_TC1(void);
void Test_Gpio_PinMode_TC2(void);
void Test_Gpio_PinMode_TC3(void);
void Test_Gpio_PinMode_TC4(void);
void Test_Gpio_PinMode_TC5(void);
void Test_Gpio_PinMode_TC6(void);
void Test_Gpio_PinMode_TC7(void);
void Test_Gpio_PinMode_TC8(void);
void Test_Gpio_PinMode_TC9(void);
void Test_Gpio_PinMode_TC10(void);
void Test_Gpio_PinMode_TC11(void);
void Test_Gpio_PinMode_TC12(void);
void Test_Gpio_PinMode_TC13(void);
void Test_Gpio_PinMode_TC14(void);
void Test_Gpio_PinMode_TC15(void);
void Test_Gpio_PinMode_TC16(void);
void Test_Gpio_PinMode_TC17(void);
void Test_Gpio_PinMode_TC18(void);
void Test_Gpio_PinMode_TC19(void);
void Test_Gpio_PinMode_TC20(void);
void Test_Gpio_PinMode_TC21(void);
void Test_Gpio_PinMode_TC22(void);
void Test_Gpio_PinMode_TC23(void);
void Test_Gpio_PinMode_TC24(void);
void Test_Gpio_PinMode_TC25(void);
void Test_Gpio_PinMode_TC26(void);
void Test_Gpio_PinMode_TC27(void);
void Test_Gpio_PinMode_TC28(void);
void Test_Gpio_PinMode_TC29(void);
void Test_Gpio_PinMode_TC30(void);
void Test_Gpio_PinMode_TC31(void);
void Test_Gpio_PinMode_TC32(void);
void Test_Gpio_PinMode_TC33(void);
void Test_Gpio_PinMode_TC34(void);
void Test_Gpio_PinMode_TC35(void);
void Test_Gpio_PinMode_TC36(void);
void Test_Gpio_PinMode_TC37(void);
void Test_Gpio_PinMode_TC38(void);
void Test_Gpio_PinMode_TC39(void);
void Test_Gpio_PinMode_TC40(void);
void Test_Gpio_DigitalWrite_TC1(void);
void Test_Gpio_DigitalWrite_TC2(void);
void Test_Gpio_DigitalWrite_TC3(void);
void Test_Gpio_DigitalWrite_TC4(void);
void Test_Gpio_DigitalWrite_TC5(void);
void Test_Gpio_DigitalWrite_TC6(void);
void Test_Gpio_DigitalWrite_TC7(void);
void Test_Gpio_DigitalWrite_TC8(void);
void Test_Gpio_DigitalWrite_TC9(void);
void Test_Gpio_DigitalWrite_TC10(void);
void Test_Gpio_DigitalWrite_TC11(void);
void Test_Gpio_DigitalWrite_TC12(void);
void Test_Gpio_DigitalWrite_TC13(void);
void Test_Gpio_DigitalWrite_TC14(void);
void Test_Gpio_DigitalWrite_TC15(void);
void Test_Gpio_DigitalWrite_TC16(void);
void Test_Gpio_DigitalWrite_TC17(void);
void Test_Gpio_DigitalWrite_TC18(void);
void Test_Gpio_DigitalWrite_TC19(void);
void Test_Gpio_DigitalWrite_TC20(void);
void Test_Gpio_DigitalWrite_TC21(void);
void Test_Gpio_DigitalWrite_TC22(void);
void Test_Gpio_DigitalWrite_TC23(void);
void Test_Gpio_DigitalWrite_TC24(void);
void Test_Gpio_DigitalWrite_TC25(void);
void Test_Gpio_DigitalWrite_TC26(void);
void Test_Gpio_DigitalWrite_TC27(void);
void Test_Gpio_DigitalWrite_TC28(void);
void Test_Gpio_DigitalWrite_TC29(void);
void Test_Gpio_DigitalWrite_TC30(void);
void Test_Gpio_DigitalWrite_TC31(void);
void Test_Gpio_DigitalWrite_TC32(void);
void Test_Gpio_DigitalWrite_TC33(void);
void Test_Gpio_DigitalWrite_TC34(void);
void Test_Gpio_DigitalWrite_TC35(void);
void Test_Gpio_DigitalWrite_TC36(void);
void Test_Gpio_DigitalWrite_TC37(void);
void Test_Gpio_DigitalWrite_TC38(void);
void Test_Gpio_DigitalWrite_TC39(void);
void Test_Gpio_DigitalWrite_TC40(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* _UT_GPIO_HAL_H */

/** End of File ***************************************************************/

