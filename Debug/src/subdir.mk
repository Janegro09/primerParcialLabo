################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Examen-14-10.c \
../src/clientes.c \
../src/publicacion.c \
../src/utn.c 

OBJS += \
./src/Examen-14-10.o \
./src/clientes.o \
./src/publicacion.o \
./src/utn.o 

C_DEPS += \
./src/Examen-14-10.d \
./src/clientes.d \
./src/publicacion.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


