################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/scholvat/FYDP/common" --include_path="C:/Users/scholvat/FYDP/wpsu_embedded" --include_path="C:/Users/scholvat/FYDP/wpsu_embedded/Debug" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/posix/ccs" --include_path="C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include" --define=DeviceFamily_CC13X2 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/scholvat/FYDP/wpsu_embedded/Debug/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-2193697:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-2193697-inproc

build-2193697-inproc: ../rfEasyLinkListenBeforeTalk.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs920/ccs/utils/sysconfig/sysconfig_cli.bat" -s "C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/.metadata/product.json" -o "syscfg" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_easylink_config.h: build-2193697 ../rfEasyLinkListenBeforeTalk.syscfg
syscfg/ti_easylink_config.c: build-2193697
syscfg/ti_radio_config.c: build-2193697
syscfg/ti_radio_config.h: build-2193697
syscfg/ti_devices_config.c: build-2193697
syscfg/ti_drivers_config.c: build-2193697
syscfg/ti_drivers_config.h: build-2193697
syscfg/syscfg_c.rov.xs: build-2193697
syscfg/: build-2193697

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/scholvat/FYDP/common" --include_path="C:/Users/scholvat/FYDP/wpsu_embedded" --include_path="C:/Users/scholvat/FYDP/wpsu_embedded/Debug" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/posix/ccs" --include_path="C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include" --define=DeviceFamily_CC13X2 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/scholvat/FYDP/wpsu_embedded/Debug/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


