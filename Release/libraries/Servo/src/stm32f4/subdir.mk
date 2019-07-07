################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ziash/eclipse/eclipse/arduinoPlugin/libraries/Servo/1.1.3/src/stm32f4/Servo.cpp 

LINK_OBJ += \
./libraries/Servo/src/stm32f4/Servo.cpp.o 

CPP_DEPS += \
./libraries/Servo/src/stm32f4/Servo.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/Servo/src/stm32f4/Servo.cpp.o: /home/ziash/eclipse/eclipse/arduinoPlugin/libraries/Servo/1.1.3/src/stm32f4/Servo.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/ziash/workspaceKobuki/Kobuki/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/variants/eightanaloginputs" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/libraries/Servo/1.1.3/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


