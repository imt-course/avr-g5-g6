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



int main (void)
{
    u16 i;
    Pwm_Init(&Pwm_Configuration);
    Pwm_SetICR1(20000);
    while (1)
    {
        for (i=300; i<=2300; i+=100)
        {
            Pwm_SetTimeOn(PWM_OUT_OC1A, i);
            _delay_ms(500);
        }
        for (i=2300; i>=300; i-=100)
        {
            Pwm_SetTimeOn(PWM_OUT_OC1A, i);
            _delay_ms(500);
        }
    }
}
