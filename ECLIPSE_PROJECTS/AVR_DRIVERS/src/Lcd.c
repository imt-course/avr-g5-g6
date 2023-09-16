/*
 * Lcd.c
 *
 *  Created on: Sep 16, 2023
 *      Author: ahmad
 */

#include "StdTypes.h"
#include "Macros.h"
#include "Dio.h"
#include "Delay.h"
#include "Lcd_Cfg.h"
#include "Lcd.h"


void Lcd_Init(void)
{
    /* Set LCD Pins to Output */
    Dio_SetPinMode(LCD_PIN_RS, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_RW, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_EN, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D0, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D1, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D2, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D3, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D4, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D5, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D6, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D7, DIO_MODE_OUTPUT);
    /* Function Set (N=1: 2 Lines, F=0: 5x7) (0 0 1 1 N F X X) */
    Lcd_SendCommand(0b00111000);
    /* Display Control (D=1: Display ON, C=1: Cursor ON, B=1, Cursor Blinks) (0 0 0 0 1 D C B) */
    Lcd_SendCommand(0b00001111);
    /* Display Clear */
    Lcd_SendCommand(0b00000001);
}

void Lcd_SendData (u8 data)
{
    Dio_SetPinLevel(LCD_PIN_RS, DIO_HIGH);
    Dio_SetPinLevel(LCD_PIN_RW, DIO_LOW);
    Dio_SetPinLevel(LCD_PIN_D0, GET_BIT(data, 0));
    Dio_SetPinLevel(LCD_PIN_D1, GET_BIT(data, 1));
    Dio_SetPinLevel(LCD_PIN_D2, GET_BIT(data, 2));
    Dio_SetPinLevel(LCD_PIN_D3, GET_BIT(data, 3));
    Dio_SetPinLevel(LCD_PIN_D4, GET_BIT(data, 4));
    Dio_SetPinLevel(LCD_PIN_D5, GET_BIT(data, 5));
    Dio_SetPinLevel(LCD_PIN_D6, GET_BIT(data, 6));
    Dio_SetPinLevel(LCD_PIN_D7, GET_BIT(data, 7));
    Dio_SetPinLevel(LCD_PIN_EN, DIO_HIGH);
    _delay_ms(2);
    Dio_SetPinLevel(LCD_PIN_EN, DIO_LOW);  
}

void Lcd_SendCommand (u8 command)
{
    Dio_SetPinLevel(LCD_PIN_RS, DIO_LOW);
    Dio_SetPinLevel(LCD_PIN_RW, DIO_LOW);
    Dio_SetPinLevel(LCD_PIN_D0, GET_BIT(command, 0));
    Dio_SetPinLevel(LCD_PIN_D1, GET_BIT(command, 1));
    Dio_SetPinLevel(LCD_PIN_D2, GET_BIT(command, 2));
    Dio_SetPinLevel(LCD_PIN_D3, GET_BIT(command, 3));
    Dio_SetPinLevel(LCD_PIN_D4, GET_BIT(command, 4));
    Dio_SetPinLevel(LCD_PIN_D5, GET_BIT(command, 5));
    Dio_SetPinLevel(LCD_PIN_D6, GET_BIT(command, 6));
    Dio_SetPinLevel(LCD_PIN_D7, GET_BIT(command, 7));
    Dio_SetPinLevel(LCD_PIN_EN, DIO_HIGH);
    _delay_ms(2);
    Dio_SetPinLevel(LCD_PIN_EN, DIO_LOW);  
}


void Lcd_ClearDisplay (void)
{
    Lcd_SendCommand(0b00000001);
}