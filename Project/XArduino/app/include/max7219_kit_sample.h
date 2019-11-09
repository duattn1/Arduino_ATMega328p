/** @file max7219_kit_sample.h
 *  @brief Declaration of LED matrix (based on Max7219) sample application 
 *         function and data.
 *
 *  This is the header file for the definition of LED matrix (based on Max7219)
 *  sample application.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 * -----------------------------------------------------------------------------
 */

#ifndef MAX7219_KIT_SAMPLE_H_
#define MAX7219_KIT_SAMPLE_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "ledMatrix_Max7219.h"

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
 * @brief Set up Max7219 kit
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param None
 * @return None
 *
 * @see None
 */
void Max7219_Setup(void);

/** 
 * @brief Perform the Max7219 kit infinite loop
 *
 * PRE-CONDITION: Max7219_Setup() function is invoked
 * POST-CONDITION: None
 *
 * @param None
 * @return None
 *
 * @see Max7219_Setup()
 */
void Max7219_Loop(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MAX7219_KIT_SAMPLE_H_ */

/** End of File ***************************************************************/
