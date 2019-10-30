################################################################################
# 1. Including files
################################################################################
import xlrd
import Configuration as Config # This module is the global configuration


################################################################################
# 2. Global Variables
################################################################################


################################################################################
# 3. Class definition
################################################################################
class testSuiteCollection:
    test_suite_name = ""
    testcases = []
    
    def __init__(self, test_suite_name):
        self.test_suite_name = str(test_suite_name)

class testcaseCollection:
    function_name = ""
    testcase_name = ""
    invoked_func_precondition = ""
    params = []
    return_objs = []
    global_vars = []
    
    def __init__(self, function_name, testcase_name):
        self.function_name = str(function_name)
        self.testcase_name = str(testcase_name)

class paramCollection:
    gen_name = ""
    type = ""
    param_name = ""
    init_value = ""
    isStructType = "False"
    def __init__(self, gen_name, type, param_name, init_value, isStructType):
        self.gen_name = str(gen_name)
        self.type = str(type)
        self.param_name = str(param_name)
        self.init_value = str(init_value)
        self.isStructType = str(isStructType)

class returnObjCollection:
    gen_name = ""
    type = ""
    expected_value = ""
    isPointer = "False"
    def __init__(self, gen_name, type, expected_value, isPointer):
        self.gen_name = str(gen_name)
        self.type = str(type)
        self.expected_value = str(expected_value)
        self.isPointer = str(isPointer)
        
class globalVarCollection:
    gen_name = ""
    type = ""
    expected = ""
    actual_mem = ""
    mask = ""
    def __init__(self, gen_name, type, expected, actual_mem, mask):
        self.gen_name = str(gen_name)
        self.type = str(type)
        self.expected = str(expected)
        self.actual_mem = str(actual_mem)
        self.mask = str(mask)
        

################################################################################
# 4. Function definition
################################################################################
def find_output_position(firstParamColumn):
    output_position = firstParamColumn # assume that there is no INPUT data, 
    # and OUTPUT data begins at first param column.
    for i in range(sheet.ncols):
        if "Output" == sheet.cell_value(2, i):
            output_position = i
    return output_position

def isStructure(type):
    result = "True"

    # check if "type" param has the "Struct_" prefix
    try:        
        type.index("Struct_")
    except ValueError:
        result = "False"
            
    return result
    
def isPointer(type):
    result = "True"

    # check if "type" param has the "*" character
    try:        
        type.index("*")
    except ValueError:
        result = "False"
            
    return result
    
    
################################################################################
# 5. Main processing: XLS file parsing
################################################################################

testSuite = testSuiteCollection(Config.testSuiteName)

# Open XLS file
wb = xlrd.open_workbook(Config.testSuiteExcelFile) 
for tcSheet in Config.testcaseSheetList:
    # Open a sheet
    sheet = wb.sheet_by_index(tcSheet)
    
    noRows = sheet.nrows
    noCols = sheet.ncols
    func_name = sheet.cell_value(0, 1)
    output_position = find_output_position(Config.firstParamColumn)
    
    for i in range(Config.tcFirstLine, noRows):
        testcase_name = sheet.cell_value(i, Config.tcNameColumn)
        testcase_invoked_func = sheet.cell_value(i, Config.tcInvokedFuncColumn)
        
        # Count all parameters
        noParams = (output_position - Config.firstParamColumn) // 2 # division with result of integer number
        
        # Count all return object
        noReturnObjs = 0
        firstOutputObject = sheet.cell_value(Config.tcFirstLine - 2, output_position)
        if "Return" == firstOutputObject:
            noReturnObjs = 1
            
        # Count all global variables
        noOutputObjects = (noCols - output_position) // 2 # division with result of integer number    
        noGlobalVars = noOutputObjects - noReturnObjs

        testcase = testcaseCollection(func_name, testcase_name)
        testcase.invoked_func_precondition = testcase_invoked_func
        testcase.params = [None]*noParams
        testcase.return_objs = [None]*noReturnObjs
        testcase.global_vars = [None]*noGlobalVars
        
        # Collect all parameters
        index = 0
        for j in range(Config.firstParamColumn, output_position, 2): 
            gen_name = "param_" + str(index + 1)
            type = sheet.cell_value(Config.ioTypeRow, j) # unchanged
            param_name = sheet.cell_value(Config.ioNameRow, j) # unchanged
            init_value = sheet.cell_value(i, j)        
            isStructType = isStructure(type)            
            testcase.params[index] = \
            paramCollection(gen_name, type, param_name, init_value, isStructType)
            
            index += 1        
            
        # Collect all global variables
        index = 0
        for j in range(output_position, noCols - 1, 2): 
            currentOutputObject = sheet.cell_value(Config.ioNameRow, j)
            if "Return" == currentOutputObject:
                gen_name = "return_obj"
                type = sheet.cell_value(Config.ioTypeRow, j) # unchanged                
                expected_value = sheet.cell_value(i, j)
                isPtr = isPointer(type)
                testcase.return_objs[0] = \
                returnObjCollection(gen_name, type, expected_value, isPtr)
            else:
                gen_name = "global_var_" + str(index + 1)
                type = sheet.cell_value(Config.ioTypeRow, j) # unchanged
                expected = sheet.cell_value(i, j)
                actual_mem = sheet.cell_value(Config.ioNameRow, j) # unchanged
                mask = sheet.cell_value(i, j + 1)
                testcase.global_vars[index] = \
                globalVarCollection(gen_name, type, expected, actual_mem, mask)
                            
                index += 1
        
        testSuite.testcases.append(testcase)
