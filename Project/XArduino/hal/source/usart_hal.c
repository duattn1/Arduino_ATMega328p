/** @file usart_hal.c
 *  @brief Function implementation for USART driver.
 *
 *  This is the source file for the definition of USART driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 */

#ifdef USE_USART_HAL
 
/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "usart_hal.h"

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
void Usart_InitUSART(const Struct_Usart_Config_Typedef *config_ptr){
	/* Declare 2 local variables since data frame size configuring bits 
	   are located in 2 registers.*/
	uint8_t UCSZn2_uint8 = (config_ptr->dataFrame) & 0x04;
	uint8_t UCSZn1To0_uint8 = (config_ptr->dataFrame) & 0x03;
	
	// Select sync or async USART
	UCSR0C &= ~(MASK_2BIT << UMSEL00);
	UCSR0C |= config_ptr->mode << UMSEL00;
	// Select parity mode
	UCSR0C &= ~(MASK_2BIT << UPM00);
	UCSR0C |= config_ptr->parity << UPM00;
	// Select number of stop bit
	UCSR0C &= ~(MASK_1BIT << USBS0);
	UCSR0C |= config_ptr->stopBit << USBS0;
	// Select data frame size
	UCSR0B &= ~(MASK_1BIT << UCSZ02);
	UCSR0C &= ~(MASK_2BIT << UCSZ00);
	UCSR0B |= UCSZn2_uint8 << UCSZ02;	
	UCSR0C |= UCSZn1To0_uint8 << UCSZ00;
}


void Usart_SetBaudrate(Enum_Usart_Baudrate_Typedef baudrate_enum){
	uint16_t UBRRnValue_uint16;
	uint8_t isDoubleSpeed_uint8 = UCSR0A & (1 << U2X0);
	
	if(0 == isDoubleSpeed_uint8){
		UBRRnValue_uint16 = FOSC/(baudrate_enum*16) - 1;
	} else {
		UBRRnValue_uint16 = FOSC/(baudrate_enum*8) - 1;
	}
	
	/* Set baudrate. Since baudrate value range from 0..0x0FFF, the UBRRnL and UBRRnH are compared with 
	0x00FF and 0x0F00 respectively. */
	UBRR0L = (UBRRnValue_uint16 & 0x00FF);
	UBRR0H = (UBRRnValue_uint16 & 0x0F00);
}

void Usart_CommandTransmitter(Enum_Command_Typedef cmd_enum){
	if(Enable == cmd_enum){
		UCSR0B |= Enable << TXEN0;
	} else {
		UCSR0B &= ~(MASK_1BIT << TXEN0);
	}
}

void Usart_CommandReceiver(Enum_Command_Typedef cmd_enum){
	if(Enable == cmd_enum){
		UCSR0B |= Enable << RXEN0;
	} else {
		UCSR0B &= ~(MASK_1BIT << RXEN0);
	}
}

uint8_t Usart_SendChar(uint8_t data_uint8, FILE *stream_ptr){
	if(data_uint8 == '\n') {
      Usart_SendChar('\r', 0);
	}
	/* Wait for empty transmit buffer */
	while (!(UCSR0A & (1 << UDRE0)));
	/* Put data into buffer to send the data */
	UDR0 = data_uint8;
	return 0;
}

void Usart_SendString(uint8_t *string_ptr){
	while('\0' != *string_ptr){
		Usart_SendChar(*string_ptr, 0);
		string_ptr++;
	}
}

uint8_t Usart_ReceiveChar(FILE *stream_ptr){
	/* Wait for data to be received */
	while (!(UCSR0A & (1 << RXC0)));
	/* Get and return received data from buffer */
	return (uint8_t)UDR0;
}

#endif /* USE_USART_HAL */

/** End of File ***************************************************************/
