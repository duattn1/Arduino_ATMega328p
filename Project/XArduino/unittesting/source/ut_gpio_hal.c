/** @file ut_gpio_hal.c
 *  @brief Function implementation for unit test of GPIO driver.
 *
 *  This file is generated from scripts. This is the source file for 
 *  the unit test definition of GPIO driver.
 *
 *  @author 	Tran Nhat Duat (duattn)
 *  @version 	V1.0
 */

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "ut_gpio_hal.h"

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
// List of all test cases
void (*testcaseList[3])(void) = 
{
	Test_Gpio_GetPortBase_TC1,
	Test_Gpio_GetPortBase_TC2,
	Test_Gpio_GetPortBase_TC3
};

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void Test_Gpio_GetPortBase_TC1(void)
{
	// Declare object to store returning value
	Uint8PtrData_Typedef return_obj;
	uint8_t *x;
	
	// Initialize param_1
	Enum_Gpio_Port_Typedef port = Gpio_PortB;
	
	// Call the tested function
	x = (uint8_t*)
	(port);
	
	// Compare return_obj with expected value
	return_obj.actual = x;
	return_obj.expected = (uint8_t*)GPIOB;
	compareOnUint8Ptr(return_obj);
}

void Test_Gpio_GetPortBase_TC2(void)
{
	// Declare object to store returning value
	Uint8PtrData_Typedef return_obj;
	uint8_t *x;
	
	// Initialize param_1
	Enum_Gpio_Port_Typedef port = Gpio_PortC;
	
	// Call the tested function
	x = (uint8_t*)Gpio_GetPortBase(port);
	
	// Compare return_obj with expected value
	return_obj.actual = x;
	return_obj.expected = (uint8_t*)GPIOC;
	compareOnUint8Ptr(return_obj);
}

void Test_Gpio_GetPortBase_TC3(void)
{
	// Declare object to store returning value
	Uint8PtrData_Typedef return_obj;
	uint8_t *x;
	
	// Initialize param_1
	Enum_Gpio_Port_Typedef port = Gpio_PortD;
	
	// Call the tested function
	x = (uint8_t*)Gpio_GetPortBase(port);
	
	// Compare return_obj with expected value
	return_obj.actual = x;
	return_obj.expected = (uint8_t*)GPIOD;
	compareOnUint8Ptr(return_obj);
}

/** End of File ***************************************************************/

