/*
 * pressure_sensor.c
 *
 *  Created on: Mar 23, 2020
 *      Author: scholvat
 */

#include "pressure_sensor.h"
#include <ti/drivers/SPI.h>
#include <ti/drivers/GPIO.h>

#include "ti_drivers_config.h"

static SPI_Handle  spi;
static SPI_Params  spiParams;
static uint8_t     transmitBuffer[4];
static uint8_t     receiveBuffer[4];
static SPI_Transaction spiTransaction;

void pressure_init(){
    GPIO_init();
    SPI_init();

    SPI_Params_init(&spiParams);  // Initialize SPI parameters
    spiParams.dataSize = 8;       // 8-bit data size
    spiParams.transferMode = SPI_MODE_BLOCKING;
    spiParams.transferTimeout = 10000; //TODO calcuate actual timeout

    spi = SPI_open(SPI_0, &spiParams);
    if (spi == NULL) {
        while (1);  // SPI_open() failed
    }
}

int16_t pressure_read(uint8_t ss_pin){
    // Fill in transmitBuffer
    spiTransaction.count = 4;
    spiTransaction.txBuf = (void *)transmitBuffer;
    spiTransaction.rxBuf = (void *)receiveBuffer;

    int32_t status;
    do{
        GPIO_write(ss_pin, 0);
        if (!SPI_transfer(spi, &spiTransaction)) {
         // Error in SPI or transfer already in progress.
         while (1);
        }
        GPIO_write(ss_pin, 1);
        status = receiveBuffer[0] >>6;
    }while(status != 0);

    //Pressure
    uint16_t pressure_output = (((receiveBuffer[0] << 8) | receiveBuffer[1] ) & 0x3FFF);
    return ((pressure_output - 1638)*150)/ 131; //psi*100

    //output /2047 *200 + 50 = degrees C
    //temp = (((receiveBuffer[2] << 3) | receiveBuffer[3] >> 5 ) & 0x7FF)*200/2047 - 50;

}
