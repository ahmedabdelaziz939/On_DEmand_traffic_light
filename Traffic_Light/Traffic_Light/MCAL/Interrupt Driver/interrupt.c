/*
 * interrupt.c
 *
 * Created: 12/09/2022 21:39:53
 *  Author: Ahmed
 */ 




#include "interrupt.h"

void EXTI_INT0_init(void){
	MCUCR |= (1<<MCUCR_ISC00)|(1<<MCUCR_ISC01); //set sense control as rising edge 
	GICR |=(1<<GICR_INT0);    // enable peripheral interrupt INT0
}
void EXTI_INT1_init(void);
void EXTI_INT2_init(void);