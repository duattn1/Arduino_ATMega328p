/** @file timer_hal_sample.h
 *  @brief Declaration of Timer driver sample application function and data.
 *
 *  This is the header file for the definition of Timer driver sample application.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 * -----------------------------------------------------------------------------
 */

#ifndef TIMER_HAL_SAMPLE_H_
#define TIMER_HAL_SAMPLE_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "config_app.h"
#include "timer_hal.h"

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
 * @brief Set up Timer driver
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param None
 * @return None
 *
 * @see None
 */
void Timer_Setup(void);

/** 
 * @brief Perform the Timer driver infinite loop
 *
 * PRE-CONDITION: Timer_Setup() function is invoked
 * POST-CONDITION: None
 *
 * @param None
 * @return None
 *
 * @see Timer_Setup()
 */
void Timer_Loop(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* TIMER_HAL_SAMPLE_H_ */

/** End of File ***************************************************************/
