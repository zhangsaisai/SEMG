/*
 * hmc5883.h
 *
 *  Created on: Jan 14, 2015
 *      Author: lab
 */

#ifndef HMC5883_H_
#define HMC5883_H_
#include "PE_Types.h"

#define PI 3.1415926535898


#define        SMPLRT_FRE        0x00        
#define        MAG_CONFIG        0x01        
#define        CONVERT_CONFIG    0x02
#define        MAG_XOUT_H        0x03
#define        MAG_XOUT_L        0x04
#define        MAG_ZOUT_H        0x05
#define        MAG_ZOUT_L        0x06
#define        MAG_YOUT_H        0x07
#define        MAG_YOUT_L        0x08
#define        IDEN_REG1         0x0A
#define        IDEN_REG2         0x0B
#define        IDEN_REG3         0x0C


uint8 hal_dev_hmc5883_read_reg(uint8 addr);
void hal_dev_hmc5883_write_reg(uint8 addr, uint8 data);
void HMC5883_Init(void);
void get_mag(short *Mx,short *My,short *Mz);


#endif /* HMC5883_H_ */
