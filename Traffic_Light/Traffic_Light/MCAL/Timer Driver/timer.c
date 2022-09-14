/*
 * timer.c
 *
 * Created: 04/09/2022 15:13:42
 *  Author: Ahmed
 */ 
#include "timer.h"


void Set_timer(){
	  TCCR0=0x00; // normal mode
	  TCNT0=0x00; // set timer initial value
}
void Start_timer(unsigned int overFlowsNumber){
	unsigned int overFlowCounter=0;
	TCCR0 |=(1<<0);
	while(overFlowCounter<overFlowsNumber){
		while((TIFR & (1<<0))==0);
		TIFR |=(1<<0);
		overFlowCounter++;
	}
	overFlowCounter=0;
}
void Timer_stop(){
	TCCR0 =0x00;
}
