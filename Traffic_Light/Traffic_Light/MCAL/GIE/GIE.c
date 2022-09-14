/*
 * GIE.c
 *
 * Created: 12/09/2022 21:47:19
 *  Author: Ahmed
 */ 

#include "GIE.h"

void GIE_enable(void){
	SREG |=(1<<SREG_I);
}
void GIE_disable(void){
	SREG &=~(1<<SREG_I);
}