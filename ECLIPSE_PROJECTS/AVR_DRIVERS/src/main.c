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
    //Dio_SetPinMode(DIO_PORTA, DIO_PIN0, DIO_MODE_INPUT_FLOATING);
    Adc_Init();
    Lcd_Init(&Lcd_Configuration);
    while (1)
    {
        Adc_StartConversion();
        result = Adc_GetResult();
        Lcd_ClearDisplay();
        Lcd_DisplayNumber(result);
        _delay_ms(500);
    }
    
}
