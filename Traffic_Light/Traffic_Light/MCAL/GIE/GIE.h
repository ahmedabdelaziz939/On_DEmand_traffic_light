/*
 * GIE.h
 *
 * Created: 12/09/2022 21:47:33
 *  Author: Ahmed
 */ 


// All internal driver typedefs
// all driver macros
// all driver function prototypes
// 1. function to enable GIE
// 2. function to disable GIE



#ifndef GIE_H_
#define GIE_H_

#include "../../Utilities/register.h"

//define SREG BIT
#define  SREG_I      7


void GIE_enable(void);
void GIE_disable(void);


#endif /* GIE_H_ */