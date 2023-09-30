/*
 * main.c
 *
 *  Created on: Sep 15, 2023
 *      Author: ahmad
 */

#include "StdTypes.h"
#include "Delay.h"
#include "Dio.h"
#include "Lcd.h"
#include "Keypad.h"
#include "Interrupts.h"
#include "Gie.h"
#include "ExtInt.h"
#include "Adc.h"
#include "Lm35.h"

#define LM35_CHANNEL    ADC_CHANNEL_ADC0
#define LDR_CHANNEL     ADC_CHANNEL_ADC1

volatile u8 counter = 0;
volatile u16 resultAvg = 0;

void Handler_ADC (u16 result)
{
    resultAvg += result;
    counter++;
}

int main (void)
{
    Adc_Init(&Adc_Configuration);
    Lcd_Init(&Lcd_Configuration);
    Adc_SetCallback(Handler_ADC);
    Adc_EnableInterrupt();
    Gie_Enable();
    while (1)
    {
        Adc_StartConversion(LDR_CHANNEL);
        if (counter == 10)
        {
            Lcd_ClearDisplay();
            Lcd_DisplayNumber(resultAvg / 10);
            counter = 0;
            resultAvg = 0;
        }
        _delay_ms(500);
    }
    
}
