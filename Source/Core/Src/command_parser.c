/*
 * command_parser.c
 *
 *  Created on: Nov 29, 2024
 *      Author: ADMINS
 */

#include "command_parser.h"

uint8_t Parser_state = PARSER_IDEL_STATE;

void command_parser_fsm(void){
	switch(Parser_state){
	case PARSER_IDEL_STATE:
		if(temp == '!'){
			index_start = (index_buffer - 1 + MAX_BUFFER_SIZE) % MAX_BUFFER_SIZE;

			Parser_state = PARSER_START_STATE;
		}

		break;
	case PARSER_START_STATE:
		if(temp == '!'){
			index_start = (index_buffer - 1 + MAX_BUFFER_SIZE) % MAX_BUFFER_SIZE;

			Parser_state = PARSER_START_STATE;
		}

		if(temp == '#'){
			cmd_flag = 1;

			Parser_state = PARSER_IDEL_STATE;
		}

		break;
	default:
		break;
	}
}
