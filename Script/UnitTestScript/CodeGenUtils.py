################################################################################
# 1. Including files
################################################################################
from CodeGen import *
from Configuration import * # This module is the global configuration
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

def gen_function_call_no_arg(fileType, func_name, noOfReturnObj):
    if 0 == noOfReturnObj:
        content = func_name + "();"
    else:
        content = "return_obj = " + func_name + "();"
        
    if "SourceFile" == fileType:
        sourceFile(content)
    if "HeaderFile" == fileType:
        headerFile(content)
    
def gen_function_call_with_arg(fileType, func_name, params, noOfReturnObj): 
    if 0 == noOfReturnObj:
        content = func_name + "("
    else:
        content = "return_obj = " + func_name + "("
        
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
headerFile = CppFile(generatedHeaderFileName)
sourceFile = CppFile(generatedSourceFileName)
