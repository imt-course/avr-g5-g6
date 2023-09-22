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


int main (void)
{
    Keypad_ButtonType counter;
    Lcd_Init(&Lcd_Configuration);
    Keypad_Init();
    while (1)
    {
        for (counter = KEYPAD_B00; counter <= KEYPAD_B15; counter++)
        {
            if(Keypad_GetButtonState(counter) == KEYPAD_PRESSED)
            {
                Lcd_DisplayNumber(counter);
            }
        }
    }
    
    
}
