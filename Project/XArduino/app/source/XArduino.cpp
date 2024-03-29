/** @file main.c
 *  @brief Definition of main processing function and data.
 *
 *  This is the source file for the definition of main processing.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 * -----------------------------------------------------------------------------
 */
 
/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/
#include "sample.h"

#ifdef UNIT_TESTING
#include "ut_main.h"
#endif
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
int main(void)
{
#ifndef UNIT_TESTING	
    Sample_RunApp();
#else
    Test_RunTest();	
#endif
}

/** End of File ***************************************************************/
