

/*
 *  ======== rfEasyLinkListenBeforeTalk.c ========
 */
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Clock.h>

/* TI-RTOS Header files */
#include <ti/drivers/PIN.h>
#include <ti/drivers/SPI.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/ADC.h>
#include <ti/drivers/power/PowerCC26XX.h>

/* Board Header files */
#include "ti_drivers_config.h"

/* EasyLink API Header files */
#include "easylink/EasyLink.h"

/* Application header files */
#include <ti_radio_config.h>

/* Runtime Library Header Files */
#include <stdlib.h>
#include <string.h>

/* Driverlib Header files */
#include <ti/devices/DeviceFamily.h>

/* Driver Header files */
#include <ti/drivers/TRNG.h>
#include <ti/drivers/cryptoutils/cryptokey/CryptoKeyPlaintext.h>

//custom includes
#include "wpsu.h"
#include "pressure_sensor.h"
#include "battery_monitor.h"

#define RFEASYLINKLBT_TASK_STACK_SIZE       (1024U)
#define RFEASYLINKLBT_TASK_PRIORITY         (2U)
#define RFEASYLINKLBT_PAYLOAD_LENGTH        (30U)

#define KEY_LENGTH_BYTES                    (4U)
#define MAX_TRNG_RETRIES                    (2U) // Max attempts to generate a random number

#define TRANSMIT_PERIOD 100 //milliseconds
#define MAX_VOLTAGE 4100
#define MIN_VOLTAGE 3500

/*
 * Set to 1 if you want to attempt to retransmit a packet that couldn't be
 * transmitted after the CCA
 */
#define RFEASYLINKLBT_RETRANSMIT_PACKETS    1

#if RFEASYLINKLBT_RETRANSMIT_PACKETS
bool bAttemptRetransmission = false;
#endif // RFEASYLINKLBT_RETRANSMIT_PACKETS

Task_Struct lbtTask;                 /* not static so you can see in ROV */
static Task_Params lbtTaskParams;
static uint8_t lbtTaskStack[RFEASYLINKLBT_TASK_STACK_SIZE];

/* TRNG driver handle */
static TRNG_Handle trngHandle;

/* Crypto Key driver variables */
static CryptoKey entropyKey;
uint8_t entropyBuffer[KEY_LENGTH_BYTES];

static Semaphore_Handle lbtDoneSem;

ADC_Handle adcHandle;

uint32_t getRandomNumber( void )
{
    int_fast16_t result = TRNG_STATUS_ERROR;
    uint8_t breakCounter = MAX_TRNG_RETRIES;
    do
    {
        if(0U == breakCounter--)
        {
            System_abort("Unable to generate a random value");
        }
        else
        {
            result = TRNG_generateEntropy(trngHandle, &entropyKey);
        }
    }while(TRNG_STATUS_SUCCESS != result);

    return(*((uint32_t *)entropyBuffer));
}

void lbtDoneCb(EasyLink_Status status)
{
    if (status == EasyLink_Status_Success)
    {
        /* Toggle GLED to indicate TX */
        GPIO_write(RLED, GPIO_read(GLED));
        GPIO_write(GLED, !GPIO_read(GLED));
#if RFEASYLINKLBT_RETRANSMIT_PACKETS
        bAttemptRetransmission = false;
#endif // RFEASYLINKLBT_RETRANSMIT_PACKETS
    }
    else if (status == EasyLink_Status_Busy_Error)
    {
        /* Toggle RLED to indicate maximum retries reached */
        GPIO_write(GLED, 0);
        GPIO_write(RLED, !GPIO_read(RLED));

#if RFEASYLINKLBT_RETRANSMIT_PACKETS
        bAttemptRetransmission = true;
#endif // RFEASYLINKLBT_RETRANSMIT_PACKETS
    }
    else
    {
        /* Set red LED to indicate error */
        GPIO_write(GLED, 0);
        GPIO_write(RLED, 1);
    }

    Semaphore_post(lbtDoneSem);
}

static void rfEasyLinkLbtFnx(UArg arg0, UArg arg1)
{
    uint32_t absTime;
    EasyLink_TxPacket lbtPacket = { {0}, 0, 0, {0} };

    /* Create a semaphore */
    Semaphore_Params sem_params;
    Error_Block eb;

    /* Init params */
    Semaphore_Params_init(&sem_params);
    Error_init(&eb);

    pressure_init();

    ADC_init();

    ADC_Params adc_params;
    ADC_Params_init(&adc_params);
    adc_params.isProtected = true;
    adcHandle = ADC_open(BATTERY_VOLTAGE, &adc_params);

    //battery_init();

    /* Create a semaphore instance */
    lbtDoneSem = Semaphore_create(0, &sem_params, &eb);
    if(lbtDoneSem == NULL)
    {
        System_abort("Semaphore creation failed");
    }

    /* Initialize the TRNG driver and a blank crypto key */
    TRNG_init();
    TRNG_Params trngParams;
    TRNG_Params_init(&trngParams);
    trngParams.returnBehavior = TRNG_RETURN_BEHAVIOR_POLLING;
    trngHandle = TRNG_open(CONFIG_TRNG_EASYLINK, &trngParams);
    if(NULL == trngHandle)
    {
        System_abort("Failed to init TRNG driver");
    }
    int_fast16_t result = CryptoKeyPlaintext_initBlankKey(&entropyKey, entropyBuffer, KEY_LENGTH_BYTES);
    if(CryptoKey_STATUS_SUCCESS != result)
    {
        System_abort("Unable to create a blank crypto key");
    }

    // Initialize the EasyLink parameters to their default values
    EasyLink_Params easyLink_params;
    EasyLink_Params_init(&easyLink_params);

    // Change the RNG function used for clear channel assessment
    easyLink_params.pGrnFxn = (EasyLink_GetRandomNumber)getRandomNumber;

    /* Initialize EasyLink */
    if(EasyLink_init(&easyLink_params) != EasyLink_Status_Success)
    {
        System_abort("EasyLink_init failed");
    }

    while(1)
    {
        wpsu_packet_t tx_packet;
        tx_packet.uuid = WPSU_UUID; //TODO change to slightly more dynamic UUID instead of hardcoded

        //fill out the packet with data
        int16_t pressure1 = pressure_read(SS1); //TODO change from blocking to callback
        int16_t pressure2 = pressure_read(SS2);
        tx_packet.pressure[0] = (pressure1 + pressure2) / 2; //average
        tx_packet.pressure_diff[0] = ((pressure1 > pressure2) ? (pressure1 - pressure2) : (pressure2 - pressure1));

        //get battery info
        uint16_t adc_result;
        ADC_convert(adcHandle, &adc_result);

        //millivolt value
        adc_result = ADC_convertToMicroVolts(adcHandle, adc_result) / 500;

        //set limits
        adc_result = adc_result >= MAX_VOLTAGE ? MAX_VOLTAGE : adc_result;
        adc_result = adc_result <= MIN_VOLTAGE ? MIN_VOLTAGE : adc_result;

        //linear scaling to percentage
        tx_packet.battery = (adc_result - MIN_VOLTAGE) * 100 / (MAX_VOLTAGE - MIN_VOLTAGE);

        //get charging state
        tx_packet.faults = 0;
        tx_packet.faults |= GPIO_read(CHARGE_STAT) ? 0 : FAULT_CHARGING;

        //copy packet over to the tx buffer
        memcpy(&lbtPacket.payload, &tx_packet, sizeof(wpsu_packet_t));
        lbtPacket.len = sizeof(wpsu_packet_t);
        lbtPacket.dstAddr[0] = 0xaa;

        //set timeout period
        if(EasyLink_getAbsTime(&absTime) != EasyLink_Status_Success)
        {
            // Problem getting absolute time
            //TODO error handling
        }

        lbtPacket.absTime = absTime + EasyLink_ms_To_RadioTime(TRANSMIT_PERIOD);
        EasyLink_transmitCcaAsync(&lbtPacket, lbtDoneCb);

        /* Wait forever for TX to complete */
        Semaphore_pend(lbtDoneSem, BIOS_WAIT_FOREVER);
    }
}

void lbtTask_init()
{

    Task_Params_init(&lbtTaskParams);
    lbtTaskParams.stackSize = RFEASYLINKLBT_TASK_STACK_SIZE;
    lbtTaskParams.priority  = RFEASYLINKLBT_TASK_PRIORITY;
    lbtTaskParams.stack     = (void *)&lbtTaskStack[0];
    lbtTaskParams.arg0      = (UInt)1000000;

    Task_construct(&lbtTask, rfEasyLinkLbtFnx, &lbtTaskParams, NULL);
}

/*
 *  ======== main ========
 */
int main(void)
{
    /* Call driver init functions */
    Board_initGeneral();

    /* Set power dependency for the TRNG */
    Power_setDependency(PowerCC26XX_PERIPH_TRNG);

    lbtTask_init();

    /* Start BIOS */
    BIOS_start();

    return(0);
}

