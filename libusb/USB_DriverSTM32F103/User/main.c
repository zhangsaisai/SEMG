/**
  ******************************************************************************
  * @file    main.c
  * $Author: wdluo $
  * $Revision: 67 $
  * $Date:: 2012-08-15 19:00:29 +0800 #$
  * @brief   ������.
  ******************************************************************************
  * @attention
  *
  *<h3><center>&copy; Copyright 2009-2012, EmbedNet</center>
  *<center><a href="http://www.embed-net.com">http://www.embed-net.com</a></center>
  *<center>All Rights Reserved</center></h3>
  * 
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "usb_lib.h"
#include "hw_config.h"
#include "usbio.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern volatile uint32_t EP1_ReceivedCount;
extern volatile uint32_t EP2_ReceivedCount;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  ���ڴ�ӡ���
  * @param  None
  * @retval None
  */
int main(void)
{
	uint8_t data[256];
	uint32_t i=0;
	Set_System();//ϵͳʱ�ӳ�ʼ��
	USART_Configuration();//����1��ʼ��
	printf("\x0c\0");printf("\x0c\0");//�����ն�����
	printf("\033[1;40;32m");//���ó����ն˱���Ϊ��ɫ���ַ�Ϊ��ɫ
	printf("\r\n*******************************************************************************");
	printf("\r\n************************ Copyright 2009-2012, EmbedNet ************************");
	printf("\r\n*************************** http://www.embed-net.com **************************");
	printf("\r\n***************************** All Rights Reserved *****************************");
	printf("\r\n*******************************************************************************");
	printf("\r\n");

	USB_Interrupts_Config();
	Set_USBClock();
	USB_Init();

	while(1)
	{
		if(EP1_ReceivedCount > 0){
			USB_GetData(ENDP1,data,EP1_ReceivedCount);
			USB_SendData(ENDP1,data,EP1_ReceivedCount);
			printf("usb EP1 get data %d byte data\n\r",EP1_ReceivedCount);
			for(i=0;i<EP1_ReceivedCount;i++){
				printf("0x%02X ",data[i]);
			}
			printf("\n\r");
			EP1_ReceivedCount=0;
		}
		if(EP2_ReceivedCount > 0){
			USB_GetData(ENDP2,data,EP2_ReceivedCount);
			USB_SendData(ENDP2,data,EP2_ReceivedCount);
			printf("usb EP2 get data %d byte data\n\r",EP2_ReceivedCount);
			for(i=0;i<EP2_ReceivedCount;i++){
				printf("0x%02X ",data[i]);
			}
			printf("\n\r");
			EP2_ReceivedCount=0;	
		}
	}
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  �����ڼ�������������ʱ��Դ�ļ����ʹ�������
  * @param  file Դ�ļ���
  * @param  line ������������ 
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
    /* �û����������Լ��Ĵ������ڱ��������ļ�������������,
       ���磺printf("�������ֵ: �ļ��� %s �� %d��\r\n", file, line) */

    /* ����ѭ�� */
    while (1)
    {
    }
}
#endif

/*********************************END OF FILE**********************************/
