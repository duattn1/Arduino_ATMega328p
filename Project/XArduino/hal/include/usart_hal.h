/** @file usart_hal.h
 *  @brief Function prototypes for USART driver.
 * 
 *  This is the header file for the definition of USART driver.
 *  
 * 	@author Tran Nhat Duat (duattn)
 *	@version 	V1.0
 */

#ifndef USART_HAL_H_
#define USART_HAL_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include "boards.h"
#include "misc.h"

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/
#define FOSC 16000000UL
#define RECEIVED_STRING_LENGTH 50

/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/

	
/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Pointers, Others
 ******************************************************************************/
/**
 * @enum This enumeration is a list of USART modes.
 */
typedef enum
{
	Usart_UCSRnC_AsyncMode = 0x00,			/**< UART mode */
	Usart_UCSRnC_SyncMode = 0x01,			/**< USART mode */
	// Reserved value: 0x02
	Usart_UCSRnC_SPIMode = 0x03				/**< USART in SPI mode */
} Enum_Usart_Mode_Typedef;

/**
 * @enum This enumeration is a list of parity bit options.
 */
typedef enum
{
	Usart_UCSRnC_DisabledParity = 0x00,			/**< Parity is disabled */
	// Reserved value: 0x01
	Usart_UCSRnC_EvenParity = 0x02,				/**< Even parity mode */
	Usart_UCSRnC_OddParity = 0x03				/**< Odd parity mode */
} Enum_Usart_ParityMode_Typedef;

/**
 * @enum This enumeration is a list of stop bit options.
 */
typedef enum
{	
	Usart_UCSRnC_1StopBit = 0x00,				/**< 1 stop bit */
	Usart_UCSRnC_2StopBits = 0x01				/**< 2 stop bits */
} Enum_Usart_StopBit_Typedef;

/**
 * @enum This enumeration is a list of data frame size options.
 */
typedef enum
{	
	Usart_UCSRnC_5bitsData = 0x00,				/**< 5-bit data frame */
	Usart_UCSRnC_6bitsData = 0x01,				/**< 6-bit data frame */
	Usart_UCSRnC_7bitsData = 0x02,				/**< 7-bit data frame */
	Usart_UCSRnC_8bitsData = 0x03,				/**< 8-bit data frame */
	// Reserved value: 0x04
	// Reserved value: 0x05
	// Reserved value: 0x06
	Usart_UCSRnC_9bitsData = 0x07				/**< 9-bit data frame */
} Enum_Usart_DataFrameSize_Typedef;

/**
 * @enum This enumeration is a list USART baudrate options.
 */
typedef enum
{	
	Usart_2400bps = 2400,				/**< 2400 bps */
	Usart_4800bps = 4800,				/**< 4800 bps */
	Usart_9600bps = 9600,				/**< 9600 bps */
	Usart_14400bps = 14400,				/**< 14400 bps */
	Usart_19200bps = 19200,				/**< 19200 bps */
	Usart_28800bps = 28800,				/**< 28800 bps */
	Usart_38400bps = 38400,				/**< 38400 bps */
	Usart_57600bps = 57600,				/**< 57600 bps */
	Usart_76800bps = 76800,				/**< 76800 bps */
	Usart_115200bps = 115200,			/**< 115200 bps */
	Usart_230400bps = 230400,			/**< 230400 bps */
	Usart_250000bps = 250000			/**< 250000 bps */
} Enum_Usart_Baudrate_Typedef;

/**
 * @struct This structure is for USART configuration.
 */
typedef struct {
	Enum_Usart_Mode_Typedef mode;
	Enum_Usart_ParityMode_Typedef parity;
	Enum_Usart_StopBit_Typedef stopBit;
	Enum_Usart_DataFrameSize_Typedef dataFrame;
} Struct_Usart_Config_Typedef;


/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/


/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/** @brief Initialize USART module.
 *
 *  @param config Initializing configuration
 *  @return none
 */
void Usart_InitUSART(const Struct_Usart_Config_Typedef *config);

/** @brief Set the USART baudrate.
 *
 *  @param baudrate The desired baudrate
 *  @return none
 */
void Usart_SetBaudrate(Enum_Usart_Baudrate_Typedef baudrate);

/** @brief Enable/Disable the USART transmitter.
 *
 *  @param cmd Enable or Disable option
 *  @return none
 */
void Usart_CommandTransmitter(Enum_Command_Typedef cmd);
	
/** @brief Enable/Disable the USART receiver.
 *
 *  @param cmd Enable or Disable option
 *  @return none
 */
void Usart_CommandReceiver(Enum_Command_Typedef cmd);

/** @brief Transmit a character in polling mode.
 *
 *  @param data Character to be sent.
 *  @param stream Standard output stream (Applied in testing stdio redirect)
 *	@note This function return a integer to become compatible with the stdout. 
 *  @return none
 */
uint8_t Usart_SendChar(uint8_t data, FILE *stream);

/** @brief Transmit a string in polling mode.
 *
 *  @param str String to be sent.
 *  @return none
 */
void Usart_SendString(uint8_t *str);

/** @brief Receive a character in polling mode.
 *
 *  @param stream Standard input stream (Applied in testing stdio redirect)
 *  @return Received character
 */
uint8_t Usart_ReceiveChar(FILE *stream);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* USART_HAL_H_ */

/** End of File ***************************************************************/
