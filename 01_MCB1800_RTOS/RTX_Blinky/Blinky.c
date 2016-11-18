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
		
		EventRecord2((EventRecorder_CID | 0x00), threadCounter, threadCounter);
		    
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
		EventRecord2((EventRecorder_CID | 0x01), threadCounter, threadCounter);
  
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
		EventRecord2((EventRecorder_CID | 0x02), threadCounter, threadCounter);
    
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
		EventRecord2((EventRecorder_CID | 0x03), threadCounter, threadCounter);
    
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
		EventRecord2((EventRecorder_CID | 0x04), threadCounter, threadCounter);
    
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
		EventRecord2((EventRecorder_CID | 0x05), threadCounter, threadCounter);
    
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
		EventRecord2((EventRecorder_CID | 0x06), threadCounter, threadCounter);
    
    osThreadYield();                                                
  }
}

/*----------------------------------------------------------------------------
 * main: blink LED and check button state
 *----------------------------------------------------------------------------*/
int main (void) {

  osKernelInitialize ();                                          
  SystemCoreClockUpdate();
  LED_Initialize();                                                 
	
  Init_Thread_LED(); 
	/*	
  Init_Thread_01();                                             
  Init_Thread_02();                                              
  Init_Thread_03();                                               
  Init_Thread_04();                                                
  Init_Thread_05();                                                
  Init_Thread_06();   
	*/


  osKernelStart ();                                                
	
	EventRecorderInitialize(EventRecordAll, 1);
  EventRecorderStop();
  EventRecorderStart();
	
  for (;;) {                                                      

    osDelay(1000);				
    osSignalSet(tid_Thread_LED, 0x0001);
		/*
    osSignalSet(tid_Thread_01, 0x0001);
    osSignalSet(tid_Thread_02, 0x0001);
    osSignalSet(tid_Thread_03, 0x0001);
    osSignalSet(tid_Thread_04, 0x0001);
    osSignalSet(tid_Thread_05, 0x0001);
    osSignalSet(tid_Thread_06, 0x0001);
		*/
		
  }
}
