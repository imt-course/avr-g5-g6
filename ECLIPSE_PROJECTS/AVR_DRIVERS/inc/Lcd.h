/*
 * Lcd.h
 *
 *  Created on: Sep 16, 2023
 *      Author: ahmad
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "StdTypes.h"

void Lcd_Init(void);
void Lcd_DisplayCharacter (u8 data);
void Lcd_DisplayString (char str[]);
void Lcd_DisplayNumber (s32 number);
void Lcd_ClearDisplay (void);

#endif /* INC_LCD_H_ */
