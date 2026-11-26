################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS905P1_Bus-de-com/Lib/protocols/SPI/spi.c 

OBJS += \
./Lib/protocols/SPI/spi.o 

C_DEPS += \
./Lib/protocols/SPI/spi.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/protocols/SPI/spi.o: C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS905P1_Bus-de-com/Lib/protocols/SPI/spi.c Lib/protocols/SPI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32F4xx-Nucleo -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-protocols-2f-SPI

clean-Lib-2f-protocols-2f-SPI:
	-$(RM) ./Lib/protocols/SPI/spi.cyclo ./Lib/protocols/SPI/spi.d ./Lib/protocols/SPI/spi.o ./Lib/protocols/SPI/spi.su

.PHONY: clean-Lib-2f-protocols-2f-SPI

