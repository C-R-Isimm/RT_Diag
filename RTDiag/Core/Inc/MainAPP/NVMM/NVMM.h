
#ifndef  NVMM_H_
#define NVMM_H_


#include "stdint.h"

void NV_save_data(uint32_t Address,uint32_t data);

char * NV_read_data(uint32_t Address);


void NV_erase_data(uint32_t Address);
#endif 
