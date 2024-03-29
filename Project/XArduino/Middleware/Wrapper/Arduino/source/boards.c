/** @file boards.c
 *  @brief Definition of Arduino boards pin mapping.
 *
 *  This is the source file for the definition of Arduino boards pin mapping.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 * -----------------------------------------------------------------------------
 */
 
/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "boards.h"

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
#ifdef ARDUINO_NANO
const Struct_BoardPin_Typedef Pins_array[20] = 
{
    {Gpio_PortD, Gpio_Pin0},    /* Arduino Nano Pin 0 */
    {Gpio_PortD, Gpio_Pin1},    /* Arduino Nano Pin 1 */
    {Gpio_PortD, Gpio_Pin2},    /* Arduino Nano Pin 2 */
    {Gpio_PortD, Gpio_Pin3},    /* Arduino Nano Pin 3 */
    {Gpio_PortD, Gpio_Pin4},    /* Arduino Nano Pin 4 */
    {Gpio_PortD, Gpio_Pin5},    /* Arduino Nano Pin 5 */
    {Gpio_PortD, Gpio_Pin6},    /* Arduino Nano Pin 6 */
    {Gpio_PortD, Gpio_Pin7},    /* Arduino Nano Pin 7 */
    {Gpio_PortB, Gpio_Pin0},    /* Arduino Nano Pin 8 */
    {Gpio_PortB, Gpio_Pin1},    /* Arduino Nano Pin 9 */
    {Gpio_PortB, Gpio_Pin2},    /* Arduino Nano Pin 10 */
    {Gpio_PortB, Gpio_Pin3},    /* Arduino Nano Pin 11 */
    {Gpio_PortB, Gpio_Pin4},    /* Arduino Nano Pin 12 */
    {Gpio_PortB, Gpio_Pin5},    /* Arduino Nano Pin 13 */
    {Gpio_PortC, Gpio_Pin0},    /* Arduino Nano Pin 14 */
    {Gpio_PortC, Gpio_Pin1},    /* Arduino Nano Pin 15 */
    {Gpio_PortC, Gpio_Pin2},    /* Arduino Nano Pin 16 */
    {Gpio_PortC, Gpio_Pin3},    /* Arduino Nano Pin 17 */
    {Gpio_PortC, Gpio_Pin4},    /* Arduino Nano Pin 18 */
    {Gpio_PortC, Gpio_Pin5}     /* Arduino Nano Pin 19 */
};
#endif /* ARDUINO_NANO */

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/

/** End of File ***************************************************************/
