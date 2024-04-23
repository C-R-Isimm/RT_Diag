################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/MainAPP/MainAPP.c 

OBJS += \
./Core/Src/MainAPP/MainAPP.o 

C_DEPS += \
./Core/Src/MainAPP/MainAPP.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/MainAPP/%.o Core/Src/MainAPP/%.su Core/Src/MainAPP/%.cyclo: ../Core/Src/MainAPP/%.c Core/Src/MainAPP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-MainAPP

clean-Core-2f-Src-2f-MainAPP:
	-$(RM) ./Core/Src/MainAPP/MainAPP.cyclo ./Core/Src/MainAPP/MainAPP.d ./Core/Src/MainAPP/MainAPP.o ./Core/Src/MainAPP/MainAPP.su

.PHONY: clean-Core-2f-Src-2f-MainAPP

