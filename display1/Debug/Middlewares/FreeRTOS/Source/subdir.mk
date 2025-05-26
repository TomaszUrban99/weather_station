################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/FreeRTOS/Source/croutine.c \
../Middlewares/FreeRTOS/Source/event_groups.c \
../Middlewares/FreeRTOS/Source/list.c \
../Middlewares/FreeRTOS/Source/queue.c \
../Middlewares/FreeRTOS/Source/stream_buffer.c \
../Middlewares/FreeRTOS/Source/tasks.c \
../Middlewares/FreeRTOS/Source/timers.c 

OBJS += \
./Middlewares/FreeRTOS/Source/croutine.o \
./Middlewares/FreeRTOS/Source/event_groups.o \
./Middlewares/FreeRTOS/Source/list.o \
./Middlewares/FreeRTOS/Source/queue.o \
./Middlewares/FreeRTOS/Source/stream_buffer.o \
./Middlewares/FreeRTOS/Source/tasks.o \
./Middlewares/FreeRTOS/Source/timers.o 

C_DEPS += \
./Middlewares/FreeRTOS/Source/croutine.d \
./Middlewares/FreeRTOS/Source/event_groups.d \
./Middlewares/FreeRTOS/Source/list.d \
./Middlewares/FreeRTOS/Source/queue.d \
./Middlewares/FreeRTOS/Source/stream_buffer.d \
./Middlewares/FreeRTOS/Source/tasks.d \
./Middlewares/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/FreeRTOS/Source/%.o Middlewares/FreeRTOS/Source/%.su Middlewares/FreeRTOS/Source/%.cyclo: ../Middlewares/FreeRTOS/Source/%.c Middlewares/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -c -I../Inc -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Drivers/CMSIS/Core/Include" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Middlewares/FreeRTOS/Source/include" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Middlewares/FreeRTOS/Source/CMSIS_RTOS_V2" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Middlewares/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Middlewares/FreeRTOS/Source/portable/MemMang" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Inc/Peripherals" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Inc/Interfaces" -I"/home/tomasz/Documents/Elektronika_Mgr/uC_Programming/Final_Project/weather_station/display1/Inc/Threads" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-FreeRTOS-2f-Source

clean-Middlewares-2f-FreeRTOS-2f-Source:
	-$(RM) ./Middlewares/FreeRTOS/Source/croutine.cyclo ./Middlewares/FreeRTOS/Source/croutine.d ./Middlewares/FreeRTOS/Source/croutine.o ./Middlewares/FreeRTOS/Source/croutine.su ./Middlewares/FreeRTOS/Source/event_groups.cyclo ./Middlewares/FreeRTOS/Source/event_groups.d ./Middlewares/FreeRTOS/Source/event_groups.o ./Middlewares/FreeRTOS/Source/event_groups.su ./Middlewares/FreeRTOS/Source/list.cyclo ./Middlewares/FreeRTOS/Source/list.d ./Middlewares/FreeRTOS/Source/list.o ./Middlewares/FreeRTOS/Source/list.su ./Middlewares/FreeRTOS/Source/queue.cyclo ./Middlewares/FreeRTOS/Source/queue.d ./Middlewares/FreeRTOS/Source/queue.o ./Middlewares/FreeRTOS/Source/queue.su ./Middlewares/FreeRTOS/Source/stream_buffer.cyclo ./Middlewares/FreeRTOS/Source/stream_buffer.d ./Middlewares/FreeRTOS/Source/stream_buffer.o ./Middlewares/FreeRTOS/Source/stream_buffer.su ./Middlewares/FreeRTOS/Source/tasks.cyclo ./Middlewares/FreeRTOS/Source/tasks.d ./Middlewares/FreeRTOS/Source/tasks.o ./Middlewares/FreeRTOS/Source/tasks.su ./Middlewares/FreeRTOS/Source/timers.cyclo ./Middlewares/FreeRTOS/Source/timers.d ./Middlewares/FreeRTOS/Source/timers.o ./Middlewares/FreeRTOS/Source/timers.su

.PHONY: clean-Middlewares-2f-FreeRTOS-2f-Source

