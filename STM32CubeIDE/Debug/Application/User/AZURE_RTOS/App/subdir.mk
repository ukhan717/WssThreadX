################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/WorkSpace/Documentation/Stm32U5/WebsocketServer/WssThreadX/AZURE_RTOS/App/app_azure_rtos.c 

OBJS += \
./Application/User/AZURE_RTOS/App/app_azure_rtos.o 

C_DEPS += \
./Application/User/AZURE_RTOS/App/app_azure_rtos.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/AZURE_RTOS/App/app_azure_rtos.o: C:/WorkSpace/Documentation/Stm32U5/WebsocketServer/WssThreadX/AZURE_RTOS/App/app_azure_rtos.c Application/User/AZURE_RTOS/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DNX_INCLUDE_USER_DEFINE_FILE -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U585xx -c -I../../NetXDuo/App -I../../Core/Inc -I../../AZURE_RTOS/App -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Middlewares/ST/netxduo/addons/dhcp -I../../Middlewares/ST/threadx/common/inc -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Middlewares/ST/netxduo/common/inc -I../../Middlewares/ST/netxduo/ports/cortex_m33/gnu/inc -I../../Middlewares/ST/threadx/ports/cortex_m33/gnu/inc -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/mx_wifi -I../../Middlewares/ST/netxduo/common/drivers/wifi/mxchip -I../../Drivers/BSP/B-U585I-IOT02A -I../../NetXDuo/Target -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-AZURE_RTOS-2f-App

clean-Application-2f-User-2f-AZURE_RTOS-2f-App:
	-$(RM) ./Application/User/AZURE_RTOS/App/app_azure_rtos.d ./Application/User/AZURE_RTOS/App/app_azure_rtos.o

.PHONY: clean-Application-2f-User-2f-AZURE_RTOS-2f-App

