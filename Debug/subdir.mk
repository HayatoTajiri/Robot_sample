################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../main.cpp 

OBJS += \
./main.o 

CPP_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 '-D__MBED__=1' '-DDEVICE_I2CSLAVE=1' -DTARGET_LIKE_MBED '-DDEVICE_PORTOUT=1' '-DMBED_BUILD_TIMESTAMP=1542112513.75' '-DDEVICE_PORTINOUT=1' -DTARGET_RTOS_M4_M7 '-DDEVICE_LOWPOWERTIMER=1' '-DDEVICE_RTC=1' '-DDEVICE_SERIAL_ASYNCH=1' -DTARGET_STM32F4 -D__CMSIS_RTOS '-D__FPU_PRESENT=1' -DTARGET_STM32F446xE -DTOOLCHAIN_GCC '-DDEVICE_CAN=1' -DTARGET_CORTEX_M '-DDEVICE_I2C_ASYNCH=1' -DTARGET_LIKE_CORTEX_M4 '-DDEVICE_ANALOGOUT=1' -DTARGET_M4 '-DDEVICE_SPI_ASYNCH=1' '-DDEVICE_PWMOUT=1' '-DDEVICE_INTERRUPTIN=1' -DTARGET_CORTEX '-DDEVICE_I2C=1' '-DTRANSACTION_QUEUE_SIZE_SPI=2' -D__CORTEX_M4 '-DDEVICE_STDIO_MESSAGES=1' -DTARGET_FF_MORPHO -DTARGET_FAMILY_STM32 -DTARGET_FF_ARDUINO -DTARGET_STM32F446RE -DTARGET_RELEASE -DTARGET_STM -DUSBHOST_OTHER -D__MBED_CMSIS_RTOS_CM '-DDEVICE_SLEEP=1' -DTOOLCHAIN_GCC_ARM '-DDEVICE_SPI=1' -DUSB_STM_HAL -DTARGET_NUCLEO_F446RE '-DDEVICE_SPISLAVE=1' '-DDEVICE_ANALOGIN=1' '-DDEVICE_SERIAL=1' '-DDEVICE_FLASH=1' '-DDEVICE_PORTIN=1' -DARM_MATH_CM4 '-DDEVICE_SERIAL_FC=1' -DMBED_DEBUG '-DMBED_TRAP_ERRORS_ENABLED=1' -DMBED_DEBUG '-DMBED_TRAP_ERRORS_ENABLED=1' -DNDEBUG -DNDEBUG -I"C:/Users/g031q/workspace/Robot_sample" -I"C:/Users/g031q/workspace/Robot_sample/BNO055_fusion" -I"C:/Users/g031q/workspace/Robot_sample/Ballsensor" -I"C:/Users/g031q/workspace/Robot_sample/Linesensor" -I"C:/Users/g031q/workspace/Robot_sample/Motor" -I"C:/Users/g031q/workspace/Robot_sample/Ping" -I"C:/Users/g031q/workspace/Robot_sample/mbed" -I"C:/Users/g031q/workspace/Robot_sample/mbed/TARGET_NUCLEO_F446RE" -I"C:/Users/g031q/workspace/Robot_sample/mbed/TARGET_NUCLEO_F446RE/TARGET_STM" -I"C:/Users/g031q/workspace/Robot_sample/mbed/TARGET_NUCLEO_F446RE/TARGET_STM/TARGET_STM32F4" -I"C:/Users/g031q/workspace/Robot_sample/mbed/TARGET_NUCLEO_F446RE/TARGET_STM/TARGET_STM32F4/TARGET_STM32F446xE" -I"C:/Users/g031q/workspace/Robot_sample/mbed/TARGET_NUCLEO_F446RE/TARGET_STM/TARGET_STM32F4/TARGET_STM32F446xE/TARGET_NUCLEO_F446RE" -I"C:/Users/g031q/workspace/Robot_sample/mbed/TARGET_NUCLEO_F446RE/TARGET_STM/TARGET_STM32F4/TARGET_STM32F446xE/device" -I"C:/Users/g031q/workspace/Robot_sample/mbed/TARGET_NUCLEO_F446RE/TARGET_STM/TARGET_STM32F4/device" -I"C:/Users/g031q/workspace/Robot_sample/mbed/drivers" -I"C:/Users/g031q/workspace/Robot_sample/mbed/hal" -I"C:/Users/g031q/workspace/Robot_sample/mbed/platform"  -includeC:/Users/g031q/workspace/Robot_sample/mbed_config.h -O0 -funsigned-char -fno-delete-null-pointer-checks -fomit-frame-pointer -fmessage-length=0 -fno-builtin -g3 -Wall -Wextra -Wvla -Wno-unused-parameter -Wno-missing-field-initializers -ffunction-sections -fdata-sections -c -fno-exceptions -fno-rtti -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


