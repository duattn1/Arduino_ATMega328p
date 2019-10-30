################################################################################
# 1. Including files
################################################################################


################################################################################
# 2. Global Variables
################################################################################

# Test case Excel file global names
testSuiteExcelFile = ("C:\\Users\\PC\\Documents\\GitHub\\Arduino_ATMega328p\\UT_TestSuite.xls") 
testcaseSheetList = [1, 2, 3, 4]
firstParamColumn = 3
tcFirstLine = 5
tcNameColumn = 0
tcInvokedFuncColumn = 1
ioTypeRow = 4
ioNameRow = 3

testedFile = "gpio_hal"

testedHeaderFile = testedFile + ".h"
generatedHeaderFileName = "ut_" + testedFile + ".h"
generatedSourceFileName = "ut_" + testedFile + ".c"

testSuiteName = "ut_" + testedFile
testTarget = "GPIO driver"
headerIncludingGuard = "_UT_GPIO_HAL_H"

systemRegisterSize = 8 # Arduino is a 8-bit MCU 
################################################################################
# 3. Class definition
################################################################################


################################################################################
# 4. Function definition
################################################################################

    
################################################################################
# 5. Main processing
################################################################################
