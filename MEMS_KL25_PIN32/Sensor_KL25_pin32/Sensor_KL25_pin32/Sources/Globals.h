/*
 * Globals.h
 *
 *  Created on: May 7, 2015
 *      Author: lab
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

#include "PE_Types.h"
#include "Macros.h"



//SPI receive variables
#define    COMM_SIZE       1   //master send command to slave
#define    MASTER_DATA        0X01//master send 0x11 to slave ,then slave receive the command and prepare data 
#define    MASTER_DUMMY       0X03//master send 0x13 to slave ,then slave send prepared data to master
#define    SLAVE_DUMMY        0X02


TSENSOR    tSENSOR;             /*!< The structure of ADC device. */
TSENSORPtr tSENSORPtr;       /*!< The pointer to the structure of ADC device. */
TMCU tMCU;                              /*!< The structure of MCU device. */
TMCUPtr tMCUPtr;                        /*!< The pointer to the structure of MCU device. */
TARM tARM;                              /*!< The structure of ARM device. */
TARMPtr tARMPtr;                        /*!< The pointer to the structure of ARM device. */


LDD_TDeviceData* slaveSPI0DevData; /*!< Pointer to SPI0 device data structure in master mode. */

LDD_TDeviceData* slaveSPIRxDMADevData; /*!< Pointer to SPI0 DMA reception device data structure in master mode. */
LDD_TDeviceData* slaveSPITxDMADevData; /*!< Pointer to SPI0 DMA transmission device data structure in master mode. */
/* Already defined in DMA_CTRL.h */
LDD_TDeviceData* dmaControllerDevData;             /*!< Pointer to DMA controller device data structure. */

LDD_TDeviceData* portD7DevData;  /*!< Pointer to PortD Pin7 device data structure, signal: SYNC_INT. */


#endif /* GLOBALS_H_ */
