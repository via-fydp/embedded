################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
easylink/%.obj: ../easylink/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/scholvat/FYDP/rfEasyLinkRx_CC1352P_2_LAUNCHXL_tirtos_ccs" --include_path="C:/Users/scholvat/FYDP/rfEasyLinkRx_CC1352P_2_LAUNCHXL_tirtos_ccs/Debug" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_40_00_02/source" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_40_00_02/source/ti/posix/ccs" --include_path="C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include" --define=DeviceFamily_CC13X2 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="easylink/$(basename $(<F)).d_raw" --include_path="C:/Users/scholvat/FYDP/rfEasyLinkRx_CC1352P_2_LAUNCHXL_tirtos_ccs/Debug/syscfg" --obj_directory="easylink" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


