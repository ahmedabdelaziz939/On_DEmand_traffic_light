/*
 * DIO.c
 *
 * Created: 02/09/2022 13:12:14
 *  Author: Ahmed
 */ 

// include.h files
//global variables
// function definitions 




#include "dio.h"


EN_Dio_error Dio_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)
{
	switch(portNumber){
		case PORT_A:
		if(direction==INPUT){
			DDRA &=~(1<<pinNumber);  // make pin input
			return OK;
		}else if(direction==OUTPUT){
			DDRA |=(1<<pinNumber);   // make pin output
			return OK;
		}else{
          return Dio_init_error;		// error handling
		}
		break;
		case PORT_B:
		if(direction==INPUT){
			DDRB &=~(1<<pinNumber);  // make pin input
			return OK;
			}else if(direction==OUTPUT){
			DDRB |=(1<<pinNumber); //make pin output
			return OK;
			}else{
            return Dio_init_error;			// error handling
		}
		break;
		case PORT_C:
		if(direction==INPUT){
			DDRC &=~(1<<pinNumber);     // make pin input
			return OK;
			}else if(direction==OUTPUT){
			DDRC |=(1<<pinNumber);    // make pin output
			return OK;
			}else{
		     return Dio_init_error;	// error handling
		}
		break;
		case PORT_D:
		if(direction==INPUT){
			DDRD &=~(1<<pinNumber);   //make pin input
			return OK;
			}else if(direction==OUTPUT){
			DDRD |=(1<<pinNumber);   //make pin output
			return OK;
			}else{
	        return Dio_init_error;		// error handling
		}
		break;
		default:
		return Dio_init_error;
		break;
		
	}
}
EN_Dio_error Dio_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value){
	switch(portNumber){
		case PORT_A:
		if(value==LOW){
			PORTA &=~(1<<pinNumber);  // write 0
		    return OK;
			}else if(value==HIGH){  
			PORTA |=(1<<pinNumber); //write 1
			return OK;
			}else{
			return Dio_write_error;   // error handling
		}
		break;
		case PORT_B:
		if(value==LOW){
			PORTB &=~(1<<pinNumber);   //write 0
			return OK;
			}else if(value==HIGH){
			PORTB |=(1<<pinNumber);   // write 1
			return OK;
			}else{
		return Dio_write_error;  	// error handling
		}
		break;
		case PORT_C:
		if(value==LOW){
			PORTC &=~(1<<pinNumber);  // write 0
			return OK;
			}else if(value==HIGH){
			PORTC |=(1<<pinNumber);   // write 1
			return OK;
			}else{
		return Dio_write_error;  	// error handling
		}
		break;
		case PORT_D:
		if(value==LOW){
			PORTD &=~(1<<pinNumber); // write 0
			}else if(value==HIGH){
			PORTD |=(1<<pinNumber);  // write 1
			}else{
		return Dio_write_error; 	 // error handling
		}
		break;
		default:
	    return Dio_write_error;    // error
		break;
	}
}
EN_Dio_error Dio_toggle(uint8_t portNumber, uint8_t pinNumber){
	switch(portNumber){
		case PORT_A:
		PORTA ^=(1<<pinNumber);
		break;
		case PORT_B:
		PORTB ^=(1<<pinNumber);    
		break;
		case PORT_C:
		PORTC ^=(1<<pinNumber);
		break;
		case PORT_D:
		PORTD ^=(1<<pinNumber);
		break;
		default:
		return Dio_toggle_error;   // error
		break;
		
	}
}
EN_Dio_error Dio_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value){
	switch(portNumber){
		case PORT_A:
		*value=(PINA & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_B:
		*value=(PINB & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_C:
		*value=(PINC & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_D:
		*value=(PIND & (1<<pinNumber))>>pinNumber;
		break;
		default:
		 return Dio_read_error; // error
		break;
	}
}


