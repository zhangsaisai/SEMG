#ifndef __USB_DRIVER_H__
#define __USB_DRIVER_H__

// Device endpoint(s)
#define EP0		0x00
#define EP1_IN	0x81	//wMaxPacketSize:   16	Int
#define EP1_OUT	0x01	//wMaxPacketSize:   16	Int
#define EP2_IN	0x82	//wMaxPacketSize:   64	Bulk
#define EP2_OUT	0x02	//wMaxPacketSize:   64	Bulk

int __stdcall USBScanDev(int NeedInit);
int __stdcall USBOpenDev(int DevIndex);
int __stdcall USBCloseDev(int DevIndex);
int __stdcall USBBulkWriteData(unsigned int nBoardID,int pipenum,char *sendbuffer,int len,int waittime);
int __stdcall USBBulkReadData(unsigned int nBoardID,int pipenum,char *readbuffer,int len,int waittime);
int __stdcall USBIntWriteData(unsigned int nBoardID,int pipenum,char *sendbuffer,int len,int waittime);
int __stdcall USBIntReadData(unsigned int nBoardID,int pipenum,char *readbuffer,int len,int waittime);
int __stdcall USBCtrlData(unsigned int nBoardID,int requesttype,int request,int value, int index, char *bytes, int size,int waittime);

int __stdcall print_device(int level);


#endif