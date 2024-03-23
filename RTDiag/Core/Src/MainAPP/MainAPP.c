/*
 * MainAPP.c
 *
 *  Created on: Jan 31, 2024
 *      Author: Chayma GARGOUCH
 */
#include <MainAPP/__MainFSM/FSM.h>
#include <MainAPP/MainAPP.h>
#include <MainAPP/Common/component.h>
#include <stdint.h>
#include <stdbool.h>


// Define constant variable
const int errorcod = -1 ; 




int main()
{
    int8_t UserIn ;                                          //input from the user 
    state state = IDLE ;                                     //state initialization to IDLE state 
    Devicetype device ;                                      //device declaration

//Possible states 
    switch(state)                                                       
    {
        case IDLE :
            if(Read_input(&UserIn))
            {
                state = DeviceConfig ;                       //if the user enter a value : transition to device configuration state
            }
        break;
        case DeviceConfig :
            if(configDevice(device)== true)                  //if the device configuration is successful : transition to device testing state
            {
                state = DeviceTest;
            }
        break;
        case DeviceTest :

        break;    
        case ErrorHandler :

        break;   
        case PassState :

        break; 
        default:

        break;                           
    }
    return 0;
}
