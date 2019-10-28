#ifdef UNIT_TESTING	

/************************************************
 *  1. Included Files
 ***********************************************/
#include "ut_base.h"

/************************************************
 *  2. Global, Static and Extern Variables
 ***********************************************/


/************************************************
 *  3. Function Defintition
 ***********************************************/
void compareBits(Uint32Data_Typedef data){
	// Run 1 test case as basic test
	TEST_ASSERT_BITS(data.mask, data.expected, data.actual);	
}

#endif /* UNIT_TESTING */
	