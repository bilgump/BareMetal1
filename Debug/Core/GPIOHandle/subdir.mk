################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GPIOHandle/LEDManager.c \
../Core/GPIOHandle/buttonFSM.c 

OBJS += \
./Core/GPIOHandle/LEDManager.o \
./Core/GPIOHandle/buttonFSM.o 

C_DEPS += \
./Core/GPIOHandle/LEDManager.d \
./Core/GPIOHandle/buttonFSM.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GPIOHandle/%.o Core/GPIOHandle/%.su Core/GPIOHandle/%.cyclo: ../Core/GPIOHandle/%.c Core/GPIOHandle/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/App -I../Core/GPIOHandle -I../Core/SideTasks -I../Core/USBHandle -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-GPIOHandle

clean-Core-2f-GPIOHandle:
	-$(RM) ./Core/GPIOHandle/LEDManager.cyclo ./Core/GPIOHandle/LEDManager.d ./Core/GPIOHandle/LEDManager.o ./Core/GPIOHandle/LEDManager.su ./Core/GPIOHandle/buttonFSM.cyclo ./Core/GPIOHandle/buttonFSM.d ./Core/GPIOHandle/buttonFSM.o ./Core/GPIOHandle/buttonFSM.su

.PHONY: clean-Core-2f-GPIOHandle

