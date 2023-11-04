/*
 * main.c
 *
 *  Created on: Nov 3, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Dio.h"
#include "Scheduler.h"

#define LED_PIN     DIO_PORTA,DIO_PIN0
#define LED_PIN2     DIO_PORTA,DIO_PIN2
#define BUTTON_PIN  DIO_PORTA,DIO_PIN1

u8 ledTaskIndex;
void InitTask(void)
{
    Dio_SetPinMode(LED_PIN, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LED_PIN2, DIO_MODE_OUTPUT);
    Dio_SetPinMode(BUTTON_PIN, DIO_MODE_INPUT_PULLUP);
}

void ButtonTask (void)
{
    if (Dio_ReadPinLevel(BUTTON_PIN) == DIO_LOW)
    {
        Scheduler_ResumeTask(ledTaskIndex);
    }
    else
    {
        Scheduler_SuspendTask(ledTaskIndex);
    }
}

void LedTask (void)
{
    Dio_FlipPinLevel(LED_PIN);
}

void LedTask2 (void)
{
    Dio_FlipPinLevel(LED_PIN2);
}

int main (void)
{
    Scheduler_Init();
    Scheduler_AddTask(InitTask, 0, 0); // One Shot Task
    //Scheduler_AddTask(ButtonTask, 100, 0);
    ledTaskIndex = Scheduler_AddTask(LedTask, 1000, 0);
    Scheduler_AddTask(LedTask2, 500, 1000);
    Scheduler_Start();
    Scheduler_Dispatch();
}
