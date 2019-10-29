/** @file ut_base.c
 *  @brief Function implementation for unit testing base.
 *
 *  This is the source file for the definition of unit testing base.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 */

#ifdef UNIT_TESTING	

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
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
void compareBitsOnUint8(Struct_Uint8Data_Typedef *data_ptr){
	// Run 1 test case as basic test
	TEST_ASSERT_BITS(data_ptr->mask, data_ptr->expected, data_ptr->actual);	
}

void compareBitsOnUint32(Struct_Uint32Data_Typedef *data_ptr){
	// Run 1 test case as basic test
	TEST_ASSERT_BITS(data_ptr->mask, data_ptr->expected, data_ptr->actual);	
}

void compareOnUint8(Struct_Uint8Data_Typedef *data_ptr){
	// Run 1 test case as basic test
	TEST_ASSERT_EQUAL(data_ptr->expected, data_ptr->actual);	
}

void compareOnUint8Ptr(Struct_Uint8PtrData_Typedef *data_ptr){
	// Run 1 test case as basic test
	TEST_ASSERT_EQUAL_PTR(data_ptr->expected, data_ptr->actual);	
}

void compareOnUint32(Struct_Uint32Data_Typedef *data_ptr){
	// Run 1 test case as basic test
	TEST_ASSERT_EQUAL(data_ptr->expected, data_ptr->actual);	
}


#endif /* UNIT_TESTING */

/** End of File ***************************************************************/
