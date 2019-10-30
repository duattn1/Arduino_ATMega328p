/** @file timer_hal.h
 *  @brief Function prototypes for Timer driver.
 * 
 *  This is the header file for the definition of Timer driver.
 *  
 * 	@author Tran Nhat Duat (duattn)
 *	@version 	V1.0
 */

#ifndef TIMER_HAL_H_
#define TIMER_HAL_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include <avr/io.h>
#include <stdint.h>
#include <stddef.h>
#include "boards.h"
#include "misc.h"

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/


/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/

	
/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Pointers, Others
 ******************************************************************************/
/**
 * @enum This enumeration is a list n-bit Timers max counter value.
 */
typedef enum
{
	Timer_8bitTimerMaxCounterValue = 254,		/**< 8-bit Timer */
	Timer_16bitTimerMaxCounterValue = 65535		/**< 16-bit Timer */
} Enum_Timer_TimerMaxCounterValue_Typedef;

/**
 * @enum This enumeration is a list of TODO.
 */
typedef enum
{
	Timer_ChannelA,		/**< Timer channel A */
	Timer_ChannelB		/**< Timer channel B */
} Enum_Timer_Channels_Typedef;

/**
 * @enum This enumeration is a list of TODO.
 */
typedef enum
{
	Timer_TCCRnA_CompareOutputMode0 = 0,		/**< Compare output mode 0 */
	Timer_TCCRnA_CompareOutputMode1,			/**< Compare output mode 1 */
	Timer_TCCRnA_CompareOutputMode2,			/**< Compare output mode 2 */
	Timer_TCCRnA_CompareOutputMode3				/**< Compare output mode 3 */
} Enum_Timer_TCCRnA_CompareMatchOutputMode_Typedef;


/** Region: Waveform Generation Mode enumerations *****************************/

/**
 * @enum This enumeration is a list of waveform generation modes.
 * @note There are only 8 modes (mode 0 to mode 7) for Timer 0, but 16 modes for Timer 1
 *       Waveform generation modes are described in below table.
 *       
 *       + Timer 0 waveform generation modes
 * |--------------------------------------------------------------------------------|
 * |Mode|WGM02	|WGM01	|WGM00	|Timer/Counter		|TOP	|Update of	|TOV Flag	|
 * |	|		|		|		|Mode of			|		|OCRx at	|Set on		|
 * |	|		|		|		|Operation			|		|			|			|
 * |--------------------------------------------------------------------------------|
 * |0	0		0		0		Normal				0xFF	Immediate	MAX			|
 * |1	0		0		1		PWM, phase correct	0xFF	TOP			BOTTOM		|
 * |2	0		1		0		CTC					OCRA	Immediate	MAX			|
 * |3	0		1		1		Fast PWM			0xFF	BOTTOM		MAX			|
 * |4	1		0		0		Reserved			N/a		N/a			N/a			|
 * |5	1		0		1		PWM,phase correct	OCRA	TOP			BOTTOM		|
 * |6	1		1		0		Reserved			N/a		N/a			N/a			|
 * |7	1		1		1		Fast PWM			OCRA	BOTTOM		TOP			|
 * |--------------------------------------------------------------------------------|
 * 
 *       + Timer 1 waveform generation modes
 * |------------------------------------------------------------------------------------------------|
 * |Mode|WGM13	|WGM12	|WGM11	|WGM10	|Timer/Counter				|TOP	|Update of	|TOV Flag	|
 * |	|		|		|		|		|Mode of					|		|OCRx at	|Set on		|
 * |	|		|		|		|		|Operation					|		|			|			|
 * |------------------------------------------------------------------------------------------------|
 * |0	0		0		0		0		Normal						0xFFFF	Immediate	MAX			|
 * |1	0		0		0		1		PWM, phase correct, 8-bit	0x00FF	TOP			BOTTOM		|
 * |2	0		0		1		0		PWM, phase correct, 9-bit	0x01FF	TOP			BOTTOM		|
 * |3	0		0		1		1		PWM, phase correct, 10-bit	0x03FF	TOP			BOTTOM		|
 * |4	0		1		0		0		CTC							OCR1A	Immediate	MAX			|
 * |5	0		1		0		1		Fast PWM, 8-bit				0x00FF	BOTTOM		TOP			|
 * |6	0		1		1		0		Fast PWM, 9-bit				0x01FF	BOTTOM		TOP			|
 * |7	0		1		1		1		Fast PWM, 10-bit			0x03FF	BOTTOM		TOP			|
 * |8	1		0		0		0		PWM, phase & freq correct	ICR1	BOTTOM		BOTTOM		|
 * |9	1		0		0		1		PWM, phase & freq correct	OCR1A	BOTTOM		BOTTOM		|
 * |10	1		0		1		0		PWM, phase correct			ICR1	TOP			BOTTOM		|
 * |11	1		0		1		1		PWM, phase correct			OCR1A	TOP			BOTTOM		|
 * |12	1		1		0		0		CTC							ICR1	Immediate	MAX			|
 * |13	1		1		0		1		(Reserved)					N/a		N/a			N/a			|
 * |14	1		1		1		0		Fast PWM					ICR1	BOTTOM		TOP			|
 * |15	1		1		1		1		Fast PWM					OCR1A	BOTTOM		TOP			|
 * |------------------------------------------------------------------------------------------------|
 */
typedef enum
{
	Timer_TCCRnA_WaveformGenerationMode0 = 0,	/**< Waveform generation mode 0 */
	Timer_TCCRnA_WaveformGenerationMode1,		/**< Waveform generation mode 1 */
	Timer_TCCRnA_WaveformGenerationMode2,		/**< Waveform generation mode 2 */
	Timer_TCCRnA_WaveformGenerationMode3,		/**< Waveform generation mode 3 */
	Timer_TCCRnA_WaveformGenerationMode4,		/**< Waveform generation mode 4 */
	Timer_TCCRnA_WaveformGenerationMode5,		/**< Waveform generation mode 5 */
	Timer_TCCRnA_WaveformGenerationMode6,		/**< Waveform generation mode 6 */
	Timer_TCCRnA_WaveformGenerationMode7,		/**< Waveform generation mode 7 */
	Timer_TCCRnA_WaveformGenerationMode8,		/**< Waveform generation mode 8 */
	Timer_TCCRnA_WaveformGenerationMode9,		/**< Waveform generation mode 9 */
	Timer_TCCRnA_WaveformGenerationMode10,		/**< Waveform generation mode 10 */
	Timer_TCCRnA_WaveformGenerationMode11,		/**< Waveform generation mode 11 */
	Timer_TCCRnA_WaveformGenerationMode12,		/**< Waveform generation mode 12 */
	Timer_TCCRnA_WaveformGenerationMode13,		/**< Waveform generation mode 13 */
	Timer_TCCRnA_WaveformGenerationMode14,		/**< Waveform generation mode 14 */
	Timer_TCCRnA_WaveformGenerationMode15		/**< Waveform generation mode 15 */
} Enum_Timer_TCCRnA_WaveformGenerationMode_Typedef;

/** End region: Waveform Generation Mode enumerations *************************/

/**
 * @enum This enumeration is a list of clock source selections.
 */
typedef enum
{
	Timer_TCCRnB_NoClockSource = 0,							/**< No clock source (Timer/Counter stopped) */
	Timer_TCCRnB_ClkIoDiv1,									/**< IO clock frequency divided by 1 */
	Timer_TCCRnB_ClkIoDiv8,									/**< IO clock frequency divided by 8 */
	Timer_TCCRnB_ClkIoDiv64,								/**< IO clock frequency divided by 64 */
	Timer_TCCRnB_ClkIoDiv256,								/**< IO clock frequency divided by 256 */
	Timer_TCCRnB_ClkIoDiv1024,								/**< IO clock frequency divided by 1024 */
	Timer_TCCRnB_TnPinExternalClock_FallingEdgeClocked,		/**< External clock source on T0 pin. Clock on falling edge */
	Timer_TCCRnB_TnPinExternalClock_RisingEdgeClocked		/**< External clock source on T0 pin. Clock on rising edge */
} Enum_Timer_TCCRnB_ClockSelect_Typedef;

/**
 * @struct This structure is for Timer configuration.
 */
typedef struct {
	Enum_Timer_TCCRnA_CompareMatchOutputMode_Typedef compareOutputMode_enum;
	Enum_Timer_TCCRnA_WaveformGenerationMode_Typedef waveformGenerationMode_enum;
	Enum_Timer_TCCRnB_ClockSelect_Typedef clockPrescaler_enum;
	uint8_t compareOutputValue_uint8;
} Struct_Timer_Config_Typedef;

/**
 * @struct This structure is for mapping TCCR0B Clock Select options to their real value.
 */
typedef struct {
	Enum_Timer_TCCRnB_ClockSelect_Typedef prescalerName_enum;
	uint16_t prescalerValue_uint16;
} Struct_Timer_PrescalerValue_Typedef;

/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/


/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/** @brief Initialize Timer 0 module
 *
 *  @param config_ptr Initializing configuration
 *  @param channel_enum Timer 0 channel selection
 *  @return none
 */
void Timer_InitTimer0(Struct_Timer_Config_Typedef *config_ptr, Enum_Timer_Channels_Typedef channel_enum);

/** @brief Initialize Timer 1 module
 *
 *  @param config_ptr Initializing configuration
 *  @param channel_enum Timer 1 channel selection
 *  @return none
 */
void Timer_InitTimer1(Struct_Timer_Config_Typedef *config_ptr, Enum_Timer_Channels_Typedef channel_enum);

/** @brief Suggest a prescaler value to make interrupt after a number of seconds
 *
 *  @param seconds_uint32 Number of seconds that makes the Timer interrupt occur
 *  @param maxCounterValue_enum Maximum counter value of n-bit Timer
 *  @return none
 */
uint16_t suggestPrescalerValue(uint32_t seconds_uint32, Enum_Timer_TimerMaxCounterValue_Typedef maxCounterValue_enum);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* TIMER_HAL_H_ */

/** End of File ***************************************************************/
