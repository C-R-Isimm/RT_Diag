/*
 * TM.c
 *
 *  Created on: Jan 31, 2024
 *      Author: Hamdi
 */
#include "MainAPP/TM/TM.h"

#include "MainAPP/ComM/ComM.h"

#include "MainAPP/UIM/UIM.h"

#define NULL ((void *)0)

uint32_t *TMResultfinal;

void TMDeviceTypeconfig(Devicetype Deviceconfig)
{
   if (Deviceconfig == lm35)
   {
      /*configuration(lm35);*/
   }
   else if (Deviceconfig == tcrt)
   {
      /* configuration(tcrt);*/
   }
   else if (Deviceconfig == Ultrasonic)
   {
      /*configuration(Ultrasonic);*/
   }
   else if (Deviceconfig == qtr_8rc)
   {
      /*configuration(qtr_8rc);*/
   }
   else if (Deviceconfig == dht11)
   {
      /*configuration(dht11);*/
   }
   else
   {
   }
}
// Static test functions (not visible outside this file)
static void TMTestlm35()
{
  /* UIMwrite("First check: Assessing room temperature.");
   TMResultfinal = ComMReadSensorValeur(lm35);
   UIMwrite("Second  check: The temperature is cold.");
   TMResultfinal = ComMReadSensorValeur(lm35);
   UIMwrite("Third check: The temperature is hot.");
   TMResultfinal = ComMReadSensorValeur(lm35);
   UIMwrite("LM35 temperature sensor test completed.");
*/
}




static void TMTesttcrt()
{
   /* UIMwrite("Testing TCRT sensor on black surface");
	 TMResultfinal = ComMReadSensorValeur(tcrt);
	 UIMwrite("Testing TCRT sensor on White surface");
	 TMResultfinal = ComMReadSensorValeur(tcrt);
    UIMwrite("TCRT sensor test completed.");
*/
}

static void TMTestUltrasonic()
{
   /* UIMwrite("Starting ultrasonic sensor test");
	 TMResultfinal = ComMReadSensorValeur(Ultrasonic);
    UIMwrite("Ultrasonic sensor test completed.");
*/
}


static void TMTestqtr_8rc()
{
	/* UIMwrite("Testing TCRT sensor on black surface");
	 TMResultfinal = ComMReadSensorValeur(qtr_8rc);
	 UIMwrite("Testing TCRT sensor on White surface");
	 TMResultfinal = ComMReadSensorValeur(qtr_8rc);
    UIMwrite("QTR-8RC sensor test completed.");
*/
}

static void TMTestdht11()
{
	/*UIMwrite("First check: Assessing humidity.");
	TMResultfinal = ComMReadSensorValeur(dht11);
	UIMwrite("Second check: Verifying humidity.");
	TMResultfinal = ComMReadSensorValeur(dht11);
	UIMwrite("DHT11 humidity sensor test completed.");
*/

}

uint32_t *TMResultTest(Devicetype Deviceconfig)
{
   if (Deviceconfig == lm35)
   {
      TMTestlm35();
   }

   else if (Deviceconfig == tcrt)
   {
      TMTesttcrt();
   }
   else if (Deviceconfig == Ultrasonic)
   {
      TMTestUltrasonic();
   }
   else if (Deviceconfig == tcrt)
   {
      TMTesttcrt();
   }
   else if (Deviceconfig == qtr_8rc)
   {
      TMTestqtr_8rc();
   }
   else if (Deviceconfig == dht11)
   {
      TMTestdht11();
   }
   else
   {
      TMResultfinal = NULL;
   }

   return TMResultfinal;
}
