/*
 * usb_mems.c
 *
 *  Created on: Apr 20, 2015
 *      Author: lab
 */
#include "PE_Types.h"
#include "usb_mems.h"
#include "usb_devapi.h"   /* USB device Header File */
#include "usb_class.h"

static       uint8       g_current_interface = 0;
extern       uint8       MCU_NUMBER; 
extern       uint16      S_FrameNumber;
extern       uint16      G_FrameNumber;
extern       uint8       Init_State;//MCU Init State

/* callback function pointer structure for Application to handle events */
typedef void(_CODE_PTR_ USB_CLASS_CALLBACK)(uint_8, uint_8, void*);
/* callback function pointer structure to handle USB framework request */
typedef uint_8 (_CODE_PTR_ USB_REQ_FUNC)(uint_8, USB_SETUP_STRUCT *,
                                              uint_8_ptr*,
                                              USB_PACKET_SIZE*);


/****************************************************************************
* Internal Variables
****************************************************************************/
/* Mems endpoint info array */
USB_CLASS_MEMS_ENDPOINT_DATA g_mems_endpoint_data;
/* Mems Class Callback Function Pointer */
static USB_CLASS_CALLBACK g_mems_class_callback=NULL;
/* Mems Class Vendor Callback Function Pointer */
static USB_REQ_FUNC       g_vendor_req_callback=NULL;
/* Mems Class requests Callback Function Pointer */
static USB_CLASS_CALLBACK g_param_callback = NULL;

/*
** ===================================================================
**     Method      :  USB_Service_Mems_Status_Interrupt (component USB_MEMS_CLASS)
**
**     Description :
**         The funtion is callback function of Mems Status Interrupt 
**         endpoint
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Service_Mems_Status_Interrupt(
PTR_USB_DEV_EVENT_STRUCT event
)
{
    uint_8 index;
    uint_8 producer, consumer;
    USB_ENDPOINTS *usb_ep_data = (USB_ENDPOINTS *)USB_Desc_Get_Endpoints(event->controller_ID);

    /* map the endpoint num to the index of the endpoint structure */
    for(index = 0; index < usb_ep_data->count; index++)
    {
        if(usb_ep_data->ep[index].ep_num == event->ep_num)
        break;
    }

    producer = g_mems_endpoint_data.ep[index].bin_producer;
    consumer = g_mems_endpoint_data.ep[index].bin_consumer;
    /* if there are no errors de-queue the queue and decrement the no. of
    transfers left, else send the same data again */
    if (event->errors == 0)
    {
        /* de-queue if the send is complete without an error */
        if((MAX_QUEUE_ELEMS-1) == consumer)
        {
            g_mems_endpoint_data.ep[index].bin_consumer = 0;
        }
        else
        {
            g_mems_endpoint_data.ep[index].bin_consumer++;
        }
    }

    consumer = g_mems_endpoint_data.ep[index].bin_consumer;
    g_mems_endpoint_data.ep[index].queue_num--;

    if(0 == g_mems_endpoint_data.ep[index].queue_num)
    {
        /*if bin is not empty */
        USB_CLASS_MEMS_QUEUE queue;
        /* send the next packet in queue */
        queue = g_mems_endpoint_data.ep[index].queue[consumer];
        (void)USB_Class_Send_Data(queue.controller_ID, queue.channel,
        queue.app_buff, queue.size);
    }

    if(g_param_callback != NULL)
    {
        uint_8 event_type = USB_APP_SEND_COMPLETE;
        if(event->errors != 0)
        {
            event_type = USB_APP_ERROR;
        }
        g_param_callback(event->controller_ID, event_type,
        (uint_8*)(&(event->errors)));
    }
}


/*
** ===================================================================
**     Method      :  USB_Class_MEMS_Service_Dic_Bulk_In (component USB_MEMS_CLASS)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Class_MEMS_Service_Dic_Bulk_In(PTR_USB_DEV_EVENT_STRUCT event)
{
	    uint_8 index;
	    uint_8 producer, consumer;
	    APP_DATA_STRUCT iso_in_recv;
	    USB_ENDPOINTS *usb_ep_data = (USB_ENDPOINTS *)USB_Desc_Get_Endpoints(event->controller_ID);

	    iso_in_recv.data_ptr  = event->buffer_ptr;
	    iso_in_recv.data_size = event->len;
	    /* map the endpoint num to the index of the endpoint structure */
	    for(index = 0; index < usb_ep_data->count; index++)
	    {
	        if(usb_ep_data->ep[index].ep_num ==event->ep_num)
	        break;
	    }
	    producer = g_mems_endpoint_data.ep[index].bin_producer;
	    /* if there are no errors de-queue the queue and decrement the no. of
	    transfers left, else send the same data again */
	    if(event->errors == 0)
	    {
	        /* de-queue if the send is complete without an error */
	        if ((MAX_QUEUE_ELEMS-1) == g_mems_endpoint_data.ep[index].bin_consumer)
	        {
	            g_mems_endpoint_data.ep[index].bin_consumer = 0;
	        }
	        else
	        {
	            g_mems_endpoint_data.ep[index].bin_consumer++;
	        }
	        g_mems_endpoint_data.ep[index].queue_num--;
	    }

	    consumer = g_mems_endpoint_data.ep[index].bin_consumer;
	    if(0 != g_mems_endpoint_data.ep[index].queue_num)
	    {
	        /*if bin is not empty */
	        USB_CLASS_MEMS_QUEUE queue;
	        /* send the next packet in queue */
	        queue = g_mems_endpoint_data.ep[index].queue[consumer];
	        (void)USB_Class_Send_Data(queue.controller_ID, queue.channel,
	        queue.app_buff, queue.size);
	    }

	    if(g_mems_class_callback != NULL)
	    {
	        uint_8 event_type = USB_APP_SEND_COMPLETE;
	        if(event->errors != 0)
	        {
	            event_type = USB_APP_ERROR;
	        }
	        g_mems_class_callback(event->controller_ID, event_type,
	        (uint_8*)(&(event->errors)));
	    }
}

/*
** ===================================================================
**     Method      :  USB_Class_MEMS_Service_Dic_Bulk_Out (component USB_CDC_CLASS)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Class_MEMS_Service_Dic_Bulk_Out(PTR_USB_DEV_EVENT_STRUCT event)
{
   APP_DATA_STRUCT bulk_out_recv;

    bulk_out_recv.data_ptr = event->buffer_ptr;
    bulk_out_recv.data_size = event->len;

    if(g_mems_class_callback != NULL)
    {
        if(event->errors != 0)
        {
            g_mems_class_callback(event->controller_ID, USB_APP_ERROR,
                (uint_8*)(&(event->errors)));
        }
        else
        {
        	g_mems_class_callback(event->controller_ID, USB_APP_DATA_RECEIVED,
                (void*)&bulk_out_recv);
        }
    }
}



/*
** ===================================================================
**     Method      :  USB_Class_Mems_Event (component USB_MEMS_CLASS)
**
**     Description :
**         The funtion initializes Mems endpoint
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Class_Mems_Event(
uint_8 controller_ID,
uint_8 event,
void* val
)
{
    uint_8 index;

    if(event == USB_APP_ENUM_COMPLETE)
    {
        uint_8 count;
        /* get the endpoints from the descriptor module */
        USB_ENDPOINTS *ep_desc_data = (USB_ENDPOINTS *)
        USB_Desc_Get_Endpoints(controller_ID);

        count = ep_desc_data->count;
        /* deinitialize all endpoints in case they were initialized */
        while(count > 0)
        {
            USB_EP_STRUCT_PTR ep_struct_ptr=
            (USB_EP_STRUCT_PTR) (&ep_desc_data->ep[count - 1]);
            (void)_usb_device_deinit_endpoint(&controller_ID,
            ep_struct_ptr->ep_num, ep_struct_ptr->direction);
            count--;
        }

        /* intialize all non control endpoints */
        while(count < ep_desc_data->count)
        {
            USB_EP_STRUCT_PTR ep_struct=
            (USB_EP_STRUCT_PTR)&ep_desc_data->ep[count];

            (void)_usb_device_init_endpoint(&controller_ID, ep_struct->ep_num,
            ep_struct->size, ep_struct->direction, ep_struct->type, TRUE);

            /* register callback service for the endpoint */
            switch(ep_struct->type)
            {
            case USB_INTERRUPT_PIPE:
                (void)_usb_device_register_service(controller_ID,
                (uint_8)(USB_SERVICE_EP0+ep_struct->ep_num),
                USB_Service_Mems_Status_Interrupt);
                break;       
                
            case USB_BULK_PIPE :
               if(ep_struct->direction == USB_RECV)
               {
                     (void)_usb_device_register_service(controller_ID,
                     (uint_8)(USB_SERVICE_EP0+ep_struct->ep_num),
                     USB_Class_MEMS_Service_Dic_Bulk_Out);
               }
               else
               {
                      (void)_usb_device_register_service(controller_ID,
                      (uint_8)(USB_SERVICE_EP0+ep_struct->ep_num),
                      USB_Class_MEMS_Service_Dic_Bulk_In);
               }
               break;
                                
            default:
                break;
            }
            /* set the EndPoint Status as Idle in the device layer */
            (void)_usb_device_set_status(&controller_ID,
            (uint_8)(USB_STATUS_ENDPOINT | 1|
            (ep_struct->direction << USB_COMPONENT_DIRECTION_SHIFT)),
            USB_STATUS_IDLE);
            count++;
        }
    }
    else if(event == USB_APP_BUS_RESET)
    {
        /* clear producer and consumer on reset */
        for(index = 0; index < g_mems_endpoint_data.count; index++)
        {
            g_mems_endpoint_data.ep[index].bin_consumer = 0x00;
            g_mems_endpoint_data.ep[index].bin_producer = 0x00;
            g_mems_endpoint_data.ep[index].queue_num    = 0x00;
        }
    }

    if(g_mems_class_callback != NULL)
    {
        /* notify the event to the application */
        g_mems_class_callback(controller_ID, event, val);
    }
}


/*
** ===================================================================
**     Method      :  USB_Get_Request_MCU (component USB_CDC_CLASS)
**     Description :
**         This function is called in response to Get MCU Message
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**       * setup_packet    - [IN] Pointer to setup
**                           packet
**       * data            - [OUT] Pointer to Data
**       * size            - [OUT] Pointer to Size of Data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
static uint_8  USB_Get_Request_MCU(
uint_8 controller_ID,
USB_SETUP_STRUCT *setup_packet,
uint_8_ptr *data,
USB_PACKET_SIZE *size
)
{    
    UNUSED (controller_ID);
    g_current_interface = (uint_8)setup_packet->index ;
 
    switch(setup_packet -> request)
        {
            /* Copy Protect Control only supports the CUR attribute!*/
        case GET_NUMber:
        	/* if interface valid */
        	if(g_current_interface < USB_MAX_SUPPORTED_INTERFACES){
        	/* get MCU_NUMBER*/
        	*size=1;
        	*data=&MCU_NUMBER;
        	}
            break;
        case GET_Frame:
        	/* if interface valid */
        	if(g_current_interface < USB_MAX_SUPPORTED_INTERFACES){
        	/* get Expected Frame*/
        	*size=2;
        	S_FrameNumber &= 0x3ff;
        	*data=&S_FrameNumber ;
        	}
            break; 
        case Get_State:
             /* if interface valid */
             if(g_current_interface < USB_MAX_SUPPORTED_INTERFACES){
             /* get Init State*/
             *size=1;
             *data=&Init_State ;
             }
             break;
        default:
            break;
        }    
     return USB_OK;
}

/*
** ===================================================================
**     Method      :  USB_Set_Request_MCU (component USB_CDC_CLASS)
**     Description :
**         This function is called in response to Set MCU Message 
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**       * setup_packet    - [IN] Pointer to setup
**                           packet
**       * data            - [OUT] Pointer to Data the Time to Sample Delay
**       * size            - [OUT] Pointer to Size of Data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
static uint_8  USB_Set_Request_MCU(
uint_8 controller_ID,
USB_SETUP_STRUCT *setup_packet,
uint_8_ptr *data,
USB_PACKET_SIZE *size
)
{    
	uint16_t    SampleDelay = 0;
	UNUSED (controller_ID);
    g_current_interface = (uint_8)setup_packet->index ;
    
    switch(setup_packet -> request)
            {
                /* Copy Protect Control only supports the CUR attribute!*/
            case SET_Sample:
            	/* if interface valid */
            	if(g_current_interface < USB_MAX_SUPPORTED_INTERFACES){
            	/* set expected sample time delay */
            	SampleDelay = (uint_16)setup_packet->value;
            	SampleDelay = SampleDelay % 1024;
            	S_FrameNumber += SampleDelay;
            	S_FrameNumber &= 0x3ff; //if  S_FrameNumber > 1024,S_FrameNumber -= 1024
            	}
                break;
            case SET_Frame:
                /* if interface valid */
                if(g_current_interface < USB_MAX_SUPPORTED_INTERFACES){
                /* set expected frame number */
                S_FrameNumber = (uint_16)setup_packet->value;
                S_FrameNumber &= 0x3ff;//if  S_FrameNumber > 1024,S_FrameNumber -= 1024
                }
                break;       
            default:
                break;
            }    
     return USB_OK;
}
/*
** ===================================================================
**     Method      :  USB_Other_Requests (component USB_MEMS_CLASS)
**
**     Description :
**         The funtion provides flexibilty to add class and vendor 
**         specific requests
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_Other_Requests(
uint_8 controller_ID,
USB_SETUP_STRUCT *setup_packet,
uint_8_ptr *data,
USB_PACKET_SIZE *size
)
{
    uint_8 status = USBERR_INVALID_REQ_TYPE;
    /* point to the data which comes after the setup packet */
    *data = ((uint_8*)setup_packet)+USB_SETUP_PKT_SIZE;
    if (size == NULL)
    {
        return USBERR_GET_MEMORY_FAILED;
    }
    switch(setup_packet->request_type)
    {
        /*Get MCU USB Message */
    case GET_REQUEST_MCU:
        status = USB_Get_Request_MCU(controller_ID,setup_packet,data,size);
        break;
        /* Set MCU USB Message */
    case SET_REQUEST_MCU:
        status = USB_Set_Request_MCU(controller_ID,setup_packet,data,size);
        break;
        /* Get Endpoint Request */
    //case GET_REQUEST_EP:
    //    status = USB_Get_Request_Endpoint(controller_ID,setup_packet,data,size);
    //    break;
    default:
        break;
    } /* end of switch */
    return status;
}

/*
** ===================================================================
**     Method      :  USB_Class_Mems_Init (component USB_MEMS_CLASS)
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
uint_8 USB_Class_Mems_Init(
uint_8 controller_ID,
USB_CLASS_CALLBACK mems_class_callback,
USB_REQ_FUNC vendor_req_callback,
USB_CLASS_CALLBACK param_callback
)
{
    uint_8 index;
    USB_ENDPOINTS *ep_desc_data = (USB_ENDPOINTS *)
    USB_Desc_Get_Endpoints(controller_ID);

    /* Initialize the device layer*/
    uint_8 status = _usb_device_init(controller_ID, NULL,
    (uint_8)(ep_desc_data->count+1));
    if(status == USB_OK)
    {
        /* Initialize the generic class functions */
        status = USB_Class_Init(controller_ID,USB_Class_Mems_Event,
        USB_Other_Requests);
        if(status == USB_OK)
        {
            g_mems_endpoint_data.count = ep_desc_data->count;
            for(index = 0; index < ep_desc_data->count; index++)
            {
                g_mems_endpoint_data.ep[index].endpoint =
                ep_desc_data->ep[index].ep_num;
                g_mems_endpoint_data.ep[index].type =
                ep_desc_data->ep[index].type;
                g_mems_endpoint_data.ep[index].bin_consumer = 0x00;
                g_mems_endpoint_data.ep[index].bin_producer = 0x00;
                g_mems_endpoint_data.ep[index].queue_num    = 0x00;
            }

            /* save the Mems class callback pointer */
            g_mems_class_callback = mems_class_callback;

            /* save the vendor request callback pointer */
            g_vendor_req_callback = vendor_req_callback;

            /* Save the callback to ask application for class specific params*/
            g_param_callback = param_callback;
        }
    }
    return status;
}

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
uint_8 USB_Class_Mems_DeInit(
uint_8 controller_ID
)
{
    uint_8 status;

    /* free the Mems class callback pointer */
    g_mems_class_callback = NULL;

    /* free the vendor request callback pointer */
    g_vendor_req_callback = NULL;

    /* free the callback to ask application for class specific params*/
    g_param_callback = NULL;

    /* Call common class deinit function */
    status = USB_Class_DeInit(controller_ID);

    if(status == USB_OK)
    /* Call device deinit function */
    status = _usb_device_deinit();

    return status;
}

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
uint_8 USB_Class_Mems_Send_Data(
uint_8 controller_ID,
uint_8 ep_num,
uint_8_ptr app_buff,
USB_PACKET_SIZE size
)
{
    uint_8 status = USB_OK;
    PTR_USB_CLASS_MEMS_QUEUE queue_tmp;
    uint_8 index;
    uint_8 producer, queue_num;

    USB_ENDPOINTS *usb_ep_data = (USB_ENDPOINTS *)
    USB_Desc_Get_Endpoints(controller_ID);

    /* map the endpoint num to the index of the endpoint structure */

    for(index = 0; index < usb_ep_data->count; index++)
    {
        if(usb_ep_data->ep[index].ep_num == ep_num)
        break;
    }

    producer = g_mems_endpoint_data.ep[index].bin_producer;
    queue_num = g_mems_endpoint_data.ep[index].queue_num;

    //if queue_num==1,there is already a queue,USB is busy
    //if queue_num!=1,there USB queue is empty
    if(MAX_QUEUE_ELEMS != queue_num) 
    {
        /* the bin is not full*/
        /* put all send request parameters in the endpoint data structure */
        queue_tmp = &(g_mems_endpoint_data.ep[index].queue[producer]);
        queue_tmp->controller_ID  = controller_ID;
        queue_tmp->channel        = ep_num;
        queue_tmp->app_buff       = app_buff;
        queue_tmp->size           = size;

        /* increment producer bin by 1*/
        if (producer == (MAX_QUEUE_ELEMS - 1))
        {
            g_mems_endpoint_data.ep[index].bin_producer = 0;
        }
        else
        {
            g_mems_endpoint_data.ep[index].bin_producer++;
        }
        g_mems_endpoint_data.ep[index].queue_num++;

        if(g_mems_endpoint_data.ep[index].queue_num == 1)
        {
            status = USB_Class_Send_Data(controller_ID, ep_num, app_buff,size);
        }
    }
    else /* bin is full */
    {
        status = USBERR_DEVICE_BUSY;
    }
    return status;
}

/*
** ===================================================================
**     Method      :  usb_mems_USB_Class_Mems_Recv_Data (component USB_MEMS_CLASS)
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
uint_8 USB_Class_Mems_Recv_Data(
uint_8 controller_ID,
uint_8 ep_num,
uint_8_ptr app_buff,
USB_PACKET_SIZE size
)
{
    uint_8 status;
    status = _usb_device_recv_data(&controller_ID,ep_num,app_buff,size);
    return status;
}
