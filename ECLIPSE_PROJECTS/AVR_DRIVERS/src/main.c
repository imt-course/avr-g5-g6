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


ISR(VECTOR_INT0)
{
    Dio_FlipPinLevel(LED_PIN);
}

/*
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
    Dio_FlipPinLevel(LED_PIN);
}
*/

int main (void)
{
    Dio_SetPinMode(LED_PIN, DIO_MODE_OUTPUT);
    Dio_SetPinMode(EXTINT_PIN_INT0, DIO_MODE_INPUT_PULLUP);
    ExtInt_SetSenseControl(EXTINT_SOURCE_INT0, EXTINT_SENSE_FALLING_EDGE);
    ExtInt_EnableInterrupt(EXTINT_SOURCE_INT0);
    Gie_Enable();
    while (1)
    {
        
    }
}
