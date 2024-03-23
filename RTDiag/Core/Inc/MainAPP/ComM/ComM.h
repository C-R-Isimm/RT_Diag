/*
 * ComM.h
 *
 *  Created on: Feb 22, 2024
 *      Author: garab
 */

#ifndef SRC_MAINAPP_COMM_COMM_H_

#define SRC_MAINAPP_COMM_COMM_H_

#include"MainAPP/Common/component.h"

#include <stdint.h>

void ComMReadSensorValue(Devicetype Device);

void ComMConfigDevice(Devicetype Device);

void Error_Handler(void);

#endif /* SRC_MAINAPP_COMM_COMM_H_ */
