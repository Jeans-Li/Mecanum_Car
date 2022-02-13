################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Src/Startup/subdir.mk
-include Core/Src/subdir.mk
-include APP/Src/subdir.mk
-include APP/Drivers/u8g2/csrc/subdir.mk
-include APP/Drivers/u8g2/subdir.mk
-include APP/Drivers/track/subdir.mk
-include APP/Drivers/remote/subdir.mk
-include APP/Drivers/motor/subdir.mk
-include APP/Drivers/SPI_OLED/subdir.mk
-include APP/Drivers/RGB/subdir.mk
-include APP/Drivers/Pressure/subdir.mk
-include APP/Drivers/PID/subdir.mk
-include APP/Drivers/MPU6050/subdir.mk
-include APP/Drivers/JY901/subdir.mk
-include APP/Drivers/HC_SR04/subdir.mk
-include APP/Drivers/BEEP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Mecanum_Car
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Mecanum_Car.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Mecanum_Car.list \

OBJCOPY_BIN += \
Mecanum_Car.bin \


# All Target
all: main-build

# Main-build Target
main-build: Mecanum_Car.elf secondary-outputs

# Tool invocations
Mecanum_Car.elf: $(OBJS) $(USER_OBJS) C:\Users\Jeans\Desktop\2021\Mecanum_Car\STM32F407ZGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Mecanum_Car.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Jeans\Desktop\2021\Mecanum_Car\STM32F407ZGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Mecanum_Car.map" -Wl,--gc-sections -static -u _printf_float --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Mecanum_Car.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Mecanum_Car.list"
	@echo 'Finished building: $@'
	@echo ' '

Mecanum_Car.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Mecanum_Car.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
