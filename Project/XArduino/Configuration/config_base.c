/** @file config_base.c
 *  @brief Definition of basic configuration.
 *
 *  This is the source file for basic configuration.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Initial version
 *              - Added definition for fail assertion.
 * -----------------------------------------------------------------------------
 */

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "config_base.h"

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
 * 6. Function Definitions
 ******************************************************************************/
#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line){
	printf("File %s:\n", file);
	printf("Assertion was failed at line %d.\n", line);
	/* Perform a infinite loop to pause the application */
	while(1);
}
#endif /* USE_FULL_ASSERT */

/** End of File ***************************************************************/
