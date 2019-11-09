/** @file ut_main.h
 *  @brief Declaration of unit testing main controlling function and data.
 *
 *  This is the header file for the definition of unit testing main controlling.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 * -----------------------------------------------------------------------------
 */

#ifndef _UT_MAIN_H
#define _UT_MAIN_H

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include <avr/interrupt.h>
#include "ut_base.h"
#include "usart_hal.h"
#include "ut_gpio_hal.h"

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/

/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/

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

/** 
 * @brief Perform testing
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param None
 * @return None
 *
 * @see Test_Init(), Test_Loop(), Test_Conclude()
 */
void Test_RunTest(void);

/** 
 * @brief Perform testing initialization
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param None
 * @return None
 *
 * @see None
 */
void Test_Init(void);

/** 
 * @brief Perform the test loop: wait for testing data from host
 *
 * PRE-CONDITION: Testing is initialized with Test_Init()
 * POST-CONDITION: None
 *
 * @param None
 * @return None
 *
 * @see Test_Init()
 */
void Test_Loop(void);

/** 
 * @brief Perform the test conclusion
 *
 * PRE-CONDITION: Test cases are run with Test_Loop()
 * POST-CONDITION: None
 *
 * @param None
 * @return None
 *
 * @see Test_Loop()
 */
void Test_Conclude(void);

/** 
 * @brief Get the host command via serial connection
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param NoneF
 * @return Host command
 *
 * @see None
 */
uint8_t Test_GetHostCommand(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _UT_MAIN_H */

/** End of File ***************************************************************/
