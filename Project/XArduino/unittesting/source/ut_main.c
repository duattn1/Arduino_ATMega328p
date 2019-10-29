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
extern void (*TestcaseList_array[85])(void);

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
void runTest(void) {
	uint16_t noTestcase_uint16 = sizeof(TestcaseList_array)/ sizeof(TestcaseList_array[0]);

	Usart_InitUSART(&(UsartRedirectConfig_array[0]));
	Usart_SetBaudrate(Usart_9600bps);
	Usart_CommandTransmitter(Enable);
	stdout = &Usart_stream;
	
	UNITY_BEGIN();
	
	for(uint8_t i = 0; i < noTestcase_uint16; i++) {
		RUN_TEST(TestcaseList_array[i]);
	}	
	
	UNITY_END();	
}

#endif /* UNIT_TESTING	*/

/** End of File ***************************************************************/
