/** @file usart_hal.h
 *  @brief Declaration of USART driver function and data.
 *
 *  This is the header file for the definition of USART driver
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 * -----------------------------------------------------------------------------
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
 * 4. Typedefs: Enumerations, Structures, Unions, Pointers, Others
 ******************************************************************************/
/**
 * @enum This enumeration is a list of USART modes.
 */
typedef enum
{
    Usart_UCSRnC_AsyncMode = 0x00,          /**< UART mode */
    Usart_UCSRnC_SyncMode = 0x01,           /**< USART mode */
    /* Reserved value: 0x02 */
    Usart_UCSRnC_SPIMode = 0x03             /**< USART in SPI mode */
} Enum_Usart_Mode_Typedef;

/**
 * @enum This enumeration is a list of parity bit options.
 */
typedef enum
{
    Usart_UCSRnC_DisabledParity = 0x00,         /**< Parity is disabled */
    /* Reserved value: 0x01 */
    Usart_UCSRnC_EvenParity = 0x02,             /**< Even parity mode */
    Usart_UCSRnC_OddParity = 0x03               /**< Odd parity mode */
} Enum_Usart_ParityMode_Typedef;

/**
 * @enum This enumeration is a list of stop bit options.
 */
typedef enum
{	
    Usart_UCSRnC_1StopBit = 0x00,       /**< 1 stop bit */
    Usart_UCSRnC_2StopBits = 0x01       /**< 2 stop bits */
} Enum_Usart_StopBit_Typedef;

/**
 * @enum This enumeration is a list of data frame size options.
 */
typedef enum
{
    Usart_UCSRnC_5bitsData = 0x00,          /**< 5-bit data frame */
    Usart_UCSRnC_6bitsData = 0x01,          /**< 6-bit data frame */
    Usart_UCSRnC_7bitsData = 0x02,          /**< 7-bit data frame */
    Usart_UCSRnC_8bitsData = 0x03,          /**< 8-bit data frame */
    /* Reserved value: 0x04 */
    /* Reserved value: 0x05 */
    /* Reserved value: 0x06 */
    Usart_UCSRnC_9bitsData = 0x07           /**< 9-bit data frame */
} Enum_Usart_DataFrameSize_Typedef;

/**
 * @enum This enumeration is a list USART baudrate options.
 */
typedef enum
{
    Usart_2400bps = 2400,               /**< 2400 bps */
    Usart_4800bps = 4800,               /**< 4800 bps */
    Usart_9600bps = 9600,               /**< 9600 bps */
    Usart_14400bps = 14400,             /**< 14400 bps */
    Usart_19200bps = 19200,             /**< 19200 bps */
    Usart_28800bps = 28800,             /**< 28800 bps */
    Usart_38400bps = 38400,             /**< 38400 bps */
    Usart_57600bps = 57600,             /**< 57600 bps */
    Usart_76800bps = 76800,             /**< 76800 bps */
    Usart_115200bps = 115200,           /**< 115200 bps */
    Usart_230400bps = 230400,           /**< 230400 bps */
    Usart_250000bps = 250000            /**< 250000 bps */
} Enum_Usart_Baudrate_Typedef;

/**
 * @struct This structure is for USART configuration.
 */
typedef struct {
    Enum_Usart_Mode_Typedef mode;                   /**< USART mode: async/sync/SPI mode */
    Enum_Usart_ParityMode_Typedef parity;           /**< Parity mode selection */
    Enum_Usart_StopBit_Typedef stopBit;             /**< Number of stop bits */
    Enum_Usart_DataFrameSize_Typedef dataSize;      /**< Size of data frame */
} Struct_Usart_Config_Typedef;

/*******************************************************************************
 * 5. Global, Static, Constant, Extern Variables and Extern Functions
 ******************************************************************************/

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/** 
 * @brief Initialize USART module
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param config_ptr Initializing configuration
 * @return None
 *
 * @see None
 */
void Usart_InitUSART(const Struct_Usart_Config_Typedef *config_ptr);

/** 
 * @brief Set the USART baudrate
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param baudrate_enum The desired baudrate value
 * @return None
 *
 * @see None
 */
void Usart_SetBaudrate(Enum_Usart_Baudrate_Typedef baudrate_enum);

/** 
 * @brief Enable/Disable the USART transmitter
 *
 * PRE-CONDITION: USART driver should be configured with Usart_InitUSART() and Usart_SetBaudrate()
 * POST-CONDITION: None
 *
 * @param cmd_enum Enable or Disable option
 * @return None
 *
 * @see Usart_InitUSART(), Usart_SetBaudrate()
 */
void Usart_CommandTransmitter(Enum_Command_Typedef cmd_enum);

/** 
 * @brief Enable/Disable the USART receiver.
 *
 * PRE-CONDITION: USART driver should be configured with Usart_InitUSART() and Usart_SetBaudrate()
 * POST-CONDITION: None
 *
 * @param cmd_enum Enable or Disable option
 * @return None
 *
 * @see Usart_InitUSART(), Usart_SetBaudrate()
 */
void Usart_CommandReceiver(Enum_Command_Typedef cmd_enum);

/** 
 * @brief Transmit a character in polling mode
 *
 * PRE-CONDITION: Transmitter must be enabled with Usart_CommandTransmitter()
 * POST-CONDITION: None
 *
 * @param data_uint8 Character to be sent
 * @param stream_ptr Standard output stream (Applied in testing stdio redirect)
 * @note This function return a integer to become compatible with the stdout. 
 * @return TODO
 *
 * @see Usart_CommandTransmitter()
 */
uint8_t Usart_SendChar(uint8_t data_uint8, FILE *stream_ptr);

/** 
 * @brief Transmit a string in polling mode.
 *
 * PRE-CONDITION: Transmitter must be enabled with Usart_CommandTransmitter()
 * POST-CONDITION: None
 *
 * @param string_ptr String to be sent
 * @return None
 *
 * @see Usart_CommandTransmitter()
 */
void Usart_SendString(uint8_t *string_ptr);

/** 
 * @brief Receive a character
 *
 * PRE-CONDITION: Receiver must be enabled with Usart_CommandReceiver()
 * POST-CONDITION: None
 *
 * @param stream_ptr Standard input stream (Applied in testing stdio redirect)
 * @return None
 *
 * @see Usart_CommandReceiver()
 */
uint8_t Usart_ReceiveChar(FILE *stream_ptr);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* USART_HAL_H_ */

/** End of File ***************************************************************/
