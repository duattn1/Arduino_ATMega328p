/** @file ledMatrix_Max7219.h
 *  @brief Function prototypes for LED matrix based on Max7219.
 * 
 *  This is the header file for the definition of LED matrix based on Max7219.
 *  
 * 	@author Tran Nhat Duat (duattn)
 *	@version 	V1.0
 */

#ifndef LEDMATRIX_MAX7219_H_
#define LEDMATRIX_MAX7219_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include <avr/io.h>
#include "gpio_hal.h"

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/
#define CS_PIN		10
#define CLK_PIN		13
#define MOSI_PIN	11
#define MISO_PIN	12


/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/

	
/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Pointers, Others
 ******************************************************************************/


/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/
extern const uint8_t characterLib[43][8];

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/** @brief Send 1 byte to Max7219.
 *
 *  @param data To be sent data
 *  @return none
 */
void write_Max7219_byte(uint8_t data);

/** @brief Send a command to Max7219.
 *
 *  @param address Address to receive the command
 *  @param data To be sent command
 *  @return none
 */
void write_Max7219(uint8_t address, uint8_t data);

/** @brief Initialize Max7219
 *
 *  @param none
 *  @return none
 */
void init_Max7219(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* LEDMATRIX_MAX7219_H_ */

/** End of File ***************************************************************/
