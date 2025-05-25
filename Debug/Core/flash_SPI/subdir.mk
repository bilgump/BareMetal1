################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/flash_SPI/flash_w25q16.c 

OBJS += \
./Core/flash_SPI/flash_w25q16.o 

C_DEPS += \
./Core/flash_SPI/flash_w25q16.d 


# Each subdirectory must supply rules for building sources it contributes
Core/flash_SPI/%.o Core/flash_SPI/%.su Core/flash_SPI/%.cyclo: ../Core/flash_SPI/%.c Core/flash_SPI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/App -I../Core/flash_SPI -I../Core/GPIOHandle -I../Core/SideTasks -I../Core/USBHandle -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-flash_SPI

clean-Core-2f-flash_SPI:
	-$(RM) ./Core/flash_SPI/flash_w25q16.cyclo ./Core/flash_SPI/flash_w25q16.d ./Core/flash_SPI/flash_w25q16.o ./Core/flash_SPI/flash_w25q16.su

.PHONY: clean-Core-2f-flash_SPI

