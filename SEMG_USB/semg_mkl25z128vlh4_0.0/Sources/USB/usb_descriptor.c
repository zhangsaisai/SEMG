/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_descriptor.c
**     Project   : ProcessorExpert
**     Processor : MKL25Z128LK4
**     Component : USB_AUDIO_CLASS
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
/******************************************************************************
* Includes
*****************************************************************************/
#include "types.h"
#include "usb_class.h"
#include "usb_descriptor.h"
#include "usb_framework.h"
#include <stdlib.h>
#include <string.h>

/*****************************************************************************
* Constant and Macro's
*****************************************************************************/
//#define SEMG_ISOC_IN_ENDPOINT 1
//#define SEMG_ISOC_IN_PACKET_SIZE 1023
#define SEMG_BULK_IN_ENDPOINT 1
#define SEMG_BULK_OUT_ENDPOINT 2
#define SEMG_NOTIF_ENDPOINT 3
#define SEMG_BULK_IN_PACKET_SIZE 64
#define SEMG_BULK_OUT_PACKET_SIZE 64
#define SEMG_NOTIF_ENDP_PACKET_SIZE 8


/* structure containing details of all the endpoints used by this device */
const USB_ENDPOINTS usb_desc_ep ={
    AUDIO_DESC_ENDPOINT_COUNT,
    {
        {
        	SEMG_BULK_IN_ENDPOINT,
            //USB_ISOCHRONOUS_PIPE,
            USB_BULK_PIPE,
            USB_SEND,
            SEMG_BULK_IN_PACKET_SIZE,
        },
        {
            SEMG_BULK_OUT_ENDPOINT,
            USB_BULK_PIPE,
            USB_RECV,
            SEMG_BULK_OUT_PACKET_SIZE,
        },
        {
            SEMG_NOTIF_ENDPOINT,
            USB_INTERRUPT_PIPE,
            USB_SEND,
            SEMG_NOTIF_ENDP_PACKET_SIZE
        }
    }
};

/* *********************************************************************
* definition a struct of Input/output or Feature Unit
************************************************************************ */
/* Struct of Terminal Input /Output or Feature Unit */
 USB_AUDIO_UNITS usb_audio_unit = {
    AUDIO_UNIT_COUNT,
    {
        {0x01,AUDIO_CONTROL_INPUT_TERMINAL},
        {0x02,AUDIO_CONTROL_FEATURE_UNIT},
        {0x03,AUDIO_CONTROL_OUTPUT_TERMINAL},
    }
};
 
/* Device Descriptor */
uint_8 g_device_descriptor[DEVICE_DESCRIPTOR_SIZE]=
{
    DEVICE_DESCRIPTOR_SIZE,            /* Device Descriptor Size         */
    USB_DEVICE_DESCRIPTOR,             /* Device Type of descriptor      */
    0x00, 0x02,                        /* BCD USB version                */
    0x00,                              /* Device Class is indicated inthe interface descriptors      */
    0x00,                              /* Device Subclass is indicated
                                       in the interface descriptors   */
    0x00,                              /* Device Protocol                */
    0x20,                              /* Max Packet size                */
    0xAC, 0x05,                        /* Vendor ID                      */
    0x22,0x22,                         /* Product ID  */
    0x10, 0x00,                        /* BCD Device version             */
    0x01 ,                             /* Manufacturer string index      */
    0x02 ,                             /* Product string index           */
    0x03 ,                             /* Serial number string index     */
    0x01                               /* Number of configurations       */
};

/* Configuration Descriptor */
uint_8 g_config_descriptor[CONFIG_DESC_SIZE] =
{
    CONFIG_ONLY_DESC_SIZE,             /* Configuration Descriptor Size */
    USB_CONFIG_DESCRIPTOR,             /* Configuration type of descriptor */
    USB_uint_16_low(CONFIG_DESC_SIZE),USB_uint_16_high(CONFIG_DESC_SIZE), /* Total length of the Configuration descriptor */
    0x02,                              /* NumInterfaces*/
    0x01,                              /* Configuration Value */
    0x00,                              /* Configuration Description String Index*/
    (BUS_POWERED | SELF_POWERED),      /* Attributes.support RemoteWakeup and self power*/
    0x32,                              /* Current draw from bus*/
    /* Interface 0 Descriptor */
    IFACE_ONLY_DESC_SIZE,              /* Size of this descriptor */
    USB_IFACE_DESCRIPTOR,              /* INTERFACE descriptor type */
    0x00,                              /* Number of interface */
    0x00,                              /* Alternate Setting value */
    0x01,                              /* Number of endpoints */
    0x00,                              /* Interface Class */
    0x00,                              /* Interface Sub Class */
    0x00,                              /* Interface Protocol */
    0x00,                              /* Index of a string descriptor */
    /* Endpoint 3 INTERRUPT IN Descriptor ()                                      */
    ENDP_ONLY_DESC_SIZE,               /* Descriptor size */
    USB_ENDPOINT_DESCRIPTOR,            /* Descriptor type: Endpopint descriptor */
    0x83,                              /* Address: 3, direction: IN */
    0x03,                              /* Transfer type: No Synchonisation */
    0x20, 0x00,                        /* Max. packet size: 8 byte(s) */
    0x00,                              /* Maximum NAK rate*/
    /* Interface 1 Descriptor ()                           */
    IFACE_ONLY_DESC_SIZE,              /* Descriptor Size */
    USB_IFACE_DESCRIPTOR,              /* Descriptor type: Interface descriptor */
    0x01,                              /* Number of this Interface (0..) */
    0x00,                              /* Alternative for this Interface (if any) */
    0x02,                              /* No of EPs used by this IF (excl. EP0) */
    0x00,                              /* Interface Class */
    0x00,                              /* Interface Subclass*/
    0x00,                              /* Interface Protocol*/
    0x00,                              /* Index of String Desc for this Interface */
    /* Endpoint 1 BULK IN Descriptor */
    ENDP_ONLY_DESC_SIZE,               /* Size of this descriptor */
    USB_ENDPOINT_DESCRIPTOR,           /* Descriptor type */
    0x81,                              /* Endpoint address */
    0x02,                              /* Transfer type: BULK and No Synchonisation */
    0x40,0x00,                         /* Max. packet size: 64 byte(s) */
    0x00,                              /* Maximum NAK rate*/
    /* Endpoint 2 BULK OUT Descriptor ()                                      */
    ENDP_ONLY_DESC_SIZE,               /* Descriptor size */
    USB_ENDPOINT_DESCRIPTOR,            /* Descriptor type: Endpopint descriptor */
    0x02,                              /* Address: 2, direction: OUT */
    0x02,                              /* Transfer type: BULK and No Synchonisation */
    0x40, 0x00,                        /* Max. packet size: 64 byte(s) */
    0x00,                              /* Maximum NAK rate*/ 
//    /* Class-specific SEMG Control Interface Descriptor */
//    HEADER_ONLY_DESC_SIZE,             /* Size of this descriptor */
//    AUDIO_INTERFACE_DESCRIPTOR_TYPE,   /* Interface descriptor type */
//    AUDIO_CONTROL_HEADER,              /* Interface descriptor sub type */
//    0x00,0x01,                         /* bcdADC */
//    0x29,0x00,                         /* Total Length */
//    0x01,                              /* Interface collection */
//    0x01,                              /* Interface Number */    
//
//    /* SEMG INTERFACE DESCRIPTOR */
//    /* Standard AS interface descriptor */
//    /* Alternate setting 0 */
//    IFACE_ONLY_DESC_SIZE,              /* Size of this descriptor */
//    USB_IFACE_DESCRIPTOR,              /* Descriptor type */
//    0x01,                              /* Interface number */
//    0x00,                              /* Alternate setting */
//    0x00,                              /* Number endpoints */
//    0x01,                              /* Interface class */
//    0x02,                              /* Interface sub class */
//    0x00,                              /* Interface protocol */
//    0x00,                              /* Interface index string */
//
//
//    /* Type I format type interface descriptor */
//    AUDIO_INTERFACE_DESC_TYPE_I_SIZE,  /* Size of this descriptor */
//    AUDIO_INTERFACE_DESCRIPTOR_TYPE,   /* Interface Descriptor type */
//    AUDIO_STREAMING_FORMAT_TYPE,       /* Interface descriptor sub type */
//    AUDIO_FORMAT_TYPE_I,               /* Format type */
//    0x01,                              /* Number channel */
//    0x01,                              /* Frame size */
//    0x10,                              /* Bit resolution */
//    0x01,                              /* One Sampling frequency */
//    0x40,0x1F,0x00,                    /* Sampling frequency */
};

/* String 0 Descriptor */
uint_8 USB_STR_0[USB_STR_0_SIZE+USB_STR_DESC_SIZE] = {
    sizeof(USB_STR_0),
    USB_STRING_DESCRIPTOR,
    0x09,
    0x04                               /*equiavlent to 0x0409*/
};

uint_8 USB_STR_1[USB_STR_1_SIZE+USB_STR_DESC_SIZE] = {
    sizeof(USB_STR_1),
    USB_STRING_DESCRIPTOR,
    'C',0,
    'N',0,
    '.',0,
    'E',0,
    'D',0,
    'U',0,
    '.',0,
    'Z',0,
    'J',0,
    'U',0,
    '.',0,
    'I',0,
    'S',0,
    'E',0,
    'E',0,
    '.',0,
    'C',0,
    '&',0,
    'S',0,
    ' ',0,
    ' ',0,
    ' ',0,
    ' ',0,
    ' ',0,
    ' ',0,
    ' ',0,
    ' ',0,
    ' ',0,
};
uint_8 USB_STR_2[USB_STR_2_SIZE+USB_STR_DESC_SIZE] = {
    sizeof(USB_STR_2),
    USB_STRING_DESCRIPTOR,
    'S',0,
    'E',0,
    'M',0,
    'G',0,
    ' ',0,
    'C',0,
    'A',0,
    'P',0,
    'T',0,
    'U',0,
    'R',0,
    'E',0,
    ' ',0,
    'D',0,
    'E',0,
    'V',0,
    'I',0,
    'C',0,
    'E',0,
    ' ',0,
};

uint_8 USB_STR_n[USB_STR_n_SIZE+USB_STR_DESC_SIZE] = {
    sizeof(USB_STR_n),
    USB_STRING_DESCRIPTOR,
    'B',0,
    'A',0,
    'D',0,
    ' ',0,
    'S',0,
    'T',0,
    'R',0,
    'I',0,
    'N',0,
    'G',0,
    ' ',0,
    'I',0,
    'N',0,
    'D',0,
    'E',0,
    'X',0
};

USB_PACKET_SIZE const g_std_desc_size[USB_MAX_STD_DESCRIPTORS+1] = {
    0,
    DEVICE_DESCRIPTOR_SIZE,
    CONFIG_DESC_SIZE,
    0, /* string */
    0, /* Interface */
    0, /* Endpoint */
    0, /* Device Qualifier */
    0, /* other speed config */
    0
};

uint_8_ptr const g_std_descriptors[USB_MAX_STD_DESCRIPTORS+1] = {
    NULL,
    (uint_8_ptr)g_device_descriptor,
    (uint_8_ptr)g_config_descriptor,
    NULL, /* string */
    NULL, /* Interface */
    NULL, /* Endpoint */
    NULL, /* Device Qualifier */
    NULL, /* other speed config*/
    NULL
};

uint_8 const g_string_desc_size[USB_MAX_STRING_DESCRIPTORS+1] = {
    sizeof(USB_STR_0),
    sizeof(USB_STR_1),
    sizeof(USB_STR_2),
    sizeof(USB_STR_n)
};

uint_8_ptr const g_string_descriptors[USB_MAX_STRING_DESCRIPTORS+1] = {
    (uint_8_ptr const)USB_STR_0,
    (uint_8_ptr const)USB_STR_1,
    (uint_8_ptr const)USB_STR_2,
    (uint_8_ptr const)USB_STR_n
};

USB_ALL_LANGUAGES g_languages = {
    USB_STR_0, sizeof(USB_STR_0),
    {
        {
            (uint_16 const)0x0409,
            (const uint_8 **)g_string_descriptors,
            g_string_desc_size
        }
    }
};

uint_8 const g_valid_config_values[USB_MAX_CONFIG_SUPPORTED+1]={0,1};





/****************************************************************************
* Public Variables
****************************************************************************/
/* Current mute variables */
//uint_8 g_cur_mute[USB_MAX_SUPPORTED_INTERFACES] ={0x00};

/****************************************************************************
* Internal Variables
****************************************************************************/
static uint_8 g_alternate_interface[USB_MAX_SUPPORTED_INTERFACES];

/* Current automatic gain variables */
static uint_8 g_cur_automatic_gain[USB_MAX_SUPPORTED_INTERFACES] = {0x01};

/* Copy protect variables */
static uint_8 g_copy_protect[USB_MAX_SUPPORTED_INTERFACES]={0x01};

/* Sampling frequency variables */
static uint_8 g_cur_sampling_frequency[3] = {0x00,0x00,0x01};

/* Status endpoint data */
static uint_8 status_endpoint_data[5] = {0x01, 0x02, 0x03, 0x04, 0x05};

static uint_8 g_alternate_interface[USB_MAX_SUPPORTED_INTERFACES];





/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**     Description :
**         The function returns the correponding descriptor
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         type            - 
**         str_num         - 
**         index           - 
**       * descriptor      - Pointer to descriptor 
**       * size            - Pointer to 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Desc_Get_Descriptor(
uint_8 controller_ID,
uint_8 type,
uint_8 str_num,
uint_16 index,
uint_8_ptr *descriptor,
USB_PACKET_SIZE *size
)
{
    UNUSED (controller_ID);
    switch(type)
    {
    case USB_AUDIO_DESCRIPTOR:
        {
            type = USB_CONFIG_DESCRIPTOR ;
            *descriptor = (uint_8_ptr)(g_std_descriptors [type]+
            CONFIG_ONLY_DESC_SIZE+IFACE_ONLY_DESC_SIZE);
            *size = AUDIO_ONLY_DESC_SIZE;
        }
        break;
    case USB_STRING_DESCRIPTOR:
        {
            if(index == 0)
            {
                /* return the string and size of all languages */
                *descriptor = (uint_8_ptr)g_languages.
                languages_supported_string;
                *size = g_languages.languages_supported_size;
            } else
            {
                uint_8 lang_id=0;
                uint_8 lang_index=USB_MAX_LANGUAGES_SUPPORTED;

                for(;lang_id< USB_MAX_LANGUAGES_SUPPORTED;lang_id++)
                {
                    /* check whether we have a string for this language */
                    if(index == g_languages.usb_language[lang_id].language_id)
                    {   /* check for max descriptors */
                        if(str_num < USB_MAX_STRING_DESCRIPTORS)
                        {   /* setup index for the string to be returned */
                            lang_index=str_num;
                        }
                        break;
                    }
                }

                /* set return val for descriptor and size */
                *descriptor = (uint_8_ptr)g_languages.usb_language[lang_id].
                lang_desc[lang_index];
                *size = g_languages.usb_language[lang_id].
                lang_desc_size[lang_index];
            }
        }
        break;
        default :
        if (type < USB_MAX_STD_DESCRIPTORS)
        {
            /* set return val for descriptor and size*/
            *descriptor = (uint_8_ptr)g_std_descriptors [type];

            /* if there is no descriptor then return error */
            if(*descriptor == NULL)
            {
                return USBERR_INVALID_REQ_TYPE;
            }
            *size = g_std_desc_size[type];
        }
        else /* invalid descriptor */
        {
            return USBERR_INVALID_REQ_TYPE;
        }
        break;
    }
    return USB_OK;
}

/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**     Description :
**         The function returns the alternate interface
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         interface       - 
**         alt_interface   - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Desc_Get_Interface(
uint_8 controller_ID,
uint_8 interface,
uint_8_ptr alt_interface
)
{
    UNUSED (controller_ID);
    /* if interface valid */
    if(interface < USB_MAX_SUPPORTED_INTERFACES)
    {
        /* get alternate interface*/
        *alt_interface = g_alternate_interface[interface];
        return USB_OK;
    }
    return USBERR_INVALID_REQ_TYPE;
}

/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**     Description :
**         The function sets the alternate interface
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         interface       - 
**         alt_interface   - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Desc_Set_Interface(
uint_8 controller_ID,
uint_8 interface,
uint_8 alt_interface
)
{
    UNUSED (controller_ID);
    /* if interface valid */
    if(interface < USB_MAX_SUPPORTED_INTERFACES)
    {
        /* set alternate interface*/
        g_alternate_interface[interface] = alt_interface;
        return USB_OK;
    }

    return USBERR_INVALID_REQ_TYPE;
}

/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**     Description :
**         The function checks whether the configuration parameter
**         input is valid or not
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         config_val      - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
boolean USB_Desc_Valid_Configation(
uint_8 controller_ID,
uint_16 config_val
)
{
    uint_8 loop_index=0;

    UNUSED (controller_ID);
    /* check with only supported val right now */
    while(loop_index < (USB_MAX_CONFIG_SUPPORTED+1))
    {
        if(config_val == g_valid_config_values[loop_index])
        {
            return TRUE;
        }
        loop_index++;
    }
    return FALSE;
}

/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**     Description :
**         The function checks whether the interface parameter input is
**         valid or not
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         interface       - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
boolean USB_Desc_Valid_Interface(
uint_8 controller_ID,
uint_8 interface
)
{
    uint_8 loop_index=0;
    UNUSED (controller_ID);
    /* check with only supported val right now */
    while(loop_index < USB_MAX_SUPPORTED_INTERFACES)
    {
        if(interface == g_alternate_interface[loop_index])
        {
            return TRUE;
        }
        loop_index++;
    }
    return FALSE;
}

/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**     Description :
**         The function checks whether the remote wakeup is supported
**         or not
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
boolean USB_Desc_Remote_Wakeup(uint_8 controller_ID)
{
    UNUSED (controller_ID);
    return REMOTE_WAKEUP_SUPPORT;
}

/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**     Description :
**         The function returns with the list of all non control
**         endpoints used
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
void* USB_Desc_Get_Endpoints(
uint_8 controller_ID
)
{
    UNUSED (controller_ID);
    return (void*)&usb_desc_ep;
}






//Next is audio specific function

/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**
**     Description :
**         The function returns with the list of all Input Terminal,
**         Output Terminal and Feature Unit
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
void* USB_Desc_Get_Entities(
uint_8 controller_ID
)
{
    UNUSED (controller_ID);
    return (void*)&usb_audio_unit;
}

/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**
**     Description :
**         The function is called in response to Set Terminal Control
**         Request
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         interface       - 
**       * data            - Pointer to Data
**       * size            - Pointer to size of data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Desc_Set_Copy_Protect(
uint_8 controller_ID,
uint_8 interface,
uint_8_ptr *data,
USB_PACKET_SIZE *size
)
{
    UNUSED (controller_ID);
    UNUSED (size);
    /* if interface valid */
    if(interface < USB_MAX_SUPPORTED_INTERFACES){
        /* set copy protect data*/
        g_copy_protect[interface] = **data;
        return USB_OK;
    }
    return USBERR_INVALID_REQ_TYPE;
}

/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**
**     Description :
**         The function is called in response to Get Terminal Control
**         Request
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         interface       - 
**       * data            - Pointer to Data
**       * size            - Pointer to size of data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Desc_Get_Copy_Protect(
uint_8 controller_ID,
uint_8 interface,
uint_8_ptr *data,
USB_PACKET_SIZE *size
)
{
    UNUSED (controller_ID);
    UNUSED (size);
    /* if interface valid */
    if(interface < USB_MAX_SUPPORTED_INTERFACES){
        /* get copy protect data*/
        *size=1;
        *data=&g_copy_protect[interface];
        return USB_OK;
    }
    return USBERR_INVALID_REQ_TYPE;
}

/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**     Description :
**         The function sets Current Automatic Gain value
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         interface       - 
**       * data            - Pointer to Data
**       * size            - Pointer to size of data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Desc_Set_Cur_Automatic_Gain(
uint_8 controller_ID,
uint_8 interface,
uint_8_ptr *data,
USB_PACKET_SIZE *size
)
{
    UNUSED (controller_ID);
    UNUSED (size);
    /* if interface valid */
    if(interface < USB_MAX_SUPPORTED_INTERFACES){
        /* set current automatic data*/
        g_cur_automatic_gain[interface] = **data;
        return USB_OK;
    }
    return USBERR_INVALID_REQ_TYPE;
}

/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**     Description :
**         The function gets Current Automatic Gain value
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         interface       - 
**       * data            - Pointer to Data
**       * size            - Pointer to size of data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Desc_Get_Cur_Automatic_Gain(
uint_8 controller_ID,
uint_8 interface,
uint_8_ptr *data,
USB_PACKET_SIZE *size
)
{
    UNUSED (controller_ID);
    /* if interface valid */
    if(interface < USB_MAX_SUPPORTED_INTERFACES){
        /* get current automatic data*/
        *size=1;
        *data=&g_cur_automatic_gain[interface];
        return USB_OK;
    }
    return USBERR_INVALID_REQ_TYPE;
}



/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**     Description :
**         The function sets Current Sampling Frequency value
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         interface       - 
**       * data            - Pointer to Data
**       * size            - Pointer to size of data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Desc_Set_Cur_Sampling_Frequency(
uint_8 controller_ID,
uint_8 interface,
uint_8_ptr *data,
USB_PACKET_SIZE *size
)
{
    UNUSED (controller_ID);
    UNUSED (size);
    UNUSED (interface);
    /* set current sampling fequency data*/
    g_cur_sampling_frequency[0] = **data;
    g_cur_sampling_frequency[1] = *(*data+1);
    g_cur_sampling_frequency[2] = *(*data+2);
    return USB_OK;
}

/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**     Description :
**         The function gets Current Sampling Frequency value
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         interface       - 
**       * data            - Pointer to Data
**       * size            - Pointer to size of data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Desc_Get_Cur_Sampling_Frequency(
uint_8 controller_ID,
uint_8 interface,
uint_8_ptr *data,
USB_PACKET_SIZE *size
)
{
    UNUSED (controller_ID);
    UNUSED (interface);
    /* get current sampling frequency data*/
    *size=3;
    *data=g_cur_sampling_frequency;
    return USB_OK;
}


/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**     Description :
**         The function gets endpoint memory value
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         offset          - 
**         interface       - 
**       * data            - Pointer to Data
**       * size            - Pointer to size of data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Desc_Set_Mem_Endpoint(
uint_8 controller_ID,
uint_16 offset,
uint_8 interface,
uint_8_ptr *data,
USB_PACKET_SIZE *size
)
{
    uint_16 index;

    UNUSED (controller_ID);
    UNUSED (interface);

    for(index = 0; index < *size ; index++)
    {   /* copy the report sent by the host */
        status_endpoint_data[offset + index] = *(*data + index);
    }
    *size = 0;

    return USB_OK;
}

/*
** ===================================================================
**     Method      :  usb_audio_ (component USB_AUDIO_CLASS)
**     Description :
**         The function gets endpoint memory value
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - 
**         offset          - 
**         interface       - 
**       * data            - Pointer to Data
**       * size            - Pointer to size of data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Desc_Get_Mem_Endpoint(
uint_8 controller_ID,
uint_16 offset,
uint_8 interface,
uint_8_ptr *data,
USB_PACKET_SIZE *size
)
{
    UNUSED (controller_ID);
    UNUSED (interface);
    UNUSED (size);

    *data = &status_endpoint_data[offset];
    return USB_OK;
}

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