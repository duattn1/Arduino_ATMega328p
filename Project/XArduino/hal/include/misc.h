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
	Low = 0x00,			/**< I/O Low(0) value */
	High = 0x01			/**< I/O High(1) value */
} Enum_IOValue_Typedef;

/**
 * @enum This enumeration is a list of pin direction modes.
 */
typedef enum
{
	Disable = 0x00,			/**< Disable a configuration */
	Enable = 0x01			/**< Enable a configuration */
} Enum_Command_Typedef;

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