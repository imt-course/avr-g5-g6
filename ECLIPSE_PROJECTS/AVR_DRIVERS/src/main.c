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

#define LED_PIN DIO_PORTA,DIO_PIN0
#define LED2_PIN DIO_PORTA,DIO_PIN1

volatile u8 counter = 0;

void SwitchHandler (void);
void Handler2 (void);

void Handler2 (void)
{
    Dio_FlipPinLevel(LED2_PIN);
    counter++;
    if (counter == 5)
    {
        counter = 0;
        ExtInt_SetCallback(EXTINT_SOURCE_INT0, NULL_PTR);
    }

}
void SwitchHandler (void)
{
    Dio_FlipPinLevel(LED_PIN);
    counter++;
    if (counter == 5)
    {
        counter = 0;
        ExtInt_SetCallback(EXTINT_SOURCE_INT0, Handler2);
    }
}


int main (void)
{
    Dio_SetPinMode(LED_PIN, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LED2_PIN, DIO_MODE_OUTPUT);
    Dio_SetPinMode(EXTINT_PIN_INT0, DIO_MODE_INPUT_PULLUP);
    ExtInt_SetSenseControl(EXTINT_SOURCE_INT0, EXTINT_SENSE_ON_CHANGE);
    ExtInt_SetCallback(EXTINT_SOURCE_INT0, SwitchHandler);
    ExtInt_EnableInterrupt(EXTINT_SOURCE_INT0);
    Gie_Enable();
    while (1)
    {
        
    }
}
