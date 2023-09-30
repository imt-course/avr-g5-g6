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

#define LM35_CHANNEL    ADC_CHANNEL_ADC0
#define LDR_CHANNEL     ADC_CHANNEL_ADC1
int main (void)
{
    u16 result;
    u8 counter;
    Adc_Init(&Adc_Configuration);
    Lcd_Init(&Lcd_Configuration);
    while (1)
    {
        Lcd_ClearDisplay();
        for (counter = 0; counter<10; counter++)
        {
            Adc_StartConversion(LM35_CHANNEL);
            result += Adc_GetResult();
        }
        result /= 10;
        Lcd_DisplayString("Temp = ");
        Lcd_DisplayNumber(((u32)result*500)/1024);
        Lcd_DisplayString(" C");
        for (counter = 0; counter<10; counter++)
        {
            Adc_StartConversion(LDR_CHANNEL);
            result += Adc_GetResult();
        }
        result /= 10;
        Lcd_SetCursorPosition(1,0);
        Lcd_DisplayString("LDR = ");
        Lcd_DisplayNumber(((u32)result*5000)/1024);
        _delay_ms(500);
    }
    
}
