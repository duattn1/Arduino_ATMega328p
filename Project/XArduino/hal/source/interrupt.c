/** @file gpio_hal.c
 *  @brief Function implementation for GPIO driver.
 *
 *  This is the source file for the definition of GPIO driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 */

#ifdef USE_INTERRUPT

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "interrupt.h"

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
volatile uint8_t counter = 0;

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
ISR (TIMER1_COMPA_vect)
{	
    counter++;	
}

#endif /* USE_INTERRUPT */

/** End of File ***************************************************************/
