
/**
 * @file NVMM.c
 * @brief Functions for reading, writing, and erasing data in flash memory.
 * 
 * This file contains functions to perform operations on flash memory, including saving,
 * reading, and erasing data. These functions are designed for use with a specific 
 * microcontroller stm32f407VG and memory layout.
 */



#include "MainAPP/NVMM/NVMM.h"
#include "stm32f4xx_hal.h"

volatile uint32_t adresse=0x080E0000;
uint8_t flag=0;
/**
 * @brief Save data into flash memory.
 * 
 * @param Data Pointer to the data to be saved.
 * @return uint32_t Error code, 0 if saving is successful.
 */

uint32_t NvSaveData(data_stock *Data){
	 HAL_FLASH_Unlock();
	    /*Check the valid space*/
	 volatile uint32_t check_adresse=0x080E0000;
	 if (flag != 0)
	 {
	 	for(uint8_t i=0; i<=flag;i++){
	 		check_adresse=check_adresse+sizeof(data_stock);
	 	}
	 }


	     /*Check the valid space*/

	 		  if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,check_adresse, Data->component) == HAL_OK)
	 		     {
	 		    	 check_adresse +=4;
	  		     }

	 		 for( uint8_t Sizecounter=0; Sizecounter<=100;Sizecounter++)
	 		 {
	 		 HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, check_adresse, Data->comment[Sizecounter]);
	 		check_adresse+=1;
	 		 }
	           flag++;
	 		  HAL_FLASH_Lock();
	 return 0;

}




/**
 * @brief Read data from flash memory.
 * 
 * @param numofdata Number of data to read.
 * @return data_stock* Pointer to the read data, or NULL if no data is available.
 */

data_stock* NvReadData(uint8_t numofdata ){
	HAL_FLASH_Unlock();
static data_stock result;
uint32_t adresseOfread=0x080E0000;
if (flag==0)
{
	return NULL;
}
else
{
	adresseOfread=(0x080E0000 + (sizeof(data_stock)*numofdata-1));
result.component = (Devicetype)(*(__IO uint32_t *)adresseOfread);
memcpy(result.comment, (int8_t *)(adresseOfread + sizeof(Devicetype)), sizeof(result.comment));

}
return &result;
}

/**
 * @brief Erase data stored in flash memory.
 * 
 * @return uint32_t Error code, 0 if erasing is successful.
 */
uint32_t NvEraseData(void){
static FLASH_EraseInitTypeDef EraseInitStruct;
uint32_t SECTORError;
		 /* Unlock the Flash to enable the flash control register access *************/
		  HAL_FLASH_Unlock();

		  /* Erase the user Flash area */

		  /* Get the number of sector to erase from 1st sector */

		  uint32_t StartSector =FLASH_SECTOR_11;
		  uint32_t EndSector =FLASH_SECTOR_11;

		  /* Fill EraseInit structure*/
		  EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
		  EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
		  EraseInitStruct.Sector        = StartSector;
		  EraseInitStruct.NbSectors     = (EndSector - StartSector) + 1;


		  if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK)
		  {
			  return HAL_FLASH_GetError ();
		  }
		  else
		  {
		   flag=0;
		    return 0;
		   }
}

