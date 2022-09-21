/*
 * Traffic_Light.c
 *
 * Created: 02/09/2022 12:48:59
 * Author : Ahmed
 */ 



//#include "ECUAL/Button Driver/button.h"
//#include "ECUAL/LED Driver/LED.h"
//#include "MCAL/Timer Driver/timer.h"
//#include <avr/interrupt.h>
#include "Application/app.h"

uint8_t PIN_Value;

int main(void)
{
        LED_init(PORT_C,0);
		LED_init(PORT_C,1);
		
        EXTI_INT0_init();
		GIE_enable();
		
		Button_init(PORT_D,2);
    	while (1)
    	{
			  	LED_on(PORT_C,0);  //yellow
			  	Start_timer(5000);
			  	Timer_stop();
				LED_off(PORT_C,0);
}
}
void __vector_1(void) __attribute__((signal));     // ISR Function
void __vector_1(void){
	
	LED_off(PORT_C,0);
	LED_on(PORT_C,1);  // green
	Start_timer(5000);
	Timer_stop();
	LED_off(PORT_C,1);
	
	return main();
}
