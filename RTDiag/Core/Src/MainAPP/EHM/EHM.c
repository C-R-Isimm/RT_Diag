/*
 * EHM.c
 *
 *  Created on: Jan 31, 2024
 *      Author: omar
 */

#include <stdint.h>

#include "MainAPP/EHM/EHM.h"

#define ARRAY_SIZE 10
#define MIN_RANGE_CM 2
#define MAX_RANGE_CM 400
/**
 *
 *
 * @brief   Implementation of HandleSensors function goes here
 *          You should add the logic to handle sensor values based on the device type
 * @param SensorValues
 * @param Sensor
 * @return ErrorType
 */
ErrorType EHMHandleSensors(uint8_t *SensorValues, Devicetype Sensor)
{
        // Assume that the TCRT sensor is the only sensor for now
    if (Sensor == tcrt)
    {
        int i = 0;
        while (i < ARRAY_SIZE)
        {
            if (SensorValues[i] != 0 && SensorValues[i] != 1)
            {
                return MECHANICAL_FAILURE;
            }
            return i++;
        }

            
        // Check if the TCRT sensor values are constant
        uint8_t firstValue = SensorValues[0];
                int index = 1;
                // Use a while loop to check all values in the array
        while (index < ARRAY_SIZE && SensorValues[index] == firstValue)
       
        {
                        index++;
                   
        }
                // If all values are identical, the sensor is malfunctioning
        if (index != ARRAY_SIZE)
       
        {
                        return MECHANICAL_FAILURE;
                   
        }

           
    }
        // Checking the validity of the sensor values
    // Here, we simulate a malfunction by returning a fixed value
    if (Sensor == Ultrasonic)
   
    {
        // Check if all values in the array fall within the logical range
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            if (SensorValues[i] < MIN_RANGE_CM || SensorValues[i] > MAX_RANGE_CM)
            {
                return MECHANICAL_FAILURE; // If any value is outside the logical range, return mechanical failure
            }
        }
    }
        if (Sensor == qtr_8rc)
   
    {
        int i = 0;
        while (i < ARRAY_SIZE)
        {
            if (SensorValues[i] != 0 && SensorValues[i] != 1)
            {
                return MECHANICAL_FAILURE;
            }
            return i++;
        }
                // Check if all sensor values are the same
        uint8_t firstValue = SensorValues[0];
                int index = 1;
                // Use a while loop to check if all values are the same
        while (index < ARRAY_SIZE && SensorValues[index] == firstValue)
       
        {
                        index++;
                   
        }
                // If all values are the same, sensor is malfunctioning
        if (index != ARRAY_SIZE)
       
        {
                        return MECHANICAL_FAILURE;
                   
        }
           
    }
}
/**
 * @brief   Implementation of EHMMotor function goes here
           You should add the logic to handle motor values
 *
 * @param MotorValues
 * @return ErrorType
 */
ErrorType EHMHandleMotor(uint8_t *MotorValues)
{
}
