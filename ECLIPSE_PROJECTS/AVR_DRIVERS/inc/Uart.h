/*
 * Uart.h
 *
 *  Created on: Oct 20, 2023
 *      Author: ahmad
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "StdTypes.h"
#include "Dio.h"

#define UART_PIN_RX DIO_PORTD,DIO_PIN0
#define UART_PIN_TX DIO_PORTD,DIO_PIN1

typedef enum {
    UART_INT_SOURCE_RX,
    UART_INT_SOURCE_TX,
    UART_INT_SOURCE_DATA_REG_EMPTY,
} Uart_InterruptSourceType;

void Uart_Init(void);
void Uart_Transmit(u8 data);
u8 Uart_Receive(void);
void Uart_EnableInterrupt(Uart_InterruptSourceType source);
void Uart_DisableInterrupt(Uart_InterruptSourceType source);
void Uart_SetCallback(Uart_InterruptSourceType source, void (*callbackPtr)(void));

#endif /* INC_UART_H_ */
