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
    Lcd_Init();
    while (1)
    {
        Lcd_SendData('A');
        Lcd_SendData('h');
        Lcd_SendData('m');
        Lcd_SendData('e');
        Lcd_SendData('d');
        _delay_ms(1000);
        Lcd_ClearDisplay();
        _delay_ms(1000);
    }
}
