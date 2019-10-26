/** @file misc.h
 *  @brief Function prototypes for miscellaneous things.
 * 
 *  This is the header file for the definition of miscellaneous things.
 *  
 * 	@author Tran Nhat Duat (duattn)
 *	@version 	V1.0
 */

#ifndef MISC_H_
#define MISC_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include <avr/io.h>

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/
#define NULL	0

/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/

	
/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Pointers, Others
 ******************************************************************************/
/**
 * @enum This enumeration is a list of pin direction modes.
 */
typedef enum
{
	LOW = 0x00,			/**< I/O LOW(0) value */
	HIGH = 0x01			/**< I/O HIGH(1) value */
} IOValue_Typedef;

/**
 * @enum This enumeration is a list of pin direction modes.
 */
typedef enum
{
	DISABLE = 0x00,			/**< Disable a configuration */
	ENABLE = 0x01			/**< Enable a configuration */
} Command_Typedef;

/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/


/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif


#ifdef __cplusplus
} // extern "C"
#endif

#endif /* MISC_H_ */

/** End of File ***************************************************************/
