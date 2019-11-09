/** @file usart_hal_sample.c
 *  @brief Definition of USART driver sample application function and data.
 *
 *  This is the source file for the definition of USART driver sample application.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 03, 2019 - Initial version, moved USART driver application from sample.c 
 *                to a new file.
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
uint8_t buffer[255];
uint8_t buffer_index = 0;

const Struct_Usart_Config_Typedef UsartSampleConfig[1] = 
{
    { Usart_UCSRnC_AsyncMode, Usart_UCSRnC_DisabledParity,
    Usart_UCSRnC_1StopBit, Usart_UCSRnC_8bitsData }
};

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void Usart_Setup(void){
    uint8_t strStart_uint8[] = "Start";
    cli();
    Usart_InitUSART(&UsartSampleConfig[0]);
    Usart_SetBaudrate(Usart_9600bps);
    Usart_CommandTransmitter(Enable);	
    Usart_CommandReceiver(Enable);
    sei();
    Usart_SendString(strStart_uint8);	
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
