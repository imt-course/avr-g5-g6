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
int main (void)
{
    u16 result;
    u8 counter;
    Adc_Init(&Adc_Configuration);
    Lcd_Init(&Lcd_Configuration);
    while (1)
    {
        Lcd_ClearDisplay();
        result = Lm35_GetTemperature(LM35_CHANNEL, 10, 1);
        Lcd_DisplayString("Temp = ");
        Lcd_DisplayNumber(result);
        Lcd_DisplayString(" C");
        result = 0;
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
