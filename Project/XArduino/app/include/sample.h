/** @file sample.h
 *  @brief Declaration of sample application function and data.
 *
 *  This is the header file for the definition of sample application.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 * -----------------------------------------------------------------------------
 */

#ifndef SAMPLE_H_
#define SAMPLE_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
/* HAL sample application*/
#include "config_app.h"
#include "gpio_hal_sample.h"
#include "spi_hal_sample.h"
#include "usart_hal_sample.h"
#include "timer_hal_sample.h"

/* Kit application */	
#include "max7219_kit_sample.h"

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
 * @brief Run the sample application
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param None
 * @return None
 *
 * @see None
 */
void Sample_RunApp(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* SAMPLE_H_ */

/** End of File ***************************************************************/
