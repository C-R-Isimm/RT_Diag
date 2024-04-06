#ifndef NVMM_H_
#define NVMM_H_
#include "stdint.h"
#include "MainAPP/Common/component.h"
#include "string.h"

/**
 * @brief Data structure for storing device information.
 * 
 * This structure defines a data stock entry, which includes the status of the device,
 * the type of component, and a comment field for additional information.
 */
typedef struct {
    // status ;
    Devicetype component;
    int8_t comment[100];
} data_stock;

uint32_t NvSaveData(data_stock *);

data_stock* NvReadData(uint8_t numofdata);


uint32_t NvEraseData(void);

#endif 

