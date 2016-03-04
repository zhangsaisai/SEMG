/** ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-08-08, 16:59, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include <string.h>

/* Global Variables */
#define COMM_SIZE 1
#define DATA_SIZE 14

extern volatile bool SlaveReceivedFlg;
extern volatile bool MasterReceivedFlg;
extern char master_send[14];
extern char slave_send[14];
extern char master_receive[14];
extern char slave_receive[14];

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
**     Description :
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the <NMI
**         interrrupt> property is set to 'Enabled'.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  Cpu_OnHardFault (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
**     Description :
**         This event is called when the Hard Fault exception had
**         occurred. This event is automatically enabled when the <Hard
**         Fault> property is set to 'Enabled'.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cpu_OnHardFault(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  IO1_OnBlockReceived (module Events)
**
**     Component   :  IO1 [Serial_LDD]
**     Description :
**         This event is called when the requested number of data is
**         moved to the input buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void IO1_OnBlockReceived(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */  

}

/*
** ===================================================================
**     Event       :  IO1_OnBlockSent (module Events)
**
**     Component   :  IO1 [Serial_LDD]
**     Description :
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void IO1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}


/*
** ===================================================================
**     Event       :  SS1_OnBlockSent (module Events)
**
**     Component   :  SS1 [SPISlave_LDD]
**     Description :
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. This event is
**         available only if the SendBlock method is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer is passed
**                           as the parameter of Init method. 
**     Returns     : Nothing
** ===================================================================
*/
void SS1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */

}

/*
** ===================================================================
**     Event       :  SS1_OnBlockReceived (module Events)
**
**     Component   :  SS1 [SPISlave_LDD]
**     Description :
**         This event is called when the requested number of data is
**         moved to the input buffer. This method is available only if
**         the ReceiveBlock method is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer is passed
**                           as the parameter of Init method. 
**     Returns     : Nothing
** ===================================================================
*/
void SS1_OnBlockReceived(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
  SlaveReceivedFlg = TRUE;  /* Set MasterReceivedFlg flag */
  
    if (slave_receive[0] == 0x01)
    {
      printf("\nSlave: Data send to master...\n");
      slave_send[0]=0x02;
      slave_send[13]=0x04;
      SS1_SendBlock(SS1_DeviceData, slave_send, DATA_SIZE);
      SS1_ReceiveBlock(SS1_DeviceData, slave_receive, DATA_SIZE);
    }
    else
    	SS1_ReceiveBlock(SS1_DeviceData, slave_receive, COMM_SIZE);
  
}

/*
** ===================================================================
**     Event       :  SM1_OnBlockSent (module Events)
**
**     Component   :  SM1 [SPIMaster_LDD]
**     Description :
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. This event is
**         available only if the SendBlock method is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer is passed
**                           as the parameter of Init method. 
**     Returns     : Nothing
** ===================================================================
*/
void SM1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */

}

/*
** ===================================================================
**     Event       :  SM1_OnBlockReceived (module Events)
**
**     Component   :  SM1 [SPIMaster_LDD]
**     Description :
**         This event is called when the requested number of data is
**         moved to the input buffer. This method is available only if
**         the ReceiveBlock method is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer is passed
**                           as the parameter of Init method. 
**     Returns     : Nothing
** ===================================================================
*/
void SM1_OnBlockReceived(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
    MasterReceivedFlg = TRUE;  /* Set MasterReceivedFlg flag */

     if ((strcmp(master_receive, "Data For Slave") == 0))
     {
         printf("\nMaster: Master accepted Data...\n");      
     }
     else  if ((strcmp(master_receive, "" ) == 0))
     {
       printf("\nMaster: Slave is not responding...\n"); 
     }
     else  if((strcmp(master_receive, "dummy" ) == 0))
     {
     	  printf("\nMaster: dummy accepted ...\n");
     }
     else 
        printf("Master accepted :  %x,%x  ",master_receive[0],master_receive[13]);

}

/*
** ===================================================================
**     Function    : uart_putchar
**
**     Description :
**         This function sends one character to the desired UART port.
**         It was written to patch a CodeWarrior bug with the printf
**         function.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ch              - Character to be sent to the UART
**         uart_port_num   - Specifies which UART to send the 
**         					 character to.   
**                           
**     Returns     : Nothing
** ===================================================================
*/
void uart_putchar (int uart_port_num, char ch)
{
	if (uart_port_num == 0)
	{
      /* Wait until space is available in the FIFO */
      while(!(UART0_S1 & UART_S1_TDRE_MASK));
    
      /* Send the character */
      UART0_D = (uint8)ch;
	}
	else if (uart_port_num == 1)
	{
	  /* Wait until space is available in the FIFO */
	  while(!(UART1_S1 & UART_S1_TDRE_MASK));
	   
	  /* Send the character */
	  UART1_D = (uint8)ch;
	}
	else
	{
	  /* Wait until space is available in the FIFO */
	  while(!(UART2_S1 & UART_S1_TDRE_MASK));
	  
	  /* Send the character */
	  UART2_D = (uint8)ch;
	}
 }

/*
** ===================================================================
**     Function    : uart_getchar
**
**     Description :
**         This function gets one character to the desired UART port.
**         It was written to patch a CodeWarrior bug with the getchar
**         function.
**     Parameters  :
**         NAME            - DESCRIPTION
**         uart_port_num   - Specifies which UART to get the 
**         					 character from.   
**                           
**     Returns     : character (UARTx_D)
** ===================================================================
*/
char uart_getchar (int uart_port_num)
{
	if (uart_port_num == 0)
	{
      /* Wait until space is available in the FIFO */
      while(!(UART0_S1 & UART_S1_RDRF_MASK));
    
      /* Send the character */
      return (uint8)UART0_D;
	}
	else if (uart_port_num == 1)
	{
	  /* Wait until space is available in the FIFO */
	  while(!(UART1_S1 & UART_S1_RDRF_MASK));
	   
	  /* Send the character */
	  return (uint8)UART1_D;
	}
	else
	{
	  /* Wait until space is available in the FIFO */
	  while(!(UART2_S1 & UART_S1_RDRF_MASK));
	  
	  /* Send the character */
	  return (uint8)UART2_D;
	}
 }

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.02]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
