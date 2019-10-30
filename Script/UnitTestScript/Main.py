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
GenSourceFile = "SourceFile"
GenHeaderFile = "HeaderFile"


################################################################################
# 4. Function definition
################################################################################
def init_output_var(testcase):    
    globalVarDataType = "Struct_Uint8Data_Typedef"
    returnObjDataType = "Struct_Uint8Data_Typedef"        
        
    # Initialize return object   
    for obj in testcase.return_objs:
        if "True" == obj.isPointer:
            if 8 == Config.systemRegisterSize:
                returnObjDataType = "Struct_Uint8PtrData_Typedef"
            if 16 == Config.systemRegisterSize:
                returnObjDataType = "Struct_Uint16PtrData_Typedef"
            if 32 == Config.systemRegisterSize:
                returnObjDataType = "Struct_Uint64PtrData_Typedef"

        GenUtils.gen_comment_line(GenSourceFile, "Declare object to store returning value")
        GenUtils.gen_var_declaration(GenSourceFile, returnObjDataType, obj.gen_name)
        # Declare a temporary pointer to stored the returning address.
        if "True" == obj.isPointer:
            GenUtils.sourceFile("uint8_t *result_ptr;")


    # Initialize global variables   
    for var in testcase.global_vars:
        GenUtils.gen_comment_line(GenSourceFile, "Declare object to check value of " + var.actual_mem)
        GenUtils.gen_var_declaration(GenSourceFile, globalVarDataType, var.gen_name)
    GenUtils.gen_break_line(GenSourceFile)

def init_param(testcase):
    for param in testcase.params:
        GenUtils.gen_comment_line(GenSourceFile, "Initialize " + param.gen_name)
        if param.isStructType == "False":
            GenUtils.gen_var_definition(GenSourceFile, param.type, param.param_name, param.init_value)
        else:
            GenUtils.gen_var_declaration(GenSourceFile, param.type, param.param_name)
            # Split the structure init contents into lines and store in an array
            struct_member_init = param.init_value.split("\n") 
            for statement in struct_member_init:
                GenUtils.sourceFile(param.param_name + "." + statement + ";")
    GenUtils.gen_break_line(GenSourceFile)

def call_funct_preconditon(testcase):
    invoked_func_str = testcase.invoked_func_precondition
    if "-" != invoked_func_str:
        statements = invoked_func_str.split("\n")
        
        GenUtils.gen_comment_line(GenSourceFile, "Test case precondition configuration")
        for statement in statements:
            GenUtils.sourceFile(statement)
        GenUtils.gen_break_line(GenSourceFile)

def call_test_method(testcase):
    # Create an array with null items ("None" is similar to null")
    param_list = [None] * len(testcase.params)
    
    # Get list of parameters from "testcase" class
    i = 0
    for param in testcase.params:
        param_list[i] = param.param_name
        i += 1

    result_var = ""
    type_cast = ""
    if len(testcase.return_objs) > 0:
        result_var = "result_ptr"
        if "True" == testcase.return_objs[0].isPointer:
            type_cast = "(uint8_t*)"
    


    GenUtils.gen_comment_line(GenSourceFile, "Call the tested function")
    params_count = len(param_list)
    if params_count > 0:
        GenUtils.gen_function_call_with_arg(GenSourceFile, testcase.function_name, result_var, type_cast, param_list)
    else:
        GenUtils.gen_function_call_no_arg(GenSourceFile, testcase.function_name, result_var, type_cast)
    GenUtils.gen_break_line(GenSourceFile)    

def compare_returning_value(return_obj):
    return_obj_name = return_obj.gen_name
    return_obj_name_to_function = "&" + return_obj_name                   

    # define temporary array to pass as parameters to GenUtils.GenUtils.gen_function_call_with_arg()
    temp_return_obj = [return_obj_name_to_function]

    GenUtils.gen_comment_line(GenSourceFile, "Compare " + return_obj_name + " with expected value")
    
    # Contents of actual result after function calling
    actual_content = return_obj_name + ".actual = "
    actual_content += "result_ptr;" #fixed name
    # Contents of return_obj.expected_value
    expected_content = return_obj_name + ".expected = (uint8_t*)" # perform a pointer casting
    expected_content += return_obj.expected_value
    expected_content += ";"
        
    GenUtils.sourceFile(actual_content)
    GenUtils.sourceFile(expected_content)
    
    GenUtils.gen_function_call_with_arg(GenSourceFile, "compareOnUint8Ptr", "", "", temp_return_obj)

def compare_one_register(global_var):
    global_var_name = global_var.gen_name
    global_var_name_to_function = "&" + global_var_name

    # define temporary array to pass as parameters to GenUtils.gen_function_call_with_arg()
    temp_global_var = [global_var_name_to_function]

    GenUtils.gen_comment_line(GenSourceFile, "Compare " + global_var_name + " with expected value")
    
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
    
    GenUtils.sourceFile(actual_content)
    GenUtils.sourceFile(expected_content)
    GenUtils.sourceFile(mask_content)
    
    GenUtils.gen_function_call_with_arg(GenSourceFile, "compareBitsOnUint8", "", "", temp_global_var)  

def compare(testcase):
    for returnObj in testcase.return_objs:
        compare_returning_value(returnObj)
    for var in testcase.global_vars:
        compare_one_register(var)

def gen_externC_beginning():
    GenUtils.headerFile("#ifdef __cplusplus")
    GenUtils.headerFile("extern \"C\"{")
    GenUtils.headerFile("#endif")
    GenUtils.gen_break_line(GenHeaderFile)

def gen_externC_ending():
    GenUtils.headerFile("#ifdef __cplusplus")
    GenUtils.headerFile("} // extern \"C\"")
    GenUtils.headerFile("#endif")
    GenUtils.gen_break_line(GenHeaderFile)

def gen_section_0_header_comment_block(fileType):
    if "SourceFile" == fileType:
        GenUtils.sourceFile("/** @file ut_gpio_hal.c") 
        GenUtils.sourceFile(" *  @brief Function implementation for unit test of " + Config.testTarget + ".")
        GenUtils.sourceFile(" *")
        GenUtils.sourceFile(" *  This file is generated from scripts. This is the source file for ")
        GenUtils.sourceFile(" *  the unit test definition of " + Config.testTarget + ".")
        GenUtils.sourceFile(" *")
        GenUtils.sourceFile(" *  @author 	Tran Nhat Duat (duattn)")
        GenUtils.sourceFile(" *  @version 	V1.0")
        GenUtils.sourceFile(" */")
        GenUtils.gen_break_line(GenSourceFile)
        GenUtils.sourceFile("#ifdef UNIT_TESTING")
        GenUtils.gen_break_line(GenSourceFile)
    if "HeaderFile" == fileType:
        GenUtils.headerFile("/** @file ut_gpio_hal.h")
        GenUtils.headerFile(" *  @brief Function prototypes for unit test of " + Config.testTarget + ".")
        GenUtils.headerFile(" *")
        GenUtils.headerFile(" *  This file is generated from scripts. This is the header file for ")
        GenUtils.headerFile(" *  the unit test definition of " + Config.testTarget + ".")
        GenUtils.headerFile(" *")
        GenUtils.headerFile(" *  @author 	Tran Nhat Duat (duattn)")
        GenUtils.headerFile(" *  @version 	V1.0")
        GenUtils.headerFile(" */")
        GenUtils.gen_break_line(GenHeaderFile)
        GenUtils.headerFile("#ifndef " + Config.headerIncludingGuard)
        GenUtils.headerFile("#define " + Config.headerIncludingGuard)
        GenUtils.gen_break_line(GenHeaderFile)
    
def gen_section_1_include_file(fileType):
    
    if "SourceFile" == fileType:
        GenUtils.gen_comment_block(GenSourceFile, "1. Included Files") 
        GenUtils.sourceFile("#include \"" + Config.generatedHeaderFileName + "\"")
        GenUtils.gen_break_line(GenSourceFile)
    if "HeaderFile" == fileType:
        GenUtils.gen_comment_block(GenHeaderFile, "1. Included Files") 
        GenUtils.headerFile("#include <stdlib.h>")
        GenUtils.headerFile("#include \"unity.h\"")
        GenUtils.headerFile("#include \"ut_base.h\"")
        GenUtils.headerFile("#include \"" + Config.testedHeaderFile + "\"")
        GenUtils.gen_break_line(GenHeaderFile)
    
def gen_section_2_object_macro():
    # Generate sourcr contents
    GenUtils.gen_comment_block(GenSourceFile, "2. Object-like Macros") 
    GenUtils.gen_break_line(GenSourceFile)
    # Generate header contents
    GenUtils.gen_comment_block(GenHeaderFile, "2. Object-like Macros") 
    GenUtils.gen_break_line(GenHeaderFile)
    
def gen_section_3_function_macro():
    # Generate source contents
    GenUtils.gen_comment_block(GenSourceFile, "3. Function-like Macros") 
    GenUtils.gen_break_line(GenSourceFile)
    # Generate header contents
    GenUtils.gen_comment_block(GenHeaderFile, "3. Function-like Macros") 
    GenUtils.gen_break_line(GenHeaderFile)
    
def gen_section_4_typedef():
    # Generate source contents
    GenUtils.gen_comment_block(GenSourceFile, "4. Typedefs: Enumerations, Structures, Pointers, Others") 
    GenUtils.gen_break_line(GenSourceFile)
    # Generate header contents
    GenUtils.gen_comment_block(GenHeaderFile, "4. Typedefs: Enumerations, Structures, Pointers, Others") 
    GenUtils.gen_break_line(GenHeaderFile)

def gen_section_5_variable(fileType):
    if "SourceFile" == fileType:
        GenUtils.gen_comment_block(GenSourceFile, "5. Global, Static and Extern Variables")
        noTestcase = len(XlsProcessing.testSuite.testcases)
        GenUtils.gen_comment_line(GenSourceFile, "List of all test cases")
        with GenUtils.sourceFile.block("void (*TestcaseList_array[" + str(noTestcase) + \
        "])(void) = ", ";"):
            counter = 1
            for testcase in XlsProcessing.testSuite.testcases:
                if counter < noTestcase:
                    GenUtils.sourceFile(testcase.testcase_name + ",")           
                else:
                    GenUtils.sourceFile(testcase.testcase_name)
                counter += 1
        GenUtils.gen_break_line(GenSourceFile)
    if "HeaderFile" == fileType:
        GenUtils.gen_comment_block(GenHeaderFile, "5. Global, Static and Extern Variables")
        GenUtils.gen_break_line(GenHeaderFile)
        
def gen_section_6_function_definition(fileType):
    if "SourceFile" == fileType:
        GenUtils.gen_comment_block(GenSourceFile, "6. Function Definitions")
        # Generate blocks of testcases
        for testcase in XlsProcessing.testSuite.testcases:
            testcase_prototype = "void " + testcase.testcase_name + "(void)"
            with GenUtils.sourceFile.block(testcase_prototype):
                init_output_var(testcase)    
                init_param(testcase)
                call_funct_preconditon(testcase)
                call_test_method(testcase)    
                compare(testcase)      
            GenUtils.gen_break_line(GenSourceFile)
    if "HeaderFile" == fileType:
        GenUtils.gen_comment_block(GenHeaderFile, "6. Function Prototypes")
        gen_externC_beginning()
        for testcase in XlsProcessing.testSuite.testcases:
            GenUtils.headerFile("void " + testcase.testcase_name + "(void);")
        GenUtils.gen_break_line(GenHeaderFile)
        gen_externC_ending()
        
def gen_ending_header():
    # Generate source contents
    GenUtils.sourceFile("#endif /* UNIT_TESTING */")
    GenUtils.gen_break_line(GenSourceFile)
    GenUtils.sourceFile("/** End of File ***************************************************************/")
    GenUtils.gen_break_line(GenSourceFile)
    # Generate header contents
    GenUtils.headerFile("#endif /* " + Config.headerIncludingGuard + " */")
    GenUtils.gen_break_line(GenHeaderFile)
    GenUtils.headerFile("/** End of File ***************************************************************/")
    GenUtils.gen_break_line(GenHeaderFile)
    
################################################################################
# 5. Main processing: File generating
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
GenUtils.sourceFile.close()
GenUtils.headerFile.close()