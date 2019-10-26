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
	SPI_SPCR_TransmitMSBFirst = 0x00,			/**< Transmit data MSB first */
	SPI_SPCR_TransmitLSBFirst = 0x01			/**< Transmit data LSB first */
} SPI_DataOrder_Typedef;

/**
 * @enum This enumeration is a list of SPI modes.
 */
typedef enum
{
	SPI_SPCR_SlaveMode = 0x00,			/**< Slave mode */
	SPI_SPCR_MasterMode = 0x01			/**< Master mode */
} SPI_MasterSlaveMode_Typedef;

/**
 * @enum This enumeration is a list of SPI clock polarity options.
 */
typedef enum
{
	SPI_SPCR_IdleLow = 0x00,			/**< SPI SCK is LOW when idle */
	SPI_SPCR_IdleHigh = 0x01			/**< SPI SCK is HIGH when idle  */
} SPI_ClockPolarity_Typedef;

/**
 * @enum This enumeration is a list of SPI clock phase options.
 */
typedef enum
{
	SPI_SPCR_LeadingEdgeSampling = 0x00,			/**< Sample data on leading edge */
	SPI_SPCR_TrailingEdgeSampling = 0x01			/**< Sample data on trailing edge */
} SPI_ClockPhase_Typedef;

/**
 * @enum This enumeration is a list SPI clock frequency options.
 * @note This enumeration maps with an array of configuring bits structure 
 * (declared as "clkFreqConfig"). There are two bits configuration for 
 * the "Oscillator Frequency divided by 64" setting.
 */
typedef enum
{	
	SPI_FoscDiv4 = 0,			/**< Oscillator Frequency divided by 4 */
	SPI_FoscDiv16,				/**< Oscillator Frequency divided by 16 */
	SPI_FoscDiv64_config1,		/**< Oscillator Frequency divided by 64 */
	SPI_FoscDiv128,				/**< Oscillator Frequency divided by 128 */
	SPI_FoscDiv2,				/**< Oscillator Frequency divided by 2 */
	SPI_FoscDiv8,				/**< Oscillator Frequency divided by 8 */
	SPI_FoscDiv32,				/**< Oscillator Frequency divided by 32 */
	SPI_FoscDiv64_config2		/**< Oscillator Frequency divided by 64 */
} SPI_ClockFrequency_Typedef;

/**
 * @struct This structure is for SPI configuration.
 */
typedef struct {
	SPI_DataOrder_Typedef dataTxOrder;
	SPI_MasterSlaveMode_Typedef masterSlaveMode;
	SPI_ClockPolarity_Typedef clockPolarity;
	SPI_ClockPhase_Typedef clockPhase;
	SPI_ClockFrequency_Typedef clockFrequency;
} SPI_Config_Typedef;

/**
 * @struct This structure is for configuring bits based on defined clock frequencies.
 */
typedef struct {
	uint8_t SPI2X_value;
	uint8_t SPR1_value;
	uint8_t SPR0_value;
} SPI_ClockFrequencyConfigBits_Typedef;

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
void initSPI(SPI_Config_Typedef *config);

/** @brief Enable/Disable the SPI.
 *
 *  @param cmd Enable or Disable option
 *  @return none
 */
void commandSPI(Command_Typedef cmd);

/** @brief Transmit a byte from master node.
 *
 *  @param data To be sent data
 *  @return none
 */
void masterTransmit(uint8_t data);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* SPI_HAL_H_ */

/** End of File ***************************************************************/
