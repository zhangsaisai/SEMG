/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : DMA_CTRL.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLH4
**     Component   : DMA_LDD
**     Version     : Component 01.065, Driver 01.07, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-06-26, 22:07, # CodeGen: 282
**     Abstract    :
**          This embedded component implements initialization
**          and runtime handling of an on-chip DMA controller.
**     Settings    :
**          Component name                                 : DMA_CTRL
**          Device                                         : DMA
**          Channel arbitration type                       : Round robin
**          DMA channels                                   : 4
**            Settings of DMA channel                      : DMA_Channel0
**              Channel                                    : DMA_Channel0
**              Channel arbitration type                   : Round robin
**              Interrupt service                          : Enabled
**                Transfer complete interrupt              : INT_DMA0
**                Transfer complete interrupt priority     : high priority
**            Settings of DMA channel                      : DMA_Channel1
**              Channel                                    : DMA_Channel1
**              Channel arbitration type                   : Round robin
**              Interrupt service                          : Enabled
**                Transfer complete interrupt              : INT_DMA1
**                Transfer complete interrupt priority     : high priority
**            Settings of DMA channel                      : DMA_Channel2
**              Channel                                    : DMA_Channel2
**              Channel arbitration type                   : Round robin
**              Interrupt service                          : Enabled
**                Transfer complete interrupt              : INT_DMA2
**                Transfer complete interrupt priority     : low priority
**            Settings of DMA channel                      : DMA_Channel3
**              Channel                                    : DMA_Channel3
**              Channel arbitration type                   : Round robin
**              Interrupt service                          : Enabled
**                Transfer complete interrupt              : INT_DMA3
**                Transfer complete interrupt priority     : low priority
**          Initialization                                 : 
**            Enabled in init. code                        : no
**            Auto initialization                          : no
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init                         - LDD_TDeviceData* DMA_CTRL_Init(LDD_TUserData *UserDataPtr);
**         Deinit                       - void DMA_CTRL_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable                       - LDD_TError DMA_CTRL_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable                      - LDD_TError DMA_CTRL_Disable(LDD_TDeviceData *DeviceDataPtr);
**         AllocateChannel              - LDD_TError DMA_CTRL_AllocateChannel(LDD_TDeviceData *DeviceDataPtr,...
**         EnableChannel                - LDD_TError DMA_CTRL_EnableChannel(LDD_TDeviceData *DeviceDataPtr,...
**         DisableChannel               - LDD_TError DMA_CTRL_DisableChannel(LDD_TDeviceData *DeviceDataPtr,...
**         SetChannelSourceAddress      - LDD_TError DMA_CTRL_SetChannelSourceAddress(LDD_TDeviceData *DeviceDataPtr,...
**         SetChannelDestinationAddress - LDD_TError DMA_CTRL_SetChannelDestinationAddress(LDD_TDeviceData...
**         SetChannelByteCount          - LDD_TError DMA_CTRL_SetChannelByteCount(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file DMA_CTRL.h
** @version 01.07
** @brief
**          This embedded component implements initialization
**          and runtime handling of an on-chip DMA controller.
*/         
/*!
**  @addtogroup DMA_CTRL_module DMA_CTRL module documentation
**  @{
*/         

#ifndef __DMA_CTRL_H
#define __DMA_CTRL_H

/* MODULE DMA_CTRL. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "Cpu.h"
#include "DMA_PDD.h"
#include "DMAMUX_PDD.h"

#include "Cpu.h"


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define DMA_CTRL_PRPH_BASE_ADDRESS  0x40008000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define DMA_CTRL_Init_METHOD_ENABLED   /*!< Init method of the component DMA_CTRL is enabled (generated) */
#define DMA_CTRL_Deinit_METHOD_ENABLED /*!< Deinit method of the component DMA_CTRL is enabled (generated) */
#define DMA_CTRL_Enable_METHOD_ENABLED /*!< Enable method of the component DMA_CTRL is enabled (generated) */
#define DMA_CTRL_Disable_METHOD_ENABLED /*!< Disable method of the component DMA_CTRL is enabled (generated) */
#define DMA_CTRL_AllocateChannel_METHOD_ENABLED /*!< AllocateChannel method of the component DMA_CTRL is enabled (generated) */
#define DMA_CTRL_EnableChannel_METHOD_ENABLED /*!< EnableChannel method of the component DMA_CTRL is enabled (generated) */
#define DMA_CTRL_DisableChannel_METHOD_ENABLED /*!< DisableChannel method of the component DMA_CTRL is enabled (generated) */
#define DMA_CTRL_SetChannelSourceAddress_METHOD_ENABLED /*!< SetChannelSourceAddress method of the component DMA_CTRL is enabled (generated) */
#define DMA_CTRL_SetChannelDestinationAddress_METHOD_ENABLED /*!< SetChannelDestinationAddress method of the component DMA_CTRL is enabled (generated) */
#define DMA_CTRL_SetChannelByteCount_METHOD_ENABLED /*!< SetChannelByteCount method of the component DMA_CTRL is enabled (generated) */

/* Number of DMA channels supported by hardware */
#define DMA_CTRL_DMA_CHANNELS_NUMBER 0x04U
/* DMA doesn't support multiple multiplexers */
#define DMA_CTRL_DMAMUX0_CHANNELS_NUMBER 0x00U
#define DMA_CTRL_DMAMUX1_CHANNELS_NUMBER 0x00U
/* Number of configured channels (i.e. all channels set in DMA_CTRL component) */
#define DMA_CTRL_CONFIGURED_CHANNELS_NUMBER 0x04U
/* Number of available channels (i.e. all configured channels excluding permanently allocated channels) */
#define DMA_CTRL_AVAILABLE_CHANNELS_NUMBER 0x00U
/* No DMAMUX0 channels configured */
#define DMA_CTRL_CONFIGURED_DMAMUX0_CHANNELS_NUMBER 0x00U
/* No DMAMUX0 channels available */
#define DMA_CTRL_AVAILABLE_DMAMUX0_CHANNELS_NUMBER 0x00U
/* No DMAMUX1 channels configured */
#define DMA_CTRL_CONFIGURED_DMAMUX1_CHANNELS_NUMBER 0x00U
/* No DMAMUX1 channels available */
#define DMA_CTRL_AVAILABLE_DMAMUX1_CHANNELS_NUMBER 0x00U
/* Number of permanently allocated channels */
#define DMA_CTRL_ALLOCATED_CHANNELS_NUMBER 0x04U
/* No DMAMUX0 permanently allocated channels */
#define DMA_CTRL_ALLOCATED_DMAMUX0_CHANNELS_NUMBER 0x00U
/* No DMAMUX1 permanently allocated channels */
#define DMA_CTRL_ALLOCATED_DMAMUX1_CHANNELS_NUMBER 0x00U
/* Number of available channels capable of periodic triggering (excluding permanently allocated channels) */
#define DMA_CTRL_PERIODIC_TRIGGER_CHANNELS_NUMBER 0x00U
/* No DMAMUX0 channels capable of periodic triggering available. */
#define DMA_CTRL_PERIODIC_TRIGGER_DMAMUX0_CHANNELS_NUMBER 0U
/* No DMAMUX1 channels capable of periodic triggering available. */
#define DMA_CTRL_PERIODIC_TRIGGER_DMAMUX1_CHANNELS_NUMBER 0U
/* No channels without periodic triggering capability available. */
#define DMA_CTRL_SIMPLE_CHANNELS_NUMBER 0U
/* No DMAMUX0 channels without periodic triggering capability available. */
#define DMA_CTRL_SIMPLE_DMAMUX0_CHANNELS_NUMBER 0U
/* No DMAMUX1 channels without periodic triggering capability available. */
#define DMA_CTRL_SIMPLE_DMAMUX1_CHANNELS_NUMBER 0U
/* Channel number constants */
#define DMA_CTRL_CHANNEL_0 0x00U
#define DMA_CTRL_CHANNEL_1 0x01U
#define DMA_CTRL_CHANNEL_2 0x02U
#define DMA_CTRL_CHANNEL_3 0x03U
/*  This constant contains mask of all supported events */
#define DMA_CTRL_AVAILABLE_EVENTS_MASK (LDD_DMA_ON_COMPLETE | LDD_DMA_ON_ERROR)
/* Maximum number of bytes to be transferred in each service request of the channel */
#define DMA_CTRL_MAX_BYTE_COUNT 0x00FFFFFFU
typedef struct {
  LDD_DMA_TChannelNumber ChannelNumber; /* ChannelNumber */
  LDD_DMA_TTransferDescriptor *DescriptorPtr; /* Pointer to the channel's transfer descriptor */
  bool Interrupts;                     /* True, if the DMA channel has enabled interrupts */
  bool Initialized;                    /* True, if the DMA channel has been initialized */
  bool Enabled;                        /* True, if the DMA channel is enabled */
} DMA_CTRL_TDescriptorRecord;          /* Transfer descriptor record type. */

typedef DMA_CTRL_TDescriptorRecord *DMA_CTRL_TDescriptorRecordPtr; /* Pointer to transfer descriptor record. */

typedef struct {
  bool EnUser;                         /* Enable/Disable device */
  DMA_CTRL_TDescriptorRecord DescriptorRecord[DMA_CTRL_CONFIGURED_CHANNELS_NUMBER]; /* Transfer descriptor records table, one record per one channel. */
  DMA_CTRL_TDescriptorRecord *ChannelRecord[DMA_CTRL_DMA_CHANNELS_NUMBER]; /* Channel record table for each channel. */
  LDD_TUserData *UserDataPtr;          /* User device data structure */
  LDD_TEventMask EventMask[DMA_CTRL_DMA_CHANNELS_NUMBER]; /* Event mask of enabled events */
} DMA_CTRL_TDeviceData;                /* Device data structure */

/* DMA Transfer descriptor structure variables external declarations */
extern DMA_CTRL_TDeviceData *DMA_CTRL_DeviceDataPtr;


/*
** ===================================================================
**     Method      :  DMA_CTRL_Init (component DMA_LDD)
*/
/*!
**     @brief
**         Initializes the device according to design-time
**         configuration properties. Allocates memory for the device
**         data structure. 
**         If the <Enable in init. code> is set to "yes" then the
**         device is also enabled (see the description of the Enable
**         method).
**         This method can be called only once. Before the second call
**         of Init the Deinit method must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the device data structure. 
*/
/* ===================================================================*/
LDD_TDeviceData* DMA_CTRL_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  DMA_CTRL_Deinit (component DMA_LDD)
*/
/*!
**     @brief
**         Deinitializes the associated peripheral(s) and frees the
**         component internal data structure.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void DMA_CTRL_Deinit(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  DMA_CTRL_Enable (component DMA_LDD)
*/
/*!
**     @brief
**         Enables DMA device.
**         This method is intended to be used together with Disable
**         method to temporary switch On/Off the device after the
**         device is initialized.
**         This method is required if the <Enable in init. code>
**         property is set to "no" value.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
*/
/* ===================================================================*/
LDD_TError DMA_CTRL_Enable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  DMA_CTRL_Disable (component DMA_LDD)
*/
/*!
**     @brief
**         Disables the DMA device. When the device is disabled, some
**         component methods should not be called. If so, error
**         ERR_DISABLED is reported.
**         This method is intended to be used together with Enable
**         method to temporary switch On/Off the device after the
**         device is initialized.
**         This method is not required. The Deinit method can be used
**         to switch off and uninstall the device.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
*/
/* ===================================================================*/
LDD_TError DMA_CTRL_Disable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  DMA_CTRL_AllocateChannel (component DMA_LDD)
*/
/*!
**     @brief
**         The method allocates DMA channel for the DMA transfer
**         defined by the transfer descriptor input parameter
**         DescriptorPtr. This method must be called before DMA channel
**         is initialized. Otherwise ERR_NOTAVAIL error code is
**         returned after call of DMA_LDD channel methods.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         DescriptorPtr   - Pointer to a DMA
**                           transfer descriptor structure.
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
LDD_TError DMA_CTRL_AllocateChannel(LDD_TDeviceData *DeviceDataPtr, LDD_DMA_TTransferDescriptor *DescriptorPtr);

/*
** ===================================================================
**     Method      :  DMA_CTRL_EnableChannel (component DMA_LDD)
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
**         After calling of EnableChannel method channel status is set
**         to LDD_DMA_IDLE.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         DescriptorPtr   - Pointer to a DMA
**                           transfer descriptor structure.
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
LDD_TError DMA_CTRL_EnableChannel(LDD_TDeviceData *DeviceDataPtr, LDD_DMA_TTransferDescriptor *DescriptorPtr);

/*
** ===================================================================
**     Method      :  DMA_CTRL_DisableChannel (component DMA_LDD)
*/
/*!
**     @brief
**         The method disables the DMA channel allocated for the DMA
**         transfer defined by the transfer descriptor input parameter
**         DescriptorPtr and disables HW requests services. However, it
**         is still possible to start transfer explicitly as SW
**         transfer requests via StartChannelTransfer method. After
**         calling of DisableChannel method channel status is set to
**         LDD_DMA_IDLE.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         DescriptorPtr   - Pointer to a DMA
**                           transfer descriptor structure.
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
LDD_TError DMA_CTRL_DisableChannel(LDD_TDeviceData *DeviceDataPtr, LDD_DMA_TTransferDescriptor *DescriptorPtr);

/*
** ===================================================================
**     Method      :  DMA_CTRL_SetChannelSourceAddress (component DMA_LDD)
*/
/*!
**     @brief
**         The method sets an source address for data to be transferred
**         by the DMA channel allocated for the DMA transfer defined by
**         the transfer descriptor parameter DescriptorPtr. This method
**         can be used to update DMA transfer source address when DMA
**         channel is enabled. New source address is stored in transfer
**         descriptor and written to associated DMA channel registers.
**         The new source address can be optionally checked for
**         consistency with rest of the transfer descriptor data.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         DescriptorPtr   - Pointer to a DMA
**                           transfer descriptor structure.
**     @param
**         Address         - Address of source data for a DMA
**                           channel allocated for a DMA transfer
**                           descriptor defined by the TCD parameter.
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
LDD_TError DMA_CTRL_SetChannelSourceAddress(LDD_TDeviceData *DeviceDataPtr, LDD_DMA_TTransferDescriptor *DescriptorPtr, LDD_DMA_TAddress Address);

/*
** ===================================================================
**     Method      :  DMA_CTRL_SetChannelDestinationAddress (component DMA_LDD)
*/
/*!
**     @brief
**         The method sets an destination address for data to be
**         transferred by the DMA channel allocated for the DMA
**         transfer defined by the transfer descriptor parameter
**         DescriptorPtr. This method can be used to update DMA
**         transfer destination address when DMA channel is enabled.
**         New destination address is stored in transfer descriptor and
**         written to associated DMA channel registers. The new
**         destination address can be optionally checked for
**         consistency with rest of the transfer descriptor data.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         DescriptorPtr   - Pointer to a DMA
**                           transfer descriptor structure.
**     @param
**         Address         - Address of a destination data to
**                           be transferred to by the DMA channel
**                           allocated for a DMA transfer descriptor
**                           defined by the TCD parameter.
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
LDD_TError DMA_CTRL_SetChannelDestinationAddress(LDD_TDeviceData *DeviceDataPtr, LDD_DMA_TTransferDescriptor *DescriptorPtr, LDD_DMA_TAddress Address);

/*
** ===================================================================
**     Method      :  DMA_CTRL_SetChannelByteCount (component DMA_LDD)
*/
/*!
**     @brief
**         The method sets a byte count (size of data) to be
**         transferred by the DMA channel allocated for the DMA
**         transfer defined by the transfer descriptor input parameter
**         DescriptorPtr. This method can be used to update DMA
**         transfer byte count when DMA channel is enabled. New
**         transfer byte count is stored in transfer descriptor and
**         written to associated DMA channel registers. The new
**         transfer byte count can be optionally checked for
**         consistency with rest of the transfer descriptor data. If
**         nested operation is used, the method sets the minor (inner)
**         loop byte count.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         DescriptorPtr   - Pointer to a DMA
**                           transfer descriptor structure.
**     @param
**         ByteCount       - Byte count (size of data) to
**                           be transferred by the DMA channel allocated
**                           for a DMA transfer descriptor defined by
**                           the TCD parameter.
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
LDD_TError DMA_CTRL_SetChannelByteCount(LDD_TDeviceData *DeviceDataPtr, LDD_DMA_TTransferDescriptor *DescriptorPtr, LDD_DMA_TByteCount ByteCount);

/*
** ===================================================================
**     Method      :  DMA_CTRL_SetClockConfiguration (component DMA_LDD)
**
**     Description :
**         This method changes the clock configuration. During a clock 
**         configuration change the component changes it's setting 
**         immediately upon a request.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void DMA_CTRL_SetClockConfiguration(LDD_TDeviceData *DeviceDataPtr, LDD_TClockConfiguration ClockConfiguration);

/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(DMA_CTRL_Channel0Interrupt);

/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(DMA_CTRL_Channel1Interrupt);

/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(DMA_CTRL_Channel2Interrupt);

/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(DMA_CTRL_Channel3Interrupt);


/* END DMA_CTRL. */

#endif
/* ifndef __DMA_CTRL_H */
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
