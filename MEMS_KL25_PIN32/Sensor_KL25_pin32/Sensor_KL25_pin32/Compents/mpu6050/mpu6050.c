/*
 * mpu6050.c
 *
 *  Created on: Jan 14, 2015
 *      Author: lab
 */
#include "PE_Types.h"
#include "mpu6050.h"


void InitMPU6050()
{
	uint8 reg[7],d;    
	
	d=0x00;// 解除休眠
	I2C_run_G(I2C_SEND,MPU6050_I2C_ADDRESS,PWR_MGMT_1,&d,1);
	I2C_run_G(I2C_SrRECV,MPU6050_I2C_ADDRESS,PWR_MGMT_1,reg,1); 
	d=0x13;//采样频率:1000hz,分频是20
	I2C_run_G(I2C_SEND,MPU6050_I2C_ADDRESS,SMPLRT_DIV,&d,1);
	I2C_run_G(I2C_SrRECV,MPU6050_I2C_ADDRESS,SMPLRT_DIV,reg+1,1);
	d=0x02;//94HZ滤波，延迟3.0ms
	I2C_run_G(I2C_SEND,MPU6050_I2C_ADDRESS,CONFIG,&d,1);
	I2C_run_G(I2C_SrRECV,MPU6050_I2C_ADDRESS,CONFIG,reg+2,1);
	d=0x18;//量程
	I2C_run_G(I2C_SEND,MPU6050_I2C_ADDRESS,GYRO_CONFIG,&d,1);
	I2C_run_G(I2C_SrRECV,MPU6050_I2C_ADDRESS,GYRO_CONFIG,reg+3,1);
	d=0x01;//量程
	I2C_run_G(I2C_SEND,MPU6050_I2C_ADDRESS,ACCEL_CONFIG,&d,1);
	I2C_run_G(I2C_SrRECV,MPU6050_I2C_ADDRESS,ACCEL_CONFIG,reg+4,1);
	
	
	
	d=0x30;//中断信号配置
	I2C_run_G(I2C_SEND,MPU6050_I2C_ADDRESS,INT_CONFIGURATION,&d,1);
	I2C_run_G(I2C_SrRECV,MPU6050_I2C_ADDRESS,INT_CONFIGURATION,reg+5,1);	

	d=0x01;//中断使能
    I2C_run_G(I2C_SEND,MPU6050_I2C_ADDRESS,INTERRUPT_ENABLE,&d,1);
    I2C_run_G(I2C_SrRECV,MPU6050_I2C_ADDRESS,INTERRUPT_ENABLE,reg+6,1);
	time_delay_us(10000);
	
	
}


//读取MPU6050内部寄存器数据
uint8 Read_MPU6050(uint8 REG_Address)
{   
	uint8 REG_data;
    IIC_Start_G();                          //起始信号
    IIC_Send_Byte_G(MPU6050_I2C_ADDRESS);           //发送设备地址+写信号
	IIC_Wait_Ack_G();

    IIC_Send_Byte_G(REG_Address);                   //发送存储单元地址，从0开始	
	IIC_Wait_Ack_G();

    IIC_Start_G();                          //起始信号
    IIC_Send_Byte_G(MPU6050_I2C_ADDRESS+1);         //发送设备地址+读信号
	IIC_Wait_Ack_G();

    REG_data=IIC_Read_Byte_G();              //读出寄存器数据
	IIC_NAck_G();
    IIC_Stop_G();                           //停止信号
    return REG_data; 
}

//获取mpu6050的加速度传感器值
void get_acc(short *Ax,short *Ay,short *Az)
{
	uint8  d[6];
	
	d[0]=Read_MPU6050(ACCEL_XOUT_H);
	d[1]=Read_MPU6050(ACCEL_XOUT_L);
	d[2]=Read_MPU6050(ACCEL_YOUT_H);
	d[3]=Read_MPU6050(ACCEL_YOUT_L);
	d[4]=Read_MPU6050(ACCEL_ZOUT_H);
	d[5]=Read_MPU6050(ACCEL_ZOUT_L);
	
	*Ax = ( (short) (d[0] << 8) + d[1] );
	*Ay = ( (short) (d[2] << 8) + d[3] );
	*Az = ( (short) (d[4] << 8) + d[5] );
}


void get_gyro(short *Gx,short *Gy,short *Gz)
{
	uint8  d[6];
	d[0]=Read_MPU6050(GYRO_XOUT_H);
	d[1]=Read_MPU6050(GYRO_XOUT_L);
	d[2]=Read_MPU6050(GYRO_YOUT_H);
	d[3]=Read_MPU6050(GYRO_YOUT_L);
	d[4]=Read_MPU6050(GYRO_ZOUT_H);
	d[5]=Read_MPU6050(GYRO_ZOUT_L);
	
	*Gx = ( (short) (d[0] << 8) + d[1] ) ;
	*Gy = ( (short) (d[2] << 8) + d[3] ) ;
	*Gz = ( (short) (d[4] << 8) + d[5] ) ;
}






