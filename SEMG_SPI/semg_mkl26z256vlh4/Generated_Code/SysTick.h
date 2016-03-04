/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : SysTick.h
**     Project     : ProcessorExpert
**     Processor   : MKL26Z256VLH4
**     Component   : Init_SysTick
**     Version     : Component 01.003, Driver 01.03, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-01-02, 19:11, # CodeGen: 275
**     Abstract    :
**          This file implements the SysTick (SysTick) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : SysTick
**          Device                                         : SysTick
**          Settings                                       : 
**            Clock source                                 : External clock
**            Reload value                                 : 000000
**            Counter period                               : STOP
**          Interrupts                                     : 
**            Interrupt                                    : INT_SysTick
**            Interrupt priority                           : 0 (Highest)
**            ISR Name                                     : SysTick_Interrupt
**            Timer interrupt                              : Enabled
**          Initialization                                 : 
**            Timer enable                                 : no
**            Clear counter                                : yes
**            Call Init method                             : no
**     Contents    :
**         Init - void SysTick_Init(void);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file SysTick.h
** @version 01.03
** @brief
**          This file implements the SysTick (SysTick) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup SysTick_module SysTick module documentation
**  @{
*/         

#ifndef SysTick_H_
#define SysTick_H_

/* MODULE SysTick. */

/* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

/* Peripheral base address parameter */
#define SysTick_DEVICE SysTick_BASE_PTR


/*
** ===================================================================
**     Method      :  SysTick_Init (component Init_SysTick)
**     Description :
**         This method initializes registers of the SysTick module
**         according to the Peripheral Initialization settings.
**         Call this method in user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void SysTick_Init(void);
/*
** ===================================================================
** The interrupt service routine must be implemented by user in one
** of the user modules (see SysTick.c file for more information).
** ===================================================================
*/
PE_ISR(SysTick_Interrupt);


/* END SysTick. */
#endif /* #ifndef __SysTick_H_ */
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