################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TP1\ RO.c 

OBJS += \
./src/TP1\ RO.o 

C_DEPS += \
./src/TP1\ RO.d 


# Each subdirectory must supply rules for building sources it contributes
src/TP1\ RO.o: ../src/TP1\ RO.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Intel C Compiler'
	icc -g -O0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/TP1\ RO.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


