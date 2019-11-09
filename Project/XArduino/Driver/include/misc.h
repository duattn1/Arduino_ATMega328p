/** @file misc.h
 *  @brief Declaration of miscellaneous function and data.
 *
 *  This is the header file for the definition of miscellaneous data.
 *
 *  @author Tran Nhat Duat (duattn)
 *  @version V1.0
 *
 * ------------------------------ REVISION HISTORY -----------------------------
 * Nov 09, 2019 - Changed project language from C to C++.
 *              - Added function-like macro for Command enum
 * -----------------------------------------------------------------------------
 */
#ifndef MISC_H_
#define MISC_H_

/*******************************************************************************
 * 1. Included Files
 ******************************************************************************/

/*******************************************************************************
 * 2. Object-like Macros
 ******************************************************************************/
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

/* Bit Masks definition */
#define MASK_1BIT   0x01
#define MASK_2BIT   0x03
#define MASK_3BIT   0x07
#define MASK_4BIT   0x0F
#define MASK_5BIT   0x1F
#define MASK_6BIT   0x3F
#define MASK_7BIT   0x7F
#define MASK_8BIT   0xFF

/*******************************************************************************
 * 3. Function-like Macros
 ******************************************************************************/
/**
 * @def Check if command selection is valid.
 */
#define IS_VALID_COMMAND(cmd) \
    ((Disable == (cmd)) || \
	(Enable == (cmd)))

/**
 * @def Check if command selection is valid.
 */
#define IS_VALID_IOVALUE(value) \
    ((Low == (value)) || \
	(High == (value)))

/*******************************************************************************
 * 4. Typedefs: Enumerations, Structures, Unions, Pointers, Others
 ******************************************************************************/
/**
 * @enum This enumeration is a list of pin direction modes.
 */
typedef enum
{
    Low = 0x00,     /**< I/O Low(0) value */
    High = 0x01     /**< I/O High(1) value */
} Enum_IOValue_Typedef;

/**
 * @enum This enumeration is a list of pin direction modes.
 */
typedef enum
{
    Disable = 0x00,     /**< Disable a configuration */
    Enable = 0x01       /**< Enable a configuration */
} Enum_Command_Typedef;

/*******************************************************************************
 * 5. Global, Static, Constant, Extern Variables and Extern Functions
 ******************************************************************************/

/*******************************************************************************
 * 6. Function Prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MISC_H_ */

/** End of File ***************************************************************/
