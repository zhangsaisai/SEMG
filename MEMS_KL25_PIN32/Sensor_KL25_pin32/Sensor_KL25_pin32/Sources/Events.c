/* ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VFM4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-01-14, 10:27, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "delay.h"
#include "SysTick_PDD.h"
#include "Events.h"
#include "Macros.h"
#include "Times.h"
#include "Aliases.h"
#include "Globals.h"

extern uint16 TimingDelay;
#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
#define SYSTICK SysTick_DEVICE
/* Global Variables */
#define COMM_SIZE 1
#define DATA_SIZE 96
extern volatile bool SlaveReceivedFlg;
extern volatile bool MasterReceivedFlg;
extern char master_receive[96];
extern char slave_receive[96];
extern char master_send[96];
extern char slave_send[96];
extern   uint16 intcnt;
/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  MPU6050_DRDY_OnInterrupt (module Events)
**
**     Component   :  MPU6050_DRDY [ExtInt_LDD]
*/
/*!
**     @brief
**         This event is called when an active signal edge/level has
**         occurred.
**     @param
**         UserDataPtr     - Pointer to RTOS device
**                           data structure pointer.
*/
/* ===================================================================*/
void MPU6050_DRDY_OnInterrupt(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
	extern TSENSORPtr tSENSORPtr;

	tSENSORPtr->sensorStatus.isDataReady = TRUE;
    intcnt ++;
    intcnt %= 65535;
    
}

/*
** ===================================================================
**     Event       :  SS_SPI0_OnBlockSent (module Events)
**
**     Component   :  SS_SPI0 [SPISlave_LDD]
*/
/*!
**     @brief
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. This event is
**         available only if the SendBlock method is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer is passed
**                           as the parameter of Init method. 
*/
/* ===================================================================*/
void SS_SPI0_OnBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  SS_SPI0_OnBlockReceived (module Events)
**
**     Component   :  SS_SPI0 [SPISlave_LDD]
*/
/*!
**     @brief
**         This event is called when the requested number of data is
**         moved to the input buffer. This method is available only if
**         the ReceiveBlock method is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer is passed
**                           as the parameter of Init method. 
*/
/* ===================================================================*/
void SS_SPI0_OnBlockReceived(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
	   SlaveReceivedFlg = TRUE;  /* Set slaveReceivedFlg flag */ 
	  
	   if ( slave_receive[0] == MASTER_DATA )//slave receive the command 0x01:send data to master
	   {
		   SwapARMDataBuffer();
		   TransmitMCUData();
		   //SPI0Send( slave_send, DATA_SIZE);
		   //when master send dummy for sensor data,slave receive buffer
		   //SPI0Receive( slave_receive, COMM_SIZE ); 
	   }
	   else  if ( slave_receive[0] == MASTER_DUMMY )//slave receive dummy data
	   {
		   //SPI0Receive( slave_receive, COMM_SIZE);
	   }
	   else 
	   {
		   
	   } 
}

/*
** ===================================================================
**     Event       :  EINT_SYNC_INT_OnInterrupt (module Events)
**
**     Component   :  EINT_SYNC_INT [ExtInt_LDD]
*/
/*!
**     @brief
**         This event is called when an active signal edge/level has
**         occurred.
**     @param
**         UserDataPtr     - Pointer to RTOS device
**                           data structure pointer.
*/
/* ===================================================================*/
void EINT_SYNC_INT_OnInterrupt(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
    extern TARMPtr tARMPtr;
    SwapARMDataBuffer();
    TransmitMCUData();
}

/* END Events */
/*
 ** ===================================================================
 **     Method      :  SysTick_Interrupt (component SysTick)
 **
 **     Description :
 **         The ISR function handling the device SysTick interrupt.
 **         This method is internal. It is used by Processor Expert only.
 ** ===================================================================
 */
PE_ISR(Systick_IRQ)
{
	SysTick_PDD_ClearInterruptFlag(SYSTICK);
	TimingDelay_Decrement();	
	//only close the systick timer in Systick_IRQ is effective.If close it in main function is useless.
	if(TimingDelay==0)
    {
		SYST_CSR &=  ~SysTick_CSR_ENABLE_MASK;//close the Systick timer
		//SYST_CSR &=  ~SysTick_CSR_TICKINT_MASK;//close the interrupt enable
    }
}



#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
