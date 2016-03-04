#include "myiic_m.h"
#include "MKL25Z4.h"
#include "PE_Types.h"


void IIC_Init_M(void)
{
    SIM_SCGC4 |= SIM_SCGC4_I2C1_MASK;
    SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
    
    /* PORTC_PCR1: ISF=0,MUX=2 */
    PORTC_PCR1 = (uint32_t)((PORTC_PCR1 & (uint32_t)~(uint32_t)(
                  PORT_PCR_ISF_MASK |
                  PORT_PCR_MUX(0x06)
                 )) | (uint32_t)(
                  PORT_PCR_MUX(0x02)
                 ));  
    /* PORTC_PCR2: ISF=0,MUX=2 */
    PORTC_PCR2 = (uint32_t)((PORTC_PCR2 & (uint32_t)~(uint32_t)(
                  PORT_PCR_ISF_MASK |
                  PORT_PCR_MUX(0x06)
                 )) | (uint32_t)(
                  PORT_PCR_MUX(0x02)
                 ));    

    I2C1_F  = 0x20;
    I2C1_C1 = 0x80;
}
