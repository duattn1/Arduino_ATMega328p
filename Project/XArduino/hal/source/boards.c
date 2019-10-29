/** @file boards.c
 *  @brief Pin mapping of Arduino boards.
 *
 *  This is the source file for the definition of pin mapping of Arduino boards.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
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
 * 4. Typedefs: Enumerations, Structures, Pointers, Others
 ******************************************************************************/


/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/
#ifdef ARDUINO_NANO
const Struct_BoardPin_Typedef pins[20] = 
	{
	{Gpio_PortD, Gpio_Pin0},	/* Arduino Nano Pin 0 */
	{Gpio_PortD, Gpio_Pin1},	/* Arduino Nano Pin 1 */
	{Gpio_PortD, Gpio_Pin2},	/* Arduino Nano Pin 2 */
	{Gpio_PortD, Gpio_Pin3},	/* Arduino Nano Pin 3 */
	{Gpio_PortD, Gpio_Pin4},	/* Arduino Nano Pin 4 */
	{Gpio_PortD, Gpio_Pin5},	/* Arduino Nano Pin 5 */
	{Gpio_PortD, Gpio_Pin6},	/* Arduino Nano Pin 6 */
	{Gpio_PortD, Gpio_Pin7},	/* Arduino Nano Pin 7 */
	{Gpio_PortB, Gpio_Pin0},	/* Arduino Nano Pin 8 */
	{Gpio_PortB, Gpio_Pin1},	/* Arduino Nano Pin 9 */
	{Gpio_PortB, Gpio_Pin2},	/* Arduino Nano Pin 10 */
	{Gpio_PortB, Gpio_Pin3},	/* Arduino Nano Pin 11 */
	{Gpio_PortB, Gpio_Pin4},	/* Arduino Nano Pin 12 */
	{Gpio_PortB, Gpio_Pin5},	/* Arduino Nano Pin 13 */
	{Gpio_PortC, Gpio_Pin0},	/* Arduino Nano Pin 14 */
	{Gpio_PortC, Gpio_Pin1},	/* Arduino Nano Pin 15 */
	{Gpio_PortC, Gpio_Pin2},	/* Arduino Nano Pin 16 */
	{Gpio_PortC, Gpio_Pin3},	/* Arduino Nano Pin 17 */
	{Gpio_PortC, Gpio_Pin4},	/* Arduino Nano Pin 18 */
	{Gpio_PortC, Gpio_Pin5},	/* Arduino Nano Pin 19 */
	};
#endif

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/


/** End of File ***************************************************************/
