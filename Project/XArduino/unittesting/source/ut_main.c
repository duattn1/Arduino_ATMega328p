/** @file ut_main.c
 *  @brief Function implementation for unit testing main controlling.
 *
 *  This is the source file for the definition of unit testing main controlling.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 */

#ifdef UNIT_TESTING	

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "ut_main.h"
#include <stdio.h>
#include <math.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

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
Struct_FunctionCall_Typedef Function_array[] =
{
	{ 'd', Test_RunOneCase }	
};

extern void (*TestcaseList_array[46])(void);
extern void Test_Gpio_GetPortBase_TC1(void);
extern uint8_t buffer[256];
extern uint8_t buffer_index;

/* USART initializing configuration */
const Struct_Usart_Config_Typedef UsartRedirectConfig_array[1] = 
{
	{ Usart_UCSRnC_AsyncMode, Usart_UCSRnC_DisabledParity,
	Usart_UCSRnC_1StopBit, Usart_UCSRnC_8bitsData }
};

/** 
 * Set stream pointer
 * @note Refer http://tiny.cc/FDEV_SETUP_STREAM
 * @note Usart_SendChar function pointer is casted into "(int (*)(char, FILE *))"
 * become to compatible with argument "put" of fdev_setup_stream() function.
 */
FILE Usart_stream = FDEV_SETUP_STREAM((int (*)(char, FILE *)) Usart_SendChar, NULL, _FDEV_SETUP_RW);

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void setUp(void) {  
	// Thing to do before running test
}

void tearDown(void) {
	// Thing to do after running test
}

/**
 * @note To redirect STDIO via usart, these things must be done.
 *       - Add "-Wl,-u,vfprintf -lprintf_flt -lm" flags to linker. 
 *       - Add "libprintf_flt.a" and "libm.a" to linker static libraries. 
 *       Adding "-r" flag for archiver will enable linker static libraries.
 */
void Test_Init(void) {	
	cli(); /* Disable all interrupts */
	Usart_InitUSART(&(UsartRedirectConfig_array[0]));
	Usart_SetBaudrate(Usart_9600bps);
	Usart_CommandTransmitter(Enable);
	Usart_CommandReceiver(Enable);
	stdout = &Usart_stream;
	sei(); /* Enable all interrupts */
	
	uint8_t end[] = "Start";
	Usart_SendString(end);
	UNITY_BEGIN();		
}

void Test_One(void){
	RUN_TEST(Test_Gpio_GetPortBase_TC1);
}

void Test_Loop(void){	
	while(1){
		if(buffer_index > 0){
			buffer_index--;	
			Usart_SendChar(buffer[buffer_index], 0);
			
			if ('q' == buffer[buffer_index]) {
				break;
			} 
			if ('d' == buffer[buffer_index]) {
				Function_array[0].function();
			} 
			
			/*switch (buffer[buffer_index]){
			case q:
				break;
			}*/
			
		}
	}
}

void Test_Conclude(void){
	UNITY_END();
	uint8_t end[] = "end";
	Usart_SendString(end);
}

#endif /* UNIT_TESTING	*/

/** End of File ***************************************************************/
