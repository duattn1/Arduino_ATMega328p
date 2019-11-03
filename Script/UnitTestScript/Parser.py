class Enum:
    enum_name = ""
    enum_constant = []
    
    def __init__(self, enum_name, enum_constant):
        self.enum_name = str(enum_name)
        self.enum_constant = str(enum_constant)
########################################################333
# Open the header file
f = open("header.h", "r")
# read all header file contents
contents = f.read()
contents_length = len(contents)

# Declare searched index variable
enum_start_index = 0
enum_end_index = 0
enums_index = 0



enums = [None]*3

#temp
counter = 3

# Look for enum keyword on the entire header file contents
while enum_start_index < contents_length:
    enum_start_index = contents.find("typedef enum", enum_end_index)

    # exit while loop when the enum keyword is not found
    if -1 == enum_start_index:
        break
    enum_end_index = contents.find(";", enum_start_index)
    enum_contents = contents[enum_start_index:enum_end_index]

    # debug
    #print(enum_contents)

    # Look for enum contants from a enum defintion
    enum_constant_start_index = 0
    enum_constant_end_index = 0
    while enum_constant_start_index < len(enum_contents):
        enum_constant_start_index = enum_contents.find("{", enum_constant_end_index)
        # exit while loop when the enum keyword is not found
        if -1 == enum_constant_start_index:
            break
        enum_constant_end_index = enum_contents.find(",", enum_constant_start_index)
        enum_constant_contents = enum_contents[enum_constant_start_index+1:enum_constant_end_index]
        print(enum_constant_contents.strip())

    #enums[enums_index] = Enum(enum_name, 1)


print("---------------------------")
#print(enums[0].enum_name)
##############################################################################
# Close the header file
f.close()