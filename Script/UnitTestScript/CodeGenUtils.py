################################################################################
# 1. Including files
################################################################################
from CodeGen import *
import shutil               # This module is for file copying

################################################################################
# 2. Class definition
################################################################################

################################################################################
# 3. Function definition
################################################################################
def gen_comment_line(fileType, comment):
    content = "// " + comment
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

def gen_function_call_no_arg(fileType, func_name):
    content = func_name + "();"
    if "SourceFile" == fileType:
        sourceFile(content)
    if "HeaderFile" == fileType:
        headerFile(content)
    
def gen_function_call_with_arg(fileType, func_name, params):   
    content = func_name + "("
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
 
############################################################################### 
# Create the generated file
headerFile = CppFile("ut_usart_driver.h")
sourceFile = CppFile("ut_usart_driver.c")
