/** @file gpio_hal.h
 *  @brief Declaration of GPIO driver function and data.
 *
 *  This is the header file for the definition of GPIO driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 *              - Added assertion function-like macros.
 * -----------------------------------------------------------------------------
 */

#ifndef GPIO_HAL_H_
#define GPIO_HAL_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "config_driver.h"

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/

/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/
/**
 * @def Check if a pin direction is valid
 */
#define IS_VALID_GPIO_DDRXDIRECTION(direction) \
    ((Gpio_DDRx_Input == (direction)) || \
	(Gpio_DDRx_Output == (direction)))
	
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

/**
 * @struct This structure is for GPIO configuration.
 */
typedef struct {
	Enum_Gpio_Pin_Typedef pin_enum;                 /**< Input mode */
	Enum_Gpio_DDRxDirection_Typedef direction_enum; /**< Input mode */
} Struct_Gpio_Config_Typedef;

/*******************************************************************************
 * 5. Global, Static, Constant, Extern Variables and Extern Functions
 ******************************************************************************/

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/** 
 * @brief Initialize a GPIO pin
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param gpio_ptr GPIO port base address pointer
 * @param config_ptr GPIO initializing configuration pointer
 * @return None
 *
 * @see None
 */
void Gpio_Init(Struct_Gpio_Typedef *gpio_ptr, Struct_Gpio_Config_Typedef *config_ptr);

/** 
 * @brief Set pin output value to HIGH
 *
 * PRE-CONDITION: Pin direction is set to output with Gpio_Init()
 * POST-CONDITION: None
 *
 * @param gpio_ptr GPIO port base address pointer
 * @param pin_enum GPIO pin
 * @return None
 *
 * @see Gpio_Init()
 */
void Gpio_PinSet(Struct_Gpio_Typedef *gpio_ptr, Enum_Gpio_Pin_Typedef pin_enum);

/** 
 * @brief Reset pin output value to LOW
 *
 * PRE-CONDITION: Pin direction is set to output with Gpio_Init()
 * POST-CONDITION: None
 *
 * @param gpio_ptr GPIO port base address pointer
 * @param pin_enum GPIO pin
 * @return None
 *
 * @see Gpio_Init()
 */
void Gpio_PinReset(Struct_Gpio_Typedef *gpio_ptr, Enum_Gpio_Pin_Typedef pin_enum);

/** 
 * @brief Toggle pin output value
 *
 * PRE-CONDITION: Pin direction is set to output with Gpio_Init()
 * POST-CONDITION: None
 *
 * @param gpio_ptr GPIO port base address pointer
 * @param pin_enum GPIO pin
 * @return None
 *
 * @see Gpio_Init()
 */
void Gpio_PinToggle(Struct_Gpio_Typedef *gpio_ptr, Enum_Gpio_Pin_Typedef pin_enum);

/** 
 * @brief Read pin input value
 *
 * PRE-CONDITION: Pin direction is set to input with Gpio_Init()
 * POST-CONDITION: None
 *
 * @param gpio_ptr GPIO port base address pointer
 * @param pin_enum GPIO pin
 * @return None
 *
 * @see Gpio_Init()
 */
uint8_t Gpio_ReadPin(Struct_Gpio_Typedef *gpio_ptr, Enum_Gpio_Pin_Typedef pin_enum);

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

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* GPIO_HAL_H_ */

/** End of File ***************************************************************/
