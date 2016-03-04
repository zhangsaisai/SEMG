#include "myiic_g.h"
#include "MKL25Z4.h"
#include "PE_Types.h"


void IIC_Init_G(void)
{
    SIM_SCGC4 |= SIM_SCGC4_I2C0_MASK;
    SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
    
    /* PORTE_PCR24: ISF=0,MUX=5 */
    PORTE_PCR24 = (uint32_t)((PORTE_PCR24 & (uint32_t)~(uint32_t)(
                  PORT_PCR_ISF_MASK |
                  PORT_PCR_MUX(0x06)
                 )) | (uint32_t)(
                  PORT_PCR_MUX(0x05)
                 ));  
    /* PORTE_PCR25: ISF=0,MUX=5 */
    PORTE_PCR25 = (uint32_t)((PORTE_PCR25 & (uint32_t)~(uint32_t)(
                  PORT_PCR_ISF_MASK |
                  PORT_PCR_MUX(0x06)
                 )) | (uint32_t)(
                  PORT_PCR_MUX(0x05)
                 ));    

    I2C0_F  = 0x20;
    I2C0_C1 = 0x80;
}
