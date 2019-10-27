/** @file main.c
 *  @brief Function implementation for main processing.
 *
 *  This is the source file for the definition of main processing.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 */
 
/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include <avr/io.h>
#include "sample.h"
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
 * 6. Function Definitions
 ******************************************************************************/
int main(void)
{	
	setup();
	loop();
}

/** End of File ***************************************************************/
