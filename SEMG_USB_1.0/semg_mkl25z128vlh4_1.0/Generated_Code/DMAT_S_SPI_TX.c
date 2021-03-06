/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : DMAT_S_SPI_TX.c
**     Project     : ProcessorExpert
**     Processor   : MKL26Z256VLH4
**     Component   : DMATransfer_LDD
**     Version     : Component 01.100, Driver 01.08, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-02-07, 12:12, # CodeGen: 294
**     Abstract    :
**          This embedded component implements
**          a DMA transfer channel descriptor definition.
**     Settings    :
**          Component name                                 : DMAT_S_SPI_TX
**          DMA controller device                          : DMA_CTRL
**          Channel                                        : 
**            Channel select                               : Fixed
**              Channel                                    : DMA_Channel2
**              Interrupts                                 : Enabled
**              Allocate channel                           : yes
**          Trigger                                        : 
**            Trigger source type                          : Peripheral device
**              Trigger source                             : SPI1_Transmit_DMA_Request
**              Periodic trigger                           : Disabled
**          Data source                                    : 
**            External object declaration                  : volatile byte* SPI1TxDMADataSourceBuffer = NULL;
**            Address                                      : SPI1TxDMADataSourceBuffer
**            Transfer size                                : 8-bit
**            Address offset                               : 1
**            Circular buffer                              : Buffer disabled
**          Data destination                               : 
**            External object declaration                  : volatile byte* SPI1TxDMADataDestinationBuffer = NULL;
**            Address                                      : (&SPI1_DL)
**            Transfer size                                : 8-bit
**            Address offset                               : 0
**            Circular buffer                              : Buffer disabled
**          Data size                                      : 
**            External object declaration                  : volatile uint8_t SPI1TxDMAByteCount = 0;
**            Value                                        : SPI1TxDMAByteCount
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
**         Init                  - LDD_TDeviceData* DMAT_S_SPI_TX_Init(LDD_TUserData *UserDataPtr);
**         Deinit                - void DMAT_S_SPI_TX_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         AllocateChannel       - LDD_TError DMAT_S_SPI_TX_AllocateChannel(LDD_TDeviceData *DeviceDataPtr);
**         EnableChannel         - LDD_TError DMAT_S_SPI_TX_EnableChannel(LDD_TDeviceData *DeviceDataPtr);
**         DisableChannel        - LDD_TError DMAT_S_SPI_TX_DisableChannel(LDD_TDeviceData *DeviceDataPtr);
**         SetSourceAddress      - LDD_TError DMAT_S_SPI_TX_SetSourceAddress(LDD_TDeviceData *DeviceDataPtr,...
**         SetDestinationAddress - LDD_TError DMAT_S_SPI_TX_SetDestinationAddress(LDD_TDeviceData...
**         SetByteCount          - LDD_TError DMAT_S_SPI_TX_SetByteCount(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file DMAT_S_SPI_TX.c
** @version 01.08
** @brief
**          This embedded component implements
**          a DMA transfer channel descriptor definition.
*/         
/*!
**  @addtogroup DMAT_S_SPI_TX_module DMAT_S_SPI_TX module documentation
**  @{
*/         

/* MODULE DMAT_S_SPI_TX. */

#include "Events.h"
#include "DMAT_S_SPI_TX.h"
/* User external source object declaration */
volatile byte* SPI1TxDMADataSourceBuffer = NULL;

/* User external destination object declaration */
volatile byte* SPI1TxDMADataDestinationBuffer = NULL;

/* User external data size object declaration */
volatile uint8_t SPI1TxDMAByteCount = 0;

typedef struct {
  DMA_CTRL_TDeviceData *DMA_LDD_DeviceDataPtr; /* Pointer to the DMA_LDD component data structure */
  LDD_DMA_TTransferDescriptor *DescriptorPtr; /* Pointer to the component's transfer descriptor */
} DMAT_S_SPI_TX_TDeviceData;

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static DMAT_S_SPI_TX_TDeviceData DeviceDataPtr__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static LDD_DMA_TTransferDescriptor DescriptorPtr__DEFAULT_RTOS_ALLOC;
/*
** ===================================================================
**     Method      :  DMAT_S_SPI_TX_Init (component DMATransfer_LDD)
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
LDD_TDeviceData* DMAT_S_SPI_TX_Init(LDD_TUserData *UserDataPtr)
{
  DMAT_S_SPI_TX_TDeviceData *DeviceDataPtr; /* LDD device structure */
  LDD_DMA_TTransferDescriptor *DescriptorPtr; /* Transfer descriptor structure */

  /* Allocate LDD device structure */
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPtr = &DeviceDataPtr__DEFAULT_RTOS_ALLOC;
  /* Allocate Transfer descriptor structure */
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DescriptorPtr = &DescriptorPtr__DEFAULT_RTOS_ALLOC;
  DeviceDataPtr->DescriptorPtr = DescriptorPtr; /* Store pointer to the descriptor structure */
  /* Transfer descriptor initialization */
  DeviceDataPtr->DescriptorPtr->UserDataPtr = UserDataPtr; /* User device data structure pointer to be returned by the DMA_LDD component's ISR to the dynamic callback of this Descriptor */
  /* Source settings */
  DeviceDataPtr->DescriptorPtr->SourceAddress = (LDD_DMA_TAddress)SPI1TxDMADataSourceBuffer; /* Address of a DMA transfer source data */
  DeviceDataPtr->DescriptorPtr->SourceTransferSize = (LDD_DMA_TTransferSize)DMA_PDD_8_BIT; /* 8-bit source data transfer size. */
  DeviceDataPtr->DescriptorPtr->SourceModuloSize = (LDD_DMA_TModuloSize)DMA_PDD_CIRCULAR_BUFFER_DISABLED; /* Circular buffer size. */
  DeviceDataPtr->DescriptorPtr->SourceAddressIncrement = TRUE; /* Address incremented after each elemental read operation. */
  /* Destination settings */
  DeviceDataPtr->DescriptorPtr->DestinationAddress = (LDD_DMA_TAddress)(&SPI1_DL); /* Address of a DMA transfer destination data */
  DeviceDataPtr->DescriptorPtr->DestinationTransferSize = (LDD_DMA_TTransferSize)DMA_PDD_8_BIT; /* 8-bit destination data transfer size. */
  DeviceDataPtr->DescriptorPtr->DestinationModuloSize = (LDD_DMA_TModuloSize)DMA_PDD_CIRCULAR_BUFFER_DISABLED; /* Circular buffer size. */
  DeviceDataPtr->DescriptorPtr->DestinationAddressIncrement = FALSE; /* Address not incremented. */
  /* Byte count value */
  DeviceDataPtr->DescriptorPtr->ByteCount = (LDD_DMA_TByteCount)SPI1TxDMAByteCount; /* Size of data to be transferred. */
  /* Trigger settings */
  DeviceDataPtr->DescriptorPtr->TriggerType = LDD_DMA_HW_TRIGGER; /* External peripheral trigger is used */
  DeviceDataPtr->DescriptorPtr->TriggerSource = (LDD_DMA_TTriggerSource)0x13U; /* External peripheral trigger source number */
  DeviceDataPtr->DescriptorPtr->PeriodicTrigger = FALSE; /* Periodic trigger mode is not used */
  DeviceDataPtr->DescriptorPtr->ChannelAutoSelection = FALSE; /* DMA channel fixed value */
  DeviceDataPtr->DescriptorPtr->ChannelNumber = (LDD_DMA_TChannelNumber)0x02U; /* DMA channel number */
  DeviceDataPtr->DescriptorPtr->AsynchronousRequests = FALSE; /* DMA channel asynchronous requests disabled. */
  /* Inner and outer loop linking settings */
  DeviceDataPtr->DescriptorPtr->ChannelLinkingMode = LDD_DMA_LINKING_DISABLED; /* Channel linking disabled. */
  DeviceDataPtr->DescriptorPtr->InnerLoopLinkedChannel = 0x00U; /* Linked DMA channel number not used. */
  DeviceDataPtr->DescriptorPtr->OuterLoopLinkedChannel = 0x00U; /* Linked DMA channel number not used. */
  /* Transfer control settings */
  DeviceDataPtr->DescriptorPtr->TransferMode = LDD_DMA_CYCLE_STEAL_TRANSFERS; /* Cycle-steal transfers - one elementary read-write transfer per request. */
  DeviceDataPtr->DescriptorPtr->DisableAfterRequest = TRUE; /* Disable after request. */
  /* Interrupts and events settings */
  DeviceDataPtr->DescriptorPtr->Interrupts = TRUE; /* Interrupts are requested. */
  DeviceDataPtr->DescriptorPtr->OnComplete = TRUE; /* Event enabled in initialization code. */
  DeviceDataPtr->DescriptorPtr->OnError = TRUE; /* Event enabled in initialization code. */
  DeviceDataPtr->DescriptorPtr->OnCompleteEventPtr = &DMAT_S_SPI_TX_OnComplete; /* Pointer to the OnTransferComplete event */
  DeviceDataPtr->DescriptorPtr->OnErrorEventPtr = &DMAT_S_SPI_TX_OnError; /* Pointer to the OnError event */
  DeviceDataPtr->DescriptorPtr->ChannelEnabled = FALSE; /* Descriptor is not allocating nor using any channel. */
  if (PE_LDD_DeviceDataList[PE_LDD_COMPONENT_DMA_CTRL_ID] == NULL) {
    DeviceDataPtr->DMA_LDD_DeviceDataPtr = DMA_CTRL_Init(NULL);
  }
  else {
    DeviceDataPtr->DMA_LDD_DeviceDataPtr = PE_LDD_DeviceDataList[PE_LDD_COMPONENT_DMA_CTRL_ID];
  }
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_DMAT_S_SPI_TX_ID,DeviceDataPtr);
  return ((LDD_TDeviceData *)DeviceDataPtr); /* Return pointer to the data data structure. */
}

/*
** ===================================================================
**     Method      :  DMAT_S_SPI_TX_Deinit (component DMATransfer_LDD)
*/
/*!
**     @brief
**         Deinitializes the DMATransfer component.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void DMAT_S_SPI_TX_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  ((DMAT_S_SPI_TX_TDeviceData *)DeviceDataPtr)->DescriptorPtr = NULL;
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_DMAT_S_SPI_TX_ID);
  /* Deallocation of the Transfer descriptor structure */
  /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
  /* Deallocation of the device structure */
  /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
}

/*
** ===================================================================
**     Method      :  DMAT_S_SPI_TX_AllocateChannel (component DMATransfer_LDD)
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
LDD_TError DMAT_S_SPI_TX_AllocateChannel(LDD_TDeviceData *DeviceDataPtr)
{
  return DMA_CTRL_AllocateChannel((LDD_TDeviceData *)(((DMAT_S_SPI_TX_TDeviceData *)DeviceDataPtr)->DMA_LDD_DeviceDataPtr), ((DMAT_S_SPI_TX_TDeviceData *)DeviceDataPtr)->DescriptorPtr);
}

/*
** ===================================================================
**     Method      :  DMAT_S_SPI_TX_EnableChannel (component DMATransfer_LDD)
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
LDD_TError DMAT_S_SPI_TX_EnableChannel(LDD_TDeviceData *DeviceDataPtr)
{
  return DMA_CTRL_EnableChannel((LDD_TDeviceData *)(((DMAT_S_SPI_TX_TDeviceData *)DeviceDataPtr)->DMA_LDD_DeviceDataPtr), ((DMAT_S_SPI_TX_TDeviceData *)DeviceDataPtr)->DescriptorPtr);
}

/*
** ===================================================================
**     Method      :  DMAT_S_SPI_TX_DisableChannel (component DMATransfer_LDD)
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
LDD_TError DMAT_S_SPI_TX_DisableChannel(LDD_TDeviceData *DeviceDataPtr)
{
  return DMA_CTRL_DisableChannel((LDD_TDeviceData *)(((DMAT_S_SPI_TX_TDeviceData *)DeviceDataPtr)->DMA_LDD_DeviceDataPtr), ((DMAT_S_SPI_TX_TDeviceData *)DeviceDataPtr)->DescriptorPtr);
}

/*
** ===================================================================
**     Method      :  DMAT_S_SPI_TX_SetSourceAddress (component DMATransfer_LDD)
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
LDD_TError DMAT_S_SPI_TX_SetSourceAddress(LDD_TDeviceData *DeviceDataPtr, LDD_DMA_TAddress Address)
{
  return DMA_CTRL_SetChannelSourceAddress((LDD_TDeviceData *)(((DMAT_S_SPI_TX_TDeviceData *)DeviceDataPtr)->DMA_LDD_DeviceDataPtr), ((DMAT_S_SPI_TX_TDeviceData *)DeviceDataPtr)->DescriptorPtr, Address);
}

/*
** ===================================================================
**     Method      :  DMAT_S_SPI_TX_SetDestinationAddress (component DMATransfer_LDD)
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
LDD_TError DMAT_S_SPI_TX_SetDestinationAddress(LDD_TDeviceData *DeviceDataPtr, LDD_DMA_TAddress Address)
{
  return DMA_CTRL_SetChannelDestinationAddress((LDD_TDeviceData *)(((DMAT_S_SPI_TX_TDeviceData *)DeviceDataPtr)->DMA_LDD_DeviceDataPtr), ((DMAT_S_SPI_TX_TDeviceData *)DeviceDataPtr)->DescriptorPtr, Address);
}

/*
** ===================================================================
**     Method      :  DMAT_S_SPI_TX_SetByteCount (component DMATransfer_LDD)
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
LDD_TError DMAT_S_SPI_TX_SetByteCount(LDD_TDeviceData *DeviceDataPtr, LDD_DMA_TByteCount ByteCount)
{
  return DMA_CTRL_SetChannelByteCount((LDD_TDeviceData *)(((DMAT_S_SPI_TX_TDeviceData *)DeviceDataPtr)->DMA_LDD_DeviceDataPtr), ((DMAT_S_SPI_TX_TDeviceData *)DeviceDataPtr)->DescriptorPtr, ByteCount);
}

/* END DMAT_S_SPI_TX. */

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
