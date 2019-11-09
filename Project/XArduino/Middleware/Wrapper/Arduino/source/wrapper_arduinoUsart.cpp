/** @file wrapper_arduinoUsart.cpp
 *  @brief Definition of Arduino wrapper for USART driver function and data.
 *
 *  This is the source file for the definition of Arduino wrapper for USART
 *  driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Initial version
 * -----------------------------------------------------------------------------
 */
 

#ifdef USART_HAL

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "wrapper_arduinoUsart.h"

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
const Struct_Usart_Config_Typedef UsartConfig[1] = 
{
    { Usart_UCSRnC_AsyncMode, Usart_UCSRnC_DisabledParity,
    Usart_UCSRnC_1StopBit, Usart_UCSRnC_8bitsData }
};
/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void Serial::begin(Enum_Usart_Baudrate_Typedef baudrate_enum){
    cli();
    Usart_InitUSART(&UsartConfig[0]);
    Usart_SetBaudrate(baudrate_enum);
    Usart_CommandTransmitter(Enable);	
    Usart_CommandReceiver(Enable);
    sei();
}

void Serial::print(char *string_ptr){
    Usart_SendString((uint8_t*)string_ptr);
}

#endif /* USART_HAL */

/** End of File ***************************************************************/
