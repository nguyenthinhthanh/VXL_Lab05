/*
 * uart_communiation.h
 *
 *  Created on: Nov 29, 2024
 *      Author: ADMINS
 */

#ifndef INC_UART_COMMUNIATION_H_
#define INC_UART_COMMUNIATION_H_

#include "gobal.h"
#include "timer.h"

#define COMMUNICATE_IDEL_STATE				0
#define COMMUNICATE_CHECK_CMD_STATE			1
#define COMMUNICATE_SEND_STATE				2
#define COMMUNICATE_WAIT_ACK_STATE			3
#define COMMUNICATE_RESEND_STATE			4
#define COMMUNICATE_FAULT_STATE				5

void uart_communiation_fsm(void);

#endif /* INC_UART_COMMUNIATION_H_ */
