#include "MainAPP/NVMM/NVMM.h"
#include "stm32f4xx_hal.h"

uint32_t *data;
uint32_t adresse=0x080E0000;


uint32_t NV_save_data(data_stock *Data){

int16_t sofar=0;
uint32_t *ptr=(uint32_t *)Data;

   /*Check the valid space*/
uint32_t *check_adresse=(uint32_t *)0x080E0000;
while(1){
	if(*check_adresse==0xffffffff)
	{
		adresse=(uint32_t)check_adresse;
		break;
	}
	check_adresse++;
}

                  /****/
uint16_t numberofwords=(sizeof(data_stock)/4);
	while (sofar<numberofwords)
		   {
		     if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,adresse, *ptr) == HAL_OK)
		     {
		    	 adresse +=4;
		    	 ptr++;
		    	 sofar++;
		     }
		     else
		     {
		       /* Error occurred while writing data in Flash memory*/
		    	 return HAL_FLASH_GetError ();
		     }
		   }

		  HAL_FLASH_Lock();

		   return 0;

}


uint8_t * NV_read_data(){
	while (1)
		{

			*data = *(__IO uint32_t *)adresse;
			if(*data==0xffffffff){
				*data='\0';
				break;
			}
			adresse+= 4;
			data++;
		}
}

uint32_t NV_erase_data(void){
	static FLASH_EraseInitTypeDef EraseInitStruct;
		uint32_t SECTORError;
		 /* Unlock the Flash to enable the flash control register access *************/
		  HAL_FLASH_Unlock();

		  /* Erase the user Flash area */

		  /* Get the number of sector to erase from 1st sector */

		  uint32_t StartSector =(uint32_t)0x080E0000;
		  uint32_t EndSector =(uint32_t)0x080FFFFF;

		  /* Fill EraseInit structure*/
		  EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
		  EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
		  EraseInitStruct.Sector        = StartSector;
		  EraseInitStruct.NbSectors     = (EndSector - StartSector) + 1;


		  if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK)
		  {
			  return HAL_FLASH_GetError ();
		  }
		  else { return 0;}
}

