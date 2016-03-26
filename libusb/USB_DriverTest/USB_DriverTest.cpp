// USB_DriverTest.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"

#define	EP1_OUT_SIZE	64
#define	EP1_IN_SIZE	64

/* Code of bmRequest Type */
#define GET_REQUEST_MCU            (0xC0)//Get the MCU USB Message
#define SET_REQUEST_MCU            (0x40)//Set the MCU USB Message

/* Mems Class Specific Request Codes */
#define Get_State                            (0x66)
#define GET_Frame                            (0x65)
#define SET_Frame                            (0x64)
#define SET_Sample                           (0x63)
#define GET_NUMber                           (0x62)


#define SIZE_NUMber                          (0x01)
#define SIZE_State                           (0x01)
#define SIZE_Frame                           (0x02)
int main(int argc, char *argv[])
{
  struct usb_bus *bus;
  int DevNum;
  int ret;
  char bytes[10];
  //扫描设备连接数，需要初始化
	DevNum = USBScanDev(1);
	printf("设备连接数为：%d\n",DevNum);

	//打开设备0
	ret = USBOpenDev(0);
	if(ret == SEVERITY_ERROR){
		printf("打开设备0失败！\n");
		return SEVERITY_ERROR;
	}else{
		printf("打开设备0成功！\n");
	}
	//打印设备0的描述符
	ret = print_device(0);
	
	//打开设备1
	ret = USBOpenDev(1);
	if(ret == SEVERITY_ERROR){
		printf("打开设备1失败！\n");
		return SEVERITY_ERROR;
	}else{
		printf("打开设备1成功！\n");
	}
	//打印设备1的描述符
	ret = print_device(1);

	//receive the MCU Number
	ret = USBCtrlData(0,GET_REQUEST_MCU,GET_NUMber,0x00, EP0, bytes, SIZE_NUMber,100);

	//receive the MCU State
	ret = USBCtrlData(0,GET_REQUEST_MCU,Get_State,0x00, EP0, bytes+1, SIZE_State,100);
	//state=200,unsigned char is 11001000-----char:首先取反：00110111，转化成十进制是55，加上符号是-55，再减去1是-56

	//receive the Frame Number
	ret = USBCtrlData(0,GET_REQUEST_MCU,GET_Frame,0x00, EP0, bytes+2, SIZE_Frame,100);
	//S_FrameNumber初始值是10000.在经过S_FrameNumber &= 0x3ff取余操作后，等于784
	//784是无符号数0011 0001 0000，直接转换成两个字节的有符号数，是0011 和0001 0000，即是0x10和0x03
	
	//在计算机系统中，仍然是以二进制存储的，因此对于state=200而言，对应的二进制是0xc8，上位机接收到的也是0xc8

	return 0;
}




/*
int _tmain(int argc, _TCHAR* argv[])
{
	int DevNum;
	int ret;
	char WriteTestData[256]={1,2,3,4,5,6,7,8,9};
	char ReadTestData[256]={0};
	for(int i=0;i<256;i++){
		WriteTestData[i] = i;
	}
	//扫描设备连接数，需要初始化
	DevNum = USBScanDev(1);
	printf("设备连接数为：%d\n",DevNum);
	//打开设备0
	ret = USBOpenDev(0);
	if(ret == SEVERITY_ERROR){
		printf("打开设备失败！\n");
		return SEVERITY_ERROR;
	}else{
		printf("打开设备成功！\n");
	}

	//端点1写数据
	ret = USBBulkWriteData(0,EP1_OUT,WriteTestData,EP1_OUT_SIZE,500);
	if(ret != EP1_OUT_SIZE){
		printf("端点1写数据失败！%d\n",ret);
		return SEVERITY_ERROR;
	}else{
		printf("端点1写数据成功！\n");
	}
	//端点1读数据
	ret = USBBulkReadData(0,EP1_IN,ReadTestData,EP1_IN_SIZE,500);
	if(ret != EP1_IN_SIZE){
		printf("端点1读数据失败！%d\n",ret);
		return SEVERITY_ERROR;
	}else{
		printf("端点1读数据成功！\n");
		for(int i=0;i<EP1_IN_SIZE;i++){
			printf("%02X ",ReadTestData[i]);
			if(((i+1)%16)==0){
				printf("\n");
			}
		}
		printf("\n");
	}
	Sleep(100);
	//端点2写数据
	ret = USBBulkWriteData(0,EP2_OUT,WriteTestData+64,64,500);
	if(ret != 64){
		printf("端点2写数据失败！%d\n",ret);
		return SEVERITY_ERROR;
	}else{
		printf("端点2写数据成功！\n");
	}
	//端点2读数据
	ret = USBBulkReadData(0,EP2_IN,ReadTestData,64,500);
	if(ret != 64){
		printf("端点2读数据失败！%d\n",ret);
		return SEVERITY_ERROR;
	}else{
		printf("端点2读数据成功！\n");
		for(int i=0;i<64;i++){
			printf("%02X ",ReadTestData[i]);
			if(((i+1)%16)==0){
				printf("\n");
			}
		}
		printf("\n");
	}
	getchar();
	return 0;
}
*/


