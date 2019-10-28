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

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* _UT_GPIO_HAL_H */

/** End of File ***************************************************************/

