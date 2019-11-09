/** @file gpio_hal.c
 *  @brief Definition of GPIO driver function and data.
 *
 *  This is the source file for the definition of GPIO driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 *              - Added assertion for all functions.
 * -----------------------------------------------------------------------------
 */
 

#ifdef GPIO_HAL

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
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

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/

void Gpio_Init(Struct_Gpio_Typedef *gpio_ptr,Struct_Gpio_Config_Typedef *config_ptr){
    /* Check gpio_ptr, no need to check DDRx_uint8 since gpio_ptr is a peripheral pointer */
    assert(NULL != gpio_ptr);
	assert(IS_VALID_PORT(gpio_ptr));
    /* Check config_ptr and members of the pointed structure */
    assert(NULL != config_ptr);
    assert(IS_VALID_PIN(config_ptr->pin_enum));
	assert(IS_VALID_DIRECTION(config_ptr->direction_enum));
    
#ifdef ARDUINO_NANO
    /* Check if pin differs with PB6, PB7, PC6, PC7 since these pins are not available in Arduino Nano board */
    assert(!((GPIOB == gpio_ptr) && (Gpio_Pin6 == config_ptr->pin_enum)));
	assert(!((GPIOB == gpio_ptr) && (Gpio_Pin7 == config_ptr->pin_enum)));
    assert(!((GPIOC == gpio_ptr) && (Gpio_Pin6 == config_ptr->pin_enum)));
	assert(!((GPIOC == gpio_ptr) && (Gpio_Pin7 == config_ptr->pin_enum)));
#endif /* ARDUINO_NANO */
    
    gpio_ptr->DDRx_uint8 &= ~(MASK_1BIT << config_ptr->pin_enum);
    gpio_ptr->DDRx_uint8 |= config_ptr->direction_enum << config_ptr->pin_enum;
}

void Gpio_PinSet(Struct_Gpio_Typedef *gpio_ptr, Enum_Gpio_Pin_Typedef pin_enum){
	/* Check gpio_ptr, no need to check DDRx_uint8 since gpio_ptr is a peripheral pointer */
    assert(NULL != gpio_ptr);
	assert(IS_VALID_PORT(gpio_ptr));
    /* Check pin_enum */
    assert(IS_VALID_PIN(pin_enum));
    
#ifdef ARDUINO_NANO
    /* Check if pin differs with PB6, PB7, PC6, PC7 since these pins are not available in Arduino Nano board */
    assert(!((GPIOB == gpio_ptr) && (Gpio_Pin6 == pin_enum)));
	assert(!((GPIOB == gpio_ptr) && (Gpio_Pin7 == pin_enum)));
    assert(!((GPIOC == gpio_ptr) && (Gpio_Pin6 == pin_enum)));
	assert(!((GPIOC == gpio_ptr) && (Gpio_Pin7 == pin_enum)));
#endif /* ARDUINO_NANO */

    /* Check precondition: pin direction must be output */
	assert((Gpio_DDRx_Output << pin_enum) == ((gpio_ptr->DDRx_uint8) & (MASK_1BIT << pin_enum))); /* Compare DDRx register with a mask */

	gpio_ptr->PORTx_uint8 |= 0x01 << pin_enum;
}

void Gpio_PinReset(Struct_Gpio_Typedef *gpio_ptr, Enum_Gpio_Pin_Typedef pin_enum){
	/* Check gpio_ptr, no need to check DDRx_uint8 since gpio_ptr is a peripheral pointer */
    assert(NULL != gpio_ptr);
	assert(IS_VALID_PORT(gpio_ptr));
    /* Check pin_enum */
    assert(IS_VALID_PIN(pin_enum));
    
#ifdef ARDUINO_NANO
    /* Check if pin differs with PB6, PB7, PC6, PC7 since these pins are not available in Arduino Nano board */
    assert(!((GPIOB == gpio_ptr) && (Gpio_Pin6 == pin_enum)));
	assert(!((GPIOB == gpio_ptr) && (Gpio_Pin7 == pin_enum)));
    assert(!((GPIOC == gpio_ptr) && (Gpio_Pin6 == pin_enum)));
	assert(!((GPIOC == gpio_ptr) && (Gpio_Pin7 == pin_enum)));
#endif /* ARDUINO_NANO */

    /* Check precondition: pin direction must be output */
	assert((Gpio_DDRx_Output << pin_enum) == ((gpio_ptr->DDRx_uint8) & (MASK_1BIT << pin_enum))); /* Compare DDRx register with a mask */

	gpio_ptr->PORTx_uint8 &= ~(0x01 << pin_enum);
}

void Gpio_PinToggle(Struct_Gpio_Typedef *gpio_ptr, Enum_Gpio_Pin_Typedef pin_enum){
	/* Check gpio_ptr, no need to check DDRx_uint8 since gpio_ptr is a peripheral pointer */
    assert(NULL != gpio_ptr);
	assert(IS_VALID_PORT(gpio_ptr));
    /* Check pin_enum */
    assert(IS_VALID_PIN(pin_enum));
    
#ifdef ARDUINO_NANO
    /* Check if pin differs with PB6, PB7, PC6, PC7 since these pins are not available in Arduino Nano board */
    assert(!((GPIOB == gpio_ptr) && (Gpio_Pin6 == pin_enum)));
	assert(!((GPIOB == gpio_ptr) && (Gpio_Pin7 == pin_enum)));
    assert(!((GPIOC == gpio_ptr) && (Gpio_Pin6 == pin_enum)));
	assert(!((GPIOC == gpio_ptr) && (Gpio_Pin7 == pin_enum)));
#endif /* ARDUINO_NANO */

	/* Check precondition: pin direction must be output */
	assert((Gpio_DDRx_Output << pin_enum) == ((gpio_ptr->DDRx_uint8) & (MASK_1BIT << pin_enum))); /* Compare DDRx register with a mask */
	
	gpio_ptr->PORTx_uint8 ^= 0x01 << pin_enum;
}

uint8_t Gpio_ReadPin(Struct_Gpio_Typedef *gpio_ptr, Enum_Gpio_Pin_Typedef pin_enum){
	/* Check gpio_ptr, no need to check DDRx_uint8 since gpio_ptr is a peripheral pointer */
    assert(NULL != gpio_ptr);
	assert(IS_VALID_PORT(gpio_ptr));
    /* Check pin_enum */
    assert(IS_VALID_PIN(pin_enum));
    
#ifdef ARDUINO_NANO
    /* Check if pin differs with PB6, PB7, PC6, PC7 since these pins are not available in Arduino Nano board */
    assert(!((GPIOB == gpio_ptr) && (Gpio_Pin6 == pin_enum)));
	assert(!((GPIOB == gpio_ptr) && (Gpio_Pin7 == pin_enum)));
    assert(!((GPIOC == gpio_ptr) && (Gpio_Pin6 == pin_enum)));
	assert(!((GPIOC == gpio_ptr) && (Gpio_Pin7 == pin_enum)));
#endif /* ARDUINO_NANO */

	/* Check precondition: pin direction must be input */
	assert((Gpio_DDRx_Input << pin_enum) == ((gpio_ptr->DDRx_uint8) & (MASK_1BIT << pin_enum))); /* Compare DDRx register with a mask */
	
	uint8_t pinValueMask = 0x01 << pin_enum;
	return (gpio_ptr->PINx_uint8 & pinValueMask);
}

void Gpio_CommandPullUpResistorSetting(Enum_Command_Typedef cmd_enum)
{
    /* Check cmd_enum*/
    assert(IS_VALID_COMMAND(cmd_enum));
	
	if (Disable == cmd_enum)
    {
        MCUCR |= 0x01 << PUD; /* Write 1 to PUD bit to disable pull-up resistor */
    } 
    else
    {
        MCUCR &= ~(MASK_1BIT << PUD);
    }
}

#endif /* GPIO_HAL */

/** End of File ***************************************************************/
