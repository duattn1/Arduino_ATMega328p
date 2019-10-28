#ifdef UNIT_TESTING	

/************************************************
 *  1. Included Files
 ***********************************************/
#include "ut_main.h"


/************************************************
 *  2. Global, Static and Extern Variables
 ***********************************************/
extern void (*testcaseList[1])(void);

const Struct_Usart_Config_Typedef usartRedirectConfig[1] = 
{
	{ Usart_UCSRnC_AsyncMode, Usart_UCSRnC_DisabledParity,
	Usart_UCSRnC_1StopBit, Usart_UCSRnC_8bitsData }
};

/************************************************
 *  3. Function Defintition
 ***********************************************/
void setUp(void) {  
	
}

void tearDown(void) {
}

void runTest(void) {
	int i;
	int noTestcase = sizeof(testcaseList)/ sizeof(testcaseList[0]);

	uint8_t *strStart = "Start testing";
	Usart_InitUSART(&(usartRedirectConfig[0]));
	Usart_SetBaudrate(Usart_9600bps);
	Usart_CommandTransmitter(Enable);
	//Usart_CommandReceiver(Enable);
	Usart_SendString(strStart);	
	
	UNITY_BEGIN();
	
	for(i = 0; i < noTestcase; i++) {
		RUN_TEST(testcaseList[i]);
	}	

	UNITY_END();
}


#endif /* UNIT_TESTING	*/
