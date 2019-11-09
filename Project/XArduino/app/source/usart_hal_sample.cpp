/** @file usart_hal_sample.cpp
 *  @brief Definition of USART driver sample application function and data.
 *
 *  This is the source file for the definition of USART driver sample application.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 *              - Changed file extension to .cpp.
 *              - Updated Usart_Setup() to call functions from Serial class.
 * -----------------------------------------------------------------------------
 */

#ifdef USART_HAL_SAMPLE
 
/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "usart_hal_sample.h"

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
Serial Serial; /* Serial object */
uint8_t buffer[255];
uint8_t buffer_index = 0;

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void Usart_Setup(void){
    char strStart_uint8[] = "Start";    
    Serial.begin(Usart_9600bps);
    Serial.print(strStart_uint8);
}

void Usart_Loop(void){	
    while(1){
        if(buffer_index > 0){
            buffer_index--;	
            Usart_SendChar(buffer[buffer_index], 0);
        }
    }
}

#ifdef USE_INTERRUPT
/**
 * USART reception complete interrupt handler
 */
ISR(USART_RX_vect)
{
    while (!(UCSR0A & (1 << RXC0)));	
    uint8_t data = (uint8_t)UDR0;    
    buffer[buffer_index] = data;
    buffer_index++;
}
#endif /* USE_INTERRUPT */

#endif /* USART_HAL_SAMPLE */

/** End of File ***************************************************************/
