/*
 * TM.c
 *
 *  Created on: Jan 31, 2024
 *      Author: Hamdi
 */
#include "MainAPP/TM/TM.h"

#include "MainAPP/ComM/ComM.h"

#define NULL ((void *)0)

uint32_t *TMResultfinal;

void TMDeviceTypeconfig(Devicetype Deviceconfig)
{
   if (Deviceconfig == lm35)
   {
      /*configuration(lm35);*/
   }
   else if (Deviceconfig == Motor)
   {
      /*configuration(Motor);*/
   }
   else if (Deviceconfig == tcrt)
   {
      /* configuration(tcrt);*/
   }
   else if (Deviceconfig == Ultrasonic)
   {
      /*configuration(Ultrasonic);*/
   }
   else if (Deviceconfig == arduino)
   {
      /*configuration(arduino);*/
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
}

static void TMTestMotor()
{
}

static void TMTesttcrt()
{
}

static void TMTestUltrasonic()
{
}

static void TMTestarduino()
{
}

static void TMTestqtr_8rc()
{
}

static void TMTestdht11()
{
}

uint32_t *TMResultTest(Devicetype Deviceconfig)
{
   if (Deviceconfig == lm35)
   {
      TMTestlm35();
   }
   else if (Deviceconfig == Motor)
   {
      TMTestMotor();
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
   else if (Deviceconfig == arduino)
   {
      TMTestarduino();
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
