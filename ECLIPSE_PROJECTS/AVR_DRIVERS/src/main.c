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
#include "Uart.h"
#include "Spi.h"

#include "Spi_Cfg.h"
#if (SPI_CFG_MODE == SPI_MASTER)

void Uart_ReceiveHandler (u8 data)
{
    Uart_Transmit(data);
    (void)Spi_Transfer(data);
}

int main (void)
{
    Uart_Init();
    Spi_Init();
    Uart_EnableInterrupt(UART_INT_SOURCE_RX);
    Uart_SetReceiveCallback(Uart_ReceiveHandler);
    Gie_Enable();
    while (1)
    {

    }
}


#elif (SPI_CFG_MODE == SPI_SLAVE)

void Spi_ReceiveHandler (u8 data)
{
    Uart_Transmit(data);
}

int main (void)
{
    Uart_Init();
    Spi_Init();
    Spi_EnableInterrupt();
    Spi_SetCallback(Spi_ReceiveHandler);
    Gie_Enable();
    while (1)
    {

    }
}

#endif