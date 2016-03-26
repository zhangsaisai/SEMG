/******************** (C) COPYRIGHT 2009 STMicroelectronics ********************
* File Name          : usb_endp.c
* Author             : MCD Application Team
* Version            : V3.0.1
* Date               : 04/27/2009
* Description        : Endpoint routines
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "platform_config.h"
#include "stm32f10x.h"
#include "usb_lib.h"
#include "usb_istr.h"
#include "usb_desc.h"
#include <stdio.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint8_t USB_Receive_Buffer[256];
uint8_t USB_Send_Buffer[256];
volatile uint32_t EP1_ReceivedCount=0;
volatile uint32_t EP2_ReceivedCount=0;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : EP1_IN_Callback.
* Description    : EP1 IN Callback Routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP1_IN_Callback(void)
{
	//SetEPTxStatus(ENDP1, EP_TX_STALL);
	//printf("EP2_IN_Callback\n\r");
}
/*******************************************************************************
* Function Name  : EP1_OUT_Callback.
* Description    : EP1 OUT Callback Routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP1_OUT_Callback(void)
{
	EP1_ReceivedCount = GetEPRxCount(ENDP1);
	PMAToUserBufferCopy(USB_Receive_Buffer, ENDP1_RXADDR, EP1_ReceivedCount);
	SetEPRxStatus(ENDP1, EP_RX_VALID);
}
/*******************************************************************************
* Function Name  : EP2_IN_Callback.
* Description    : EP2 IN Callback Routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP2_IN_Callback(void)
{
	//SetEPTxStatus(ENDP2, EP_TX_STALL);
	//printf("EP2_IN_Callback\n\r");
}

/*******************************************************************************
* Function Name  : EP2_OUT_Callback.
* Description    : EP2 OUT Callback Routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP2_OUT_Callback(void)
{
	EP2_ReceivedCount = GetEPRxCount(ENDP2);
	PMAToUserBufferCopy(USB_Receive_Buffer, ENDP2_RXADDR, EP2_ReceivedCount);
	SetEPRxStatus(ENDP2, EP_RX_VALID);
}
/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/

