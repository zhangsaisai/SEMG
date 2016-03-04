/* ###################################################################
 **     THIS COMPONENT MODULE IS GENERATED BY USER
 **     Filename    : Init.c
 **     Project     : semg_mkl15z128vlh4
 **     Processor   : MKL15Z128VLH4
 **     Component   :
 **     Version     :
 **     Datasheet   :
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-07-12, 15:40, # CodeGen: 0
 **     Author	    : Dong
 **     Abstract    :
 **			This file contains user initialization of data, on-chip and peripheral devices.
 **
 **			The followings will be initialized:
 **			    - User data
 **				- On-chip devices
 **					- SPI0, SPI1
 **					- SPI0_TX_DMA, SPI0_RX_DMA, SPI1_TX_DMA, SPI1_RX_DMA
 **					- DMA
 **					- UART0, UART2
 **                 - PTA2
 **                 - PTB1, PTB19
 **                 - PTC1, PTC2
 **                 - PTD4
 **                 - PTE18, PTE19
 **				- Peripheral devices
 **					- ADC
 **     Settings    :
 **
 **     Contents    :
 **     			UserInit - UserInit(void);
 **
 **     Mail      	: pzdongdong@163.com
 **
 **     Revision    : No.  Name        Date/Time        Content
 ** ###################################################################*/
/*!
 * @file Init.h
 * @version 01.00
 * @brief
 * 	    This file contains user initialization of data, on-chip and peripheral devices.
 *	    <p>The followings will be initialized:</p>
 *		<ul>
 *		<li> User data
 *		<li> On-chip devices
 *			<ul>
 *			<li> SPI0, SPI1
 *			<li> SPI0_TX_DMA, SPI0_RX_DMA, SPI1_TX_DMA, SPI1_RX_DMA
 *			<li> DMA
 *			<li> UART0, UART2
 *          <li> PTA2
 *          <li> PTB1, PTB19
 *          <li> PTC1, PTC2
 *          <li> PTD4
 *          <li> PTE18, PTE19
 *			</ul>
 *		<li> Peripheral devices
 *			<ul>
 *			<li> ADC
 *			</ul>
 *		</ul>
 */
/*!
 *  @addtogroup UserInitialization	User Initialization
 *      This module contains user initialization of data, on-chip and peripheral devices.
 *      <p>The followings will be initialized:</p>
 *      <ul>
 *      <li> User data
 *      <li> On-chip devices
 *          <ul>
 *          <li> SPI0, SPI1
 *          <li> SPI0_TX_DMA, SPI0_RX_DMA, SPI1_TX_DMA, SPI1_RX_DMA
 *          <li> DMA
 *          <li> UART0, UART2
 *          <li> PTA2
 *          <li> PTB1, PTB19
 *          <li> PTC1, PTC2
 *          <li> PTD4
 *          <li> PTE18, PTE19
 *          </ul>
 *      <li> Peripheral devices
 *          <ul>
 *          <li> ADC
 *          </ul>
 *      </ul>
 *  @{
 */

#ifndef Init_H_
#define Init_H_

/* MODULE Init. */

/* {Default RTOS Adapter} No RTOS includes */

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * ===================================================================
 *     Method      :  UserInit (Component on-chip and peripheral devices)
 */
/*!
 *     @brief
 *          Initialize on-chip and peripheral devices.
 *          The method is called in the main function and will be called
 *          only once.
 *     @param
 *          void
 *     @return
 *          void
 */
/* ===================================================================*/
void UserInit(void);

void ARMDataHeaderInit(void);
/* END Init. */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
/* #ifndef Init_H_ */

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