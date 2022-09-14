/*
 * interrupt.h
 *
 * Created: 12/09/2022 21:39:37
 *  Author: Ahmed
 */ 

// All internal driver typedefs
// all driver macros
// all driver function prototypes
// 1. function to initialize EXTERNAL interrupt 0
// 2. function to initialize EXTERNAL interrupt 1
// 3. function to initialize EXTERNAL interrupt 2

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../Utilities/register.h"

/* define GICR bit */
#define  GICR_INT0   6
#define  GICR_INT1   7
#define  GICR_INT2   5

/*define MCUCR BIT */
#define MCUCR_ISC00  0
#define MCUCR_ISC01  1
#define MCUCR_ISC10  2
#define MCUCR_ISC11  3

/*define MCUCSR BIT */
#define MCUCSR_INT2  6



void EXTI_INT0_init(void);
void EXTI_INT1_init(void);
void EXTI_INT2_init(void);




#endif /* INTERRUPT_H_ */