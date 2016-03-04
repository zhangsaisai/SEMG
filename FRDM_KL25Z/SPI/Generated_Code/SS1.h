/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : SS1.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : SPISlave_LDD
**     Version     : Component 01.047, Driver 01.02, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-09-10, 09:38, # CodeGen: 1
**     Abstract    :
**         This component "SPISlave_LDD" implements SLAVE part of synchronous
**         serial master-slave communication.
**     Settings    :
**          Component name                                 : SS1
**          Device                                         : SPI1
**          Interrupt service/event                        : Enabled
**            Input interrupt                              : INT_SPI1
**            Input interrupt priority                     : medium priority
**            Output interrupt                             : INT_SPI1
**            Output interrupt priority                    : medium priority
**          Settings                                       : 
**            Input pin                                    : Enabled
**              Pin                                        : PTE3/SPI1_MISO/SPI1_MOSI
**              Pin signal                                 : 
**            Output pin                                   : Enabled
**              Pin                                        : PTE1/SPI1_MOSI/UART1_RX/SPI1_MISO/I2C1_SCL
**              Pin signal                                 : 
**            Clock pin                                    : 
**              Pin                                        : PTE2/SPI1_SCK
**              Pin signal                                 : 
**            Slave select                                 : 
**              Pin                                        : PTE4/SPI1_PCS0
**              Pin signal                                 : 
**              Active level                               : Low
**            Attribute set                                : 
**              Width                                      : 8 bits
**              MSB first                                  : yes
**              Clock polarity                             : Low
**              Clock phase                                : Capture on leading edge
**              Parity                                     : None
**            HW input buffer size                         : Max buffer size
**            HW input watermark                           : 1
**            Receiver DMA                                 : Disabled
**            HW output buffer size                        : Max buffer size
**            HW output watermark                          : 1
**            Transmitter DMA                              : Disabled
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnBlockSent                                : Enabled
**              OnBlockReceived                            : Enabled
**              OnError                                    : Disabled
**     Contents    :
**         Init                   - LDD_TDeviceData* SS1_Init(LDD_TUserData *UserDataPtr);
**         Deinit                 - void SS1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SendBlock              - LDD_TError SS1_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         ReceiveBlock           - LDD_TError SS1_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         GetSentDataNum         - uint16_t SS1_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr);
**         GetReceivedDataNum     - uint16_t SS1_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);
**         GetBlockSentStatus     - bool SS1_GetBlockSentStatus(LDD_TDeviceData *DeviceDataPtr);
**         GetBlockReceivedStatus - bool SS1_GetBlockReceivedStatus(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file SS1.h
** @version 01.02
** @brief
**         This component "SPISlave_LDD" implements SLAVE part of synchronous
**         serial master-slave communication.
*/         
/*!
**  @addtogroup SS1_module SS1 module documentation
**  @{
*/         

#ifndef __SS1_H
#define __SS1_H

/* MODULE SS1. */

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
#define SS1_PRPH_BASE_ADDRESS  0x40077000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define SS1_Init_METHOD_ENABLED        /*!< Init method of the component SS1 is enabled (generated) */
#define SS1_Deinit_METHOD_ENABLED      /*!< Deinit method of the component SS1 is enabled (generated) */
#define SS1_SendBlock_METHOD_ENABLED   /*!< SendBlock method of the component SS1 is enabled (generated) */
#define SS1_ReceiveBlock_METHOD_ENABLED /*!< ReceiveBlock method of the component SS1 is enabled (generated) */
#define SS1_GetSentDataNum_METHOD_ENABLED /*!< GetSentDataNum method of the component SS1 is enabled (generated) */
#define SS1_GetReceivedDataNum_METHOD_ENABLED /*!< GetReceivedDataNum method of the component SS1 is enabled (generated) */
#define SS1_GetBlockSentStatus_METHOD_ENABLED /*!< GetBlockSentStatus method of the component SS1 is enabled (generated) */
#define SS1_GetBlockReceivedStatus_METHOD_ENABLED /*!< GetBlockReceivedStatus method of the component SS1 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define SS1_OnBlockSent_EVENT_ENABLED  /*!< OnBlockSent event of the component SS1 is enabled (generated) */
#define SS1_OnBlockReceived_EVENT_ENABLED /*!< OnBlockReceived event of the component SS1 is enabled (generated) */


typedef struct {
  LDD_SPISLAVE_TError ErrFlag;         /* Error flags */
  uint16_t InpRecvDataNum;             /* The counter of received characters */
  uint8_t *InpDataPtr;                 /* The buffer pointer for received characters */
  uint16_t InpDataNumReq;              /* The counter of characters to receive by ReceiveBlock() */
  uint16_t OutSentDataNum;             /* The counter of sent characters */
  uint8_t *OutDataPtr;                 /* The buffer pointer for data to be transmitted */
  uint16_t OutDataNumReq;              /* The counter of characters to be send by SendBlock() */
  uint8_t SerFlag;                     /* Flags for serial communication */
  LDD_TUserData *UserData;             /* User device data structure */
} SS1_TDeviceData;                     /* Device data structure type */

typedef SS1_TDeviceData* SS1_TDeviceDataPtr; /* Pointer to the device data structure */

#define BLOCK_RECEIVED  0x02U          /* Data block received flag */

/*
** ===================================================================
**     Method      :  SS1_Init (component SPISlave_LDD)
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
LDD_TDeviceData* SS1_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  SS1_Deinit (component SPISlave_LDD)
*/
/*!
**     @brief
**         This method deinitializes the device. It switches off the
**         device, frees the device data structure memory, interrupts
**         vectors, etc.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void SS1_Deinit(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  SS1_ReceiveBlock (component SPISlave_LDD)
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
LDD_TError SS1_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);

/*
** ===================================================================
**     Method      :  SS1_SendBlock (component SPISlave_LDD)
*/
/*!
**     @brief
**         This method sends a block of characters. The method returns
**         ERR_BUSY when the previous block transmission is not
**         completed. The method <CancelBlockTransmission> can be used
**         to cancel a transmit operation.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to the block of data
**                           to send.
**     @param
**         Size            - Number of characters in the buffer.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - The previous transmit request is
**                           pending
*/
/* ===================================================================*/
LDD_TError SS1_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);

/*
** ===================================================================
**     Method      :  SS1_GetReceivedDataNum (component SPISlave_LDD)
*/
/*!
**     @brief
**         Returns the number of received characters in the receive
**         buffer. This method is available only if the ReceiveBlock
**         method is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - The number of characters in the input
**                           buffer.
*/
/* ===================================================================*/
uint16_t SS1_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  SS1_GetSentDataNum (component SPISlave_LDD)
*/
/*!
**     @brief
**         Returns the number of sent characters. This method is
**         available only if method SendBlock is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - The number of characters in the output
**                           buffer.
*/
/* ===================================================================*/
uint16_t SS1_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  SS1_GetBlockSentStatus (component SPISlave_LDD)
*/
/*!
**     @brief
**         This method returns whether the transmitter is finished
**         transmitting all data block. The status flag is accumulated,
**         after calling this method the status is returned and cleared
**         (set to "false" state). This method is available only if
**         method SendBlock is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Return value:
**                           true - Data block is completely transmitted
**                           false - Data block isn't completely
**                           transmitted.
*/
/* ===================================================================*/
bool SS1_GetBlockSentStatus(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  SS1_GetBlockReceivedStatus (component SPISlave_LDD)
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
bool SS1_GetBlockReceivedStatus(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  SS1_Interrupt (component SPISlave_LDD)
**
**     Description :
**         The ISR function handling the device receive/transmit 
**         interrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(SS1_Interrupt);

/* END SS1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __SS1_H */
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
