/******************** (C) COPYRIGHT 2010 STMicroelectronics ********************
* File Name          : usb_desc.c
* Author             : MCD Application Team
* Version            : V3.2.1
* Date               : 07/05/2010
* Description        : Descriptors for Joystick Mouse Demo
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "usb_desc.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define LOBYTE(x)  ((uint8_t)(x & 0x00FF))
#define HIBYTE(x)  ((uint8_t)((x & 0xFF00) >>8))
#define USBD_VID	0x1483
#define USBD_PID	0x5751
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* USB Standard Device Descriptor */
const uint8_t CustomHID_DeviceDescriptor[CUSTOMHID_SIZ_DEVICE_DESC] =
{
    0x12,                       /*bLength */
    USB_DEVICE_DESCRIPTOR_TYPE, /*bDescriptorType*/
    0x00,                       /*bcdUSB */
    0x02,
    0x00,                       /*bDeviceClass*/
    0x00,                       /*bDeviceSubClass*/
    0x00,                       /*bDeviceProtocol*/
    0x40,                       /*bMaxPacketSize40*/
    LOBYTE(USBD_VID),           /*idVendor*/
    HIBYTE(USBD_VID),           /*idVendor*/
    LOBYTE(USBD_PID),           /*idVendor*/
    HIBYTE(USBD_PID),           /*idVendor*/
    0x00,                       /*bcdDevice rel. 2.00*/
    0x02,
    1,                          /*Index of string descriptor describing manufacturer */
    2,                          /*Index of string descriptor describing product*/
    3,                          /*Index of string descriptor describing the device serial number */
    0x01                        /*bNumConfigurations*/
}; /* CustomHID_DeviceDescriptor */


/* USB Configuration Descriptor */
/* All Descriptors (Configuration, Interface, Endpoint, Class, Vendor */
const uint8_t CustomHID_ConfigDescriptor[CUSTOMHID_SIZ_CONFIG_DESC] =
{
    0x09, /* bLength: Configuation Descriptor size */
    USB_CONFIGURATION_DESCRIPTOR_TYPE, /* bDescriptorType: Configuration */
    CUSTOMHID_SIZ_CONFIG_DESC,
    /* wTotalLength: Bytes returned */
    0x00,
    0x01,         /* bNumInterfaces: 1 interface */
    0x01,         /* bConfigurationValue: Configuration value */
    0x00,         /* iConfiguration: Index of string descriptor describing
                                 the configuration*/
    0xE0,         /* bmAttributes: Bus powered */
                  /*Bus powered: 7th bit, Self Powered: 6th bit, Remote wakeup: 5th bit, reserved: 4..0 bits */
    0xFA,         /* MaxPower 500 mA: this current is used for detecting Vbus */
    /************** Descriptor of Custom HID interface ****************/
    /* 09 */
    0x09,         /* bLength: Interface Descriptor size */
    USB_INTERFACE_DESCRIPTOR_TYPE,/* bDescriptorType: Interface descriptor type */
    0x00,         /* bInterfaceNumber: Number of Interface */
    0x00,         /* bAlternateSetting: Alternate setting */
    0x04,         /* bNumEndpoints */
    0xDC,         /* bInterfaceClass: Class code = 0DCH */
    0xA0,         /* bInterfaceSubClass : Subclass code = 0A0H */
    0xB0,         /* nInterfaceProtocol : Protocol code = 0B0H */
    0,            /* iInterface: Index of string descriptor */
    /******************** endpoint descriptor ********************/
    /* 18 */
    0x07,         /* endpoint descriptor length = 07H */
    USB_ENDPOINT_DESCRIPTOR_TYPE, /* endpoint descriptor type = 05H */
    0x81,         /* endpoint 1 IN */
    0x02,					/* bulk transfer = 02H */
    0x40,0x00,    /* endpoint max packet size = 0040H */
    0x00,         /* the value is invalid when bulk transfer */

    0x07,         /* endpoint descriptor length = 07H */
    USB_ENDPOINT_DESCRIPTOR_TYPE, /* endpoint descriptor type = 05H */
    0x01,         /* endpoint 1 OUT */
    0x02,					/* bulk transfer = 02H */
    0x40,0x00,    /* endpoint max packet size = 0040H */
    0x00,         /* the value is invalid when bulk transfer */
		
    0x07,         /* endpoint descriptor length = 07H */
    USB_ENDPOINT_DESCRIPTOR_TYPE, /* endpoint descriptor type = 05H */
    0x82,         /* endpoint 2 IN */
    0x02,					/* bulk transfer = 02H */
    0x40,0x00,    /* endpoint max packet size = 0040H */
    0x00,         /* the value is invalid when bulk transfer */
		
    0x07,         /* endpoint descriptor length = 07H */
    USB_ENDPOINT_DESCRIPTOR_TYPE, /* endpoint descriptor type = 05H */
    0x02,         /* endpoint 2 OUT */
    0x02,					/* bulk transfer = 02H */
    0x40,0x00,    /* endpoint max packet size = 0040H */
    0x00,         /* the value is invalid when bulk transfer */
}; /* CustomHID_ConfigDescriptor */


/* USB String Descriptors (optional) */
const uint8_t CustomHID_StringLangID[CUSTOMHID_SIZ_STRING_LANGID] =
{
    CUSTOMHID_SIZ_STRING_LANGID,
    USB_STRING_DESCRIPTOR_TYPE,
    0x09,
    0x04
}; /* LangID = 0x0409: U.S. English */

const uint8_t CustomHID_StringVendor[CUSTOMHID_SIZ_STRING_VENDOR] =
{
    CUSTOMHID_SIZ_STRING_VENDOR, /* Size of Vendor string */
    USB_STRING_DESCRIPTOR_TYPE,  /* bDescriptorType*/
    // Manufacturer: "STMicroelectronics" 
    'M', 0, 'y', 0, 'U', 0,'S', 0,'B', 0, '_', 0, 'H', 0,'I',0,'D',0
};

const uint8_t CustomHID_StringProduct[CUSTOMHID_SIZ_STRING_PRODUCT] =
{
    CUSTOMHID_SIZ_STRING_PRODUCT,          /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    'B', 0, 'y', 0, ' ', 0, 'e', 0, 'm', 0, 'b', 0,'e',0,'d',0,'-',0,'n',0,'e',0,'t',0
};
uint8_t CustomHID_StringSerial[CUSTOMHID_SIZ_STRING_SERIAL] =
{
    CUSTOMHID_SIZ_STRING_SERIAL,           /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    'x', 0, 'x', 0, 'x', 0,'x', 0,'x', 0, 'x', 0, 'x', 0
};
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/

