/*
 * timer.h
 *
 * Created: 04/09/2022 15:13:55
 *  Author: Ahmed
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../../Utilities/register.h"

void Set_timer();
void Start_timer(unsigned int overFlowsNumber);
void Timer_stop();


#endif /* TIMER_H_ */