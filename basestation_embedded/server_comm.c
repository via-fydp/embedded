/*
 * server_comm.c
 *
 *  Created on: Mar 11, 2020
 *      Author: scholvat
 */

#include "server_comm.h"

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Clock.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>

#include <string.h>
#include <stdlib.h>

#include "ti_drivers_config.h"
#include "pneumatics.h"

#define BUF_SIZE 50

#define STR_STARTS_WITH(a, b) ({(strncmp(a, b, strlen(b)) == 0) ? 1 : 0;})

#define SERVER_TASK_STACK_SIZE    1024
#define SERVER_TASK_PRIORITY      1

#define BUFSIZE 30

/***** Variable declarations *****/
static Task_Params serverTaskParams;
Task_Struct serverTask;    /* not static so you can see in ROV */
static uint8_t serverTaskStack[SERVER_TASK_STACK_SIZE];

static char server_initted = 0;
static UART_Handle uart;
static UART_Params uartParams;

void server_task_init(){
    Task_Params_init(&serverTaskParams);
    serverTaskParams.stackSize = SERVER_TASK_STACK_SIZE;
    serverTaskParams.priority = SERVER_TASK_PRIORITY;
    serverTaskParams.stack = &serverTaskStack;
    serverTaskParams.arg0 = (UInt)1000000;

    Task_construct(&serverTask, server_task_run, &serverTaskParams, NULL);
}

void server_init(){
        UART_init();

        /* Create a UART with data processing off. */
        UART_Params_init(&uartParams);
        uartParams.writeDataMode = UART_DATA_BINARY;
        uartParams.readDataMode = UART_DATA_BINARY;
        uartParams.readReturnMode = UART_RETURN_FULL;
        uartParams.readEcho = UART_ECHO_OFF;
        uartParams.baudRate = 115200;

        uart = UART_open(CONFIG_UART_0, &uartParams);

        if (uart == NULL) {
            /* UART_open() failed */
            while (1);
        }

        server_initted = 1;

        server_print_str("basestation_welcome\n");
}

void server_print_str(const char * str){
    if(!server_initted) return;
    UART_write(uart, str, strlen(str));
}

void server_print_ln(const char * str){
    server_print_str(str);
    server_print_str("\n");

}


void server_task_run(){
    char buffer_index;
    char buffer[BUF_SIZE];

    server_init();
    pneumatics_init();

    while(1){
        buffer_index=0;
        do{
            UART_read(uart, &buffer[buffer_index], 1);
            buffer_index++;
            if(buffer_index > BUF_SIZE){
                //reset line if overflow
                buffer_index=0;
            }
        }while(buffer[buffer_index-1] != '\n');

        buffer[buffer_index-1]=0; //null terminate string, truncating \n
        char status = 0;
        if(strcmp(buffer,"charge_main")==0){
            status = pneumatics_charge_main();
        }
        else if(strcmp(buffer,"drain_main")==0){
            status = pneumatics_drain_main();
        }
        else if(strcmp(buffer,"hold_main")==0){
            status = pneumatics_hold_main();
        }
        else if(STR_STARTS_WITH(buffer,"charge_brake_")){
            status = pneumatics_charge_brake(atoi(&buffer[strlen("charge_brake_")]));
        }
        else if(STR_STARTS_WITH(buffer,"drain_brake_")){
            status = pneumatics_drain_brake(atoi(&buffer[strlen("drain_brake_")]));
        }
        else if(strcmp(buffer,"hold_brake")==0){
            status = pneumatics_hold_brake();
        }
        else if(strcmp(buffer,"emerg_drain_brake")==0){
            status = pneumatics_emerg_drain_brake();
        }
        else if(strcmp(buffer,"hold_all")==0){
            status = pneumatics_hold_all();
        }
        if(status>0){
            server_print_str("ack_");
        }else{
            server_print_str("nack_");
        }

        server_print_ln(buffer);
    }
}
