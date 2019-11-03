/** @file timer_hal.c
 *  @brief Definition of Timer driver function and data.
 *
 *  This is the source file for the definition of Timer driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * TODO<<Jan 01, 2019>> - TODO<< WHAT WAS UPDATED?>>
 * -----------------------------------------------------------------------------
 */

#ifdef TIMER_HAL
 
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
 * 4. Typedefs: Enumerations, Structures, Unions, Pointers, Others
 ******************************************************************************/

/*******************************************************************************
 * 5. Global, Static, Constant, Extern Variables and Extern Functions
 ******************************************************************************/
const Struct_Timer_PrescalerValue_Typedef PrescalerValue_array[5] = 
{
    {Timer_TCCRnB_ClkIoDiv1, 1},
    {Timer_TCCRnB_ClkIoDiv8, 8},
    {Timer_TCCRnB_ClkIoDiv64, 64},
    {Timer_TCCRnB_ClkIoDiv256, 256},
    {Timer_TCCRnB_ClkIoDiv1024, 1024}
};

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void Timer_InitTimer0(Struct_Timer_Config_Typedef *config_ptr, Enum_Timer_Channels_Typedef channel_enum){
    /* TODO; show error when (compareOutputValue_uint8 > 255) AND (waveformGenerationMode_enum > mode7) */
    uint8_t COM0x0_Position_uint8, OCIE0x_Position_uint8;
    uint8_t *OCR0x_ptr;
    uint8_t WGM0_Bit2_uint8 = (config_ptr->waveformGenerationMode_enum) & 0x04;
    uint8_t WGM0_Bit1To0_uint8 = (config_ptr->waveformGenerationMode_enum) & 0x03;
    
    if (Timer_ChannelA == channel_enum)
    {
        COM0x0_Position_uint8 = COM0A0;
        OCIE0x_Position_uint8 = OCIE0A;
        OCR0x_ptr = (uint8_t*)&OCR0A;
    } 
    else if (Timer_ChannelB == channel_enum)
    {
        COM0x0_Position_uint8 = COM0B0;
        OCIE0x_Position_uint8 = OCIE0B;
        OCR0x_ptr = (uint8_t*)&OCR0B;
    }

    /* Select compare output mode for channel */ 
    TCCR0A &= ~(MASK_2BIT << COM0x0_Position_uint8);
    TCCR0A |= config_ptr->compareOutputMode_enum << COM0x0_Position_uint8;
    /* Select waveform generation mode for channel */
    TCCR0B &= ~(MASK_1BIT << WGM02);
    TCCR0A &= ~(MASK_2BIT << WGM00);
    TCCR0B |= WGM0_Bit2_uint8 << WGM02;
    TCCR0A |= WGM0_Bit1To0_uint8 << WGM00;
    /* Select Timer clock prescaler */
    TCCR0B &= ~(MASK_3BIT << CS00);
    TCCR0B |= config_ptr->clockPrescaler_enum << CS00;
    /* Set compared output value */
    *OCR0x_ptr = config_ptr->compareOutputValue_uint8;
    /* Enable Output compare match interrupt */
    TIMSK1 |= 1 << OCIE0x_Position_uint8;
}

void Timer_InitTimer1(Struct_Timer_Config_Typedef *config_ptr, Enum_Timer_Channels_Typedef channel_enum){
    uint8_t COM1x0_Position_uint8, OCIE1x_Position_uint8;
    uint8_t *OCR1xL_ptr, *OCR1xH_ptr;
    uint8_t WGM1_Bit3To2_uint8 = (config_ptr->waveformGenerationMode_enum) & 0x0C;
    uint8_t WGM1_Bit1To0_uint8 = (config_ptr->waveformGenerationMode_enum) & 0x03;
    
    if (Timer_ChannelA == channel_enum)
    {
        COM1x0_Position_uint8 = COM1A0;
        OCIE1x_Position_uint8 = OCIE1A;
        OCR1xL_ptr = (uint8_t*)&OCR1AL;
        OCR1xH_ptr = (uint8_t*)&OCR1AH;
    } 
    else if (Timer_ChannelB == channel_enum)
    {
        COM1x0_Position_uint8 = COM1B0;
        OCIE1x_Position_uint8 = OCIE1B;
        OCR1xL_ptr = (uint8_t*)&OCR1BL;
        OCR1xH_ptr = (uint8_t*)&OCR1BH;
    }
    
    /* Select compare output mode for channel */
    TCCR1A &= ~(MASK_2BIT << COM1x0_Position_uint8);
    TCCR1A |= config_ptr->compareOutputMode_enum << COM1x0_Position_uint8;
    /* Select waveform generation mode for channel */
    TCCR1B &= ~(MASK_2BIT << WGM12);
    TCCR1A &= ~(MASK_2BIT << WGM10);
    TCCR1B |= WGM1_Bit3To2_uint8 << WGM12;
    TCCR1A |= WGM1_Bit1To0_uint8 << WGM10;
    /* Select Timer clock prescaler */
    TCCR1B &= ~(MASK_3BIT << CS10);
    TCCR1B |= config_ptr->clockPrescaler_enum << CS10;
    /* Set compared output value */
    *OCR1xL_ptr = (config_ptr->compareOutputValue_uint8) & MASK_8BIT;
    *OCR1xH_ptr = (config_ptr->compareOutputValue_uint8) & (MASK_8BIT << 8);
    /* Enable Output compare match interrupt */
    TIMSK1 |= 1 << OCIE1x_Position_uint8;
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

#endif /* TIMER_HAL */

/** End of File ***************************************************************/
