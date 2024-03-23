/**
 * FSM.h
 *
 *  Created on: Mar 19, 2024
 *      Author: Chayma
 */
#ifndef FSM_H_
#define FSM_H_

#include <stdbool.h>




typedef enum 			//states of the finite state machine
{
	IDLE,				//idle state
	DeviceConfig,		//configuration state
	DeviceTest,			//device testing state
	ErrorHandler,		//error diagnostic state
    PassState 			//device passed state
} state;


//Events function 
int8_t Read_input(int8_t * input);
bool configDevice(Devicetype device);




#endif
