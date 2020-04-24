/*
 *  ======== ti_drivers_config.c ========
 *  Configured TI-Drivers module definitions
 *
 *  DO NOT EDIT - This file is generated for the CC1352P_2_LAUNCHXL
 *  by the SysConfig tool.
 */

#include <stddef.h>

#ifndef DeviceFamily_CC13X2
#define DeviceFamily_CC13X2
#endif

#include <ti/devices/DeviceFamily.h>

#include "ti_drivers_config.h"

/*
 *  =============================== GPIO ===============================
 */

#include <ti/drivers/GPIO.h>
#include <ti/drivers/gpio/GPIOCC26XX.h>

/*
 *  ======== gpioPinConfigs ========
 *  Array of Pin configurations
 */
GPIO_PinConfig gpioPinConfigs[] = {
    /* CONFIG_GPIO_RLED : LaunchPad LED Red */
    GPIOCC26XX_DIO_06 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* CONFIG_GPIO_GLED : LaunchPad LED Green */
    GPIOCC26XX_DIO_07 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* PANEL_LED */
    GPIOCC26XX_DIO_26 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* MAIN_DRAIN_VALVE */
    GPIOCC26XX_DIO_21 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* MAIN_INPUT_VALVE */
    GPIOCC26XX_DIO_19 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* BRAKE_INPUT_VALVE */
    GPIOCC26XX_DIO_05 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* BRAKE_EMERG_VALVE */
    GPIOCC26XX_DIO_11 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
};

/*
 *  ======== gpioCallbackFunctions ========
 *  Array of callback function pointers
 *
 *  NOTE: Unused callback entries can be omitted from the callbacks array to
 *  reduce memory usage by enabling callback table optimization
 *  (GPIO.optimizeCallbackTableSize = true)
 */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    /* CONFIG_GPIO_RLED : LaunchPad LED Red */
    NULL,
    /* CONFIG_GPIO_GLED : LaunchPad LED Green */
    NULL,
    /* PANEL_LED */
    NULL,
    /* MAIN_DRAIN_VALVE */
    NULL,
    /* MAIN_INPUT_VALVE */
    NULL,
    /* BRAKE_INPUT_VALVE */
    NULL,
    /* BRAKE_EMERG_VALVE */
    NULL,
};

/*
 *  ======== GPIOCC26XX_config ========
 */
const GPIOCC26XX_Config GPIOCC26XX_config = {
    .pinConfigs = (GPIO_PinConfig *)gpioPinConfigs,
    .callbacks = (GPIO_CallbackFxn *)gpioCallbackFunctions,
    .numberOfPinConfigs = 7,
    .numberOfCallbacks = 7,
    .intPriority = (~0)
};


/*
 *  =============================== PIN ===============================
 */

#include <ti/drivers/PIN.h>
#include <ti/drivers/pin/PINCC26XX.h>

const PIN_Config BoardGpioInitTable[] = {
    /* Parent Signal: CONFIG_GPTIMER_0 PWM Pin, (DIO25) */
    CONFIG_PIN_0 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MED,
    /* XDS110 UART, Parent Signal: CONFIG_UART_0 TX, (DIO13) */
    CONFIG_PIN_1 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_HIGH | PIN_PUSHPULL | PIN_DRVSTR_MED,
    /* XDS110 UART, Parent Signal: CONFIG_UART_0 RX, (DIO12) */
    CONFIG_PIN_2 | PIN_INPUT_EN | PIN_NOPULL | PIN_IRQ_DIS,
    /* CONFIG_RF_24GHZ (DIO28) */
    CONFIG_RF_24GHZ | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    /* CONFIG_RF_HIGH_PA (DIO29) */
    CONFIG_RF_HIGH_PA | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    /* CONFIG_RF_SUB1GHZ (DIO30) */
    CONFIG_RF_SUB1GHZ | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    /* LaunchPad LED Red, Parent Signal: CONFIG_GPIO_RLED GPIO Pin, (DIO6) */
    CONFIG_PIN_RLED | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MED,
    /* LaunchPad LED Green, Parent Signal: CONFIG_GPIO_GLED GPIO Pin, (DIO7) */
    CONFIG_PIN_GLED | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MED,
    /* Parent Signal: PANEL_LED GPIO Pin, (DIO26) */
    CONFIG_PIN_3 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MED,
    /* Parent Signal: MAIN_DRAIN_VALVE GPIO Pin, (DIO21) */
    CONFIG_PIN_4 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MED,
    /* Parent Signal: MAIN_INPUT_VALVE GPIO Pin, (DIO19) */
    CONFIG_PIN_5 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MED,
    /* Parent Signal: BRAKE_INPUT_VALVE GPIO Pin, (DIO5) */
    CONFIG_PIN_6 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MED,
    /* Parent Signal: BRAKE_EMERG_VALVE GPIO Pin, (DIO11) */
    CONFIG_PIN_7 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MED,

    PIN_TERMINATE
};

const PINCC26XX_HWAttrs PINCC26XX_hwAttrs = {
    .intPriority = (~0),
    .swiPriority = 0
};


/*
 *  =============================== PWM ===============================
 */

#include <ti/drivers/PWM.h>
#include <ti/drivers/pwm/PWMTimerCC26XX.h>

/* include driverlib definitions */
#include <ti/devices/cc13x2_cc26x2/driverlib/ioc.h>
#include <ti/devices/cc13x2_cc26x2/inc/hw_ints.h>
#include <ti/devices/cc13x2_cc26x2/inc/hw_memmap.h>

#define CONFIG_PWM_COUNT 1

/*
 *  ======== pwmCC26XXObjects ========
 */
PWMTimerCC26XX_Object pwmTimerCC26XXObjects[CONFIG_PWM_COUNT];

/*
 *  ======== pwmCC26XXHWAttrs ========
 */
const PWMTimerCC26XX_HwAttrs pwmTimerCC26XXHWAttrs[CONFIG_PWM_COUNT] = {
    /* PROPORTIONAL_VALVE */
    {
        .pwmPin = IOID_25,
        .gpTimerUnit = CONFIG_GPTIMER_0
    },
};

/*
 *  ======== PWM_config ========
 */
const PWM_Config PWM_config[CONFIG_PWM_COUNT] = {
    /* PROPORTIONAL_VALVE */
    {
        .fxnTablePtr = &PWMTimerCC26XX_fxnTable,
        .object = &pwmTimerCC26XXObjects[PROPORTIONAL_VALVE],
        .hwAttrs = &pwmTimerCC26XXHWAttrs[PROPORTIONAL_VALVE]
    },
};

const uint_least8_t PWM_count = CONFIG_PWM_COUNT;


/*
 *  =============================== Power ===============================
 */
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26X2.h>
#include "ti_drivers_config.h"

extern void PowerCC26XX_standbyPolicy(void);
extern bool PowerCC26XX_calibrate(unsigned int);

const PowerCC26X2_Config PowerCC26X2_config = {
    .enablePolicy             = true,
    .policyInitFxn            = NULL,
    .policyFxn                = PowerCC26XX_standbyPolicy,
    .calibrateFxn             = PowerCC26XX_calibrate,
    .calibrateRCOSC_LF        = true,
    .calibrateRCOSC_HF        = true,
    .enableTCXOFxn            = NULL
};


/*
 *  =============================== RF Front-end ===============================
 */

/*
 * ======== Front-end control ========
 */
static PIN_Handle frontendPins;
static PIN_State frontendState;

void initRfFrontend(void)
{
    static bool initialized = false;

    if (!initialized) {
        PIN_Config frontendConfig[] = {
            CONFIG_RF_24GHZ | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,      /* Path disabled */
            CONFIG_RF_HIGH_PA | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,      /* Path disabled */
            CONFIG_RF_SUB1GHZ | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,      /* Path disabled */
            PIN_TERMINATE
        };
        frontendPins = PIN_open(&frontendState, frontendConfig);
        initialized = true;
    }
}

/*
 *  =============================== RF Driver ===============================
 */

#include <ti/drivers/rf/RF.h>
/*
 *  Board-specific callback function to set the correct antenna path.
 *
 */
static void rfDriverCallback(RF_Handle client, RF_GlobalEvent event, void* arg);

const RFCC26XX_HWAttrsV2 RFCC26XX_hwAttrs = {
    .hwiPriority        = (~0),
    .swiPriority        = (uint8_t)0,
    .xoscHfAlwaysNeeded = true,
    .globalCallback     = rfDriverCallback,
    .globalEventMask    = RF_GlobalEventRadioPowerDown | RF_GlobalEventRadioSetup
};

/*
 * ======== rfDriverCallback ========
 * Sets up the antenna switch depending on the current PHY configuration.
 * Truth table:
 *
 * Path        DIO28 DIO29 DIO30
 * =========== ===== ===== =====
 * Off         0     0     0
 * Sub-1 GHz   0     0     1
 * 2.4 GHz     1     0     0
 * 20 dBm TX   0     1     0
 */
static void rfDriverCallback(RF_Handle client, RF_GlobalEvent events, void *arg)
{
    /* Local variable. */
    bool    sub1GHz   = false;
    uint8_t loDivider = 0;

    /* Initialize front-end (will only be done once) */
    initRfFrontend();

    /* Switch off all paths first. Needs to be done anyway in every sub-case below. */
    PINCC26XX_setOutputValue(CONFIG_RF_24GHZ, 0);
    PINCC26XX_setOutputValue(CONFIG_RF_HIGH_PA, 0);
    PINCC26XX_setOutputValue(CONFIG_RF_SUB1GHZ, 0);

    if (events & RF_GlobalEventRadioSetup) {
        /* Decode the current PA configuration. */
        RF_TxPowerTable_PAType paType = (RF_TxPowerTable_PAType)RF_getTxPower(client).paType;

        /* Decode the generic argument as a setup command. */
        RF_RadioSetup* setupCommand = (RF_RadioSetup*)arg;

        switch (setupCommand->common.commandNo) {
            case (CMD_RADIO_SETUP):
            case (CMD_BLE5_RADIO_SETUP):
                    loDivider = RF_LODIVIDER_MASK & setupCommand->common.loDivider;

                    /* Sub-1GHz front-end. */
                    if (loDivider != 0) {
                        sub1GHz = true;
                    }
                    break;
            case (CMD_PROP_RADIO_DIV_SETUP):
                    loDivider = RF_LODIVIDER_MASK & setupCommand->prop_div.loDivider;

                    /* Sub-1GHz front-end. */
                    if (loDivider != 0) {
                        sub1GHz = true;
                    }
                    break;
            default:break;
        }

        if (sub1GHz) {
            /* Sub-1 GHz */
            if (paType == RF_TxPowerTable_HighPA) {
                /* PA enable --> HIGH PA
                 * LNA enable --> Sub-1 GHz
                 */
                PINCC26XX_setMux(frontendPins, CONFIG_RF_24GHZ, PINCC26XX_MUX_GPIO);
                /* Note: RFC_GPO3 is a work-around because the RFC_GPO1 (PA enable signal) is sometimes not
                         de-asserted on CC1352 Rev A. */
                PINCC26XX_setMux(frontendPins, CONFIG_RF_HIGH_PA, PINCC26XX_MUX_RFC_GPO3);
                PINCC26XX_setMux(frontendPins, CONFIG_RF_SUB1GHZ, PINCC26XX_MUX_RFC_GPO0);
            } else {
                /* RF core active --> Sub-1 GHz */
                PINCC26XX_setMux(frontendPins, CONFIG_RF_24GHZ, PINCC26XX_MUX_GPIO);
                PINCC26XX_setMux(frontendPins, CONFIG_RF_HIGH_PA, PINCC26XX_MUX_GPIO);
                PINCC26XX_setMux(frontendPins, CONFIG_RF_SUB1GHZ, PINCC26XX_MUX_GPIO);
                PINCC26XX_setOutputValue(CONFIG_RF_SUB1GHZ, 1);
            }
        } else {
            /* 2.4 GHz */
            if (paType == RF_TxPowerTable_HighPA)
            {
                /* PA enable --> HIGH PA
                 * LNA enable --> 2.4 GHz
                 */
                PINCC26XX_setMux(frontendPins, CONFIG_RF_24GHZ, PINCC26XX_MUX_RFC_GPO0);
                /* Note: RFC_GPO3 is a work-around because the RFC_GPO1 (PA enable signal) is sometimes not
                         de-asserted on CC1352 Rev A. */
                PINCC26XX_setMux(frontendPins, CONFIG_RF_HIGH_PA, PINCC26XX_MUX_RFC_GPO3);
                PINCC26XX_setMux(frontendPins, CONFIG_RF_SUB1GHZ, PINCC26XX_MUX_GPIO);
            } else {
                /* RF core active --> 2.4 GHz */
                PINCC26XX_setMux(frontendPins, CONFIG_RF_24GHZ, PINCC26XX_MUX_GPIO);
                PINCC26XX_setMux(frontendPins, CONFIG_RF_HIGH_PA, PINCC26XX_MUX_GPIO);
                PINCC26XX_setMux(frontendPins, CONFIG_RF_SUB1GHZ, PINCC26XX_MUX_GPIO);
                PINCC26XX_setOutputValue(CONFIG_RF_24GHZ, 1);
            }
        }
    } else {
        /* Reset the IO multiplexer to GPIO functionality */
        PINCC26XX_setMux(frontendPins, CONFIG_RF_24GHZ, PINCC26XX_MUX_GPIO);
        PINCC26XX_setMux(frontendPins, CONFIG_RF_HIGH_PA, PINCC26XX_MUX_GPIO);
        PINCC26XX_setMux(frontendPins, CONFIG_RF_SUB1GHZ, PINCC26XX_MUX_GPIO);
    }
}


/*
 *  =============================== UART ===============================
 */

#include <ti/drivers/UART.h>
#include <ti/drivers/uart/UARTCC26XX.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26X2.h>
#include <ti/devices/cc13x2_cc26x2/inc/hw_memmap.h>
#include <ti/devices/cc13x2_cc26x2/inc/hw_ints.h>

#define CONFIG_UART_COUNT 1

UARTCC26XX_Object uartCC26XXObjects[CONFIG_UART_COUNT];

static unsigned char uartCC26XXRingBuffer0[32];

static const UARTCC26XX_HWAttrsV2 uartCC26XXHWAttrs[CONFIG_UART_COUNT] = {
  {
    .baseAddr           = UART0_BASE,
    .intNum             = INT_UART0_COMB,
    .intPriority        = (~0),
    .swiPriority        = 0,
    .powerMngrId        = PowerCC26XX_PERIPH_UART0,
    .ringBufPtr         = uartCC26XXRingBuffer0,
    .ringBufSize        = sizeof(uartCC26XXRingBuffer0),
    .rxPin              = IOID_12,
    .txPin              = IOID_13,
    .ctsPin             = PIN_UNASSIGNED,
    .rtsPin             = PIN_UNASSIGNED,
    .txIntFifoThr       = UARTCC26XX_FIFO_THRESHOLD_1_8,
    .rxIntFifoThr       = UARTCC26XX_FIFO_THRESHOLD_4_8,
    .errorFxn           = NULL
  },
};

const UART_Config UART_config[CONFIG_UART_COUNT] = {
    {   /* CONFIG_UART_0 */
        .fxnTablePtr = &UARTCC26XX_fxnTable,
        .object      = &uartCC26XXObjects[0],
        .hwAttrs     = &uartCC26XXHWAttrs[0]
    },
};

const uint_least8_t UART_count = CONFIG_UART_COUNT;


/*
 *  =============================== GPTimer ===============================
 */

#include <ti/drivers/timer/GPTimerCC26XX.h>
#include <ti/drivers/power/PowerCC26XX.h>
#include <ti/devices/cc13x2_cc26x2/inc/hw_memmap.h>
#include <ti/devices/cc13x2_cc26x2/inc/hw_ints.h>

#define CONFIG_GPTIMER_COUNT 1

/*
 *  ======== gptimerCC26XXObjects ========
 */
GPTimerCC26XX_Object gptimerCC26XXObjects[CONFIG_GPTIMER_COUNT];

/*
 *  ======== gptimerCC26XXHWAttrs ========
 */
const GPTimerCC26XX_HWAttrs gptimerCC26XXHWAttrs[CONFIG_GPTIMER_COUNT] = {
    /* CONFIG_GPTIMER_0, used by PROPORTIONAL_VALVE */
    {
        .baseAddr = GPT0_BASE,
        .intNum      = INT_GPT0A,
        .intPriority = (~0),
        .powerMngrId = PowerCC26XX_PERIPH_GPT0,
        .pinMux      = GPT_PIN_0A
    },
};

/*
 *  ======== GPTimer_config ========
 */
const GPTimerCC26XX_Config GPTimerCC26XX_config[CONFIG_GPTIMER_COUNT] = {
    /* CONFIG_GPTIMER_0 */
    {
        .object    = &gptimerCC26XXObjects[CONFIG_GPTIMER_0],
        .hwAttrs   = &gptimerCC26XXHWAttrs[CONFIG_GPTIMER_0],
        .timerPart = GPT_A
    },
};

const uint_least8_t GPTimer_count = CONFIG_GPTIMER_COUNT;


#include <ti/drivers/Board.h>

/*
 *  ======== Board_initHook ========
 *  Perform any board-specific initialization needed at startup.  This
 *  function is declared weak to allow applications to override it if needed.
 */
void __attribute__((weak)) Board_initHook(void)
{
}

/*
 *  ======== Board_init ========
 *  Perform any initialization needed before using any board APIs
 */
void Board_init(void)
{
    /* ==== /ti/drivers/Power initialization ==== */
    Power_init();

    /* ==== /ti/drivers/PIN initialization ==== */
    if (PIN_init(BoardGpioInitTable) != PIN_SUCCESS) {
        /* Error with PIN_init */
        while (1);
    }
    Board_initHook();
}
