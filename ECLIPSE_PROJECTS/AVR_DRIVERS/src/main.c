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

volatile u32 T_on = 0;
volatile u32 T_total = 0;

void ExtInt_Handler (void)
{
    static u8 state = 1;
    if (state == 1) 
    {
        Gpt_SetCounterValue(GPT_CHANNEL_TIM0, 0);
        ExtInt_SetSenseControl(EXTINT_SOURCE_INT0, EXTINT_SENSE_FALLING_EDGE);
        state = 2;
    }
    else if (state == 2) 
    {
        T_on = Gpt_GetElapsedTime(GPT_CHANNEL_TIM0);
        ExtInt_SetSenseControl(EXTINT_SOURCE_INT0, EXTINT_SENSE_RISING_EDGE);
        state = 3;
    }
    else if (state == 3) 
    {
        T_total = Gpt_GetElapsedTime(GPT_CHANNEL_TIM0);
        state = 1;
    }
    else
    {
        /* Do Nothing. */
    }
}


int main (void)
{
    Lcd_Init(&Lcd_Configuration);
    Gpt_Init(&Gpt_Configuration);
    Pwm_Init(&Pwm_Configuration);
    Pwm_SetTimeOn(PWM_CH1, 1000);
    Pwm_SetICR1(5000);
    Dio_SetPinMode(EXTINT_PIN_INT0, DIO_MODE_INPUT_FLOATING);
    ExtInt_SetSenseControl(EXTINT_SOURCE_INT0, EXTINT_SENSE_RISING_EDGE);
    ExtInt_EnableInterrupt(EXTINT_SOURCE_INT0);
    ExtInt_SetCallback(EXTINT_SOURCE_INT0, ExtInt_Handler);
    Gie_Enable();
    while (1)
    {
        Lcd_DisplayString("T_on = ");
        Lcd_DisplayNumber(T_on);
        Lcd_SetCursorPosition(1,0);
        Lcd_DisplayString("T_total = ");
        Lcd_DisplayNumber(T_total);
        _delay_ms(500);
        Lcd_ClearDisplay();
    }
}
