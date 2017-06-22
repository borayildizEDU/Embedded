/*----------------------------------------------------------------------------
 *      RL-ARM - RTX
 *----------------------------------------------------------------------------
 *      Name:    BLinky.c
 *      Purpose: RTX example program
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2014 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/
 
#include "cmsis_os.h"
#include "LPC18xx.h"
#include "Board_LED.h"
#include "EventRecorder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CDCI.h"


#define EventRecorder_CID     0x0100
#define EventRecorder_Print   0x0107


/*----------------------------------------------------------------------------
 * main: blink LED and check button state
 *----------------------------------------------------------------------------*/
int main (void) {
  CDCI cdci;
  
  SystemCoreClockUpdate();
  LED_Initialize();                                                 
                                           
	EventRecorderInitialize(EventRecordAll, 1);
  EventRecorderStop();
  EventRecorderStart();
  
  cdci.Test();
  
	
  for (;;) {    
    

		
  }
}
