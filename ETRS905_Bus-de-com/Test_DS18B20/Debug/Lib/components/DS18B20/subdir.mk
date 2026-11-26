################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS905P1_Bus-de-com/Lib/components/DS18B20/ds18b20.c 

OBJS += \
./Lib/components/DS18B20/ds18b20.o 

C_DEPS += \
./Lib/components/DS18B20/ds18b20.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/components/DS18B20/ds18b20.o: C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS905P1_Bus-de-com/Lib/components/DS18B20/ds18b20.c Lib/components/DS18B20/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32F4xx-Nucleo -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS905P1_Bus-de-com/Lib/low_level/GPIO" -I"C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS905P1_Bus-de-com/Lib/low_level/TIMER" -I"C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS905P1_Bus-de-com/Lib/protocols/ONEWIRE" -I"C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS905P1_Bus-de-com/Lib/components/DS18B20" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-components-2f-DS18B20

clean-Lib-2f-components-2f-DS18B20:
	-$(RM) ./Lib/components/DS18B20/ds18b20.cyclo ./Lib/components/DS18B20/ds18b20.d ./Lib/components/DS18B20/ds18b20.o ./Lib/components/DS18B20/ds18b20.su

.PHONY: clean-Lib-2f-components-2f-DS18B20

