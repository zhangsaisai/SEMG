/*
 * hmc5883.h
 *
 *  Created on: Jan 14, 2015
 *      Author: lab
 */

#ifndef HMC5883_H_
#define HMC5883_H_
#include "PE_Types.h"

#define I2C_RECV     0    /* 接收模式 */
#define I2C_SEND     1    /* 发送模式 */
#define I2C_SrRECV   2    /* 带Sr接收 */
#define HMC5883_I2C_ADDRESS 0x3c
#define PI 3.1415926535898


#define        SMPLRT_FRE        0x00        
#define        MAG_CONFIG        0x01        
#define        CONVERT_CONFIG    0x02
#define        MAG_XOUT_H        0x03
#define        MAG_XOUT_L        0x04
#define        MAG_YOUT_H        0x05
#define        MAG_YOUT_L        0x06
#define        MAG_ZOUT_H        0x07
#define        MAG_ZOUT_L        0x08
#define        IDEN_REG1         0x0A
#define        IDEN_REG2         0x0B
#define        IDEN_REG3         0x0C


void HMC5883_Init(void);
uint8 Read_HMC5883(uint8 REG_Address);
void Multiple_read_HMC5883(uint8 *BUF);
void get_mag(short *Mx,short *My,short *Mz);


#endif /* HMC5883_H_ */
