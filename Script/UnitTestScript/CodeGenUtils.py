################################################################################
# 1. Including files
################################################################################
import CodeGen as CodeGen
import Configuration as Config  # This module is the global configuration
import shutil               # This module is for file copying


################################################################################
# 2. Global Variables
################################################################################


################################################################################
# 3. Class definition
################################################################################


################################################################################
# 4. Function definition
################################################################################
def gen_comment_line(fileType, comment):
    content = "/* " + comment + " */"
    if "SourceFile" == fileType:
        sourceFile(content)
    if "HeaderFile" == fileType:
        headerFile(content)

def gen_comment_block(fileType, section_name):
    content = " * " + section_name
    if "SourceFile" == fileType:
        sourceFile("/*******************************************************************************")
        sourceFile(content)
        sourceFile(" ******************************************************************************/")
    if "HeaderFile" == fileType:
        headerFile("/*******************************************************************************")
        headerFile(content)
        headerFile(" ******************************************************************************/")

def gen_var_declaration(fileType, var_type, var_name):
    content = var_type + " " + var_name + ";" 
    if "SourceFile" == fileType:
        sourceFile(content)
    if "HeaderFile" == fileType:
        headerFile(content)

def gen_var_definition(fileType, var_type, var_name, init_value):
    content = var_type + " " + var_name + " = " + init_value + ";" 
    if "SourceFile" == fileType:
        sourceFile(content)
    if "HeaderFile" == fileType:
        headerFile(content)

def gen_var_assignment(fileType, var_name, assign_operator, value):
    content = var_name + " " + assign_operator + " " + value + ";"
    if "SourceFile" == fileType:
        sourceFile(content)
    if "HeaderFile" == fileType:
        headerFile(content)

def gen_function_call_no_arg(fileType, func_name, result_var, type_cast):
    content = ""
    if "" != result_var:
        content += result_var + " = "

    content += type_cast + func_name + "();"        
    if "SourceFile" == fileType:
        sourceFile(content)
    if "HeaderFile" == fileType:
        headerFile(content)
    
def gen_function_call_with_arg(fileType, func_name, result_var, type_cast, params): 
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
    if "SourceFile" == fileType:
        sourceFile(content)
    if "HeaderFile" == fileType:
        headerFile(content)

def gen_break_line(fileType):
    content = ""
    if "SourceFile" == fileType:
        sourceFile(content)
    if "HeaderFile" == fileType:
        headerFile(content)
 
################################################################################
# 5. Main processing: Create the generated file
################################################################################ 
headerFile = CodeGen.CppFile(Config.generatedHeaderFileName)
sourceFile = CodeGen.CppFile(Config.generatedSourceFileName)
