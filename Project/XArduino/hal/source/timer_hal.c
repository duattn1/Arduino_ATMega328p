/** @file timer_hal.c
 *  @brief Function implementation for Timer driver.
 *
 *  This is the source file for the definition of Timer driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 */

#ifdef USE_TIMER_HAL
 
/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "timer_hal.h"

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
void Timer_InitTimer(Struct_Timer_Config_Typedef *config, Enum_Timer_Channels_Typedef channel){
	uint8_t COM0x0_Position;
	uint8_t *OCR0x_Ptr;
	uint8_t WGMn2 = (config->waveformGenerationMode) & 0x04;
	uint8_t WGMn1To0 = (config->waveformGenerationMode) & 0x03;
	
	if (Timer_ChannelA == channel)
	{
		COM0x0_Position = COM0A0;
		OCR0x_Ptr = (uint8_t*)&OCR0A;
	} 
	else if (Timer_ChannelB == channel)
	{
		COM0x0_Position = COM0B0;
		OCR0x_Ptr = (uint8_t*)&OCR0B;
	}
	
	// Select compare output mode for channel
	TCCR0A &= ~(MASK_2BIT << COM0x0_Position);
	TCCR0A |= config->compareOutputMode << COM0x0_Position;
	// Select waveform generation mode for channel
	TCCR0B &= ~(MASK_1BIT << WGM02);
	TCCR0A &= ~(MASK_2BIT << WGM00);
	TCCR0B |= WGMn2 << WGM02;
	TCCR0A |= WGMn1To0 << WGM00;	
	// Select Timer clock prescaler
	TCCR0B &= ~(MASK_3BIT << CS00);
	TCCR0B |= config->clockPrescaler << CS00;	
	// Set compared output value
	*OCR0x_Ptr = config->compareOutputValue;	
}

#endif /* USE_TIMER_HAL */

/** End of File ***************************************************************/
