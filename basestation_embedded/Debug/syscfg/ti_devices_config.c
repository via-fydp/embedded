/*
 *  ======== ti_devices_config.c ========
 *  Customer Configuration for CC26XX and CC13XX devices.
 *
 *  DO NOT EDIT - This file is generated by the SysConfig tool.
 *
 */

//#####################################
// Force VDDR high setting (Higher output power but also higher power consumption)
// This is also called "boost mode"
//#####################################

// Force VDDR voltage to the factory HH setting (FCFG1..VDDR_TRIM_HH)
#define CCFG_FORCE_VDDR_HH                              0x1        


//#####################################
// Power settings
//#####################################

// Use the DC/DC during recharge in powerdown
#define SET_CCFG_MODE_CONF_DCDC_RECHARGE                0x0

// Use the DC/DC during active mode
#define SET_CCFG_MODE_CONF_DCDC_ACTIVE                  0x0


//#####################################
// Clock settings
//#####################################

// LF XOSC
#define SET_CCFG_MODE_CONF_SCLK_LF_OPTION               0x2

// Apply cap-array delta
#define SET_CCFG_MODE_CONF_XOSC_CAP_MOD                 0x0 
#define SET_CCFG_MODE_CONF_XOSC_CAPARRAY_DELTA          0xc1

//#####################################
// Special HF clock source setting
//#####################################

// HF source is a 48 MHz xtal
#define SET_CCFG_MODE_CONF_XOSC_FREQ                    0x2    

//#####################################
// Bootloader settings
//#####################################

// Enable ROM boot loader
#define SET_CCFG_BL_CONFIG_BOOTLOADER_ENABLE            0xC5

// Enabled boot loader backdoor
#define SET_CCFG_BL_CONFIG_BL_ENABLE                    0xC5

// DIO number for boot loader backdoor
#define SET_CCFG_BL_CONFIG_BL_PIN_NUMBER                0xf

// Active low to open boot loader backdoor
#define SET_CCFG_BL_CONFIG_BL_LEVEL                     0x0


//#####################################
// Debug access settings
//#####################################

// Disable unlocking of TI FA option.
#define SET_CCFG_CCFG_TI_OPTIONS_TI_FA_ENABLE           0x00

// Access enabled if also enabled in FCFG
#define SET_CCFG_CCFG_TAP_DAP_0_CPU_DAP_ENABLE          0xC5

// Access enabled if also enabled in FCFG
#define SET_CCFG_CCFG_TAP_DAP_0_PWRPROF_TAP_ENABLE      0xC5

// Access disabled
#define SET_CCFG_CCFG_TAP_DAP_0_TEST_TAP_ENABLE         0x00

// Access disabled
#define SET_CCFG_CCFG_TAP_DAP_1_PBIST2_TAP_ENABLE       0x00

// Access disabled
#define SET_CCFG_CCFG_TAP_DAP_1_PBIST1_TAP_ENABLE       0x00

// Access disabled
#define SET_CCFG_CCFG_TAP_DAP_1_AON_TAP_ENABLE          0x00


//#####################################
// Select between cache or GPRAM
//#####################################
// Cache is enabled and GPRAM is disabled (unavailable)
#define SET_CCFG_SIZE_AND_DIS_FLAGS_DIS_GPRAM           0x1



/*
 *  ======== Include Base Settings for device ========
 */

#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(startup_files/ccfg.c)
