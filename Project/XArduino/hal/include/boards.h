/** @file boards.h
 *  @brief Declaration of Arduino boards function and data.
 *
 *  This is the header file for the definition of Arduino boards.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * TODO<<Jan 01, 2019>> - TODO<< WHAT WAS UPDATED?>>
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
#endif

/**
 * @enum This enumeration is a list of pins of each port.
 */
typedef enum
{
    Gpio_PortB,     /**< Port B */
    Gpio_PortC,     /**< Port C */
    Gpio_PortD      /**< Port D */
} Enum_Gpio_Port_Typedef;

/**
 * @enum This enumeration is a list of pins of each port.
 */
typedef enum
{
    Gpio_Pin0,      /**< Pin 0 */
    Gpio_Pin1,      /**< Pin 1 */
    Gpio_Pin2,      /**< Pin 2 */
    Gpio_Pin3,      /**< Pin 3 */
    Gpio_Pin4,      /**< Pin 4 */
    Gpio_Pin5,      /**< Pin 5 */
    Gpio_Pin6,      /**< Pin 6 */
    Gpio_Pin7       /**< Pin 7 */
} Enum_Gpio_Pin_Typedef;

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
