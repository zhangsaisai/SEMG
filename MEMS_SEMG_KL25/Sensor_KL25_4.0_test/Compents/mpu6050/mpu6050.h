/*
 * mpu6050.h
 *
 *  Created on: Jan 14, 2015
 *      Author: lab
 */

#ifndef MPU6050_H_
#define MPU6050_H_

#include "PE_Types.h"
/****************************************/
// 定义MPU6050内部地址
//****************************************/
#define        SMPLRT_DIV          0x19        //采样率，典型0x07（125HZ）
#define        CONFIG              0x1A        //低通滤波频率
#define        GYRO_CONFIG         0x1B        //陀螺仪测量范围
#define        ACCEL_CONFIG        0x1C        //加速度计测量范围

#define        INT_CONFIGURATION   0x37        //中断信号配置
#define        INTERRUPT_ENABLE    0x38        //中断使能


#define        ACCEL_XOUT_H        0x3B
#define        ACCEL_XOUT_L        0x3C
#define        ACCEL_YOUT_H        0x3D
#define        ACCEL_YOUT_L        0x3E
#define        ACCEL_ZOUT_H        0x3F
#define        ACCEL_ZOUT_L        0x40
#define        TEMP_OUT_H          0x41
#define        TEMP_OUT_L          0x42
#define        GYRO_XOUT_H         0x43
#define        GYRO_XOUT_L         0x44        
#define        GYRO_YOUT_H         0x45
#define        GYRO_YOUT_L         0x46
#define        GYRO_ZOUT_H         0x47
#define        GYRO_ZOUT_L         0x48
#define        PWR_MGMT_1          0x6B        //电源管理，典型�?�?x00(正常启用)
#define        WHO_AM_I            0x75        //IIC地址寄存�?默认数�?0x68，只�?

static void pause(void);
uint8 hal_dev_mpu6050_read_reg(uint8 addr);
void hal_dev_mpu6050_write_reg(uint8 addr, uint8 data);
void hal_dev_mpu6050_readn(uint8 addr,uint8 data[],uint8 N);
void get_acc(short *Ax,short *Ay,short *Az);
void get_gyro(short *Gx,short *Gy,short *Gz);
void MPU6050_Init(void);

#endif /* MPU6050_H_ */
