/*
 * FSM.c
 *
 *  Created on: Mar 19, 2024
 *      Author: chayma
 */
#include<MainAPP/__MainFSM/FSM.h>
#include <MainAPP/Common/component.h>
#include <stdint.h>
#include <stdbool.h>

int8_t errorcod = -1 ;


int8_t Read_input(int8_t * input)
{
    if(scanf("%d",input) == 1)
    {
        return 1;
    }else
    {
        return errorcod;
    }
}

bool configDevice(Devicetype device)
{
    switch(device)
    {
        case lm35 :
        return true ; 

        case Ultrasonic : 
        return true ; 

        case arduino :
        return true ; 

        case tcrt : 
        return true ; 

        case dht11:
        return true ;

        case qtr_8rc : 
        return true ; 

        case Motor : 
        return true ; 
        
        default : 
        return false ;  

    }
}