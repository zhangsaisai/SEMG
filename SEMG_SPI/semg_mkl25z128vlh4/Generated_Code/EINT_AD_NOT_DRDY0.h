/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : EINT_AD_NOT_DRDY0.h
**     Project     : ProcessorExpert
**     Processor   : MKL15Z128VLH4
**     Component   : ExtInt_LDD
**     Version     : Component 02.156, Driver 01.02, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-03-27, 22:11, # CodeGen: 222
**     Abstract    :
**         This component, "ExtInt_LDD", provide a low level API 
**         for unified access of external interrupts handling
**         across various device designs.
**         The component uses one pin which generates interrupt on 
**         selected edge.
**     Settings    :
**          Component name                                 : EINT_AD_NOT_DRDY0
**          Pin                                            : TSI0_CH2/PTA1/UART0_RX/TPM2_CH0
**          Pin signal                                     : AD_NOT_DRDY0
**          Generate interrupt on                          : falling edge
**          Interrupt                                      : INT_PORTA
**          Interrupt priority                             : medium priority
**          Initialization                                 : 
**            Enabled in init. code                        : no
**            Auto initialization                          : no
**          Threshold level                                : 0
**     Contents    :
**         Init    - LDD_TDeviceData* EINT_AD_NOT_DRDY0_Init(LDD_TUserData *UserDataPtr);
**         Enable  - void EINT_AD_NOT_DRDY0_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable - void EINT_AD_NOT_DRDY0_Disable(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file EINT_AD_NOT_DRDY0.h
** @version 01.02
** @brief
**         This component, "ExtInt_LDD", provide a low level API 
**         for unified access of external interrupts handling
**         across various device designs.
**         The component uses one pin which generates interrupt on 
**         selected edge.
*/         
/*!
**  @addtogroup EINT_AD_NOT_DRDY0_module EINT_AD_NOT_DRDY0 module documentation
**  @{
*/         

#ifndef __EINT_AD_NOT_DRDY0_H
#define __EINT_AD_NOT_DRDY0_H

/* MODULE EINT_AD_NOT_DRDY0. */

#include "Cpu.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "GPIO_PDD.h"
#include "PORT_PDD.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define EINT_AD_NOT_DRDY0_PRPH_BASE_ADDRESS  0x400FF000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define EINT_AD_NOT_DRDY0_Init_METHOD_ENABLED /*!< Init method of the component EINT_AD_NOT_DRDY0 is enabled (generated) */
#define EINT_AD_NOT_DRDY0_Enable_METHOD_ENABLED /*!< Enable method of the component EINT_AD_NOT_DRDY0 is enabled (generated) */
#define EINT_AD_NOT_DRDY0_Disable_METHOD_ENABLED /*!< Disable method of the component EINT_AD_NOT_DRDY0 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define EINT_AD_NOT_DRDY0_OnInterrupt_EVENT_ENABLED /*!< OnInterrupt event of the component EINT_AD_NOT_DRDY0 is enabled (generated) */

/* Definition of implementation constants */
#define EINT_AD_NOT_DRDY0_PIN_INDEX 0x01U /*!< Index of the used pin from the port */
#define EINT_AD_NOT_DRDY0_PIN_MASK 0x02U /*!< Mask of the used pin from the port */

/*
** ===================================================================
**     Method      :  EINT_AD_NOT_DRDY0_Init (component ExtInt_LDD)
*/
/*!
**     @brief
**         This method initializes the associated peripheral(s) and the
**         component internal variables. The method is called
**         automatically as a part of the application initialization
**         code.
**     @param
**         UserDataPtr     - Pointer to the RTOS device
**                           structure. This pointer will be passed to
**                           all events as parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* EINT_AD_NOT_DRDY0_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  EINT_AD_NOT_DRDY0_Enable (component ExtInt_LDD)
*/
/*!
**     @brief
**         Enable the component - the external events are accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void EINT_AD_NOT_DRDY0_Enable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  EINT_AD_NOT_DRDY0_Disable (component ExtInt_LDD)
*/
/*!
**     @brief
**         Disable the component - the external events are not accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void EINT_AD_NOT_DRDY0_Disable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  EINT_AD_NOT_DRDY0_Interrupt (component ExtInt_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
void EINT_AD_NOT_DRDY0_Interrupt(void);

/* END EINT_AD_NOT_DRDY0. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __EINT_AD_NOT_DRDY0_H */
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
