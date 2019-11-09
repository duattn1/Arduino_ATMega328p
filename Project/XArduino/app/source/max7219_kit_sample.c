/** @file max7219_kit_sample.c
 *  @brief Definition of LED matrix (based on Max7219) sample application 
 *         function and data.
 *
 *  This is the source file for the definition of LED matrix (based on Max7219) 
 *  sample application.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 * -----------------------------------------------------------------------------
 */

#ifdef MAX7219_KIT_SAMPLE
 
/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "max7219_kit_sample.h"

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
extern const uint8_t CharacterLib_array[43][8];

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void Max7219_Setup(void){
    init_Max7219();	
    for(uint8_t i = 0; i < 8; i++){
        write_Max7219(i + 1, CharacterLib_array['A' - '0'][i]);
    }
}

void Max7219_Loop(void){	
    while(1){
    
    }
}

#endif /* MAX7219_KIT_SAMPLE */

/** End of File ***************************************************************/
