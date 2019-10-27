/** @file spi_hal.h
 *  @brief Function prototypes for SPI driver.
 * 
 *  This is the header file for the definition of SPI driver.
 *  
 * 	@author Tran Nhat Duat (duattn)
 *	@version 	V1.0
 */

#ifndef SPI_HAL_H_
#define SPI_HAL_H_

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


/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/

	
/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Pointers, Others
 ******************************************************************************/
/**
 * @enum This enumeration is a list of SPI data transmit order options.
 */
typedef enum
{
	Spi_SPCR_TransmitMSBFirst = 0x00,			/**< Transmit data MSB first */
	Spi_SPCR_TransmitLSBFirst = 0x01			/**< Transmit data LSB first */
} Enum_Spi_DataOrder_Typedef;

/**
 * @enum This enumeration is a list of SPI modes.
 */
typedef enum
{
	Spi_SPCR_SlaveMode = 0x00,			/**< Slave mode */
	Spi_SPCR_MasterMode = 0x01			/**< Master mode */
} Enum_Spi_MasterSlaveMode_Typedef;

/**
 * @enum This enumeration is a list of SPI clock polarity options.
 */
typedef enum
{
	Spi_SPCR_IdleLow = 0x00,			/**< SPI SCK is LOW when idle */
	Spi_SPCR_IdleHigh = 0x01			/**< SPI SCK is HIGH when idle  */
} Enum_Spi_ClockPolarity_Typedef;

/**
 * @enum This enumeration is a list of SPI clock phase options.
 */
typedef enum
{
	Spi_SPCR_LeadingEdgeSampling = 0x00,			/**< Sample data on leading edge */
	Spi_SPCR_TrailingEdgeSampling = 0x01			/**< Sample data on trailing edge */
} Enum_Spi_ClockPhase_Typedef;

/**
 * @enum This enumeration is a list SPI clock frequency options.
 * @note This enumeration maps with an array of configuring bits structure 
 * (declared as "clkFreqConfig"). There are two bits configuration for 
 * the "Oscillator Frequency divided by 64" setting.
 */
typedef enum
{	
	Spi_FoscDiv4 = 0,			/**< Oscillator Frequency divided by 4 */
	Spi_FoscDiv16,				/**< Oscillator Frequency divided by 16 */
	Spi_FoscDiv64_config1,		/**< Oscillator Frequency divided by 64 */
	Spi_FoscDiv128,				/**< Oscillator Frequency divided by 128 */
	Spi_FoscDiv2,				/**< Oscillator Frequency divided by 2 */
	Spi_FoscDiv8,				/**< Oscillator Frequency divided by 8 */
	Spi_FoscDiv32,				/**< Oscillator Frequency divided by 32 */
	Spi_FoscDiv64_config2		/**< Oscillator Frequency divided by 64 */
} Enum_Spi_ClockFrequency_Typedef;

/**
 * @struct This structure is for SPI configuration.
 */
typedef struct {
	Enum_Spi_DataOrder_Typedef dataTxOrder;
	Enum_Spi_MasterSlaveMode_Typedef masterSlaveMode;
	Enum_Spi_ClockPolarity_Typedef clockPolarity;
	Enum_Spi_ClockPhase_Typedef clockPhase;
	Enum_Spi_ClockFrequency_Typedef clockFrequency;
} Struct_Spi_Config_Typedef;

/**
 * @struct This structure is for configuring bits based on defined clock frequencies.
 */
typedef struct {
	uint8_t SPI2X_value;
	uint8_t SPR1_value;
	uint8_t SPR0_value;
} Struct_Spi_ClockFrequencyConfigBits_Typedef;

/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/


/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/** @brief Initialize SPI module.
 *
 *  @param config Initializing configuration
 *  @return none
 */
void Spi_InitSPI(Struct_Spi_Config_Typedef *config);

/** @brief Enable/Disable the SPI.
 *
 *  @param cmd Enable or Disable option
 *  @return none
 */
void Spi_CommandSPI(Enum_Command_Typedef cmd);

/** @brief Transmit a byte from master node.
 *
 *  @param data To be sent data
 *  @return none
 */
void Spi_MasterTransmit(uint8_t data);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* SPI_HAL_H_ */

/** End of File ***************************************************************/
