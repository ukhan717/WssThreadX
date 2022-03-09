################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/WorkSpace/Documentation/Stm32U5/SecWkspace/Nx_TCP_Echo_Server/Middlewares/ST/netxduo/common/drivers/wifi/mxchip/mx_wifi_azure_rtos.c \
C:/WorkSpace/Documentation/Stm32U5/SecWkspace/Nx_TCP_Echo_Server/Middlewares/ST/netxduo/common/drivers/wifi/mxchip/nx_driver_emw3080.c 

OBJS += \
./Middlewares/Interfaces/Network/wifi/mx_wifi_azure_rtos.o \
./Middlewares/Interfaces/Network/wifi/nx_driver_emw3080.o 

C_DEPS += \
./Middlewares/Interfaces/Network/wifi/mx_wifi_azure_rtos.d \
./Middlewares/Interfaces/Network/wifi/nx_driver_emw3080.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Interfaces/Network/wifi/mx_wifi_azure_rtos.o: C:/WorkSpace/Documentation/Stm32U5/SecWkspace/Nx_TCP_Echo_Server/Middlewares/ST/netxduo/common/drivers/wifi/mxchip/mx_wifi_azure_rtos.c Middlewares/Interfaces/Network/wifi/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DNX_INCLUDE_USER_DEFINE_FILE -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U585xx -c -I../../NetXDuo/App -I../../Core/Inc -I../../AZURE_RTOS/App -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Middlewares/ST/netxduo/addons/dhcp -I../../Middlewares/ST/threadx/common/inc -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Middlewares/ST/netxduo/common/inc -I../../Middlewares/ST/netxduo/ports/cortex_m33/gnu/inc -I../../Middlewares/ST/threadx/ports/cortex_m33/gnu/inc -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/mx_wifi -I../../Middlewares/ST/netxduo/common/drivers/wifi/mxchip -I../../Drivers/BSP/B-U585I-IOT02A -I../../NetXDuo/Target -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/Interfaces/Network/wifi/nx_driver_emw3080.o: C:/WorkSpace/Documentation/Stm32U5/SecWkspace/Nx_TCP_Echo_Server/Middlewares/ST/netxduo/common/drivers/wifi/mxchip/nx_driver_emw3080.c Middlewares/Interfaces/Network/wifi/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DNX_INCLUDE_USER_DEFINE_FILE -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U585xx -c -I../../NetXDuo/App -I../../Core/Inc -I../../AZURE_RTOS/App -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Middlewares/ST/netxduo/addons/dhcp -I../../Middlewares/ST/threadx/common/inc -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Middlewares/ST/netxduo/common/inc -I../../Middlewares/ST/netxduo/ports/cortex_m33/gnu/inc -I../../Middlewares/ST/threadx/ports/cortex_m33/gnu/inc -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/mx_wifi -I../../Middlewares/ST/netxduo/common/drivers/wifi/mxchip -I../../Drivers/BSP/B-U585I-IOT02A -I../../NetXDuo/Target -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Interfaces-2f-Network-2f-wifi

clean-Middlewares-2f-Interfaces-2f-Network-2f-wifi:
	-$(RM) ./Middlewares/Interfaces/Network/wifi/mx_wifi_azure_rtos.d ./Middlewares/Interfaces/Network/wifi/mx_wifi_azure_rtos.o ./Middlewares/Interfaces/Network/wifi/nx_driver_emw3080.d ./Middlewares/Interfaces/Network/wifi/nx_driver_emw3080.o

.PHONY: clean-Middlewares-2f-Interfaces-2f-Network-2f-wifi

