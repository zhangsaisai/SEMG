/*
 * File:		platinum.c
 * Purpose:		Main process
 *
 */

#include "common.h"
#include "global.h"
#include "hal_i2c.h"
#include "hal_dev_mma8451.h"

#ifdef CMSIS
#include "start.h"
#endif

/********************************************************************/
int main (void)
{
    	char ch;
        
#ifdef CMSIS  // If we are conforming to CMSIS, we need to call start here
    start();
#endif
        
  	printf("\n\rRunning the platinum project.\n\r");

	while(1)
	{
	    hal_i2c_init();
	    hal_dev_mma8451_test_function();
	} 
}
/********************************************************************/
