################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TP\ 2\ RO.c 

OBJS += \
./src/TP\ 2\ RO.o 

C_DEPS += \
./src/TP\ 2\ RO.d 


# Each subdirectory must supply rules for building sources it contributes
src/TP\ 2\ RO.o: ../src/TP\ 2\ RO.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Intel C Compiler'
	icc -g -O0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/TP\ 2\ RO.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


