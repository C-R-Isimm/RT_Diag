#include "stdint.h"
#include "stm32f4xx_hal.h"
#include"stdint.h"
void NV_save_data(uint32_t Address,uint32_t data)
{



}
char * NV_read_data(uint32_t Address){

}

uint32_t NV_erase_data(void)
{

static FLASH_EraseInitTypeDef EraseInitStruct;
uint32_t SECTORError;



 /* Unlock the Flash to enable the flash control register access *************/
		  HAL_FLASH_Unlock();

/* Erase the user Flash area */

/* Get the number of sector to erase from 1st sector */

		  uint32_t StartSector =(uint32_t)0x080E0000;
		  uint32_t EndSectorAddress =(uint32_t)0x080FFFFF;
		  uint32_t EndSector =EndSectorAddress;

		  /* Fill EraseInit structure*/
		  EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
		  EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
		  EraseInitStruct.Sector        = StartSector;
		  EraseInitStruct.NbSectors     = (EndSector - StartSector) + 1;

		  /* Note: If an erase operation in Flash memory also concerns data in the data or instruction cache,
		     you have to make sure that these data are rewritten before they are accessed during code
		     execution. If this cannot be done safely, it is recommended to flush the caches by setting the
		     DCRST and ICRST bits in the FLASH_CR register. */
		  if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK)
		  {
			  return HAL_FLASH_GetError ();
		  }
return 0;
}

