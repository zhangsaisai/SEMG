/* ###################################################################
 **     THIS COMPONENT MODULE IS GENERATED BY USER
 **     Filename    : SPI.c
 **     Project     : semg_mkl15z128vlh4
 **     Processor   : MKL15Z128VLH4
 **     Component   :
 **     Version     :
 **     Datasheet   :
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-Sep 20, 2013, 4:29:29 PM, # CodeGen: 1
 **     Author	    : Dong
 **     Abstract    :
 **     Abstract    :
 **         This file contains high level functions on receiving and sending data via SPI.
 **     Settings    :
 **
 **     Contents    :
 **        ReceiveData     - SPI0ReceiveData(LDD_DMA_TAddress destAddr, LDD_DMA_TByteCount receiveByteCount);
 **                        - SPI1ReceiveData(LDD_DMA_TAddress destAddr, LDD_DMA_TByteCount sendByteCount);
 **        SendData        - SPI0SendData(LDD_DMA_TAddress srcAddr, LDD_DMA_TByteCount receiveByteCount);
 **                        - SPI1SendData(LDD_DMA_TAddress srcAddr, LDD_DMA_TByteCount receiveByteCount);
 **        ReceiveSendData - SPI0ReceiveSendData(ESPIMode mode,
 **                                              LDD_DMA_TAddress srcAddr, LDD_DMA_TAddress destAddr,
 **                                              LDD_DMA_TByteCount receiveByteCount, LDD_DMA_TByteCount sendByteCount);
 **                        - SPI1ReceiveSendData(LDD_DMA_TAddress srcAddr, LDD_DMA_TAddress destAddr,
 **                                              LDD_DMA_TByteCount receiveByteCount, LDD_DMA_TByteCount sendByteCount);
 **     Mail      	: pzdongdong@163.com
 **
 **     Revision    : No.  Name        Data/Time        Content
 ** ###################################################################*/
/*!
 * @file SPI.h
 * @version 01.00
 * @brief
 *      This file contains high level functions on receiving and sending data via SPI.
 */
/*!
 * @addtogroup SPI_Operation SPI Operation
 *     This module contains high level functions on receiving and sending data via SPI.
 * @{
 */

/* MODULE SPI */

/* {Default RTOS Adapter} No RTOS includes */
#include "DMA_CTRL.h"
#include "DMAT_M_SPI_RX.h"
#include "DMAT_M_SPI_TX.h"
#include "DMAT_S_SPI_RX.h"
#include "DMAT_S_SPI_TX.h"
#include "SM_SPI0.h"
#include "SS_SPI1.h"
#include "Events.h"
#include "SPI_PDD.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"

#include "MyHeaders.h"
#include "stdlib.h"

/*
 * ===================================================================
 *     Method      : SPI0ReceiveData( Component SPI )
 */
/*!
 *     @brief
 *         	This method packs a serious operations of receiving data from
 *         	SPI0. Receive data from SPI0 directly with it.
 *     @param[out]
 *         	destAddr        - The address of destination buffer.
 *     @param[in]
 *          receiveByteCount   - The number of bytes to be received.
 *     @return
 *                          - Error code of the the transmission status.
 *                          - Possible codes:
 *                              - ERR_OK       - OK.
 *                              - ERR_SPEED    - This device does not work in
 *                                               the active clock configuration.
 *                              - ERR_DISABLED - Component is disabled.
 *                              - ERR_BUSY     - The previous receive request is
 *                                               pending.
 *                              - etc.         - See PE_Error.h.
 */
/* ===================================================================*/
LDD_TError SPI0ReceiveData(LDD_DMA_TAddress destAddr, LDD_DMA_TByteCount receiveByteCount)
{
    byte* dummy = NULL;

    dummy = (byte*)malloc(receiveByteCount);

//    SPI0RxDMASetSourceAddress((LDD_DMA_TAddress)(&SPI0_DLL));
    SPI0RxDMASetDestinationAddress((LDD_DMA_TAddress)destAddr);
    SPI0RxDMASetByteCount((LDD_DMA_TByteCount)receiveByteCount);

    SPI0TxDMASetSourceAddress((LDD_DMA_TAddress)dummy);
//    SPI0TxDMASetDestinationAddress((LDD_DMA_TAddress)(&SPI0_DLL));
    SPI0TxDMASetByteCount((LDD_DMA_TByteCount)receiveByteCount);


//    SPI0EnableRxDMA();
//    SPI0EnableTxDMA();
    SPI0RxDMAEnable();
    SPI0TxDMAEnable();
//    SPI0Enable();

    free(dummy);

    return ERR_OK;
}

/*
 * ===================================================================
 *     Method      : SPI0SendData( Component SPI )
 */
/*!
 *     @brief
 *          This method packs a serious operations of sending data via
 *          SPI0. Send data via SPI0 directly with it.
 *     @param[in]
 *          srcAddr         - The address of source buffer.
 *     @param[in]
 *          sendByteCount  - The number of bytes to be written.
 *     @return
 *                          - Error code of the the transmission status.
 *                          - Possible codes:
 *                              - ERR_OK       - OK.
 *                              - ERR_SPEED    - This device does not work in
 *                                               the active clock configuration.
 *                              - ERR_DISABLED - Component is disabled.
 *                              - ERR_BUSY     - The previous receive request is
 *                                               pending.
 *                              - etc.         - See PE_Error.h.
 */
/* ===================================================================*/
LDD_TError SPI0SendData(LDD_DMA_TAddress srcAddr, LDD_DMA_TByteCount sendByteCount)
{
    //byte* dummy = NULL;

    //dummy = (byte*)malloc(sendByteCount);

//    SPI0RxDMASetSourceAddress((LDD_DMA_TAddress)(&SPI0_DL));
//    SPI0RxDMASetDestinationAddress((LDD_DMA_TAddress)dummy);
//    SPI0RxDMASetByteCount((LDD_DMA_TByteCount)sendByteCount);

    SPI0TxDMASetSourceAddress((LDD_DMA_TAddress)srcAddr);
//    SPI0TxDMASetDestinationAddress((LDD_DMA_TAddress)(&SPI0_DL));
    SPI0TxDMASetByteCount((LDD_DMA_TByteCount)sendByteCount);

    SPI0DisableRxDMA();
    SPI0EnableTxDMA();
//    SPI0RxDMAEnable();
    SPI0TxDMAEnable();
//    SPI0Enable();

//    free(dummy);

    return ERR_OK;
}

/*
 * ===================================================================
 *     Method      : SPI0ReceiveSendData( Component SPI )
 */
/*!
 *     @brief
 *          This method packs a serious operations of receiving & sending data via
 *          SPI0. Receive & send data from SPI0 directly with it.
 *     @param[in]
 *          mode            - The SPI mode, polling, interrupt or DMA.
 *     @param[in]
 *          srcAddr         - The address of source buffer.
 *     @param[out]
 *          destAddr        - The address of destination buffer.
 *     @param[in]
 *          receiveByteCount   - The number of bytes to be received & write.
 *     @param[in]
 *          sendByteCount  - The number of bytes to be written.
 *     @return
 *                          - Error code of the the transmission status.
 *                          - Possible codes:
 *                              - ERR_OK       - OK.
 *                              - ERR_SPEED    - This device does not work in
 *                                               the active clock configuration.
 *                              - ERR_DISABLED - Component is disabled.
 *                              - ERR_BUSY     - The previous receive request is
 *                                               pending.
 *                              - etc.         - See PE_Error.h.
 */
/* ===================================================================*/
LDD_TError SPI0ReceiveSendData(ESPIMode mode, LDD_DMA_TAddress srcAddr, LDD_DMA_TAddress destAddr, LDD_DMA_TByteCount receiveByteCount, LDD_DMA_TByteCount sendByteCount)
{
    switch(mode)
    {
    case ePoll:
        SPI0Receive(destAddr, receiveByteCount);
        SPI0Send(srcAddr, sendByteCount);
        while(!SPI0ReceiveStatus() || !SPI0SendStatus())
        {
            SPI0Poll();
        }
        break;
    case eInterrupt:
        break;
    case eDMA:
//        SPI0RxDMASetSourceAddress((LDD_DMA_TAddress)(&SPI0_DL));

        SPI0RxDMASetDestinationAddress((LDD_DMA_TAddress)destAddr);
        //DMA_PDD_SetDestinationAddress(DMA_BASE_PTR, 1, (LDD_DMA_TAddress)destAddr);

        SPI0RxDMASetByteCount((LDD_DMA_TByteCount)receiveByteCount);
        //DMA_PDD_SetByteCount(DMA_BASE_PTR, 1, (LDD_DMA_TByteCount)receiveByteCount);

        SPI0TxDMASetSourceAddress((LDD_DMA_TAddress)srcAddr);
        //DMA_PDD_SetSourceAddress(DMA_BASE_PTR, 0, (LDD_DMA_TAddress)srcAddr);

//        SPI0TxDMASetDestinationAddress((LDD_DMA_TAddress)(&SPI0_DL));

        SPI0TxDMASetByteCount((LDD_DMA_TByteCount)sendByteCount);
        //DMA_PDD_SetByteCount(DMA_BASE_PTR, 0, (LDD_DMA_TByteCount)sendByteCount);

        SPI0EnableRxDMA();
        SPI0EnableTxDMA();
        SPI0RxDMAEnable();
        SPI0TxDMAEnable();
        break;
    }

    return ERR_OK;
}

/*
 * ===================================================================
 *     Method      : SPI1ReceiveData( Component SPI )
 */
/*!
 *     @brief
 *          This method packs a serious operations of receiving data from
 *          SPI1. Receive data from SPI1 directly with it.
 *     @param[out]
 *          destAddr        - The address of destination buffer.
 *     @param[in]
 *          receiveByteCount   - The number of bytes to be receive.
 *     @return
 *                          - Error code of the the transmission status.
 *                          - Possible codes:
 *                              - ERR_OK       - OK.
 *                              - ERR_SPEED    - This device does not work in
 *                                               the active clock configuration.
 *                              - ERR_DISABLED - Component is disabled.
 *                              - ERR_BUSY     - The previous receive request is
 *                                               pending.
 *                              - etc.         - See PE_Error.h.
 */
/* ===================================================================*/
LDD_TError SPI1ReceiveData(LDD_DMA_TAddress destAddr, LDD_DMA_TByteCount receiveByteCount)
{
//    byte* dummy = NULL;

//    dummy = (byte*)malloc(receiveByteCount);

//    SPI1RxDMASetSourceAddress((LDD_DMA_TAddress)(&SPI1_D));
    SPI1RxDMASetDestinationAddress((LDD_DMA_TAddress)destAddr);
    SPI1RxDMASetByteCount((LDD_DMA_TByteCount)receiveByteCount);

//    SPI1TxDMASetSourceAddress((LDD_DMA_TAddress)dummy);
//    SPI1TxDMASetDestinationAddress((LDD_DMA_TAddress)(&SPI1_D));
//    SPI1TxDMASetByteCount((LDD_DMA_TByteCount)receiveByteCount);

//    SPI1EnableRxDMA();
//    SPI1EnableTxDMA();
    SPI1EnableRxDMA();
    SPI1DisableTxDMA();
    SPI1RxDMAEnable();
//    SPI1TxDMAEnable();
//    SPI1Enable();

//    free(dummy);

    return ERR_OK;
}

/*
 * ===================================================================
 *     Method      : SPI1SendData( Component SPI )
 */
/*!
 *     @brief
 *          This method packs a serious operations of sending data via
 *          SPI1. Send data via SPI1 directly with it.
 *     @param[in]
 *          srcAddr         - The address of source buffer.
 *     @param[in]
 *          sendByteCount  - The number of bytes to be written.
 *     @return
 *                          - Error code of the the transmission status.
 *                          - Possible codes:
 *                              - ERR_OK       - OK.
 *                              - ERR_SPEED    - This device does not work in
 *                                               the active clock configuration.
 *                              - ERR_DISABLED - Component is disabled.
 *                              - ERR_BUSY     - The previous receive request is
 *                                               pending.
 *                              - etc.         - See PE_Error.h.
 */
/* ===================================================================*/
LDD_TError SPI1SendData(LDD_DMA_TAddress srcAddr, LDD_DMA_TByteCount sendByteCount)
{
//    byte* dummy = NULL;

//    dummy = (byte*)malloc(sendByteCount);

    //extern TMCUPtr tMCUPtr;

//    SPI1TxDMADisable();
//    SPI1DisableTxDMA();

    //if(tMCUPtr->mcuStatus.isSPI1TxDMAChannelError)
    //{
    __DI();
    DMA_CTRL_Init(NULL);
    //SPI1TxDMADisable();
    //SPI1DisableTxDMA();
    //SPI1Disable();
    SPI1Init(NULL);
    __EI();
    //tMCUPtr->mcuStatus.isSPI1TxDMAChannelError = FALSE;
    //}
    DMAControllerEnable();
    SPI1TxDMAAllocateChannel();
//    SPI1RxDMASetSourceAddress((LDD_DMA_TAddress)(&SPI1_D));
//    SPI1RxDMASetDestinationAddress((LDD_DMA_TAddress)dummy);
//    SPI1RxDMASetByteCount((LDD_DMA_TByteCount)sendByteCount);

    SPI1TxDMASetSourceAddress((LDD_DMA_TAddress)srcAddr);
//    SPI1TxDMASetDestinationAddress((LDD_DMA_TAddress)(&SPI1_D));
    SPI1TxDMASetByteCount((LDD_DMA_TByteCount)sendByteCount);

//    SPI1EnableRxDMA();
//    SPI1EnableTxDMA();
//    SPI1RxDMAEnable();
    SPI1EnableTxDMA();
    SPI1RxDMADisable();
    SPI1TxDMAEnable();
    SPI1Enable();

//    free(dummy);

    return ERR_OK;
}

/*
 * ===================================================================
 *     Method      : SPI1ReceiveSendData( Component SPI )
 */
/*!
 *     @brief
 *          This method packs a serious operations of receiving & sending data via
 *          SPI1. Receive & send data from SPI1 directly with it.
 *     @param[in]
 *          srcAddr         - The address of source buffer.
 *     @param[out]
 *          destAddr        - The address of destination buffer.
 *     @param[in]
 *          receiveByteCount   - The number of bytes to be received & write.
 *     @param[in]
 *          sendByteCount  - The number of bytes to be written.
 *     @return
 *                          - Error code of the the transmission status.
 *                          - Possible codes:
 *                              - ERR_OK       - OK.
 *                              - ERR_SPEED    - This device does not work in
 *                                               the active clock configuration.
 *                              - ERR_DISABLED - Component is disabled.
 *                              - ERR_BUSY     - The previous receive request is
 *                                               pending.
 *                              - etc.         - See PE_Error.h.
 */
/* ===================================================================*/
LDD_TError SPI1ReceiveSendData(LDD_DMA_TAddress srcAddr, LDD_DMA_TAddress destAddr, LDD_DMA_TByteCount receiveByteCount, LDD_DMA_TByteCount sendByteCount)
{
//    SPI1Disable();
//    SPI1TxDMADisable();
//    SPI1RxDMADisable();

//    SPI1RxDMASetSourceAddress((LDD_DMA_TAddress)(&SPI1_D));
    SPI1RxDMASetDestinationAddress((LDD_DMA_TAddress)destAddr);
    SPI1RxDMASetByteCount((LDD_DMA_TByteCount)receiveByteCount);

    SPI1TxDMASetSourceAddress((LDD_DMA_TAddress)(srcAddr));
//    SPI1TxDMASetDestinationAddress((LDD_DMA_TAddress)(&SPI1_D));
    SPI1TxDMASetByteCount((LDD_DMA_TByteCount)(sendByteCount));

    SPI1EnableRxDMA();
    SPI1EnableTxDMA();

    SPI1RxDMAEnable();
    SPI1TxDMAEnable();

//    SPI1Enable();
//    SPI1EnableRxDMA();
//    SPI1EnableTxDMA();
//    SPI1_C2 |= SPI_C2_TXDMAE_MASK | SPI_C2_RXDMAE_MASK;



    return ERR_OK;
}

    /* End MODULE SPI */
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


