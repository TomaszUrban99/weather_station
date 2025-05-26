################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Threads/basic_task.c 

OBJS += \
./Src/Threads/basic_task.o 

C_DEPS += \
./Src/Threads/basic_task.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Threads/%.o Src/Threads/%.su Src/Threads/%.cyclo: ../Src/Threads/%.c Src/Threads/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -c -I../Inc -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Drivers/CMSIS/Core/Include" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Middlewares/FreeRTOS/Source/include" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Middlewares/FreeRTOS/Source/CMSIS_RTOS_V2" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Middlewares/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Middlewares/FreeRTOS/Source/portable/MemMang" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Inc/Peripherals" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Inc/Interfaces" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Inc/Threads" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Threads

clean-Src-2f-Threads:
	-$(RM) ./Src/Threads/basic_task.cyclo ./Src/Threads/basic_task.d ./Src/Threads/basic_task.o ./Src/Threads/basic_task.su

.PHONY: clean-Src-2f-Threads

