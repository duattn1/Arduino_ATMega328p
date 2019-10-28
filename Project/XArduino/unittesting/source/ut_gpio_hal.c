/** @file ut_gpio_driver.c
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
void (*testcaseList[1])(void) = 
{
	Test_GPIO_Enable_TC1
};

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void Test_GPIO_Enable_TC1(void)
{
	// Declare object to check value of RCC->AHB1ENR
	Uint32Data_Typedef global_var_1;
	
	// Init param_1
	//Enum_GPIO_Port_Typedef port = GPIO_PortGPIOA;
	
	// Call the tested function
	//GPIO_Enable(port);
	
	// Compare global_var_1 with expected value
	global_var_1.actual = DDRB;
	global_var_1.expected = 0x01;
	global_var_1.mask = 0x01;
	compareBits(global_var_1);
}

#endif /* UNIT_TESTING	*/

/** End of File ***************************************************************/

