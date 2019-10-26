/** @file sample.c
 *  @brief Function implementation for Arduino samples.
 *
 *  This is the source file for the definition of Arduino samples.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 */
 
/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "sample.h"

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/
/* Arduino Nano clock frequency */
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/


/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Pointers, Others
 ******************************************************************************/


/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/
extern const uint8_t characterLib[43][8];

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void setup(void){
#ifdef GPIO_SAMPLE	
	pinMode(ARDUINO_NANO_USER_LED, GPIO_DDRx_Output);
	digitalWrite(ARDUINO_NANO_USER_LED, HIGH);
#endif

#ifdef USART_SAMPLE
	uint8_t *strStart = "Start";
	uint8_t *strEnd = "End";
	USART_Config_Typedef config;
	config.mode = USART_UCSRnC_AsyncMode;
	config.parity = USART_UCSRnC_DisabledParity;
	config.stopBit = USART_UCSRnC_1StopBit;
	config.dataFrame = USART_UCSRnC_8bitsData;
	initUSART(&config);
	setBaudrate(USART_9600bps);
	commandTransmitter(ENABLE);
	commandReceiver(ENABLE);
	sendString(strStart);
#endif


	SPI_Config_Typedef config;
	config.dataTxOrder = SPI_SPCR_TransmitMSBFirst;
	config.masterSlaveMode = SPI_SPCR_MasterMode;
	config.clockPolarity = SPI_SPCR_IdleLow;
	config.clockPhase = SPI_SPCR_LeadingEdgeSampling;
	config.clockFrequency = SPI_FoscDiv16 ;
	initSPI(&config);
	commandSPI(ENABLE);
	masterTransmit('A');


#ifdef MAX7219_SAMPLE	
	init_Max7219();
	uint8_t i;
	for(i = 0; i < 8; i++){
		write_Max7219(i + 1, characterLib['A' - '0'][i]);
	}
#endif
	
	

}

void loop(void){	
	while(1){
		
	}	
}

/** End of File ***************************************************************/
