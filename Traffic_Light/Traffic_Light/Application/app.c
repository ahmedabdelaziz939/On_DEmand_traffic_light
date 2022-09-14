/*
 * app.c
 *
 * Created: 11/09/2022 06:11:26
 *  Author: Ahmed
 */ 

#include "app.h"

uint8_t Led_Number=0;
uint8_t PIN_Value;

void app_init(void){

	
	LED_init(PORT_A,3);   // car green
	LED_init(PORT_A,4);   // car yellow
	LED_init(PORT_B,4);   // car red 
	
	LED_init(PORT_C,0);  // pedestrian green
	LED_init(PORT_C,4);  // pedestrian yellow
	LED_init(PORT_C,7);  // pedestrian red
	
	Button_init(PORT_D,2);  // making this pin input 
	
	Set_timer();         //setting the timer
	
	EXTI_INT0_init();    //Interrupt 0
	GIE_enable();        // enable global interrupt
	
}
	
void app_start(void){
	
			// normal mode
			LED_on(PORT_A,PIN3);  //car's green led on 
			LED_on(PORT_C,PIN7);  //ped's red led on 
			Start_timer(19532);
			Timer_stop();
			LED_off(PORT_A,PIN3);  //car's green led off
			LED_off(PORT_C,PIN7);  //ped's red led off
		
			TWO_LED_blink(PORT_A,PIN4,PORT_C,PIN4);  // Both yellow led on 
			LED_off(PORT_A,PIN4);  //car's yellow led off
			LED_off(PORT_C,PIN4);  //ped's yellow led off
			
			LED_on(PORT_B,PIN4);  //car's Red led on
			LED_on(PORT_C,PIN0);  //ped's green led on
			Start_timer(19532);
			Timer_stop();
			LED_off(PORT_B,PIN4);  //car's red led off
			LED_off(PORT_C,PIN0);  //ped's green led off
			
			
			TWO_LED_blink(PORT_A,PIN4,PORT_C,PIN4);  // Both yellow led on
			LED_off(PORT_A,PIN4);  //car's yellow led off
			LED_off(PORT_C,PIN4);  //ped's yellow led off
		
}



void __vector_1(void) __attribute__((signal));     // ISR Function 
void __vector_1(void){
		Dio_read(PORT_B,4,&PIN_Value); // reading pin of car's red led
		if (PIN_Value==HIGH)   // checking if car is red led already on or not
		{
				
			LED_on(PORT_B,PIN4);  //car's Red led on
			LED_on(PORT_C,PIN0);  //ped's green led on
			Start_timer(19532);
			Timer_stop();
			LED_off(PORT_B,PIN4);  //car's red led off
			LED_off(PORT_C,PIN0);  //ped's green led off
				
			TWO_LED_blink(PORT_A,PIN4,PORT_C,PIN4);  // Both yellow led on
			LED_off(PORT_A,PIN4);  //car's yellow led off
			LED_off(PORT_C,PIN4);  //ped's yellow led off

			}else {             // if car's red led is not on
			LED_off(PORT_A,3);
			LED_off(PORT_A,4);
			LED_off(PORT_C,4);
			LED_off(PORT_C,7);
				
			TWO_LED_blink(PORT_A,PIN4,PORT_C,PIN4);  // Both yellow led on
			LED_off(PORT_A,PIN4);  //car's yellow led off
			LED_off(PORT_C,PIN4);  //ped's yellow led off
				
			LED_on(PORT_B,PIN4);  //car's Red led on
			LED_on(PORT_C,PIN0);  //ped's green led on
			Start_timer(19532);
			Timer_stop();
			LED_off(PORT_B,PIN4);  //car's red led off
			LED_off(PORT_C,PIN0);  //ped's green led off
				
			TWO_LED_blink(PORT_A,PIN4,PORT_C,PIN4);  // Both yellow led on
			LED_off(PORT_A,PIN4);  //car's yellow led off
			LED_off(PORT_C,PIN4);  //ped's yellow led off
		}

		return app_start();

}