/*
 * myiic_m.c
 *
 *  Created on: Jan 15, 2015
 *      Author: lab
 */

#include "MKL25Z4.h"
#include "myiic_m.h"
#include "delay.h"
#include "PE_Types.h"
#include "SCL_M.h"
#include "SDA_M.h"


#define     M_SetScl()          GPIO_PSOR_REG(SCL_M_MODULE_BASE_ADDRESS) = (uint32_t)(SCL_M_PORT_MASK)
#define     M_ClrScl()          GPIO_PCOR_REG(SCL_M_MODULE_BASE_ADDRESS) = (uint32_t)(SCL_M_PORT_MASK)
#define     M_SetSda()          GPIO_PSOR_REG(SDA_M_MODULE_BASE_ADDRESS) = (uint32_t)(SDA_M_PORT_MASK)
#define     M_ClrSda()          GPIO_PCOR_REG(SDA_M_MODULE_BASE_ADDRESS) = (uint32_t)(SDA_M_PORT_MASK)
#define     M_SetDir_out()      GPIO_PDDR_REG(SDA_M_MODULE_BASE_ADDRESS) |= (uint32_t)(SDA_M_PORT_MASK)
#define     M_SetDir_in()       GPIO_PDDR_REG(SDA_M_MODULE_BASE_ADDRESS) &= (uint32_t)(~(uint32_t)(SDA_M_PORT_MASK))


//////////////////////////////////////////////////////////////////////////////////	 
void IIC_Init_M(void)
{					      
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	SCL_M_Init(NULL);
	//SCL_M_SetVal(NULL);
	M_SetScl();
	SDA_M_Init(NULL);
    //SDA_M_SetVal(NULL);
	M_SetSda();
}

//����IIC��ʼ�ź�
void IIC_Start_M(void)
{
	//SDA_M_SetDir(NULL, 1);
	M_SetDir_out();
	M_SetSda();
	//SCL_M_SetVal(NULL);
	M_SetScl();
	time_delay_us(4);
    //SDA_M_ClrVal(NULL);
	M_ClrSda();
    time_delay_us(4);
    //SCL_M_ClrVal(NULL); 
    M_ClrScl();
}

//����IICֹͣ�ź�
void IIC_Stop_M(void)
{
	//SDA_M_SetDir(NULL, 1);
	M_SetDir_out();
	M_ClrScl();
	//SDA_M_ClrVal(NULL);
	M_ClrSda();
	time_delay_us(4);
	//SCL_M_SetVal(NULL);
	M_SetScl();
	//time_delay_us(2);
	//SDA_M_SetVal(NULL);
	M_SetSda();
	time_delay_us(4);
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
uint8 IIC_Wait_Ack_M(void)
{
	uint8 ucErrTime=0;
	//SDA_M_SetDir(NULL, 0);
	M_SetDir_in();
	//SDA_M_SetVal(NULL);
	M_SetSda();
	time_delay_us(1);
	//SCL_M_SetVal(NULL);
	M_SetScl();
	time_delay_us(1);
	
	while(SDA_M_GetVal(NULL))
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC_Stop_M();
			return 1;//�����ʱ���ȡ��SDA_M_GetValΪ1������Ӧ��ʧ��
		}
	}
	//SCL_M_ClrVal(NULL);
	M_ClrScl();
	//time_delay_us(2);
	return 0;  
} 
//����ACKӦ��
void IIC_Ack_M(void)
{
	//SCL_M_ClrVal(NULL);
	M_ClrScl();
	//SDA_M_SetDir(NULL, 1);
	M_SetDir_out();
	//SDA_M_ClrVal(NULL);
	M_ClrSda();
	time_delay_us(2);
	//SCL_M_SetVal(NULL);
	M_SetScl();
	time_delay_us(2);
	//SCL_M_ClrVal(NULL);
	M_ClrScl();
	//time_delay_us(2);//SDA data hold time ���3.45us
}
//������ACKӦ��		    
void IIC_NAck_M(void)
{
	//SCL_M_ClrVal(NULL);
	M_ClrScl();
	//SDA_M_SetDir(NULL, 1);
	M_SetDir_out();
	//SDA_M_SetVal(NULL);
	M_SetSda();
	time_delay_us(2);
	//SCL_M_SetVal(NULL);
	M_SetScl();
	time_delay_us(2);
	//SCL_M_ClrVal(NULL);
	M_ClrScl();
	//time_delay_us(2);//SDA data hold time ���3.45us
}					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void IIC_Send_Byte_M(uint8 txd)
{                        
    uint8 t; 
    
    //SDA_M_SetDir(NULL, 1);
    M_SetDir_out();
    //SCL_M_ClrVal(NULL);
    M_ClrScl();
    for(t=0;t<8;t++)
    {              
    	if( (txd&0x80)>>7 )//�����0x80���������7λ��Ϊ1
    		//SDA_M_SetVal(NULL);
    		M_SetSda();
    	else
    		//SDA_M_ClrVal(NULL);
    		M_ClrSda();
   	
        txd<<=1; 
        time_delay_us(2); 
        //SCL_M_SetVal(NULL);
        M_SetScl();
        time_delay_us(2);
        //SCL_M_ClrVal(NULL);
        M_ClrScl();
        time_delay_us(2);
    }	 
} 	    
//��1���ֽ�
uint8 IIC_Read_Byte_M()
{
	uint8 i,receive=0;
	
	//SDA����Ϊ����
	//SDA_M_SetDir(NULL, 0);	
    for(i=0;i<8;i++ )
	{
    	M_ClrScl();
    	time_delay_us(2);
    	//SCL_M_SetVal(NULL);
    	M_SetScl();
    	//time_delay_us(2); 
        receive=receive<<1;//�����ֽ�����һλ��Ϊ��ȡ������׼��
        if(SDA_M_GetVal(NULL))//���������Ϊ�ߵ�ƽ
            receive=receive|0x1;//��������ֽڵ�ĩλд1
        time_delay_us(1);
    }					  
    return receive;
}

/******************************************************************************
������void I2C_run_M()
���ܣ�����I2C�����շ�����
���أ�0��������1���쳣����Ӧ��
˵��������Mode�ǲ���ģʽ������I2C�����շ���ʽ���������շ���ʽ��3�֣��������£�
       0������ģʽ����ʽ��S | SLA+R | Data... | P
       1������ģʽ����ʽ��S | SLA+W | Addr | Data... | P
       2����Sr���գ���ʽ��S | SLA+W | Addr | Sr | SLA+R | Data... | P
******************************************************************************/
uint8 I2C_run_M
(
		uint8 Mode,      //����ģʽ
		uint8 SLA,       //�ӻ���ַ
		uint8 Addr,      //�ӵ�ַ
		uint8 *Buf,      //���ݻ�����
		uint8 Size       //���ݳ���
)
{
//����I2C����
     IIC_Start_M();
     if ( Mode != I2C_RECV )
     {
     //����SLA+W
         IIC_Send_Byte_M(SLA & 0xFE);
         if ( IIC_Wait_Ack_M() )
         {
             IIC_Stop_M();
             return 1;
         }
     //�����ӵ�ַ
         IIC_Send_Byte_M(Addr);
         if ( IIC_Wait_Ack_M() )
         {
             IIC_Stop_M();
             return 1;
         }
         if ( Mode == I2C_SEND )
         {
         //��������
             do
             {
                 IIC_Send_Byte_M(*Buf++);
                 if ( IIC_Wait_Ack_M() )
                 {
                     IIC_Stop_M();
                     return 1;
                 }
             } while ( --Size != 0 );
         //�������
             IIC_Stop_M();
             return 0;
         }
         else
         {
             IIC_Start_M();     //�����ظ���ʼ����
         }
     }
//����SLA+R
     IIC_Send_Byte_M(SLA | 0x01);
     if ( IIC_Wait_Ack_M() )
     {
         IIC_Stop_M();
         return 1;
     }
//��������
     for (;;)
     {
         *Buf++ = IIC_Read_Byte_M();
         if ( --Size == 0 )
         {
             IIC_NAck_M();     //���������һ������ʱ����NACK
             break;
         }
         IIC_Ack_M();
     }
//�������
     IIC_Stop_M();
     return 0;
}






