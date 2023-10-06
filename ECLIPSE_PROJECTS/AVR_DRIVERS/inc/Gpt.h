/*
 * Gpt.h
 *
 *  Created on: Oct 6, 2023
 *      Author: ahmad
 */

#ifndef INC_GPT_H_
#define INC_GPT_H_

void Gpt_Init(void);
void Gpt_EnableInterrupt(void);
void Gpt_DisableInterrupt(void);
void Gpt_SetCallback(void (*callbackPtr) (void));


#endif /* INC_GPT_H_ */
