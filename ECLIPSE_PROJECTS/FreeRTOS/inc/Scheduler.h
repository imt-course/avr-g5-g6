/*
 * Scheduler.h
 *
 *  Created on: Nov 3, 2023
 *      Author: ahmad
 */

#ifndef SCHEDULER_SCHEDULER_H_
#define SCHEDULER_SCHEDULER_H_

#include "StdTypes.h"


/**
 * @brief Initialze Scheduler
 * @param None
 * @return None
*/
void Scheduler_Init(void);

/**
 * @brief Add new task to the scheduler
 * @param funcPtr: Pointer to function needs to be executed in the task
 * @param periodicity: Periodicity of the added task (unit ticks), if 0: task is one shot task
 * @param delay: First delay the task will be executed after (unit ticks)
 * @return - Task Index (0 < value < SCHEDULER_MAX_TASKS)
 * @return - SCHEDULER_MAX_TASKS if there is no space in tasks array (task is not added)
*/
u8 Scheduler_AddTask(void (*funcPtr) (void), u32 periodicity, u32 delay);

/**
 * @brief Delete recently added task from scheduler
 * @param taskIndex: Task Index returned by Scheduler_AddTask Function
 * @return - E_OK: if task index is valid (taskIndex<SCHEDULER_MAX_TASKS)
 * @return - E_OK: if task index is invalid (taskIndex>=SCHEDULER_MAX_TASKS)
*/
StdReturnType Scheduler_DeleteTask(u8 taskIndex);

/**
 * @brief Suspend recently added task from scheduler
 * @param taskIndex: Task Index returned by Scheduler_AddTask Function
 * @return - E_OK: if task index is valid (taskIndex<SCHEDULER_MAX_TASKS)
 * @return - E_OK: if task index is invalid (taskIndex>=SCHEDULER_MAX_TASKS)
*/
StdReturnType Scheduler_SuspendTask(u8 taskIndex);

/**
 * @brief Resume recently added task from scheduler
 * @param taskIndex: Task Index returned by Scheduler_AddTask Function
 * @return - E_OK: if task index is valid (taskIndex<SCHEDULER_MAX_TASKS)
 * @return - E_OK: if task index is invalid (taskIndex>=SCHEDULER_MAX_TASKS)
*/
StdReturnType Scheduler_ResumeTask(u8 taskIndex);

/**
 * @brief Start timer so the scheduler begins updating tasks 
 * @param None
 * @return None
*/
void Scheduler_Start(void);

/**
 * @brief - Run Scheduler Alogorithms to execute tasks 
 * @brief - Note: Apllication shall not ever return from this function
 * @param None
 * @return None
*/
void Scheduler_Dispatch(void);


#endif /* SCHEDULER_SCHEDULER_H_ */
