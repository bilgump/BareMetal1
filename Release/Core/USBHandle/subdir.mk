################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/USBHandle/USBPrints.c 

OBJS += \
./Core/USBHandle/USBPrints.o 

C_DEPS += \
./Core/USBHandle/USBPrints.d 


# Each subdirectory must supply rules for building sources it contributes
Core/USBHandle/%.o Core/USBHandle/%.su Core/USBHandle/%.cyclo: ../Core/USBHandle/%.c Core/USBHandle/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-USBHandle

clean-Core-2f-USBHandle:
	-$(RM) ./Core/USBHandle/USBPrints.cyclo ./Core/USBHandle/USBPrints.d ./Core/USBHandle/USBPrints.o ./Core/USBHandle/USBPrints.su

.PHONY: clean-Core-2f-USBHandle

