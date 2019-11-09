/** @file config_base.h
 *  @brief Declaration of hardware abstract layer configuration.
 *
 *  This is the header file for the definition of miscellaneous data.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Initial version
 * -----------------------------------------------------------------------------
 */
#ifndef CONFIG_BASE_H_
#define CONFIG_BASE_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/
/**
 * Enable Target Arduino board
 */
//#define ARDUINO_NANO

/**
 * @def List of global macros configuration
 * @note Comment out unused sample applications
 */
//#define GPIO_HAL_SAMPLE

/**
 * @def Macros that need defining when corresponding sample application is enabled.
 */
//#ifdef GPIO_HAL_SAMPLE
//#define GPIO_HAL
//#endif

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


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CONFIG_BASE_H_ */

/** End of File ***************************************************************/
