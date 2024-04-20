#include <MainAPP/__FSM/FSM.h>
#include <MainAPP/Common/component.h>
#include <MainAPP/TM/TM.h>
#include <stdint.h>
#include <MainAPP/UIM/UIM.h>
#include <usbd_cdc_if.h>
#define CHECK_DEVICE(device) ((device == '1') || (device == '2') || (device == '3') || (device == '4')|| (device == '5')|| (device == '6'))

// Variable declaration
state State = IDLE ;                                     //state initialization to IDLE state
Devicetype device ;                                      //device declaration
char* data = "Enter your device number :\n1.LM35\n2.Ultrasonic\n3.QTR 8RC\n4.TCRT\n5.DHT11\n6.DC motor\n";
uint8_t buffer[64];

//Possible states
void FSM()
{

	switch(State)
    {
        case IDLE :
        State = Start();
        break;
        case DeviceConfig :
        {
        	ConfigDevice(data , device);                        //if the device configuration is successful : transition to device testing state
        }
        break;
        case DeviceTest :

        break;
        case ErrorHandler :

        break;
        case PassState :

        break;
        default :

        break;
    }
}
/*********** Event 1 : start button**************/
state Start()
{
	if(HAL_GPIO_ReadPin(start_GPIO_Port,start_Pin)==1 && count == 1)
		{
			count++;
			return DeviceConfig ;
        }
}
/******* Event 2 : device configuration input*********/
void ConfigDevice(char *data,Devicetype device)
{
	do{
		CDC_Transmit_FS((uint8_t*) data, strlen(data));
	}while(0);
	if(CHECK_DEVICE(buffer[0]))
	{
		device = (Devicetype)buffer[0];
		if(TMDeviceTypeconfig(device)==HAL_OK)
		{
			state = DeviceTest;
		}else
		{
			state = ErrorHandler;
		}

	}else
	{
		CDC_Transmit_FS((uint8_t*) "Invalid expression !\nRepeat again", strlen(data));
	}
}
/******* Event 3 : device Testing *********/
void TestDevice()
{

}

