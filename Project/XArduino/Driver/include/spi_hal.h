/** @file spi_hal.h
 *  @brief Declaration of SPI driver function and data.
 *
 *  This is the header file for the definition of SPI driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 * -----------------------------------------------------------------------------
 */
#ifndef SPI_HAL_H_
#define SPI_HAL_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "config_driver.h"

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/

/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/
	
/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Unions, Pointers, Others
 ******************************************************************************/
/**
 * @enum This enumeration is a list of SPI data transmit order options.
 */
typedef enum
{
    Spi_SPCR_TransmitMSBFirst = 0x00,       /**< Transmit data MSB first */
    Spi_SPCR_TransmitLSBFirst = 0x01        /**< Transmit data LSB first */
} Enum_Spi_DataOrder_Typedef;

/**
 * @enum This enumeration is a list of SPI modes.
 */
typedef enum
{
    Spi_SPCR_SlaveMode = 0x00,      /**< Slave mode */
    Spi_SPCR_MasterMode = 0x01      /**< Master mode */
} Enum_Spi_MasterSlaveMode_Typedef;

/**
 * @enum This enumeration is a list of SPI clock polarity options.
 */
typedef enum
{
    Spi_SPCR_IdleLow = 0x00,        /**< SPI SCK is LOW when idle */
    Spi_SPCR_IdleHigh = 0x01        /**< SPI SCK is HIGH when idle  */
} Enum_Spi_ClockPolarity_Typedef;

/**
 * @enum This enumeration is a list of SPI clock phase options.
 */
typedef enum
{
    Spi_SPCR_LeadingEdgeSampling = 0x00,        /**< Sample data on leading edge */
    Spi_SPCR_TrailingEdgeSampling = 0x01        /**< Sample data on trailing edge */
} Enum_Spi_ClockPhase_Typedef;

/**
 * @enum This enumeration is a list SPI clock frequency options.
 * @note This enumeration maps with an array of configuring bits structure 
 * (declared as "clkFreqConfig"). There are two bits configuration for 
 * the "Oscillator Frequency divided by 64" setting.
 */
typedef enum
{
    Spi_FoscDiv4 = 0,           /**< Oscillator Frequency divided by 4 */
    Spi_FoscDiv16,              /**< Oscillator Frequency divided by 16 */
    Spi_FoscDiv64_config1,      /**< Oscillator Frequency divided by 64 */
    Spi_FoscDiv128,             /**< Oscillator Frequency divided by 128 */
    Spi_FoscDiv2,               /**< Oscillator Frequency divided by 2 */
    Spi_FoscDiv8,               /**< Oscillator Frequency divided by 8 */
    Spi_FoscDiv32,              /**< Oscillator Frequency divided by 32 */
    Spi_FoscDiv64_config2       /**< Oscillator Frequency divided by 64 */
} Enum_Spi_ClockFrequency_Typedef;

/**
 * @struct This structure is for SPI configuration.
 */
typedef struct {
    Enum_Spi_DataOrder_Typedef dataTxOrder;             /**< Data transmit order: transfer data MSB or LSB first */
    Enum_Spi_MasterSlaveMode_Typedef masterSlaveMode;   /**< Mode selection: master or slave */
    Enum_Spi_ClockPolarity_Typedef clockPolarity;       /**< Clock polarity mode selection */
    Enum_Spi_ClockPhase_Typedef clockPhase;             /**< Clock phase mode selection */
    Enum_Spi_ClockFrequency_Typedef clockFrequency;     /**< Clock frequency value */
} Struct_Spi_Config_Typedef;

/**
 * @struct This structure is for configuring bits based on defined clock frequencies.
 */
typedef struct {
    uint8_t SPI2X_value;    /**< SPI2X bit value */
    uint8_t SPR1_value;     /**< SPR1 bit value */
    uint8_t SPR0_value;     /**< SPR0 bit value */
} Struct_Spi_ClockFrequencyConfigBits_Typedef;

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
 * @brief Initialize SPI driver
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param config_ptr Initializing configuration
 * @return None
 *
 * @see None
 */
void Spi_InitSPI(Struct_Spi_Config_Typedef *config_ptr);

/** 
 * @brief Enable/Disable the SPI
 *
 * PRE-CONDITION: Spi_InitSPI() should be invoked before enalbe SPI driver
 * POST-CONDITION: None
 *
 * @param cmd_enum Enable or Disable option
 * @return None
 *
 * @see Spi_InitSPI()
 */
void Spi_CommandSPI(Enum_Command_Typedef cmd_enum);

/** 
 * @brief Transmit a byte from master node
 *
 * PRE-CONDITION: - SPI is enabled with Spi_CommandSPI()
 *                - SPI device is set as Master mode with Spi_InitSPI()
 * POST-CONDITION: None
 *
 * @param data_uint8 To be sent data
 * @return None
 *
 * @see Spi_InitSPI(), Spi_CommandSPI()
 */
void Spi_MasterTransmit(uint8_t data_uint8);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* SPI_HAL_H_ */

/** End of File ***************************************************************/
