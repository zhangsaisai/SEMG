/* ###################################################################
 **     THIS COMPONENT MODULE IS GENERATED BY USER.
 **     Filename    : Aliases.h
 **     Project     : semg_mkl15z128vlh4
 **     Processor   : MKL15Z128VLH4
 **     Component   :
 **     Version     :
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-07-14, 00:30, # CodeGen: 0
 **     Author      : Dong
 **     Abstract    :
 **          This file contains ports and functions aliases.
 **          Aliases guarantee minimum modification of code,
 **          when ports or functions changed.
 **
 **
 **     Mail        : pzdongdong@163.com
 **
 **     Revision    : No.  Name        Date/Time        Content
 ** ###################################################################*/
/*!
 * @file Aliases.h
 * @version 01.00
 * @brief
 *      This file contains ports and functions aliases.
 *      Aliases guarantee minimum modification of code,
 *      when ports or functions changed.
 *
 */
/*!
 * @addtogroup Ala Alias
 *     This module contains ports and functions aliases.
 *     Aliases guarantee minimum modification of code,
 *     when ports or functions changed.
 * @{
 */

#ifndef ALIASES_H_
#define ALIASES_H_
/* MODULE ALIASES */

#include "Settings.h"

/*
 * ===================================================================
 * Devices Aliases
 * ===================================================================
 */
        /*!
         * @addtogroup DevAla Devices Aliases
         * @{
         */
            /*!
             * @{
             */
#define SYSTICK SysTick_DEVICE
            /*!
             * @}
             */
            /*!
             * @{
             */
#define EINT_AD_NOT_DRDY0 portA1DevData
#define IO_AD_START0      portB2DevData
#define IO_AD_NOT_RESET0  portE0DevData
#define IO_AD_NOT_CS0     portC4DevData

#define EINT_AD_NOT_DRDY1 portA5DevData
#define IO_AD_START1      portB1DevData
#define IO_AD_NOT_RESET1  portE1DevData
#define IO_AD_NOT_CS1     portC8DevData

#define EINT_SYNC_INT     portA2DevData
#define IO_UPRDY          portE29DevData

#define IO_TEST_SGINAL    portC3DevData
            /*!
             * @}
             */
            /*!
             * @{
             */
#if USING_DMA
#define DMA_CTRL      dmaControllerDevData
//#define DMA_CTRL      DMA_CTRL_DeviceDataPtr
#endif
            /*!
             * @{
             */
#if USING_SPI0
#define SPI0 masterSPI0DevData
#endif
#if USING_SPI1
#define SPI1 slaveSPI1DevData
#endif

#if USING_SPI0_DMA
#define SPI0_RX_DMA masterSPIRxDMADevData
#define SPI0_TX_DMA masterSPITxDMADevData
#endif
#if USING_SPI1_DMA
#define SPI1_RX_DMA slaveSPIRxDMADevData
#define SPI1_TX_DMA slaveSPITxDMADevData
#endif
            /*!
             * @}
             */
            /*!
             * @{
             */
#if USING_UART2
#define UART2 uart2DevData
#endif
            /*!
             * @}
             */
        /*!
         * @}
         */

/*
 * ===================================================================
 * Functions Aliases
 * ===================================================================
 */
        /*!
         * @addtogroup FuncAla Functions Aliases
         * @{
         */
            /*!
             * @{
             */
#define SysTickInit()                     SysTick_Init()
#define SysTickWriteReloadValueReg(value) SysTick_PDD_WriteReloadValueReg(SYSTICK, value)
#define SysTickEnable()                   SysTick_PDD_EnableDevice(SYSTICK, PDD_ENABLE)
#define SysTickDisable()                  SysTick_PDD_EnableDevice(SYSTICK, PDD_DISABLE)
#define SysTickClearCountFlag()           SysTick_PDD_ClearInterruptFlag(SYSTICK)
#define SysTickGetCountFlag()             SysTick_PDD_GetInterruptFlag(SYSTICK)
#define SysTickGetClockSource()           SysTick_PDD_GetClkSource(SYSTICK)                     /*!< 0 - External Clock, 1 - Processor Clock.*/
#define SysTickSetClockSource(source)     SysTick_PDD_SetClkSource(SYSTICK, source)
            /*!
             * @}
             */
            /*!
             * @{
             */
#define IOADStart0Init(userDataPtr) BitIO_AD_START0_Init(userDataPtr)
#define IOADStart0GetVal()          BitIO_AD_START0_GetVal(IO_AD_START0)
#define IOADStart0PutVal(value)     BitIO_AD_START0_PutVal(IO_AD_START0, value)
#define IOADStart0ClrVal()          BitIO_AD_START0_ClrVal(IO_AD_START0)
#define IOADStart0SetVal()          BitIO_AD_START0_SetVal(IO_AD_START0)
            /*!
             * @}
             */
            /*!
             * @{
             */
#define EIntADNotReady0Init(userDataPtr)    EINT_AD_NOT_DRDY0_Init(userDataPtr)
#define EIntADNotReady0Enable(userDataPtr)  EINT_AD_NOT_DRDY0_Enable(userDataPtr)
#define EIntADNotReady0Disable(userDataPtr) EINT_AD_NOT_DRDY0_Disable(userDataPtr)
            /*!
             * @}
             */
            /*!
             * @{
             */
#define IOADNotReset0Init(userDataPtr) BitIO_AD_NOT_RESET0_Init(userDataPtr)
#define IOADNotReset0GetVal()          BitIO_AD_NOT_RESET0_GetVal(IO_AD_NOT_RESET0)
#define IOADNotReset0PutVal(value)     BitIO_AD_NOT_RESET0_PutVal(IO_AD_NOT_RESET0, value)
#define IOADNotReset0ClrVal()          BitIO_AD_NOT_RESET0_ClrVal(IO_AD_NOT_RESET0)
#define IOADNotReset0SetVal()          BitIO_AD_NOT_RESET0_SetVal(IO_AD_NOT_RESET0)
            /*!
             * @}
             */
            /*!
             * @{
             */
#define IOADNotCS0Init(userDataPtr) BitIO_AD_NOT_CS0_Init(userDataPtr)
#define IOADNotCS0GetVal()          BitIO_AD_NOT_CS0_GetVal(IO_AD_NOT_CS0)
#define IOADNotCS0PutVal(value)     BitIO_AD_NOT_CS0_PutVal(IO_AD_NOT_CS0, value)
#define IOADNotCS0ClrVal()          BitIO_AD_NOT_CS0_ClrVal(IO_AD_NOT_CS0)
#define IOADNotCS0SetVal()          BitIO_AD_NOT_CS0_SetVal(IO_AD_NOT_CS0)
            /*!
             * @}
             */
            /*!
             * @{
             */
#define IOADStart1Init(userDataPtr) BitIO_AD_START1_Init(userDataPtr)
#define IOADStart1GetVal()          BitIO_AD_START1_GetVal(IO_AD_START1)
#define IOADStart1PutVal(value)     BitIO_AD_START1_PutVal(IO_AD_START1, value)
#define IOADStart1ClrVal()          BitIO_AD_START1_ClrVal(IO_AD_START1)
#define IOADStart1SetVal()          BitIO_AD_START1_SetVal(IO_AD_START1)
            /*!
             * @}
             */
            /*!
             * @{
             */
#define EIntADNotReady1Init(userDataPtr)    EINT_AD_NOT_DRDY1_Init(userDataPtr)
#define EIntADNotReady1Enable(userDataPtr)  EINT_AD_NOT_DRDY1_Enable(userDataPtr)
#define EIntADNotReady1Disable(userDataPtr) EINT_AD_NOT_DRDY1_Disable(userDataPtr)
            /*!
             * @}
             */
            /*!
             * @{
             */
#define IOADNotReset1Init(userDataPtr) BitIO_AD_NOT_RESET1_Init(userDataPtr)
#define IOADNotReset1GetVal()          BitIO_AD_NOT_RESET1_GetVal(IO_AD_NOT_RESET1)
#define IOADNotReset1PutVal(value)     BitIO_AD_NOT_RESET1_PutVal(IO_AD_NOT_RESET1, value)
#define IOADNotReset1ClrVal()          BitIO_AD_NOT_RESET1_ClrVal(IO_AD_NOT_RESET1)
#define IOADNotReset1SetVal()          BitIO_AD_NOT_RESET1_SetVal(IO_AD_NOT_RESET1)
            /*!
             * @}
             */
            /*!
             * @{
             */
#define IOADNotCS1Init(userDataPtr) BitIO_AD_NOT_CS1_Init(userDataPtr)
#define IOADNotCS1GetVal()          BitIO_AD_NOT_CS1_GetVal(IO_AD_NOT_CS1)
#define IOADNotCS1PutVal(value)     BitIO_AD_NOT_CS1_PutVal(IO_AD_NOT_CS1, value)
#define IOADNotCS1ClrVal()          BitIO_AD_NOT_CS1_ClrVal(IO_AD_NOT_CS1)
#define IOADNotCS1SetVal()          BitIO_AD_NOT_CS1_SetVal(IO_AD_NOT_CS1)
            /*!
             * @}
             */
            /*!
             * @{
             */
#define EIntSyncInterruptInit(userDataPtr)    EINT_SYNC_INT_Init(userDataPtr)
#define EIntSyncInterruptEnable(userDataPtr)  EINT_SYNC_INT_Enable(userDataPtr)
#define EIntSyncInterruptDisable(userDataPtr) EINT_SYNC_INT_Disable(userDataPtr)
            /*!
             * @}
             */
            /*!
             * @{
             */
#define IOUploadReadyInit(userDataPtr) BitIO_UPRDY_Init(userDataPtr)
#define IOUploadReadyGetVal()          BitIO_UPRDY_GetVal(IO_UPRDY)
#define IOUploadReadyPutVal(value)     BitIO_UPRDY_PutVal(IO_UPRDY, value)
#define IOUploadReadyClrVal()          BitIO_UPRDY_ClrVal(IO_UPRDY)
#define IOUploadReadySetVal()          BitIO_UPRDY_SetVal(IO_UPRDY)
            /*!
             * @}
             */
            /*!
             * @{
             */
//#define IOTestSignalInit(userDataPtr) BitIO_TEST_SIGNAL_Init(userDataPtr)
//#define IOTestSignalGetVal()          BitIO_TEST_SIGNAL_GetVal(IO_TEST_SGINAL)
//#define IOTestSignalPutVal(value)     BitIO_TEST_SIGNAL_PutVal(IO_TEST_SGINAL, value)
//#define IOTestSignalClrVal()          BitIO_TEST_SIGNAL_ClrVal(IO_TEST_SGINAL)
//#define IOTestSignalSetVal()          BitIO_TEST_SIGNAL_SetVal(IO_TEST_SGINAL)
            /*!
             * @}
             */
            /*!
             * @{
             */
#if USING_DMA
#define DMAControllerInit(userDataPtr)                                    DMA_CTRL_Init(userDataPtr)
#define DMAControllerEnable()                                             DMA_CTRL_Enable(DMA_CTRL)
#define DMAControllerDisable()                                            DMA_CTRL_Disable(DMA_CTRL)
#define DMAControllerAllocateChannel(descriptorPtr)                       DMA_CTRL_AllocateChannel(DMA_CTRL, descriptorPtr)
#define DMAControllerEnableChannel(descriptorPtr)                         DMA_CTRL_EnableChannel(DMA_CTRL, descriptorPtr)
#define DMAControllerDisableChannel(descriptorPtr)                        DMA_CTRL_DisableChannel(DMA_CTRL, descriptorPtr)
#define DMAControllerSetChannelSourceAddress(descriptorPtr, address)      DMA_CTRL_SetChannelSourceAddress(DMA_CTRL, descriptorPtr, address)
#define DMAControllerSetChannelDestinationAddress(descriptorPtr, address) DMA_CTRL_SetChannelDestinationAddress(DMA_CTRL, descriptorPtr, address)
#define DMAControllerSetChannelByteCount(descriptorPtr, byteCount)        DMA_CTRL_SetChannelByteCount(DMA_CTRL, descriptorPtr, byteCount)
#endif
            /*!
             * @}
             */
            /*!
             * @{
             */
#if USING_SPI0
#define SPI0Init(userDataPtr)   SM_SPI0_Init(userDataPtr)
#define SPI0Enable()            SM_SPI0_Enable(SPI0)
#define SPI0Disable()           SM_SPI0_Disable(SPI0)
#define SPI0Receive(data, size) SM_SPI0_ReceiveBlock(SPI0, data, size)
#define SPI0Send(data, size)    SM_SPI0_SendBlock(SPI0, data, size)
#define SPI0ReceiveStatus()     SM_SPI0_GetBlockReceivedStatus(SPI0)
#define SPI0SendStatus()        SM_SPI0_GetBlockSentStatus(SPI0)
#define SPI0Poll()              SM_SPI0_Main(SPI0)
#define SPI0EnableInterrupt()   SM_SPI0_EnableInterrupt(TRUE, TRUE)
#define SPI0EnableTxInterrupt() SM_SPI0_EnableInterrupt(TRUE, FALSE)
#define SPI0EnableRxInterrupt() SM_SPI0_EnableInterrupt(FALSE, TRUE)
#define SPI0EnableTxDMA()       SPI_PDD_EnableTransmitDma(SPI0_BASE_PTR, PDD_ENABLE)
#define SPI0DisableTxDMA()      SPI_PDD_EnableTransmitDma(SPI0_BASE_PTR, PDD_DISABLE)
#define SPI0EnableRxDMA()       SPI_PDD_EnableReceiveDma(SPI0_BASE_PTR, PDD_ENABLE)
#define SPI0DisableRxDMA()      SPI_PDD_EnableReceiveDma(SPI0_BASE_PTR, PDD_DISABLE)
#endif
            /*!
             * @}
             */
            /*!
             * @{
             */
#if USING_SPI1
#define SPI1Init(userDataPtr)   SS_SPI1_Init(userDataPtr)
#define SPI1Enable()            SS_SPI1_Enable(SPI1)
#define SPI1Disable()           SS_SPI1_Disable(SPI1)
#define SPI1Receive(data, size) SS_SPI1_ReceiveBlock(SPI1, data, size)
#define SPI1Send(data, size)    SS_SPI1_SendBlock(SPI1, data, size)
#define SPI1EnableInterrupt()   SS_SPI1_EnableInterrupt(TRUE, TRUE)
#define SPI1EnableTxInterrupt() SS_SPI1_EnableInterrupt(TRUE, FALSE)
#define SPI1EnableTxDMA()       SPI_PDD_EnableTransmitDma(SPI1_BASE_PTR, PDD_ENABLE)
#define SPI1DisableTxDMA()      SPI_PDD_EnableTransmitDma(SPI1_BASE_PTR, PDD_DISABLE)
#define SPI1EnableRxDMA()       SPI_PDD_EnableReceiveDma(SPI1_BASE_PTR, PDD_ENABLE)
#define SPI1DisableRxDMA()      SPI_PDD_EnableReceiveDma(SPI1_BASE_PTR, PDD_DISABLE)
#endif
            /*!
             * @}
             */
            /*!
             * @{
             */
#if USING_SPI0_DMA
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
#endif
            /*!
             * @}
             */
            /*!
             * @{
             */
#if USING_SPI1_DMA
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
#endif
            /*!
             * @}
             */
            /*!
             * @{
             */
#if USING_UART2
#define UART2Init(UserDataPtr)   AS_UART2_Init(UserDataPtr)
#define UART2Receive(data, size) AS_UART2_ReceiveBlock(UART2, data, size)
#define UART2Send(data, size)    AS_UART2_SendBlock(UART2, data, size)
#define Print(data)              flagUartSent = FALSE; \
                                 UART2Send(data, sizeof(data)); \
                                 while(!flagUartSent)
#define Printn(data, size)       flagUartSent = FALSE; \
                                 UART2Send(data, size); \
                                 while(!flagUartSent)
#endif
            /*!
             * @}
             */
        /*!
         * @}
         */

    /* END Aliases. */

#endif
/* #ifndef ALIASES_H_ */

/*!
 * @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Dong
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
