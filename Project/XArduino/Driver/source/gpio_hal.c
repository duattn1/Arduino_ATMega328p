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
    gpio_ptr->DDRx_uint8 &= ~(MASK_1BIT << config_ptr->pin_enum);
    gpio_ptr->DDRx_uint8 |= config_ptr->direction_enum << config_ptr->pin_enum;
}

void Gpio_PinSet(Struct_Gpio_Typedef *gpio_ptr, Enum_Gpio_Pin_Typedef pin_enum){
	gpio_ptr->PORTx_uint8 |= 0x01 << pin_enum;
}

void Gpio_PinReset(Struct_Gpio_Typedef *gpio_ptr, Enum_Gpio_Pin_Typedef pin_enum){
	gpio_ptr->PORTx_uint8 &= ~(0x01 << pin_enum);
}

void Gpio_PinToggle(Struct_Gpio_Typedef *gpio_ptr, Enum_Gpio_Pin_Typedef pin_enum){
	gpio_ptr->PORTx_uint8 ^= 0x01 << pin_enum;
}

uint8_t Gpio_ReadPin(Struct_Gpio_Typedef *gpio_ptr, Enum_Gpio_Pin_Typedef pin_enum){
	uint8_t pinValueMask = 0x01 << pin_enum;
	return (gpio_ptr->PINx_uint8 & pinValueMask);
}

void Gpio_CommandPullUpResistorSetting(Enum_Command_Typedef cmd_enum)
{
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
