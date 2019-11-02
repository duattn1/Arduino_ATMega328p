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

/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/
extern uint8_t buffer[256];
extern uint8_t buffer_index;
extern bool endCommand;

extern Struct_HostCommand_Typedef Test_GetHostCommand(void);

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void Test_RunAll(void)
{	
	Struct_HostCommand_Typedef cmd;
	
	while(1) {
		cmd = Test_GetHostCommand();
				
		/* Quit the test loop when "q:" is received. */				
		if ('d' == cmd.command) {
			break;			 
		}
	}
	
	switch (cmd.option) {
		case 0: 
			/* Parameters position starts from 3, since the command format is ":d[option][param1][param2][...]" */
			Test_Gpio_GetPortBase(PARAM_1, (uint8_t*)PARAM_2);
			break;
		case 1:
			Test_Gpio_CommandPullUpResistorSetting(PARAM_1, PARAM_2, PARAM_3);
			break;
		case 2:
			Test_Gpio_PinMode(PARAM_1, PARAM_2, PARAM_3, PARAM_4);
			break;
		case 3:
			Test_Gpio_DigitalWrite(PARAM_1, PARAM_2, PARAM_3, PARAM_4);
			break;
	};	
}

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

void Test_Gpio_CommandPullUpResistorSetting(Enum_Command_Typedef cmd_enum, uint8_t expected, uint8_t mask)
{
	/* Declare object to check value of MCUCR */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Call the tested function */
	Gpio_CommandPullUpResistorSetting(cmd_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = MCUCR;
	global_var_1.expected = expected;
	global_var_1.mask = mask;
	compareBitsOnUint8(&global_var_1);
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

void Test_Gpio_DigitalWrite(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_IOValue_Typedef value_enum, uint8_t expected, uint8_t mask)
{
	/* Declare object to check value of gpiox_ptr->PORTx_uint8 */
	Struct_Uint8Data_Typedef global_var_1;
	
	/* Test case precondition configuration */
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	
	/* Call the tested function */
	Gpio_DigitalWrite(arduinoPin_enum, value_enum);
	
	/* Compare global_var_1 with expected value */
	global_var_1.actual = gpiox_ptr->PORTx_uint8;
	global_var_1.expected = expected;
	global_var_1.mask = mask;
	compareBitsOnUint8(&global_var_1);
}

#endif /* defined (UNIT_TESTING) && defined (USE_GPIO_HAL) */

/** End of File ***************************************************************/

