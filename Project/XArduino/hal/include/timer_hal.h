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
 * @enum This enumeration is a list of TODO.
 */
typedef enum
{
	Timer_ChannelA,		/**< Timer channel A */
	Timer_ChannelB,		/**< Timer channel B */
} Enum_Timer_Channels_Typedef;

/**
 * @enum This enumeration is a list of TODO.
 */
typedef enum
{
	Timer_TCCR0A_CompareOutputMode0 = 0,		/**< Compare output mode 0 */
	Timer_TCCR0A_CompareOutputMode1,			/**< Compare output mode 1 */
	Timer_TCCR0A_CompareOutputMode2,			/**< Compare output mode 2 */
	Timer_TCCR0A_CompareOutputMode3				/**< Compare output mode 3 */
} Enum_Timer_TCCR0A_CompareMatchOutputMode_Typedef;


/** Region: Waveform Generation Mode enumerations *****************************/

/**
 * @enum This enumeration is a list of waveform generation modes.
 * @note Waveform generation modes are described in below table.
 *
 * |--------------------------------------------------------------------------------|
 * |Mode|WGM02	|WGM01	|WGM00	|Timer/Counter		|TOP	|Update of	|TOV Flag	|
 * |	|		|		|		|Mode of			|		|OCRx at	|Set on		|
 * |	|		|		|		|Operation			|		|			|			|
 * |--------------------------------------------------------------------------------|
 * |0	0		0		0		Normal				0xFF	Immediate	MAX			|
 * |1	0		0		1		PWM, phase correct	0xFF	TOP			BOTTOM		|
 * |2	0		1		0		CTC					OCRA	Immediate	MAX			|
 * |3	0		1		1		Fast PWM			0xFF	BOTTOM		MAX			|
 * |4	1		0		0		Reserved			–		–			–			|
 * |5	1		0		1		PWM,phase correct	OCRA	TOP			BOTTOM		|
 * |6	1		1		0		Reserved			–		–			–			|
 * |7	1		1		1		Fast PWM			OCRA	BOTTOM		TOP			|
 * |--------------------------------------------------------------------------------|
 */
typedef enum
{
	Timer_TCCR0A_WaveformGenerationMode0 = 0,	/**< Waveform generation mode 0 */
	Timer_TCCR0A_WaveformGenerationMode1,		/**< Waveform generation mode 1 */
	Timer_TCCR0A_WaveformGenerationMode2,		/**< Waveform generation mode 2 */
	Timer_TCCR0A_WaveformGenerationMode3,		/**< Waveform generation mode 3 */
	Timer_TCCR0A_WaveformGenerationMode4,		/**< Waveform generation mode 4 */
	Timer_TCCR0A_WaveformGenerationMode5,		/**< Waveform generation mode 5 */
	Timer_TCCR0A_WaveformGenerationMode6,		/**< Waveform generation mode 6 */
	Timer_TCCR0A_WaveformGenerationMode7		/**< Waveform generation mode 7 */
} Enum_Timer_TCCR0A_WaveformGenerationMode_Typedef;

/** End region: Waveform Generation Mode enumerations *************************/

/**
 * @enum This enumeration is a list of clock source selections.
 */
typedef enum
{
	Timer_TCCR0B_NoClockSource = 0,							/**< No clock source (Timer/Counter stopped) */
	Timer_TCCR0B_ClkIoDiv1,									/**< IO clock frequency divided by 1 */
	Timer_TCCR0B_ClkIoDiv8,									/**< IO clock frequency divided by 8 */
	Timer_TCCR0B_ClkIoDiv64,								/**< IO clock frequency divided by 64 */
	Timer_TCCR0B_ClkIoDiv256,								/**< IO clock frequency divided by 256 */
	Timer_TCCR0B_ClkIoDiv1024,								/**< IO clock frequency divided by 1024 */
	Timer_TCCR0B_T0PinExternalClock_FallingEdgeClocked,		/**< External clock source on T0 pin. Clock on falling edge */
	Timer_TCCR0B_T0PinExternalClock_RisingEdgeClocked		/**< External clock source on T0 pin. Clock on rising edge */
} Enum_Timer_TCCR0B_ClockSelect_Typedef;

/**
 * @struct This structure is for Timer configuration.
 */
typedef struct {
	Enum_Timer_TCCR0A_CompareMatchOutputMode_Typedef compareOutputMode;
	Enum_Timer_TCCR0A_WaveformGenerationMode_Typedef waveformGenerationMode;
	Enum_Timer_TCCR0B_ClockSelect_Typedef clockPrescaler;
	uint8_t compareOutputValue;
} Struct_Timer_Config_Typedef;

/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/


/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/** @brief Initialize Timer module
 *
 *  @param config Initializing configuration
 *  @param channel Timer channel selection
 *  @return none
 */
void Timer_InitTimer(Struct_Timer_Config_Typedef *config, Enum_Timer_Channels_Typedef channel);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* TIMER_HAL_H_ */

/** End of File ***************************************************************/
