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
#include "interrupt.h"
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
/**
 * @struct This struct TODO
 */
typedef struct{
	uint8_t character;
	void (*function)(void);
} Struct_FunctionCall_Typedef;

/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/** @brief Perform testing initialization
 *
 *  @param none
 *  @return none
 */
void Test_Init(void);

/** @brief Perform the test loop: wait for testing data from host
 *
 *  @param none
 *  @return none
 */
void Test_Loop(void);

/** @brief Run one test case.
 *
 *  @param none
 *  @return none
 */
void Test_RunOneCase(void);

/** @brief Perform the test conclusion
 *
 *  @param none
 *  @return none
 */
void Test_Conclude(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* _UT_MAIN_H */

/** End of File ***************************************************************/
