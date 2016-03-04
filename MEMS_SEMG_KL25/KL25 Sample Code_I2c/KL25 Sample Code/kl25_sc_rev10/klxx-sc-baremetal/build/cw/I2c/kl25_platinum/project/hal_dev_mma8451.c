

#include "common.h"
#include "global.h"
#include "hal_i2c_ex.h"


#define I2C_ADDR_MMA8451 (0x1d<<1)
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
    for(n=0; n<4000; n++)
        asm("nop");
}
u8 hal_dev_mma8451_read_reg(u8 addr)
{
    u8 result;

    i2c_start(I2C0_B);

    i2c_write_byte(I2C0_B, I2C_ADDR_MMA8451 | I2C_WRITE);
    i2c_wait(I2C0_B);
    i2c_get_ack(I2C0_B);

    i2c_write_byte(I2C0_B, addr);
    i2c_wait(I2C0_B);
    i2c_get_ack(I2C0_B);

    i2c_repeated_start(I2C0_B);
    i2c_write_byte(I2C0_B, I2C_ADDR_MMA8451 | I2C_READ);
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
void hal_dev_mma8451_write_reg(u8 addr, u8 data)
{
    i2c_start(I2C0_B);

    i2c_write_byte(I2C0_B, I2C_ADDR_MMA8451|I2C_WRITE);
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

static void to_active_mode(void)
{
    u8 v;
    v = hal_dev_mma8451_read_reg(0x2a);
    hal_dev_mma8451_write_reg(0x2a,v|0x01);
}
static void to_standby_mode(void)
{
    u8 v;
    v = hal_dev_mma8451_read_reg(0x2a);
    hal_dev_mma8451_write_reg(0x2a,v&0x7e);
}
void hal_dev_mma8451_init(void)
{
    to_standby_mode();
}

////////////////////////////////////////////////////////////////////////

bool hal_dev_mma8451_test_reg_rw(void)
{
    u8 d;
    d = hal_dev_mma8451_read_reg(0x2f);
    printf("d=%x\n",d);
    
    hal_dev_mma8451_write_reg(0x2f,0xaa);
    d = hal_dev_mma8451_read_reg(0x2f);
    printf("d=%x\n",d);
    
    hal_dev_mma8451_write_reg(0x2f,0x55);
    d = hal_dev_mma8451_read_reg(0x2f);
    printf("d=%x\n",d);

    hal_dev_mma8451_write_reg(0x2f,0xff);
    d = hal_dev_mma8451_read_reg(0x2f);
    printf("d=%x\n",d);

    hal_dev_mma8451_write_reg(0x2f,0x00);
    d = hal_dev_mma8451_read_reg(0x2f);
    printf("d=%x\n",d);
    return 0;
}

void hal_dev_mma8451_test_function(void)
{
    s16 resultx;
    s16 resulty;
    s16 resultz;

    to_active_mode();

    printf("X     Y     Z\n");

    while(1)
    {
        if((hal_dev_mma8451_read_reg(0x00)&0xf) != 0)
        {
            resultx = 0;
            resulty = 0;
            resultz = 0;

            resultx   = hal_dev_mma8451_read_reg(0x01)<<8;
            resultx  |= hal_dev_mma8451_read_reg(0x02);
            resultx >>= 2;

            resulty   = hal_dev_mma8451_read_reg(0x03)<<8;
            resulty  |= hal_dev_mma8451_read_reg(0x04);
            resulty >>= 2;

            resultz   = hal_dev_mma8451_read_reg(0x05)<<8;
            resultz  |= hal_dev_mma8451_read_reg(0x06);
            resultz >>= 2;

            printf("accx = %d\r\n   ",   resultx);
            printf("accy = %d\r\n   ",   resulty);
            printf("accz = %d\r\n   ",   resultz);

            //printf("        \r");
        }
    }
}




