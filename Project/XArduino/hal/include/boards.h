/** @file boards.h
 *  @brief Pin mapping of Arduino boards.
 * 
 *  This is the header file for in mapping of Arduino boards.
 
 *  
 * 	@author Tran Nhat Duat (duattn)
 *	@version 	V1.0
 */

#ifndef BOARDS_H_
#define BOARDS_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include <avr/io.h>

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/
#define ARDUINO_NANO_USER_LED 13

/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/

	
/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Pointers, Others
 ******************************************************************************/
/**
 * @enum This enumeration is a list of pins of each port.
 */
typedef enum
{
	Gpio_PortB,		/**< Port B */
	Gpio_PortC,		/**< Port C */
	Gpio_PortD		/**< Port D */
} Enum_Gpio_Port_Typedef;

/**
 * @enum This enumeration is a list of pins of each port.
 */
typedef enum
{
	Gpio_Pin0,		/**< Pin 0 */
	Gpio_Pin1,		/**< Pin 1 */
	Gpio_Pin2,		/**< Pin 2 */
	Gpio_Pin3,		/**< Pin 3 */
	Gpio_Pin4,		/**< Pin 4 */
	Gpio_Pin5,		/**< Pin 5 */
	Gpio_Pin6,		/**< Pin 6 */
	Gpio_Pin7		/**< Pin 7 */
} Enum_Gpio_Pin_Typedef;

/**
 * @struct This structure define a way for Arduino pin naming.
 */
typedef struct {
	Enum_Gpio_Port_Typedef port;
	Enum_Gpio_Pin_Typedef pin;
} Struct_BoardPin_Typedef;

/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/
extern const Struct_BoardPin_Typedef pins[];

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif


#ifdef __cplusplus
} // extern "C"
#endif

#endif /* BOARDS_H_ */

/** End of File ***************************************************************/
