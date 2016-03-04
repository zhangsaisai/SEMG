/*
 * myiic_m.h
 *
 *  Created on: Jan 15, 2015
 *      Author: lab
 */

#ifndef MYIIC_M_H_
#define MYIIC_M_H_

#include "PE_Types.h"
#define I2C_RECV     0    /* 接收模式 */
#define I2C_SEND     1    /* 发送模式 */
#define I2C_SrRECV   2    /* 带Sr接收 */
//IIC所有操作函数
void IIC_Init_M(void);                //初始化IIC的IO口				 
void IIC_Start_M(void);				//发送IIC开始信号
void IIC_Stop_M(void);	  			//发送IIC停止信号
void IIC_Send_Byte_M(uint8 txd);			//IIC发送一个字节
uint8 IIC_Read_Byte_M(void);//IIC读取一个字节
uint8 IIC_Wait_Ack_M(void); 				//IIC等待ACK信号
void IIC_Ack_M(void);					//IIC发送ACK信号
void IIC_NAck_M(void);				//IIC不发送ACK信号
uint8 I2C_run_M
(
		uint8 Mode,      //操作模式
		uint8 SLA,       //从机地址
		uint8 Addr,      //子地址
		uint8 *Buf,      //数据缓冲区
		uint8 Size       //数据长度
);

#endif /* MYIIC_M_H_ */
