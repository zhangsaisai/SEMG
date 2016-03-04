/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VFT4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-01-14, 10:27, # CodeGen: 0
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
#include "SysTick.h"
#include "SCL_G.h"
#include "SDA_G.h"
#include "SCL_M.h"
#include "SDA_M.h"
#include "usb_device.h"
#include "USB_LDD.h"
#include "MPU6050_DRDY.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "delay.h"
#include "function.h"
#include "hmc5883.h"
#include "mpu6050.h"
//#include "uart.h"

uint16 TimingDelay;
short max_Mx,max_My,max_Mz,min_Mx,min_My,min_Mz;
float Mx_offset,My_offset,Mz_offset;
float Mx_gain=1;
float My_gain=1;
float Mz_gain=1;
float pitch,roll,yaw;


uint8       MCU_NUMBER = 0x0B; 
uint8       Init_State = 100;//MCU Init State is 0
uint8       DataReady = FALSE;

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
  short Ax,Ay,Az,Mx,My,Mz,Gx,Gy,Gz;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  
  /* Write your code here */

  TestApp_Init(); /* Initialize the USB Test Application */

  UserInit();
  
  Init_State = 200;//after MEMS init complete,Init_State = 200 
  
  time_delay_us(5);
  
  SwapARMDataBuffer();//ARM Init:tARMPtr->armStatus.foreBufferStatus == eNull,need to swap buffer to set the buffer empty
  
  
  while(1){
	  ReadData();
	  Process();
  }
  
  
  /* For example: for(;;) { } */

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
