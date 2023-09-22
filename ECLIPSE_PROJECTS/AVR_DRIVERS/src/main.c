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
    Lcd_Init(&Lcd_Configuration);
    Lcd_DisplayString("Ahmed ");
    while (1)
    {
        
    }
    
}
