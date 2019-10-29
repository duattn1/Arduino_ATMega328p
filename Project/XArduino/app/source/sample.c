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


/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/


/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Pointers, Others
 ******************************************************************************/


/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/
extern const uint8_t CharacterLib_array[43][8];
extern const Struct_Timer_PrescalerValue_Typedef PrescalerValue_array[5];

#ifdef USART_HAL_SAMPLE
const Struct_Usart_Config_Typedef UsartSampleConfig[1] = 
{
	{ Usart_UCSRnC_AsyncMode, Usart_UCSRnC_DisabledParity,
	Usart_UCSRnC_1StopBit, Usart_UCSRnC_8bitsData }
};
#endif

#ifdef SPI_HAL_SAMPLE
Struct_Spi_Config_Typedef SpiSampleConfig[1] =
{
	{ Spi_SPCR_TransmitMSBFirst, Spi_SPCR_MasterMode,
	Spi_SPCR_IdleLow, Spi_SPCR_LeadingEdgeSampling,	Spi_FoscDiv16 }
};
#endif
/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void setup(void){
#ifdef GPIO_HAL_SAMPLE	
	Gpio_PinMode(ARDUINO_NANO_USER_LED, GPIO_DDRx_Output);
	Gpio_DigitalWrite(ARDUINO_NANO_USER_LED, High);
#endif

#ifdef USART_HAL_SAMPLE
	uint8_t strStart_uint8[] = "Start";
	Usart_InitUSART(&UsartSampleConfig[0]);
	Usart_SetBaudrate(Usart_9600bps);
	Usart_CommandTransmitter(Enable);
	//Usart_CommandReceiver(Enable);
	Usart_SendString(strStart_uint8);	
#endif

#ifdef SPI_HAL_SAMPLE	
	Spi_InitSPI(&SpiSampleConfig[0]);
	Spi_CommandSPI(Enable);
	Spi_MasterTransmit('A');
#endif

#ifdef TIMER_HAL_SAMPLE	
	Enum_Timer_TCCR0B_ClockSelect_Typedef prescalerName_enum = Timer_TCCR0B_NoClockSource;
	uint16_t clockPrescaler_uint16 = suggestPrescalerValue(1, Timer_16bitTimerMaxCounterValue);
	
	for(uint8_t i = 0; i < sizeof(PrescalerValue_array)/sizeof(PrescalerValue_array[0]); i++ ){
		if(clockPrescaler_uint16 == PrescalerValue_array[i].prescalerValue){
			prescalerName_enum = PrescalerValue_array[i].prescalerName;
		}
	}
	
	Struct_Timer_Config_Typedef config_struct;
	config_struct.compareOutputMode = Timer_TCCR0A_CompareOutputMode0;
	config_struct.waveformGenerationMode = Timer_TCCR0A_WaveformGenerationMode2;
	config_struct.clockPrescaler = prescalerName_enum;
	config_struct.compareOutputValue = 100;
	Timer_InitTimer(&config_struct, Timer_ChannelA);
#endif

#ifdef MAX7219_KIT_SAMPLE	
	init_Max7219();	
	for(uint8_t i = 0; i < 8; i++){
		write_Max7219(i + 1, CharacterLib_array['A' - '0'][i]);
	}
#endif	



}

void loop(void){	
	while(1){
		
	}	
}

/** End of File ***************************************************************/
