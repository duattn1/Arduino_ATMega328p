/** @file wrapper_arduinoUsart.h
 *  @brief Declaration of Arduino wrapper for USART driver function and data.
 *
 *  This is the header file for the definition of Arduino wrapper for USART driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Initial version
 * -----------------------------------------------------------------------------
 */

#ifndef WRAPPER_ARDUINOUSART_H_
#define WRAPPER_ARDUINOUSART_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "config_middleware.h"
#include "boards.h"
#include "usart_hal.h"

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/

/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/

/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Unions, Pointers, Others
 ******************************************************************************/
/**
 * 
 */ 
#ifdef __cplusplus
class Serial
{
    public:
        void begin(Enum_Usart_Baudrate_Typedef baudrate_enum);
        void print(char *string_ptr);
    protected:
    private:
};
#endif

/*******************************************************************************
 * 5. Global, Static, Constant, Extern Variables and Extern Functions
 ******************************************************************************/

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WRAPPER_ARDUINOUSART_H_ */

/** End of File ***************************************************************/
