/** @file gpio_hal.h
 *  @brief Function prototypes for GPIO driver.
 * 
 *  This is the header file for the definition of GPIO driver.
 *  
 * 	@author Tran Nhat Duat (duattn)
 *	@version 	V1.0
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
/* Set GPIOx_BASE to address of PINx since PINx register is the begin register
   of each port. 
   Currently, PINB, PINC and PIND is defined as an lvalue after preprocessing.*/
#define GPIOB_BASE	&PINB 
#define GPIOC_BASE	&PINC
#define GPIOD_BASE	&PIND
#define GPIOB		((Struct_Gpio_Typedef *) GPIOB_BASE)
#define GPIOC		((Struct_Gpio_Typedef *) GPIOC_BASE)
#define GPIOD		((Struct_Gpio_Typedef *) GPIOD_BASE)

/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/

	
/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Pointers, Others
 ******************************************************************************/
/**
 * @enum This enumeration is a list of pin direction modes.
 */
typedef enum
{
	Gpio_DDRx_Input = 0x00,			/**< Input mode */
	Gpio_DDRx_Output = 0x01			/**< Output mode */
} Enum_Gpio_DDRxDirection_Typedef;

/**
 * @struct This structure list all registers of each GPIO port.
 */
typedef struct {
	uint8_t PINx_uint8;
	uint8_t DDRx_uint8;
	uint8_t PORTx_uint8;
} Struct_Gpio_Typedef;
/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/
extern const Struct_BoardPin_Typedef Pins_array[];

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/** @brief Get the pointer to port X structure.
 *
 *  @param port_enum Port name
 *  @return Pointer to port X structure.
 */
Struct_Gpio_Typedef* Gpio_GetPortBase(Enum_Gpio_Port_Typedef port_enum);

/** @brief Disable pull-up resistor
 *
 *  @param cmd_enum Enable or Disable option.
 *  @return none.
 */
void Gpio_CommandPullUpResistorSetting(Enum_Command_Typedef cmd_enum);

/** @brief Configure a pin direction.
 *
 *  @param arduinoPin_enum Arduino digital pin
 *  @param direction_enum Pin direction
 *  @return none.
 */
void Gpio_PinMode(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_Gpio_DDRxDirection_Typedef direction_enum);

/** @brief Set or reset a pin value.
 *
 *  @param arduinoPin_enum Arduino digital pin
 *  @param value_enum Pin value
 *  @return none.
 */
void Gpio_DigitalWrite(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_IOValue_Typedef value_enum);


#ifdef __cplusplus
} // extern "C"
#endif

#endif /* GPIO_HAL_H_ */

/** End of File ***************************************************************/
