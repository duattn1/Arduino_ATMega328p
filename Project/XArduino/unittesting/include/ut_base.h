#ifndef _UT_BASE_H
#define _UT_BASE_H

/************************************************
 *  1. Included Files
 ***********************************************/
#include <stdint.h>
#include "unity.h"


/************************************************
 *  2. Macros
 ***********************************************/


/************************************************
 *  3. Typedef
 ***********************************************/
typedef struct {
	uint32_t actual;
	uint32_t expected;
	uint32_t mask;
} Uint32Data_Typedef;

/************************************************
 *  4. Global, Static and Extern Variables
 ***********************************************/
//extern Uint32Data_Typedef data;

/************************************************
 *  5. Function Declaration
***********************************************/
void compareBits(Uint32Data_Typedef data);


#endif
