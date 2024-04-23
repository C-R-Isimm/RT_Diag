#include <MainAPP/__FSM/FSM.h>
#include <MainAPP/Common/component.h>
#include <MainAPP/TM/TM.h>
#include <stdint.h>
#include <MainAPP/UIM/UIM.h>
#include <usbd_cdc_if.h>
#define CHECK_DEVICE(device) ((device == '1') || (device == '2') || (device == '3') || (device == '4')|| (device == '5')|| (device == '6')|| (device == '7'))
#define ASCII_TO_INT(a) ((a)-'0')

// Variable declaration
state State = IDLE ;                                     //state initialization to IDLE state
Devicetype device ;                                      //device declaration
static char* msg = "Enter your device number :\n1.LM35\n2.Motor\n3.Ultrasonic\n4.Arduino\n5.Tcrt\n6.Qtr 8rc\n7.Dht11\n";
uint8_t count =1 ;
uint8_t buffer[64];

//Possible states
void FSM()
{

	switch(State)
    {
        case IDLE :
        Start();
        break;
        case DeviceConfig :
        ConfigDevice(msg , device);                        //if the device configuration is successful : transition to device testing state
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
void Start()
{
	if(HAL_GPIO_ReadPin(start_GPIO_Port,start_Pin)==1 && count == 1)
	{
			count++;
			State = DeviceConfig ;
	}
}

/******* Event 2 : device configuration input*********/
void ConfigDevice(char *msg,Devicetype device)
{
	do{
		CDC_Transmit_FS((uint8_t*) msg, strlen(msg));
	  }while(0);
	device = ASCII_TO_INT(buffer[0]);
	if(CHECK_DEVICE(device))
	{
		if(TMDeviceTypeconfig(device)==HAL_OK)
		{
			State = DeviceTest;
		}else
		{
			State = ErrorHandler;
		}

	}else
	{
		CDC_Transmit_FS((uint8_t*) "The device you entered is not supported ! Please try again.", strlen(msg));
	}
}

/******* Event 3 : device Testing *********/
void TestDevice()
{

}

