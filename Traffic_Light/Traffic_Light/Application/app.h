/*
 * app.h
 *
 * Created: 11/09/2022 06:11:40
 *  Author: Ahmed
 */


#ifndef APP_H_
#define APP_H_


#include "../ECUAL/Button Driver/button.h"
#include "../ECUAL/LED Driver/LED.h"
#include "../MCAL/Interrupt Driver/interrupt.h"
#include "../MCAL/GIE/GIE.h"


void app_init(void);
void app_start(void);

#endif /* APP_H_ */