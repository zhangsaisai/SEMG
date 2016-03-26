// USB_DriverTest.cpp : �������̨Ӧ�ó������ڵ㡣

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
  //ɨ���豸����������Ҫ��ʼ��
	DevNum = USBScanDev(1);
	printf("�豸������Ϊ��%d\n",DevNum);

	//���豸0
	ret = USBOpenDev(0);
	if(ret == SEVERITY_ERROR){
		printf("���豸0ʧ�ܣ�\n");
		return SEVERITY_ERROR;
	}else{
		printf("���豸0�ɹ���\n");
	}
	//��ӡ�豸0��������
	ret = print_device(0);
	
	//���豸1
	ret = USBOpenDev(1);
	if(ret == SEVERITY_ERROR){
		printf("���豸1ʧ�ܣ�\n");
		return SEVERITY_ERROR;
	}else{
		printf("���豸1�ɹ���\n");
	}
	//��ӡ�豸1��������
	ret = print_device(1);

	//receive the MCU Number
	ret = USBCtrlData(0,GET_REQUEST_MCU,GET_NUMber,0x00, EP0, bytes, SIZE_NUMber,100);

	//receive the MCU State
	ret = USBCtrlData(0,GET_REQUEST_MCU,Get_State,0x00, EP0, bytes+1, SIZE_State,100);
	//state=200,unsigned char is 11001000-----char:����ȡ����00110111��ת����ʮ������55�����Ϸ�����-55���ټ�ȥ1��-56

	//receive the Frame Number
	ret = USBCtrlData(0,GET_REQUEST_MCU,GET_Frame,0x00, EP0, bytes+2, SIZE_Frame,100);
	//S_FrameNumber��ʼֵ��10000.�ھ���S_FrameNumber &= 0x3ffȡ������󣬵���784
	//784���޷�����0011 0001 0000��ֱ��ת���������ֽڵ��з���������0011 ��0001 0000������0x10��0x03
	
	//�ڼ����ϵͳ�У���Ȼ���Զ����ƴ洢�ģ���˶���state=200���ԣ���Ӧ�Ķ�������0xc8����λ�����յ���Ҳ��0xc8

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


