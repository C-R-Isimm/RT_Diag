/*
 * ComM.c
 *
 *  Created on: Jan 31, 2024
 *      Author: Hamdi wel prezzz
 */


#include"MainAPP/ComM/ComM.h"


static void ComMConfigUART(){

}

static void ComMConfigADC(){

}

static void ComMConfigGPIO(){

}

static void ReadGPIO(){

}

static void WriteGPIO(){

}

void ComMConfigDevice(Devicetype Device){
	if (Device == lm35){
		ComMConfigADC();

	}
	else if (Device == tcrt){
		ComMConfigGPIO();

		}
	else if (Device == Ultrasonic){
		ComMConfigGPIO();

		}
	else if (Device == arduino){
		ComMConfigUART();

		}
	else if (Device == qtr_8rc){
		ComMConfigGPIO();

		}
	else if (Device == dht11){
		ComMConfigADC();

			}
}
void ComMReadSensorValue(Devicetype Device){

	if (Device == lm35){

		}
		else if (Device == tcrt){


			}
		else if (Device == Ultrasonic){


			}
		else if (Device == arduino){


			}
		else if (Device == qtr_8rc){


			}
		else if (Device == dht11){


				}
}

