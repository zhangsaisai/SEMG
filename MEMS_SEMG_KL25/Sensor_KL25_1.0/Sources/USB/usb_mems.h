/*
 * usb_mems.h
 *
 *  Created on: Apr 20, 2015
 *      Author: lab
 */

#ifndef USB_MEMS_H_
#define USB_MEMS_H_

#include "usb_descriptor.h"
#include "usb_class.h"

/******************************************************************************
* Macro's
*****************************************************************************/
#define MAX_QUEUE_ELEMS                     (1)
/* Code of bmRequest Type */
#define SET_REQUEST_ITF                     (0x21)
#define SET_REQUEST_EP                      (0x22)
#define GET_REQUEST_ITF                     (0xA1)
#define GET_REQUEST_EP                      (0xA2)
#define GET_REQUEST_MCU                     (0xC0)//Get the MCU USB Message
#define SET_REQUEST_MCU                     (0x40)//Set the MCU USB Message

/* Mems Class Specific Request Codes */
#define Get_State                            (0x66)
#define GET_Frame                            (0x65)
#define SET_Frame                            (0x64)
#define SET_Sample                           (0x63)
#define GET_NUMber                           (0x62)
/******************************************************************************
* Types
*****************************************************************************/
typedef struct _app_data_struct
{
    uint_8_ptr      data_ptr;     /* pointer to buffer */
    USB_PACKET_SIZE data_size;    /* buffer size of endpoint */
}APP_DATA_STRUCT;

/* structure to hold a request in the endpoint queue */
typedef struct _usb_class_mems_queue
{
    uint_8 controller_ID;         /* Controller ID*/
    uint_8 channel;               /* Endpoint number */
    uint_8_ptr app_buff;          /* Buffer to send */
    USB_PACKET_SIZE size;         /* Size of the transfer */
}USB_CLASS_MEMS_QUEUE, *PTR_USB_CLASS_MEMS_QUEUE;

/* USB class Mems endpoint data */
typedef struct _usb_class_mems_endpoint
{
    uint_8 endpoint;              /* Endpoint number */
    uint_8 type;                  /* Type of endpoint (interrupt,bulk or isochronous) */
    uint_8 bin_consumer;          /* Num of queued elements */
    uint_8 bin_producer;          /* Num of de-queued elements */
    uint_8 queue_num;             /* Num of queue */
    USB_CLASS_MEMS_QUEUE queue[MAX_QUEUE_ELEMS]; /* Queue data */
}USB_CLASS_MEMS_ENDPOINT;

/* contains the endpoint data for non control endpoints */
typedef struct _usb_class_mems_endpoint_data
{
    /* Num of non control endpoints */
    uint_8 count;
    /* contains the endpoint info */
    USB_CLASS_MEMS_ENDPOINT ep[0x03];
}USB_CLASS_MEMS_ENDPOINT_DATA, *PTR_USB_CLASS_MEMS_ENDPOINT_DATA;

uint_8 USB_Class_Mems_Init(
uint_8 controller_ID,
USB_CLASS_CALLBACK mems_class_callback,
USB_REQ_FUNC vendor_req_callback,
USB_CLASS_CALLBACK param_callback
);
/*
** ===================================================================
**     Method      :  usb_mems_USB_Class_Mems_Init (component USB_MEMS_CLASS)
**     Description :
**         The funtion initializes the Device and Controller layer
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         mems_class_callback - 
**         vendor_req_callback - 
**         param_callback  - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_Class_Mems_DeInit(
uint_8 controller_ID
);
/*
** ===================================================================
**     Method      :  usb_mems_USB_Class_Mems_DeInit (component USB_MEMS_CLASS)
**     Description :
**         The funtion de-initializes the Device and Controller layer
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_Class_Mems_Send_Data(
uint_8 controller_ID,
uint_8 ep_num,
uint_8_ptr app_buff,
USB_PACKET_SIZE size
);
/*
** ===================================================================
**     Method      :  usb_mems_USB_Class_Mems_Send_Data (component USB_MEMS_CLASS)
**     Description :
**         This fucntion is used by Application to send data through
**         Mems class
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         ep_num          - 
**         app_buff        - 
**         size            - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_Class_Mems_Recv_Data(
uint_8 controller_ID,
uint_8 ep_num,
uint_8_ptr app_buff,
USB_PACKET_SIZE size
);
/*
** ===================================================================
**     Method      :  USB_Class_Mems_Recv_Data (component USB_MEMS_CLASS)
**     Description :
**         This function receives Data from Host.
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         ep_num          - 
**         app_buff        - 
**         size            - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
/* EOF */
/* END usb_mems. */

#endif /* USB_MEMS_H_ */
