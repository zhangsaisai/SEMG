/*
 * hmc5883.c
 *
 *  Created on: Jan 14, 2015
 *      Author: lab
 */

#include "hmc5883.h" 
#include "myiic_m.h"
#include "hal_iic.h"
#include "MKL25Z4.h"
#include "function.h"
#include <math.h>
#include <stdio.h> 
#include "delay.h"
#include "PE_Types.h"

#define I2C_ADDR_HMC5883 (0x1e<<1)
#define I2C1_B I2C1_BASE_PTR

/*
    This delay is very important, it may cause w-r operation failure.
    The delay time is dependent on the current baudrate.
    It must be equal or longer than at least on clock of current baudrate.
    So, if you set to a higher baudrate, the loop value can be reduced from 4000 to 20, depending on your current baudrate.
*/
static void pause(void)
{
    int n;
    //for(n=0; n<4000; n++)//源程序中循环次数为4000
    //如果磁传感器循环次数设置为3000，采集程序正常，full.如果设置为2000，可能会出现empty的状态，即是磁传感器的采集进入IIC死循环
    for(n=0; n<3000; n++)
        asm("nop");
}

uint8 hal_dev_hmc5883_read_reg(uint8 addr)
{
	uint8 result;

    i2c_start(I2C1_B);

    i2c_write_byte(I2C1_B, I2C_ADDR_HMC5883 | I2C_WRITE);
    i2c_wait(I2C1_B);
    i2c_get_ack(I2C1_B);

    i2c_write_byte(I2C1_B, addr);
    i2c_wait(I2C1_B);
    i2c_get_ack(I2C1_B);

    i2c_repeated_start(I2C1_B);
    i2c_write_byte(I2C1_B, I2C_ADDR_HMC5883 | I2C_READ);
    i2c_wait(I2C1_B);
    i2c_get_ack(I2C1_B);

    i2c_set_rx_mode(I2C1_B);

    i2c_give_nack(I2C1_B);
    result = i2c_read_byte(I2C1_B);
    i2c_wait(I2C1_B);

    i2c_stop(I2C1_B);
    result = i2c_read_byte(I2C1_B);
    pause();
    return result;
}
void hal_dev_hmc5883_write_reg(uint8 addr, uint8 data)
{
    i2c_start(I2C1_B);

    i2c_write_byte(I2C1_B, I2C_ADDR_HMC5883|I2C_WRITE);
    i2c_wait(I2C1_B);
    i2c_get_ack(I2C1_B);

    i2c_write_byte(I2C1_B, addr);
    i2c_wait(I2C1_B);
    i2c_get_ack(I2C1_B);

    i2c_write_byte(I2C1_B, data);
    i2c_wait(I2C1_B);
    i2c_get_ack(I2C1_B);

    i2c_stop(I2C1_B);
    pause();
}


void HMC5883_Init(void)
{
	uint8 d;
    
    hal_dev_hmc5883_write_reg(0x00,0x18);//SMPLRT_FRE
    d = hal_dev_hmc5883_read_reg(0x00);
    
    hal_dev_hmc5883_write_reg(0x01,0x00);//MAG_CONFIG
    d = hal_dev_hmc5883_read_reg(0x01);

    hal_dev_hmc5883_write_reg(0x02,0x00);//CONVERT_CONFIG
    d = hal_dev_hmc5883_read_reg(0x02);
    
    d = hal_dev_hmc5883_read_reg(0x0A);//IDEN_REG1
    d = hal_dev_hmc5883_read_reg(0x0B);//IDEN_REG2
    d = hal_dev_hmc5883_read_reg(0x0C);//IDEN_REG3

}

void get_mag(short *Mx,short *My,short *Mz)
{
	uint8  reg[6],status;
	

    reg[0]   = hal_dev_hmc5883_read_reg(0x03);//MAG_XOUT_H
    reg[1]   = hal_dev_hmc5883_read_reg(0x04);//MAG_XOUT_L

    reg[2]   = hal_dev_hmc5883_read_reg(0x07);//MAG_YOUT_H
    reg[3]   = hal_dev_hmc5883_read_reg(0x08);//MAG_YOUT_L

    reg[4]   = hal_dev_hmc5883_read_reg(0x05);//MAG_ZOUT_H
    reg[5]   = hal_dev_hmc5883_read_reg(0x06);//MAG_ZOUT_L
            
    *Mx = ( (short) (reg[0] << 8) + reg[1] ) ;
    *My = ( (short) (reg[2] << 8) + reg[3] ) ;
    *Mz = ( (short) (reg[4] << 8) + reg[5] ) ;
        	

}













