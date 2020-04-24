/*
 * pneumatics.c
 *
 *  Created on: Mar 11, 2020
 *      Author: scholvat
 */

#include "pneumatics.h"

/* TI-RTOS Header files */
#include <ti/drivers/PWM.h>
#include <ti/drivers/GPIO.h>

/* Board Header files */
#include "ti_drivers_config.h"

//PWM value to hold proportional valve
#define PROPORTIONAL_HOLD_VALUE 0
#define PROPORTIONAL_PWM_PERIOD 512

PWM_Handle proportional_valve_pwm_handle;

static char pneumatics_initted = 0;

void pneumatics_init(){

    PWM_Params params;

    PWM_init();
    PWM_Params_init(&params);
    params.dutyUnits = PWM_DUTY_US;
    params.dutyValue = 0;
    params.periodUnits = PWM_PERIOD_US;
    params.periodValue = PROPORTIONAL_PWM_PERIOD;
    proportional_valve_pwm_handle = PWM_open(PROPORTIONAL_VALVE, &params);
    if (proportional_valve_pwm_handle == 0) {
        /* PWM did not open */
        while (1);
    }

    PWM_start(proportional_valve_pwm_handle);

    GPIO_init();

    /* Turn on user LED */
    GPIO_write(PANEL_LED, 1);
    pneumatics_initted = 1;
}

char pneumatics_charge_main(){
    if(!pneumatics_initted) return 0;
    GPIO_write(MAIN_DRAIN_VALVE, 1);
    GPIO_write(MAIN_INPUT_VALVE, 1);
    return 1;
}

char pneumatics_drain_main(){
    if(!pneumatics_initted) return 0;
    GPIO_write(MAIN_INPUT_VALVE, 0);
    GPIO_write(MAIN_DRAIN_VALVE, 1);

    return 1;
}

char pneumatics_hold_main(){
    if(!pneumatics_initted) return 0;
    GPIO_write(MAIN_INPUT_VALVE, 0);
    GPIO_write(MAIN_DRAIN_VALVE, 0);
    return 1;

}

char pneumatics_charge_brake(uint16_t val){
    if(!pneumatics_initted) return 0;
    GPIO_write(BRAKE_EMERG_VALVE, 0);
    GPIO_write(BRAKE_INPUT_VALVE, 1);
    PWM_setDuty(proportional_valve_pwm_handle, val);
    return 1;
}

char pneumatics_drain_brake(uint16_t val){
    if(!pneumatics_initted) return 0;
    GPIO_write(BRAKE_EMERG_VALVE, 0);
    GPIO_write(BRAKE_INPUT_VALVE, 0);
    PWM_setDuty(proportional_valve_pwm_handle, val);
    return 1;
}

char pneumatics_hold_brake(){
    if(!pneumatics_initted) return 0;
    GPIO_write(BRAKE_INPUT_VALVE, 0);
    GPIO_write(BRAKE_EMERG_VALVE, 0);
    PWM_setDuty(proportional_valve_pwm_handle, PROPORTIONAL_HOLD_VALUE);
    return 1;
}

char pneumatics_emerg_drain_brake(){
    if(!pneumatics_initted) return 0;
    GPIO_write(BRAKE_INPUT_VALVE, 0);
    PWM_setDuty(proportional_valve_pwm_handle, PROPORTIONAL_HOLD_VALUE);
    GPIO_write(BRAKE_EMERG_VALVE, 1);
    return 1;
}

char pneumatics_hold_all(){
    return (pneumatics_hold_brake() && pneumatics_hold_main());
}
