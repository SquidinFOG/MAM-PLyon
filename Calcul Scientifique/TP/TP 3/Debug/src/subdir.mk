################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TP\ 3.c 

OBJS += \
./src/TP\ 3.o 

C_DEPS += \
./src/TP\ 3.d 


# Each subdirectory must supply rules for building sources it contributes
src/TP\ 3.o: ../src/TP\ 3.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Intel C Compiler'
	icc -g -O0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/TP\ 3.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


