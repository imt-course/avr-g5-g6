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
    /*Dio_SetPinMode(DIO_PORTA, DIO_PIN1, DIO_MODE_OUTPUT);
    Dio_SetPinMode(DIO_PORTA, DIO_PIN2, DIO_MODE_OUTPUT);
    Dio_SetPinMode(DIO_PORTA, DIO_PIN3, DIO_MODE_OUTPUT);
    Dio_SetPinMode(DIO_PORTA, DIO_PIN4, DIO_MODE_OUTPUT);
    while (1)
    {
        Dio_SetPinLevel(DIO_PORTA, DIO_PIN1, DIO_HIGH);
        Dio_SetPinLevel(DIO_PORTA, DIO_PIN2, DIO_LOW);
        Dio_SetPinLevel(DIO_PORTA, DIO_PIN3, DIO_LOW);
        Dio_SetPinLevel(DIO_PORTA, DIO_PIN4, DIO_HIGH);
        _delay_ms(1000);
        Dio_SetPinLevel(DIO_PORTA, DIO_PIN1, DIO_LOW);
        Dio_SetPinLevel(DIO_PORTA, DIO_PIN2, DIO_HIGH);
        Dio_SetPinLevel(DIO_PORTA, DIO_PIN3, DIO_HIGH);
        Dio_SetPinLevel(DIO_PORTA, DIO_PIN4, DIO_LOW);
        _delay_ms(1000);
    }*/
    /*
    Dio_SetPinMode(DIO_PORTA, DIO_PIN1, DIO_MODE_OUTPUT);
    while (1)
    {
        Dio_SetPinLevel(DIO_PORTA, DIO_PIN1, DIO_HIGH);
        _delay_ms(1000);
        Dio_SetPinLevel(DIO_PORTA, DIO_PIN1, DIO_LOW);
        _delay_ms(1000);
    }
    */
   
    u16 value = 0;
    Pwm_Init(&Pwm_Configuration);
    while (1)
    {
        Pwm_SetTimeOn(PWM_OUT_OC1A, value / 2);
        Pwm_SetICR1(value);
        value += 1000;
        _delay_ms(1000);
    }
    
    
}
