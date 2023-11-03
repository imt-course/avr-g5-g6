/*
 * Gie.h
 *
 *  Created on: Sep 23, 2023
 *      Author: ahmad
 */

#ifndef INC_GIE_H_
#define INC_GIE_H_

#include "StdTypes.h"

/* Set Bit 7 in SREG Register */
#define Gie_Enable() *((volatile u8*) 0x5F) |= 0x80
/* Clr Bit 7 in SREG Register */
#define Gie_Disable() *((volatile u8*) 0x5F) &= 0x7F

#endif /* INC_GIE_H_ */
