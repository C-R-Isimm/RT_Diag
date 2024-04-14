#include "MainAPP/UIM/UIM.h"

extern USBD_HandleTypeDef hUsbDeviceFS;
extern uint8_t buffer[64];

uint8_t UIM_Transmit_FS(uint8_t* Buf, uint16_t Len)
{
  uint8_t result = USBD_OK;
  USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef*)hUsbDeviceFS.pClassData;
  if (hcdc->TxState != 0){
    return USBD_BUSY;
  }
  USBD_CDC_SetTxBuffer(&hUsbDeviceFS, Buf, Len);
  result = USBD_CDC_TransmitPacket(&hUsbDeviceFS);
  return result;
}

void UIM_Receive_FS(uint8_t* Buf, uint32_t *Len)
{
	USBD_CDC_SetRxBuffer(&hUsbDeviceFS, &Buf[0]);
	 USBD_CDC_ReceivePacket(&hUsbDeviceFS);
	  uint8_t len = (uint8_t) *Len;
	  memset (buffer,'\0', 64),
	  memcpy (buffer, Buf, len);
	  //return (USBD_OK);
}
