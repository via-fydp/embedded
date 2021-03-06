/*
 *  ======== ti_drivers_config.h ========
 *  Configured TI-Drivers module declarations
 *
 *  DO NOT EDIT - This file is generated for the CC1352P1F3RGZ
 *  by the SysConfig tool.
 */
#ifndef ti_drivers_config_h
#define ti_drivers_config_h

#define CONFIG_SYSCONFIG_PREVIEW

#define CONFIG_CC1352P1F3RGZ

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
 *  ======== ADC ========
 */

/* DIO26 */
#define BATTERY_VOLTAGE             0


/*
 *  ======== GPIO ========
 */

/* DIO6 */
#define RLED                        0
/* DIO7 */
#define GLED                        1
/* DIO23 */
#define SS1                         2
/* DIO14 */
#define SS2                         3
/* DIO24 */
#define REG_PG                      4
/* DIO20 */
#define CHARGE_STAT                 5
/* DIO30 */
#define RF_900                      6
/* DIO29 */
#define RF_24                       7
/* DIO28 */
#define RF_PA                       8
/* DIO5 */
#define BATT_MONITOR_EN             9

/* LEDs are active high */
#define CONFIG_GPIO_LED_ON  (1)
#define CONFIG_GPIO_LED_OFF (0)

#define CONFIG_LED_ON  (CONFIG_GPIO_LED_ON)
#define CONFIG_LED_OFF (CONFIG_GPIO_LED_OFF)


/*
 *  ======== I2C ========
 */

/*
 *  SCL: DIO21
 *  SDA: DIO22
 */
#define BATT_MONITOR                0

/* ======== I2C Addresses and Speeds ======== */
#include <ti/drivers/I2C.h>

/* ---- BATT_MONITOR I2C bus components ---- */

/* no components connected to BATT_MONITOR */

/* max speed unspecified, defaulting to 100 Kbps */
#define BATT_MONITOR_MAXSPEED   (100U) /* Kbps */
#define BATT_MONITOR_MAXBITRATE ((I2C_BitRate)I2C_100kHz)


/*
 *  ======== PIN ========
 */

/* Includes */
#include <ti/drivers/PIN.h>

/* Externs */
extern const PIN_Config BoardGpioInitTable[];

/* Parent Signal: UART_0 TX, (DIO12) */
#define CONFIG_PIN_0    0x0000000c
/* Parent Signal: UART_0 RX, (DIO13) */
#define CONFIG_PIN_1    0x0000000d
/* Parent Signal: SPI_0 SCLK, (DIO8) */
#define CONFIG_PIN_4    0x00000008
/* Parent Signal: SPI_0 MISO, (DIO9) */
#define CONFIG_PIN_5    0x00000009
/* Parent Signal: SPI_0 MOSI, (DIO16) */
#define CONFIG_PIN_6    0x00000010
/* Parent Signal: BATT_MONITOR SDA, (DIO22) */
#define CONFIG_PIN_9    0x00000016
/* Parent Signal: BATT_MONITOR SCL, (DIO21) */
#define CONFIG_PIN_10    0x00000015
/* Parent Signal: REG_PG GPIO Pin, (DIO24) */
#define CONFIG_PIN_11    0x00000018
/* Parent Signal: BATTERY_VOLTAGE ADC Pin, (DIO26) */
#define CONFIG_PIN_17    0x0000001a
/* Parent Signal: RLED GPIO Pin, (DIO6) */
#define CONFIG_PIN_RLED    0x00000006
/* Parent Signal: GLED GPIO Pin, (DIO7) */
#define CONFIG_PIN_12    0x00000007
/* Parent Signal: UART_0 CTS, (DIO11) */
#define CONFIG_PIN_2    0x0000000b
/* Parent Signal: UART_0 RTS, (DIO10) */
#define CONFIG_PIN_3    0x0000000a
/* Parent Signal: SS1 GPIO Pin, (DIO23) */
#define CONFIG_PIN_7    0x00000017
/* Parent Signal: SS2 GPIO Pin, (DIO14) */
#define CONFIG_PIN_8    0x0000000e
/* Parent Signal: CHARGE_STAT GPIO Pin, (DIO20) */
#define CONFIG_PIN_13    0x00000014
/* Parent Signal: RF_900 GPIO Pin, (DIO30) */
#define CONFIG_PIN_14    0x0000001e
/* Parent Signal: RF_24 GPIO Pin, (DIO29) */
#define CONFIG_PIN_15    0x0000001d
/* Parent Signal: RF_PA GPIO Pin, (DIO28) */
#define CONFIG_PIN_16    0x0000001c
/* Parent Signal: BATT_MONITOR_EN GPIO Pin, (DIO5) */
#define CONFIG_PIN_18    0x00000005




/*
 *  ======== SPI ========
 */

/*
 *  MOSI: DIO16
 *  MISO: DIO9
 *  SCLK: DIO8
 */
#define SPI_0                       0


/*
 *  ======== TRNG ========
 */

#define CONFIG_TRNG_EASYLINK        0


/*
 *  ======== UART ========
 */

/*
 *  TX: DIO12
 *  RX: DIO13
 *  CTS: DIO11
 *  RTS: DIO10
 */
#define UART_0                      0


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
