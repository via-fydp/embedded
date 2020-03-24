/*
 * wpsu.h
 *
 *  Created on: Dec 7, 2019
 *      Author: scholvat
 */

#ifndef WPSU_H_
#define WPSU_H_


/* Runtime Library Header Files */
#include <stdlib.h>
#include <string.h>

#define WPSU_UUID 5
#define NUM_MEASUREMENTS 1

typedef struct {
    uint8_t uuid;
    int16_t pressure[NUM_MEASUREMENTS]; //average of pressures
    uint8_t pressure_diff[NUM_MEASUREMENTS]; //difference of pressures. 0xFF is a fault
    //uint16_t temp; // average of both sensors
    uint8_t battery;
    uint8_t faults;

} wpsu_packet_t;

#endif /* WPSU_H_ */
