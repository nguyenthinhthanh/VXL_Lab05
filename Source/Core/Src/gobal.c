/*
 * gobal.c
 *
 *  Created on: Nov 29, 2024
 *      Author: ADMINS
 */

#include "gobal.h"

uint8_t MAX_BUFFER_SIZE = 30;

char str[50];

uint8_t temp = 0;
uint8_t buffer[30];
uint8_t index_buffer = 0;
uint8_t index_start = 0;
uint8_t buffer_flag = 0;
uint8_t cmd_flag = 0;

uint32_t ADC_value = 0;
