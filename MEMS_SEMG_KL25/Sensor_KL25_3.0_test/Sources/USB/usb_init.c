/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
**************************************************************************//*!
*
* @file usb_init.c
*
* @author
*
* @version
*
* @date Jul-20-2010
*
* @brief  The file emulates a audio generator.
*****************************************************************************/

/******************************************************************************
* Includes
*****************************************************************************/
#include "hidef.h"              /* for EnableInterrupts macro */
#include "types.h"              /* Contains User Defined Data Types */
#include "usb_mems.h"          /* USB Audio Class Header File */
#include "usb_init.h"   /* Audio generator Application Header File */

/* skip the inclusion in dependency statge */
#ifndef __NO_SETJMP
#include <stdio.h>
#endif
#include <stdlib.h>
#include <string.h>

/*****************************************************************************
* Global Functions Prototypes
*****************************************************************************/
void TestApp_Init(void);

/****************************************************************************
* Global Variables
****************************************************************************/

/*****************************************************************************
* Local Types - None
*****************************************************************************/
/* Audio speaker Application start Init Flag */
static volatile boolean start_app = FALSE;
/*****************************************************************************
* Local Functions Prototypes
*****************************************************************************/
static void USB_App_Callback(uint_8 controller_ID,uint_8 event_type, void* val);

/*****************************************************************************
* Local Variables
*****************************************************************************/

/*****************************************************************************
* Local Functions
*****************************************************************************/
/******************************************************************************
*
*   @name        TestApp_Init
*
*   @brief       This function is the entry for the Audio generator application
*
*   @param       None
*
*   @return      None
*****************************************************************************
* This function starts the audio generator application
*****************************************************************************/
void TestApp_Init(void)
{
    uint_8   error;

    /* Disable interrupts */
    //DisableInterrupts;
    
    
    /* callback function : equals interrupt process function,Automatically invoked by the system when meet the event_type conditions.
     * USB_App_Callback:this function is called whenever reset occurs or enum
     * is completed. After the enum is completed this function sets a variable so
     * that the application can start.*/
    /* Initialize the USB interface */
    error = USB_Class_Mems_Init(CONTROLLER_ID,USB_App_Callback,NULL,NULL);
    
    /* Enable interrupts */
    //EnableInterrupts;
}

/******************************************************************************
*
*    @name        USB_App_Callback
*
*    @brief       This function handles Class callback
*
*    @param       controller_ID    : Controller ID
*    @param       event_type       : Value of the event
*    @param       val              : gives the configuration value
*
*    @return      None
*
*****************************************************************************
* This function is called from the class layer whenever reset occurs or enum
* is completed. After the enum is completed this function sets a variable so
* that the application can start.
* This function also receives DATA Send and RECEIVED Events
*****************************************************************************/
static void USB_App_Callback (
    uint_8 controller_ID,   /* [IN] Controller ID */
    uint_8 event_type,      /* [IN] value of the event */
    void* val               /* [IN] gives the configuration value */
)
{
    UNUSED (controller_ID)
    UNUSED (val)
    if ((event_type == USB_APP_BUS_RESET) || (event_type == USB_APP_CONFIG_CHANGED))
    {
        start_app=FALSE;
    }
    else if(event_type == USB_APP_ENUM_COMPLETE)
    {
        start_app=TRUE;
        //ENUM has complete,we can start send
        //when the ENUM completed,the program will jump here,and the flag start_app=TRUE
        
    }
    else if((event_type == USB_APP_SEND_COMPLETE) && (TRUE == start_app))
    {    
        //last send has complete,we can start next sending
    }
    return;
}

/* EOF */
