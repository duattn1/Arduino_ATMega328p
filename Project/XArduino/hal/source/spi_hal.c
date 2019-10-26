/** @file spi_hal.c
 *  @brief Function implementation for SPI driver.
 *
 *  This is the source file for the definition of SPI driver.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 */
 
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
SPI_ClockFrequencyConfigBits_Typedef clkFreqConfig[] = 
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
void initSPI(SPI_Config_Typedef *config){
	// Select data transmission order
	SPCR &= ~(1 << DORD);
	SPCR |= config->dataTxOrder << DORD;
	// Select mode: Master or Slave
	SPCR &= ~(1 << MSTR);
	SPCR |= config->masterSlaveMode << MSTR;
	// Select clock polarity
	SPCR &= ~(1 << CPOL);
	SPCR |= config->clockPolarity << CPOL;
	// Select clock phase
	SPCR &= ~(1 << CPHA);
	SPCR |= config->clockPhase << CPHA;
	// Select clock frequency
	SPCR &= ~(3 << SPR0);	/* 2-bit mask */
	SPSR &= ~(1 << SPI2X);
	SPCR |= (clkFreqConfig[config->clockFrequency].SPR1_value | 
		clkFreqConfig[config->clockFrequency].SPR0_value) << SPR0;
	SPSR |= clkFreqConfig[config->clockFrequency].SPI2X_value << SPI2X;
}

void commandSPI(Command_Typedef cmd){
	if(ENABLE == cmd){
		SPCR |= 1 << SPE;
	} else {
		SPCR &= ~(1 << SPE);
	}
}

void masterTransmit(uint8_t data) {
	SPDR = data;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
}

/** End of File ***************************************************************/
