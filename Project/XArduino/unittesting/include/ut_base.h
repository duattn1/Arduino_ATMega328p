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
#include <string.h>
#include "unity.h"


/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/
/**
 * Command index according to the unit testing data frame
 * @note Syntax:
 *       :[command][...]. 
 */
#define CMD_INDEX           1                   /* Start testing */
#define CMD_NAME            buffer[CMD_INDEX]   /* Command name */
#define CMD_END_CHARACTER   '.'                 /* Command ending character */

/**
 * List of host commands for unit testing
 */
#define CMD_START_TESTING   's'     /* Start testing */
#define CMD_QUIT_TESTING    'q'     /* Quit testing */
#define CMD_TEST_FUNCTION   'f'     /* Send testing function name */
#define CMD_TEST_PARAMETER  'p'     /* Send testing parameters */

/**
 * Function name index according to the unit testing data frame
 * @note Syntax:
 *       :f,[...]. 
 */
#define FUNCTION_NAME_INDEX     3   /* Index of function name */

/**
 * Parameter index according to the unit testing data frame
 * @note Syntax:
 *       :p,[param_1],[param_2],[...],[param_n]. 
 */
#define PARAM_1_INDEX           3   /* Index of first parameter */
#define PARAM_DELIMITER         ',' /* Delimiter character */
#define PARAM_DELIMITER_SIZE    1   /* Delimiter size: 1 byte */
#define DEVICE_WORD_SIZE        1   /* Parameter size (= word size): 1 byte */
#define PARAM_1         buffer[PARAM_1_INDEX + 0*(DEVICE_WORD_SIZE + PARAM_DELIMITER_SIZE)]
#define PARAM_2         buffer[PARAM_1_INDEX + 1*(DEVICE_WORD_SIZE + PARAM_DELIMITER_SIZE)]
#define PARAM_3         buffer[PARAM_1_INDEX + 2*(DEVICE_WORD_SIZE + PARAM_DELIMITER_SIZE)]
#define PARAM_4         buffer[PARAM_1_INDEX + 3*(DEVICE_WORD_SIZE + PARAM_DELIMITER_SIZE)]
#define PARAM_5         buffer[PARAM_1_INDEX + 4*(DEVICE_WORD_SIZE + PARAM_DELIMITER_SIZE)]
#define PARAM_6         buffer[PARAM_1_INDEX + 5*(DEVICE_WORD_SIZE + PARAM_DELIMITER_SIZE)]
#define PARAM_7         buffer[PARAM_1_INDEX + 6*(DEVICE_WORD_SIZE + PARAM_DELIMITER_SIZE)]
#define PARAM_8         buffer[PARAM_1_INDEX + 7*(DEVICE_WORD_SIZE + PARAM_DELIMITER_SIZE)]
#define PARAM_9         buffer[PARAM_1_INDEX + 8*(DEVICE_WORD_SIZE + PARAM_DELIMITER_SIZE)]

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
 * @brief Get function index from an array of function names
 *
 * PRE-CONDITION: None
 * POST-CONDITION: None
 *
 * @param name Searched function name
 * @param functions List of function names
 * @param functionsLength Length of function list
 * @return Function index in the function list
 *
 * @see None
 */
uint8_t getFunctionIndex(const char *name, const char *functions[], uint8_t functionsLength);

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
