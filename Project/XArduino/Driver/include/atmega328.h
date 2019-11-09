/** @file atmega328.h
 *  @brief Declaration of Atmega328 abstract data.
 *
 *  This is the header file for the definition of Atmega328 abstract data.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 *              - Added function-like macro for Gpio port and pin enums
 * -----------------------------------------------------------------------------
 */

#ifndef ATMEGA328_H_
#define ATMEGA328_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include <avr/io.h>

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/
/* GPIO register structures */
#define GPIOB_BASE  &PINB 
#define GPIOC_BASE  &PINC
#define GPIOD_BASE  &PIND
#define GPIOB       ((Struct_Gpio_Typedef *) GPIOB_BASE)
#define GPIOC       ((Struct_Gpio_Typedef *) GPIOC_BASE)
#define GPIOD       ((Struct_Gpio_Typedef *) GPIOD_BASE)

/* Timer registers structure */
#define TIMER0_BASE &TCCR0A
#define TIMER1_BASE &TCCR1A
#define TIMER0      ((Struct_Timer0_Typedef *) TIMER0_BASE)
#define TIMER1      ((Struct_Timer1_Typedef *) TIMER1_BASE)

/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/
/**
 * @def Check if a port base is valid
 */
#define IS_VALID_PORT_BASE(port) \
    ((GPIOB == (port)) || \
	(GPIOC == (port)) || \
	(GPIOD == (port)))

/**
 * Check if port is valid
 */
#define IS_VALID_GPIO_PORT(port) \
    ((Gpio_PortB == (port)) || \
	(Gpio_PortC == (port)) || \
	(Gpio_PortD == (port)))
	
/**
 * @def Check if a pin is valid
 */
#define IS_VALID_GPIO_PIN(pin) \
    ((Gpio_Pin0 == (pin)) || \
    (Gpio_Pin1 == (pin)) || \
    (Gpio_Pin2 == (pin)) || \
    (Gpio_Pin3 == (pin)) || \
    (Gpio_Pin4 == (pin)) || \
    (Gpio_Pin5 == (pin)) || \
    (Gpio_Pin6 == (pin)) || \
    (Gpio_Pin7 == (pin)))	
/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Unions, Pointers, Others
 ******************************************************************************/
/**
 * @enum This enumeration is a list of pins of each port.
 */
typedef enum
{
    Gpio_PortB,     /**< Port B */
    Gpio_PortC,     /**< Port C */
    Gpio_PortD      /**< Port D */
} Enum_Gpio_Port_Typedef;

/**
 * @enum This enumeration is a list of pins of each port.
 */
typedef enum
{
    Gpio_Pin0,      /**< Pin 0 */
    Gpio_Pin1,      /**< Pin 1 */
    Gpio_Pin2,      /**< Pin 2 */
    Gpio_Pin3,      /**< Pin 3 */
    Gpio_Pin4,      /**< Pin 4 */
    Gpio_Pin5,      /**< Pin 5 */
    Gpio_Pin6,      /**< Pin 6 */
    Gpio_Pin7       /**< Pin 7 */
} Enum_Gpio_Pin_Typedef;

/**
 * @struct This structure lists all registers of each GPIO port.
 */
typedef struct {
    uint8_t PINx_uint8;     /**< Input mode */
    uint8_t DDRx_uint8;
    uint8_t PORTx_uint8;
} Struct_Gpio_Typedef;


/**
 * @struct This structure shows all Timer 0 registers following the memory layout,
 *         except the Interrupt Mask and Interrupt Mask register.
 */
typedef struct {
    volatile uint8_t TCCRnA_uint8;  /**< TCCRnA register */
    volatile uint8_t TCCRnB_uint8;  /**< TCCRnB register */
    volatile uint8_t TCNTn_uint8;   /**< TCNT register */
    volatile uint8_t OCRnA_uint8;   /**< OCRnA register */
    volatile uint8_t OCRnB_uint8;   /**< OCRnB register */
} Struct_Timer0_Typedef;

/**
 * @struct This structure shows all Timer 1 registers following the memory layout,
 *         except the Interrupt Mask and Interrupt Mask register.
 */
typedef struct {
    volatile uint8_t TCCRnA_uint8;  /**< TCCRnA register */
    volatile uint8_t TCCRnB_uint8;  /**< TCCRnB register */
    volatile uint8_t TCCRnC_uint8;  /**< TCCRnC register */
    uint8_t reserved[1];            /**< Reserved address */
    volatile uint8_t TCNTnL_uint8;  /**< TCNTnL register */
    volatile uint8_t TCNTnH_uint8;  /**< TCNTnH register */
    volatile uint8_t ICR1L_uint8;   /**< ICR1L register */
    volatile uint8_t ICR1H_uint8;   /**< ICR1H register */
    volatile uint8_t OCRnAL_uint8;  /**< OCRnAL register */
    volatile uint8_t OCRnAH_uint8;  /**< OCRnAH register */
    volatile uint8_t OCRnBL_uint8;  /**< OCRnBL register */
    volatile uint8_t OCRnBH_uint8;  /**< OCRnBH register */
} Struct_Timer1_Typedef;

/*******************************************************************************
 * 5. Global, Static, Constant, Extern Variables and Extern Functions
 ******************************************************************************/

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ATMEGA328_H_ */

/** End of File ***************************************************************/