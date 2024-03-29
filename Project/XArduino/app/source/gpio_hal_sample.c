/** @file gpio_hal_sample.c
 *  @brief Definition of GPIO driver sample application function and data.
 *
 *  This is the source file for the definition of GPIO driver sample application.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 * -----------------------------------------------------------------------------
 */

#ifdef GPIO_HAL_SAMPLE
 
/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "gpio_hal_sample.h"

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

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void Gpio_Setup(void){
    pinMode(ARDUINO_NANO_USER_LED, Gpio_DDRx_Output);
    digitalWrite(ARDUINO_NANO_USER_LED, High);
}

void Gpio_Loop(void){	
    while(1){
    
    }
}

#endif /* GPIO_HAL_SAMPLE */

/** End of File ***************************************************************/
