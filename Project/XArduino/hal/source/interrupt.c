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
uint8_t buffer[255];
uint8_t buffer_index = 0;
bool endCommand = false;

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
ISR (TIMER1_COMPA_vect)
{	
    counter++;	
}


ISR(USART_RX_vect)
{
    while (!(UCSR0A & (1 << RXC0)));	
	uint8_t data = (uint8_t)UDR0;
	if ('.' == data)
	{ 
		endCommand = true;
	}
	buffer[buffer_index] = data;
	buffer_index++;
}

#endif /* USE_INTERRUPT */

/** End of File ***************************************************************/
