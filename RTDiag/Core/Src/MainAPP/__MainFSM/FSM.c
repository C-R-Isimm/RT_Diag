/*
 * FSM.c
 *
 *  Created on: Mar 19, 2024
 *      Author: chayma
 */
#include <MainAPP/__MainFSM/FSM.h>
#include <MainAPP/Common/component.h>
#include <stdint.h>

#define CHECK_DEVICE(device)({(device == lm35 ? true : false) / (device == Ultrasonic? true : false)/ (device == dht11 ? true : false )/ (device == tcrt ? true : false )})
// Define constant variable
state State = IDLE ;                                     //state initialization to IDLE state
Devicetype device ;                                      //device declaration

//Possible states 
void FSM()
{

	switch(State)
    {
        case IDLE :


        break;
        case DeviceConfig :
                                //if the device configuration is successful : transition to device testing state

        break;
        case DeviceTest :

        break;    
        case ErrorHandler :

        break;   
        case PassState :

        break; 
        default :

        break;                           
    }
}

