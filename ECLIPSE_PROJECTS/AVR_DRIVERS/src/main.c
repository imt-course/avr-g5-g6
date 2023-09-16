/*
 * main.c
 *
 *  Created on: Sep 15, 2023
 *      Author: ahmad
 */

#include "StdTypes.h"
#include "Dio.h"

#define LED_PIN         DIO_PORTA,DIO_PIN0
#define SWITCH_PIN      DIO_PORTA,DIO_PIN1


int main (void)
{
    Dio_LevelType currentState = DIO_HIGH;
    Dio_LevelType lastState = DIO_HIGH;
    
    /* Initialization */
    Dio_SetPinMode(LED_PIN, DIO_MODE_OUTPUT);
    Dio_SetPinMode(SWITCH_PIN, DIO_MODE_INPUT_PULLUP);
    while (1)
    {
        currentState = Dio_ReadPinLevel(SWITCH_PIN);
        if ((DIO_LOW == currentState) && (DIO_HIGH == lastState))
        {
            Dio_FlipPinLevel(LED_PIN);
        }
        lastState = currentState;
    }

}
