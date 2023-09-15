/*
 * main.c
 *
 *  Created on: Sep 15, 2023
 *      Author: ahmad
 */

#include "StdTypes.h"
#include "Dio.h"

#define LED_PIN         DIO_PORTA,DIO_PIN0
#define SWITCH_PIN      DIO_PORTA,DIO_PIN0


int main (void)
{
    /* Initialization */
    Dio_SetPinMode(LED_PIN, DIO_MODE_OUTPUT);
    Dio_SetPinMode(SWITCH_PIN, DIO_MODE_INPUT_PULLUP);
    while (1)
    {
        /* Switch is pressed */
        if (DIO_LOW == Dio_ReadPinLevel(SWITCH_PIN))
        {
            Dio_SetPinLevel(LED_PIN, DIO_HIGH);
        }
        /* Switch is not pressed */
        else 
        {
            Dio_SetPinLevel(LED_PIN, DIO_LOW);
        }
    }

}
