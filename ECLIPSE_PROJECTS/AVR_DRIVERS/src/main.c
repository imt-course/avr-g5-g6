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

volatile u32 T_on = 0;
volatile u32 T_total = 0;
volatile u32 overflow_counter = 0;

void Timer_Handler (void)
{
    overflow_counter++;
}

void Icu_Handler (u16 value)
{
    static u8 state = 1;
    static u16 tempValue;
    if (state == 1) 
    {
        Icu_SetTriggerEdge(ICU_EDGE_FALLING);
        overflow_counter = 0;
        tempValue= value;
        state = 2;
    }
    else if (state == 2) 
    {
        T_on = value + overflow_counter*0x10000 - tempValue;
        Icu_SetTriggerEdge(ICU_EDGE_RISING);
        state = 3;
    }
    else if (state == 3) 
    {
        T_total = value + overflow_counter*0x10000 - tempValue;
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
    Pwm_SetTimeOn(PWM_CH0, 90);
    Gpt_EnableInterrupt(GPT_INT_SOURCE_TIM1_OVF);
    Gpt_SetCallback(GPT_INT_SOURCE_TIM1_OVF, Timer_Handler);
    Dio_SetPinMode(ICU_PIN_ICP1, DIO_MODE_INPUT_FLOATING);
    Icu_SetTriggerEdge(ICU_EDGE_RISING);
    Icu_EnableInterrupt();
    Icu_SetCallback(Icu_Handler);
    Gie_Enable();
    while (1)
    {
        Lcd_Print("T_on = %ld", T_on);
        Lcd_SetCursorPosition(1,0);
        Lcd_Print("T_total = %ld", T_total);
        _delay_ms(500);
        Lcd_ClearDisplay();
    }
}
