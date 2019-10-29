/** @file spi_hal.c
 *  @brief Function implementation for SPI driver.
 *
 *  This is the source file for the definition of SPI driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 */

#ifdef USE_SPI_HAL
 
/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "spi_hal.h"

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
/* This array list all values of SPI2X, SPR1 and SPR0 to configure each clock frequency. */
Struct_Spi_ClockFrequencyConfigBits_Typedef ClkFreqConfig_array[] = 
{
	{0, 0, 0},  /* Fosc/4 */
	{0, 0, 1},  /* Fosc/16 */
	{0, 1, 0},  /* Fosc/64 */
	{0, 1, 1},  /* Fosc/128 */
	{1, 0, 0},  /* Fosc/2 */
	{1, 0, 1},  /* Fosc/8 */
	{1, 1, 0},  /* Fosc/32 */
	{1, 1, 1}	/* Fosc/64 */
};

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void Spi_InitSPI(Struct_Spi_Config_Typedef *config_ptr){
	// Select data transmission order
	SPCR &= ~(MASK_1BIT << DORD);
	SPCR |= config_ptr->dataTxOrder << DORD;
	// Select mode: Master or Slave
	SPCR &= ~(MASK_1BIT << MSTR);
	SPCR |= config_ptr->masterSlaveMode << MSTR;
	// Select clock polarity
	SPCR &= ~(MASK_1BIT << CPOL);
	SPCR |= config_ptr->clockPolarity << CPOL;
	// Select clock phase
	SPCR &= ~(MASK_1BIT << CPHA);
	SPCR |= config_ptr->clockPhase << CPHA;
	// Select clock frequency
	SPCR &= ~(MASK_2BIT << SPR0);
	SPSR &= ~(MASK_1BIT << SPI2X);
	SPCR |= (ClkFreqConfig_array[config_ptr->clockFrequency].SPR1_value | 
		ClkFreqConfig_array[config_ptr->clockFrequency].SPR0_value) << SPR0;
	SPSR |= ClkFreqConfig_array[config_ptr->clockFrequency].SPI2X_value << SPI2X;
}

void Spi_CommandSPI(Enum_Command_Typedef cmd_enum){
	if(Enable == cmd_enum){
		SPCR |= 1 << SPE;
	} else {
		SPCR &= ~(1 << SPE);
	}
}

void Spi_MasterTransmit(uint8_t data_uint8) {
	SPDR = data_uint8;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
}

#endif /* USE_SPI_HAL */

/** End of File ***************************************************************/
