/*
 * Adc.c
 *
 *  Created on: Sep 29, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Registers.h"
#include "Macros.h"
#include "Interrupts.h"
#include "Adc.h"

void Adc_Init (void)
{
    /* Reference Selection Bits */
    SET_BIT(ADMUX, 6);
    CLR_BIT(ADMUX, 7);
    /*  ADC Left Adjust Result (OFF) */
    CLR_BIT(ADMUX, 5);
    /* ADC Channel ADC0 */
    CLR_BIT(ADMUX, 4);
    CLR_BIT(ADMUX, 3);
    CLR_BIT(ADMUX, 2);
    CLR_BIT(ADMUX, 1);
    CLR_BIT(ADMUX, 0);
    /* ADC Auto Trigger Enable (OFF) */
    CLR_BIT(ADCSRA, 5);
    /* ADC Prescaler Select Bits 128 */
    SET_BIT(ADCSRA, 0);
    SET_BIT(ADCSRA, 1);
    SET_BIT(ADCSRA, 2);
    /* ADC Enable */
    SET_BIT(ADCSRA, 7);
}

void Adc_StartConversion (void)
{
    /* Wait till current conversion completes */
    while (GET_BIT(ADCSRA, 6) == 1);
    /* Start new conversion */
    SET_BIT(ADCSRA, 6);
}

u16 Adc_GetResult (void)
{
    u16 result;
    /* Wait till current conversion completes */
    while (GET_BIT(ADCSRA, 4) == 0);
    /* Clear Flag */
    SET_BIT(ADCSRA, 4);
    /* Read Result */
    //result = ADCDATA & 0x3FF;
     result = ((ADCH<<8) | ADCL) & 0x3FF; // 0b0000001111111111
    return result;
}

