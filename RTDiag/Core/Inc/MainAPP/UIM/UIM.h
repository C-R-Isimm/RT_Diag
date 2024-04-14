#ifndef INC_MAINAPP_UIM_UIM_H_
#define INC_MAINAPP_UIM_UIM_H_

#include "usb_device.h"
#include "usbd_cdc_if.h"
#include "string.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

// Function declaration
uint8_t UIM_Transmit_FS(uint8_t* Buf, uint16_t Len);
void UIM_Receive_FS(uint8_t* Buf, uint32_t *Len);
#endif /* INC_MAINAPP_UIM_UIM_H_ */
