/** @file wrapper_arduinoGpio.h
 *  @brief Declaration of Arduino wrapper for GPIO driver function and data.
 *
 *  This is the header file for the definition of Arduino wrapper for GPIO driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 * -----------------------------------------------------------------------------
 */

#ifndef WRAPPER_ARDUINOGPIO_H_
#define WRAPPER_ARDUINOGPIO_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "config_middleware.h"
#include "boards.h"
#include "gpio_hal.h"

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
extern const Struct_BoardPin_Typedef Pins_array[];

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/** 
 * @brief Get the pointer to desired GPIO register structure
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param port_enum Port name
 * @return Pointer to port X structure
 *
 * @see None
 */
Struct_Gpio_Typedef* Arduino_GetPortBase(Enum_Gpio_Port_Typedef port_enum);

/** 
 * @brief Configure a pin direction
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param arduinoPin_enum Arduino digital pin
 * @param direction_enum Pin direction
 * @return None
 *
 * @see Gpio_GetPortBase()
 */
void pinMode(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_Gpio_DDRxDirection_Typedef direction_enum);

/** 
 * @brief Set or reset a pin value
 *
 * PRE-CONDITION: Pin direction is set to output with Gpio_PinMode()
 * POST-CONDITION: None
 *
 * @param arduinoPin_enum Arduino digital pin
 * @param value_enum Pin value
 * @return None
 *
 * @see Gpio_GetPortBase(), Gpio_PinMode()
 */
void digitalWrite(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_IOValue_Typedef value_enum);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WRAPPER_ARDUINOGPIO_H_ */

/** End of File ***************************************************************/
