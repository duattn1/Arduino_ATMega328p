/** @file spi_hal_sample.c
 *  @brief Definition of SPI driver sample application function and data.
 *
 *  This is the source file for the definition of SPI driver sample application.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 03, 2019 - Initial version, moved SPI driver application from sample.c 
 *                to a new file.
 * -----------------------------------------------------------------------------
 */

#ifdef SPI_HAL_SAMPLE
 
/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "spi_hal_sample.h"

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
Struct_Spi_Config_Typedef SpiSampleConfig[1] =
{
    { Spi_SPCR_TransmitMSBFirst, Spi_SPCR_MasterMode,
    Spi_SPCR_IdleLow, Spi_SPCR_LeadingEdgeSampling,	Spi_FoscDiv16 }
};

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void Spi_Setup(void){
    Spi_InitSPI(&SpiSampleConfig[0]);
    Spi_CommandSPI(Enable);
    Spi_MasterTransmit('A');
}

void Spi_Loop(void){	
    while(1){
    
    }
}

#endif /* SPI_HAL_SAMPLE */

/** End of File ***************************************************************/
