// USB_DriverTest.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"

#define	DEVICE0	         0
#define	DEVICE1	         1

#define	EP1_OUT_SIZE	128
#define	EP1_IN_SIZE	    128

//ʵ�ʶ�ȡ���͵�����
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

  unsigned char sensor_data[128];

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

	//device0��Ӧ�ӿ�0��device1��Ӧ�ӿ�1
	//receive the device0 MCU Number
	ret = USBCtrlData(DEVICE0,GET_REQUEST_MCU,GET_NUMber,0x00, EP0, rece_comm_dev0, SIZE_NUMber,100);
	//receive the device0 MCU State
	ret = USBCtrlData(DEVICE0,GET_REQUEST_MCU,Get_State,0x00, EP0, rece_comm_dev0+1, SIZE_State,100);
	//state=200,unsigned char is 11001000(0xc8)-----char:���յ���16����Ҳ��0xc8���ڽ���ת��������ȡ����00110111��ת����ʮ������55�����Ϸ�����-55���ټ�ȥ1��-56
	//�ڼ����ϵͳ�У���Ȼ���Զ����ƴ洢�ģ���˶���state=200���ԣ���Ӧ�Ķ�������0xc8����λ�����յ���Ҳ��0xc8
	//receive the device0 Frame Number
	ret = USBCtrlData(DEVICE0,GET_REQUEST_MCU,GET_Frame,0x00, EP0, rece_comm_dev0+2, SIZE_Frame,100);
	//S_FrameNumber��ʼֵ��10000.�ھ���S_FrameNumber &= 0x3ffȡ������󣬵���784
	//784���޷�����0011 0001 0000��ֱ��ת���������ֽڵ��з���������0011 ��0001 0000������0x03��0x10,0x10�����ֽڣ��ڵ��ڴ��ַ��0x03�����ֽڣ��ڸ��ڴ��ַ
	
	//receive the device1 MCU Number��MCU State��Frame Number
	ret = USBCtrlData(DEVICE1,GET_REQUEST_MCU,GET_NUMber,0x00, EP0, rece_comm_dev1, SIZE_NUMber,100);
	ret = USBCtrlData(DEVICE1,GET_REQUEST_MCU,Get_State,0x00, EP0, rece_comm_dev1+1, SIZE_State,100);
	ret = USBCtrlData(DEVICE1,GET_REQUEST_MCU,GET_Frame,0x00, EP0, rece_comm_dev1+2, SIZE_Frame,100);

	//��device1����Ӧ�ӿ�1������ͬ���˵�0��ͬ���˵�1�����н�������,102���ֽ�
	//���������ʧ��ʱ������ֵΪ-116��
    //���������ֽ�����Ϊ64�ı��������飩����������������ȷ��������-5.
    //�����������ֽ���Ϊ64�����Ҷ�����������ȷʱ������ֵΪ�ɹ���ȡ���ֽ�����
	while(1)
	{
		ret = USBBulkReadData(DEVICE1,EP1_IN,rece_data_dev1,EP1_IN_SIZE,500);//EP1_IN_SIZE����Ϊ64�ı�����128
		if(ret != DATA_IN_SIZE){
			printf("�˵�1������ʧ�ܣ�%d\n",ret);
			return SEVERITY_ERROR;
		}else{
			printf("�˵�1�����ݳɹ���\n");
			for(int i=0;i<DATA_IN_SIZE;i++){
				sensor_data[i] = (unsigned char)rece_data_dev1[i];
				printf("%d, 0x%02x  ", i,  sensor_data[i]);
				if(((i+1)%5)==0){
					printf("\n\r");
				}
			}
			printf("\n");
		}
		Sleep(1);
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


