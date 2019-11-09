/** @file config_base.h
 *  @brief Declaration of basic configuration.
 *
 *  This is the header file for the definition of basic configuration.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Initial version
 *              - Added assertion definition.
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
/** 
 * @def Do assertion for an expression
 *
 *  @param expression The evaluated expression.
 *  @retval nothing When the expression is true
 *  @retval error notification When the expression is false
 */
#ifdef USE_FULL_ASSERT
#define assert(expression) ((expression) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
#else
#define assert(expression) ((void)0) 
#endif
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
 * @brief Show the file name and line of code where the assertion failed.
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param file Name of file.
 * @param line Code line number.
 * @return None
 *
 * @see None
 */
void assert_failed(uint8_t* file, uint32_t line);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CONFIG_BASE_H_ */

/** End of File ***************************************************************/
