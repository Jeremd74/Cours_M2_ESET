################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/portable/MemMang/heap_4.c 

OBJS += \
./ThirdParty/portable/MemMang/heap_4.o 

C_DEPS += \
./ThirdParty/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/portable/MemMang/%.o ThirdParty/portable/MemMang/%.su ThirdParty/portable/MemMang/%.cyclo: ../ThirdParty/portable/MemMang/%.c ThirdParty/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -c -I../Inc -I"C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS903_RTOS/STM32F446_FromScratch/Drivers" -I"C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS903_RTOS/STM32F446_FromScratch/Src" -I"C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS903_RTOS/STM32F446_FromScratch/Drivers/CMSIS/Device/ST/STM32F4xx" -I"C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS903_RTOS/STM32F446_FromScratch/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS903_RTOS/STM32F446_FromScratch/Drivers/CMSIS/Include" -I"C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS903_RTOS/STM32F446_FromScratch/ThirdParty" -I"C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS903_RTOS/STM32F446_FromScratch/ThirdParty/include" -I"C:/Users/Jerem/Documents/GitHub/Cours_M2_ESET/ETRS903_RTOS/STM32F446_FromScratch/ThirdParty/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-portable-2f-MemMang

clean-ThirdParty-2f-portable-2f-MemMang:
	-$(RM) ./ThirdParty/portable/MemMang/heap_4.cyclo ./ThirdParty/portable/MemMang/heap_4.d ./ThirdParty/portable/MemMang/heap_4.o ./ThirdParty/portable/MemMang/heap_4.su

.PHONY: clean-ThirdParty-2f-portable-2f-MemMang

