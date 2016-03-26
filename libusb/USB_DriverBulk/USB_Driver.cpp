// USB_Driver.cpp : 定义 DLL 应用程序的导出函数。
#include "stdafx.h"
#include "lusb0_usb.h"

#pragma comment(lib, "libusb.lib")

#ifdef __GNUC__
#define _snprintf snprintf
#endif

// Enables this example to work with a device running the
// libusb-win32 PIC Benchmark Firmware.
//#define BENCHMARK_DEVICE

//////////////////////////////////////////////////////////////////////////////
// TEST SETUP (User configurable)

// Issues a Set configuration request
//#define TEST_SET_CONFIGURATION

// Issues a claim interface request
#define TEST_CLAIM_INTERFACE

// Use the libusb-win32 async transfer functions. see
// transfer_bulk_async() below.
#define TEST_ASYNC	0

// Attempts one bulk read.
#define TEST_BULK_READ

// Attempts one bulk write.
#define TEST_BULK_WRITE

//////////////////////////////////////////////////////////////////////////////
// DEVICE SETUP (User configurable)

// Device vendor and product id.
#define USB_VID 0x05AC
#define USB_PID 0x2222

// Device configuration and interface id.
#define MY_CONFIG 1
#define MY_INTF 0

struct usb_device *pBoard[100]={NULL};
usb_dev_handle *pBoardHandle[100]={NULL};

int verbose = 1;
/**
  * @brief  查找指定的USB设备个数
  * @param  pBoard 设备句柄存放地址
  * @retval 识别到的指定设备个数
  */
static int scan_dev(struct usb_device *pBoard[])
{
    struct usb_bus *bus;
    struct usb_device *dev;
	int devnum=0,i=0;
    for (bus = usb_get_busses(); bus; bus = bus->next)
    {
        for (dev = bus->devices; dev; dev = dev->next)
        {
            if (dev->descriptor.idVendor == USB_VID
                    && dev->descriptor.idProduct == USB_PID)
            {
				pBoard[devnum] = dev;
				devnum++;
            }
        }
    }
	for(i=devnum;i<100;i++){
		pBoard[i] = NULL;
	}
    return devnum;
}
/**
  * @brief  扫描设备连接数
  * @param  NeedInit 是否需要初始化，第一次调用该函数需要初始化
  * @retval 识别到的指定设备个数
  */
int __stdcall USBScanDev(int NeedInit)
{
	if(NeedInit){
		usb_init(); /* initialize the library */
		usb_find_busses(); /* find all busses */
		usb_find_devices(); /* find all connected devices */
	}
	return scan_dev(pBoard);
}

/**
  * @brief  打开指定的USB设备
  * @param  devNum	需要打开的设备号
  * @param	pBoard	设备句柄存放地址
  * @retval 已经打开了的设备句柄
  */
static usb_dev_handle * open_dev(int devNum,struct usb_device *pBoard[])
{
    struct usb_bus *bus;
    struct usb_device *dev;
	int devnum=0;
    for (bus = usb_get_busses(); bus; bus = bus->next)
    {
        for (dev = bus->devices; dev; dev = dev->next)
        {
            if (dev->descriptor.idVendor == USB_VID
                    && dev->descriptor.idProduct == USB_PID)
            {
                if(devnum==devNum){
					return usb_open(pBoard[devNum]);
				}
				devnum++;
            }
        }
    }
    return NULL;
}

/**
  * @brief  打开指定的USB设备
  * @param  devNum	需要打开的设备号
  * @retval 打开状态
  */
int __stdcall USBOpenDev(int DevIndex)
{
	pBoardHandle[DevIndex] = open_dev(DevIndex,pBoard);
	if(pBoardHandle[DevIndex]==NULL){
		return SEVERITY_ERROR;
	}else{
		return SEVERITY_SUCCESS;
	}
}
/**
  * @brief  关闭指定的USB设备
  * @param  devNum	需要关闭的设备号
  * @param  pBoardHandle	开打了的设备句柄
  * @retval 已经打开了的设备句柄
  */
static int close_dev(int devNum,struct usb_dev_handle *pBoardHandle[])
{
    struct usb_bus *bus;
    struct usb_device *dev;
	int devnum=0;
    for (bus = usb_get_busses(); bus; bus = bus->next)
    {
        for (dev = bus->devices; dev; dev = dev->next)
        {
            if (dev->descriptor.idVendor == USB_VID
                    && dev->descriptor.idProduct == USB_PID)
            {
                if(devnum==devNum){
					return usb_close(pBoardHandle[devNum]);
				}
				devnum++;
            }
        }
    }
    return NULL;
}

/**
  * @brief  关闭指定的USB设备
  * @param  devNum	需要关闭的设备号
  * @retval 打开状态
  */
int __stdcall USBCloseDev(int DevIndex)
{
	return close_dev(DevIndex,pBoardHandle);
}

/*
* Read/Write using async transfer functions.
*
* NOTE: This function waits for the transfer to complete essentially making
* it a sync transfer function so it only serves as an example of how one might
* implement async transfers into thier own code.
*/
static int transfer_bulk_async(usb_dev_handle *dev,
                               int ep,
                               char *bytes,
                               int size,
                               int timeout)
{
    // Each async transfer requires it's own context. A transfer
    // context can be re-used.  When no longer needed they must be
    // freed with usb_free_async().
    //
    void* async_context = NULL;
    int ret;

    // Setup the async transfer.  This only needs to be done once
    // for multiple submit/reaps. (more below)
    //
    ret = usb_bulk_setup_async(dev, &async_context, ep);
    if (ret < 0)
    {
        //printf("error usb_bulk_setup_async:\n%s\n", usb_strerror());
        goto Done;
    }

    // Submit this transfer.  This function returns immediately and the
    // transfer is on it's way to the device.
    //
    ret = usb_submit_async(async_context, bytes, size);
    if (ret < 0)
    {
        //printf("error usb_submit_async:\n%s\n", usb_strerror());
        usb_free_async(&async_context);
        goto Done;
    }

    // Wait for the transfer to complete.  If it doesn't complete in the
    // specified time it is cancelled.  see also usb_reap_async_nocancel().
    //
    ret = usb_reap_async(async_context, timeout);

    // Free the context.
    usb_free_async(&async_context);

Done:
    return ret;
}

/**
  * @brief  USB Bulk端点写数据
  * @param  nBoardID 设备号
  * @param  pipenum 端点号
  * @param  sendbuffer 发送数据缓冲区
  * @param  len 发送数据字节数
  * @param  waittime 超时时间
  * @retval 成功发送的数据字节数
  */

int __stdcall USBBulkWriteData(unsigned int nBoardID,int pipenum,char *sendbuffer,int len,int waittime)
{
	int ret=0;
	if(pBoardHandle[nBoardID] == NULL){
		return SEVERITY_ERROR;
	}
#ifdef TEST_SET_CONFIGURATION
    if (usb_set_configuration(pBoardHandle[nBoardID], MY_CONFIG) < 0)
    {
        usb_close(pBoardHandle[nBoardID]);
        return SEVERITY_ERROR;
    }
#endif

#ifdef TEST_CLAIM_INTERFACE
    if (usb_claim_interface(pBoardHandle[nBoardID], 0) < 0)
    {
        usb_close(pBoardHandle[nBoardID]);
        return SEVERITY_ERROR;
    }
#endif

#if TEST_ASYNC
    // Running an async write test
    ret = transfer_bulk_async(dev, pipenum, sendbuffer, len, waittime);
#else
	ret = usb_bulk_write(pBoardHandle[nBoardID], pipenum, sendbuffer, len, waittime);
	/*if((len%64) == 0){
		usb_bulk_write(pBoardHandle[nBoardID], pipenum, sendbuffer, 0, waittime);
	}*/
#endif
#ifdef TEST_CLAIM_INTERFACE
    usb_release_interface(pBoardHandle[nBoardID], 0);
#endif
    return ret;
}

/**
  * @brief  USB interrupt端点写数据
  * @param  nBoardID 设备号
  * @param  pipenum 端点号
  * @param  sendbuffer 发送数据缓冲区
  * @param  len 发送数据字节数
  * @param  waittime 超时时间
  * @retval 成功发送的数据字节数
  */
int __stdcall USBIntWriteData(unsigned int nBoardID,int pipenum,char *sendbuffer,int len,int waittime)
{
	int ret=0;
	if(pBoardHandle[nBoardID] == NULL){
		return SEVERITY_ERROR;
	}
#ifdef TEST_SET_CONFIGURATION
    if (usb_set_configuration(pBoardHandle[nBoardID], MY_CONFIG) < 0)
    {
        usb_close(pBoardHandle[nBoardID]);
        return SEVERITY_ERROR;
    }
#endif

#ifdef TEST_CLAIM_INTERFACE
    if (usb_claim_interface(pBoardHandle[nBoardID], 0) < 0)
    {
        usb_close(pBoardHandle[nBoardID]);
        return SEVERITY_ERROR;
    }
#endif
	ret = usb_interrupt_write(pBoardHandle[nBoardID], pipenum, sendbuffer, len, waittime);
#ifdef TEST_CLAIM_INTERFACE
    usb_release_interface(pBoardHandle[nBoardID], 0);
#endif
    return ret;
}

/**
  * @brief  USB 控制端点写数据
  * @param  nBoardID 设备号
  * @param  pipenum 端点号
  * @param  sendbuffer 发送数据缓冲区
  * @param  len 发送数据字节数
  * @param  waittime 超时时间
  * @retval 成功发送的数据字节数
  */
int __stdcall USBCtrlData(unsigned int nBoardID,int requesttype,int request,int value, int index, char *bytes, int size,int waittime)
{
	int ret=0;
	if(pBoardHandle[nBoardID] == NULL){
		return SEVERITY_ERROR;
	}
#ifdef TEST_SET_CONFIGURATION
    if (usb_set_configuration(pBoardHandle[nBoardID], MY_CONFIG) < 0)
    {
        usb_close(pBoardHandle[nBoardID]);
        return SEVERITY_ERROR;
    }
#endif

#ifdef TEST_CLAIM_INTERFACE
    if (usb_claim_interface(pBoardHandle[nBoardID], 0) < 0)
    {
        usb_close(pBoardHandle[nBoardID]);
        return SEVERITY_ERROR;
    }
#endif
	ret = usb_control_msg(pBoardHandle[nBoardID], requesttype, request,value, index, bytes, size,waittime);
#ifdef TEST_CLAIM_INTERFACE
    usb_release_interface(pBoardHandle[nBoardID], 0);
#endif
    return ret;
}

/**
  * @brief  USB Bulk读数据
  * @param  nBoardID 设备号
  * @param  pipenum 端点号
  * @param  readbuffer 读取数据缓冲区
  * @param  len 读取数据字节数
  * @param  waittime 超时时间
  * @retval 读到的数据字节数
  */
int __stdcall USBBulkReadData(unsigned int nBoardID,int pipenum,char *readbuffer,int len,int waittime)
{
	int ret=0;
	if(pBoardHandle[nBoardID] == NULL){
		return SEVERITY_ERROR;
	}
#ifdef TEST_SET_CONFIGURATION
    if (usb_set_configuration(pBoardHandle[nBoardID], MY_CONFIG) < 0)
    {
        usb_close(pBoardHandle[nBoardID]);
        return SEVERITY_ERROR;
    }
#endif

#ifdef TEST_CLAIM_INTERFACE
    if (usb_claim_interface(pBoardHandle[nBoardID], 0) < 0)
    {
        usb_close(pBoardHandle[nBoardID]);
        return SEVERITY_ERROR;
    }
#endif

#if TEST_ASYNC
    // Running an async read test
    ret = transfer_bulk_async(pGinkgoBoardHandle[nBoardID], pipenum, sendbuffer, len, waittime);
#else
	ret = usb_bulk_read(pBoardHandle[nBoardID], pipenum, readbuffer, len, waittime);
#endif
#ifdef TEST_CLAIM_INTERFACE
    usb_release_interface(pBoardHandle[nBoardID], 0);
#endif
    return ret;
}

/**
  * @brief  USB interrupt读数据
  * @param  nBoardID 设备号
  * @param  pipenum 端点号
  * @param  readbuffer 读取数据缓冲区
  * @param  len 读取数据字节数
  * @param  waittime 超时时间
  * @retval 读到的数据字节数
  */
int __stdcall USBIntReadData(unsigned int nBoardID,int pipenum,char *readbuffer,int len,int waittime)
{
	int ret=0;
	if(pBoardHandle[nBoardID] == NULL){
		return SEVERITY_ERROR;
	}
#ifdef TEST_SET_CONFIGURATION
    if (usb_set_configuration(pGinkgoBoardHandle[nBoardID], MY_CONFIG) < 0)
    {
        usb_close(pGinkgoBoardHandle[nBoardID]);
        return SEVERITY_ERROR;
    }
#endif

#ifdef TEST_CLAIM_INTERFACE
    if (usb_claim_interface(pBoardHandle[nBoardID], 0) < 0)
    {
        usb_close(pBoardHandle[nBoardID]);
        return SEVERITY_ERROR;
    }
#endif
	ret = usb_interrupt_read(pBoardHandle[nBoardID], pipenum, readbuffer, len, waittime);
#ifdef TEST_CLAIM_INTERFACE
    usb_release_interface(pBoardHandle[nBoardID], 0);
#endif
    return ret;
}



void print_endpoint(struct usb_endpoint_descriptor *endpoint)
{
  printf("      bEndpointAddress: %02xh\n", endpoint->bEndpointAddress);
  printf("      bmAttributes:     %02xh\n", endpoint->bmAttributes);
  printf("      wMaxPacketSize:   %d\n", endpoint->wMaxPacketSize);
  printf("      bInterval:        %d\n", endpoint->bInterval);
  printf("      bRefresh:         %d\n", endpoint->bRefresh);
  printf("      bSynchAddress:    %d\n", endpoint->bSynchAddress);
}

void print_altsetting(struct usb_interface_descriptor *interface)
{
  int i;

  printf("    bInterfaceNumber:   %d\n", interface->bInterfaceNumber);
  printf("    bAlternateSetting:  %d\n", interface->bAlternateSetting);
  printf("    bNumEndpoints:      %d\n", interface->bNumEndpoints);
  printf("    bInterfaceClass:    %d\n", interface->bInterfaceClass);
  printf("    bInterfaceSubClass: %d\n", interface->bInterfaceSubClass);
  printf("    bInterfaceProtocol: %d\n", interface->bInterfaceProtocol);
  printf("    iInterface:         %d\n", interface->iInterface);

  for (i = 0; i < interface->bNumEndpoints; i++)
    print_endpoint(&interface->endpoint[i]);
}

void print_interface(struct usb_interface *interface)
{
  int i;

  for (i = 0; i < interface->num_altsetting; i++)
    print_altsetting(&interface->altsetting[i]);
}

void print_configuration(struct usb_config_descriptor *config)
{
  int i;

  printf("  wTotalLength:         %d\n", config->wTotalLength);
  printf("  bNumInterfaces:       %d\n", config->bNumInterfaces);
  printf("  bConfigurationValue:  %d\n", config->bConfigurationValue);
  printf("  iConfiguration:       %d\n", config->iConfiguration);
  printf("  bmAttributes:         %02xh\n", config->bmAttributes);
  printf("  MaxPower:             %d\n", config->MaxPower);

  for (i = 0; i < config->bNumInterfaces; i++)
    print_interface(&config->interface[i]);
}


//DevIndex is the number index of device
int __stdcall print_device(int DevIndex)
{

  usb_dev_handle *udev;
  struct usb_device *dev;

  char description[256];
  char string[256];
  int ret, i;
  description[sizeof(description)-1]=0;//ensure the last char is null

  dev = pBoard[DevIndex];

  udev = usb_open(dev);
  if (udev) {
    if (dev->descriptor.iManufacturer) {
	  printf("iManufacturer = %d\n", dev->descriptor.iManufacturer);
      ret = usb_get_string_simple(udev, dev->descriptor.iManufacturer, string, sizeof(string));
      if (ret > 0)
        _snprintf(description, sizeof(description), "%s - ", string);//using _snprintf replace snprintf(GCC)
      else
        _snprintf(description, sizeof(description), "%04X - ",
                 dev->descriptor.idVendor);
    } else
      _snprintf(description, sizeof(description), "%04X - ",
               dev->descriptor.idVendor);

    if (dev->descriptor.iProduct) {
	  printf("iProduct = %d\n", dev->descriptor.iProduct);
      ret = usb_get_string_simple(udev, dev->descriptor.iProduct, string, sizeof(string));
      if (ret > 0)
        _snprintf(description + strlen(description), sizeof(description) -
                 strlen(description), "%s", string);
      else
        _snprintf(description + strlen(description), sizeof(description) -
                 strlen(description), "%04X", dev->descriptor.idProduct);
    } else
      _snprintf(description + strlen(description), sizeof(description) -
               strlen(description), "%04X", dev->descriptor.idProduct);

  } else
    _snprintf(description, sizeof(description), "%04X - %04X",
             dev->descriptor.idVendor, dev->descriptor.idProduct);

  printf("#%d:   %s\n",  dev->devnum,    description);

  //if (udev)
  //  usb_close(udev);


  if (!dev->config) {
      printf("  Couldn't retrieve descriptors\n");
      return 0;
    }

    for (i = 0; i < dev->descriptor.bNumConfigurations; i++)
      print_configuration(&dev->config[i]);


  return 0;
}



/*
int main(int argc, char *argv[])
{
  struct usb_bus *bus;
  int DevNum;
  int ret;

  if (argc > 1 && !strcmp(argv[1], "-v"))
    verbose = 1;

  usb_init();

  usb_find_busses();
  usb_find_devices();

  for (bus = usb_busses; bus; bus = bus->next) {
    if (bus->root_dev && !verbose)
      print_device(bus->root_dev, 0);
    else {
      struct usb_device *dev;

      for (dev = bus->devices; dev; dev = dev->next)
        print_device(dev, 0);
    }
  }

  return 0;
}
*/

