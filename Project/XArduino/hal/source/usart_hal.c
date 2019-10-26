/** @file usart_hal.c
 *  @brief Function implementation for USART driver.
 *
 *  This is the source file for the definition of USART driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 */
 
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
void initUSART(USART_Config_Typedef *config){
	/* Declare 2 local variables since data frame size configuring bits 
	   are located in 2 registers.*/
	uint8_t UCSZn2 = (config->dataFrame) & 0x04;
	uint8_t UCSZn1To0 = (config->dataFrame) & 0x03;;
	
	// Select sync or async USART
	UCSR0C &= ~(config->mode << 6);
	UCSR0C |= config->mode << 6;
	// Select parity mode
	UCSR0C &= ~(config->parity << 4);
	UCSR0C |= config->parity << 4;
	// Select number of stop bit
	UCSR0C &= ~(config->stopBit << 3);
	UCSR0C |= config->stopBit << 3;
	// Select data frame size
	UCSR0B &= ~(UCSZn2 << 2);
	UCSR0B |= UCSZn2 << 2;
	UCSR0C &= ~(UCSZn1To0 << 1);
	UCSR0C |= UCSZn1To0 << 1;
}


void setBaudrate(USART_Baudrate_Typedef baudrate){
	uint16_t UBRRnValue;
	uint8_t isDoubleSpeed = UCSR0A & (1 << U2X0);
	
	if(0 == isDoubleSpeed){
		UBRRnValue = FOSC/(baudrate*16) - 1;
	} else {
		UBRRnValue = FOSC/(baudrate*8) - 1;
	}
	
	/* Set baudrate. Since baurate value range from 0..0x0FFF, the UBRRnL and UBRRnH are compared with 
	0x00FF and 0x0F00 respectively. */
	UBRR0L = (UBRRnValue & 0x00FF);
	UBRR0H = (UBRRnValue & 0x0F00);
}

void commandTransmitter(Command_Typedef cmd){
	if(ENABLE == cmd){
		UCSR0B |= 1 << TXEN0;
	} else {
		UCSR0B &= ~(1 << TXEN0);
	}
}

void commandReceiver(Command_Typedef cmd){
	if(ENABLE == cmd){
		UCSR0B |= 1 << RXEN0;
	} else {
		UCSR0B &= ~(1 << RXEN0);
	}
}

void sendChar(uint8_t data){
	/* Wait for empty transmit buffer */
	while (!(UCSR0A & (1 << UDRE0)));
	/* Put data into buffer to send the data */
	UDR0 = data;
}

void sendString(uint8_t *str){
	while(NULL != *str){
		sendChar(*str);
		str++;
	}
}

uint8_t receiveChar(void){
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<RXC0)));
	/* Get and return received data from buffer */
	return UDR0;
}

uint8_t* receiveString(void){
	static uint8_t *str;//TODO str[RECEIVED_STRING_LENGTH];
	uint8_t data, i = 0;

	do {
		data = receiveChar();
		str[i++] = data;		
	} while('\n' != data);
	
	return str;
}

/** End of File ***************************************************************/
