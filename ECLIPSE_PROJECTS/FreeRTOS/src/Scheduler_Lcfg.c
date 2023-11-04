/*
 * Scheduler_Lcfg.c
 *
 *  Created on: Nov 3, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Gpt.h"
#include "Gie.h"

/**
 * @brief - The function shall initialize the timer channel that will be used by scheduler
 * @brief - The timer channel used by scheduler shall not be used by any other application
 * @brief - Timer Interrupt Time will be tick time for scheduler
 * @param timerCallback: Function Pointer that will be used in Timer Interrupt
 * @return None
*/
void Scheduler_InitializeTimer(void (*timerCallback) (void))
{
    /**
     *  Set:
     *  - Prescaler = 64
     *  - Compare Value = 125
     *  - CPU Frequency 8MHz
     * Result: Compare Interrupt Time = 1ms (Scheduler Tick = 1ms)
    */
    Gpt_Init(&Gpt_Configuration);
    Gpt_SetCompareValue(GPT_COMP0, 125);
    Gpt_SetCallback(GPT_INT_SOURCE_TIM0_COMP, timerCallback);
    Gpt_EnableInterrupt(GPT_INT_SOURCE_TIM0_COMP);
    Gie_Enable();
}

