/*
 * myiic_g.h
 *
 *  Created on: Jan 15, 2015
 *      Author: lab
 */

#ifndef MYIIC_G_H_
#define MYIIC_G_H_

#include "PE_Types.h"
#define I2C_RECV     0    /* ����ģʽ */
#define I2C_SEND     1    /* ����ģʽ */
#define I2C_SrRECV   2    /* ��Sr���� */
//IIC���в�������
void IIC_Init_G(void);                //��ʼ��IIC��IO��				 
void IIC_Start_G(void);				//����IIC��ʼ�ź�
void IIC_Stop_G(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte_G(uint8 txd);			//IIC����һ���ֽ�
uint8 IIC_Read_Byte_G(void);//IIC��ȡһ���ֽ�
uint8 IIC_Wait_Ack_G(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack_G(void);					//IIC����ACK�ź�
void IIC_NAck_G(void);				//IIC������ACK�ź�
uint8 I2C_run_G
(
		uint8 Mode,      //����ģʽ
		uint8 SLA,       //�ӻ���ַ
		uint8 Addr,      //�ӵ�ַ
		uint8 *Buf,      //���ݻ�����
		uint8 Size       //���ݳ���
);

#endif /* MYIIC_G_H_ */
