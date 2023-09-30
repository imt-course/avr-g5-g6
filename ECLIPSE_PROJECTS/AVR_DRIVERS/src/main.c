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



int main (void)
{
    Dio_SetPinMode(DIO_PORTA, DIO_PIN0, DIO_MODE_OUTPUT);
    Dio_SetPinMode(DIO_PORTA, DIO_PIN1, DIO_MODE_OUTPUT);
    while (1)
    {
        Dio_FlipPinLevel(DIO_PORTA, DIO_PIN0);
        Dio_FlipPinLevel(DIO_PORTA, DIO_PIN1);
        _delay_ms(1000);
    }
    
}
