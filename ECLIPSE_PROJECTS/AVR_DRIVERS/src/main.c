/*
 * main.c
 *
 *  Created on: Sep 15, 2023
 *      Author: ahmad
 */

#include "StdTypes.h"
#include "Registers.h"
#include "Delay.h"
#include "Dio.h"
#include "Lcd.h"
#include "Keypad.h"
#include "Interrupts.h"
#include "Gie.h"
#include "ExtInt.h"
#include "Adc.h"
#include "Lm35.h"
#include "Gpt.h"
#include "Pwm.h"
#include "Icu.h"
#include "Wdt.h"
#include "Uart.h"

void Uart_ReceiveHandler (u8 data)
{
    Uart_Transmit(data);
}

int main (void)
{
    Uart_Init();
    Uart_EnableInterrupt(UART_INT_SOURCE_RX);
    Uart_SetReceiveCallback(Uart_ReceiveHandler);
    Gie_Enable();
    Uart_Print("Hello %d %c %f\n", 5, 65, 32.3); // Hello 5 a 32.30
    Uart_Print("New line \n");
    while (1)
    {

    }
    
}
