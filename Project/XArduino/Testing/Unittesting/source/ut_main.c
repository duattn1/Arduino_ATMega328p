/** @file ut_main.c
 *  @brief Definition of unit testing main controlling function and data.
 *
 *  This is the source file for the definition of unit testing main controlling.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 * -----------------------------------------------------------------------------
 */

#ifdef UNIT_TESTING	

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "ut_main.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <avr/pgmspace.h>

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
extern void Test_RunTestcase(void);
uint8_t buffer[256];
uint8_t buffer_index = 0;
char functionName[255] = "";
bool endCommand = false;

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
    /* Thing to do before running test */
}

void tearDown(void) {
    /* Thing to do after running test */
}

void Test_RunTest(void){
    Test_Init();
    Test_Loop();
    Test_Conclude();
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
    
    Usart_SendString("Start testing");
    UNITY_BEGIN();
}

void Test_Loop(void){
    uint8_t cmd;

    while(1) {
        cmd = Test_GetHostCommand();
        
        if (CMD_QUIT_TESTING == cmd) {
			/* 
			 * Quit the test loop 
			 */
            break; 
        } else if (CMD_START_TESTING == cmd){
			/* 
			 * Run a test case 
			 */
            buffer_index = 0;
            RUN_TEST(Test_RunTestcase);
        }
    }
}

void Test_Conclude(void){
    UNITY_END();
    Usart_SendString("End testing");
}

uint8_t Test_GetHostCommand(void){
    uint8_t cmd;
    if(true == endCommand){
        endCommand = false;
        uint8_t read_index = 0;
        uint8_t data;
        
		/* Command format is  ":[cmd_character][...]." => get the [1] element of buffer array */
        cmd = CMD_NAME;			
		
        /* Print out received data */
        while(read_index < buffer_index){
            data = buffer[read_index];
            Usart_SendChar(data, 0);
			
			/* Store function name if host send the function command*/
			if((CMD_TEST_FUNCTION == cmd) && (read_index >= FUNCTION_NAME_INDEX) && (CMD_END_CHARACTER != data)){
				/* Append the received character to function name when host send the ":f" command */
			    strncat(functionName, &data, 1);
		    }	
		
            read_index++;
        }
        
        /* Reset buffer index */
        buffer_index = 0;
    } /* End of if(true == endCommand){ */
    return cmd;
}

/**
 * USART reception complete interrupt handler
 */
ISR(USART_RX_vect)
{
    while (!(UCSR0A & (1 << RXC0)));	
    uint8_t data = (uint8_t)UDR0;
	if ('.' == data){
		endCommand = true;
	}
	
    buffer[buffer_index] = data;
    buffer_index++;
}

#endif /* UNIT_TESTING	*/

/** End of File ***************************************************************/
