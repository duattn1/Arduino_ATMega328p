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
class Test_suite_collection:
    test_suite_name = ""
    test_cases = []
    
    def __init__(self, test_suite_name):
        self.test_suite_name = str(test_suite_name)

class Test_case_collection:
    function_name = ""
    testcase_name = ""
    invoked_func_precondition = ""
    params = []
    return_objs = []
    global_vars = []
    
    def __init__(self, function_name, testcase_name):
        self.function_name = str(function_name)
        self.testcase_name = str(testcase_name)

class Param_collection:
    gen_name = ""
    type = ""
    param_name = ""
    init_value = ""
    is_struct_type = "False"
    def __init__(self, gen_name, type, param_name, init_value, is_struct_type):
        self.gen_name = str(gen_name)
        self.type = str(type)
        self.param_name = str(param_name)
        self.init_value = str(init_value)
        self.is_struct_type = str(is_struct_type)

class Return_obj_collection:
    gen_name = ""
    type = ""
    expected_value = ""
    is_pointer = "False"
    def __init__(self, gen_name, type, expected_value, is_pointer):
        self.gen_name = str(gen_name)
        self.type = str(type)
        self.expected_value = str(expected_value)
        self.is_pointer = str(is_pointer)
        
class Global_var_collection:
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
def find_output_position(first_param_column):
    output_position = first_param_column # assume that there is no INPUT data, 
    # and OUTPUT data begins at first param column.
    for i in range(sheet.ncols):
        if "Output" == sheet.cell_value(2, i):
            output_position = i
    return output_position

def is_structure(type):
    result = "True"

    # check if "type" param has the "Struct_" prefix
    try:        
        type.index("Struct_")
    except ValueError:
        result = "False"
            
    return result
    
def is_pointer(type):
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

test_suite = Test_suite_collection(Config.test_suite_name)

# Open XLS file
wb = xlrd.open_workbook(Config.test_suite_excel_file) 
for tcSheet in Config.test_case_sheet_list:
    # Open a sheet
    sheet = wb.sheet_by_index(tcSheet)
    
    noRows = sheet.nrows
    noCols = sheet.ncols
    func_name = sheet.cell_value(0, 1)
    output_position = find_output_position(Config.first_param_column)
    
    for i in range(Config.tc_first_line, noRows):
        testcase_name = sheet.cell_value(i, Config.tc_name_column)
        testcase_invoked_func = sheet.cell_value(i, Config.tc_invoked_func_column)
        
        # Count all parameters
        no_params = (output_position - Config.first_param_column) // 2 # division with result of integer number
        
        # Count all return object
        no_return_objs = 0
        first_output_object = sheet.cell_value(Config.tc_first_line - 2, output_position)
        if "Return" == first_output_object:
            no_return_objs = 1
            
        # Count all global variables
        no_output_objs = (noCols - output_position) // 2 # division with result of integer number    
        no_global_vars = no_output_objs - no_return_objs

        test_case = Test_case_collection(func_name, testcase_name)
        test_case.invoked_func_precondition = testcase_invoked_func
        test_case.params = [None]*no_params
        test_case.return_objs = [None]*no_return_objs
        test_case.global_vars = [None]*no_global_vars
        
        # Collect all parameters
        index = 0
        for j in range(Config.first_param_column, output_position, 2): 
            gen_name = "param_" + str(index + 1)
            type = sheet.cell_value(Config.io_type_row, j) # unchanged
            param_name = sheet.cell_value(Config.io_name_row, j) # unchanged
            init_value = sheet.cell_value(i, j)        
            is_struct_type = is_structure(type)            
            test_case.params[index] = \
            Param_collection(gen_name, type, param_name, init_value, is_struct_type)
            
            index += 1        
            
        # Collect all global variables
        index = 0
        for j in range(output_position, noCols - 1, 2): 
            current_output_object = sheet.cell_value(Config.io_name_row, j)
            if "Return" == current_output_object:
                gen_name = "return_obj"
                type = sheet.cell_value(Config.io_type_row, j) # unchanged                
                expected_value = sheet.cell_value(i, j)
                isPtr = is_pointer(type)
                test_case.return_objs[0] = \
                Return_obj_collection(gen_name, type, expected_value, isPtr)
            else:
                gen_name = "global_var_" + str(index + 1)
                type = sheet.cell_value(Config.io_type_row, j) # unchanged
                expected = sheet.cell_value(i, j)
                actual_mem = sheet.cell_value(Config.io_name_row, j) # unchanged
                mask = sheet.cell_value(i, j + 1)
                test_case.global_vars[index] = \
                Global_var_collection(gen_name, type, expected, actual_mem, mask)
                            
                index += 1
        
        test_suite.test_cases.append(test_case)
