/*
 * pneumatics.h
 *
 *  Created on: Mar 11, 2020
 *      Author: scholvat
 */

#ifndef PNEUMATICS_H_
#define PNEUMATICS_H_

#include <stdint.h>

void pneumatics_init();
char pneumatics_charge_main();
char pneumatics_drain_main();
char pneumatics_hold_main();
char pneumatics_charge_brake(uint16_t val);
char pneumatics_drain_brake(uint16_t val);
char pneumatics_hold_brake();
char pneumatics_emerg_drain_brake();
char pneumatics_hold_all();
#endif /* PNEUMATICS_H_ */
