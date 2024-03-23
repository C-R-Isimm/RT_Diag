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

uint8_t *TMResultfinal;

uint8_t tab[10];uint8_t tab1[7];


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
	   // Devicetype no supported
   }
}
// Static test functions (not visible outside this file)
static void TMTestlm35()
{
	//int8_t i;
   /*UIMwrite("First check: Assessing room temperature.");
   TMResultfinal = (uint8_t *)ComMReadSensorValeur(lm35);
    for ( i=0 , i<3 ,i++ ){
    tab[i]= *(TMResultfinal+i);
    }
   UIMwrite("Second  check: The temperature is cold.");
   TMResultfinal = (uint8_t *)ComMReadSensorValeur(lm35);
    for ( i=3 , i<6 ,i++ ){
    tab[i]= *(TMResultfinal+i);
    }
   UIMwrite("Third check: The temperature is hot.");
   TMResultfinal = (uint8_t *)ComMReadSensorValeur(lm35);
    for ( i=6 , i<9 ,i++ ){
    tab[i]= *(TMResultfinal+i);
    }
   UIMwrite("LM35 temperature sensor test completed.");
   */
}

static void TMTesttcrt()
{
   /* UIMwrite("Testing TCRT sensor on black surface");
	 TMResultfinal = ComMReadSensorValeur(tcrt);
	  for ( i=0 , i<3 ,i++ ){
    tab1[i]= *(TMResultfinal+i);
    }
	 UIMwrite("Testing TCRT sensor on White surface");
	 TMResultfinal = ComMReadSensorValeur(tcrt);
	  for ( i=3 , i<6 ,i++ ){
    tab1[i]= *(TMResultfinal+i);
    }
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

uint8_t *TMResultTest(Devicetype Deviceconfig)
{
   if (Deviceconfig == lm35)
   {
      TMTestlm35();
      return TMResultfinal=tab;
   }


   else if (Deviceconfig == tcrt)
   {
      TMTesttcrt();
      return TMResultfinal=tab1;

   }
   else if (Deviceconfig == Ultrasonic)
   {
      TMTestUltrasonic();
      return TMResultfinal;
   }
   else if (Deviceconfig == tcrt)
   {
      TMTesttcrt();
      return TMResultfinal;
   }
   else if (Deviceconfig == qtr_8rc)
   {
      TMTestqtr_8rc();
      return TMResultfinal;
   }
   else if (Deviceconfig == dht11)
   {
      TMTestdht11();
      return TMResultfinal;
   }
   else
   {
	   return TMResultfinal = NULL;
   }


}
