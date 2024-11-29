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

#define MAX_BUFFER_SIZE 30

extern char str[50];
extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern uint32_t ADC_value;

#endif /* INC_GOBAL_H_ */
