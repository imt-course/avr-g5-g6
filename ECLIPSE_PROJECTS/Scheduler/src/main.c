/*
 * main.c
 *
 *  Created on: Nov 3, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Dio.h"
#include "Scheduler.h"

#define LED_PIN_1   DIO_PORTA,DIO_PIN0
#define LED_PIN_2   DIO_PORTA,DIO_PIN1
#define LED_PIN_3   DIO_PORTA,DIO_PIN2

void InitTask(void)
{
    Dio_SetPinMode(LED_PIN_1, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LED_PIN_2, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LED_PIN_3, DIO_MODE_OUTPUT);
}
void Task1 (void)
{
    Dio_FlipPinLevel(LED_PIN_1);
}

void Task2 (void)
{
    Dio_FlipPinLevel(LED_PIN_2);
}

void Task3 (void)
{
    Dio_FlipPinLevel(LED_PIN_3);
}


int main (void)
{
    Scheduler_Init();
    Scheduler_AddTask(InitTask, 0, 0); // One Shot Task
    Scheduler_AddTask(Task1, 1000, 0);
    Scheduler_AddTask(Task2, 1000, 0);
    Scheduler_AddTask(Task3, 1000, 0);
    Scheduler_Start();
    Scheduler_Dispatch();
}
