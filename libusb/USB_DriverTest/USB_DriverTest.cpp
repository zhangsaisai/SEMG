// USB_DriverTest.cpp : �������̨Ӧ�ó������ڵ㡣

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

  //ɨ���豸����������Ҫ��ʼ��
	DevNum = USBScanDev(1);
	printf("�豸������Ϊ��%d\n",DevNum);
	//���豸0
	ret = USBOpenDev(0);
	if(ret == SEVERITY_ERROR){
		printf("���豸ʧ�ܣ�\n");
		return SEVERITY_ERROR;
	}else{
		printf("���豸�ɹ���\n");
	}

	ret = print_device(0);
	
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
	//ɨ���豸����������Ҫ��ʼ��
	DevNum = USBScanDev(1);
	printf("�豸������Ϊ��%d\n",DevNum);
	//���豸0
	ret = USBOpenDev(0);
	if(ret == SEVERITY_ERROR){
		printf("���豸ʧ�ܣ�\n");
		return SEVERITY_ERROR;
	}else{
		printf("���豸�ɹ���\n");
	}

	//�˵�1д����
	ret = USBBulkWriteData(0,EP1_OUT,WriteTestData,EP1_OUT_SIZE,500);
	if(ret != EP1_OUT_SIZE){
		printf("�˵�1д����ʧ�ܣ�%d\n",ret);
		return SEVERITY_ERROR;
	}else{
		printf("�˵�1д���ݳɹ���\n");
	}
	//�˵�1������
	ret = USBBulkReadData(0,EP1_IN,ReadTestData,EP1_IN_SIZE,500);
	if(ret != EP1_IN_SIZE){
		printf("�˵�1������ʧ�ܣ�%d\n",ret);
		return SEVERITY_ERROR;
	}else{
		printf("�˵�1�����ݳɹ���\n");
		for(int i=0;i<EP1_IN_SIZE;i++){
			printf("%02X ",ReadTestData[i]);
			if(((i+1)%16)==0){
				printf("\n");
			}
		}
		printf("\n");
	}
	Sleep(100);
	//�˵�2д����
	ret = USBBulkWriteData(0,EP2_OUT,WriteTestData+64,64,500);
	if(ret != 64){
		printf("�˵�2д����ʧ�ܣ�%d\n",ret);
		return SEVERITY_ERROR;
	}else{
		printf("�˵�2д���ݳɹ���\n");
	}
	//�˵�2������
	ret = USBBulkReadData(0,EP2_IN,ReadTestData,64,500);
	if(ret != 64){
		printf("�˵�2������ʧ�ܣ�%d\n",ret);
		return SEVERITY_ERROR;
	}else{
		printf("�˵�2�����ݳɹ���\n");
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


