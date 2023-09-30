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

int main (void)
{
    u16 result;
    Adc_Init(&Adc_Configuration);
    Lcd_Init(&Lcd_Configuration);
    while (1)
    {
        Adc_StartConversion(ADC_CHANNEL_ADC0);
        result = Adc_GetResult();
        Lcd_ClearDisplay();
        Lcd_DisplayNumber(((u32)result*5000)/1024);
        _delay_ms(500);
    }
    
}
