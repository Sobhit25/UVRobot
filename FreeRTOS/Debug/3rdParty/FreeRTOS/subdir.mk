################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../3rdParty/FreeRTOS/croutine.c \
../3rdParty/FreeRTOS/event_groups.c \
../3rdParty/FreeRTOS/list.c \
../3rdParty/FreeRTOS/queue.c \
../3rdParty/FreeRTOS/stream_buffer.c \
../3rdParty/FreeRTOS/tasks.c \
../3rdParty/FreeRTOS/timers.c 

OBJS += \
./3rdParty/FreeRTOS/croutine.o \
./3rdParty/FreeRTOS/event_groups.o \
./3rdParty/FreeRTOS/list.o \
./3rdParty/FreeRTOS/queue.o \
./3rdParty/FreeRTOS/stream_buffer.o \
./3rdParty/FreeRTOS/tasks.o \
./3rdParty/FreeRTOS/timers.o 

C_DEPS += \
./3rdParty/FreeRTOS/croutine.d \
./3rdParty/FreeRTOS/event_groups.d \
./3rdParty/FreeRTOS/list.d \
./3rdParty/FreeRTOS/queue.d \
./3rdParty/FreeRTOS/stream_buffer.d \
./3rdParty/FreeRTOS/tasks.d \
./3rdParty/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
3rdParty/FreeRTOS/%.o: ../3rdParty/FreeRTOS/%.c 3rdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../USB_HOST/App -I"E:/UV_Robot/FreeRTOS/3rdParty/FreeRTOS" -I"E:/UV_Robot/FreeRTOS/3rdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"E:/UV_Robot/FreeRTOS/3rdParty/FreeRTOS/include" -I../USB_HOST/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

