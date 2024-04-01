#ifndef NVMM_H_
#define NVMM_H_
#include "stdint.h"
#include "MainAPP/Common/component.h"
#include "string.h"
typedef struct {
    // status ;
    Devicetype component;
    int8_t comment[100];
} data_stock;

uint32_t NV_save_data(data_stock *);

uint8_t* NV_read_data(void);


uint32_t  NV_erase_data(void);

#endif 

