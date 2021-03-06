/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : MPU6050_DRDY.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VFT4
**     Component   : ExtInt_LDD
**     Version     : Component 02.156, Driver 01.02, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-09-17, 10:04, # CodeGen: 56
**     Abstract    :
**         This component, "ExtInt_LDD", provide a low level API 
**         for unified access of external interrupts handling
**         across various device designs.
**         The component uses one pin which generates interrupt on 
**         selected edge.
**     Settings    :
**          Component name                                 : MPU6050_DRDY
**          Pin                                            : TSI0_CH2/PTA1/UART0_RX/TPM2_CH0
**          Pin signal                                     : 
**          Generate interrupt on                          : rising edge
**          Interrupt                                      : INT_PORTA
**          Interrupt priority                             : medium priority
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**          Threshold level                                : 0
**     Contents    :
**         Init - LDD_TDeviceData* MPU6050_DRDY_Init(LDD_TUserData *UserDataPtr);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file MPU6050_DRDY.h
** @version 01.02
** @brief
**         This component, "ExtInt_LDD", provide a low level API 
**         for unified access of external interrupts handling
**         across various device designs.
**         The component uses one pin which generates interrupt on 
**         selected edge.
*/         
/*!
**  @addtogroup MPU6050_DRDY_module MPU6050_DRDY module documentation
**  @{
*/         

#ifndef __MPU6050_DRDY_H
#define __MPU6050_DRDY_H

/* MODULE MPU6050_DRDY. */

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
#define MPU6050_DRDY_PRPH_BASE_ADDRESS  0x400FF000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define MPU6050_DRDY_Init_METHOD_ENABLED /*!< Init method of the component MPU6050_DRDY is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define MPU6050_DRDY_OnInterrupt_EVENT_ENABLED /*!< OnInterrupt event of the component MPU6050_DRDY is enabled (generated) */

/* Definition of implementation constants */
#define MPU6050_DRDY_PIN_INDEX 0x01U   /*!< Index of the used pin from the port */
#define MPU6050_DRDY_PIN_MASK 0x02U    /*!< Mask of the used pin from the port */

/*
** ===================================================================
**     Method      :  MPU6050_DRDY_Init (component ExtInt_LDD)
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
LDD_TDeviceData* MPU6050_DRDY_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  MPU6050_DRDY_Interrupt (component ExtInt_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(MPU6050_DRDY_Interrupt);

/* END MPU6050_DRDY. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __MPU6050_DRDY_H */
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
