/** @file ut_main.h
 *  @brief Function prototypes for unit testing main controlling.
 * 
 *  This is the header file for the definition of unit testing main controlling.
 *  
 * 	@author Tran Nhat Duat (duattn)
 *	@version 	V1.0
 */


#ifndef _UT_MAIN_H
#define _UT_MAIN_H

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "usart_hal.h"
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

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/** @brief Run testing with all test cases
 *
 *  @param none
 *  @return none
 */
void runTest(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* _UT_MAIN_H */

/** End of File ***************************************************************/
