/** @file timer_hal_sample.c
 *  @brief Definition of Timer driver sample application function and data.
 *
 *  This is the source file for the definition of Timer driver sample application.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 * -----------------------------------------------------------------------------
 */

#ifdef TIMER_HAL_SAMPLE
 
/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "timer_hal_sample.h"

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
extern const Struct_Timer_PrescalerValue_Typedef PrescalerValue_array[5];

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void Timer_Setup(void){
    cli();
    Enum_Timer_TCCRnB_ClockSelect_Typedef prescalerName_enum = Timer_TCCRnB_NoClockSource;
    uint16_t clockPrescaler_uint16 = suggestPrescalerValue(1, Timer_16bitTimerMaxCounterValue);
    
    for(uint8_t i = 0; i < sizeof(PrescalerValue_array)/sizeof(PrescalerValue_array[0]); i++ ){
        if(clockPrescaler_uint16 == PrescalerValue_array[i].prescalerValue_uint16){
            prescalerName_enum = PrescalerValue_array[i].prescalerName_enum;
        }
    }
    
    Struct_Timer_Config_Typedef config_struct;
    config_struct.compareOutputMode_enum = Timer_TCCRnA_CompareOutputMode0;
    config_struct.waveformGenerationMode_enum = Timer_TCCRnA_WaveformGenerationMode2;
    config_struct.clockPrescaler_enum = prescalerName_enum;
    config_struct.compareOutputValue_uint8 = 100;
    Timer_InitTimer1(&config_struct, Timer_ChannelA);
    sei();
}

void Timer_Loop(void){	
    while(1){
    
    }
}

#endif /* TIMER_HAL_SAMPLE */

/** End of File ***************************************************************/
