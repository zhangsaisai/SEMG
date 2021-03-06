/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : SS_SPI1.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : SPISlave_LDD
**     Version     : Component 01.047, Driver 01.02, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-09-28, 17:30, # CodeGen: 44
**     Abstract    :
**         This component "SPISlave_LDD" implements SLAVE part of synchronous
**         serial master-slave communication.
**     Settings    :
**          Component name                                 : SS_SPI1
**          Device                                         : SPI1
**          Interrupt service/event                        : Enabled
**            Input interrupt                              : INT_SPI1
**            Input interrupt priority                     : medium priority
**            Output interrupt                             : INT_SPI1
**            Output interrupt priority                    : medium priority
**          Settings                                       : 
**            Input pin                                    : Enabled
**              Pin                                        : PTE3/SPI1_MISO/SPI1_MOSI
**              Pin signal                                 : SPI1_IN
**            Output pin                                   : Enabled
**              Pin                                        : PTE1/SPI1_MOSI/UART1_RX/SPI1_MISO/I2C1_SCL
**              Pin signal                                 : SPI1_OUT
**            Clock pin                                    : 
**              Pin                                        : PTE2/SPI1_SCK
**              Pin signal                                 : SPI1_SCK
**            Slave select                                 : 
**              Pin                                        : PTE4/SPI1_PCS0
**              Pin signal                                 : SPI1_CS
**              Active level                               : Low
**            Attribute set                                : 
**              Width                                      : 8 bits
**              MSB first                                  : yes
**              Clock polarity                             : Low
**              Clock phase                                : Capture on leading edge
**              Parity                                     : None
**            HW input buffer size                         : 1
**            HW input watermark                           : 1
**            Receiver DMA                                 : Disabled
**            HW output buffer size                        : 1
**            HW output watermark                          : 1
**            Transmitter DMA                              : Disabled
**          Initialization                                 : 
**            Enabled in init. code                        : no
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnBlockSent                                : Disabled
**              OnBlockReceived                            : Enabled
**              OnError                                    : Disabled
**     Contents    :
**         Init                   - LDD_TDeviceData* SS_SPI1_Init(LDD_TUserData *UserDataPtr);
**         Enable                 - LDD_TError SS_SPI1_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable                - LDD_TError SS_SPI1_Disable(LDD_TDeviceData *DeviceDataPtr);
**         ReceiveBlock           - LDD_TError SS_SPI1_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         GetBlockReceivedStatus - bool SS_SPI1_GetBlockReceivedStatus(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file SS_SPI1.h
** @version 01.02
** @brief
**         This component "SPISlave_LDD" implements SLAVE part of synchronous
**         serial master-slave communication.
*/         
/*!
**  @addtogroup SS_SPI1_module SS_SPI1 module documentation
**  @{
*/         

#ifndef __SS_SPI1_H
#define __SS_SPI1_H

/* MODULE SS_SPI1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "Cpu.h"
#include "SPI_PDD.h"

#ifdef __cplusplus
extern "C" {
#endif 


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define SS_SPI1_PRPH_BASE_ADDRESS  0x40077000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define SS_SPI1_Init_METHOD_ENABLED    /*!< Init method of the component SS_SPI1 is enabled (generated) */
#define SS_SPI1_Enable_METHOD_ENABLED  /*!< Enable method of the component SS_SPI1 is enabled (generated) */
#define SS_SPI1_Disable_METHOD_ENABLED /*!< Disable method of the component SS_SPI1 is enabled (generated) */
#define SS_SPI1_ReceiveBlock_METHOD_ENABLED /*!< ReceiveBlock method of the component SS_SPI1 is enabled (generated) */
#define SS_SPI1_GetBlockReceivedStatus_METHOD_ENABLED /*!< GetBlockReceivedStatus method of the component SS_SPI1 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define SS_SPI1_OnBlockReceived_EVENT_ENABLED /*!< OnBlockReceived event of the component SS_SPI1 is enabled (generated) */

/* These constants contain pins masks */
#define SS_SPI1_AVAILABLE_PIN_MASK (LDD_SPISLAVE_INPUT_PIN | LDD_SPISLAVE_OUTPUT_PIN | LDD_SPISLAVE_CLK_PIN | LDD_SPISLAVE_SS_PIN)
#define BLOCK_SENT      0x01U          /* Data block sent flag */
#define BLOCK_RECEIVED  0x02U          /* Data block received flag */

typedef struct {
  bool EnUser;                         /* Enable/Disable device */
  LDD_SPISLAVE_TError ErrFlag;         /* Error flags */
  uint16_t InpRecvDataNum;             /* The counter of received characters */
  uint8_t *InpDataPtr;                 /* The buffer pointer for received characters */
  uint16_t InpDataNumReq;              /* The counter of characters to receive by ReceiveBlock() */
  uint8_t SerFlag;                     /* Flags for serial communication */
  LDD_TUserData *UserData;             /* User device data structure */
} SS_SPI1_TDeviceData;                 /* Device data structure type */

typedef SS_SPI1_TDeviceData* SS_SPI1_TDeviceDataPtr; /* Pointer to the device data structure */

/*
** ===================================================================
**     Method      :  SS_SPI1_Init (component SPISlave_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
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
LDD_TDeviceData* SS_SPI1_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  SS_SPI1_Enable (component SPISlave_LDD)
*/
/*!
**     @brief
**         This method enables SPI device. This method is intended to
**         be used together with <Disable()> method to temporary switch
**         On/Off the device after the device is initialized. This
**         method is required if the <Enabled in init. code> property
**         is set to "no" value.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
*/
/* ===================================================================*/
LDD_TError SS_SPI1_Enable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  SS_SPI1_Disable (component SPISlave_LDD)
*/
/*!
**     @brief
**         Disables the SPI device. When the device is disabled, some
**         component methods should not be called. If so, error
**         ERR_DISABLED may be reported. This method is intended to be
**         used together with <Enable()> method to temporary switch
**         on/off the device after the device is initialized. This
**         method is not required. The <Deinit()> method can be used to
**         switch off and uninstall the device.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
*/
/* ===================================================================*/
LDD_TError SS_SPI1_Disable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  SS_SPI1_ReceiveBlock (component SPISlave_LDD)
*/
/*!
**     @brief
**         This method specifies the number of data to receive. The
**         method returns ERR_BUSY until the specified number of
**         characters is received. The method <CancelBlockReception>
**         can be used to cancel a running receive operation.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to A buffer where
**                           received characters will be stored.
**     @param
**         Size            - Size of the block
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - The previous receive request is
**                           pending
*/
/* ===================================================================*/
LDD_TError SS_SPI1_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);

/*
** ===================================================================
**     Method      :  SS_SPI1_GetBlockReceivedStatus (component SPISlave_LDD)
*/
/*!
**     @brief
**         This method returns whether the receiver is finished
**         reception of all data block. The status flag is accumulated,
**         after calling this method the status is returned and cleared
**         (set to "false" state). This method is available only if
**         method ReceiveBlock is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Return value:
**                           true - Data block is completely received
**                           false - Data block isn't completely received
*/
/* ===================================================================*/
bool SS_SPI1_GetBlockReceivedStatus(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  SS_SPI1_Interrupt (component SPISlave_LDD)
**
**     Description :
**         The ISR function handling the device receive/transmit 
**         interrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(SS_SPI1_Interrupt);

/* END SS_SPI1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __SS_SPI1_H */
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
