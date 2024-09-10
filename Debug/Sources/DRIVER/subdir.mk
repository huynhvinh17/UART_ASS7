################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/DRIVER/DRIVER_ADC.c \
../Sources/DRIVER/DRIVER_GPIO.c \
../Sources/DRIVER/DRIVER_NVIC.c \
../Sources/DRIVER/DRIVER_PIT.c \
../Sources/DRIVER/DRIVER_PORT.c \
../Sources/DRIVER/DRIVER_SIM.c \
../Sources/DRIVER/DRIVER_Software_timer.c \
../Sources/DRIVER/DRIVER_Systick.c \
../Sources/DRIVER/DRIVER_UART.c \
../Sources/DRIVER/DRIVER_UART_checkData.c 

OBJS += \
./Sources/DRIVER/DRIVER_ADC.o \
./Sources/DRIVER/DRIVER_GPIO.o \
./Sources/DRIVER/DRIVER_NVIC.o \
./Sources/DRIVER/DRIVER_PIT.o \
./Sources/DRIVER/DRIVER_PORT.o \
./Sources/DRIVER/DRIVER_SIM.o \
./Sources/DRIVER/DRIVER_Software_timer.o \
./Sources/DRIVER/DRIVER_Systick.o \
./Sources/DRIVER/DRIVER_UART.o \
./Sources/DRIVER/DRIVER_UART_checkData.o 

C_DEPS += \
./Sources/DRIVER/DRIVER_ADC.d \
./Sources/DRIVER/DRIVER_GPIO.d \
./Sources/DRIVER/DRIVER_NVIC.d \
./Sources/DRIVER/DRIVER_PIT.d \
./Sources/DRIVER/DRIVER_PORT.d \
./Sources/DRIVER/DRIVER_SIM.d \
./Sources/DRIVER/DRIVER_Software_timer.d \
./Sources/DRIVER/DRIVER_Systick.d \
./Sources/DRIVER/DRIVER_UART.d \
./Sources/DRIVER/DRIVER_UART_checkData.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/DRIVER/%.o: ../Sources/DRIVER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


