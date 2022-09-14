/*
 * LED.c
 *
 * Created: 03/09/2022 22:48:19
 *  Author: Ahmed
 */ 
#include "LED.h"



void LED_init(uint8_t ledPort, uint8_t ledPin){
	Dio_init(ledPort,ledPin,OUTPUT);
}
void LED_on(uint8_t ledPort, uint8_t ledPin){
	Dio_write(ledPort,ledPin,HIGH);
}
void LED_off(uint8_t ledPort, uint8_t ledPin){
	Dio_write(ledPort,ledPin,LOW);
}
void LED_toggle(uint8_t ledPort, uint8_t ledPin){
    Dio_toggle(ledPort,ledPin);
}
void LED_blink(uint8_t ledPort, uint8_t ledPin){
	unsigned int blinkNumber=0;
	while(blinkNumber<5){
		Dio_toggle(ledPort,ledPin);
		Start_timer(3907);
		Timer_stop();
		blinkNumber++;
	}
}
void TWO_LED_blink(uint8_t ledPort_1, uint8_t ledPin_1,uint8_t ledPort_2, uint8_t ledPin_2){
	unsigned int blinkNumber=0;
	while(blinkNumber<5){
		Dio_toggle(ledPort_1,ledPin_1);
		Dio_toggle(ledPort_2,ledPin_2);
		Start_timer(3907);
		Timer_stop();
		blinkNumber++;
	}
}