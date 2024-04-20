/*
 * EHM.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Omar
 */

#ifndef EHM_H_
#define EHM_H_

#include "MainAPP/Common/component.h"

typedef enum
{                       // Enumeration for different types of errors
    NO_ERROR,           // No error
    CONNECTION_ERROR,   // Connection error
    POWER_SUPPLY_ERROR, // Power supply error
    OVERHEATING_ERROR,  // Overheating error
    MECHANICAL_FAILURE  // Mechanical failure
} ErrorType;

/**
 * @brief   Function to handle sensors
 *
 * @param SensorValues    Pointer to the array of sensor values
 * @param Sensor          Type of device (sensor) being handled
 * @return ErrorType      ErrorType indicating the status of sensor handling
 */
ErrorType EHMHandleSensors(uint8_t *SensorValues, Devicetype Sensor);

/**
 * @brief  Function to handle motors
 *
 * @param MotorValues     Pointer to the array of motor values
 * @return ErrorType      ErrorType indicating the status of motor handling
 */
ErrorType EHMHandleMotor(uint8_t *MotorValues);

#endif /* INC_MAINAPP_EHM_EHM_H_ */
