################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/MainAPP/EHM/EHM.c 

OBJS += \
./Core/Src/MainAPP/EHM/EHM.o 

C_DEPS += \
./Core/Src/MainAPP/EHM/EHM.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/MainAPP/EHM/%.o Core/Src/MainAPP/EHM/%.su Core/Src/MainAPP/EHM/%.cyclo: ../Core/Src/MainAPP/EHM/%.c Core/Src/MainAPP/EHM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-MainAPP-2f-EHM

clean-Core-2f-Src-2f-MainAPP-2f-EHM:
	-$(RM) ./Core/Src/MainAPP/EHM/EHM.cyclo ./Core/Src/MainAPP/EHM/EHM.d ./Core/Src/MainAPP/EHM/EHM.o ./Core/Src/MainAPP/EHM/EHM.su

.PHONY: clean-Core-2f-Src-2f-MainAPP-2f-EHM

