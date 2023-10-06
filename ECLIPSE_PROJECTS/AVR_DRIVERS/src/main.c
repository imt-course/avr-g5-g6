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

void Handler_Tim0_Comp (void)
{
    counter++;
}

int main (void)
{
    Dio_SetPinMode(DIO_PORTA, DIO_PIN0, DIO_MODE_OUTPUT);
    Dio_SetPinMode(GPT_PIN_OC0, DIO_MODE_OUTPUT);
    Gpt_Init(&Gpt_Configuration);
    Gpt_SetCompareValue(GPT_COMP0, 250);
    Gpt_EnableInterrupt(GPT_INT_SOURCE_TIM0_COMP);
    Gpt_SetCallback(GPT_INT_SOURCE_TIM0_COMP, Handler_Tim0_Comp);
    Gie_Enable();
    while (1)
    {
        if (counter == 500)
        {
            counter = 0;
            Dio_FlipPinLevel(DIO_PORTA, DIO_PIN0);
        }
    }
    
    
}
