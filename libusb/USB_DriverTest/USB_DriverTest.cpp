// USB_DriverTest.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"

#define	EP1_OUT_SIZE	64
#define	EP1_IN_SIZE	64


int main(int argc, char *argv[])
{
  struct usb_bus *bus;
  int DevNum;
  int ret;

  /*
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
  */

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


