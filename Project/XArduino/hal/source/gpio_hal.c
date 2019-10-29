/** @file gpio_hal.c
 *  @brief Function implementation for GPIO driver.
 *
 *  This is the source file for the definition of GPIO driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 */

#ifdef USE_GPIO_HAL

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
 * 4. Typedefs: Enumerations, Structures, Pointers, Others
 ******************************************************************************/


/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/


/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
Struct_Gpio_Typedef* Gpio_GetPortBase(Enum_Gpio_Port_Typedef port_enum){
	Struct_Gpio_Typedef* gpiox_ptr = NULL;
	
	switch(port_enum){
		case Gpio_PortB:
			gpiox_ptr = GPIOB;
			break;
		case Gpio_PortC:
			gpiox_ptr = GPIOC;
			break;
		case Gpio_PortD:
			gpiox_ptr = GPIOD;
			break;
	}
	
	return gpiox_ptr;
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

void Gpio_PinMode(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_Gpio_DDRxDirection_Typedef direction_enum){
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	Enum_Gpio_Pin_Typedef pin_enum = Pins_array[arduinoPin_enum].pin;
	
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	if(NULL != gpiox_ptr){
		gpiox_ptr->DDRx_uint8 &= ~(MASK_1BIT << pin_enum);
		gpiox_ptr->DDRx_uint8 |= direction_enum << pin_enum;
	} else {
		// Do nothing
	}
	
}

void Gpio_DigitalWrite(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_IOValue_Typedef value_enum){
	Struct_Gpio_Typedef *gpiox_ptr = NULL;
	Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
	Enum_Gpio_Pin_Typedef pin_enum = Pins_array[arduinoPin_enum].pin;
	
	gpiox_ptr = Gpio_GetPortBase(port_enum);
	if(NULL != gpiox_ptr){
		if(High == value_enum){
			gpiox_ptr->PORTx_uint8 |= High << pin_enum;
		} else {
			gpiox_ptr->PORTx_uint8 &= ~(High << pin_enum);
		}
		
	} else {
		// Do nothing
	}		
	
}

#endif /* USE_GPIO_HAL */

/** End of File ***************************************************************/
