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
GPIO_Typedef* getPortBase(GPIO_Port_Typedef port){
	GPIO_Typedef* gpiox = NULL;
	
	switch(port){
		case GPIO_PortB:
			gpiox = GPIOB;
			break;
		case GPIO_PortC:
			gpiox = GPIOC;
			break;
		case GPIO_PortD:
			gpiox = GPIOD;
			break;
	}
	
	return gpiox;
}

void disablePullUpResistor(void){
	MCUCR |= 0x01 << 4;
}

void pinMode(uint8_t arduinoPin, GPIO_DDRxDirection_Typedef direction){
	GPIO_Typedef *gpiox = NULL;
	GPIO_Port_Typedef port = pins[arduinoPin].port;
	GPIO_Pin_Typedef pin = pins[arduinoPin].pin;
	
	gpiox = getPortBase(port);
	if(NULL != gpiox){
		gpiox->DDRx &= ~(GPIO_DDRx_Output << pin);
		gpiox->DDRx |= direction << pin;
	} else {
		// Do nothing
	}
	
}

void digitalWrite(uint8_t arduinoPin, IOValue_Typedef value){
	GPIO_Typedef *gpiox = NULL;
	GPIO_Port_Typedef port = pins[arduinoPin].port;
	GPIO_Pin_Typedef pin = pins[arduinoPin].pin;
	
	gpiox = getPortBase(port);
	if(NULL != gpiox){
		if(HIGH == value){
			gpiox->PORTx |= HIGH << pin;
		} else {
			gpiox->PORTx &= ~(HIGH << pin);
		}
		
	} else {
		// Do nothing
	}		
	
}

/** End of File ***************************************************************/
