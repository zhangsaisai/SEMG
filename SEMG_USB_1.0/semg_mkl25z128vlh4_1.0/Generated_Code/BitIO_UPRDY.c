/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : BitIO_UPRDY.c
**     Project     : ProcessorExpert
**     Processor   : MKL15Z128VLH4
**     Component   : BitIO_LDD
**     Version     : Component 01.033, Driver 01.03, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-03-17, 16:48, # CodeGen: 199
**     Abstract    :
**         The HAL BitIO component provides a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL BitIO API are simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : BitIO_UPRDY
**          Pin for I/O                                    : CMP0_IN5/ADC0_SE4b/PTE29/TPM0_CH2/TPM_CLKIN0
**          Pin signal                                     : BitIO_UPRDY
**          Direction                                      : Output
**          Initialization                                 :
**            Init. direction                              : Output
**            Init. value                                  : 1
**            Auto initialization                          : no
**          Safe mode                                      : no
**     Contents    :
**         Init   - LDD_TDeviceData* BitIO_UPRDY_Init(LDD_TUserData *UserDataPtr);
**         GetVal - bool BitIO_UPRDY_GetVal(LDD_TDeviceData *DeviceDataPtr);
**         PutVal - void BitIO_UPRDY_PutVal(LDD_TDeviceData *DeviceDataPtr, bool Val);
**         ClrVal - void BitIO_UPRDY_ClrVal(LDD_TDeviceData *DeviceDataPtr);
**         SetVal - void BitIO_UPRDY_SetVal(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file BitIO_UPRDY.c
** @version 01.03
** @brief
**         The HAL BitIO component provides a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL BitIO API are simpler and more
**         portable to various microprocessors.
*/
/*!
**  @addtogroup BitIO_UPRDY_module BitIO_UPRDY module documentation
**  @{
*/

/* MODULE BitIO_UPRDY. */

/* {Default RTOS Adapter} No RTOS includes */
#include "BitIO_UPRDY.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
** ===================================================================
**     Method      :  BitIO_UPRDY_Init (component BitIO_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the "Enable
**         in init. code" is set to "yes" value then the device is also
**         enabled(see the description of the Enable() method). In this
**         case the Enable() method is not necessary and needn't to be
**         generated.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* BitIO_UPRDY_Init(LDD_TUserData *UserDataPtr)
{
  /* Configure pin as output */
  /* GPIOE_PDDR: PDD|=0x20000000 */
  GPIOE_PDDR |= GPIO_PDDR_PDD(0x20000000);
  /* Set initialization value */
  /* GPIOE_PDOR: PDO|=0x20000000 */
  GPIOE_PDOR |= GPIO_PDOR_PDO(0x20000000);
  /* Initialization of Port Control register */
  /* PORTE_PCR29: ISF=0,MUX=1 */
  PORTE_PCR29 = (uint32_t)((PORTE_PCR29 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x06)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x01)
                ));
  return ERR_OK;
}
/*
** ===================================================================
**     Method      :  BitIO_UPRDY_GetVal (component BitIO_LDD)
*/
/*!
**     @brief
**         Returns the input/output value. If the direction is [input]
**         then the input value of the pin is read and returned. If the
**         direction is [output] then the last written value is read
**         and returned (see <Safe mode> property for limitations).
**         This method cannot be disabled if direction is [input].
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Input or output value. Possible values:
**                           <false> - logical "0" (Low level)
**                           <true> - logical "1" (High level)
*/
/* ===================================================================*/
bool BitIO_UPRDY_GetVal(LDD_TDeviceData *DeviceDataPtr)
{
  uint32_t PortData;                   /* Port data masked according to the bit used */

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  PortData = GPIO_PDD_GetPortDataOutput(BitIO_UPRDY_MODULE_BASE_ADDRESS) & BitIO_UPRDY_PORT_MASK;
  return (PortData != 0U) ? (bool)TRUE : (bool)FALSE;
}

/*
** ===================================================================
**     Method      :  BitIO_UPRDY_PutVal (component BitIO_LDD)
*/
/*!
**     @brief
**         The specified output value is set. If the direction is <b>
**         input</b>, the component saves the value to a memory or a
**         register and this value will be written to the pin after
**         switching to the output mode (using <tt>SetDir(TRUE)</tt>;
**         see <a href="BitIOProperties.html#SafeMode">Safe mode</a>
**         property for limitations). If the direction is <b>output</b>,
**         it writes the value to the pin. (Method is available only if
**         the direction = <u><tt>output</tt></u> or <u><tt>
**         input/output</tt></u>).
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Val             - Output value. Possible values:
**                           <false> - logical "0" (Low level)
**                           <true> - logical "1" (High level)
*/
/* ===================================================================*/
void BitIO_UPRDY_PutVal(LDD_TDeviceData *DeviceDataPtr, bool Val)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  if (Val) {
    GPIO_PDD_SetPortDataOutputMask(BitIO_UPRDY_MODULE_BASE_ADDRESS, BitIO_UPRDY_PORT_MASK);
  } else { /* !Val */
    GPIO_PDD_ClearPortDataOutputMask(BitIO_UPRDY_MODULE_BASE_ADDRESS, BitIO_UPRDY_PORT_MASK);
  } /* !Val */
}

/*
** ===================================================================
**     Method      :  BitIO_UPRDY_ClrVal (component BitIO_LDD)
*/
/*!
**     @brief
**         Clears (set to zero) the output value. It is equivalent to
**         the [PutVal(FALSE)]. This method is available only if the
**         direction = _[output]_ or _[input/output]_.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure returned by <Init> method.
*/
/* ===================================================================*/
void BitIO_UPRDY_ClrVal(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  GPIO_PDD_ClearPortDataOutputMask(BitIO_UPRDY_MODULE_BASE_ADDRESS, BitIO_UPRDY_PORT_MASK);
}

/*
** ===================================================================
**     Method      :  BitIO_UPRDY_SetVal (component BitIO_LDD)
*/
/*!
**     @brief
**         Sets (to one) the output value. It is equivalent to the
**         [PutVal(TRUE)]. This method is available only if the
**         direction = _[output]_ or _[input/output]_.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure returned by <Init> method.
*/
/* ===================================================================*/
void BitIO_UPRDY_SetVal(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  GPIO_PDD_SetPortDataOutputMask(BitIO_UPRDY_MODULE_BASE_ADDRESS, BitIO_UPRDY_PORT_MASK);
}

/* END BitIO_UPRDY. */

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
