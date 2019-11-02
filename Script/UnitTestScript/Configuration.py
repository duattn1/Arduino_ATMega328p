################################################################################
# 1. Including files
################################################################################


################################################################################
# 2. Global Variables
################################################################################

# Test case Excel file global names
test_suite_excel_file = ("F:\\Workspace\\GitHub\\Arduino_ATMega328p\\UT_TestSuite.xls") 
test_case_sheet_list = [1, 2, 3, 4]
first_param_column = 3
tc_first_line = 5
tc_name_column = 0
tc_invoked_func_column = 1
io_type_row = 4
io_name_row = 3

tested_file = "gpio_hal"

tested_header_file = tested_file + ".h"
generated_header_file_name = "ut_" + tested_file + ".h"
generated_source_file_name = "ut_" + tested_file + ".c"

test_suite_name = "ut_" + tested_file
test_target = "GPIO driver"
header_including_guard = "_UT_GPIO_HAL_H"
test_HAL_enable_macro = "USE_GPIO_HAL"

system_register_size = 8 # Arduino is a 8-bit MCU 
################################################################################
# 3. Class definition
################################################################################


################################################################################
# 4. Function definition
################################################################################

    
################################################################################
# 5. Main processing
################################################################################
