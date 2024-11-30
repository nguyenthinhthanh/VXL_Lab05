/*
 * command_parser.h
 *
 *  Created on: Nov 29, 2024
 *      Author: ADMINS
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_

#include "gobal.h"

#define PARSER_IDEL_STATE				0
#define PARSER_START_STATE				1
//#define PARSER_END_STATE				2

//extern uint8_t Parser_state;			/*Just for debug*/

void command_parser_fsm(void);

#endif /* INC_COMMAND_PARSER_H_ */
