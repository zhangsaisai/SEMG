/* ###################################################################
**     Filename    : main.c
**     Project     : I2C_PE
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-11-02, 15:16, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "CI2C1.h"
#include "RED.h"
#include "BitIoLdd1.h"
#include "GREEN.h"
#include "BitIoLdd2.h"
#include "BLUE.h"
#include "BitIoLdd3.h"
#include "WAIT1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "PEimplementation.h"
#include "LSM303DLHC.h"


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
  
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  
  RED_PutVal(1);
  GREEN_PutVal(1);
  BLUE_PutVal(1);
  
  //Test Red
  RED_PutVal(0); //turns red on
  WAIT1_Waitms(1000);
  RED_PutVal(1); //turns red off
  
  //Test Green
  GREEN_PutVal(0); //turns green on
  WAIT1_Waitms(1000);
  GREEN_PutVal(1); //turns green off

  //Test Blue
  BLUE_PutVal(0); //turns blue on
  WAIT1_Waitms(1000);
  BLUE_PutVal(1); //turns blue off

  /* For example: for(;;) { } */
  for(;;){
	  LSM303_Init();
	  
	  float heading = SimpleHeading();
	  
	  //Turn on RED on North
	  if (heading >=45 && heading < 135){
		  RED_PutVal(0);
		  GREEN_PutVal(1);
		  BLUE_PutVal(1);
	  }
	  
	  //Turn on GREEN on West
	  else if(heading >= 135 && heading < 225){
		  RED_PutVal(1);
		  GREEN_PutVal(0);
		  BLUE_PutVal(1);
	  }
	  
	  //Turn on BLUE on South
	  else if(heading >= 225 && heading < 305){
		  RED_PutVal(1);
		  GREEN_PutVal(1);
		  BLUE_PutVal(0);
	  }
	  
	  //Turn on white on East
	  else if(heading >= 305 && heading < 45){
		  RED_PutVal(0);
		  GREEN_PutVal(0);
		  BLUE_PutVal(0);
	  }
	  
	  //Blink white on invalid
	  else{
		  int i;
		  for(i=0; i<10; i++){			  
			  RED_PutVal(0);		//Turn on red
			  WAIT1_Waitms(100);		//Green and Red
			  
			  GREEN_PutVal(1);		//Turn off green
			  WAIT1_Waitms(100);		//Just Red
			  
			  BLUE_PutVal(0);		//Turn on blue
			  WAIT1_Waitms(100);		//Blue and Red
			  
			  RED_PutVal(1);		//Turn off red
			  WAIT1_Waitms(100);		//Just Blue
			  
			  GREEN_PutVal(0);		//Turn on Green
			  WAIT1_Waitms(100);		//Green and Blue
			  
			  BLUE_PutVal(1);		//Turn off blue
			  WAIT1_Waitms(100);		//Just Green
		  }
	  }
	  
	  LSM303_Deinit();
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

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
