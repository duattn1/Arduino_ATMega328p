/** @file ut_gpio_hal.c
 *  @brief Function implementation for unit test of GPIO driver.
 *
 *  This file is generated from scripts. This is the source file for 
 *  the unit test definition of GPIO driver.
 *
 *  @author 	Tran Nhat Duat (duattn)
 *  @version 	V1.0
 */

#ifdef UNIT_TESTING	

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
void (*testcaseList[85])(void) = 
{
	Test_Gpio_GetPortBase_TC1,
	Test_Gpio_GetPortBase_TC2,
	Test_Gpio_GetPortBase_TC3,
	Test_Gpio_CommandPullUpResistorSetting_TC1,
	Test_Gpio_CommandPullUpResistorSetting_TC2,
	Test_Gpio_PinMode_TC1,
	Test_Gpio_PinMode_TC2,
	Test_Gpio_PinMode_TC3,
	Test_Gpio_PinMode_TC4,
	Test_Gpio_PinMode_TC5,
	Test_Gpio_PinMode_TC6,
	Test_Gpio_PinMode_TC7,
	Test_Gpio_PinMode_TC8,
	Test_Gpio_PinMode_TC9,
	Test_Gpio_PinMode_TC10,
	Test_Gpio_PinMode_TC11,
	Test_Gpio_PinMode_TC12,
	Test_Gpio_PinMode_TC13,
	Test_Gpio_PinMode_TC14,
	Test_Gpio_PinMode_TC15,
	Test_Gpio_PinMode_TC16,
	Test_Gpio_PinMode_TC17,
	Test_Gpio_PinMode_TC18,
	Test_Gpio_PinMode_TC19,
	Test_Gpio_PinMode_TC20,
	Test_Gpio_PinMode_TC21,
	Test_Gpio_PinMode_TC22,
	Test_Gpio_PinMode_TC23,
	Test_Gpio_PinMode_TC24,
	Test_Gpio_PinMode_TC25,
	Test_Gpio_PinMode_TC26,
	Test_Gpio_PinMode_TC27,
	Test_Gpio_PinMode_TC28,
	Test_Gpio_PinMode_TC29,
	Test_Gpio_PinMode_TC30,
	Test_Gpio_PinMode_TC31,
	Test_Gpio_PinMode_TC32,
	Test_Gpio_PinMode_TC33,
	Test_Gpio_PinMode_TC34,
	Test_Gpio_PinMode_TC35,
	Test_Gpio_PinMode_TC36,
	Test_Gpio_PinMode_TC37,
	Test_Gpio_PinMode_TC38,
	Test_Gpio_PinMode_TC39,
	Test_Gpio_PinMode_TC40,
	Test_Gpio_DigitalWrite_TC1,
	Test_Gpio_DigitalWrite_TC2,
	Test_Gpio_DigitalWrite_TC3,
	Test_Gpio_DigitalWrite_TC4,
	Test_Gpio_DigitalWrite_TC5,
	Test_Gpio_DigitalWrite_TC6,
	Test_Gpio_DigitalWrite_TC7,
	Test_Gpio_DigitalWrite_TC8,
	Test_Gpio_DigitalWrite_TC9,
	Test_Gpio_DigitalWrite_TC10,
	Test_Gpio_DigitalWrite_TC11,
	Test_Gpio_DigitalWrite_TC12,
	Test_Gpio_DigitalWrite_TC13,
	Test_Gpio_DigitalWrite_TC14,
	Test_Gpio_DigitalWrite_TC15,
	Test_Gpio_DigitalWrite_TC16,
	Test_Gpio_DigitalWrite_TC17,
	Test_Gpio_DigitalWrite_TC18,
	Test_Gpio_DigitalWrite_TC19,
	Test_Gpio_DigitalWrite_TC20,
	Test_Gpio_DigitalWrite_TC21,
	Test_Gpio_DigitalWrite_TC22,
	Test_Gpio_DigitalWrite_TC23,
	Test_Gpio_DigitalWrite_TC24,
	Test_Gpio_DigitalWrite_TC25,
	Test_Gpio_DigitalWrite_TC26,
	Test_Gpio_DigitalWrite_TC27,
	Test_Gpio_DigitalWrite_TC28,
	Test_Gpio_DigitalWrite_TC29,
	Test_Gpio_DigitalWrite_TC30,
	Test_Gpio_DigitalWrite_TC31,
	Test_Gpio_DigitalWrite_TC32,
	Test_Gpio_DigitalWrite_TC33,
	Test_Gpio_DigitalWrite_TC34,
	Test_Gpio_DigitalWrite_TC35,
	Test_Gpio_DigitalWrite_TC36,
	Test_Gpio_DigitalWrite_TC37,
	Test_Gpio_DigitalWrite_TC38,
	Test_Gpio_DigitalWrite_TC39,
	Test_Gpio_DigitalWrite_TC40
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

void Test_Gpio_CommandPullUpResistorSetting_TC1(void)
{
	// Declare object to check value of MCUCR
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	Enum_Command_Typedef cmd = Disable;
	
	// Call the tested function
	Gpio_CommandPullUpResistorSetting(cmd);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = MCUCR;
	global_var_1.expected = 0x10;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_CommandPullUpResistorSetting_TC2(void)
{
	// Declare object to check value of MCUCR
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	Enum_Command_Typedef cmd = Enable;
	
	// Call the tested function
	Gpio_CommandPullUpResistorSetting(cmd);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = MCUCR;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC1(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin0;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC2(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin0;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x01;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC3(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin1;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC4(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin1;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x02;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC5(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin2;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC6(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin2;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x04;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC7(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin3;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC8(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin3;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x08;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC9(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin4;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC10(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin4;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x10;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC11(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin5;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC12(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin5;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x20;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC13(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin6;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x40;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC14(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin6;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x40;
	global_var_1.mask = 0x40;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC15(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin7;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x80;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC16(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin7;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x80;
	global_var_1.mask = 0x80;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC17(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin8;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC18(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin8;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x01;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC19(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin9;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC20(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin9;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x02;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC21(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin10;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC22(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin10;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x04;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC23(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin11;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC24(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin11;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x08;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC25(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin12;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC26(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin12;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x10;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC27(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin13;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC28(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin13;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x20;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC29(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin14;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC30(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin14;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x01;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC31(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin15;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC32(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin15;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x02;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC33(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin16;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC34(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin16;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x04;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC35(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin17;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC36(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin17;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x08;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC37(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin18;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC38(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin18;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x10;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC39(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin19;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Input;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_PinMode_TC40(void)
{
	// Declare object to check value of gpiox->DDRx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin19;
	// Initialize param_2
	Enum_Gpio_DDRxDirection_Typedef direction = Gpio_DDRx_Output;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_PinMode(arduinoPin, direction);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->DDRx;
	global_var_1.expected = 0x20;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC1(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin0;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC2(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin0;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x01;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC3(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin1;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC4(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin1;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x02;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC5(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin2;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC6(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin2;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x04;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC7(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin3;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC8(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin3;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x08;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC9(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin4;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC10(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin4;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x10;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC11(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin5;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC12(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin5;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x20;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC13(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin6;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x40;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC14(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin6;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x40;
	global_var_1.mask = 0x40;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC15(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin7;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x80;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC16(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin7;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x80;
	global_var_1.mask = 0x80;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC17(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin8;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC18(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin8;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x01;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC19(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin9;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC20(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin9;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x02;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC21(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin10;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC22(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin10;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x04;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC23(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin11;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC24(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin11;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x08;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC25(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin12;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC26(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin12;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x10;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC27(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin13;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC28(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin13;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x20;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC29(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin14;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC30(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin14;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x01;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC31(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin15;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC32(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin15;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x02;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC33(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin16;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC34(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin16;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x04;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC35(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin17;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC36(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin17;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x08;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC37(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin18;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC38(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin18;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x10;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC39(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin19;
	// Initialize param_2
	Enum_IOValue_Typedef value = Low;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(global_var_1);
}

void Test_Gpio_DigitalWrite_TC40(void)
{
	// Declare object to check value of gpiox->PORTx
	Uint8Data_Typedef global_var_1;
	
	// Initialize param_1
	uint8_t arduinoPin = Pin19;
	// Initialize param_2
	Enum_IOValue_Typedef value = High;
	
	// Test case precondition configuration
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port; 
	gpiox = Gpio_GetPortBase(port);
	
	// Call the tested function
	Gpio_DigitalWrite(arduinoPin, value);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = gpiox->PORTx;
	global_var_1.expected = 0x20;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(global_var_1);
}

#endif /* UNIT_TESTING */

/** End of File ***************************************************************/
