/*
 * Aliases.h
 *
 *  Created on: Jul 17, 2015
 *      Author: lab
 */

#ifndef ALIASES_H_
#define ALIASES_H_

#include "Aliases.h"

#define EINT_SYNC_INT     portD7DevData

#define EIntSyncInterruptInit(userDataPtr)    EINT_SYNC_INT_Init(userDataPtr)
#define EIntSyncInterruptEnable(userDataPtr)  EINT_SYNC_INT_Enable(userDataPtr)
#define EIntSyncInterruptDisable(userDataPtr) EINT_SYNC_INT_Disable(userDataPtr)



#define DMA_CTRL      dmaControllerDevData
//#define DMA_CTRL      DMA_CTRL_DeviceDataPtr
            /*!
             * @{
             */
#define SPI0 masterSPI0DevData


#define SPI1 slaveSPI1DevData



#define SPI0_RX_DMA masterSPIRxDMADevData
#define SPI0_TX_DMA masterSPITxDMADevData


#define SPI1_RX_DMA slaveSPIRxDMADevData
#define SPI1_TX_DMA slaveSPITxDMADevData


#define DMAControllerInit(userDataPtr)                                    DMA_CTRL_Init(userDataPtr)
#define DMAControllerEnable()                                             DMA_CTRL_Enable(DMA_CTRL)
#define DMAControllerDisable()                                            DMA_CTRL_Disable(DMA_CTRL)
#define DMAControllerAllocateChannel(descriptorPtr)                       DMA_CTRL_AllocateChannel(DMA_CTRL, descriptorPtr)
#define DMAControllerEnableChannel(descriptorPtr)                         DMA_CTRL_EnableChannel(DMA_CTRL, descriptorPtr)
#define DMAControllerDisableChannel(descriptorPtr)                        DMA_CTRL_DisableChannel(DMA_CTRL, descriptorPtr)
#define DMAControllerSetChannelSourceAddress(descriptorPtr, address)      DMA_CTRL_SetChannelSourceAddress(DMA_CTRL, descriptorPtr, address)
#define DMAControllerSetChannelDestinationAddress(descriptorPtr, address) DMA_CTRL_SetChannelDestinationAddress(DMA_CTRL, descriptorPtr, address)
#define DMAControllerSetChannelByteCount(descriptorPtr, byteCount)        DMA_CTRL_SetChannelByteCount(DMA_CTRL, descriptorPtr, byteCount)
            /*!
             * @}
             */
            /*!
             * @{
             */
#define SPI0Init(userDataPtr)   SM_SPI0_Init(userDataPtr)
#define SPI0Enable()            SM_SPI0_Enable(SPI0)
#define SPI0Disable()           SM_SPI0_Disable(SPI0)
#define SPI0Receive(data, size) SM_SPI0_ReceiveBlock(SPI0, data, size)
#define SPI0Send(data, size)    SM_SPI0_SendBlock(SPI0, data, size)
#define SPI0ReceiveStatus()     SM_SPI0_GetBlockReceivedStatus(SPI0)
#define SPI0SendStatus()        SM_SPI0_GetBlockSentStatus(SPI0)
#define SPI0Poll()              SM_SPI0_Main(SPI0)
#define SPI0EnableInterrupt()   SM_SPI0_EnableInterrupt(TRUE, TRUE)
#define SPI0EnableTxInterrupt()  SPI_PDD_EnableInterruptMask(SPI0_BASE_PTR, SPI_PDD_TX_BUFFER_EMPTY)
#define SPI0DisableTxInterrupt()  SPI_PDD_DisableInterruptMask(SPI0_BASE_PTR, SPI_PDD_TX_BUFFER_EMPTY)
#define SPI0EnableRxInterrupt()  SPI_PDD_EnableInterruptMask(SPI0_BASE_PTR, SPI_PDD_RX_BUFFER_FULL_OR_FAULT)
#define SPI0DisableRxInterrupt() SPI_PDD_DisableInterruptMask(SPI0_BASE_PTR, SPI_PDD_RX_BUFFER_FULL_OR_FAULT)
#define SPI0EnableTxDMA()        SPI_PDD_EnableTransmitDma(SPI0_BASE_PTR, PDD_ENABLE)
#define SPI0DisableTxDMA()      SPI_PDD_EnableTransmitDma(SPI0_BASE_PTR, PDD_DISABLE)
#define SPI0EnableRxDMA()       SPI_PDD_EnableReceiveDma(SPI0_BASE_PTR, PDD_ENABLE)
#define SPI0DisableRxDMA()      SPI_PDD_EnableReceiveDma(SPI0_BASE_PTR, PDD_DISABLE)
            /*!
             * @}
             */
            /*!
             * @{
             */
#define SPI1Init(userDataPtr)   SS_SPI1_Init(userDataPtr)
#define SPI1Enable()            SS_SPI1_Enable(SPI1)
#define SPI1Disable()           SS_SPI1_Disable(SPI1)
#define SPI1Receive(data, size) SS_SPI1_ReceiveBlock(SPI1, data, size)
#define SPI1Send(data, size)    SS_SPI1_SendBlock(SPI1, data, size)
#define SPI1EnableInterrupt()   SS_SPI1_EnableInterrupt(TRUE, TRUE)
#define SPI1EnableTxInterrupt()  SPI_PDD_EnableInterruptMask(SPI1_BASE_PTR, SPI_PDD_TX_BUFFER_EMPTY)
#define SPI1DisableTxInterrupt()  SPI_PDD_DisableInterruptMask(SPI1_BASE_PTR, SPI_PDD_TX_BUFFER_EMPTY)
#define SPI1EnableRxInterrupt()  SPI_PDD_EnableInterruptMask(SPI1_BASE_PTR, SPI_PDD_RX_BUFFER_FULL_OR_FAULT)
#define SPI1DisableRxInterrupt() SPI_PDD_DisableInterruptMask(SPI1_BASE_PTR, SPI_PDD_RX_BUFFER_FULL_OR_FAULT)
#define SPI1EnableTxDMA()       SPI_PDD_EnableTransmitDma(SPI1_BASE_PTR, PDD_ENABLE)
#define SPI1DisableTxDMA()      SPI_PDD_EnableTransmitDma(SPI1_BASE_PTR, PDD_DISABLE)
#define SPI1EnableRxDMA()       SPI_PDD_EnableReceiveDma(SPI1_BASE_PTR, PDD_ENABLE)
#define SPI1DisableRxDMA()      SPI_PDD_EnableReceiveDma(SPI1_BASE_PTR, PDD_DISABLE)
            /*!
             * @}
             */
            /*!
             * @{
             */
#define SPI0RxDMAInit(userDataPtr)              DMAT_M_SPI_RX_Init(userDataPtr)
#define SPI0RxDMAAllocateChannel()              DMAT_M_SPI_RX_AllocateChannel(SPI0_RX_DMA)
#define SPI0RxDMAEnable()                       DMAT_M_SPI_RX_EnableChannel(SPI0_RX_DMA)
#define SPI0RxDMADisable()                      DMAT_M_SPI_RX_DisableChannel(SPI0_RX_DMA)
#define SPI0RxDMASetSourceAddress(address)      DMAT_M_SPI_RX_SetSourceAddress(SPI0_RX_DMA, address)
#define SPI0RxDMASetDestinationAddress(address) DMAT_M_SPI_RX_SetDestinationAddress(SPI0_RX_DMA, address)
#define SPI0RxDMASetByteCount(address)          DMAT_M_SPI_RX_SetByteCount(SPI0_RX_DMA, address)

#define SPI0TxDMAInit(userDataPtr)              DMAT_M_SPI_TX_Init(userDataPtr)
#define SPI0TxDMAAllocateChannel()              DMAT_M_SPI_TX_AllocateChannel(SPI0_TX_DMA)
#define SPI0TxDMAEnable()                       DMAT_M_SPI_TX_EnableChannel(SPI0_TX_DMA)
#define SPI0TxDMADisable()                      DMAT_M_SPI_TX_DisableChannel(SPI0_TX_DMA)
#define SPI0TxDMASetSourceAddress(address)      DMAT_M_SPI_TX_SetSourceAddress(SPI0_TX_DMA, address)
#define SPI0TxDMASetDestinationAddress(address) DMAT_M_SPI_TX_SetDestinationAddress(SPI0_TX_DMA, address)
#define SPI0TxDMASetByteCount(byteCount)        DMAT_M_SPI_TX_SetByteCount(SPI0_TX_DMA, byteCount)
            /*!
             * @}
             */
            /*!
             * @{
             */
#define SPI1RxDMAInit(userDataPtr)              DMAT_S_SPI_RX_Init(userDataPtr)
#define SPI1RxDMAAllocateChannel()              DMAT_S_SPI_RX_AllocateChannel(SPI1_RX_DMA)
#define SPI1RxDMAEnable()                       DMAT_S_SPI_RX_EnableChannel(SPI1_RX_DMA)
#define SPI1RxDMADisable()                      DMAT_S_SPI_RX_DisableChannel(SPI1_RX_DMA)
#define SPI1RxDMASetSourceAddress(address)      DMAT_S_SPI_RX_SetSourceAddress(SPI1_RX_DMA, address)
#define SPI1RxDMASetDestinationAddress(address) DMAT_S_SPI_RX_SetDestinationAddress(SPI1_RX_DMA, address)
#define SPI1RxDMASetByteCount(address)          DMAT_S_SPI_RX_SetByteCount(SPI1_RX_DMA, address)

#define SPI1TxDMAInit(userDataPtr)              DMAT_S_SPI_TX_Init(userDataPtr)
#define SPI1TxDMAAllocateChannel()              DMAT_S_SPI_TX_AllocateChannel(SPI1_TX_DMA)
#define SPI1TxDMAEnable()                       DMAT_S_SPI_TX_EnableChannel(SPI1_TX_DMA)
#define SPI1TxDMADisable()                      DMAT_S_SPI_TX_DisableChannel(SPI1_TX_DMA)
#define SPI1TxDMASetSourceAddress(address)      DMAT_S_SPI_TX_SetSourceAddress(SPI1_TX_DMA, address)
#define SPI1TxDMASetDestinationAddress(address) DMAT_S_SPI_TX_SetDestinationAddress(SPI1_TX_DMA, address)
#define SPI1TxDMASetByteCount(byteCount)        DMAT_S_SPI_TX_SetByteCount(SPI1_TX_DMA, byteCount)

#endif /* ALIASES_H_ */
