/*
 * mpu6050.c
 *
 *  Created on: Jan 14, 2015
 *      Author: lab
 */
#include "mpu6050.h" 
#include "myiic_g.h"
#include "myiic_m.h"
#include "hal_iic.h"
#include "MKL25Z4.h"
#include "function.h"
#include <math.h>
#include <stdio.h> 
#include "delay.h"
#include "PE_Types.h"

#define I2C_ADDR_MPU6050 (0x68<<1)
#define I2C0_B I2C0_BASE_PTR

/*
    This delay is very important, it may cause w-r operation failure.
    The delay time is dependent on the current baudrate.
    It must be equal or longer than at least on clock of current baudrate.
    So, if you set to a higher baudrate, the loop value can be reduced from 4000 to 20, depending on your current baudrate.
*/
static void pause(void)
{
    int n;
    //源程序中是n<4000
    for(n=0; n<2000; n++)
        asm("nop");
}

uint8 hal_dev_mpu6050_read_reg(uint8 addr)
{
	uint8 result;

    i2c_start(I2C0_B);

    i2c_write_byte(I2C0_B, I2C_ADDR_MPU6050 | I2C_WRITE);
    i2c_wait(I2C0_B);
    i2c_get_ack(I2C0_B);

    i2c_write_byte(I2C0_B, addr);
    i2c_wait(I2C0_B);
    i2c_get_ack(I2C0_B);

    i2c_repeated_start(I2C0_B);
    i2c_write_byte(I2C0_B, I2C_ADDR_MPU6050 | I2C_READ);
    i2c_wait(I2C0_B);
    i2c_get_ack(I2C0_B);

    i2c_set_rx_mode(I2C0_B);

    i2c_give_nack(I2C0_B);
    result = i2c_read_byte(I2C0_B);
    i2c_wait(I2C0_B);

    i2c_stop(I2C0_B);
    result = i2c_read_byte(I2C0_B);
    pause();
    return result;
}
void hal_dev_mpu6050_write_reg(uint8 addr, uint8 data)
{
    i2c_start(I2C0_B);

    i2c_write_byte(I2C0_B, I2C_ADDR_MPU6050|I2C_WRITE);
    i2c_wait(I2C0_B);
    i2c_get_ack(I2C0_B);

    i2c_write_byte(I2C0_B, addr);
    i2c_wait(I2C0_B);
    i2c_get_ack(I2C0_B);

    i2c_write_byte(I2C0_B, data);
    i2c_wait(I2C0_B);
    i2c_get_ack(I2C0_B);

    i2c_stop(I2C0_B);
    pause();
}


void MPU6050_Init(void)
{
	uint8 d;    
	
	d=0x00;// 解除休眠
	hal_dev_mpu6050_write_reg(PWR_MGMT_1,d);

	d=0x13;//采样频率:1000hz,分频是20
	hal_dev_mpu6050_write_reg(SMPLRT_DIV,d);
	d = hal_dev_mpu6050_read_reg(SMPLRT_DIV);

	d=0x01;//滤波184HZ
	hal_dev_mpu6050_write_reg(CONFIG,d);

	d=0x18;//量程
	hal_dev_mpu6050_write_reg(GYRO_CONFIG,d);

	d=0x01;//量程
	hal_dev_mpu6050_write_reg(ACCEL_CONFIG,d);
	
	d=0x30;//中断信号配置
	hal_dev_mpu6050_write_reg(INT_CONFIGURATION,d);	

	d=0x01;//中断使能
	hal_dev_mpu6050_write_reg(INTERRUPT_ENABLE,d);

	//time_delay_us(10000);

}

void get_gyro(short *Gx,short *Gy,short *Gz)
{
	uint8  reg[6],status;
	
    reg[0]   = hal_dev_mpu6050_read_reg(GYRO_XOUT_H);
    reg[1]   = hal_dev_mpu6050_read_reg(GYRO_XOUT_L);

    reg[2]   = hal_dev_mpu6050_read_reg(GYRO_YOUT_H);
    reg[3]   = hal_dev_mpu6050_read_reg(GYRO_YOUT_L);

    reg[4]   = hal_dev_mpu6050_read_reg(GYRO_ZOUT_H);
    reg[5]   = hal_dev_mpu6050_read_reg(GYRO_ZOUT_L);
            
    *Gx = ( (short) (reg[0] << 8) + reg[1] ) ;
    *Gy = ( (short) (reg[2] << 8) + reg[3] ) ;
    *Gz = ( (short) (reg[4] << 8) + reg[5] ) ;

        	
}

void get_acc(short *Ax,short *Ay,short *Az)
{
	uint8  reg[6],status;
	
    reg[0]   = hal_dev_mpu6050_read_reg(ACCEL_XOUT_H);
    reg[1]   = hal_dev_mpu6050_read_reg(ACCEL_XOUT_L);

    reg[2]   = hal_dev_mpu6050_read_reg(ACCEL_YOUT_H);
    reg[3]   = hal_dev_mpu6050_read_reg(ACCEL_YOUT_L);

    reg[4]   = hal_dev_mpu6050_read_reg(ACCEL_ZOUT_H);
    reg[5]   = hal_dev_mpu6050_read_reg(ACCEL_ZOUT_L);
	
    *Ax = ( (short) (reg[0] << 8) + reg[1] ) ;
    *Ay = ( (short) (reg[2] << 8) + reg[3] ) ;
    *Az = ( (short) (reg[4] << 8) + reg[5] ) ;
        	
}




