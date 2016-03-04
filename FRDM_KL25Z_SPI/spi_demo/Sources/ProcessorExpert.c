/** ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-08-08, 16:59, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Blue_LED.h"
#include "Green_LED.h"
#include "Red_LED.h"
#include "CsIO1.h"
#include "IO1.h"
#include "SM1.h"
#include "SS1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "stdio.h"
#include <string.h>

/* Global Variables */
#define COMM_SIZE 1
#define DATA_SIZE 14

volatile bool SlaveReceivedFlg = FALSE;
volatile bool MasterReceivedFlg = FALSE;

char master_send[14]    = {0};
char slave_send[14]     = {0};
char master_receive[14] = {0};
char slave_receive[14]  = {0};

int main(void)
{
  /* Write your local variable definition here */
  uint32 i = 0;

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  
 printf ("\n\n");  
 printf("********************************************************\n");
 printf("*                                                       \n");
 printf("* Running SPI Demo, Master & Slave exchanged messages   \n");
 printf("* Before continuing connect SPI0(Master)         \n");
 printf("* to SPI1 (Slave) as outlined below              \n"); 
 printf("*                                                \n"); 
 printf("* MOSI:  PTA17 (J2 pin 11) to PTE1 (J2 pin 20)   \n");
 printf("* MISO:  PTA16 (J2 pin  9) to PTE3 (J9 pin 11)   \n");
 printf("* SCK:   PTC5  (J1 pin  9) to PTE2 (J9 pin  9)   \n");
 printf("* PCS0:  PTC4  (J1 pin  7) to PTE4 (J9 pin 13)   \n");
 printf("*                                                \n");
 printf("* Then enter any key to continue                 \n");
 printf("*                                                \n");
 printf("********************************************************\n");
 printf ("\n\n");
  
  /* BLUE LED ON */ 
  Blue_LED_ClrVal(Blue_LED_DeviceData);   
  
  /* Slave sends dummy message and waits for receiving some message from master*/
  //SS1_SendBlock(SS1_DeviceData, slave_send, COMM_SIZE);
  SS1_ReceiveBlock(SS1_DeviceData, slave_receive, COMM_SIZE); 

  for(;;){
 
  /* Master sends message 1  */ 
  printf("\n\nMaster: Send command start...\n");   
  master_send[0] = 0x01;  
  SM1_SendBlock(SM1_DeviceData, master_send, COMM_SIZE);   
  //SM1_ReceiveBlock(SM1_DeviceData, master_receive_comm, COMM_SIZE);
  
   /* waiting for transferring completed  */ 
  //MasterReceivedFlg = FALSE;
  //while(!MasterReceivedFlg); 
   
  for(i=0;i<1000;i++){} //Delay
  
  /* Master sends dummy message to receive response from slave */
  master_send[0] = 0x03; 
  SM1_SendBlock(SM1_DeviceData, master_send, DATA_SIZE);   
  SM1_ReceiveBlock(SM1_DeviceData, master_receive, DATA_SIZE);
   
   /* waiting for transferring completed  */  
  //MasterReceivedFlg = FALSE;
  //while(!MasterReceivedFlg);   
        
  for(i=0;i<1000000;i++){} //Delay
   }
   

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
  return 0;
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.02]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
