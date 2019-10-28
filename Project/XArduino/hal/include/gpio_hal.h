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
	uint8_t PINx;
	uint8_t DDRx;
	uint8_t PORTx;
} Struct_Gpio_Typedef;
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

/** @brief Get the pointer to port X structure.
 *
 *  @param port Port name
 *  @return Pointer to port X structure.
 */
Struct_Gpio_Typedef* Gpio_GetPortBase(Enum_Gpio_Port_Typedef port);

/** @brief Disable pull-up resistor
 *
 *  @param cmd Enable or Disable option.
 *  @return none.
 */
void Gpio_CommandPullUpResistorSetting(Enum_Command_Typedef cmd);

/** @brief Configure a pin direction.
 *
 *  @param arduinoPin Arduino digital pin
 *  @param direction Pin direction
 *  @return none.
 */
void Gpio_PinMode(uint8_t arduinoPin, Enum_Gpio_DDRxDirection_Typedef direction);

/** @brief Set or reset a pin value.
 *
 *  @param arduinoPin Arduino digital pin
 *  @param value Pin value
 *  @return none.
 */
void Gpio_DigitalWrite(uint8_t arduinoPin, Enum_IOValue_Typedef value);


#ifdef __cplusplus
} // extern "C"
#endif

#endif /* GPIO_HAL_H_ */

/** End of File ***************************************************************/
