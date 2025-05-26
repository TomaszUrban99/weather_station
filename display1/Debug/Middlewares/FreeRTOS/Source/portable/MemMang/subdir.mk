################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/FreeRTOS/Source/portable/MemMang/heap_4.c 

OBJS += \
./Middlewares/FreeRTOS/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./Middlewares/FreeRTOS/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/FreeRTOS/Source/portable/MemMang/%.o Middlewares/FreeRTOS/Source/portable/MemMang/%.su Middlewares/FreeRTOS/Source/portable/MemMang/%.cyclo: ../Middlewares/FreeRTOS/Source/portable/MemMang/%.c Middlewares/FreeRTOS/Source/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -c -I../Inc -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Drivers/CMSIS/Core/Include" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Middlewares/FreeRTOS/Source/include" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Middlewares/FreeRTOS/Source/CMSIS_RTOS_V2" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Middlewares/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Middlewares/FreeRTOS/Source/portable/MemMang" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Inc/Peripherals" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Inc/Interfaces" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Inc/Threads" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang

clean-Middlewares-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang:
	-$(RM) ./Middlewares/FreeRTOS/Source/portable/MemMang/heap_4.cyclo ./Middlewares/FreeRTOS/Source/portable/MemMang/heap_4.d ./Middlewares/FreeRTOS/Source/portable/MemMang/heap_4.o ./Middlewares/FreeRTOS/Source/portable/MemMang/heap_4.su

.PHONY: clean-Middlewares-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang

