/*
 * UIM.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Hamdi
 */

#ifndef INC_MAINAPP_UIM_UIM_H_
#define INC_MAINAPP_UIM_UIM_H_

#include "stm32f4xx_hal.h"
#include "stdint.h"

// Function declarations
void UIM_Init(void);
void UIM_Transmit(uint8_t *data, uint16_t length);
void UIM_Receive(uint8_t *buffer, uint16_t length);

#endif /* INC_MAINAPP_UIM_UIM_H_ */
