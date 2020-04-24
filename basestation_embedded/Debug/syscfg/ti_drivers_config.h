/*
 *  ======== ti_drivers_config.h ========
 *  Configured TI-Drivers module declarations
 *
 *  DO NOT EDIT - This file is generated for the CC1352P_2_LAUNCHXL
 *  by the SysConfig tool.
 */
#ifndef ti_drivers_config_h
#define ti_drivers_config_h

#define CONFIG_SYSCONFIG_PREVIEW

#define CONFIG_CC1352P_2_LAUNCHXL

#ifndef DeviceFamily_CC13X2
#define DeviceFamily_CC13X2
#endif

#include <ti/devices/DeviceFamily.h>

#include <stdint.h>

/* support C++ sources */
#ifdef __cplusplus
extern "C" {
#endif


/*
 *  ======== GPIO ========
 */

/* DIO6, LaunchPad LED Red */
#define CONFIG_GPIO_RLED            0
/* DIO7, LaunchPad LED Green */
#define CONFIG_GPIO_GLED            1
/* DIO26 */
#define PANEL_LED                   2
/* DIO21 */
#define MAIN_DRAIN_VALVE            3
/* DIO19 */
#define MAIN_INPUT_VALVE            4
/* DIO5 */
#define BRAKE_INPUT_VALVE           5
/* DIO11 */
#define BRAKE_EMERG_VALVE           6

/* LEDs are active high */
#define CONFIG_GPIO_LED_ON  (1)
#define CONFIG_GPIO_LED_OFF (0)

#define CONFIG_LED_ON  (CONFIG_GPIO_LED_ON)
#define CONFIG_LED_OFF (CONFIG_GPIO_LED_OFF)


/*
 *  ======== PIN ========
 */

/* Includes */
#include <ti/drivers/PIN.h>

/* Externs */
extern const PIN_Config BoardGpioInitTable[];

/* Parent Signal: CONFIG_GPTIMER_0 PWM Pin, (DIO25) */
#define CONFIG_PIN_0    0x00000019
/* XDS110 UART, Parent Signal: CONFIG_UART_0 TX, (DIO13) */
#define CONFIG_PIN_1    0x0000000d
/* XDS110 UART, Parent Signal: CONFIG_UART_0 RX, (DIO12) */
#define CONFIG_PIN_2    0x0000000c
/* CONFIG_RF_24GHZ (DIO28) */
#define CONFIG_RF_24GHZ    0x0000001c
/* CONFIG_RF_HIGH_PA (DIO29) */
#define CONFIG_RF_HIGH_PA    0x0000001d
/* CONFIG_RF_SUB1GHZ (DIO30) */
#define CONFIG_RF_SUB1GHZ    0x0000001e
/* LaunchPad LED Red, Parent Signal: CONFIG_GPIO_RLED GPIO Pin, (DIO6) */
#define CONFIG_PIN_RLED    0x00000006
/* LaunchPad LED Green, Parent Signal: CONFIG_GPIO_GLED GPIO Pin, (DIO7) */
#define CONFIG_PIN_GLED    0x00000007
/* Parent Signal: PANEL_LED GPIO Pin, (DIO26) */
#define CONFIG_PIN_3    0x0000001a
/* Parent Signal: MAIN_DRAIN_VALVE GPIO Pin, (DIO21) */
#define CONFIG_PIN_4    0x00000015
/* Parent Signal: MAIN_INPUT_VALVE GPIO Pin, (DIO19) */
#define CONFIG_PIN_5    0x00000013
/* Parent Signal: BRAKE_INPUT_VALVE GPIO Pin, (DIO5) */
#define CONFIG_PIN_6    0x00000005
/* Parent Signal: BRAKE_EMERG_VALVE GPIO Pin, (DIO11) */
#define CONFIG_PIN_7    0x0000000b


/*
 *  ======== PWM ========
 */

/* DIO25 */
#define PROPORTIONAL_VALVE          0


/*
 *  ======== RF ========
 */
#define Board_DIO_30_RFSW 0x0000001e


/*
 *  ======== UART ========
 */

/*
 *  TX: DIO13
 *  RX: DIO12
 *  XDS110 UART
 */
#define CONFIG_UART_0               0


/*
 *  ======== GPTimer ========
 */

#define CONFIG_GPTIMER_0            0


/*
 *  ======== Board_init ========
 *  Perform all required TI-Drivers initialization
 *
 *  This function should be called once at a point before any use of
 *  TI-Drivers.
 */
extern void Board_init(void);

/*
 *  ======== Board_initGeneral ========
 *  (deprecated)
 *
 *  Board_initGeneral() is defined purely for backward compatibility.
 *
 *  All new code should use Board_init() to do any required TI-Drivers
 *  initialization _and_ use <Driver>_init() for only where specific drivers
 *  are explicitly referenced by the application.  <Driver>_init() functions
 *  are idempotent.
 */
#define Board_initGeneral Board_init

#ifdef __cplusplus
}
#endif

#endif /* include guard */
