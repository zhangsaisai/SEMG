// USB_DriverTest.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <fstream>
#include <iomanip>
using namespace std;

#define	DEVICE0	         0
#define	DEVICE1	         1

#define	EP1_OUT_SIZE	128
#define	EP1_IN_SIZE	    128

//实际读取或发送的数据
#define	DATA_OUT_SIZE	102
#define	DATA_IN_SIZE	102

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
  char rece_comm_dev0[5];
  char rece_comm_dev1[5];
  char send_comm_dev0[5];
  char send_comm_dev1[5];

  char rece_data_dev0[128];
  char rece_data_dev1[128];
  char send_data_dev0[128];
  char send_data_dev1[128];

  unsigned char sensor_data[128];//pringf to the command line
  int  data[128];//printf to the txt

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

	//device0对应接口0，device1对应接口1
	//receive the device0 MCU Number
	ret = USBCtrlData(DEVICE0,GET_REQUEST_MCU,GET_NUMber,0x00, EP0, rece_comm_dev0, SIZE_NUMber,100);
	//receive the device0 MCU State
	ret = USBCtrlData(DEVICE0,GET_REQUEST_MCU,Get_State,0x00, EP0, rece_comm_dev0+1, SIZE_State,100);
	//state=200,unsigned char is 11001000(0xc8)-----char:接收到的16进制也是0xc8，在将其转换成首先取反：00110111，转化成十进制是55，加上符号是-55，再减去1是-56
	//在计算机系统中，仍然是以二进制存储的，因此对于state=200而言，对应的二进制是0xc8，上位机接收到的也是0xc8
	//receive the device0 Frame Number
	ret = USBCtrlData(DEVICE0,GET_REQUEST_MCU,GET_Frame,0x00, EP0, rece_comm_dev0+2, SIZE_Frame,100);
	//S_FrameNumber初始值是10000.在经过S_FrameNumber &= 0x3ff取余操作后，等于784
	//784是无符号数0011 0001 0000，直接转换成两个字节的有符号数，是0011 和0001 0000，即是0x03和0x10,0x10（低字节）在低内存地址，0x03（高字节）在高内存地址
	
	//receive the device1 MCU Number、MCU State、Frame Number
	ret = USBCtrlData(DEVICE1,GET_REQUEST_MCU,GET_NUMber,0x00, EP0, rece_comm_dev1, SIZE_NUMber,100);
	ret = USBCtrlData(DEVICE1,GET_REQUEST_MCU,Get_State,0x00, EP0, rece_comm_dev1+1, SIZE_State,100);
	ret = USBCtrlData(DEVICE1,GET_REQUEST_MCU,GET_Frame,0x00, EP0, rece_comm_dev1+2, SIZE_Frame,100);

	//对device1（对应接口1，包括同步端点0和同步端点1）进行接收数据,102个字节
	//当你读数据失败时，返回值为-116；
    //当读数据字节数不为64的倍数（整块），读出来的数据正确，但返回-5.
    //当读出来的字节数为64倍数且读出来数据正确时，返回值为成功读取的字节数。
	
	//若文件已经存在时，清空文件的内容
	ofstream ocout_data("sensordata.txt", ios::out|ios::trunc);

	while(1)
	{
		//创建txt文件，打开方式为：打开文件之后文件指针指向文件末尾，只能在文件末尾进行数据的写入
		ofstream ocout_data("sensordata.txt", ios::out|ios::app);

		ret = USBBulkReadData(DEVICE1,EP1_IN,rece_data_dev1,EP1_IN_SIZE,500);//EP1_IN_SIZE设置为64的倍数，128
		if(ret != DATA_IN_SIZE){
			printf("端点1读数据失败！%d\n",ret);
			return SEVERITY_ERROR;
		}else{
			printf("端点1读数据成功！\n");
			for(int i=0;i<DATA_IN_SIZE;i++){
				sensor_data[i] = (unsigned char)rece_data_dev1[i];
				data[i] = (int)sensor_data[i];
				printf("%d, 0x%02x  ", i,  sensor_data[i]);
				ocout_data << dec << i <<" "<< "hex:0x" << hex << data[i]  <<" "<<"\n";
				if(((i+1)%5)==0)
					printf("\n\r");
			}
		}
		Sleep(1);
		ocout_data.close();
	}
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


