/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : DMAT_M_SPI_RX.h
**     Project     : ProcessorExpert
**     Processor   : MKL26Z256VLH4
**     Component   : DMATransfer_LDD
**     Version     : Component 01.100, Driver 01.08, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-01-02, 22:24, # CodeGen: 277
**     Abstract    :
**          This embedded component implements
**          a DMA transfer channel descriptor definition.
**     Settings    :
**          Component name                                 : DMAT_M_SPI_RX
**          DMA controller device                          : DMA_CTRL
**          Channel                                        : 
**            Channel select                               : Fixed
**              Channel                                    : DMA_Channel1
**              Interrupts                                 : Enabled
**              Allocate channel                           : yes
**          Trigger                                        : 
**            Trigger source type                          : Peripheral device
**              Trigger source                             : SPI0_Receive_DMA_Request
**              Periodic trigger                           : Disabled
**          Data source                                    : 
**            External object declaration                  : volatile byte* SPI0RxDMADataSourceBuffer = NULL;
**            Address                                      : (&SPI0_DL)
**            Transfer size                                : 8-bit
**            Address offset                               : 0
**            Circular buffer                              : Buffer disabled
**          Data destination                               : 
**            External object declaration                  : volatile byte* SPI0RxDMADataDestinationBuffer = NULL;
**            Address                                      : SPI0RxDMADataDestinationBuffer
**            Transfer size                                : 8-bit
**            Address offset                               : 1
**            Circular buffer                              : Buffer disabled
**          Data size                                      : 
**            External object declaration                  : volatile uint8_t SPI0RxDMAByteCount = 0;
**            Value                                        : SPI0RxDMAByteCount
**          Transfer control                               : Cycle-steal
**            Disable after transfer                       : yes
**            Asynchronous requests                        : Disabled
**            Channel linking                              : Disabled
**            After request complete                       : No action
**            After transfer complete                      : No action
**          Initialization                                 : 
**            Auto initialization                          : no
**            Half complete                                : Disabled
**            Event mask                                   : 
**              OnComplete                                 : Enabled
**              OnError                                    : Enabled
**     Contents    :
**         Init                  - LDD_TDeviceData* DMAT_M_SPI_RX_Init(LDD_TUserData *UserDataPtr);
**         Deinit                - void DMAT_M_SPI_RX_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         AllocateChannel       - LDD_TError DMAT_M_SPI_RX_AllocateChannel(LDD_TDeviceData *DeviceDataPtr);
**         EnableChannel         - LDD_TError DMAT_M_SPI_RX_EnableChannel(LDD_TDeviceData *DeviceDataPtr);
**         DisableChannel        - LDD_TError DMAT_M_SPI_RX_DisableChannel(LDD_TDeviceData *DeviceDataPtr);
**         SetSourceAddress      - LDD_TError DMAT_M_SPI_RX_SetSourceAddress(LDD_TDeviceData *DeviceDataPtr,...
**         SetDestinationAddress - LDD_TError DMAT_M_SPI_RX_SetDestinationAddress(LDD_TDeviceData...
**         SetByteCount          - LDD_TError DMAT_M_SPI_RX_SetByteCount(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file DMAT_M_SPI_RX.h
** @version 01.08
** @brief
**          This embedded component implements
**          a DMA transfer channel descriptor definition.
*/         
/*!
**  @addtogroup DMAT_M_SPI_RX_module DMAT_M_SPI_RX module documentation
**  @{
*/         

#ifndef __DMAT_M_SPI_RX_H
#define __DMAT_M_SPI_RX_H

/* MODULE DMAT_M_SPI_RX. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "DMA_CTRL.h"
#include "DMA_PDD.h"
#include "DMAMUX_PDD.h"

#include "Cpu.h"

/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define DMAT_M_SPI_RX_PRPH_BASE_ADDRESS  0x40008000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define DMAT_M_SPI_RX_Init_METHOD_ENABLED /*!< Init method of the component DMAT_M_SPI_RX is enabled (generated) */
#define DMAT_M_SPI_RX_Deinit_METHOD_ENABLED /*!< Deinit method of the component DMAT_M_SPI_RX is enabled (generated) */
#define DMAT_M_SPI_RX_AllocateChannel_METHOD_ENABLED /*!< AllocateChannel method of the component DMAT_M_SPI_RX is enabled (generated) */
#define DMAT_M_SPI_RX_EnableChannel_METHOD_ENABLED /*!< EnableChannel method of the component DMAT_M_SPI_RX is enabled (generated) */
#define DMAT_M_SPI_RX_DisableChannel_METHOD_ENABLED /*!< DisableChannel method of the component DMAT_M_SPI_RX is enabled (generated) */
#define DMAT_M_SPI_RX_SetSourceAddress_METHOD_ENABLED /*!< SetSourceAddress method of the component DMAT_M_SPI_RX is enabled (generated) */
#define DMAT_M_SPI_RX_SetDestinationAddress_METHOD_ENABLED /*!< SetDestinationAddress method of the component DMAT_M_SPI_RX is enabled (generated) */
#define DMAT_M_SPI_RX_SetByteCount_METHOD_ENABLED /*!< SetByteCount method of the component DMAT_M_SPI_RX is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define DMAT_M_SPI_RX_OnComplete_EVENT_ENABLED /*!< OnComplete event of the component DMAT_M_SPI_RX is enabled (generated) */
#define DMAT_M_SPI_RX_OnError_EVENT_ENABLED /*!< OnError event of the component DMAT_M_SPI_RX is enabled (generated) */

/* Source circular buffer base address mask. Represents required 0-modulo-size mask of base source address when using circular buffer. */
#define DMAT_M_SPI_RX_SOURCE_CIRCULAR_BUFFER_ADDRESS_MASK 0U
/* Destination circular buffer base address mask. Represents required 0-modulo-size mask of base destination address when using circular buffer. */
#define DMAT_M_SPI_RX_DESTINATION_CIRCULAR_BUFFER_ADDRESS_MASK 0U

/*
** ===================================================================
**     Method      :  DMAT_M_SPI_RX_Init (component DMATransfer_LDD)
*/
/*!
**     @brief
**         Initializes the DMATransfer component. Allocates memory for
**         the device data structure.
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Device data structure pointer.
*/
/* ===================================================================*/
LDD_TDeviceData* DMAT_M_SPI_RX_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  DMAT_M_SPI_RX_Deinit (component DMATransfer_LDD)
*/
/*!
**     @brief
**         Deinitializes the DMATransfer component.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void DMAT_M_SPI_RX_Deinit(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  DMAT_M_SPI_RX_AllocateChannel (component DMATransfer_LDD)
*/
/*!
**     @brief
**         The method allocates DMA channel for the DMA transfer. This
**         method must be called before DMA channel is initialized.
**         Otherwise ERR_NOTAVAIL error code is returned after call of
**         DMA_LDD channel methods.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
**                           - ERR_NOTAVAIL - There is not any possible
**                           channel with desired features to be
**                           allocated.
*/
/* ===================================================================*/
LDD_TError DMAT_M_SPI_RX_AllocateChannel(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  DMAT_M_SPI_RX_EnableChannel (component DMATransfer_LDD)
*/
/*!
**     @brief
**         The method initializes and/or enables the DMA channel
**         allocated for the DMA transfer defined by the transfer
**         descriptor input parameter DescriptorPtr. First call of this
**         method on given DMA channel initializes it and enables HW
**         requests if Peripheral device or Always enabled trigger
**         source is selected in transfer descriptor Trigger source
**         type item. This method can be also used together with
**         Disable method to temporary switch On/Off the DMA channel HW
**         requests. In such case DMA channel registers are not
**         reinitialized again. New initialization of DMA channel can
**         be done via SetChannelDescriptorUpdate method which
**         reinitializes whole channel with new transfer descriptor.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
**                           - ERR_NOTAVAIL - There is not any DMA
**                           channel allocated for the selected transfer
**                           descriptor.
**                           - ERR_PARAM_DATA - Transfer descriptor data
**                           are inconsistent.
*/
/* ===================================================================*/
LDD_TError DMAT_M_SPI_RX_EnableChannel(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  DMAT_M_SPI_RX_DisableChannel (component DMATransfer_LDD)
*/
/*!
**     @brief
**         The method disables the DMA channel allocated for the DMA
**         transfer. However, it is still possible to start transfer
**         explicitly as SW transfer requests via StartChannelTransfer
**         method.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
**                           - ERR_NOTAVAIL - There is not any DMA
**                           channel allocated for the selected transfer
**                           descriptor.
*/
/* ===================================================================*/
LDD_TError DMAT_M_SPI_RX_DisableChannel(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  DMAT_M_SPI_RX_SetSourceAddress (component DMATransfer_LDD)
*/
/*!
**     @brief
**         The method sets an data source address for to be transferred
**         by the DMA channel allocated for the DMA transfer. This
**         method can be used to update DMA transfer source address
**         when DMA channel is enabled. New source address is stored in
**         transfer descriptor and written to associated DMA channel
**         registers. The new source address can be optionally checked
**         for consistency with rest of the transfer descriptor data.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Address         - Address of source data for the DMA
**                           channel allocated for this TCD.
**     @return
**                         - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
**                           - ERR_NOTAVAIL - There is not any DMA
**                           channel allocated for the selected transfer
**                           descriptor.
**                           - ERR_PARAM_DATA - Selected source address
**                           is inconsistent with rest of transfer
**                           descriptor data.
*/
/* ===================================================================*/
LDD_TError DMAT_M_SPI_RX_SetSourceAddress(LDD_TDeviceData *DeviceDataPtr, LDD_DMA_TAddress Address);

/*
** ===================================================================
**     Method      :  DMAT_M_SPI_RX_SetDestinationAddress (component DMATransfer_LDD)
*/
/*!
**     @brief
**         The method sets an data destination address for to be
**         transferred by the DMA channel allocated for the DMA
**         transfer.  This method can be used to update DMA transfer
**         destination address when DMA channel is enabled. New
**         destination address is stored in transfer descriptor and
**         written to associated DMA channel registers. The new source
**         address can be optionally checked for consistency with rest
**         of the transfer descriptor data.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Address         - Address of a destination data to
**                           be transferred to by the DMA channel
**                           allocated for this TCD.
**     @return
**                         - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
**                           - ERR_NOTAVAIL - There is not any DMA
**                           channel allocated for the selected transfer
**                           descriptor.
**                           - ERR_PARAM_DATA - Selected source address
**                           is inconsistent with rest of transfer
**                           descriptor data.
*/
/* ===================================================================*/
LDD_TError DMAT_M_SPI_RX_SetDestinationAddress(LDD_TDeviceData *DeviceDataPtr, LDD_DMA_TAddress Address);

/*
** ===================================================================
**     Method      :  DMAT_M_SPI_RX_SetByteCount (component DMATransfer_LDD)
*/
/*!
**     @brief
**         The method sets a byte count (size of data) to be
**         transferred for the DMA transfer. This method can be used to
**         update DMA transfer byte count when DMA channel is enabled.
**         New transfer byte count is stored in transfer descriptor and
**         written to associated DMA channel registers. The new
**         transfer byte count can be optionally checked for
**         consistency with rest of the transfer descriptor data. If
**         nested operation is used, the method sets the minor (inner)
**         loop byte count.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         ByteCount       - Byte count (size of data) to
**                           be transferred by the DMA channel allocated
**                           for this TCD.
**     @return
**                         - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
**                           - ERR_NOTAVAIL - There is not any DMA
**                           channel allocated for the selected transfer
**                           descriptor.
**                           - ERR_PARAM_DATA - Selected byte count is
**                           inconsistent with rest of transfer
**                           descriptor data.
*/
/* ===================================================================*/
LDD_TError DMAT_M_SPI_RX_SetByteCount(LDD_TDeviceData *DeviceDataPtr, LDD_DMA_TByteCount ByteCount);

/* END DMAT_M_SPI_RX. */

#endif
/* ifndef __DMAT_M_SPI_RX_H */
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
