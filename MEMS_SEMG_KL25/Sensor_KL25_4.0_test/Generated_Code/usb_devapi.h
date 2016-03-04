/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_devapi.h
**     Project   : ProcessorExpert
**     Processor : MKL25Z128FT4
**     Component : USB_DEVICE_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2015-12-23, 16:34, # CodeGen: 93
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#ifndef _USB_DEVAPI_H
#define _USB_DEVAPI_H

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "types.h"          /* User Defined Data Types */

/******************************************************************************
 * Macro's
 *****************************************************************************/
#define USB_MAX_EP_BUFFER_SIZE               (64)

#ifndef CONTROL_ENDPOINT
#define CONTROL_ENDPOINT                     (0)     /* control endpoint number */
#endif

#define USB_SETUP_PKT_SIZE                   (8)     /* Setup Packet Size */

/* Error codes */
#define  USB_OK                              (0x00)
#define  USBERR_ALLOC                        (0x81)
#define  USBERR_BAD_STATUS                   (0x82)
#define  USBERR_CLOSED_SERVICE               (0x83)
#define  USBERR_OPEN_SERVICE                 (0x84)
#define  USBERR_TRANSFER_IN_PROGRESS         (0x85)
#define  USBERR_ENDPOINT_STALLED             (0x86)
#define  USBERR_ALLOC_STATE                  (0x87)
#define  USBERR_DRIVER_INSTALL_FAILED        (0x88)
#define  USBERR_DRIVER_NOT_INSTALLED         (0x89)
#define  USBERR_INSTALL_ISR                  (0x8A)
#define  USBERR_INVALID_DEVICE_NUM           (0x8B)
#define  USBERR_ALLOC_SERVICE                (0x8C)
#define  USBERR_INIT_FAILED                  (0x8D)
#define  USBERR_SHUTDOWN                     (0x8E)
#define  USBERR_INVALID_PIPE_HANDLE          (0x8F)
#define  USBERR_OPEN_PIPE_FAILED             (0x90)
#define  USBERR_INIT_DATA                    (0x91)
#define  USBERR_SRP_REQ_INVALID_STATE        (0x92)
#define  USBERR_TX_FAILED                    (0x93)
#define  USBERR_RX_FAILED                    (0x94)
#define  USBERR_EP_INIT_FAILED               (0x95)
#define  USBERR_EP_DEINIT_FAILED             (0x96)
#define  USBERR_TR_FAILED                    (0x97)
#define  USBERR_BANDWIDTH_ALLOC_FAILED       (0x98)
#define  USBERR_INVALID_NUM_OF_ENDPOINTS     (0x99)
#define  USBERR_NOT_SUPPORTED                (0x9A)

#define  USBERR_DEVICE_NOT_FOUND             (0xC0)
#define  USBERR_DEVICE_BUSY                  (0xC1)
#define  USBERR_NO_DEVICE_CLASS              (0xC3)
#define  USBERR_UNKNOWN_ERROR                (0xC4)
#define  USBERR_INVALID_BMREQ_TYPE           (0xC5)
#define  USBERR_GET_MEMORY_FAILED            (0xC6)
#define  USBERR_INVALID_MEM_TYPE             (0xC7)
#define  USBERR_NO_DESCRIPTOR                (0xC8)
#define  USBERR_NULL_CALLBACK                (0xC9)
#define  USBERR_NO_INTERFACE                 (0xCA)
#define  USBERR_INVALID_CFIG_NUM             (0xCB)
#define  USBERR_INVALID_ANCHOR               (0xCC)
#define  USBERR_INVALID_REQ_TYPE             (0xCD)

/* Pipe Types */
#define  USB_CONTROL_PIPE                    (0x00)
#define  USB_ISOCHRONOUS_PIPE                (0x01)
#define  USB_BULK_PIPE                       (0x02)
#define  USB_INTERRUPT_PIPE                  (0x03)

/* Device States */
#define  USB_STATE_UNKNOWN                   (0xff)
#define  USB_STATE_PENDING_ADDRESS           (0x04)
#define  USB_STATE_POWERED                   (0x03)
#define  USB_STATE_DEFAULT                   (0x02)
#define  USB_STATE_ADDRESS                   (0x01)
#define  USB_STATE_CONFIG                    (0x00)
#define  USB_STATE_SUSPEND                   (0x80)

/* Get_Status Request information for DEVICE */
#define  USB_SELF_POWERED                    (0x01)
#define  USB_REMOTE_WAKEUP                   (0x02)

/* Get_Status Request information for OTG (WINDEX = 0xF000) */

/* Bus Control values */
#define  USB_NO_OPERATION                    (0x00)
#define  USB_ASSERT_BUS_RESET                (0x01)
#define  USB_DEASSERT_BUS_RESET              (0x02)
#define  USB_ASSERT_RESUME                   (0x03)
#define  USB_DEASSERT_RESUME                 (0x04)
#define  USB_SUSPEND_SOF                     (0x05)
#define  USB_RESUME_SOF                      (0x06)

/* possible values of Status */
#define  USB_STATUS_IDLE                     (0)
#define  USB_STATUS_TRANSFER_ACCEPTED        (6)
#define  USB_STATUS_TRANSFER_PENDING         (2)
#define  USB_STATUS_TRANSFER_IN_PROGRESS     (3)
#define  USB_STATUS_ERROR                    (4)
#define  USB_STATUS_DISABLED                 (5)
#define  USB_STATUS_STALLED                  (1)
#define  USB_STATUS_TRANSFER_QUEUED          (7)

#define  USB_STATUS_UNKNOWN                  (0xFFFF)

#define  USB_CONTROL_ENDPOINT                (0)

#define  USB_RECV                            (0)
#define  USB_SEND                            (1)

#define  USB_DEVICE_DONT_ZERO_TERMINATE      (0x1)

#define  USB_SETUP_DATA_XFER_DIRECTION       (0x80)

#define  USB_SPEED_FULL                      (0)
#define  USB_SPEED_LOW                       (1)
#define  USB_SPEED_HIGH                      (2)

#define  USB_MAX_PKTS_PER_UFRAME             (0x6)

#define  USB_TEST_MODE_TEST_PACKET           (0x0400)

/* Available service types */
/* Services 0 through 15 are reserved for endpoints */
#define  USB_SERVICE_EP0                     (0x00)
#define  USB_SERVICE_EP1                     (0x01)
#define  USB_SERVICE_EP2                     (0x02)
#define  USB_SERVICE_EP3                     (0x03)
#define  USB_SERVICE_EP4                     (0x04)
#define  USB_SERVICE_EP5                     (0x05)
#define  USB_SERVICE_EP6                     (0x06)
#define  USB_SERVICE_EP7                     (0x07)
#define  USB_SERVICE_EP8                     (0x08)
#define  USB_SERVICE_EP9                     (0x09)
#define  USB_SERVICE_EP10                    (0x0a)
#define  USB_SERVICE_EP11                    (0x0b)
#define  USB_SERVICE_EP12                    (0x0c)
#define  USB_SERVICE_EP13                    (0x0d)
#define  USB_SERVICE_EP14                    (0x0e)
#define  USB_SERVICE_EP15                    (0x0f)

#define  USB_SERVICE_BUS_RESET               (0x10)
#define  USB_SERVICE_SUSPEND                 (0x11)
#define  USB_SERVICE_SOF                     (0x12)
#define  USB_SERVICE_RESUME                  (0x13)
#define  USB_SERVICE_SLEEP                   (0x14)
#define  USB_SERVICE_SPEED_DETECTION         (0x15)
#define  USB_SERVICE_ERROR                   (0x16)
#define  USB_SERVICE_STALL                   (0x17)
#define  USB_SERVICE_MAX                     (0x18)

#define  USB_SERVICE_MAX_EP         USB_SERVICE_EP15
/* Informational Request/Set Types */
/* component parameter in USB_Device_Get/Set_Status */
#define USB_COMPONENT_DIRECTION_SHIFT        (7)
#define USB_COMPONENT_DIRECTION_MASK         (0x01)
#define  USB_STATUS_DEVICE_STATE             (0x01)
#define  USB_STATUS_INTERFACE                (0x02)
#define  USB_STATUS_ADDRESS                  (0x03)
#define  USB_STATUS_CURRENT_CONFIG           (0x04)
#define  USB_STATUS_SOF_COUNT                (0x05)
#define  USB_STATUS_DEVICE                   (0x06)
#define  USB_STATUS_TEST_MODE                (0x07)
#define  USB_STATUS_ENDPOINT                 (0x10)
#define  USB_STATUS_ENDPOINT_NUMBER_MASK     (0x0F)


#define UNINITIALISED_VAL                    (0xffffffff)

/******************************************************************************
 * Types
 *****************************************************************************/

typedef void _PTR_  pointer;
typedef pointer _usb_device_handle;
#pragma pack(push)
#pragma pack(1)
typedef struct _USB_DEV_EVENT_STRUCT
{
        uint_8          controller_ID;      /* controller ID           */
        uint_8          ep_num;
        boolean         setup;              /* is setup packet         */
        boolean         direction;          /* direction of endpoint   */
        uint_8*         buffer_ptr;         /* pointer to buffer       */
        USB_PACKET_SIZE len;                /* buffer size of endpoint */
        uint_8          errors;             /* Any errors              */
} USB_DEV_EVENT_STRUCT, *PTR_USB_DEV_EVENT_STRUCT;

typedef void(_CODE_PTR_ USB_SERVICE_CALLBACK)(PTR_USB_DEV_EVENT_STRUCT);

typedef struct _USB_EP_STRUCT
{
        uint_8          ep_num;      /* endpoint number         */
        uint_8          type;        /* type of endpoint        */
        uint_8          direction;   /* direction of endpoint   */
        USB_PACKET_SIZE size;        /* buffer size of endpoint */
}USB_EP_STRUCT, *USB_EP_STRUCT_PTR;

#pragma pack(pop)
/******************************************************************************
 * Global Functions
 *****************************************************************************/
extern uint_8 _usb_device_init (
                uint_8                      device_number,
                _usb_device_handle _PTR_    handle,
                uint_8                      number_of_endpoints
);

extern uint_8 _usb_device_deinit(void);

extern uint_8 _usb_device_init_endpoint(
                _usb_device_handle          handle,
                uint_8                      endpoint_number,
                uint_16                     max_packet_size,
                uint_8                      direction,
                uint_8                      endpoint_type,
                uint_8                      flag
);

extern uint_8 _usb_device_cancel_transfer (
                _usb_device_handle          handle,
                uint_8                      endpoint_number,
                uint_8                      direction
);

extern uint_8 _usb_device_deinit_endpoint (
                _usb_device_handle          handle,
                uint_8                      endpoint_number,
                uint_8                      direction
);

extern uint_8 _usb_device_recv_data (
                _usb_device_handle          handle,
                uint_8                      endpoint_number,
                uchar_ptr                   buffer_ptr,
                uint_32                     size
);

extern uint_8 _usb_device_send_data (
                _usb_device_handle          handle,
                uint_8                      endpoint_number,
                uchar_ptr                   buffer_ptr,
                uint_32                     size
);

extern void _usb_device_shutdown (
                _usb_device_handle          handle
);

extern void _usb_device_stall_endpoint (
                _usb_device_handle          handle,
                uint_8                      endpoint_number,
                uint_8                      direction
);

extern void _usb_device_unstall_endpoint (
                _usb_device_handle          handle,
                uint_8                      endpoint_number,
                uint_8                      direction
);

extern void _usb_device_read_setup_data (
                _usb_device_handle          handle,
                uint_8                      endpoint_number,
                uint_8_ptr                  buffer_ptr
);

extern uint_8 _usb_device_get_status (
                _usb_device_handle          handle,
                uint_8                      component,
                uint_16_ptr                 status
);

extern uint_8 _usb_device_set_status (
                _usb_device_handle          handle,
                uint_8                      component,
                uint_16                     setting
);

extern void _usb_device_assert_resume (
                _usb_device_handle          handle
);

extern uint_8 _usb_device_register_service (
                uint_8                      controller_ID,
                uint_8                      type,
                USB_SERVICE_CALLBACK        service
);

extern uint_8 _usb_device_unregister_service (
                _usb_device_handle          handle,
                uint_8                      event_endpoint
);

extern uint_8 _usb_device_get_transfer_status (
                _usb_device_handle          handle,
                uint_8                      endpoint_number,
                uint_8                      direction
);

extern void  _usb_device_set_address (
                _usb_device_handle          handle,
                uint_8                      address
);

extern uint_8 USB_Device_Call_Service(
                uint_8                      type,
                PTR_USB_DEV_EVENT_STRUCT    event
);

#endif
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
