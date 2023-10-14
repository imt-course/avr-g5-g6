/*
 * main.c
 *
 *  Created on: Sep 15, 2023
 *      Author: ahmad
 */

#include "StdTypes.h"
#include "Registers.h"
#include "Delay.h"
#include "Dio.h"
#include "Lcd.h"
#include "Keypad.h"
#include "Interrupts.h"
#include "Gie.h"
#include "ExtInt.h"
#include "Adc.h"
#include "Lm35.h"
#include "Gpt.h"
#include "Pwm.h"
#include "Icu.h"
#include "Wdt.h"


int main (void)
{
    Dio_SetPinMode(DIO_PORTA, DIO_PIN0, DIO_MODE_OUTPUT);
    Dio_SetPinLevel(DIO_PORTA, DIO_PIN0, DIO_HIGH);
    _delay_ms(1000);
    Dio_SetPinLevel(DIO_PORTA, DIO_PIN0, DIO_LOW);
    Wdt_Refresh(WDT_TIMEOUT_1000_MS);
    while (1)
    {
        _delay_ms(1100);
        Wdt_Refresh(WDT_TIMEOUT_1000_MS);
    }
}
