/*
 * TM.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Hamdi
 */

#ifndef TM_H_
#define TM_H_

#include <stdint.h>

#include "MainAPP/Common/component.h"

void TMDeviceTypeconfig(Devicetype Deviceconfig); //  function to configure the device type

uint8_t *TMResultTest(Devicetype Deviceconfig); //  function to get the test result

#endif /* INC_MAINAPP_TM_TM_H_ */
