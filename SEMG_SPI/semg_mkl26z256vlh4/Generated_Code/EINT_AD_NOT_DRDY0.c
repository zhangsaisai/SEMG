/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : EINT_AD_NOT_DRDY0.c
**     Project     : ProcessorExpert
**     Processor   : MKL26Z256VLH4
**     Component   : ExtInt_LDD
**     Version     : Component 02.156, Driver 01.02, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-01-02, 19:11, # CodeGen: 275
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
** @file EINT_AD_NOT_DRDY0.c
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

/* MODULE EINT_AD_NOT_DRDY0. */

#include "Events.h"
#include "EINT_AD_NOT_DRDY0.h"
/* {Default RTOS Adapter} No RTOS includes */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  bool UserEnabled;                    /* Enable/disable device flag */
  LDD_TUserData *UserData;             /* RTOS device data structure */
} EINT_AD_NOT_DRDY0_TDeviceData, *EINT_AD_NOT_DRDY0_TDeviceDataPtr; /* Device data structure type */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static EINT_AD_NOT_DRDY0_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static EINT_AD_NOT_DRDY0_TDeviceData * INT_PORTA__DEFAULT_RTOS_ISRPARAM;

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
LDD_TDeviceData* EINT_AD_NOT_DRDY0_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate LDD device structure */
  EINT_AD_NOT_DRDY0_TDeviceData *DeviceDataPrv;

  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  /* Store the UserData pointer */
  DeviceDataPrv->UserData = UserDataPtr;
  /* Set device as Disable */
  DeviceDataPrv->UserEnabled = FALSE;
  /* Interrupt vector(s) allocation */
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_PORTA__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
  /* Clear interrupt status flag */
  PORTA_ISFR = PORT_ISFR_ISF(0x02);
  /* Initialization of Port Control registers */
  /* PORTA_PCR1: ISF=0,IRQC=0x0A,MUX=1 */
  PORTA_PCR1 = (uint32_t)((PORTA_PCR1 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_IRQC(0x05) |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_IRQC(0x0A) |
                PORT_PCR_MUX(0x01)
               ));
  /* NVIC_IPR7: PRI_30=0x80 */
  NVIC_IPR7 = (uint32_t)((NVIC_IPR7 & (uint32_t)~(uint32_t)(
               NVIC_IP_PRI_30(0x7F)
              )) | (uint32_t)(
               NVIC_IP_PRI_30(0x80)
              ));
  /* NVIC_ISER: SETENA|=0x40000000 */
  //NVIC_ISER |= NVIC_ISER_SETENA(0x40000000);
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_EINT_AD_NOT_DRDY0_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

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
void EINT_AD_NOT_DRDY0_Enable(LDD_TDeviceData *DeviceDataPtr)
{
  EINT_AD_NOT_DRDY0_TDeviceData *DeviceDataPrv = (EINT_AD_NOT_DRDY0_TDeviceData *)DeviceDataPtr;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  PORT_PDD_ClearPinInterruptFlag(PORTA_BASE_PTR, EINT_AD_NOT_DRDY0_PIN_INDEX);
  PORT_PDD_SetPinInterruptConfiguration(PORTA_BASE_PTR,
    EINT_AD_NOT_DRDY0_PIN_INDEX, PORT_PDD_INTERRUPT_ON_FALLING);
  DeviceDataPrv->UserEnabled = TRUE;   /* Set device as Enabled */
}

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
void EINT_AD_NOT_DRDY0_Disable(LDD_TDeviceData *DeviceDataPtr)
{
  EINT_AD_NOT_DRDY0_TDeviceData *DeviceDataPrv = (EINT_AD_NOT_DRDY0_TDeviceData *)DeviceDataPtr;

  PORT_PDD_SetPinInterruptConfiguration(PORTA_BASE_PTR,
    EINT_AD_NOT_DRDY0_PIN_INDEX, PORT_PDD_INTERRUPT_DMA_DISABLED);
  DeviceDataPrv->UserEnabled = FALSE;  /* Set device as Disabled */
}

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
void EINT_AD_NOT_DRDY0_Interrupt(void)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  EINT_AD_NOT_DRDY0_TDeviceDataPtr DeviceDataPrv = INT_PORTA__DEFAULT_RTOS_ISRPARAM;

  /* Check if the component is disabled */
  if (!DeviceDataPrv->UserEnabled) {
    return;
  }
  /* Check the pin interrupt flag of the shared interrupt */
  if (PORT_PDD_GetPinInterruptFlag(PORTA_BASE_PTR, EINT_AD_NOT_DRDY0_PIN_INDEX)) {
    /* Clear the interrupt flag */
    PORT_PDD_ClearPinInterruptFlag(PORTA_BASE_PTR, EINT_AD_NOT_DRDY0_PIN_INDEX);
    /* Call OnInterrupt event */
    EINT_AD_NOT_DRDY0_OnInterrupt(DeviceDataPrv->UserData);
  }
}

/* END EINT_AD_NOT_DRDY0. */

#ifdef __cplusplus
}  /* extern "C" */
#endif

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
