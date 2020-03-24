/*
 * pressure_sensor.h
 *
 *  Created on: Mar 23, 2020
 *      Author: scholvat
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include <stdlib.h>
#include <stdint.h>

void pressure_init();
int16_t pressure_read(uint8_t ss_pin);

#endif /* PRESSURE_SENSOR_H_ */
