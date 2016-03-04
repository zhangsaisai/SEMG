

#ifndef __HAL_DEV_MMA8451__
#define __HAL_DEV_MMA8451__

void hal_dev_mma8451_init(void);
u8   hal_dev_mma8451_read_reg(u8 addr);
void hal_dev_mma8451_write_reg(u8 addr, u8 data);
bool hal_dev_mma8451_test_reg_rw(void);
void hal_dev_mma8451_test_function(void);

#endif


