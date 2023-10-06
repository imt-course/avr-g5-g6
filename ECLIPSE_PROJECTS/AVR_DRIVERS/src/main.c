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

volatile counter = 0;

void Handler_Tim0_Ovf (void)
{
    TCNT0 = 6;
    counter++;
}

int main (void)
{
    Dio_SetPinMode(DIO_PORTA, DIO_PIN0, DIO_MODE_OUTPUT);
    Gpt_Init();
    TCNT0 = 6;
    Gpt_EnableInterrupt();
    Gpt_SetCallback(Handler_Tim0_Ovf);
    Gie_Enable();
    while (1)
    {
        if (counter == 4000)
        {
            counter = 0;
            Dio_FlipPinLevel(DIO_PORTA, DIO_PIN0);
        }

    }
    
    
}
