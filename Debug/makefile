################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := c:/ti/ccsv6/tools/compiler/arm_5.1.5

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./drivers/touch.obj" \
"./drivers/pinout.obj" \
"./drivers/kentec320x240x16_ssd2119.obj" \
"./drivers/frame.obj" \
"./third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F/portasm.obj" \
"./third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F/port.obj" \
"./third_party/FreeRTOS/Source/portable/MemMang/heap_2.obj" \
"./third_party/FreeRTOS/Source/timers.obj" \
"./third_party/FreeRTOS/Source/tasks.obj" \
"./third_party/FreeRTOS/Source/queue.obj" \
"./third_party/FreeRTOS/Source/list.obj" \
"./third_party/FreeRTOS/Source/croutine.obj" \
"./third_party/lwip-1.4.1/apps/httpserver_raw/httpd.obj" \
"./utils/ustdlib.obj" \
"./utils/lwiplib.obj" \
"./utils/locator.obj" \
"./startup_ccs.obj" \
"./lwip_task.obj" \
"./fs.obj" \
"./freertos_demo.obj" \
"../freertos_demo_ccs.cmd" \
-l"libc.a" \
-l"C:\ti\TivaWare_C_Series-2.0.1.11577/driverlib/ccs/Debug/driverlib.lib" \
-l"C:\ti\TivaWare_C_Series-2.0.1.11577/grlib/ccs/Debug/grlib.lib" \
-l"C:\ti\TivaWare_C_Series-2.0.1.11577\sensorlib\ccs\Debug\sensorlib.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include utils/subdir_vars.mk
-include third_party/lwip-1.4.1/apps/httpserver_raw/subdir_vars.mk
-include third_party/FreeRTOS/Source/subdir_vars.mk
-include third_party/FreeRTOS/Source/portable/MemMang/subdir_vars.mk
-include third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F/subdir_vars.mk
-include drivers/subdir_vars.mk
-include subdir_rules.mk
-include utils/subdir_rules.mk
-include third_party/lwip-1.4.1/apps/httpserver_raw/subdir_rules.mk
-include third_party/FreeRTOS/Source/subdir_rules.mk
-include third_party/FreeRTOS/Source/portable/MemMang/subdir_rules.mk
-include third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F/subdir_rules.mk
-include drivers/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
http_server.out \

EXE_OUTPUTS__QUOTED += \
"http_server.out" \


# All Target
all: http_server.out

# Tool invocations
http_server.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"c:/ti/ccsv6/tools/compiler/arm_5.1.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -O2 -g --gcc --define=ccs="ccs" --define=PART_TM4C129XNCZAD --define=TARGET_IS_SNOWFLAKE_RA0 --diag_warning=225 --display_error_number --diag_wrap=off --gen_func_subsections=on --ual -z --stack_size=4096 -m"freertos_demo_ccs.map" --heap_size=0 -i"c:/ti/ccsv6/tools/compiler/arm_5.1.5/lib" -i"c:/ti/ccsv6/tools/compiler/arm_5.1.5/include" --reread_libs --warn_sections --display_error_number --diag_wrap=off --xml_link_info="http_server_linkInfo.xml" --rom_model -o "http_server.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "freertos_demo.pp" "fs.pp" "lwip_task.pp" "startup_ccs.pp" "utils\locator.pp" "utils\lwiplib.pp" "utils\ustdlib.pp" "third_party\lwip-1.4.1\apps\httpserver_raw\httpd.pp" "third_party\FreeRTOS\Source\croutine.pp" "third_party\FreeRTOS\Source\list.pp" "third_party\FreeRTOS\Source\queue.pp" "third_party\FreeRTOS\Source\tasks.pp" "third_party\FreeRTOS\Source\timers.pp" "third_party\FreeRTOS\Source\portable\MemMang\heap_2.pp" "third_party\FreeRTOS\Source\portable\CCS\ARM_CM4F\port.pp" "drivers\frame.pp" "drivers\kentec320x240x16_ssd2119.pp" "drivers\pinout.pp" "drivers\touch.pp" 
	-$(RM) "freertos_demo.obj" "fs.obj" "lwip_task.obj" "startup_ccs.obj" "utils\locator.obj" "utils\lwiplib.obj" "utils\ustdlib.obj" "third_party\lwip-1.4.1\apps\httpserver_raw\httpd.obj" "third_party\FreeRTOS\Source\croutine.obj" "third_party\FreeRTOS\Source\list.obj" "third_party\FreeRTOS\Source\queue.obj" "third_party\FreeRTOS\Source\tasks.obj" "third_party\FreeRTOS\Source\timers.obj" "third_party\FreeRTOS\Source\portable\MemMang\heap_2.obj" "third_party\FreeRTOS\Source\portable\CCS\ARM_CM4F\port.obj" "third_party\FreeRTOS\Source\portable\CCS\ARM_CM4F\portasm.obj" "drivers\frame.obj" "drivers\kentec320x240x16_ssd2119.obj" "drivers\pinout.obj" "drivers\touch.obj" 
	-$(RM) "third_party\FreeRTOS\Source\portable\CCS\ARM_CM4F\portasm.pp" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-"c:/ti/ccsv6/utils/tiobj2bin/tiobj2bin" "http_server.out" "http_server.bin" "c:/ti/ccsv6/tools/compiler/arm_5.1.5/bin/armofd" "c:/ti/ccsv6/tools/compiler/arm_5.1.5/bin/armhex" "c:/ti/ccsv6/utils/tiobj2bin/mkhex4bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets

