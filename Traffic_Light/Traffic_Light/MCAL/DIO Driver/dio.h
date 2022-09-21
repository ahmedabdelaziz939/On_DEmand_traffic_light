/*
 * DIO.h
 *
 * Created: 02/09/2022 13:11:48
 *  Author: Ahmed
 */ 


#ifndef DIO_H_
#define DIO_H_


// All internal driver typedefs
// all driver macros 
// all driver function prototypes
// 1. function to initialize the pin
// 2. function to write the pin
// 3. function to toggle the pin
// 4. function to read the pin


#include "../../Utilities/types.h"
#include "../../Utilities/register.h"


// Port definition 
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//pin definition 
#define  PIN0   0
#define  PIN1   1
#define  PIN2   2
#define  PIN3   3
#define  PIN4   4
#define  PIN5   5
#define  PIN6   6
#define  PIN7   7



// Direction definition 
#define INPUT 0
#define OUTPUT 1 

// value definition
#define HIGH 1
#define LOW 0

//error handling
typedef enum EN_Dio_error{
	OK=0,
	Dio_init_error,
    Dio_read_error,
    Dio_write_error,
	Dio_toggle_error,
	}EN_Dio_error;

// Functions prototypes
 EN_Dio_error Dio_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);
 EN_Dio_error Dio_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);
 EN_Dio_error Dio_toggle(uint8_t portNumber, uint8_t pinNumber);
 EN_Dio_error Dio_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value);



#endif /* DIO_H_ */
