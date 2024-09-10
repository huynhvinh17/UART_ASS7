################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/HAL/HAL_UART/HAL_UART_BDH.c \
../Sources/HAL/HAL_UART/HAL_UART_BDL.c \
../Sources/HAL/HAL_UART/HAL_UART_C1.c \
../Sources/HAL/HAL_UART/HAL_UART_C2.c \
../Sources/HAL/HAL_UART/HAL_UART_D.c \
../Sources/HAL/HAL_UART/HAL_UART_S1.c 

OBJS += \
./Sources/HAL/HAL_UART/HAL_UART_BDH.o \
./Sources/HAL/HAL_UART/HAL_UART_BDL.o \
./Sources/HAL/HAL_UART/HAL_UART_C1.o \
./Sources/HAL/HAL_UART/HAL_UART_C2.o \
./Sources/HAL/HAL_UART/HAL_UART_D.o \
./Sources/HAL/HAL_UART/HAL_UART_S1.o 

C_DEPS += \
./Sources/HAL/HAL_UART/HAL_UART_BDH.d \
./Sources/HAL/HAL_UART/HAL_UART_BDL.d \
./Sources/HAL/HAL_UART/HAL_UART_C1.d \
./Sources/HAL/HAL_UART/HAL_UART_C2.d \
./Sources/HAL/HAL_UART/HAL_UART_D.d \
./Sources/HAL/HAL_UART/HAL_UART_S1.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/HAL/HAL_UART/%.o: ../Sources/HAL/HAL_UART/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


