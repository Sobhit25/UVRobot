################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../3rdParty/FreeRTOS/portable/MemMang/heap_4.c 

OBJS += \
./3rdParty/FreeRTOS/portable/MemMang/heap_4.o 

C_DEPS += \
./3rdParty/FreeRTOS/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
3rdParty/FreeRTOS/portable/MemMang/%.o: ../3rdParty/FreeRTOS/portable/MemMang/%.c 3rdParty/FreeRTOS/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../USB_HOST/App -I"E:/UV_Robot/FreeRTOS/3rdParty/FreeRTOS" -I"E:/UV_Robot/FreeRTOS/3rdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"E:/UV_Robot/FreeRTOS/3rdParty/FreeRTOS/include" -I../USB_HOST/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

