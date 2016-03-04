/* ###################################################################
 **     Filename    : Events.c
 **     Project     : ProcessorExpert
 **     Processor   : MKL26Z256VLH4
 **     Component   : Events
 **     Version     : Driver 01.00
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-07-11, 23:27, # CodeGen: 0
 **     Abstract    :
 **         This is user's event module.
 **         Put your event handler code here.
 **     Settings    :
 **     Contents    :
 **         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
 **
 ** ###################################################################*/
/*!
 ** @file Events.c
 ** @version 01.00
 ** @brief
 **         This is user's event module.
 **         Put your event handler code here.
 */
/*!
 **  @addtogroup Events_module Events module documentation
 **  @{
 */
/* MODULE Events */
#include "Cpu.h"
#include "Events.h"
#include "SysTick_PDD.h"
#include "SysTick.h"

#include "SPI.h"
#include "MyHeaders.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* User includes (#include below this line is not maintained by Processor Expert) */

extern void SwapARMDataBuffer(void);
extern void TransmitMCUData(void);
/*
 * ===================================================================
 * Global Variables
 * ===================================================================
 */
volatile bool isStart = FALSE;

/*
 ** ===================================================================
 **     Event       :  Cpu_OnNMIINT (module Events)
 **
 **     Component   :  Cpu [MKL15Z128LK4]
 **     Description :
 **         This event is called when the Non maskable interrupt had
 **         occurred. This event is automatically enabled when the <NMI
 **         interrupt> property is set to 'Enabled'.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void Cpu_OnNMIINT(void)
{
    /* Write your code here ... */
}

/*
 ** ===================================================================
 **     Event       :  SS_SPI1_OnBlockSent (module Events)
 **
 **     Component   :  SS_SPI1 [SPISlave_LDD]
 */
/*!
 **     @brief
 **         This event is called after the last character from the
 **         output buffer is moved to the transmitter. This event is
 **         available only if the SendBlock method is enabled.
 **     @param
 **         UserDataPtr     - Pointer to the user or
 **                           RTOS specific data. The pointer is passed
 **                           as the parameter of Init method.
 */
/* ===================================================================*/
void SS_SPI1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
    /* Write your code here ... */
    extern TMCUPtr tMCUPtr;

    tMCUPtr->mcuStatus.isSlaveSent = TRUE;
}

/*
 ** ===================================================================
 **     Event       :  SS_SPI1_OnBlockReceived (module Events)
 **
 **     Component   :  SS_SPI1 [SPISlave_LDD]
 */
/*!
 **     @brief
 **         This event is called when the requested number of data is
 **         moved to the input buffer. This method is available only if
 **         the ReceiveBlock method is enabled.
 **     @param
 **         UserDataPtr     - Pointer to the user or
 **                           RTOS specific data. The pointer is passed
 **                           as the parameter of Init method.
 */
/* ===================================================================*/
void SS_SPI1_OnBlockReceived(LDD_TUserData *UserDataPtr)
{
    /* Write your code here ... */
    extern TMCUPtr tMCUPtr;

    tMCUPtr->mcuStatus.isSlaveReceived = TRUE;
}

/*
 ** ===================================================================
 **     Event       :  SM_SPI0_OnBlockSent (module Events)
 **
 **     Component   :  SM_SPI0 [SPIMaster_LDD]
 */
/*!
 **     @brief
 **         This event is called after the last character from the
 **         output buffer is moved to the transmitter. This event is
 **         available only if the SendBlock method is enabled.
 **     @param
 **         UserDataPtr     - Pointer to the user or
 **                           RTOS specific data. The pointer is passed
 **                           as the parameter of Init method.
 */
/* ===================================================================*/
void SM_SPI0_OnBlockSent(LDD_TUserData *UserDataPtr)
{
    /* Write your code here ... */
    extern TMCUPtr tMCUPtr;

    tMCUPtr->mcuStatus.isMasterSent = TRUE;
}

/*
 ** ===================================================================
 **     Event       :  SM_SPI0_OnBlockReceived (module Events)
 **
 **     Component   :  SM_SPI0 [SPIMaster_LDD]
 */
/*!
 **     @brief
 **         This event is called when the requested number of data is
 **         moved to the input buffer. This method is available only if
 **         the ReceiveBlock method is enabled.
 **     @param
 **         UserDataPtr     - Pointer to the user or
 **                           RTOS specific data. The pointer is passed
 **                           as the parameter of Init method.
 */
/* ===================================================================*/
void SM_SPI0_OnBlockReceived(LDD_TUserData *UserDataPtr)
{
    /* Write your code here ... */
    extern TMCUPtr tMCUPtr;

    tMCUPtr->mcuStatus.isMasterReceived = TRUE;
}

/*
 ** ===================================================================
 **     Event       :  EINT_AD_NOT_DRDY0_OnInterrupt (module Events)
 **
 **     Component   :  EINT_AD_NOT_DRDY0 [ExtInt_LDD]
 */
/*!
 **     @brief
 **         This event is called when an active signal edge/level has
 **         occurred.
 **     @param
 **         UserDataPtr     - Pointer to RTOS device
 **                           data structure pointer.
 */
/* ===================================================================*/
void EINT_AD_NOT_DRDY0_OnInterrupt(LDD_TUserData *UserDataPtr)
{
    /* Write your code here ... */
    extern TADCPtr tADCPtr[USING_ADC_COUNT];

//    flagSPI1RxDMATransCompleted = FALSE;
//    ADCReadContinuousData(adcDataPtr->rawData, (LDD_DMA_TByteCount)RAW_DATA_SIZE);

    tADCPtr[0]->adcStatus.isDataReady = TRUE;
    //flagDataReady = TRUE;
}

/*
 ** ===================================================================
 **     Event       :  EINT_SYNC_INT_OnInterrupt (module Events)
 **
 **     Component   :  EINT_SYNC_INT [ExtInt_LDD]
 */
/*!
 **     @brief
 **         This event is called when an active signal edge/level has
 **         occurred.
 **     @param
 **         UserDataPtr     - Pointer to RTOS device
 **                           data structure pointer.
 */
/* ===================================================================*/
void EINT_SYNC_INT_OnInterrupt(LDD_TUserData *UserDataPtr)
{
     /*
      extern TARMPtr tARMPtr;
//    extern volatile byte* uploadBufferPtr;
//    extern volatile byte msg[2000];
//    extern volatile byte msg2[2000];
//    static bool flag1 = TRUE;
//    byte dummy[2000];

//    EIntSyncInterruptDisable(EINT_SYNC_INT);

//    flagSPI0TxDMATransCompleted = FALSE;
//    uploadBufferPtr = (uploadBufferPtr == msg) ? msg2 : msg;

      tARMPtr->armStatus.isRequiringData = TRUE;
      SwapARMDataBuffer();
      TransmitMCUData();

      if(!isStart)
      {
          isStart = TRUE;
          GPIOB_PDOR |= 0x06U;    //B1, B2, start 2 ADCs.
      }
     */
}

/*
 * ===================================================================
 *     Method      : SysTick_OnInterrupt(module Events)
 */
/*!
 *     @brief
 *          This event is called when a SysTick countdown has been 0.
 */
/* ===================================================================*/
void SysTick_OnInterrupt(void)
{

}

/*
 ** ===================================================================
 **     Method      :  SysTick_Interrupt (component SysTick)
 **
 **     Description :
 **         The ISR function handling the device SysTick interrupt.
 **         This method is internal. It is used by Processor Expert only.
 ** ===================================================================
 */
PE_ISR(SysTick_Interrupt)
{
    extern TMCUPtr tMCUPtr;

    tMCUPtr->mcuStatus.isDelayed = TRUE;
    SysTickClearCountFlag();
    SysTick_OnInterrupt();
}

/*
** ===================================================================
**     Event       :  DMAT_M_SPI_RX_OnComplete (module Events)
**
**     Component   :  DMAT_M_SPI_RX [DMATransfer_LDD]
*/
/*!
**     @brief
**         Called at the end of a DMA transfer. If the Half complete
**         property in initialization section is anabled, this event is
**         also called when current major iteration count reaches the
**         halfway point. See SetEventMask() and GetEventMask() methods.
**         This event is enabled only if Interrupts property in Channel
**         select section is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void DMAT_M_SPI_RX_OnComplete(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
    extern TADCPtr tADCPtr[USING_ADC_COUNT];
    extern TMCUPtr tMCUPtr;

//    SPI0RxDMADisable();
//    SPI0DisableRxDMA();
    tMCUPtr->mcuStatus.isSPI0RxDMATransCompleted = TRUE;
}

/*
** ===================================================================
**     Event       :  DMAT_M_SPI_RX_OnError (module Events)
**
**     Component   :  DMAT_M_SPI_RX [DMATransfer_LDD]
*/
/*!
**     @brief
**         Called when error in channel settings is detected. See
**         SetEventMask() and GetEventMask() methods. This event is
**         enabled only if Interrupts property in Channel select
**         section is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void DMAT_M_SPI_RX_OnError(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  DMAT_M_SPI_TX_OnComplete (module Events)
**
**     Component   :  DMAT_M_SPI_TX [DMATransfer_LDD]
*/
/*!
**     @brief
**         Called at the end of a DMA transfer. If the Half complete
**         property in initialization section is anabled, this event is
**         also called when current major iteration count reaches the
**         halfway point. See SetEventMask() and GetEventMask() methods.
**         This event is enabled only if Interrupts property in Channel
**         select section is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void DMAT_M_SPI_TX_OnComplete(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
    extern TMCUPtr tMCUPtr;

//    SPI0TxDMADisable();
//    SPI0DisableTxDMA();
//    SPI0Disable();

    tMCUPtr->mcuStatus.isSPI0TxDMATransCompleted = TRUE;
    //flagDataReady = FALSE;
}

/*
** ===================================================================
**     Event       :  DMAT_M_SPI_TX_OnError (module Events)
**
**     Component   :  DMAT_M_SPI_TX [DMATransfer_LDD]
*/
/*!
**     @brief
**         Called when error in channel settings is detected. See
**         SetEventMask() and GetEventMask() methods. This event is
**         enabled only if Interrupts property in Channel select
**         section is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void DMAT_M_SPI_TX_OnError(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  DMAT_S_SPI_RX_OnComplete (module Events)
**
**     Component   :  DMAT_S_SPI_RX [DMATransfer_LDD]
*/
/*!
**     @brief
**         Called at the end of a DMA transfer. If the Half complete
**         property in initialization section is anabled, this event is
**         also called when current major iteration count reaches the
**         halfway point. See SetEventMask() and GetEventMask() methods.
**         This event is enabled only if Interrupts property in Channel
**         select section is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void DMAT_S_SPI_RX_OnComplete(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
    extern TMCUPtr tMCUPtr;

//    SPI1RxDMADisable();
//    SPI1DisableRxDMA();

    tMCUPtr->mcuStatus.isSPI1RxDMATransCompleted = TRUE;
}

/*
** ===================================================================
**     Event       :  DMAT_S_SPI_RX_OnError (module Events)
**
**     Component   :  DMAT_S_SPI_RX [DMATransfer_LDD]
*/
/*!
**     @brief
**         Called when error in channel settings is detected. See
**         SetEventMask() and GetEventMask() methods. This event is
**         enabled only if Interrupts property in Channel select
**         section is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void DMAT_S_SPI_RX_OnError(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  DMAT_S_SPI_TX_OnComplete (module Events)
**
**     Component   :  DMAT_S_SPI_TX [DMATransfer_LDD]
*/
/*!
**     @brief
**         Called at the end of a DMA transfer. If the Half complete
**         property in initialization section is anabled, this event is
**         also called when current major iteration count reaches the
**         halfway point. See SetEventMask() and GetEventMask() methods.
**         This event is enabled only if Interrupts property in Channel
**         select section is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void DMAT_S_SPI_TX_OnComplete(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
    extern TMCUPtr tMCUPtr;

//    SPI1TxDMADisable();
//    SPI1RxDMADisable();

    IOUploadReadySetVal();

//    flagUploadReady = FALSE;

    tMCUPtr->mcuStatus.isSPI1TxDMATransCompleted = TRUE;
    if(eData == tARMPtr->armStatus.transmitionContent)
    {
//        tARMPtr->armStatus.isForeBufferEmpty = TRUE;
//        tARMPtr->armStatus.isForeBufferFull = FALSE;
        tARMPtr->armStatus.foreBufferStatus = eEmpty;
        tARMPtr->armStatus.isTransmittingData = FALSE;
    }

//    EIntSyncInterruptEnable(NULL);
}

/*
** ===================================================================
**     Event       :  DMAT_S_SPI_TX_OnError (module Events)
**
**     Component   :  DMAT_S_SPI_TX [DMATransfer_LDD]
*/
/*!
**     @brief
**         Called when error in channel settings is detected. See
**         SetEventMask() and GetEventMask() methods. This event is
**         enabled only if Interrupts property in Channel select
**         section is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void DMAT_S_SPI_TX_OnError(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
    extern TMCUPtr tMCUPtr;

    //tMCUPtr->mcuStatus.isSPI1TxDMAChannelError = TRUE;
}

/*
** ===================================================================
**     Event       :  EINT_AD_NOT_DRDY1_OnInterrupt (module Events)
**
**     Component   :  EINT_AD_NOT_DRDY1 [ExtInt_LDD]
*/
/*!
**     @brief
**         This event is called when an active signal edge/level has
**         occurred.
**     @param
**         UserDataPtr     - Pointer to RTOS device
**                           data structure pointer.
*/
/* ===================================================================*/
void EINT_AD_NOT_DRDY1_OnInterrupt(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
    extern TADCPtr tADCPtr[USING_ADC_COUNT];

    tADCPtr[1]->adcStatus.isDataReady = TRUE;
}

/* END Events */

#ifdef __cplusplus
} /* extern "C" */
#endif

/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.2 [05.06]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
