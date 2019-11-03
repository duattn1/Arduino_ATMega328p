/** @file spi_hal_sample.h
 *  @brief Declaration of SPI driver sample application function and data.
 *
 *  This is the header file for the definition of SPI driver sample application.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 03, 2019 - Initial version, moved SPI driver application from sample.c 
 *                to a new file.
 * -----------------------------------------------------------------------------
 */

#ifndef SPI_HAL_SAMPLE_H_
#define SPI_HAL_SAMPLE_H_

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
 * 4. Typedefs: Enumerations, Structures, Unions, Pointers, Others
 ******************************************************************************/

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
 * @brief Set up Spi driver
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param None
 * @return None
 *
 * @see None
 */
void Spi_Setup(void);

/** 
 * @brief Perform the Spi driver infinite loop
 *
 * PRE-CONDITION: Spi_Setup() function is invoked
 * POST-CONDITION: None
 *
 * @param None
 * @return None
 *
 * @see Spi_Setup()
 */
void Spi_Loop(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* SPI_HAL_SAMPLE_H_ */

/** End of File ***************************************************************/
