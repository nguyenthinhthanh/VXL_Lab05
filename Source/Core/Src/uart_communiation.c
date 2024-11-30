/*
 * uart_communiation.c
 *
 *  Created on: Nov 29, 2024
 *      Author: ADMINS
 */

#include "uart_communiation.h"

uint8_t sucess_message[] = "Transmit success, next transmit\n";
uint8_t fault_message[] = "Fault resend, stop send\n";

uint8_t start = 0;
uint8_t end = 0;
uint8_t Communicate_state = COMMUNICATE_IDEL_STATE;

void uart_communiation_fsm(void){
	switch(Communicate_state){
	case COMMUNICATE_IDEL_STATE:
		if(cmd_flag){
			start = index_start;
			end = (index_buffer - 1 + MAX_BUFFER_SIZE) % MAX_BUFFER_SIZE;
			Communicate_state = COMMUNICATE_CHECK_CMD_STATE;

			cmd_flag = 0;
		}

		break;
	case COMMUNICATE_CHECK_CMD_STATE:
		uint8_t lenght = ((end - start + MAX_BUFFER_SIZE) % MAX_BUFFER_SIZE) - 1;
		if(lenght != 3){
			Communicate_state = COMMUNICATE_IDEL_STATE;

			break;
		}

		if(buffer[(start + 1) % MAX_BUFFER_SIZE] == 'R' && buffer[(start + 2) % MAX_BUFFER_SIZE] == 'S'
				&& buffer[(start + 3) % MAX_BUFFER_SIZE] == 'T'){
			Communicate_state = COMMUNICATE_SEND_STATE;
		}

		break;
	case COMMUNICATE_SEND_STATE:
		ADC_value = HAL_ADC_GetValue(&hadc1);
		HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "%lu\n", ADC_value), 1000);

		setTimer(TIMER_TIME_OUT, 3000);
		activeTimer(TIMER_TIME_OUT);

		Communicate_state = COMMUNICATE_WAIT_ACK_STATE;

		break;
	case COMMUNICATE_WAIT_ACK_STATE:
		if(cmd_flag){
			//HAL_UART_Transmit(&huart2, sucess_message, sizeof(sucess_message), 1000);

			start = index_start;
			end = (index_buffer - 1 + MAX_BUFFER_SIZE) % MAX_BUFFER_SIZE;

			cmd_flag = 0;

			uint8_t lenght = ((end - start + MAX_BUFFER_SIZE) % MAX_BUFFER_SIZE) - 1;

			if(lenght == 2 && buffer[(start + 1) % MAX_BUFFER_SIZE] == 'O'
					&& buffer[(start + 2) % MAX_BUFFER_SIZE] == 'K'){
				ignoreTimer(TIMER_TIME_OUT);

				HAL_UART_Transmit(&huart2, sucess_message, sizeof(sucess_message), 1000);
				Communicate_state = COMMUNICATE_IDEL_STATE;

				break;
			}
		}

		if(getTimerFlags(TIMER_TIME_OUT)){
			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Resend %lu\n", ADC_value), 1000);

			setTimer(TIMER_TIME_OUT, 3000);

			setTimer(TIMER_RESEND_FAULT, 6000);
			activeTimer(TIMER_RESEND_FAULT);

			Communicate_state = COMMUNICATE_RESEND_STATE;
		}

		break;
	case COMMUNICATE_RESEND_STATE:
		if(getTimerFlags(TIMER_TIME_OUT)){
			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Resend %lu\n", ADC_value), 1000);
			setTimer(TIMER_TIME_OUT, 3000);
		}

		if(cmd_flag){
			//HAL_UART_Transmit(&huart2, sucess_message, sizeof(sucess_message), 1000);

			start = index_start;
			end = (index_buffer - 1 + MAX_BUFFER_SIZE) % MAX_BUFFER_SIZE;

			cmd_flag = 0;

			uint8_t lenght = ((end - start + MAX_BUFFER_SIZE) % MAX_BUFFER_SIZE) - 1;

			if(lenght == 2 && buffer[(start + 1) % MAX_BUFFER_SIZE] == 'O'
					&& buffer[(start + 2) % MAX_BUFFER_SIZE] == 'K'){
				ignoreTimer(TIMER_TIME_OUT);
				ignoreTimer(TIMER_RESEND_FAULT);

				HAL_UART_Transmit(&huart2, sucess_message, sizeof(sucess_message), 1000);
				Communicate_state = COMMUNICATE_IDEL_STATE;

				break;
			}
		}

		if(getTimerFlags(TIMER_RESEND_FAULT)){
			ignoreTimer(TIMER_TIME_OUT);
			ignoreTimer(TIMER_RESEND_FAULT);

			Communicate_state = COMMUNICATE_FAULT_STATE;
		}

		break;
	case COMMUNICATE_FAULT_STATE:
		HAL_UART_Transmit(&huart2, fault_message, sizeof(fault_message), 1000);

		Communicate_state = COMMUNICATE_IDEL_STATE;

		break;
	default:
		break;
	}
}
