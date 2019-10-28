#ifdef UNIT_TESTING	

/************************************************
 *  1. Included Files
 ***********************************************/
#include "ut_main.h"
#include <stdio.h>
#include <math.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

/************************************************
 *  2. Global, Static and Extern Variables
 ***********************************************/
extern void (*testcaseList[1])(void);

const Struct_Usart_Config_Typedef usartRedirectConfig[1] = 
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
FILE usart_stream = FDEV_SETUP_STREAM((int (*)(char, FILE *)) Usart_SendChar, NULL, _FDEV_SETUP_RW);

/************************************************
 *  3. Function Definition
 ***********************************************/
void setUp(void) {  
	
}

void tearDown(void) {
}

/**
 * @note To redirect STDIO via usart, these things must be done.
 *       - Add "-Wl,-u,vfprintf -lprintf_flt -lm" flags to linker. 
 *       - Add "libprintf_flt.a" and "libm.a" to linker static libraries. 
 *       Adding "-r" flag for archiver will enable linker static libraries.
 */
void runTest(void) {
	int i;
	int noTestcase = sizeof(testcaseList)/ sizeof(testcaseList[0]);

	Usart_InitUSART(&(usartRedirectConfig[0]));
	Usart_SetBaudrate(Usart_9600bps);
	Usart_CommandTransmitter(Enable);
	stdout = &usart_stream;
	printf("hello %d", 1);
	UNITY_BEGIN();
	
	for(i = 0; i < noTestcase; i++) {
		RUN_TEST(testcaseList[i]);
	}	

	UNITY_END();
}


#endif /* UNIT_TESTING	*/
