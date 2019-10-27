################################################################################
# 1. Including files
################################################################################
from CodeGenUtils import *  # This module is for contents generating utilities
from XlsProcessing import * # This module is for XLS file parsing

################################################################################
# 2. Class definition
################################################################################
# global variables
GenSourceFile = "SourceFile"
GenHeaderFile = "HeaderFile"
################################################################################
# 3. Function definition
################################################################################
def init_global_var(testcase):
    for var in testcase.global_vars:
        gen_comment_line(GenSourceFile, "Declare object to check value of " + var.actual_mem)
        gen_var_declaration(GenSourceFile, "Uint32Data_Typedef", var.gen_name)
    gen_break_line(GenSourceFile)

def init_param(testcase):
    for param in testcase.params:
        gen_comment_line(GenSourceFile, "Init " + param.gen_name)
        if param.isStructType == "False":
            gen_var_definition(GenSourceFile, param.type, param.param_name, param.init_value)
        else:
            gen_var_declaration(GenSourceFile, param.type, param.param_name)
            # Split the structure init contents into lines and store in an array
            struct_member_init = param.init_value.split("\n") 
            for statement in struct_member_init:
                sourceFile(param.param_name + "." + statement + ";")
    gen_break_line(GenSourceFile)

def call_funct_preconditon(testcase):
    invoked_func_str = testcase.invoked_func_precondition
    if "-" != invoked_func_str:
        statements = invoked_func_str.split("\n")
        
        gen_comment_line(GenSourceFile, "Test case precondition configuration")
        for statement in statements:
            sourceFile(statement)
        gen_break_line(GenSourceFile)

def call_test_method(testcase):
    # Create an array with null items ("None" is similar to null")
    param_list = [None] * len(testcase.params)
    
    # Get list of parameters from "testcase" class
    i = 0;
    for param in testcase.params:
        param_list[i] = param.param_name
        i += 1

    gen_comment_line(GenSourceFile, "Call the tested function")
    params_count = len(param_list)
    if params_count > 0:
        gen_function_call_with_arg(GenSourceFile,testcase.function_name, param_list)
    else:
        gen_function_call_no_arg(GenSourceFile, testcase.function_name)
    gen_break_line(GenSourceFile)

def compare_one_register(global_var):
    global_var_name = global_var.gen_name

    # define temporary array to pass to gen_function_call_with_arg()
    temp_global_var = [global_var_name]

    gen_comment_line(GenSourceFile, "Compare " + global_var_name + " with expected value")
    
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
    
    sourceFile(actual_content)
    sourceFile(expected_content)
    sourceFile(mask_content)
    
    gen_function_call_with_arg(GenSourceFile, "compareBits", temp_global_var)  

def compare(testcase):
    for var in testcase.global_vars:
        compare_one_register(var)

def gen_externC_beginning():
    headerFile("#ifdef __cplusplus")
    headerFile("extern \"C\"{")
    headerFile("#endif")
    gen_break_line(GenHeaderFile)

def gen_externC_ending():
    headerFile("#ifdef __cplusplus")
    headerFile("} // extern \"C\"")
    headerFile("#endif")
    gen_break_line(GenHeaderFile)

def gen_section_0_header_comment_block(fileType):
    if "SourceFile" == fileType:
        sourceFile("/** @file ut_usart_driver.c") 
        sourceFile(" *  @brief Function implementation for unit test of USART driver.")
        sourceFile(" *")
        sourceFile(" *  This file is generated from scripts. This is the source file for ")
        sourceFile(" *  the unit test definition of USART driver.")
        sourceFile(" *")
        sourceFile(" *  @author 	Tran Nhat Duat (duattn)")
        sourceFile(" *  @version 	V1.0")
        sourceFile(" */")
        gen_break_line(GenSourceFile)
    if "HeaderFile" == fileType:
        headerFile("/** @file ut_usart_driver.h")
        headerFile(" *  @brief Function prototypes for unit test of USART driver.")
        headerFile(" *")
        headerFile(" *  This file is generated from scripts. This is the header file for ")
        headerFile(" *  the unit test definition of USART driver.")
        headerFile(" *")
        headerFile(" *  @author 	Tran Nhat Duat (duattn)")
        headerFile(" *  @version 	V1.0")
        headerFile(" */")
        gen_break_line(GenHeaderFile)
        headerFile("#ifndef _UT_USART_DRIVER_H")
        headerFile("#define _UT_USART_DRIVER_H")
        gen_break_line(GenHeaderFile)
    
def gen_section_1_include_file(fileType):
    
    if "SourceFile" == fileType:
        gen_comment_block(GenSourceFile, "1. Included Files") 
        sourceFile("#include \"ut_usart_driver.h\"")
        gen_break_line(GenSourceFile)
    if "HeaderFile" == fileType:
        gen_comment_block(GenHeaderFile, "1. Included Files") 
        headerFile("#include <stdlib.h>")
        headerFile("#include \"unity.h\"")
        headerFile("#include \"ut_base.h\"")
        headerFile("#include \"usart_driver.h\"")
        gen_break_line(GenHeaderFile)
    
def gen_section_2_object_macro():
    # Generate sourcr contents
    gen_comment_block(GenSourceFile, "2. Object-like Macros") 
    gen_break_line(GenSourceFile)
    # Generate header contents
    gen_comment_block(GenHeaderFile, "2. Object-like Macros") 
    gen_break_line(GenHeaderFile)
    
def gen_section_3_function_macro():
    # Generate source contents
    gen_comment_block(GenSourceFile, "3. Function-like Macros") 
    gen_break_line(GenSourceFile)
    # Generate header contents
    gen_comment_block(GenHeaderFile, "3. Function-like Macros") 
    gen_break_line(GenHeaderFile)
    
def gen_section_4_typedef():
    # Generate source contents
    gen_comment_block(GenSourceFile, "4. Typedefs: Enumerations, Structures, Pointers, Others") 
    gen_break_line(GenSourceFile)
    # Generate header contents
    gen_comment_block(GenHeaderFile, "4. Typedefs: Enumerations, Structures, Pointers, Others") 
    gen_break_line(GenHeaderFile)

def gen_section_5_variable(fileType):
    if "SourceFile" == fileType:
        gen_comment_block(GenSourceFile, "5. Global, Static and Extern Variables")
        noTestcase = len(testSuite.testcases)
        gen_comment_line(GenSourceFile, "List of all test cases")
        with sourceFile.block("void (*testcaseList[" + str(noTestcase) + \
        "])(void) = ", ";"):
            counter = 1
            for testcase in testSuite.testcases:
                if counter < noTestcase:
                    sourceFile(testcase.testcase_name + ",")           
                else:
                    sourceFile(testcase.testcase_name)
                counter += 1
        gen_break_line(GenSourceFile)
    if "HeaderFile" == fileType:
        gen_comment_block(GenHeaderFile, "5. Global, Static and Extern Variables")
        
def gen_section_6_function_definition(fileType):
    if "SourceFile" == fileType:
        gen_comment_block(GenSourceFile, "6. Function Definitions")
        # Generate blocks of testcases
        for testcase in testSuite.testcases:
            testcase_prototype = "void " + testcase.testcase_name + "(void)"
            with sourceFile.block(testcase_prototype):
                init_global_var(testcase)    
                init_param(testcase)
                call_funct_preconditon(testcase)
                call_test_method(testcase)    
                compare(testcase)      
            gen_break_line(GenSourceFile)
    if "HeaderFile" == fileType:
        gen_comment_block(GenSourceFile, "6. Function Prototypes")
        gen_externC_beginning()
        for testcase in testSuite.testcases:
            headerFile("void " + testcase.testcase_name + "(void);")
        gen_break_line(GenHeaderFile)
        gen_externC_ending()
        
def gen_ending_header():
    # Generate source contents
    headerFile("/** End of File ***************************************************************/")
    gen_break_line(GenSourceFile)
    # Generate header contents
    headerFile("#endif /* _UT_USART_DRIVER_H */")
    gen_break_line(GenHeaderFile)
    headerFile("/** End of File ***************************************************************/")
    gen_break_line(GenHeaderFile)
    
################################################################################
# 4. Main processing: File generating
################################################################################
gen_section_0_header_comment_block(GenHeaderFile)
gen_section_0_header_comment_block(GenSourceFile)

gen_section_1_include_file(GenHeaderFile)
gen_section_1_include_file(GenSourceFile)

gen_section_2_object_macro()
gen_section_3_function_macro()
gen_section_4_typedef()

gen_section_5_variable(GenHeaderFile)
gen_section_5_variable(GenSourceFile)

gen_section_6_function_definition(GenHeaderFile)
gen_section_6_function_definition(GenSourceFile)

gen_ending_header()



# Close the generated file
sourceFile.close()