/** @file ut_gpio_hal.c
 *  @brief Function implementation for unit test of GPIO driver.
 *
 *  This file is generated from scripts. This is the source file for 
 *  the unit test definition of GPIO driver.
 *
 *  @author 	Tran Nhat Duat (duattn)
 *  @version 	V1.0
 */

#if defined (UNIT_TESTING) && defined (USE_GPIO_HAL)

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
const Struct_PinModeTestData_Typedef Test_Gpio_PinMode_Data[] =
{
    {Pin0, Gpio_DDRx_Input, 0x00, 0x01},
    {Pin0, Gpio_DDRx_Output, 0x01, 0x01},
    {Pin1, Gpio_DDRx_Input, 0x00, 0x02},
    {Pin1, Gpio_DDRx_Output, 0x02, 0x02},
    {Pin2, Gpio_DDRx_Input, 0x00, 0x04},
    {Pin2, Gpio_DDRx_Output, 0x04, 0x04},
    {Pin3, Gpio_DDRx_Input, 0x00, 0x08},
    {Pin3, Gpio_DDRx_Output, 0x08, 0x08},
    {Pin4, Gpio_DDRx_Input, 0x00, 0x10},
    {Pin4, Gpio_DDRx_Output, 0x10, 0x10},
    {Pin5, Gpio_DDRx_Input, 0x00, 0x20},
    {Pin5, Gpio_DDRx_Output, 0x20, 0x20},
    {Pin6, Gpio_DDRx_Input, 0x00, 0x40},
    {Pin6, Gpio_DDRx_Output, 0x40, 0x40},
    {Pin7, Gpio_DDRx_Input, 0x00, 0x80},
    {Pin7, Gpio_DDRx_Output, 0x80, 0x80},
    {Pin8, Gpio_DDRx_Input, 0x00, 0x01},
    {Pin8, Gpio_DDRx_Output, 0x01, 0x01},
    {Pin9, Gpio_DDRx_Input, 0x00, 0x02},
    {Pin9, Gpio_DDRx_Output, 0x02, 0x02},
    {Pin10, Gpio_DDRx_Input, 0x00, 0x04},
    {Pin10, Gpio_DDRx_Output, 0x04, 0x04},
    {Pin11, Gpio_DDRx_Input, 0x00, 0x08},
    {Pin11, Gpio_DDRx_Output, 0x08, 0x08},
    {Pin12, Gpio_DDRx_Input, 0x00, 0x10},
    {Pin12, Gpio_DDRx_Output, 0x10, 0x10},
    {Pin13, Gpio_DDRx_Input, 0x00, 0x20},
    {Pin13, Gpio_DDRx_Output, 0x20, 0x20},
    {Pin14, Gpio_DDRx_Input, 0x00, 0x01},
    {Pin14, Gpio_DDRx_Output, 0x01, 0x01},
    {Pin15, Gpio_DDRx_Input, 0x00, 0x02},
    {Pin15, Gpio_DDRx_Output, 0x02, 0x02},
    {Pin16, Gpio_DDRx_Input, 0x00, 0x04},
    {Pin16, Gpio_DDRx_Output, 0x04, 0x04},
    {Pin17, Gpio_DDRx_Input, 0x00, 0x08},
    {Pin17, Gpio_DDRx_Output, 0x08, 0x08},
    {Pin18, Gpio_DDRx_Input, 0x00, 0x10},
    {Pin18, Gpio_DDRx_Output, 0x10, 0x10},
    {Pin19, Gpio_DDRx_Input, 0x00, 0x20},
    {Pin19, Gpio_DDRx_Output, 0x20, 0x20}
};
/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/
/* List of all test cases */
void (*TestcaseList_array[46])(void) = 
{
	Test_Gpio_GetPortBase_TC1,
	Test_Gpio_GetPortBase_TC2,
	Test_Gpio_GetPortBase_TC3,
	Test_Gpio_CommandPullUpResistorSetting_TC1,
	Test_Gpio_CommandPullUpResistorSetting_TC2,
	Test_Gpio_PinMode_TC1,
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
void Test_Gpio_GetPortBase(Enum_Gpio_Port_Typedef port_enum, uint8_t* expected)
{
	/* Declare object to store returning value */
	Struct_Uint8PtrData_Typedef return_obj;
	uint8_t *result_ptr;
	
	/* Call the tested function */
	result_ptr = (uint8_t*)Gpio_GetPortBase(port_enum);
	
	/* Compare return_obj with expected value */
	return_obj.actual = result_ptr;
	return_obj.expected = expected;
	compareOnUint8Ptr(&return_obj);
}

void Test_Gpio_GetPortBase_TC1(void)
{
	Test_Gpio_GetPortBase(Gpio_PortB, (uint8_t*)GPIOB);
}

void Test_Gpio_GetPortBase_TC2(void)
{
	Test_Gpio_GetPortBase(Gpio_PortC, (uint8_t*)GPIOC);
}

void Test_Gpio_GetPortBase_TC3(void)
{
	Test_Gpio_GetPortBase(Gpio_PortD, (uint8_t*)GPIOD);
}

void Test_Gpio_CommandPullUpResistorSetting(Enum_Command_Typedef cmd_enum, uint8_t expected)
{
	/* Declare object to check value of MCUCR */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Call the tested function */
	Gpio_CommandPullUpResistorSetting(cmd_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = MCUCR;
	global_var_1.expected = expected;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_CommandPullUpResistorSetting_TC1(void)
{
	Test_Gpio_CommandPullUpResistorSetting(Disable, 0x10);
}

void Test_Gpio_CommandPullUpResistorSetting_TC2(void)
{
	Test_Gpio_CommandPullUpResistorSetting(Enable, 0x00);
}

void Test_Gpio_PinMode(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_Gpio_DDRxDirection_Typedef direction_enum, uint8_t expected, uint8_t mask)
{
	/* Declare object to check value of gpiox_ptr->DDRx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_PinMode(arduinoPin_enum, direction_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->DDRx_uint8;
	global_var_1.expected = expected;
	global_var_1.mask = mask;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_PinMode_TC1(void)
{
	Test_Gpio_PinMode(Pin0, Gpio_DDRx_Input, 0x00, 0x00);
}

void Test_Gpio_DigitalWrite_TC1(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin0;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC2(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin0;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x01;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC3(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin1;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC4(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin1;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x02;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC5(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin2;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC6(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin2;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x04;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC7(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin3;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC8(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin3;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x08;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC9(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin4;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC10(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin4;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x10;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC11(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin5;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC12(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin5;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x20;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC13(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin6;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x40;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC14(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin6;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x40;
	global_var_1.mask = 0x40;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC15(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin7;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x80;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC16(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin7;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x80;
	global_var_1.mask = 0x80;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC17(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin8;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC18(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin8;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x01;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC19(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin9;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC20(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin9;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x02;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC21(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin10;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC22(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin10;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x04;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC23(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin11;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC24(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin11;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x08;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC25(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin12;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC26(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin12;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x10;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC27(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin13;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC28(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin13;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x20;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC29(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin14;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC30(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin14;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x01;
	global_var_1.mask = 0x01;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC31(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin15;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC32(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin15;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x02;
	global_var_1.mask = 0x02;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC33(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin16;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC34(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin16;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x04;
	global_var_1.mask = 0x04;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC35(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin17;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC36(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin17;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x08;
	global_var_1.mask = 0x08;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC37(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin18;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC38(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin18;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x10;
	global_var_1.mask = 0x10;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC39(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin19;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = Low;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x00;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(&global_var_1);
}

void Test_Gpio_DigitalWrite_TC40(void)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Initialize param_1 */
	Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum = Pin19;
	/* Initialize param_2 */
	Enum_IOValue_Typedef value_enum = High;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = 0x20;
	global_var_1.mask = 0x20;
	compareBitsOnUint8(&global_var_1);
}

#endif /* defined (UNIT_TESTING) && defined (USE_GPIO_HAL) */

/** End of File ***************************************************************/

