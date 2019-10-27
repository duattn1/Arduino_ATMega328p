/** @file gpio_hal.c
 *  @brief Function implementation for GPIO driver.
 *
 *  This is the source file for the definition of GPIO driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 */
 
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
Struct_Gpio_Typedef* Gpio_GetPortBase(Enum_Gpio_Port_Typedef port){
	Struct_Gpio_Typedef* gpiox = NULL;
	
	switch(port){
		case Gpio_PortB:
			gpiox = GPIOB;
			break;
		case Gpio_PortC:
			gpiox = GPIOC;
			break;
		case Gpio_PortD:
			gpiox = GPIOD;
			break;
	}
	
	return gpiox;
}

void Gpio_CommandPullUpResistorSetting(Enum_Command_Typedef cmd)
{
	if (Disable == cmd)
	{
		MCUCR |= 0x01 << 4;
	} 
	else
	{
		MCUCR &= ~(0x01 << 4);
	}
}

void Gpio_PinMode(uint8_t arduinoPin, Enum_Gpio_DDRxDirection_Typedef direction){
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	Enum_Gpio_Pin_Typedef pin = pins[arduinoPin].pin;
	
	gpiox = Gpio_GetPortBase(port);
	if(NULL != gpiox){
		gpiox->DDRx &= ~(MASK_1BIT << pin);
		gpiox->DDRx |= direction << pin;
	} else {
		// Do nothing
	}
	
}

void Gpio_DigitalWrite(uint8_t arduinoPin, Enum_IOValue_Typedef value){
	Struct_Gpio_Typedef *gpiox = NULL;
	Enum_Gpio_Port_Typedef port = pins[arduinoPin].port;
	Enum_Gpio_Pin_Typedef pin = pins[arduinoPin].pin;
	
	gpiox = Gpio_GetPortBase(port);
	if(NULL != gpiox){
		if(High == value){
			gpiox->PORTx |= High << pin;
		} else {
			gpiox->PORTx &= ~(High << pin);
		}
		
	} else {
		// Do nothing
	}		
	
}

/** End of File ***************************************************************/
