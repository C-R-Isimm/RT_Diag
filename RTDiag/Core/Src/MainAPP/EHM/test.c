#include <stdio.h>
#include <stdint.h>
#include "MainAPP/EHM/EHM.h"

/**
 * @brief 
 * 
 * @return int 
 */
int main()
{
    // Sample sensor values for testing TCRT sensor
    uint8_t tcrtValues[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    // Call EHMHandleSensors function to test TCRT sensor
    ErrorType sensorError = EHMHandleSensors(tcrtValues, tcrt);

    // Check the error returned by the function
    if (sensorError == NO_ERROR)
    {
        printf("TCRT sensor is functioning normally.\n");
    }
    else
    {
        printf("TCRT sensor error: %d\n", sensorError);
    }

    // Sample sensor values for testing Ultrasonic sensor
    uint8_t ultrasonicValues[10] = {350, 360, 370, 380, 390, 400, 410, 420, 430, 440};

    // Call EHMHandleSensors function to test Ultrasonic sensor
    sensorError = EHMHandleSensors(ultrasonicValues, Ultrasonic);

    // Check the error returned by the function
    if (sensorError == NO_ERROR)
    {
        printf("Ultrasonic sensor is functioning normally.\n");
    }
    else
    {
        printf("Ultrasonic sensor error: %d\n", sensorError);
    }

    // Sample sensor values for testing qtr_8rc sensor
    uint8_t qtrValues[10] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0};

    // Call EHMHandleSensors function to test qtr_8rc sensor
    sensorError = EHMHandleSensors(qtrValues, qtr_8rc);

    // Check the error returned by the function
    if (sensorError == NO_ERROR)
    {
        printf("qtr_8rc sensor is functioning normally.\n");
    }
    else
    {
        printf("qtr_8rc sensor error: %d\n", sensorError);
    }

    return 0;
}
