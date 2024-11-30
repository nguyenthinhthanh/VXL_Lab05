/*
 * gobal.h
 *
 *  Created on: Nov 29, 2024
 *      Author: ADMINS
 */

#ifndef INC_GOBAL_H_
#define INC_GOBAL_H_

#include "main.h"
#include "stdint.h"
#include <stdio.h>

extern uint8_t MAX_BUFFER_SIZE;

extern char str[50];
extern uint8_t temp;
extern uint8_t buffer[30];
extern uint8_t index_buffer;
extern uint8_t index_start;
extern uint8_t buffer_flag;
extern uint8_t cmd_flag;

extern uint32_t ADC_value;

#endif /* INC_GOBAL_H_ */
