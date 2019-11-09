/** @file boards.h
 *  @brief Declaration of Arduino boards function and data.
 *
 *  This is the header file for the definition of Arduino boards.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 *              - Added function-like macro for Arduino pin enum
 * -----------------------------------------------------------------------------
 */

#ifndef BOARDS_H_
#define BOARDS_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include <avr/io.h>
#include "atmega328.h"

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/
#define ARDUINO_NANO_USER_LED Pin13

/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/
/**
 * Check if port is valid
 */
#define IS_VALID_ARDUINO_PIN(pin) \
    ((Pin0 == (pin)) || \
	(Pin1 == (pin)) || \
	(Pin2 == (pin)) || \
	(Pin3 == (pin)) || \
	(Pin4 == (pin)) || \
	(Pin5 == (pin)) || \
	(Pin6 == (pin)) || \
	(Pin7 == (pin)) || \
	(Pin8 == (pin)) || \
	(Pin9 == (pin)) || \
	(Pin10 == (pin)) || \
	(Pin11 == (pin)) || \
	(Pin12 == (pin)) || \
	(Pin13 == (pin)) || \
	(Pin14 == (pin)) || \
	(Pin15 == (pin)) || \
	(Pin16 == (pin)) || \
	(Pin17 == (pin)) || \
	(Pin18 == (pin)) || \
	(Pin19 == (pin)))
	

/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Unions, Pointers, Others
 ******************************************************************************/
#ifdef ARDUINO_NANO
/**
 * @enum This enumeration is a list of pin direction modes.
 */
typedef enum
{
    Pin0 = 0,   /**< Arduino pin 0 */
    Pin1,       /**< Arduino pin 1 */
    Pin2,       /**< Arduino pin 2 */
    Pin3,       /**< Arduino pin 3 */
    Pin4,       /**< Arduino pin 4 */
    Pin5,       /**< Arduino pin 5 */
    Pin6,       /**< Arduino pin 6 */
    Pin7,       /**< Arduino pin 7 */
    Pin8,       /**< Arduino pin 8 */
    Pin9,       /**< Arduino pin 9 */
    Pin10,      /**< Arduino pin 10 */
    Pin11,      /**< Arduino pin 11 */
    Pin12,      /**< Arduino pin 12 */
    Pin13,      /**< Arduino pin 13 */
    Pin14,      /**< Arduino pin 14 */
    Pin15,      /**< Arduino pin 15 */
    Pin16,      /**< Arduino pin 16 */
    Pin17,      /**< Arduino pin 17 */
    Pin18,      /**< Arduino pin 18 */
    Pin19       /**< Arduino pin 19 */
} Enum_Gpio_ArduinoPin_Typedef;
#endif /* ARDUINO_NANO */

/**
 * @struct This structure define a way for Arduino pin naming.
 */
typedef struct {
    Enum_Gpio_Port_Typedef port;
    Enum_Gpio_Pin_Typedef pin;
} Struct_BoardPin_Typedef;

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

#endif /* BOARDS_H_ */

/** End of File ***************************************************************/
