################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/SideTasks/flash_task.c \
../Core/SideTasks/task_blink.c \
../Core/SideTasks/task_temp.c 

OBJS += \
./Core/SideTasks/flash_task.o \
./Core/SideTasks/task_blink.o \
./Core/SideTasks/task_temp.o 

C_DEPS += \
./Core/SideTasks/flash_task.d \
./Core/SideTasks/task_blink.d \
./Core/SideTasks/task_temp.d 


# Each subdirectory must supply rules for building sources it contributes
Core/SideTasks/%.o Core/SideTasks/%.su Core/SideTasks/%.cyclo: ../Core/SideTasks/%.c Core/SideTasks/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/App -I../Core/flash_SPI -I../Core/GPIOHandle -I../Core/SideTasks -I../Core/USBHandle -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-SideTasks

clean-Core-2f-SideTasks:
	-$(RM) ./Core/SideTasks/flash_task.cyclo ./Core/SideTasks/flash_task.d ./Core/SideTasks/flash_task.o ./Core/SideTasks/flash_task.su ./Core/SideTasks/task_blink.cyclo ./Core/SideTasks/task_blink.d ./Core/SideTasks/task_blink.o ./Core/SideTasks/task_blink.su ./Core/SideTasks/task_temp.cyclo ./Core/SideTasks/task_temp.d ./Core/SideTasks/task_temp.o ./Core/SideTasks/task_temp.su

.PHONY: clean-Core-2f-SideTasks

