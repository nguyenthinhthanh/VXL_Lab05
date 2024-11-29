/*
 * timer.h
 *
 *  Created on: Nov 29, 2024
 *      Author: ADMINS
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define MAX_TIMER	3

#define TIMER_TIME_OUT			0		/*3s for timer time out*/

extern int TIMER_CYCLE;

extern int Timer_Counter[MAX_TIMER];
extern int Timer_Flag[MAX_TIMER];

void Init_Timer(void);

void ignoreTimer(int index);

void activeTimer(int index);

int getTimerFlags(int index);

void setTimer(int index, int duration);

void runTimer(void);


#endif /* INC_TIMER_H_ */
