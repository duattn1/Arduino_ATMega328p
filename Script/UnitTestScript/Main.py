################################################################################
# 1. Including files
################################################################################
import CodeGenUtils as GenUtils # This module is for contents generating utilities
import XlsProcessing as XlsProcessing # This module is for XLS file parsing
import Configuration as Config

################################################################################
# 2. Global VariablestestSuiteCollection
################################################################################


################################################################################
# 3. Class definition
################################################################################

# Global variables
gen_source_file = "SourceFile"
gen_header_file = "HeaderFile"


################################################################################
# 4. Function definition
################################################################################
def init_output_var(test_case):    
    global_var_data_type = "Struct_Uint8Data_Typedef"
    return_obj_data_type = "Struct_Uint8Data_Typedef"        
        
    # Initialize return object   
    for obj in test_case.return_objs:
        if "True" == obj.is_pointer:
            if 8 == Config.system_register_size:
                return_obj_data_type = "Struct_Uint8PtrData_Typedef"
            if 16 == Config.system_register_size:
                return_obj_data_type = "Struct_Uint16PtrData_Typedef"
            if 32 == Config.system_register_size:
                return_obj_data_type = "Struct_Uint64PtrData_Typedef"

        GenUtils.gen_comment_line(gen_source_file, "Declare object to store returning value")
        GenUtils.gen_var_declaration(gen_source_file, return_obj_data_type, obj.gen_name)
        # Declare a temporary pointer to stored the returning address.
        if "True" == obj.is_pointer:
            GenUtils.source_file("uint8_t *result_ptr;")


    # Initialize global variables   
    for var in test_case.global_vars:
        GenUtils.gen_comment_line(gen_source_file, "Declare object to check value of " + var.actual_mem)
        GenUtils.gen_var_declaration(gen_source_file, global_var_data_type, var.gen_name)
    GenUtils.gen_break_line(gen_source_file)

def init_param(test_case):
    for param in test_case.params:
        GenUtils.gen_comment_line(gen_source_file, "Initialize " + param.gen_name)
        if param.is_struct_type == "False":
            GenUtils.gen_var_definition(gen_source_file, param.type, param.param_name, param.init_value)
        else:
            GenUtils.gen_var_declaration(gen_source_file, param.type, param.param_name)
            # Split the structure init contents into lines and store in an array
            struct_member_init = param.init_value.split("\n") 
            for statement in struct_member_init:
                GenUtils.source_file(param.param_name + "." + statement + ";")
    GenUtils.gen_break_line(gen_source_file)

def call_funct_preconditon(testcase):
    invoked_func_str = testcase.invoked_func_precondition
    if "-" != invoked_func_str:
        statements = invoked_func_str.split("\n")
        
        GenUtils.gen_comment_line(gen_source_file, "Test case precondition configuration")
        for statement in statements:
            GenUtils.source_file(statement)
        GenUtils.gen_break_line(gen_source_file)

def call_test_method(test_case):
    # Create an array with null items ("None" is similar to null")
    param_list = [None] * len(test_case.params)
    
    # Get list of parameters from "testcase" class
    i = 0
    for param in test_case.params:
        param_list[i] = param.param_name
        i += 1

    result_var = ""
    type_cast = ""
    if len(test_case.return_objs) > 0:
        result_var = "result_ptr"
        if "True" == test_case.return_objs[0].is_pointer:
            type_cast = "(uint8_t*)"
    


    GenUtils.gen_comment_line(gen_source_file, "Call the tested function")
    params_count = len(param_list)
    if params_count > 0:
        GenUtils.gen_function_call_with_arg(gen_source_file, test_case.function_name, result_var, type_cast, param_list)
    else:
        GenUtils.gen_function_call_no_arg(gen_source_file, test_case.function_name, result_var, type_cast)
    GenUtils.gen_break_line(gen_source_file)    

def compare_returning_value(return_obj):
    return_obj_name = return_obj.gen_name
    return_obj_name_to_function = "&" + return_obj_name                   

    # define temporary array to pass as parameters to GenUtils.GenUtils.gen_function_call_with_arg()
    temp_return_obj = [return_obj_name_to_function]

    GenUtils.gen_comment_line(gen_source_file, "Compare " + return_obj_name + " with expected value")
    
    # Contents of actual result after function calling
    actual_content = return_obj_name + ".actual = "
    actual_content += "result_ptr;" #fixed name
    # Contents of return_obj.expected_value
    expected_content = return_obj_name + ".expected = (uint8_t*)" # perform a pointer casting
    expected_content += return_obj.expected_value
    expected_content += ";"
        
    GenUtils.source_file(actual_content)
    GenUtils.source_file(expected_content)
    
    GenUtils.gen_function_call_with_arg(gen_source_file, "compareOnUint8Ptr", "", "", temp_return_obj)

def compare_one_register(global_var):
    global_var_name = global_var.gen_name
    global_var_name_to_function = "&" + global_var_name

    # define temporary array to pass as parameters to GenUtils.gen_function_call_with_arg()
    temp_global_var = [global_var_name_to_function]

    GenUtils.gen_comment_line(gen_source_file, "Compare " + global_var_name + " with expected value")
    
    # Contents of global_var_n.actual
    actual_content = global_var_name + ".actual = "
    actual_content += global_var.actual_mem
    actual_content += ";"
    # Contents of global_var_n.expected
    expected_content = global_var_name + ".expected = "
    expected_content += global_var.expected
    expected_content += ";"
    # Contents of global_var_n.mask
    mask_content = global_var_name + ".mask = "
    mask_content += global_var.mask
    mask_content += ";"
    
    GenUtils.source_file(actual_content)
    GenUtils.source_file(expected_content)
    GenUtils.source_file(mask_content)
    
    GenUtils.gen_function_call_with_arg(gen_source_file, "compareBitsOnUint8", "", "", temp_global_var)  

def compare(testcase):
    for returnObj in testcase.return_objs:
        compare_returning_value(returnObj)
    for var in testcase.global_vars:
        compare_one_register(var)

def gen_externC_beginning():
    GenUtils.header_file("#ifdef __cplusplus")
    GenUtils.header_file("extern \"C\"{")
    GenUtils.header_file("#endif")
    GenUtils.gen_break_line(gen_header_file)

def gen_externC_ending():
    GenUtils.header_file("#ifdef __cplusplus")
    GenUtils.header_file("} // extern \"C\"")
    GenUtils.header_file("#endif")
    GenUtils.gen_break_line(gen_header_file)

def gen_section_0_header_comment_block(fileType):
    if "SourceFile" == fileType:
        GenUtils.source_file("/** @file ut_gpio_hal.c") 
        GenUtils.source_file(" *  @brief Function implementation for unit test of " + Config.test_target + ".")
        GenUtils.source_file(" *")
        GenUtils.source_file(" *  This file is generated from scripts. This is the source file for ")
        GenUtils.source_file(" *  the unit test definition of " + Config.test_target + ".")
        GenUtils.source_file(" *")
        GenUtils.source_file(" *  @author 	Tran Nhat Duat (duattn)")
        GenUtils.source_file(" *  @version 	V1.0")
        GenUtils.source_file(" */")
        GenUtils.gen_break_line(gen_source_file)
        GenUtils.source_file("#if defined (UNIT_TESTING) && defined (" + Config.test_HAL_enable_macro + ")")
        GenUtils.gen_break_line(gen_source_file)
    if "HeaderFile" == fileType:
        GenUtils.header_file("/** @file ut_gpio_hal.h")
        GenUtils.header_file(" *  @brief Function prototypes for unit test of " + Config.test_target + ".")
        GenUtils.header_file(" *")
        GenUtils.header_file(" *  This file is generated from scripts. This is the header file for ")
        GenUtils.header_file(" *  the unit test definition of " + Config.test_target + ".")
        GenUtils.header_file(" *")
        GenUtils.header_file(" *  @author 	Tran Nhat Duat (duattn)")
        GenUtils.header_file(" *  @version 	V1.0")
        GenUtils.header_file(" */")
        GenUtils.gen_break_line(gen_header_file)
        GenUtils.header_file("#ifndef " + Config.header_including_guard)
        GenUtils.header_file("#define " + Config.header_including_guard)
        GenUtils.gen_break_line(gen_header_file)
    
def gen_section_1_include_file(file_type):
    
    if "SourceFile" == file_type:
        GenUtils.gen_comment_block(gen_source_file, "1. Included Files") 
        GenUtils.source_file("#include \"" + Config.generated_header_file_name + "\"")
        GenUtils.gen_break_line(gen_source_file)
    if "HeaderFile" == file_type:
        GenUtils.gen_comment_block(gen_header_file, "1. Included Files") 
        GenUtils.header_file("#include <stdlib.h>")
        GenUtils.header_file("#include \"unity.h\"")
        GenUtils.header_file("#include \"ut_base.h\"")
        GenUtils.header_file("#include \"" + Config.tested_header_file + "\"")
        GenUtils.gen_break_line(gen_header_file)
    
def gen_section_2_object_macro():
    # Generate sourcr contents
    GenUtils.gen_comment_block(gen_source_file, "2. Object-like Macros") 
    GenUtils.gen_break_line(gen_source_file)
    # Generate header contents
    GenUtils.gen_comment_block(gen_header_file, "2. Object-like Macros") 
    GenUtils.gen_break_line(gen_header_file)
    
def gen_section_3_function_macro():
    # Generate source contents
    GenUtils.gen_comment_block(gen_source_file, "3. Function-like Macros") 
    GenUtils.gen_break_line(gen_source_file)
    # Generate header contents
    GenUtils.gen_comment_block(gen_header_file, "3. Function-like Macros") 
    GenUtils.gen_break_line(gen_header_file)
    
def gen_section_4_typedef():
    # Generate source contents
    GenUtils.gen_comment_block(gen_source_file, "4. Typedefs: Enumerations, Structures, Pointers, Others") 
    GenUtils.gen_break_line(gen_source_file)
    # Generate header contents
    GenUtils.gen_comment_block(gen_header_file, "4. Typedefs: Enumerations, Structures, Pointers, Others") 
    GenUtils.gen_break_line(gen_header_file)

def gen_section_5_variable(file_type):
    if "SourceFile" == file_type:
        GenUtils.gen_comment_block(gen_source_file, "5. Global, Static and Extern Variables")
        no_test_ccase = len(XlsProcessing.test_suite.test_cases)
        GenUtils.gen_comment_line(gen_source_file, "List of all test cases")
        with GenUtils.source_file.block("void (*TestcaseList_array[" + str(no_test_ccase) + \
        "])(void) = ", ";"):
            counter = 1
            for test_case in XlsProcessing.test_suite.test_cases:
                if counter < no_test_ccase:
                    GenUtils.source_file(test_case.testcase_name + ",")           
                else:
                    GenUtils.source_file(test_case.testcase_name)
                counter += 1
        GenUtils.gen_break_line(gen_source_file)
    if "HeaderFile" == file_type:
        GenUtils.gen_comment_block(gen_header_file, "5. Global, Static and Extern Variables")
        GenUtils.gen_break_line(gen_header_file)
        
def gen_section_6_function_definition(file_type):
    if "SourceFile" == file_type:
        GenUtils.gen_comment_block(gen_source_file, "6. Function Definitions")
        # Generate blocks of testcases
        for test_case in XlsProcessing.test_suite.test_cases:
            testcase_prototype = "void " + test_case.testcase_name + "(void)"
            with GenUtils.source_file.block(testcase_prototype):
                init_output_var(test_case)    
                init_param(test_case)
                call_funct_preconditon(test_case)
                call_test_method(test_case)    
                compare(test_case)      
            GenUtils.gen_break_line(gen_source_file)
    if "HeaderFile" == file_type:
        GenUtils.gen_comment_block(gen_header_file, "6. Function Prototypes")
        gen_externC_beginning()
        for test_case in XlsProcessing.test_suite.test_cases:
            GenUtils.header_file("void " + test_case.testcase_name + "(void);")
        GenUtils.gen_break_line(gen_header_file)
        gen_externC_ending()
        
def gen_ending_header():
    # Generate source contents
    GenUtils.source_file("#endif /* defined (UNIT_TESTING) && defined (" + Config.test_HAL_enable_macro + ") */")
    GenUtils.gen_break_line(gen_source_file)
    GenUtils.source_file("/** End of File ***************************************************************/")
    GenUtils.gen_break_line(gen_source_file)
    # Generate header contents
    GenUtils.header_file("#endif /* " + Config.header_including_guard + " */")
    GenUtils.gen_break_line(gen_header_file)
    GenUtils.header_file("/** End of File ***************************************************************/")
    GenUtils.gen_break_line(gen_header_file)
    
################################################################################
# 5. Main processing: File generating
################################################################################
gen_section_0_header_comment_block(gen_header_file)
gen_section_0_header_comment_block(gen_source_file)

gen_section_1_include_file(gen_header_file)
gen_section_1_include_file(gen_source_file)

gen_section_2_object_macro()
gen_section_3_function_macro()
gen_section_4_typedef()

gen_section_5_variable(gen_header_file)
gen_section_5_variable(gen_source_file)

gen_section_6_function_definition(gen_header_file)
gen_section_6_function_definition(gen_source_file)

gen_ending_header()


# Close the generated file
GenUtils.source_file.close()
GenUtils.header_file.close()
