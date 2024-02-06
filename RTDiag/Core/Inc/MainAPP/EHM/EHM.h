/*
 * EHM.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Hamdi
 */

#ifndef INC_MAINAPP_EHM_EHM_H_
#define INC_MAINAPP_EHM_EHM_H_

typedef enum {
    HORS_PLAGE_TEMPERATURE,             // Errors types for temperature sensors
    ERREUR_LECTURE,
    CALIBRATION_INCORRECTE
}Sensor2Error;

typedef enum {                    //List of possible error types for the motor
    POWER_SUPPLY_ERROR,     // Error of power supply
    OVERHEATING_ERROR,      // Error OVERHEATING
    MECHANICAL_FAILURE      // Mechanical failure
} MotorError;
typedef enum {                                  // List of causes of cell dysfunction of cells
    PAS_DE_CONNEXION,
    ALIMENTATION_INSUFFISANTE,
    MAUVAISE_CALIBRATION,
    ERREUR_COMMUNICATION,
    ERREUR_TRAITEMENT_DONNEES
 }CellsError;
 typedef enum {
     TcrtSensor,
     TemperatureSensor,
     Motor,
     Cell,
     Arduino
 } SensorType;
 typedef enum {
     CELLULE_TYPE_A,
     CELLULE_TYPE_B,
     CELLULE_TYPE_C,
     CELLULE_TYPE_D
 } CelluleType;
 typedef enum {
     NO_ERROR,
     CONNECTION_ERROR,
	 Electrical_Supply_Issue,
	 Temperature_Exceedance,
	 Structural_Malfunction
 } ErrorType;
 ErrorType EHMSensors(uint8_t*, SensorType S);
 ErrorType EHMMoter(uint8_t* MotorValues );
 ErrorType EHMcells(uint8_t* CellsValues, CelluleType C);



#endif /* INC_MAINAPP_EHM_EHM_H_ */
