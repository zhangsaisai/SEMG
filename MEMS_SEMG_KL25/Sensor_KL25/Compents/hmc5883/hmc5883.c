/*
 * hmc5883.c
 *
 *  Created on: Jan 14, 2015
 *      Author: lab
 */

#include "hmc5883.h" 
#include "myiic_m.h"
#include "function.h"
#include <math.h>
#include <stdio.h> 
#include "delay.h"
#include "PE_Types.h"


//////////////////////////////////////////////////////////////////////////////////	 
//初始化HMC5883L接口
//0x3c是磁传感器的从机地址，写操作；0x3D读操作
void HMC5883_Init(void)
{
uint8 d;
uint8 reg[9];    

d=0x14;//30HZ,continuous measurement 
I2C_run_M(I2C_SEND,HMC5883_I2C_ADDRESS,SMPLRT_FRE,&d,1);
I2C_run_M(I2C_SrRECV,HMC5883_I2C_ADDRESS,SMPLRT_FRE,reg,1); 
d=0xC0;//±5.6Gauss
I2C_run_M(I2C_SEND,HMC5883_I2C_ADDRESS,MAG_CONFIG,&d,1);
I2C_run_M(I2C_SrRECV,HMC5883_I2C_ADDRESS,MAG_CONFIG,reg+1,1);
d=0x00;//连续转换模式
I2C_run_M(I2C_SEND,HMC5883_I2C_ADDRESS,CONVERT_CONFIG,&d,1);
I2C_run_M(I2C_SrRECV,HMC5883_I2C_ADDRESS,CONVERT_CONFIG,reg+2,1);
//读取判别寄存器，判别A——0X48，判别B——0X34，判别C——0X33
reg[4] = Read_HMC5883(IDEN_REG1);
reg[6] = Read_HMC5883(IDEN_REG2);
reg[8] = Read_HMC5883(IDEN_REG3);
time_delay_us(10000);
}

//读取HMC5883L内部寄存器数据
uint8 Read_HMC5883(uint8 REG_Address)
{   
	uint8 REG_data;
    IIC_Start_M();                          //起始信号
    IIC_Send_Byte_M(HMC5883_I2C_ADDRESS);           //发送设备地址+写信号
	IIC_Wait_Ack_M();

    IIC_Send_Byte_M(REG_Address);                   //发送存储单元地址，从0开始	
	IIC_Wait_Ack_M();

    IIC_Start_M();                          //起始信号
    IIC_Send_Byte_M(HMC5883_I2C_ADDRESS+1);         //发送设备地址+读信号
	IIC_Wait_Ack_M();

    REG_data=IIC_Read_Byte_M();              //读出寄存器数据
	IIC_NAck_M();
    IIC_Stop_M();                           //停止信号
    return REG_data; 
}
//******************************************************
//连续读出HMC5883内部角度数据，地址范围0x3~0x5
//******************************************************
void Multiple_read_HMC5883(uint8 *BUF)
{   uint8 i;
    IIC_Start_M();                          //起始信号
    IIC_Send_Byte_M(HMC5883_I2C_ADDRESS);           //发送设备地址+写信号
	IIC_Wait_Ack_M();
    IIC_Send_Byte_M(0x03);                   //发送存储单元地址，从0x3开始	
	IIC_Wait_Ack_M();
    IIC_Start_M();                          //起始信号
    IIC_Send_Byte_M(HMC5883_I2C_ADDRESS+1);         //发送设备地址+读信号
	IIC_Wait_Ack_M();
	 for (i=0; i<6; i++)                      //连续读取6个地址数据，存储中BUF
    {
        
        if (i == 5)
        {
           BUF[i] = IIC_Read_Byte_M();          //最后一个数据需要回NOACK
           IIC_NAck_M();
        }
        else
        {
          BUF[i] = IIC_Read_Byte_M();          //返回ACK
          IIC_Ack_M();
       }
   }
    IIC_Stop_M();                          //停止信号
}

/*----------------------------------------------
获取磁传感器的原始数据  
----------------------------------------------*/
void get_mag(short *Mx,short *My,short *Mz)
{
	uint8  d[6];
/*
//该函数能读到的测量数据，但数据准确性有待验证
I2C_run(I2C_SrRECV,0x3C,0x03,d,1);
delay_ms(5);
I2C_run(I2C_SrRECV,0x3C,0x04,d+1,1);
delay_ms(5);
I2C_run(I2C_SrRECV,0x3C,0x05,d+2,1);
delay_ms(5);
I2C_run(I2C_SrRECV,0x3C,0x06,d+3,1);
delay_ms(5);
I2C_run(I2C_SrRECV,0x3C,0x07,d+4,1);
delay_ms(5);
I2C_run(I2C_SrRECV,0x3C,0x08,d+5,1);
delay_ms(5);
*/
	uint8 mode;

	//when the data overflow,acquire again
	//the value of data register is from 0xF800 to 0x07FF
	//while( (*Mx>2047)||(*Mx<-2047)||(*My>2047)||(*My<-2047)||(*Mz>2047)||(*Mz<-2047) )
	{
		d[0] = Read_HMC5883(0x03);
		d[1] = Read_HMC5883(0x04);
		d[4] = Read_HMC5883(0x05);
		d[5] = Read_HMC5883(0x06);
		d[2] = Read_HMC5883(0x07);
		d[3] = Read_HMC5883(0x08);
		*Mx = ( (short) (d[0] << 8) + d[1] ) ;
		*My = ( (short) (d[2] << 8) + d[3] ) ;
		*Mz = ( (short) (d[4] << 8) + d[5] ) ;
	}
	//after read the data register,mode turn to idle mode,so need wake up the sensor by mode register
	//in order to achieve 100HZ of mag sensor,we can put the "mode=0x01" in MPU6050 interrupt.
	//mode=0x01;//单次转换模式
	//I2C_run_M(I2C_SEND,HMC5883_I2C_ADDRESS,CONVERT_CONFIG,&mode,1);
}











