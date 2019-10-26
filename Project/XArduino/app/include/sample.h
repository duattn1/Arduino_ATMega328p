/** @file sample.h
 *  @brief Function prototypes for Arduino samples.
 * 
 *  This is the header file for the definition of Arduino samples.
 *  
 * 	@author Tran Nhat Duat (duattn)
 *	@version 	V1.0
 */

#ifndef SAMPLE_H_
#define SAMPLE_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
/* HAL including */
#include "gpio_hal.h"
#include "usart_hal.h"
#include "spi_hal.h"

/* Kit interfaces including */
#include "ledMatrix_Max7219.h"

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

/** @brief Set up the Arduino.
 *
 *  @param none.
 *  @return none.
 */
void setup(void);

/** @brief Perform the infinite loop.
 *
 *  @param none.
 *  @return none.
 */
void loop(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* SAMPLE_H_ */

/** End of File ***************************************************************/
