/*
 * hal_iic.c
 *
 *  Created on: Dec 24, 2015
 *      Author: lab
 */
#include "hal_iic.h"
#include "MKL25Z4.h"
#include "PE_Types.h"


void i2c_set_tx_mode(I2C_MemMapPtr p)
{
    p->C1 |= I2C_C1_TX_MASK;

}
void i2c_set_rx_mode(I2C_MemMapPtr p)
{
    p->C1 &= ~I2C_C1_TX_MASK;
}

void i2c_set_slave_mode(I2C_MemMapPtr p)
{
    p->C1  &= ~I2C_C1_MST_MASK;
}
void i2c_set_master_mode(I2C_MemMapPtr p)
{
    p->C1  |=  I2C_C1_MST_MASK;
}

// i2c general

void i2c_give_nack(I2C_MemMapPtr p)
{
    p->C1 |= I2C_C1_TXAK_MASK;
}
void i2c_give_ack(I2C_MemMapPtr p)
{
    p->C1 &= ~I2C_C1_TXAK_MASK;
}
void i2c_repeated_start(I2C_MemMapPtr p)
{
    p->C1     |= 0x04;
}
void i2c_write_byte(I2C_MemMapPtr p, byte data)
{
    p->D = data;
}
byte i2c_read_byte(I2C_MemMapPtr p)
{
    return p->D;
}
void i2c_start(I2C_MemMapPtr p)
{
    i2c_set_master_mode(p);
    i2c_set_tx_mode(p);
}
void i2c_stop(I2C_MemMapPtr p)
{
    i2c_set_slave_mode(p);
    i2c_set_rx_mode(p);
}
void i2c_wait(I2C_MemMapPtr p)
{
    // wait flag
    while((p->S & I2C_S_IICIF_MASK)==0)
        ;
    // clear flag
    p->S |= I2C_S_IICIF_MASK;
}
bool i2c_get_ack(I2C_MemMapPtr p)
{
    if((p->S & I2C_S_RXAK_MASK) == 0)
        return 1;
    else
        return 0;
}




