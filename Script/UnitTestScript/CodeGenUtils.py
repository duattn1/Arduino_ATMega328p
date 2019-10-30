################################################################################
# 1. Including files
################################################################################
import CodeGen as CodeGen
import Configuration as Config  # This module is the global configuration


################################################################################
# 2. Global Variables
################################################################################


################################################################################
# 3. Class definition
################################################################################


################################################################################
# 4. Function definition
################################################################################
def gen_comment_line(file_type, comment):
    content = "/* " + comment + " */"
    if "SourceFile" == file_type:
        source_file(content)
    if "HeaderFile" == file_type:
        header_file(content)

def gen_comment_block(file_type, section_name):
    content = " * " + section_name
    if "SourceFile" == file_type:
        source_file("/*******************************************************************************")
        source_file(content)
        source_file(" ******************************************************************************/")
    if "HeaderFile" == file_type:
        header_file("/*******************************************************************************")
        header_file(content)
        header_file(" ******************************************************************************/")

def gen_var_declaration(file_type, var_type, var_name):
    content = var_type + " " + var_name + ";" 
    if "SourceFile" == file_type:
        source_file(content)
    if "HeaderFile" == file_type:
        header_file(content)

def gen_var_definition(file_type, var_type, var_name, init_value):
    content = var_type + " " + var_name + " = " + init_value + ";" 
    if "SourceFile" == file_type:
        source_file(content)
    if "HeaderFile" == file_type:
        header_file(content)

def gen_var_assignment(file_type, var_name, assign_operator, value):
    content = var_name + " " + assign_operator + " " + value + ";"
    if "SourceFile" == file_type:
        source_file(content)
    if "HeaderFile" == file_type:
        header_file(content)

def gen_function_call_no_arg(file_Type, func_name, result_var, type_cast):
    content = ""
    if "" != result_var:
        content += result_var + " = "

    content += type_cast + func_name + "();"        
    if "SourceFile" == file_Type:
        source_file(content)
    if "HeaderFile" == file_Type:
        header_file(content)
    
def gen_function_call_with_arg(file_type, func_name, result_var, type_cast, params): 
    content = ""
    if "" != result_var:
        content += result_var + " = "

    content += type_cast + func_name + "("
        
    first = True
    for param in params:
        if first:
            first = False
            content += param
        else:
            content += ", " + param
    content += ");"
    if "SourceFile" == file_type:
        source_file(content)
    if "HeaderFile" == file_type:
        header_file(content)

def gen_break_line(fileType):
    content = ""
    if "SourceFile" == fileType:
        source_file(content)
    if "HeaderFile" == fileType:
        header_file(content)
 
################################################################################
# 5. Main processing: Create the generated file
################################################################################ 
header_file = CodeGen.CppFile(Config.generated_header_file_name)
source_file = CodeGen.CppFile(Config.generated_source_file_name)
