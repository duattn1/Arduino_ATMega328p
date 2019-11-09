/** @file wrapper_arduinoGpio.c
 *  @brief Definition of Arduino wrapper for GPIO driver function and data.
 *
 *  This is the source file for the definition of Arduino wrapper for GPIO driver.
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
#include "wrapper_arduinoGpio.h"

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
Struct_Gpio_Typedef* Arduino_GetPortBase(Enum_Gpio_Port_Typedef port_enum){
	/* Check port_enum */
    assert(IS_VALID_GPIO_PORT(port_enum));
	
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

void pinMode(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_Gpio_DDRxDirection_Typedef direction_enum){
	/* Check arduinoPin_enum */
    assert(IS_VALID_ARDUINO_PIN(arduinoPin_enum));
	/* Check direction_enum */
	assert(IS_VALID_GPIO_DDRXDIRECTION(direction_enum));
	
    Struct_Gpio_Typedef *gpiox_ptr = NULL;
    Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
     
    
	Struct_Gpio_Config_Typedef config_struct;
	config_struct.pin_enum = Pins_array[arduinoPin_enum].pin;
	config_struct.direction_enum = direction_enum;
	
    gpiox_ptr = Arduino_GetPortBase(port_enum);
    if(NULL != gpiox_ptr){
		Gpio_Init(gpiox_ptr, &config_struct);
    } else {
        /* Do nothing */
    }
}

void digitalWrite(Enum_Gpio_ArduinoPin_Typedef arduinoPin_enum, Enum_IOValue_Typedef value_enum){
	/* Check arduinoPin_enum */
    assert(IS_VALID_ARDUINO_PIN(arduinoPin_enum));
	/* Check value_enum */
    assert(IS_VALID_IOVALUE(value_enum));
	
    Struct_Gpio_Typedef *gpiox_ptr = NULL;
    Enum_Gpio_Port_Typedef port_enum = Pins_array[arduinoPin_enum].port;
    Enum_Gpio_Pin_Typedef pin_enum = Pins_array[arduinoPin_enum].pin;
    
    gpiox_ptr = Arduino_GetPortBase(port_enum);
    if(NULL != gpiox_ptr){
        if(High == value_enum){
            Gpio_PinSet(gpiox_ptr, pin_enum);
        } else {
            Gpio_PinReset(gpiox_ptr, pin_enum);
        }
        
    } else {
        /* Do nothing */
    }
}

#endif /* GPIO_HAL */

/** End of File ***************************************************************/
