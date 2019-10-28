/** @file ut_base.c
 *  @brief Function implementation for unit testing base.
 *
 *  This is the source file for the definition of unit testing base.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 */

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/

#ifdef UNIT_TESTING	

#include "ut_base.h"

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

/*******************************************************************************
 * 6. Function Definitions
 ******************************************************************************/
void compareBitsOnUint8(Uint8Data_Typedef data){
	// Run 1 test case as basic test
	TEST_ASSERT_BITS(data.mask, data.expected, data.actual);	
}

void compareBitsOnUint32(Uint32Data_Typedef data){
	// Run 1 test case as basic test
	TEST_ASSERT_BITS(data.mask, data.expected, data.actual);	
}

void compareOnUint8(Uint8Data_Typedef data){
	// Run 1 test case as basic test
	TEST_ASSERT_EQUAL(data.expected, data.actual);	
}

void compareOnUint8Ptr(Uint8PtrData_Typedef data){
	// Run 1 test case as basic test
	TEST_ASSERT_EQUAL(*(data.expected), *(data.actual));	
}

void compareOnUint32(Uint32Data_Typedef data){
	// Run 1 test case as basic test
	TEST_ASSERT_EQUAL(data.expected, data.actual);	
}


#endif /* UNIT_TESTING */

/** End of File ***************************************************************/
