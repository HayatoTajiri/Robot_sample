################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include mbed/TARGET_NUCLEO_F446RE/TOOLCHAIN_GCC_ARM/subdir.mk
-include Ping/subdir.mk
-include Motor/subdir.mk
-include Linesensor/subdir.mk
-include Ballsensor/subdir.mk
-include BNO055_fusion/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: pre-build main-build

# Main-build Target
main-build: Robot_sample-debug.elf

# Tool invocations
Robot_sample-debug.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU G++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -L"C:\Users\g031q\workspace\Robot_sample\mbed\TARGET_NUCLEO_F446RE\TOOLCHAIN_GCC_ARM" -Wl,--wrap=main -Wl,--wrap=_memalign_r -Wl,--wrap=exit -Wl,--wrap=atexit -DMBED_DEBUG -DMBED_TRAP_ERRORS_ENABLED=1 -Wl,-n -Wl,--start-group -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys -Wl,--end-group -T"C:/Users/g031q/workspace/Robot_sample/Debug/linker-script-debug.ld" -Wl,-Map=output.map -Wl,--gc-sections -fno-exceptions -fno-rtti -o "Robot_sample-debug.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

pre-build:
	-@echo 'Creating makefile.defs:'
	-echo "export PREPROC_CMD = C:\Ac6\SystemWorkbench\plugins\fr.ac6.mcu.externaltools.arm-none.win32_1.16.0.201807130628\tools\compiler\bin/arm-none-eabi-cpp -E -P" > C:/Users/g031q/workspace/Robot_sample/makefile.defs
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "Robot_sample-debug.elf" "Robot_sample.bin"
	arm-none-eabi-size -B "Robot_sample-debug.elf"
	make ldclean
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: main-build pre-build post-build

-include ../makefile.targets
