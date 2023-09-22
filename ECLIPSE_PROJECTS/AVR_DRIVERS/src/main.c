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


int main (void)
{
    u8 count = 0;
    Lcd_Init(&Lcd_Configuration);
    Lcd_DisplayString("My name is Ahmed Hassan");
    Lcd_SetCursorPosition(1,5);
    Lcd_DisplayString("Thank you --- ");
    while (1)
    {
        _delay_ms(500);
        Lcd_ShiftDisplayLeft(1);
        count++;
        if (count > 8)
        {
            Lcd_ReturnHome();
            count = 0;
        }
    }
    
}
