/** @file sample.c
 *  @brief Definition of sample application function and data.
 *
 *  This is the source file for the definition of sample application.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * TODO<<Jan 01, 2019>> - TODO<< WHAT WAS UPDATED?>>
 * -----------------------------------------------------------------------------
 */
 
/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "sample.h"

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
void Sample_RunApp(void){

/** HAL sample application ****************************************************/	

#ifdef GPIO_HAL_SAMPLE
Gpio_Setup();
Gpio_Loop();
#endif

#ifdef USART_HAL_SAMPLE
Usart_Setup();
Usart_Loop();
#endif

#ifdef SPI_HAL_SAMPLE
Spi_Setup();
Spi_Loop();
#endif

#ifdef TIMER_HAL_SAMPLE
Timer_Setup();
Timer_Loop();
#endif

/** Kits sample application ***************************************************/
#ifdef MAX7219_KIT_SAMPLE	
Max7219_Setup();
Max7219_Loop();
#endif	

}



/** End of File ***************************************************************/
