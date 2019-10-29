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
const Struct_Timer_PrescalerValue_Typedef PrescalerValue_array[5] = 
{
	{Timer_TCCR0B_ClkIoDiv1, 1},
	{Timer_TCCR0B_ClkIoDiv8, 8},
	{Timer_TCCR0B_ClkIoDiv64, 64},
	{Timer_TCCR0B_ClkIoDiv256, 256},
	{Timer_TCCR0B_ClkIoDiv1024, 1024}
};

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void Timer_InitTimer(Struct_Timer_Config_Typedef *config_ptr, Enum_Timer_Channels_Typedef channel_enum){
	uint8_t COM0x0_Position_uint8;
	uint8_t *OCR0x_ptr;
	uint8_t WGMn2_uint8 = (config_ptr->waveformGenerationMode) & 0x04;
	uint8_t WGMn1To0_uint8 = (config_ptr->waveformGenerationMode) & 0x03;
	
	if (Timer_ChannelA == channel_enum)
	{
		COM0x0_Position_uint8 = COM0A0;
		OCR0x_ptr = (uint8_t*)&OCR0A;
	} 
	else if (Timer_ChannelB == channel_enum)
	{
		COM0x0_Position_uint8 = COM0B0;
		OCR0x_ptr = (uint8_t*)&OCR0B;
	}
	
	// Select compare output mode for channel
	TCCR0A &= ~(MASK_2BIT << COM0x0_Position_uint8);
	TCCR0A |= config_ptr->compareOutputMode << COM0x0_Position_uint8;
	// Select waveform generation mode for channel
	TCCR0B &= ~(MASK_1BIT << WGM02);
	TCCR0A &= ~(MASK_2BIT << WGM00);
	TCCR0B |= WGMn2_uint8 << WGM02;
	TCCR0A |= WGMn1To0_uint8 << WGM00;	
	// Select Timer clock prescaler
	TCCR0B &= ~(MASK_3BIT << CS00);
	TCCR0B |= config_ptr->clockPrescaler << CS00;	
	// Set compared output value
	*OCR0x_ptr = config_ptr->compareOutputValue;	
}

uint16_t suggestPrescalerValue(uint32_t seconds_uint32, Enum_Timer_TimerMaxCounterValue_Typedef maxCounterValue_enum){
	uint16_t suggestedValue_uint16 = 0;
	uint32_t outputCompareValue_uint32 = 0;
	uint16_t prescalers_array[] = {1, 8, 64, 256, 1024};
	
	/* Look for the first prescaler value that less than or equal the maximum counter value of n-bit Timer */
	for(uint8_t i = 0; i < (sizeof(prescalers_array)/sizeof(prescalers_array[0])); i++) {
		outputCompareValue_uint32 = (F_CPU/prescalers_array[i])*seconds_uint32 - 1; /* F_CPU represents the main clock frequency. */
		if(outputCompareValue_uint32 <= maxCounterValue_enum){
			suggestedValue_uint16 = prescalers_array[i];
			break;
		}
	}
	
	return suggestedValue_uint16;
}

#endif /* USE_TIMER_HAL */

/** End of File ***************************************************************/
