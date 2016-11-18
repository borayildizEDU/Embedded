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


#define EventRecorder_CID 0x0100
static unsigned int globalCounter;

/* Threads */
osThreadId tid_Thread_LED; 
osThreadId tid_Thread_01; 
osThreadId tid_Thread_02; 
osThreadId tid_Thread_03; 
osThreadId tid_Thread_04; 
osThreadId tid_Thread_05; 
osThreadId tid_Thread_06; 
osThreadId tid_Thread_Status; 

/*----------------------------------------------------------------------------
 *      'Thread_LED': Sample thread
 *---------------------------------------------------------------------------*/

void Thread_LED (void const *argument);                                                                      
osThreadDef (Thread_LED, osPriorityNormal, 1, 0);                   

int Init_Thread_LED (void) {

  tid_Thread_LED = osThreadCreate (osThread(Thread_LED), NULL);
  if(!tid_Thread_LED) return(-1);

  return(0);
}

void Thread_LED (void const *argument) {
  uint32_t led_num    = 0;
	uint32_t threadCounter = 0;
	uint8_t led_state = 0;

  while (1) {
		threadCounter++;
		osSignalWait(0x0001, osWaitForever);
		
		// Toggle Led
		if(!led_state){
			LED_On(led_num);   
		  led_state = 1;			
		}
		else{
			LED_Off(led_num);
			led_state = 0;
		}
		
		EventRecord2((EventRecorder_CID | 0x00), threadCounter, globalCounter);
		    
    osThreadYield();                                               
  }
}

/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_01': Sample thread
 *---------------------------------------------------------------------------*/
void Thread_01 (void const *argument);                                                                         
osThreadDef (Thread_01, osPriorityNormal, 1, 0);                      

int Init_Thread_01 (void) {

  tid_Thread_01 = osThreadCreate (osThread(Thread_01), NULL);
  if(!tid_Thread_01) return(-1);

  return(0);
}

void Thread_01 (void const *argument) {
	uint32_t threadCounter = 0;	

  while (1) {
		threadCounter++;
		
		osSignalWait(0x0001, osWaitForever);
		EventRecord2((EventRecorder_CID | 0x01), threadCounter, globalCounter);
  
    osThreadYield();                                                
  }
}

/*----------------------------------------------------------------------------
 *      Thread 2 'Thread_02': Sample thread
 *---------------------------------------------------------------------------*/
void Thread_02 (void const *argument);                                                                          
osThreadDef (Thread_02, osPriorityNormal, 1, 0);                      

int Init_Thread_02 (void) {

  tid_Thread_02 = osThreadCreate (osThread(Thread_02), NULL);
  if(!tid_Thread_02) return(-1);

  return(0);
}

void Thread_02 (void const *argument) {
	uint32_t threadCounter = 0;	

  while (1) {
		threadCounter++;
		
		osSignalWait(0x0001, osWaitForever);
		EventRecord2((EventRecorder_CID | 0x02), threadCounter, globalCounter);
    
    osThreadYield();                                                
  }
}

/*----------------------------------------------------------------------------
 *      Thread 3 'Thread_03': Sample thread
 *---------------------------------------------------------------------------*/
void Thread_03 (void const *argument);                                                                           
osThreadDef (Thread_03, osPriorityNormal, 1, 0);                      

int Init_Thread_03 (void) {

  tid_Thread_03 = osThreadCreate (osThread(Thread_03), NULL);
  if(!tid_Thread_03) return(-1);

  return(0);
}

void Thread_03 (void const *argument) {
	uint32_t threadCounter = 0;	

  while (1) {
		threadCounter++;
		
		osSignalWait(0x0001, osWaitForever);
		EventRecord2((EventRecorder_CID | 0x03), threadCounter, globalCounter);
    
    osThreadYield();                                                
  }
}

/*----------------------------------------------------------------------------
 *      Thread 4 'Thread_04': Sample thread
 *---------------------------------------------------------------------------*/
void Thread_04 (void const *argument);                                                                           
osThreadDef (Thread_04, osPriorityNormal, 1, 0);                      

int Init_Thread_04 (void) {

  tid_Thread_04 = osThreadCreate (osThread(Thread_04), NULL);
  if(!tid_Thread_04) return(-1);

  return(0);
}

void Thread_04 (void const *argument) {
	uint32_t threadCounter = 0;	

  while (1) {
		threadCounter++;
		
		osSignalWait(0x0001, osWaitForever);
		EventRecord2((EventRecorder_CID | 0x04), threadCounter, globalCounter);
    
    osThreadYield();                                                
  }
}

/*----------------------------------------------------------------------------
 *      Thread 5 'Thread_05': Sample thread
 *---------------------------------------------------------------------------*/
void Thread_05 (void const *argument);                                                                         
osThreadDef (Thread_05, osPriorityNormal, 1, 0);                      

int Init_Thread_05 (void) {

  tid_Thread_05 = osThreadCreate (osThread(Thread_05), NULL);
  if(!tid_Thread_05) return(-1);

  return(0);
}

void Thread_05 (void const *argument) {
	uint32_t threadCounter = 0;	

  while (1) {
		threadCounter++;
		
		osSignalWait(0x0001, osWaitForever);
		EventRecord2((EventRecorder_CID | 0x05), threadCounter, globalCounter);
    
    osThreadYield();                                                
  }
}

/*----------------------------------------------------------------------------
 *      Thread 6 'Thread_06': Sample thread
 *---------------------------------------------------------------------------*/
void Thread_06 (void const *argument);                                                                         
osThreadDef (Thread_06, osPriorityNormal, 1, 0);                      

int Init_Thread_06 (void) {

  tid_Thread_06 = osThreadCreate (osThread(Thread_06), NULL);
  if(!tid_Thread_06) return(-1);

  return(0);
}

void Thread_06 (void const *argument) {
	uint32_t threadCounter = 0;	

  while (1) {
		threadCounter++;
		
		osSignalWait(0x0001, osWaitForever);
		EventRecord2((EventRecorder_CID | 0x06), threadCounter, globalCounter);
    
    osThreadYield();                                                
  }
}

/*----------------------------------------------------------------------------
 *      Thread 7 'Thread_Status': Writes latest status
 *---------------------------------------------------------------------------*/
void Thread_Status (void const *argument);                                                                         
osThreadDef (Thread_Status, osPriorityNormal, 1, 0);                      

int Init_Thread_Status(void) {

  tid_Thread_Status = osThreadCreate (osThread(Thread_Status), NULL);
  if(!tid_Thread_Status) return(-1);

  return(0);
}

void Thread_Status (void const *argument) {
	uint32_t threadCounter = 0;	
	char string[1000];
	
	// Thread Loop
  while (1) {
		
		osSignalWait(0x0001, osWaitForever);
		
		//sprintf(string, "Global Counter = %d", globalCounter);
		//EventRecordData((EventRecorder_CID | 0x07), string, strlen(string));
		
		printf("Test");
		//sprintf(string, "Test");
		//EventRecordData((EventRecorder_CID | 0x07), string, strlen(string));		
    
    osThreadYield();                                                
  }
	
}



/*----------------------------------------------------------------------------
 * main: blink LED and check button state
 *----------------------------------------------------------------------------*/
int main (void) {
  globalCounter = 0;
	

  osKernelInitialize ();                                            // initialize CMSIS-RTOS

  SystemCoreClockUpdate();

  LED_Initialize();                                                 // initalize LEDs
	
  Init_Thread_LED();                                              
  Init_Thread_01();                                             
  Init_Thread_02();                                              
  Init_Thread_03();                                               
  Init_Thread_04();                                                
  Init_Thread_05();                                                
  Init_Thread_06();   
	Init_Thread_Status();	

  osKernelStart ();                                                 // start thread execution
	
	EventRecorderInitialize(EventRecordAll, 1);
  EventRecorderStop();
  EventRecorderStart();
	
  for (;;) {                                                        // main must not be terminated!
    globalCounter++;
    osDelay(1000);
		
	  printf("Global Counter = %d", globalCounter);
		
		/*
    osSignalSet(tid_Thread_LED, 0x0001);
    osSignalSet(tid_Thread_01, 0x0001);
    osSignalSet(tid_Thread_02, 0x0001);
    osSignalSet(tid_Thread_03, 0x0001);
    osSignalSet(tid_Thread_04, 0x0001);
    osSignalSet(tid_Thread_05, 0x0001);
    osSignalSet(tid_Thread_06, 0x0001);
		*/
		
		osSignalSet(tid_Thread_Status, 0x0001);
  }
}