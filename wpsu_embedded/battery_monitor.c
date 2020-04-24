/*
 * battery_monitor.c
 *
 *  Created on: Mar 24, 2020
 *      Author: scholvat
 */

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/I2C.h>

/* Driver configuration */
#include "ti_drivers_config.h"

void battery_init(){
    uint16_t        sample;
    uint16_t        temperature;
    uint8_t         txBuffer[1];
    uint8_t         rxBuffer[2];
    I2C_Handle      i2c;
    I2C_Params      i2cParams;
    I2C_Transaction i2cTransaction;

    GPIO_init();
    I2C_init();

    /* Create I2C for usage */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_100kHz;
    i2cParams.transferMode = I2C_MODE_BLOCKING;
    i2c = I2C_open(BATT_MONITOR, &i2cParams);
    if (i2c == NULL) {
        //Display_printf(display, 0, 0, "Error Initializing I2C\n");
        while (1);
    }
    else {
        //Display_printf(display, 0, 0, "I2C Initialized!\n");
    }

    /* Common I2C transaction setup */
    rxBuffer[0] = 0b010101;
    rxBuffer[1] = 0b010101;
    i2cTransaction.writeBuf   = txBuffer;
    i2cTransaction.writeCount = 1;
    i2cTransaction.readBuf    = rxBuffer;
    i2cTransaction.readCount  = 2;
    i2cTransaction.slaveAddress = 0x70;
    uint8_t status;

    txBuffer[0] = 0;
    while(1){
        i2cTransaction.readCount  = 0;
        i2cTransaction.writeCount = 1;
        status = I2C_transfer(i2c, &i2cTransaction);

        i2cTransaction.readCount  = 2;
        i2cTransaction.writeCount = 0;
        status = I2C_transfer(i2c, &i2cTransaction);
        txBuffer[0]++;
        txBuffer[0] %=12;
    }
}
