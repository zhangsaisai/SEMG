/** ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-07-09, 11:32, # CodeGen: 0
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
#include "CsIO1.h"
#include "IO1.h"
#include "SM1.h"
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "Bit1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include <stdio.h>
#include <string.h>

  byte msgMaster[] = "Start!";
  byte msgSlave[] = "Accept";
  byte msgDummy[] = "------"; /* must be the same length as msgSlave */
  byte buffMaster[6]; /* master gets msg from slave */
  byte buffSlave[6]; /* slave gets msg from master */
  byte buffDummy[6]; /* master's buffer for dummy data */
  bool read_data=0;//100ms is up , master read data

  LDD_TDeviceData *slaveDevData;
  LDD_TDeviceData *masterDevData;
  LDD_TError err;
  
  int i;
int main(void)
{
  /* Write your local variable definition here */
  uint8_t MasterReceiveFlag = FALSE; 
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  masterDevData = SM1_Init(&MasterReceiveFlag);

  //printf("PTD3 and PTE1\n\r");
  //printf("PTD2 and PTE3\n\r");
  //printf("PTD1 and PTE2\n\r");
  //printf("PTD0 and PTE4\n\r");
  //printf("\n\r"); 
  
  
  //Put request for reading from SPI
  //SS1_ReceiveBlock(slaveDevData, (LDD_TData*)buffSlave, sizeof(buffSlave)); 
  
  for(;;)
  {
	  
	  while(read_data)
	  {
	  //when slave receive the data , "SM1_ReceiveBlock" is not necessary
	  //Prepare master for dummy data from slave
	  //SM1_ReceiveBlock(masterDevData, (LDD_TData*)&buffDummy, sizeof(buffDummy)); 
	
	  //Master sends request to slave
	  SM1_SendBlock(masterDevData, (LDD_TData*)msgMaster, sizeof(msgMaster) );
	
	  //To provide clock for slave, master sends anything that is as long as expected answer from slave. length(msgDummy) = length(msgSlave)
	  SM1_SendBlock(masterDevData, (LDD_TData*)msgDummy, sizeof(msgDummy) );  
	
	  
	  //Put request for reading from SPI
	  err = SM1_ReceiveBlock(masterDevData, (LDD_TData*)buffMaster, sizeof(buffMaster)); 
	  if (err != ERR_OK) { 
		  //printf(" ERROR requesting read operation (master).\n\r");
	  }
	  
	  
	  //Master waits for data from slave
	  MasterReceiveFlag = FALSE;
	  while(!MasterReceiveFlag);
	  //Compare sent and received message
	  //printf("Data path slave -> master: ");
	  if (strcmp((char*)buffMaster, (char*)msgSlave) == 0) { 
		printf("Result: PASSED\n\r");	
	  } else {
		printf("Result: FAILED !!!\n\r");
	  }
	  
	  read_data = 0;
	  //printf("+++ Step 1 - end +++\n\r");
	  

	  
	  }
	  
	  
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
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/



/* END ProcessorExpert */
/*
** ###################################################################
**
**     This file was created by Processor Expert 0.00.00 [05.02]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
