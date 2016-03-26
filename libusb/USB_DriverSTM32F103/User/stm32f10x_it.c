/**
  ******************************************************************************
  * @file    stm32f10x_it.c
  * $Author: wdluo $
  * $Revision: 67 $
  * $Date:: 2012-08-15 19:00:29 +0800 #$
  * @brief   中断函数定义.
  ******************************************************************************
  * @attention
  *
  *<h3><center>&copy; Copyright 2009-2012, EmbedNet</center>
  *<center><a href="http://www.embed-net.com">http://www.embed-net.com</a></center>
  *<center>All Rights Reserved</center></h3>
  * 
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "usb_lib.h"
#include "usb_istr.h"
#include "usb_pwr.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            			Cortex-M3 处理器的相关服务函数                        */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}
/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x 外设 中断 服务函数                               */
/*  增加需要的外设中断函数在下面。中断的函数名字都已经在startup_stm32f10x_xx.s*/
/*  的文件中定义好了，请参照它来写。                                          */
/******************************************************************************/
/**
  * @brief  USB中断处理函数
  * @note	该中断函数只有STM32F105和STM32F107系列芯片才有这个中断
  * @param  None
  * @retval None
  */
#ifndef STM32F10X_CL
void USB_LP_CAN1_RX0_IRQHandler(void)
{
  USB_Istr();
}
#endif /* STM32F10X_CL */
/**
  * @brief  This function handles OTG WakeUp interrupt request.
  * @note	None
  * @param  None
  * @retval None
  */
void OTG_FS_WKUP_IRQHandler(void)
{
  /* Initiate external resume sequence (1 step) */
  Resume(RESUME_EXTERNAL);  

}
/**
  * @brief  This function handles USB-On-The-Go FS global interrupt request.
  * @note	None
  * @param  None
  * @retval None
  */
#ifdef STM32F10X_CL
void OTG_FS_IRQHandler(void)
{
  STM32_PCD_OTG_ISR_Handler(); 
}
#endif /* STM32F10X_CL */





/*********************************END OF FILE**********************************/
