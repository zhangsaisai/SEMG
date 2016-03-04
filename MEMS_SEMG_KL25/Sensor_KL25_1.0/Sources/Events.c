/* ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VFT4
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

extern uint16 TimingDelay;
#ifdef __cplusplus
extern "C" {
#endif 

extern   uint16      intCnt;
/* User includes (#include below this line is not maintained by Processor Expert) */
#define SYSTICK SysTick_DEVICE
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
	intCnt++;
	intCnt %= 65536;
	
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
