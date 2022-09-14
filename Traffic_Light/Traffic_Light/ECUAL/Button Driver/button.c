/*
 * button.c
 *
 * Created: 03/09/2022 23:24:50
 *  Author: Ahmed
 */ 

#include "button.h"

void Button_init(uint8_t buttonPort,uint8_t buttonPin){
	Dio_init(buttonPort,buttonPin,INPUT);
}
void Button_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value){
	Dio_read(buttonPort,buttonPin,value);
}