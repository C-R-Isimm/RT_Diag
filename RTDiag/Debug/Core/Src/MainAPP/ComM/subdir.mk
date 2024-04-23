################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/MainAPP/ComM/ComM.c 

OBJS += \
./Core/Src/MainAPP/ComM/ComM.o 

C_DEPS += \
./Core/Src/MainAPP/ComM/ComM.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/MainAPP/ComM/%.o Core/Src/MainAPP/ComM/%.su Core/Src/MainAPP/ComM/%.cyclo: ../Core/Src/MainAPP/ComM/%.c Core/Src/MainAPP/ComM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-MainAPP-2f-ComM

clean-Core-2f-Src-2f-MainAPP-2f-ComM:
	-$(RM) ./Core/Src/MainAPP/ComM/ComM.cyclo ./Core/Src/MainAPP/ComM/ComM.d ./Core/Src/MainAPP/ComM/ComM.o ./Core/Src/MainAPP/ComM/ComM.su

.PHONY: clean-Core-2f-Src-2f-MainAPP-2f-ComM

