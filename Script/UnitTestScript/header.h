/** @file gpio_hal.h
 *  @brief Declaration of GPIO driver function and data.
 *
 *  This is the header file for the definition of GPIO driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * TODO<<Jan 01, 2019>> - TODO<< WHAT WAS UPDATED?>>
 * -----------------------------------------------------------------------------
 */

#ifndef GPIO_HAL_H_
#define GPIO_HAL_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include <avr/io.h>
#include <stdint.h>
#include <stddef.h>
#include "boards.h"
#include "misc.h"

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
 * @enum This enumeration is a list of pin direction modes.
 */
typedef enum
{
    Gpio_DDRx_Input = 0x00,      /**< Input mode */
    Gpio_DDRx_Output = 0x01      /**< Output mode */
} Enum_Gpio_DDRxDirection_Typedef;

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
Struct_Gpio_Typedef* Gpio_GetPortBase(Enum_Gpio_Port_Typedef port_enum);

/** 
 * @brief Disable or enable pull-up resistor
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param cmd_enum Enable or Disable option
 * @return None
 *
 * @see None
 */
void Gpio_CommandPullUpResistorSetting(Enum_Command_Typedef cmd_enum);

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
void Gpio_PinMode(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_Gpio_DDRxDirection_Typedef direction_enum);

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
void Gpio_DigitalWrite(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_IOValue_Typedef value_enum);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* GPIO_HAL_H_ */

/** End of File ***************************************************************/
