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

//产生IIC起始信号
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

//产生IIC停止信号
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
//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
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
			return 1;//如果长时间读取的SDA_M_GetVal为1，接收应答失败
		}
	}
	//SCL_G_ClrVal(NULL);
	G_ClrScl();
	return 0;  
} 
//产生ACK应答
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
	//time_delay_us(2);//SDA data hold time 最大3.45us
}
//不产生ACK应答		    
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
	//time_delay_us(2);//SDA data hold time 最大3.45us
}					 				     
//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void IIC_Send_Byte_G(uint8 txd)
{                        
    uint8 t; 
    
    //SDA_G_SetDir(NULL, 1);
    G_SetDir_out();
    //SCL_G_ClrVal(NULL);
    G_ClrScl();
    for(t=0;t<8;t++)
    {              
    	if( (txd&0x80)>>7 )//如果与0x80相与后右移7位，为1
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
//读1个字节
uint8 IIC_Read_Byte_G()
{
	uint8 i,receive=0;
	
	//SDA设置为输入
	//SDA_G_SetDir(NULL, 0);
	G_SetDir_in();
    for(i=0;i<8;i++ )
	{
    	G_ClrScl();
    	time_delay_us(2);
    	G_SetScl();
        receive=receive<<1;//缓冲字节左移一位，为读取数据做准备
        if(SDA_G_GetVal(NULL))//如果数据线为高电平
            receive=receive|0x1;//则给缓冲字节的末位写1
        time_delay_us(1);

    }					  
    return receive;
}

/******************************************************************************
函数：void I2C_run_G()
功能：启动I2C总线收发数据
返回：0－正常，1－异常（无应答）
说明：参数Mode是操作模式，决定I2C总线收发格式。常见的收发格式有3种，具体如下：
       0－接收模式，格式：S | SLA+R | Data... | P
       1－发送模式，格式：S | SLA+W | Addr | Data... | P
       2－带Sr接收，格式：S | SLA+W | Addr | Sr | SLA+R | Data... | P
******************************************************************************/
uint8 I2C_run_G
(
		uint8 Mode,      //操作模式
		uint8 SLA,       //从机地址
		uint8 Addr,      //子地址
		uint8 *Buf,      //数据缓冲区
		uint8 Size       //数据长度
)
{
//启动I2C总线
     IIC_Start_G();
     if ( Mode != I2C_RECV )
     {
     //发送SLA+W
         IIC_Send_Byte_G(SLA & 0xFE);
         if ( IIC_Wait_Ack_G() )
         {
             IIC_Stop_G();
             return 1;
         }
     //发送子地址
         IIC_Send_Byte_G(Addr);
         if ( IIC_Wait_Ack_G() )
         {
             IIC_Stop_G();
             return 1;
         }
         if ( Mode == I2C_SEND )
         {
         //发送数据
             do
             {
                 IIC_Send_Byte_G(*Buf++);
                 if ( IIC_Wait_Ack_G() )
                 {
                     IIC_Stop_G();
                     return 1;
                 }
             } while ( --Size != 0 );
         //发送完毕
             IIC_Stop_G();
             return 0;
         }
         else
         {
             IIC_Start_G();     //发送重复起始条件
         }
     }
//发送SLA+R
     IIC_Send_Byte_G(SLA | 0x01);
     if ( IIC_Wait_Ack_G() )
     {
         IIC_Stop_G();
         return 1;
     }
//接收数据
     for (;;)
     {
         *Buf++ = IIC_Read_Byte_G();
         if ( --Size == 0 )
         {
             IIC_NAck_G();     //接收完最后一个数据时发送NACK
             break;
         }
         IIC_Ack_G();
     }
//接收完毕
     IIC_Stop_G();
     return 0;
}






