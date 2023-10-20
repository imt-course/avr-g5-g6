/*
 * Uart.c
 *
 *  Created on: Oct 20, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Macros.h"
#include "Registers.h"
#include "Fcpu.h"
#include "Dio.h"
#include "Uart_Cfg.h"
#include "Uart.h"

void Uart_Init(void)
{
    u8 tempVar = 0;
    u16 baudrateRegValue = 0;
    /* Receiver Enable */
#if (UART_CFG_RX_ENABLE == UART_ON)
    SET_BIT(UCSRB, 4);
    Dio_SetPinMode(UART_PIN_RX, DIO_MODE_OUTPUT);
#elif (UART_CFG_RX_ENABLE == UART_OFF)
    CLR_BIT(UCSRB, 4);
#else
#warning "Invalid Configuration for RX Enable, defaults to disabled"
    CLR_BIT(UCSRB, 4);
#endif

    /* Transmitter Enable */
#if (UART_CFG_TX_ENABLE == UART_ON)
    SET_BIT(UCSRB, 3);
    Dio_SetPinMode(UART_PIN_TX, DIO_MODE_OUTPUT);
#elif (UART_CFG_TX_ENABLE == UART_OFF)
    CLR_BIT(UCSRB, 3);
#else
#warning "Invalid Configuration for TX Enable, defaults to disabled"
    CLR_BIT(UCSRB, 3);
#endif

    /* Character Size*/
#if (UART_CFG_CHAR_SIZE == UART_CHAR_5_BIT)
    CLR_BIT(tempVar, 1);
    CLR_BIT(tempVar, 2);
    CLR_BIT(UCSRB, 2);
#elif (UART_CFG_CHAR_SIZE == UART_CHAR_6_BIT)
    SET_BIT(tempVar, 1);
    CLR_BIT(tempVar, 2);
    CLR_BIT(UCSRB, 2);
#elif (UART_CFG_CHAR_SIZE == UART_CHAR_7_BIT)
    CLR_BIT(tempVar, 1);
    SET_BIT(tempVar, 2);
    CLR_BIT(UCSRB, 2);
#elif (UART_CFG_CHAR_SIZE == UART_CHAR_8_BIT)
    SET_BIT(tempVar, 1);
    SET_BIT(tempVar, 2);
    CLR_BIT(UCSRB, 2);
#elif (UART_CFG_CHAR_SIZE == UART_CHAR_9_BIT)
    SET_BIT(tempVar, 1);
    SET_BIT(tempVar, 2);
    SET_BIT(UCSRB, 2);
#else
#warning "Invalid Configuration for Char Size, defaults to 8 Bit"
    SET_BIT(tempVar, 0);
    SET_BIT(tempVar, 1);
    CLR_BIT(UCSRB, 2);
#endif

    /* USART Mode Select: Asynchronous */
    CLR_BIT(tempVar, 6);

    /* Parity Mode */
#if (UART_CFG_PARITY == UART_PARITY_DISABLED)
    CLR_BIT(tempVar, 4);
    CLR_BIT(tempVar, 5);
#elif (UART_CFG_PARITY == UART_PARITY_EVEN)
    CLR_BIT(tempVar, 4);
    SET_BIT(tempVar, 5);
#elif (UART_CFG_PARITY == UART_PARITY_ODD)
    SET_BIT(tempVar, 4);
    SET_BIT(tempVar, 5);
#else
#warning "Invalid Configuration for Parity Mode, defaults to disabled"
    CLR_BIT(tempVar, 4);
    CLR_BIT(tempVar, 5);
#endif

    /* Stop Bit Select */
#if (UART_CFG_STOP_BITS == UART_STOP_BITS_1)
    CLR_BIT(tempVar, 3);
#elif (UART_CFG_STOP_BITS == UART_STOP_BITS_2)
    SET_BIT(tempVar, 3);
#else
#warning "Invalid Configuration for Stop Bit, defaults to 1"
    CLR_BIT(tempVar, 3);
#endif

    SET_BIT(tempVar, 7);
    UCSRC = tempVar;

/* Check Baudrate Range*/
#if ((UART_CFG_BAUDRATE >= F_CPU/65536) && (UART_CFG_BAUDRATE <= F_CPU/8))
/* Check Double Speed Mode*/
#if (UART_CFG_BAUDRATE > (F_CPU/16))
    SET_BIT(UCSRA, 1);
    baudrateRegValue = (F_CPU/(8*UART_CFG_BAUDRATE))-1;
#else
    baudrateRegValue = (F_CPU/(16*UART_CFG_BAUDRATE))-1;
#endif
    UBRRL = (u8)(baudrateRegValue&0xFF);
    UBRRH = (u8)((baudrateRegValue>>8)&0xF);
#else
#error "Invalid Baudrate Range"
#endif
}

void Uart_Transmit(u8 data)
{
    /* Wait for register empty */
    while(GET_BIT(UCSRA, 5) == 0);
    UDR = data;
    /* Wait for Tx Complete */
    while(GET_BIT(UCSRA, 6) == 0);
    /* Clear Flag */
    SET_BIT(UCSRA, 6);
}

u8 Uart_Receive(void)
{
    /* Wait for Rx Complete */
    while(GET_BIT(UCSRA, 7) == 0);
    /* Return Data */
    return UDR;
}

void Uart_EnableInterrupt(Uart_InterruptSourceType source)
{
    switch (source)
    {
    case UART_INT_SOURCE_RX:
        SET_BIT(UCSRB, 7);
        break;
    case UART_INT_SOURCE_TX:
        SET_BIT(UCSRB, 6);
        break;
    case UART_INT_SOURCE_DATA_REG_EMPTY:
        SET_BIT(UCSRB, 5);
        break;
    default:
        break;
    }
}

void Uart_DisableInterrupt(Uart_InterruptSourceType source)
{
    switch (source)
    {
    case UART_INT_SOURCE_RX:
        CLR_BIT(UCSRB, 7);
        break;
    case UART_INT_SOURCE_TX:
        CLR_BIT(UCSRB, 6);
        break;
    case UART_INT_SOURCE_DATA_REG_EMPTY:
        CLR_BIT(UCSRB, 5);
        break;
    default:
        break;
    }
}

void Uart_SetCallback(Uart_InterruptSourceType source, void (*callbackPtr)(void));
