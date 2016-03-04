/*
 * SPI.c
 *
 *  Created on: Jul 10, 2015
 *      Author: lab
 */
/*
 * SPI.C
 *
 *  Created on: Jun 26, 2015
 *      Author: lab
 */

#include "DMA_CTRL.h"
#include "DMAT_S_SPI_RX.h"
#include "DMAT_S_SPI_TX.h"
#include "Events.h"
#include "SPI_PDD.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "stdlib.h"
#include "Globals.h"
#include "Aliases.h"


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
   
    
    __DI();
    DMA_CTRL_Init(NULL);
    SPI1Init(NULL);
    __EI();
    DMAControllerEnable();
    SPI1TxDMAAllocateChannel();
    SPI1TxDMASetSourceAddress((LDD_DMA_TAddress)srcAddr);
    SPI1TxDMASetByteCount((LDD_DMA_TByteCount)sendByteCount);
    SPI1EnableTxDMA();
    SPI1RxDMADisable();
    SPI1TxDMAEnable();
    SPI1Enable();
    
    return ERR_OK;
}


