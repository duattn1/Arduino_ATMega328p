################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../app/include \
../app/source \
../hal \
../hal/include \
../hal/source \
../app \
../kits \
../kits/include \
../kits/source


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../app/source/main.c \
../app/source/sample.c \
../hal/source/boards.c \
../hal/source/gpio_hal.c \
../hal/source/misc.c \
../hal/source/spi_hal.c \
../hal/source/usart_hal.c \
../kits/source/ledMatrix_Max7219.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
app/source/main.o \
app/source/sample.o \
hal/source/boards.o \
hal/source/gpio_hal.o \
hal/source/misc.o \
hal/source/spi_hal.o \
hal/source/usart_hal.o \
kits/source/ledMatrix_Max7219.o


OBJS_AS_ARGS +=  \
app/source/main.o \
app/source/sample.o \
hal/source/boards.o \
hal/source/gpio_hal.o \
hal/source/misc.o \
hal/source/spi_hal.o \
hal/source/usart_hal.o \
kits/source/ledMatrix_Max7219.o


C_DEPS +=  \
app/source/main.d \
app/source/sample.d \
hal/source/boards.d \
hal/source/gpio_hal.d \
hal/source/misc.d \
hal/source/spi_hal.d \
hal/source/usart_hal.d \
kits/source/ledMatrix_Max7219.d


C_DEPS_AS_ARGS +=  \
app/source/main.d \
app/source/sample.d \
hal/source/boards.d \
hal/source/gpio_hal.d \
hal/source/misc.d \
hal/source/spi_hal.d \
hal/source/usart_hal.d \
kits/source/ledMatrix_Max7219.d


OUTPUT_FILE_PATH +=XArduino.elf

OUTPUT_FILE_PATH_AS_ARGS +=XArduino.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

# AVR32/GNU C Compiler

















app/source/%.o: ../app/source/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : (AVR_8_bit_GNU_Toolchain_3.4.1_830) 4.6.2
	$(QUOTE)C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DARDUINO_NANO  -I"../hal/include" -I"../app/include" -I"../kits/include"  -O1 -fpack-struct -fshort-enums -g2 -Wall -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -mmcu=atmega328p   -o"$@" "$<" 
	@echo Finished building: $<

hal/source/%.o: ../hal/source/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : (AVR_8_bit_GNU_Toolchain_3.4.1_830) 4.6.2
	$(QUOTE)C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DARDUINO_NANO  -I"../hal/include" -I"../app/include" -I"../kits/include"  -O1 -fpack-struct -fshort-enums -g2 -Wall -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -mmcu=atmega328p   -o"$@" "$<" 
	@echo Finished building: $<

kits/source/%.o: ../kits/source/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : (AVR_8_bit_GNU_Toolchain_3.4.1_830) 4.6.2
	$(QUOTE)C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DARDUINO_NANO  -I"../hal/include" -I"../app/include" -I"../kits/include"  -O1 -fpack-struct -fshort-enums -g2 -Wall -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -mmcu=atmega328p   -o"$@" "$<" 
	@echo Finished building: $<



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : (AVR_8_bit_GNU_Toolchain_3.4.1_830) 4.6.2
	$(QUOTE)C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="XArduino.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group  -mmcu=atmega328p  
	@echo Finished building target: $@
	"C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "XArduino.elf" "XArduino.hex"
	"C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "XArduino.elf" "XArduino.eep" || exit 0
	"C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objdump.exe" -h -S "XArduino.elf" > "XArduino.lss"
	"C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "XArduino.elf" "XArduino.srec"
	"C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-size.exe" "XArduino.elf"
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS)$(C_DEPS_AS_ARGS) $(EXECUTABLES) 
	rm -rf "XArduino.elf" "XArduino.a" "XArduino.hex" "XArduino.lss" "XArduino.eep" "XArduino.map" "XArduino.srec"
	