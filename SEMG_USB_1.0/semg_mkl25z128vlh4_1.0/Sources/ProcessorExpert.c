/* ###################################################################
 **     Filename    : ProcessorExpert.c
 **     Project     : semg_mkl15z128vlh4
 **     Processor   : MKL26Z256VLH4
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-07-11, 23:27, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 **     Mail        : pzdongdong@163.com
 **
 **     Revision    : No.  Name        Date/Time        Content
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
#include "SM_SPI0.h"
#include "SS_SPI1.h"
#include "SysTick.h"
#include "BitIO_AD_NOT_RESET0.h"
#include "BitIO_AD_START0.h"
#include "EINT_AD_NOT_DRDY0.h"
#include "EINT_SYNC_INT.h"
#include "DMAT_M_SPI_TX.h"
#include "DMA_CTRL.h"
#include "DMAT_M_SPI_RX.h"
#include "DMAT_S_SPI_TX.h"
#include "DMAT_S_SPI_RX.h"
#include "BitIO_AD_NOT_CS1.h"
#include "BitIO_AD_NOT_RESET1.h"
#include "usb_device.h"
#include "USB_LDD.h"
//#include "BitIO_AD_NOT_RESET1.h"
#include "BitIO_UPRDY.h"
#include "BitIO_AD_NOT_CS0.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "SPI_PDD.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "MyHeaders.h"


uint8       Init_State = 100;//Init procdure is not finished
uint16      Period = 100;//Init communication period 100ms
/*
 * ===================================================================
 * Macros
 * ===================================================================
 */

/*
 * ===================================================================
 * Global Variables
 * ===================================================================
 */

/*
 * ===================================================================
 * Main Function
 * ===================================================================
 */
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
/*!
 *     @brief
 *          The main function of the project.
 *     @param
 *          void
 *     @return
 *          int
 */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
    /* Write your local variable definition here */

    /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
    PE_low_level_init();
    /*** End of Processor Expert internal initialization.                    ***/

    /* Write your code here */
    /* For example: for(;;) { } */
    (void)TestApp_Init(); /* Initialize the USB Test Application */
    /* Initialize on-chip and peripheral devices */
#if DEBUG
    GPIOTest();
    printf("+UserInit begins...\n");
#endif
    UserInit();
#if DEBUG
    printf("-UserInit finished.\n");
#endif

#if DEBUG
    GPIOTest();
#endif
    
    Init_State = 200;//Init is OK
    /* The main loop */
    MainLoop();

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
 **     This file was created by Processor Expert 10.2 [05.06]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
