/*
 * EHM.c
 *
 *  Created on: Jan 31, 2024
 *      Author: omar
 */

#include <stdint.h>

#include "MainAPP/EHM/EHM.h"

#define ARRAY_SIZE 10

/**
 *
 *
 * @brief   Implementation of HandleSensors function goes here
 *          You should add the logic to handle sensor values based on the device type
 * @param SensorValues
 * @param Sensor
 * @return ErrorType
 */

ErrorType EHMHandleSensors(uint8_t* SensorValues, Devicetype Sensor) {
	// Assume that the TCRT sensor is the only sensor for now
	if (Sensor == tcrt) {    
	// Check if the TCRT sensor values are constant
	     uint8_t firstValue = SensorValues[0];
		 int i = 1;  
	// Use a while loop to check all values in the array
    while (i < ARRAY_SIZE && SensorValues[i] == firstValue) {
            i++;
        }
    // If all values are identical, the sensor is malfunctioning
        
		if (i == ARRAY_SIZE) {
            return MECHANICAL_FAILURE;
      }
    }
  
	    




// Checking the validity of the sensor values
// Here, we simulate a malfunction by returning a fixed value
if (Sensor == Ultrasonic) {
    int i = 0;
    // Use a while loop to iterate through the array and check if all values are zero
    while (i < ARRAY_SIZE && SensorValues[i] == 0) {
        i++;
    }
    // If all values are zero, it indicates a malfunction
    if (i == ARRAY_SIZE) {
        return MECHANICAL_FAILURE; // The ultrasonic sensor is malfunctioning
    }
  }
  
   

	    
		
    if (Sensor == qtr_8rc) {
    // Check if all sensor values are the same
        uint8_t firstValue = SensorValues[0];
        int i = 1;
    // Use a while loop to check if all values are the same
    while (i < ARRAY_SIZE && SensorValues[i] == firstValue) {
        i++;
    }
    // If all values are the same, sensor is malfunctioning
    if (i == ARRAY_SIZE) {
        return MECHANICAL_FAILURE;
    }
   }
 }

			   
		   
   

	           
                
 


/**
 * @brief   Implementation of EHMMotor function goes here
	       You should add the logic to handle motor values
 *
 * @param MotorValues
 * @return ErrorType
 */
 ErrorType EHMHandleMotor(uint8_t* MotorValues) {
 }


