/* ###################################################################
 **     THIS COMPONENT MODULE IS GENERATED BY USER
 **     Filename    : Process.h
 **     Project     : semg_mkl15z128vlh4
 **     Processor   : MKL15Z128VLH4
 **     Component   :
 **     Version     :
 **     Datasheet   :
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-Aug 5, 2013, 8:54:36 PM, # CodeGen: 1
 **     Author	    : Dong
 **     Abstract    :
 **			This file contains functions for kinds of data processing.
 **     Settings    :
 **
 **     Contents    :
 **         Process         - void Process(void);
 **
 **     Mail      	: pzdongdong@163.com
 **
 **     Revision    : No.  Name        Data/Time        Content
 ** ###################################################################*/
/*!
 * @file Process.h
 * @version 01.00
 * @brief
 *		This file contains functions for kinds of data processing.
 */
/*!
 *  @addtogroup Proc Process module documentation
 *      This module contains functions for kinds of data processing.
 *  @{
 */

#ifndef PROCESS_H_
#define PROCESS_H_
/* Module Process */

/* {Default RTOS Adapter} No RTOS includes */
#include "Macros.h"
#include "PE_Types.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * ===================================================================
 *     Method      :  StartWork ()
 */
/*!
 *     @brief
            This methods starts main loop, ADC's conversion and so on.
 *     @param
 *          void
 *     @return
 *          void
 */
/* ===================================================================*/
void MainLoop(void);

/*
 * ===================================================================
 *     Method      : SwapARMDataBuffer (Module Process)
 */
/*!
 *     @brief
 *          This method is called to swap the arm's data. Decide either the
 *          armLeftData or armRightData is the foreground buffer or background
 *          buffer.
 *     @param
 *          void
 *     @return
 *          void
 */
/* ===================================================================*/
void SwapARMDataBuffer(void);

/*
 * ===================================================================
 *     Method      : TransmitADCData(Module Process)
 */
/*!
 *     @brief
 *          This method transmit MCU's data to ARM when is required.
 *     @param
 *          void
 *     @return
 *          void
 */
/* ===================================================================*/
void TransmitMCUData(void);

    /* END Process. */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
/* PROCESS_H_ */

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