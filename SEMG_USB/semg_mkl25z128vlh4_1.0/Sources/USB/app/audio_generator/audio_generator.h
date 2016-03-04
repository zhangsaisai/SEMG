/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
**************************************************************************//*!
*
* @file audio_generator.h
*
* @author 
*
* @version 
*
* @date Jul-20-2010
*
* @brief The file contains Macro's and functions required for Audio Generator
*        Loopback Application
*
*****************************************************************************/
#ifndef _AUDIO_GENERATOR_H
#define _AUDIO_GENERATOR_H

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

#endif 
