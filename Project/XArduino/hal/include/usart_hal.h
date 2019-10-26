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
#include <stdint.h>
#include "boards.h"
#include "misc.h"

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/
#define FOSC 16000000UL
#define RECEIVED_STRING_LENGTH 50
#define LF_SYMBOL	10
#define CR_SYMBOL	13

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
	USART_UCSRnC_AsyncMode = 0x00,			/**< UART mode */
	USART_UCSRnC_SyncMode = 0x01,			/**< USART mode */
	// Reserved value: 0x02
	USART_UCSRnC_SPIMode = 0x03				/**< USART in SPI mode */
} USART_Mode_Typedef;

/**
 * @enum This enumeration is a list of parity bit options.
 */
typedef enum
{
	USART_UCSRnC_DisabledParity = 0x00,			/**< Parity is disabled */
	// Reserved value: 0x01
	USART_UCSRnC_EvenParity = 0x02,				/**< Even parity mode */
	USART_UCSRnC_OddParity = 0x03				/**< Odd parity mode */
} USART_ParityMode_Typedef;

/**
 * @enum This enumeration is a list of stop bit options.
 */
typedef enum
{	
	USART_UCSRnC_1StopBit = 0x00,				/**< 1 stop bit */
	USART_UCSRnC_2StopBits = 0x01				/**< 2 stop bits */
} USART_StopBit_Typedef;

/**
 * @enum This enumeration is a list of data frame size options.
 */
typedef enum
{	
	USART_UCSRnC_5bitsData = 0x00,				/**< 5-bit data frame */
	USART_UCSRnC_6bitsData = 0x01,				/**< 6-bit data frame */
	USART_UCSRnC_7bitsData = 0x02,				/**< 7-bit data frame */
	USART_UCSRnC_8bitsData = 0x03,				/**< 8-bit data frame */
	// Reserved value: 0x04
	// Reserved value: 0x05
	// Reserved value: 0x06
	USART_UCSRnC_9bitsData = 0x07				/**< 9-bit data frame */
} USART_DataFrameSize_Typedef;

/**
 * @enum This enumeration is a list USART baudrate options.
 */
typedef enum
{	
	USART_2400bps = 2400,				/**< 2400 bps */
	USART_4800bps = 4800,				/**< 4800 bps */
	USART_9600bps = 9600,				/**< 9600 bps */
	USART_14400bps = 14400,				/**< 14400 bps */
	USART_19200bps = 19200,				/**< 19200 bps */
	USART_28800bps = 28800,				/**< 28800 bps */
	USART_38400bps = 38400,				/**< 38400 bps */
	USART_57600bps = 57600,				/**< 57600 bps */
	USART_76800bps = 76800,				/**< 76800 bps */
	USART_115200bps = 115200,			/**< 115200 bps */
	USART_230400bps = 230400,			/**< 230400 bps */
	USART_250000bps = 250000			/**< 250000 bps */
} USART_Baudrate_Typedef;

/**
 * @struct This structure is for USART configuration.
 */
typedef struct {
	USART_Mode_Typedef mode;
	USART_ParityMode_Typedef parity;
	USART_StopBit_Typedef stopBit;
	USART_DataFrameSize_Typedef dataFrame;
} USART_Config_Typedef;
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
void initUSART(USART_Config_Typedef *config);

/** @brief Set the USART baudrate.
 *
 *  @param baudrate The desired baudrate
 *  @return none
 */
void setBaudrate(USART_Baudrate_Typedef baudrate);

/** @brief Enable/Disable the USART transmitter.
 *
 *  @param cmd Enable or Disable option
 *  @return none
 */
void commandTransmitter(Command_Typedef cmd);
	
/** @brief Enable/Disable the USART receiver.
 *
 *  @param cmd Enable or Disable option
 *  @return none
 */
void commandReceiver(Command_Typedef cmd);

/** @brief Transmit a character in polling mode.
 *
 *  @param data Character to be sent.
 *  @return none
 */
void sendChar(uint8_t data);

/** @brief Transmit a string in polling mode.
 *
 *  @param str String to be sent.
 *  @return none
 */
void sendString(uint8_t *str);

/** @brief Receive a character in polling mode.
 *
 *  @param none
 *  @return Received character
 */
uint8_t receiveChar(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* USART_HAL_H_ */

/** End of File ***************************************************************/
