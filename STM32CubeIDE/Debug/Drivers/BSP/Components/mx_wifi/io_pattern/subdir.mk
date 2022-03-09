################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/WorkSpace/Documentation/Stm32U5/SecWkspace/Nx_TCP_Echo_Server/Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_spi.c 

OBJS += \
./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_spi.o 

C_DEPS += \
./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_spi.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_spi.o: C:/WorkSpace/Documentation/Stm32U5/SecWkspace/Nx_TCP_Echo_Server/Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_spi.c Drivers/BSP/Components/mx_wifi/io_pattern/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DNX_INCLUDE_USER_DEFINE_FILE -DTX_INCLUDE_USER_DEFINE_FILE -DTX_SINGLE_MODE_NON_SECURE=1 -DUSE_HAL_DRIVER -DSTM32U585xx -c -I../../NetXDuo/App -I../../Core/Inc -I../../AZURE_RTOS/App -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Middlewares/ST/netxduo/addons/dhcp -I../../Middlewares/ST/threadx/common/inc -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Middlewares/ST/netxduo/common/inc -I../../Middlewares/ST/netxduo/ports/cortex_m33/gnu/inc -I../../Middlewares/ST/threadx/ports/cortex_m33/gnu/inc -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/mx_wifi -I../../Middlewares/ST/netxduo/common/drivers/wifi/mxchip -I../../Drivers/BSP/B-U585I-IOT02A -I../../NetXDuo/Target -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-mx_wifi-2f-io_pattern

clean-Drivers-2f-BSP-2f-Components-2f-mx_wifi-2f-io_pattern:
	-$(RM) ./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_spi.d ./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_spi.o

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-mx_wifi-2f-io_pattern

