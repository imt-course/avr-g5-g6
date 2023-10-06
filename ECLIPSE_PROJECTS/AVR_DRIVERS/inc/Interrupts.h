/*
 * Interrupts.h
 *
 *  Created on: Sep 23, 2023
 *      Author: ahmad
 */

#ifndef INC_INTERRUPTS_H_
#define INC_INTERRUPTS_H_

#define ISR(vector) void vector (void) __attribute__((signal));\
void vector (void)

#define VECTOR_INT0         __vector_1
#define VECTOR_INT1         __vector_2
#define VECTOR_INT2         __vector_3
#define VECTOR_ADC          __vector_16
#define VECTOR_TIM0_OVF     __vector_11
#define VECTOR_TIM0_COMP    __vector_10

#endif /* INC_INTERRUPTS_H_ */
