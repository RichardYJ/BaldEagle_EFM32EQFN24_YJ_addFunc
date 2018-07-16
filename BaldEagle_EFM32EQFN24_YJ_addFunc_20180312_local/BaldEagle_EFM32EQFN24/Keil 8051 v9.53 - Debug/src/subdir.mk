################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
A51_UPPER_SRCS += \
../src/SILABS_STARTUP.A51 

C_SRCS += \
../src/BaldEagle_EFM32EQFN24_main.c \
../src/EFM8LB1_Flash.c \
../src/InitDevice.c \
../src/Interrupts.c \
../src/uart_1.c 

OBJS += \
./src/BaldEagle_EFM32EQFN24_main.OBJ \
./src/EFM8LB1_Flash.OBJ \
./src/InitDevice.OBJ \
./src/Interrupts.OBJ \
./src/SILABS_STARTUP.OBJ \
./src/uart_1.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/%.OBJ: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/BaldEagle_EFM32EQFN24_main.OBJ: D:/WorkSpace/MyCode/SYNC/BaldEagle_EFM32EQFN24_YJ_addFunc_20180312_local/BaldEagle_EFM32EQFN24/inc/bsp.h D:/WorkSpace/MyCode/SYNC/BaldEagle_EFM32EQFN24_YJ_addFunc_20180312_local/BaldEagle_EFM32EQFN24/inc/uart_1.h D:/WorkSpace/MyCode/SYNC/BaldEagle_EFM32EQFN24_YJ_addFunc_20180312_local/BaldEagle_EFM32EQFN24/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v4/developer/toolchains/keil_8051/9.53/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Register_Enums.h D:/WorkSpace/MyCode/SYNC/BaldEagle_EFM32EQFN24_YJ_addFunc_20180312_local/BaldEagle_EFM32EQFN24/inc/EFM8LB1_SMBus_MasterMultibyte.h D:/WorkSpace/MyCode/SYNC/BaldEagle_EFM32EQFN24_YJ_addFunc_20180312_local/BaldEagle_EFM32EQFN24/inc/EFM8LB1_I2C_Slave.h C:/SiliconLabs/SimplicityStudio/v4/developer/toolchains/keil_8051/9.53/INC/STRING.H D:/WorkSpace/MyCode/SYNC/BaldEagle_EFM32EQFN24_YJ_addFunc_20180312_local/BaldEagle_EFM32EQFN24/inc/EFM8LB1_Flash.h D:/WorkSpace/MyCode/SYNC/BaldEagle_EFM32EQFN24_YJ_addFunc_20180312_local/BaldEagle_EFM32EQFN24/inc/bsp_config.h D:/WorkSpace/MyCode/SYNC/BaldEagle_EFM32EQFN24_YJ_addFunc_20180312_local/BaldEagle_EFM32EQFN24/inc/efm8_config.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdbool.h

src/EFM8LB1_Flash.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Register_Enums.h D:/WorkSpace/MyCode/SYNC/BaldEagle_EFM32EQFN24_YJ_addFunc_20180312_local/BaldEagle_EFM32EQFN24/inc/EFM8LB1_Flash.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdbool.h

src/InitDevice.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Register_Enums.h D:/WorkSpace/MyCode/SYNC/BaldEagle_EFM32EQFN24_YJ_addFunc_20180312_local/BaldEagle_EFM32EQFN24/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdbool.h

src/Interrupts.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Register_Enums.h D:/WorkSpace/MyCode/SYNC/BaldEagle_EFM32EQFN24_YJ_addFunc_20180312_local/BaldEagle_EFM32EQFN24/inc/EFM8LB1_SMBus_MasterMultibyte.h D:/WorkSpace/MyCode/SYNC/BaldEagle_EFM32EQFN24_YJ_addFunc_20180312_local/BaldEagle_EFM32EQFN24/inc/EFM8LB1_I2C_Slave.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdbool.h

src/%.OBJ: ../src/%.A51
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	AX51 "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/uart_1.OBJ: D:/WorkSpace/MyCode/SYNC/BaldEagle_EFM32EQFN24_YJ_addFunc_20180312_local/BaldEagle_EFM32EQFN24/inc/uart_1.h D:/WorkSpace/MyCode/SYNC/BaldEagle_EFM32EQFN24_YJ_addFunc_20180312_local/BaldEagle_EFM32EQFN24/inc/efm8_config.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdbool.h


