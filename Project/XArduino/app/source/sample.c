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
	Gpio_PinMode(ARDUINO_NANO_USER_LED, GPIO_DDRx_Output);
	Gpio_DigitalWrite(ARDUINO_NANO_USER_LED, High);
#endif

#ifdef USART_SAMPLE
	uint8_t *strStart = "Start";
	uint8_t *strEnd = "End";
	Struct_Usart_Config_Typedef config;
	config.mode = Usart_UCSRnC_AsyncMode;
	config.parity = Usart_UCSRnC_DisabledParity;
	config.stopBit = Usart_UCSRnC_1StopBit;
	config.dataFrame = Usart_UCSRnC_8bitsData;
	Usart_InitUSART(&config);
	Usart_SetBaudrate(Usart_9600bps);
	Usart_CommandTransmitter(Enable);
	Usart_CommandReceiver(Enable);
	Usart_SendString(strStart);
#endif

#ifdef SPI_SAMPLE
	Struct_Spi_Config_Typedef config;
	config.dataTxOrder = Spi_SPCR_TransmitMSBFirst;
	config.masterSlaveMode = Spi_SPCR_MasterMode;
	config.clockPolarity = Spi_SPCR_IdleLow;
	config.clockPhase = Spi_SPCR_LeadingEdgeSampling;
	config.clockFrequency = Spi_FoscDiv16 ;
	Spi_InitSPI(&config);
	Spi_CommandSPI(Enable);
	Spi_MasterTransmit('A');
#endif

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
