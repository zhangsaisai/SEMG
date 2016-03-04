/*
 * myiic_g.c
 *
 *  Created on: Jan 15, 2015
 *      Author: lab
 */

#include "MKL25Z4.h"
#include "myiic_g.h"
#include "delay.h"
#include "PE_Types.h"
#include "SCL_G.h"
#include "SDA_G.h"

#define     G_SetScl()          GPIO_PSOR_REG(SCL_G_MODULE_BASE_ADDRESS) = (uint32_t)(SCL_G_PORT_MASK)
#define     G_ClrScl()          GPIO_PCOR_REG(SCL_G_MODULE_BASE_ADDRESS) = (uint32_t)(SCL_G_PORT_MASK)
#define     G_SetSda()          GPIO_PSOR_REG(SDA_G_MODULE_BASE_ADDRESS) = (uint32_t)(SDA_G_PORT_MASK)
#define     G_ClrSda()          GPIO_PCOR_REG(SDA_G_MODULE_BASE_ADDRESS) = (uint32_t)(SDA_G_PORT_MASK)
#define     G_SetDir_out()      GPIO_PDDR_REG(SDA_G_MODULE_BASE_ADDRESS) |= (uint32_t)(SDA_G_PORT_MASK)
#define     G_SetDir_in()       GPIO_PDDR_REG(SDA_G_MODULE_BASE_ADDRESS) &= (uint32_t)(~(uint32_t)(SDA_G_PORT_MASK))


//////////////////////////////////////////////////////////////////////////////////	 
void IIC_Init_G(void)
{					      
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	SCL_G_Init(NULL);
	//SCL_G_SetVal(NULL);
	G_SetScl();
	SDA_G_Init(NULL);
    //SDA_G_SetVal(NULL);
	G_SetSda();
}

//����IIC��ʼ�ź�
void IIC_Start_G(void)
{
	//SDA_G_SetDir(NULL, 1);
	G_SetDir_out();
	G_SetSda();
	//SCL_G_SetVal(NULL);
	G_SetScl();
	time_delay_us(4);
    //SDA_G_ClrVal(NULL);
	G_ClrSda();
    time_delay_us(4);
    //SCL_G_ClrVal(NULL); 
    G_ClrScl();
}

//����IICֹͣ�ź�
void IIC_Stop_G(void)
{
	//SDA_G_SetDir(NULL, 1);
	G_SetDir_out();
	G_ClrScl();
	//SDA_G_ClrVal(NULL);
	G_ClrSda();
	time_delay_us(4);
	//SCL_G_SetVal(NULL);
	G_SetScl();
	//SDA_G_SetVal(NULL);
	G_SetSda();
	time_delay_us(4);
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
uint8 IIC_Wait_Ack_G(void)
{
	uint8 ucErrTime=0;
	//SDA_G_SetDir(NULL, 0);
	G_SetDir_in();
	//SDA_G_SetVal(NULL);
	G_SetSda();
	time_delay_us(1);
	//SCL_G_SetVal(NULL);
	G_SetScl();
	time_delay_us(1);
	
	while(SDA_G_GetVal(NULL))	
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC_Stop_G();
			return 1;//�����ʱ���ȡ��SDA_M_GetValΪ1������Ӧ��ʧ��
		}
	}
	//SCL_G_ClrVal(NULL);
	G_ClrScl();
	return 0;  
} 
//����ACKӦ��
void IIC_Ack_G(void)
{
	//SCL_G_ClrVal(NULL);
	G_ClrScl();
	//SDA_G_SetDir(NULL, 1);
	G_SetDir_out();
	//SDA_G_ClrVal(NULL);
	G_ClrSda();
	time_delay_us(2);
	//SCL_G_SetVal(NULL);
	G_SetScl();
	time_delay_us(2);
	//SCL_G_ClrVal(NULL);
	G_ClrScl();
	//time_delay_us(2);//SDA data hold time ���3.45us
}
//������ACKӦ��		    
void IIC_NAck_G(void)
{
	//SCL_G_ClrVal(NULL);
	G_ClrScl();
	//SDA_G_SetDir(NULL, 1);
	G_SetDir_out();
	//SDA_G_SetVal(NULL);	
	G_SetSda();
	time_delay_us(2);
	//SCL_G_SetVal(NULL);
	G_SetScl();
	time_delay_us(2);
	//SCL_G_ClrVal(NULL);
	G_ClrScl();
	//time_delay_us(2);//SDA data hold time ���3.45us
}					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void IIC_Send_Byte_G(uint8 txd)
{                        
    uint8 t; 
    
    //SDA_G_SetDir(NULL, 1);
    G_SetDir_out();
    //SCL_G_ClrVal(NULL);
    G_ClrScl();
    for(t=0;t<8;t++)
    {              
    	if( (txd&0x80)>>7 )//�����0x80���������7λ��Ϊ1
    		//SDA_G_SetVal(NULL);
    		G_SetSda();
    	else
    		//SDA_G_ClrVal(NULL);
    		G_ClrSda();
   	
        txd<<=1; 
        time_delay_us(2);
        //SCL_G_SetVal(NULL);
        G_SetScl();
        time_delay_us(2);
        //SCL_G_ClrVal(NULL);
        G_ClrScl();
        time_delay_us(2);
    }	 
} 	    
//��1���ֽ�
uint8 IIC_Read_Byte_G()
{
	uint8 i,receive=0;
	
	//SDA����Ϊ����
	//SDA_G_SetDir(NULL, 0);
	G_SetDir_in();
    for(i=0;i<8;i++ )
	{
    	G_ClrScl();
    	time_delay_us(2);
    	G_SetScl();
        receive=receive<<1;//�����ֽ�����һλ��Ϊ��ȡ������׼��
        if(SDA_G_GetVal(NULL))//���������Ϊ�ߵ�ƽ
            receive=receive|0x1;//��������ֽڵ�ĩλд1
        time_delay_us(1);

    }					  
    return receive;
}

/******************************************************************************
������void I2C_run_G()
���ܣ�����I2C�����շ�����
���أ�0��������1���쳣����Ӧ��
˵��������Mode�ǲ���ģʽ������I2C�����շ���ʽ���������շ���ʽ��3�֣��������£�
       0������ģʽ����ʽ��S | SLA+R | Data... | P
       1������ģʽ����ʽ��S | SLA+W | Addr | Data... | P
       2����Sr���գ���ʽ��S | SLA+W | Addr | Sr | SLA+R | Data... | P
******************************************************************************/
uint8 I2C_run_G
(
		uint8 Mode,      //����ģʽ
		uint8 SLA,       //�ӻ���ַ
		uint8 Addr,      //�ӵ�ַ
		uint8 *Buf,      //���ݻ�����
		uint8 Size       //���ݳ���
)
{
//����I2C����
     IIC_Start_G();
     if ( Mode != I2C_RECV )
     {
     //����SLA+W
         IIC_Send_Byte_G(SLA & 0xFE);
         if ( IIC_Wait_Ack_G() )
         {
             IIC_Stop_G();
             return 1;
         }
     //�����ӵ�ַ
         IIC_Send_Byte_G(Addr);
         if ( IIC_Wait_Ack_G() )
         {
             IIC_Stop_G();
             return 1;
         }
         if ( Mode == I2C_SEND )
         {
         //��������
             do
             {
                 IIC_Send_Byte_G(*Buf++);
                 if ( IIC_Wait_Ack_G() )
                 {
                     IIC_Stop_G();
                     return 1;
                 }
             } while ( --Size != 0 );
         //�������
             IIC_Stop_G();
             return 0;
         }
         else
         {
             IIC_Start_G();     //�����ظ���ʼ����
         }
     }
//����SLA+R
     IIC_Send_Byte_G(SLA | 0x01);
     if ( IIC_Wait_Ack_G() )
     {
         IIC_Stop_G();
         return 1;
     }
//��������
     for (;;)
     {
         *Buf++ = IIC_Read_Byte_G();
         if ( --Size == 0 )
         {
             IIC_NAck_G();     //���������һ������ʱ����NACK
             break;
         }
         IIC_Ack_G();
     }
//�������
     IIC_Stop_G();
     return 0;
}






