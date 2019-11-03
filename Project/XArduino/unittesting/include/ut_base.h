/** @file ut_base.h
 *  @brief Declaration of unit testing base function and data.
 *
 *  This is the header file for the definition of unit testing base.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * TODO<<Jan 01, 2019>> - TODO<< WHAT WAS UPDATED?>>
 * -----------------------------------------------------------------------------
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
/**
 * @note This is hardcode TODO
 */
#define PARAM_1 buffer[3]
#define PARAM_2 buffer[4]
#define PARAM_3 buffer[5]
#define PARAM_4 buffer[6]
#define PARAM_5 buffer[7]
#define PARAM_6 buffer[8]
#define PARAM_7 buffer[9]
#define PARAM_8 buffer[10]
#define PARAM_9 buffer[11]
/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/

/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Unions, Pointers, Others
 ******************************************************************************/
/**
 * @struct This structure is a object for comparison with type of uint8_t.
 */
typedef struct {
    uint8_t actual;     /**< Testing actual result */
    uint8_t expected;   /**< Testing expected result */
    uint8_t mask;       /**< Testing result mask */
} Struct_Uint8Data_Typedef;

/**
 * @struct This structure is a object for comparison with type of uint8_t pointer.
 */
typedef struct {
    uint8_t *actual;    /**< Testing actual result */
    uint8_t *expected;  /**< Testing expected result */
} Struct_Uint8PtrData_Typedef;

/**
 * @struct This structure is a object for comparison with type of uint32_t.
 */
typedef struct {
    uint32_t actual;    /**< Testing actual result */
    uint32_t expected;  /**< Testing expected result */
    uint32_t mask;      /**< Testing result mask */
} Struct_Uint32Data_Typedef;

/**
 * @struct This struct TODO
 */
typedef struct{
    uint8_t command;    /**< Host command to device target */
    uint8_t option;     /**< Command option */
} Struct_HostCommand_Typedef;

/*******************************************************************************
 * 5. Global, Static, Constant, Extern Variables and Extern Functions
 ******************************************************************************/

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/** 
 * @brief Perform binary comparison on register values with type of uint8_t
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param data_ptr The object which contains compared mask, expected and actual value
 * @return None
 *
 * @see None
 */
void compareBitsOnUint8(Struct_Uint8Data_Typedef *data_ptr);

/** 
 * @brief Perform binary comparison on register values with type of uint32_t
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param data_ptr The object which contains compared mask, expected and actual value
 * @return None
 *
 * @see None
 */
void compareBitsOnUint32(Struct_Uint32Data_Typedef *data_ptr);

/** 
 * @brief Perform comparison with 2 uint8_t values
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param data_ptr The object which contains expected and actual value
 * @return None
 *
 * @see None
 */
void compareOnUint8(Struct_Uint8Data_Typedef *data_ptr);

/** 
 * @brief Perform comparison with 2 uint8_t pointers
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param data_ptr The object which contains expected and actual value
 * @return None
 *
 * @see None
 */
void compareOnUint8Ptr(Struct_Uint8PtrData_Typedef *data_ptr);

/** 
 * @brief Perform comparison with 2 uint32_t values
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param data_ptr The object which contains expected and actual value
 * @return None
 *
 * @see None
 */
void compareOnUint32(Struct_Uint32Data_Typedef *data_ptr);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _UT_BASE_H */

/** End of File ***************************************************************/
