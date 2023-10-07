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

volatile counter = 0;

void Handler_Tim0_Comp (void)
{
    counter++;
}

int main (void)
{
    u8 i;
    Pwm_Init(&Pwm_Configuration);
    while (1)
    {
        for (i=0; i<=100; i+=10)
        {
            Pwm_SetDutyCycle(PWM_OUT_OC0, i);
            _delay_ms(250);
        }
    }
    
    
    
}
