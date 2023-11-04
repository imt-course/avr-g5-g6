/*
 * Schduler.c
 *
 *  Created on: Nov 3, 2023
 *      Author: ahmad
 */

#include "StdTypes.h"
#include "Scheduler_Cfg.h"
#include "Scheduler.h"

typedef struct 
{
    void (*funcPtr) (void);
    u32 periodicity;
    u32 delay;
    boolean active;
    boolean ready;
}Scheduler_TaskType;

Scheduler_TaskType Tasks[SCHEDULER_MAX_TASKS];

static void Scheduler_UpdateTasks(void);
extern void Scheduler_InitializeTimer(void (*timerCallback) (void));

void Scheduler_Init(void)
{
    u8 loopCounter;
    for (loopCounter=0; loopCounter<SCHEDULER_MAX_TASKS; loopCounter++)
    {
        Tasks[loopCounter].funcPtr = NULL_PTR;
        Tasks[loopCounter].periodicity = 0;
        Tasks[loopCounter].delay = 0;
        Tasks[loopCounter].active = FALSE;
    }
}

u8 Scheduler_AddTask(void (*funcPtr) (void), u32 periodicity, u32 delay)
{
    u8 loopCounter;
    for (loopCounter=0; loopCounter<SCHEDULER_MAX_TASKS; loopCounter++)
    {
        if (Tasks[loopCounter].funcPtr == NULL_PTR)
        {
            Tasks[loopCounter].funcPtr = funcPtr;
            Tasks[loopCounter].periodicity = periodicity;
            Tasks[loopCounter].delay = delay;
            Tasks[loopCounter].active = TRUE;
            break;
        }
    }
    return loopCounter;
}

StdReturnType Scheduler_DeleteTask(u8 taskIndex)
{
    StdReturnType retVal;
    if (taskIndex < SCHEDULER_MAX_TASKS)
    {
        Tasks[taskIndex].funcPtr = NULL_PTR;
        Tasks[taskIndex].periodicity = 0;
        Tasks[taskIndex].delay = 0;
        Tasks[taskIndex].active = FALSE;
        retVal = E_OK;
    }
    else
    {
        retVal = E_NOT_OK;
    }
    return retVal;
}

StdReturnType Scheduler_SuspendTask(u8 taskIndex)
{
    StdReturnType retVal;
    if (taskIndex < SCHEDULER_MAX_TASKS)
    {
        Tasks[taskIndex].active = FALSE;
        retVal = E_OK;
    }
    else
    {
        retVal = E_NOT_OK;
    }
    return retVal;
}

StdReturnType Scheduler_ResumeTask(u8 taskIndex)
{
    StdReturnType retVal;
    if (taskIndex < SCHEDULER_MAX_TASKS)
    {
        Tasks[taskIndex].active = TRUE;
        retVal = E_OK;
    }
    else
    {
        retVal = E_NOT_OK;
    }
    return retVal;
}

void Scheduler_Start(void)
{
    Scheduler_InitializeTimer(Scheduler_UpdateTasks);
}

void Scheduler_Dispatch(void)
{
    u8 loopCounter;
    while (1)
    {
        for(loopCounter=0; loopCounter<SCHEDULER_MAX_TASKS; loopCounter++)
        {
            if ((Tasks[loopCounter].funcPtr != NULL_PTR) 
             && (Tasks[loopCounter].active == TRUE)
             && (Tasks[loopCounter].ready == TRUE))
            {
                Tasks[loopCounter].ready = FALSE;
                Tasks[loopCounter].funcPtr();
                if (Tasks[loopCounter].periodicity == 0)
                {
                    Scheduler_DeleteTask(loopCounter);
                }
            }
        }
    }
}

static void Scheduler_UpdateTasks(void)
{
    u8 loopCounter;
    for(loopCounter=0; loopCounter<SCHEDULER_MAX_TASKS; loopCounter++)
    {
        if ((Tasks[loopCounter].funcPtr != NULL_PTR) && (Tasks[loopCounter].active == TRUE))
        {
            if (Tasks[loopCounter].delay == 0)
            {
                Tasks[loopCounter].ready = TRUE;
                Tasks[loopCounter].delay = Tasks[loopCounter].periodicity;
            }
            Tasks[loopCounter].delay--;
        }
    }
}