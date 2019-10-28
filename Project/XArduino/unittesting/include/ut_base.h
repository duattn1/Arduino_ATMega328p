/** @file ut_base.h
 *  @brief Function prototypes for unit testing base.
 * 
 *  This is the header file for the definition of unit testing base.
 *  
 * 	@author Tran Nhat Duat (duattn)
 *	@version 	V1.0
 */

#ifndef _UT_BASE_H
#define _UT_BASE_H

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include <stdint.h>
#include "unity.h"


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
 * @struct This structure is a object for comparison with type of uint8_t.
 */
typedef struct {
	uint8_t actual;
	uint8_t expected;
	uint8_t mask;
} Uint8Data_Typedef;

/**
 * @struct This structure is a object for comparison with type of uint8_t pointer.
 */
typedef struct {
	uint8_t *actual;
	uint8_t *expected;
} Uint8PtrData_Typedef;

/**
 * @struct This structure is a object for comparison with type of uint32_t.
 */
typedef struct {
	uint32_t actual;
	uint32_t expected;
	uint32_t mask;
} Uint32Data_Typedef;

/*******************************************************************************
 * 5. Global, Static and Extern Variables
 ******************************************************************************/

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/** @brief Perform binary comparison on register values with type of uint8_t.
 *
 *  @param data The object which contains compared mask, expected and actual value
 *  @return none
 */
void compareBitsOnUint8(Uint8Data_Typedef data);

/** @brief Perform binary comparison on register values with type of uint32_t.
 *
 *  @param data The object which contains compared mask, expected and actual value
 *  @return none
 */
void compareBitsOnUint32(Uint32Data_Typedef data);

/** @brief Perform comparison with 2 uint8_t values.
 *
 *  @param data The object which contains expected and actual value
 *  @return none
 */
void compareOnUint8(Uint8Data_Typedef data);

/** @brief Perform comparison with 2 uint8_t pointers.
 *
 *  @param data The object which contains expected and actual value
 *  @return none
 */
void compareOnUint8Ptr(Uint8PtrData_Typedef data);

/** @brief Perform comparison with 2 uint32_t values.
 *
 *  @param data The object which contains expected and actual value
 *  @return none
 */
void compareOnUint32(Uint32Data_Typedef data);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* _UT_BASE_H */

/** End of File ***************************************************************/
