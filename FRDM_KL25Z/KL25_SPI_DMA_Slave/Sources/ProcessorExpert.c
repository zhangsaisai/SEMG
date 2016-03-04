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
#include "Globals.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Aliases.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

byte msgMaster[6] = "Start!";//master sned to slave
byte msgSlave[6] = "Accept";//Slave send to master
byte msgDummy[6] = "------"; /* must be the same length as msgSlave */
byte buffMaster[6]; /* master gets msg from slave */
byte buffSlave[6]; /* slave gets msg from master */
byte buffDummy[6]; /* master's buffer for dummy data */
LDD_TError err;
  
  
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
  uint8 i,j = 0;
  LDD_TError err;
  uint8_t MasterReceiveFlag = FALSE; 
 
  //DEMO project for the SPI DMA component - begin\n\r
  //PTA17 and PTE1\n\r
  //PTA16 and PTE3\n\r
  //PTC5 and PTE2\n\r
  //PTC4 and PTE4\n\r
  
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
  SPI1 = SPI1Init(NULL);
  SPI1Enable();
  
  //clear data receive flag
  ((SS_SPI1_TDeviceDataPtr)SPI1)->SerFlag &= (uint8_t)(~(uint8_t)BLOCK_RECEIVED);
  //first enable interrupt
  SS_SPI1_ReceiveBlock(SPI1, (LDD_TData*)buffSlave, sizeof(buffSlave));
  
  while(1){
	  
	  //从机在收到主机命令之前一直循环
	  while(1)
	  {
			//data receive has done
		    //while (SS_SPI1_GetBlockReceivedStatus(SPI1) == FALSE) ;
		  
		    //clear data receive flag
			//((SS_SPI1_TDeviceDataPtr)SPI1)->SerFlag &= (uint8_t)(~(uint8_t)BLOCK_RECEIVED); /* Clear data block received flag */		     			  
		  
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


