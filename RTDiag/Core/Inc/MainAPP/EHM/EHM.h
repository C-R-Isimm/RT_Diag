/*
 * EHM.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Hamdi
 */

#ifndef EHM_H_

#define EHM_H_


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

 ErrorType EHMSensors(uint8_t*, SensorType Sensor);

 // Implementation of the function HandleSensors

 ErrorType EHMMoter(uint8_t* MotorValues );

 // Implementation of the function EHMMoter

 ErrorType EHMcells(uint8_t* CellsValues, CelluleType Cells);

 // Implementation of the function EHMcells



#endif /* INC_MAINAPP_EHM_EHM_H_ */
