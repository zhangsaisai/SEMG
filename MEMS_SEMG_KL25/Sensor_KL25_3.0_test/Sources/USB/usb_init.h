/*
 * usb_init.h
 *
 *  Created on: Apr 22, 2015
 *      Author: lab
 */

#ifndef USB_INIT_H_
#define USB_INIT_H_

#include "types.h"

/******************************************************************************
* Macro's
*****************************************************************************/
#define  CONTROLLER_ID      (0)   /* ID to identify USB CONTROLLER */ 

#define  KBI_STAT_MASK      (0x0F)

/* 
DATA_BUFF_SIZE should be greater than or equal to the endpoint buffer size, 
otherwise there will be data loss. For MC9S08JS16, maximum DATA_BUFF_SIZE 
supported is 16 Bytes
*/
#define  DATA_BUFF_SIZE     (64)

/*****************************************************************************
* Global variables
*****************************************************************************/

/*****************************************************************************
* Global Functions
*****************************************************************************/
extern void TestApp_Init(void);

#endif /* USB_INIT_H_ */
