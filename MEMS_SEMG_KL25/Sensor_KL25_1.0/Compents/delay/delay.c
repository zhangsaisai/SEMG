/*
 * delay.c
 *
 *  Created on: Jan 14, 2015
 *      Author: lab
 */
#include "delay.h" 
#include <stdio.h> 

#include "PE_Types.h"
#include "MKL25Z4.h"

extern  uint16  TimingDelay;
/**************************************************************************//*!
* @brief    Timer Interrupt CallBack function
******************************************************************************/
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{ 
            TimingDelay--;
            //printf("TimingDelay \n");
	}
}

/**********************************************
 * function: time_delay_us
 * input: nTime is the time(us) you need to delay
 * output: 
 **********************************************/
void time_delay_us(uint16 nTime)
{ 
	if( nTime % 2 )
		nTime = ( nTime-1 ) / 2;
	else
		nTime /= 2;
	TimingDelay = nTime;	
	// enable the systick timer 
	SYST_CSR |=  SysTick_CSR_ENABLE_MASK;
	//SYST_CSR |=  SysTick_CSR_TICKINT_MASK;//open the interrupt enable
	while(TimingDelay != 0);	              
}



