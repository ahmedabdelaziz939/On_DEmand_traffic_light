/*
 * button.h
 *
 * Created: 03/09/2022 23:24:31
 *  Author: Ahmed
 */

 
#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"

void Button_init(uint8_t buttonPort,uint8_t buttonPin);
void Button_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value);




#endif /*BUTTON_H_*/