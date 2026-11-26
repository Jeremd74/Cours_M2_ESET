################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/tracealyser/Src/trcKernelPort.c \
../ThirdParty/tracealyser/Src/trcSnapshotRecorder.c \
../ThirdParty/tracealyser/Src/trcStreamingRecorder.c 

OBJS += \
./ThirdParty/tracealyser/Src/trcKernelPort.o \
./ThirdParty/tracealyser/Src/trcSnapshotRecorder.o \
./ThirdParty/tracealyser/Src/trcStreamingRecorder.o 

C_DEPS += \
./ThirdParty/tracealyser/Src/trcKernelPort.d \
./ThirdParty/tracealyser/Src/trcSnapshotRecorder.d \
./ThirdParty/tracealyser/Src/trcStreamingRecorder.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/tracealyser/Src/%.o ThirdParty/tracealyser/Src/%.su ThirdParty/tracealyser/Src/%.cyclo: ../ThirdParty/tracealyser/Src/%.c ThirdParty/tracealyser/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/STM32_Project/STM32F446_Nucleo/FreeRTOS/STM32F446_FromScratch_FreeRTOS_Template/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/STM32_Project/STM32F446_Nucleo/FreeRTOS/STM32F446_FromScratch_FreeRTOS_Template/Drivers/CMSIS/Include" -I"C:/STM32_Project/STM32F446_Nucleo/FreeRTOS/STM32F446_FromScratch_FreeRTOS_Template/ThirdParty/FreeRTOS/Source/include" -I"C:/STM32_Project/STM32F446_Nucleo/FreeRTOS/STM32F446_FromScratch_FreeRTOS_Template/ThirdParty/FreeRTOS/Source/portable" -I"C:/STM32_Project/STM32F446_Nucleo/FreeRTOS/STM32F446_FromScratch_FreeRTOS_Template/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/STM32_Project/STM32F446_Nucleo/FreeRTOS/STM32F446_FromScratch_FreeRTOS_Template/ThirdParty/tracealyser/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-tracealyser-2f-Src

clean-ThirdParty-2f-tracealyser-2f-Src:
	-$(RM) ./ThirdParty/tracealyser/Src/trcKernelPort.cyclo ./ThirdParty/tracealyser/Src/trcKernelPort.d ./ThirdParty/tracealyser/Src/trcKernelPort.o ./ThirdParty/tracealyser/Src/trcKernelPort.su ./ThirdParty/tracealyser/Src/trcSnapshotRecorder.cyclo ./ThirdParty/tracealyser/Src/trcSnapshotRecorder.d ./ThirdParty/tracealyser/Src/trcSnapshotRecorder.o ./ThirdParty/tracealyser/Src/trcSnapshotRecorder.su ./ThirdParty/tracealyser/Src/trcStreamingRecorder.cyclo ./ThirdParty/tracealyser/Src/trcStreamingRecorder.d ./ThirdParty/tracealyser/Src/trcStreamingRecorder.o ./ThirdParty/tracealyser/Src/trcStreamingRecorder.su

.PHONY: clean-ThirdParty-2f-tracealyser-2f-Src

