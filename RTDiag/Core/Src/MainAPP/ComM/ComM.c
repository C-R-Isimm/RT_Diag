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
ADC_HandleTypeDef hadc1;
HAL_ADC_Start(&hadc1); // begin of conversion
HAL_ADC_PollForConversion(&hadc1, 50); //wait the end of conversion
}

static void ComMConfigGPIO(){

}

static uint8_t ReadGPIO(){
return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);
}

static void WriteGPIO(int PinValue){
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, PinValue);
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
uint32_t ComMReadSensorValue(Devicetype Device){

	uint32_t x=0;

	if (Device == lm35){

		ADC_HandleTypeDef hadc1;
		x = HAL_ADC_GetValue(&hadc1);
		}

		else if (Device == tcrt){
		x = ReadGPIO();
		}

		else if (Device == Ultrasonic){

		}

		else if (Device == arduino){

		UART_HandleTypeDef huart4;
		HAL_UART_Transmit(&huart4, "Hello_CRI_UART!", 8,50); // Transmission message to Arduino
		HAL_UART_Receive(&huart4, x , 1 , 50);
		/* arduino will compare the message and the const declared in the arduino which have the same message value
		if  the same arduino will send 1 else will send 0 and the data will saved in x which will returned from function */

		}

		else if (Device == qtr_8rc){

		}

		else if (Device == dht11){

		}

	return x;
}

