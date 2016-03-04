/*
 * hal_iic.h
 *
 *  Created on: Dec 24, 2015
 *      Author: lab
 */

#ifndef HAL_IIC_H_
#define HAL_IIC_H_

#include "MKL25Z4.h"
#include "PE_Types.h"

void i2c_set_tx_mode(I2C_MemMapPtr p);
void i2c_set_rx_mode(I2C_MemMapPtr p);
void i2c_set_slave_mode(I2C_MemMapPtr p);
void i2c_set_master_mode(I2C_MemMapPtr p);
void i2c_give_nack(I2C_MemMapPtr p);
void i2c_give_ack(I2C_MemMapPtr p);
void i2c_repeated_start(I2C_MemMapPtr p);
void i2c_write_byte(I2C_MemMapPtr p, byte data);
byte i2c_read_byte(I2C_MemMapPtr p);
void i2c_start(I2C_MemMapPtr p);
void i2c_stop(I2C_MemMapPtr p);
void i2c_wait(I2C_MemMapPtr p);
bool i2c_get_ack(I2C_MemMapPtr p);


#endif /* HAL_IIC_H_ */
