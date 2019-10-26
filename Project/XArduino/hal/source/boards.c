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
const BoardPin_Typedef pins[] = 
	{
	{GPIO_PortD, GPIO_Pin0},	/* Arduino Nano Pin 0 */
	{GPIO_PortD, GPIO_Pin1},	/* Arduino Nano Pin 1 */
	{GPIO_PortD, GPIO_Pin2},	/* Arduino Nano Pin 2 */
	{GPIO_PortD, GPIO_Pin3},	/* Arduino Nano Pin 3 */
	{GPIO_PortD, GPIO_Pin4},	/* Arduino Nano Pin 4 */
	{GPIO_PortD, GPIO_Pin5},	/* Arduino Nano Pin 5 */
	{GPIO_PortD, GPIO_Pin6},	/* Arduino Nano Pin 6 */
	{GPIO_PortD, GPIO_Pin7},	/* Arduino Nano Pin 7 */
	{GPIO_PortB, GPIO_Pin0},	/* Arduino Nano Pin 8 */
	{GPIO_PortB, GPIO_Pin1},	/* Arduino Nano Pin 9 */
	{GPIO_PortB, GPIO_Pin2},	/* Arduino Nano Pin 10 */
	{GPIO_PortB, GPIO_Pin3},	/* Arduino Nano Pin 11 */
	{GPIO_PortB, GPIO_Pin4},	/* Arduino Nano Pin 12 */
	{GPIO_PortB, GPIO_Pin5},	/* Arduino Nano Pin 13 */
	{GPIO_PortC, GPIO_Pin0},	/* Arduino Nano Pin 14 */
	{GPIO_PortC, GPIO_Pin1},	/* Arduino Nano Pin 15 */
	{GPIO_PortC, GPIO_Pin2},	/* Arduino Nano Pin 16 */
	{GPIO_PortC, GPIO_Pin3},	/* Arduino Nano Pin 17 */
	{GPIO_PortC, GPIO_Pin4},	/* Arduino Nano Pin 18 */
		{GPIO_PortC, GPIO_Pin5},	/* Arduino Nano Pin 19 */
	};
#endif

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/


/** End of File ***************************************************************/
