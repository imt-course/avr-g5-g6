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


int main (void)
{
    u8 data;
    Uart_Init();
    while (1)
    {
        data = Uart_Receive();
        Uart_Transmit(data);
    }
    
}
