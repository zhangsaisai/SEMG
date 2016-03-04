/** ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-07-09, 11:32, # CodeGen: 0
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
#include "Bit1.h"
#include "PE_Types.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

extern  byte buffSlave[6]; /* slave gets msg from master */
extern  LDD_TDeviceData *slaveDevData;
extern  LDD_TDeviceData *masterDevData;
extern  int  i;
extern  bool read_data;
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
  uint8_t* MasterReceiveFlag = (LDD_TUserData*) UserDataPtr;
  *MasterReceiveFlag = TRUE;
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
	i++;
	if(i>10000)
		i=0;
	
	//Put request for reading from SPI
	SS1_ReceiveBlock(slaveDevData, (LDD_TData*)buffSlave, sizeof(buffSlave)); 
	  	
}

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT0 (module Events)
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
void Cpu_OnNMIINT0(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI1_OnInterrupt(void)
{
  /* Write your code here ... */
	uint8 i=0;
	
	read_data = 1;
	//Bit1_SetVal(NULL);
	//for(i=0;i<255;i++);
	//Bit1_ClrVal(NULL);
}

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 0.00.00 [05.02]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
