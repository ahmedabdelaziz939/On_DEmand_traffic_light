/*
 * app.c
 *
 * Created: 11/09/2022 06:11:26
 *  Author: Ahmed
 */ 

#include "app.h"

uint8_t Led_Number=0;
uint8_t PIN_Value;


/************************************************************************/
/* 1.App_init initialization of the program
     1.1 init of LEDs as output
	 1.2 init of button as input
	 1.3 init of interrupt
	 1.4 init of timer
   2.App_start start of the program   
     2.1 starting normal mode 
   3.ISR function to be done when button is pressed                                  */
/************************************************************************/


void app_init(void){

	
	LED_init(PORT_A,PIN0);   // car green
	LED_init(PORT_A,PIN1);   // car yellow
	LED_init(PORT_A,PIN2);   // car red 
	
	LED_init(PORT_B,PIN0);  // pedestrian green
	LED_init(PORT_B,PIN1);  // pedestrian yellow
	LED_init(PORT_B,PIN2);  // pedestrian red
	
	Button_init(PORT_D,2);  // making this pin input 
	
	Set_timer();         //setting the timer
	
	EXTI_INT0_init();    //Interrupt 0
	GIE_enable();        // enable global interrupt
	
}
	
void app_start(void){
	
			// normal mode
			LED_on(PORT_A,PIN0);  //car's green led on 
			LED_on(PORT_B,PIN2);  //ped's red led on 
			Start_timer(19532);
			Timer_stop();
			LED_off(PORT_A,PIN0);  //car's green led off
			LED_off(PORT_B,PIN2);  //ped's red led off
		
			TWO_LED_blink(PORT_A,PIN1,PORT_B,PIN1);  // Both yellow led on 
			LED_off(PORT_A,PIN1);  //car's yellow led off
			LED_off(PORT_B,PIN1);  //ped's yellow led off
			
			LED_on(PORT_A,PIN2);  //car's Red led on
			LED_on(PORT_B,PIN0);  //ped's green led on
			Start_timer(19532);
			Timer_stop();
			LED_off(PORT_A,PIN2);  //car's red led off
			LED_off(PORT_B,PIN0);  //ped's green led off
			
			
			TWO_LED_blink(PORT_A,PIN1,PORT_B,PIN1);  // Both yellow led on
			LED_off(PORT_A,PIN1);  //car's yellow led off
			LED_off(PORT_B,PIN1);  //ped's yellow led off
		
}


/*
void __vector_1(void) __attribute__((signal));     // ISR Function 
void __vector_1(void){
		Dio_read(PORT_A,2,&PIN_Value); // reading pin of car's red led
		if (PIN_Value==HIGH)   // checking if car is red led already on or not
		{
				
			LED_off(PORT_A,PIN2);  //car's red led off
			LED_off(PORT_B,PIN0);  //ped's green led off	
			LED_on(PORT_A,PIN2);  //car's Red led on
			LED_on(PORT_B,PIN0);  //ped's green led on
			Start_timer(19532);
			Timer_stop();
			LED_off(PORT_A,PIN2);  //car's red led off
			LED_off(PORT_B,PIN0);  //ped's green led off
				
			TWO_LED_blink(PORT_A,PIN1,PORT_B,PIN1);  // Both yellow led on
			LED_off(PORT_A,PIN1);  //car's yellow led off
			LED_off(PORT_B,PIN1);  //ped's yellow led off

			}else {             // if car's red led is not on
			LED_off(PORT_A,0);
			LED_off(PORT_A,1);
			LED_off(PORT_B,1);
			LED_off(PORT_B,2);
				
			TWO_LED_blink(PORT_A,PIN1,PORT_B,PIN1);  // Both yellow led on
			LED_off(PORT_A,PIN1);  //car's yellow led off
			LED_off(PORT_B,PIN1);  //ped's yellow led off
				
			LED_on(PORT_A,PIN2);  //car's Red led on
			LED_on(PORT_B,PIN0);  //ped's green led on
			Start_timer(19532);
			Timer_stop();
			LED_off(PORT_A,PIN2);  //car's red led off
			LED_off(PORT_B,PIN0);  //ped's green led off
				
			TWO_LED_blink(PORT_A,PIN1,PORT_B,PIN1);  // Both yellow led on
			LED_off(PORT_A,PIN1);  //car's yellow led off
			LED_off(PORT_B,PIN1);  //ped's yellow led off
		}

		return app_start();

}*/