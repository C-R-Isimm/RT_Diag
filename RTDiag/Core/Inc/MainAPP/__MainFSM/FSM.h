/**
 * FSM.h
 *
 *  Created on: Mar 19, 2024
 *      Author: Chayma
 */
#ifndef FSM_H_
#define FSM_H_



typedef enum 			//states of the finite state machine
{
	IDLE,				//idle state
	DeviceConfig,		//configuration state
	DeviceTest,			//device testing state
	ErrorHandler,		//error diagnostic state
    PassState 			//device passed state
} state;


//Events function 


#endif
