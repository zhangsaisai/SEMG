/*
 * Globals.h
 *
 *  Created on: Jul 10, 2015
 *      Author: lab
 */
/*
 * Globals.h
 *
 *  Created on: May 7, 2015
 *      Author: lab
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

#include "PE_Types.h"

LDD_TDeviceData*  masterSPI0DevData;
LDD_TDeviceData* slaveSPI1DevData; /*!< Pointer to SPI1 device data structure in master mode. */

LDD_TDeviceData* slaveSPIRxDMADevData; /*!< Pointer to SPI0 DMA reception device data structure in master mode. */
LDD_TDeviceData* slaveSPITxDMADevData; /*!< Pointer to SPI0 DMA transmission device data structure in master mode. */

/* Already defined in DMA_CTRL.h */
LDD_TDeviceData* dmaControllerDevData;             /*!< Pointer to DMA controller device data structure. */


LDD_TDeviceData* portD7DevData;  /*!< Pointer to PortD Pin7 device data structure, signal: SYNC_INT. */

#endif /* GLOBALS_H_ */


