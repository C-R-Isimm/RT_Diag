/**
 * FSM.h
 *
 *  Created on: Mar 19, 2024
 *      Author: GARGOUCHAA
 */
#ifndef FSM_H_
#define FSM_H_

/***Include libraries ****/
#include <MainAPP/Common/component.h>


typedef enum			//states of the finite state machine
{
	IDLE,				//idle state
	DeviceConfig,		//configuration state
	DeviceTest,			//device testing state
	ErrorHandler,		//error diagnostic state
    PassState 			//device passed state

}state;

//FSM main function
void FSM();

//Events function
void Start();
void ConfigDevice(char *msg,Devicetype device);
void TestDevice();


#endif
