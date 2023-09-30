/*
 * Adc.h
 *
 *  Created on: Sep 29, 2023
 *      Author: ahmad
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "StdTypes.h"

void Adc_Init (void);
void Adc_StartConversion (void);
u16 Adc_GetResult (void);

#endif /* INC_ADC_H_ */
