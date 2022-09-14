/*
 * LED.h
 *
 * Created: 03/09/2022 22:48:01
 *  Author: Ahmed
 */ 


#ifndef LED_H_
#define LED_H_


#include "../../MCAL/DIO Driver/DIO.h"
#include "../../MCAL/Timer Driver/timer.h"

void LED_init(uint8_t ledPort, uint8_t ledPin);
void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_toggle(uint8_t ledPort, uint8_t ledPin);
void LED_blink(uint8_t ledPort, uint8_t ledPin);
void TWO_LED_blink(uint8_t ledPort_1, uint8_t ledPin_1,uint8_t ledPort_2, uint8_t ledPin_2);

#endif /* LED_H_ */