#include "MainAPP/NVMM/NVMM.h"
#include "stm32f4xx_hal.h"

volatile uint32_t adresse=0x080E0000;
uint8_t c=0;

static void  NV_convert_to_string (uint32_t*,char * );


uint32_t NV_save_data(data_stock *Data){

int16_t sofar=0;
uint32_t *ptr=(uint32_t *)Data;

   /*Check the valid space*/
volatile uint32_t check_adresse=0x080E0000;
if (c != 0){

	for(uint8_t i=0; i<=c;i++){
		check_adresse=check_adresse+sizeof(data_stock);
	}

}


                  /****/
uint16_t numberofwords=(sizeof(data_stock)/4+sizeof(data_stock)%4 !=0)/4;
	while (sofar<numberofwords)
		   {
		     if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,check_adresse, *ptr) == HAL_OK)
		     {
		    	 check_adresse +=4;
		    	 ptr++;
		    	 sofar++;
		     }
		     else
		     {
		       /* Error occurred while writing data in Flash memory*/
		    	 return HAL_FLASH_GetError ();
		     }
		   }
          c++;
		  HAL_FLASH_Lock();

		   return 0;

}


uint8_t * NV_read_data(){
uint32_t *data ;
char* data_stored;// !!!!!
if (c==0){

	//message for  no data read
}else
{
uint8_t compteur = (c*(sizeof(data_stock)/4+sizeof(data_stock)%4 !=0))/4;
	 for (uint8_t i=0;i<=compteur;i++){
	*data = *(__IO uint32_t *)adresse;
	adresse+= 4;
	data++;
	 }

	 // converte and send
	 NV_convert_to_string (data,data_stored);
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
		  }else
		  {
			  c=0;
			  return 0;}
}


static void NV_convert_to_string (uint32_t* input,char* data_stored )
{
int number_of_bites = ((strlen((char *)input)/4) + ((strlen((char *)input) % 4) != 0)) *4;

for (int i=0; i<number_of_bites; i++)
	{
	data_stored[i] = input[i/4]>>(8*(i%4));
	}
// usb mariem
}

