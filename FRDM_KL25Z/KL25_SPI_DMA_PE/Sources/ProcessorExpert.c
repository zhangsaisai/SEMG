/*
 * ProcessorExpert.c
 *
 *  Created on: Sep 9, 2015
 *      Author: lab
 */
/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-07-06, 16:14, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "SS_SPI1.h"
#include "DMAT_S_SPI_TX.h"
#include "DMA_CTRL.h"
#include "DMAT_S_SPI_RX.h"
#include "SM_SPI0.h"
#include "Globals.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Aliases.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

  uint8 writedata[16] = "send_message0";
  uint8 *source_address=NULL;
  uint8 SlaveReceiveFlag = FALSE; //whether slave has receive data from master
  byte read_data[16] = "";
  byte msgMaster[16] = "";
  byte msgDummy[16] = "send_to_M"; /* must be the same length as msgSlave */
  byte buffSlave[16]=""; /* slave gets msg from master */
  byte buffDummy[16]=""; /* master's buffer for dummy data */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
  uint8 i,j = 0;
  LDD_TError err;
  uint8_t MasterReceiveFlag = FALSE; 
  source_address = (uint8 *)malloc(16*sizeof(uint8));
  byte msgMaster[] = "world!";
  byte msgSlave[] = "Hello!";
  byte msgDummy[] = "HAHAHA"; /* must be the same length as msgSlave */
  byte buffMaster[sizeof(msgSlave)]; /* master gets msg from slave */
  byte buffSlave[sizeof(msgMaster)]; /* slave gets msg from master */
  byte buffDummy[sizeof(msgMaster)]; /* master's buffer for dummy data */
  
  
  //DEMO project for the SPI DMA component - begin\n\r
  //PTD3 and PTE1\n\r
  //PTD2 and PTE3\n\r
  //PTD1 and PTE2\n\r
  //PTD0 and PTE4\n\r
  
  
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  
  //DMA INIT
  DMA_CTRL = DMAControllerInit(NULL);
  DMAControllerEnable();
  SPI1_TX_DMA = SPI1TxDMAInit(NULL);
  SPI1TxDMAAllocateChannel();
  SPI1_RX_DMA = SPI1RxDMAInit(NULL);
  SPI1RxDMAAllocateChannel();
  
  //SPI INIT
  SPI0 = SPI0Init( &MasterReceiveFlag );
  SPI1 = SPI1Init(NULL);
  SPI1Enable();
  /* Write your code here */
  while(1){
	  
	   //Put request for reading from SPI
	   SM_SPI0_ReceiveBlock(SPI0, (LDD_TData*)buffMaster, sizeof(buffMaster));
	   
	   //SS_SPI1_SendBlock(SPI1, (LDD_TData*)msgSlave, sizeof(msgSlave) );  
	   SPI1SendData((LDD_DMA_TAddress)msgSlave, sizeof(msgSlave));
	   
	   //To provide clock for slave, master sends anything that is as long as expected answer from slave. length(msgDummy) = length(msgSlave) 
	   SM_SPI0_SendBlock(SPI0, (LDD_TData*)msgDummy, sizeof(msgDummy) );  
	   
	   
	   //Master waits for data from slave
	   MasterReceiveFlag = FALSE;
	   while(!MasterReceiveFlag);
	   //Compare sent and received message 
	   //printf("Data path slave -> master: ");
	   if (strcmp((char*)buffMaster, (char*)msgSlave) == 0) { 
	     //printf("Result: PASSED\n\r");	
	   } else {
	     //printf("Result: FAILED !!!\n\r");
	   }  
	  for(i=0;i<255;i++);
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
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/


