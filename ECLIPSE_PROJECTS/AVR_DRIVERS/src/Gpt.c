/*
 * Gpt.c
 *
 *  Created on: Oct 6, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Macros.h"
#include "Registers.h"
#include "Interrupts.h"
#include "Gpt.h"

static void (*Callback_Gpt_TIM0_OVF) (void) = NULL_PTR;

ISR(VECTOR_TIM0_OVF)
{
    if (NULL_PTR != Callback_Gpt_TIM0_OVF)
    {
        Callback_Gpt_TIM0_OVF();
    }
}

void Gpt_Init(void)
{
    /* Waveform Generation Mode: Normal */
    CLR_BIT(TCCR0, 3);
    CLR_BIT(TCCR0, 6);
    /* Clock Select: Prescaler 8 */
    CLR_BIT(TCCR0, 0);
    SET_BIT(TCCR0, 1);
    CLR_BIT(TCCR0, 2);
}

void Gpt_EnableInterrupt(void)
{
    SET_BIT(TIMSK, 0);
}

void Gpt_DisableInterrupt(void)
{
    CLR_BIT(TIMSK, 0);
}

void Gpt_SetCallback(void (*callbackPtr) (void))
{
    Callback_Gpt_TIM0_OVF = callbackPtr;
}
