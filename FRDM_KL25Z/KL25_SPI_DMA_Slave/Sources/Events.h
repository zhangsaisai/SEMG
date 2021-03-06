/* ###################################################################
**     Filename    : Events.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-07-06, 16:14, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "SS_SPI1.h"
#include "DMAT_S_SPI_TX.h"
#include "DMA_CTRL.h"
#include "DMAT_S_SPI_RX.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void);


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
void DMAT_S_SPI_RX_OnComplete(LDD_TUserData *UserDataPtr);

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
void DMAT_S_SPI_RX_OnError(LDD_TUserData *UserDataPtr);

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
void DMAT_S_SPI_TX_OnComplete(LDD_TUserData *UserDataPtr);

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
void DMAT_S_SPI_TX_OnError(LDD_TUserData *UserDataPtr);

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
void EINT_SYNC_INT_OnInterrupt(LDD_TUserData *UserDataPtr);

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
void SS_SPI1_OnBlockReceived(LDD_TUserData *UserDataPtr);

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
void SM_SPI0_OnBlockReceived(LDD_TUserData *UserDataPtr);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
