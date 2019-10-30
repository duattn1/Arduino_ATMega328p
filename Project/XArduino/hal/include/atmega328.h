/** @file atmega328.h
 *  @brief Abstracting information of Atmega328 micro controller.
 * 
 *  This is the header file for abstracting information of Atmega328 microc ontroller.
 
 *  
 * 	@author Tran Nhat Duat (duattn)
 *	@version 	V1.0
 */

#ifndef ATMEGA328_H_
#define ATMEGA328_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include <avr/io.h>
#include <stdint.h>

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/
#define TIMER0_BASE	&TCCR0A
#define TIMER1_BASE	&TCCR1A
#define TIMER0		((Struct_Timer0_Typedef *) TIMER0_BASE)
#define TIMER1		((Struct_Timer1_Typedef *) TIMER1_BASE)
/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/

	
/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Pointers, Others
 ******************************************************************************/

/**
 * @struct This structure shows all Timer 0 registers following the memory layout,
 *         except the Interrupt Mask and Interrupt Mask register.
 */
typedef struct {
	volatile uint8_t TCCRnA_uint8;
	volatile uint8_t TCCRnB_uint8;
	volatile uint8_t TCNTn_uint8;
	volatile uint8_t OCRnA_uint8;
	volatile uint8_t OCRnB_uint8;
} Struct_Timer0_Typedef;

/**
 * @struct This structure shows all Timer 1 registers following the memory layout,
 *         except the Interrupt Mask and Interrupt Mask register.
 */
typedef struct {
	volatile uint8_t TCCRnA_uint8;
	volatile uint8_t TCCRnB_uint8;
	volatile uint8_t TCCRnC_uint8;
	uint8_t reserved[1];
	volatile uint8_t TCNTnL_uint8;
	volatile uint8_t TCNTnH_uint8;
	volatile uint8_t ICR1L_uint8;
	volatile uint8_t ICR1H_uint8;
	volatile uint8_t OCRnAL_uint8;
	volatile uint8_t OCRnAH_uint8;
	volatile uint8_t OCRnBL_uint8;
	volatile uint8_t OCRnBH_uint8;
} Struct_Timer1_Typedef;


/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/


/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif


#ifdef __cplusplus
} // extern "C"
#endif

#endif /* ATMEGA328_H_ */

/** End of File ***************************************************************/