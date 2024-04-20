/*
 * ComM.h
 *
 *  Created on: Feb 22, 2024
 *      Author: garab
 */

#ifndef SRC_MAINAPP_COMM_H_
#define SRC_MAINAPP_COMM_H_

#include"MainAPP/Common/component.h"

#include "main.h"

uint32_t ComMReadSensorValue(Devicetype Device);

void ComMConfigDevice(Devicetype Device);

typedef enum {
	input ,
	output,
} GPIOMode;

#endif /* SRC_MAINAPP_COMM_COMM_H_ */
