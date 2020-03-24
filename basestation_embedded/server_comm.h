/*
 * server_comm.h
 *
 *  Created on: Mar 11, 2020
 *      Author: scholvat
 */

#ifndef SERVER_COMM_H_
#define SERVER_COMM_H_

void server_task_init();
static void server_init();
void server_print_str(const char * str);
void server_print_ln(const char * str);
void server_task_run();

#endif /* SERVER_COMM_H_ */
