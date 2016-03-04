/*
 * Aliases.h
 *
 *  Created on: Jul 17, 2015
 *      Author: lab
 */

#ifndef ALIASES_H_
#define ALIASES_H_


            /*!
             * @{
             */
#define SPI0                       slaveSPI0DevData
#define SPI0Init(userDataPtr)      SS_SPI0_Init(userDataPtr)
#define SPI0Receive(data, size)    SS_SPI0_ReceiveBlock(SPI0, data, size)
#define SPI0Send(data, size)       SS_SPI0_SendBlock(SPI0, data, size)


#endif /* ALIASES_H_ */
