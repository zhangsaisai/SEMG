/* ###################################################################
**     Filename    : main.c
**     Project     : FRDM-K22F_PEx
**     Processor   : MK22FN512VLH12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-05-11, 12:29, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "pin_mux.h"
#include "I2C2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
typedef struct
{
int16_t x;
int16_t y;
int16_t z;
} ACCEL_DATA;

typedef struct
{
int16_t x;
int16_t y;
int16_t z;
} MAG_DATA;

ACCEL_DATA AccelData;
MAG_DATA MagnData;

volatile bool DataReceivedFlg = FALSE;
volatile bool DataTransmittedFlg = FALSE;
uint8_t OutData[4] = {0x00U, 0x01U, 0x02U, 0x03U};                /* Initialization of output data buffer */
uint8_t InpData[16];
LDD_TError Error;
LDD_TDeviceData *MyI2CPtr;

// FXOS8700CQ internal register addresses
#define FXOS8700CQ_STATUS 0x00
#define FXOS8700CQ_WHOAMI 0x0D			//DES was 0x00
#define FXOS8700CQ_XYZ_DATA_CFG 0x0E
#define FXOS8700CQ_CTRL_REG1 0x2A
#define FXOS8700CQ_CTRL_REG2 0x2B
#define FXOS8700CQ_M_CTRL_REG1 0x5B
#define FXOS8700CQ_M_CTRL_REG2 0x5C

#define FXOS8700CQ_WHOAMI_VAL 0xC7		//DES Default return value

void _Delay(uint32_t cnt) {
	while(cnt--) {};
}

void _DR_STATUS_VAL() {
	uint8_t out[1];
	uint8_t In[1];		//DES added

	  /* Read configuration of I2C BUS device(e.g. RTC) - Read Operation */
	   out[0] = FXOS8700CQ_STATUS; 					//DES REG_ADDRESS
	   DataTransmittedFlg = FALSE;
	   Error = I2C2_MasterSendBlock(MyI2CPtr, out, 1U, LDD_I2C_NO_SEND_STOP); /* Send REG_ADDRESS (1 byte) on the I2C bus stop condition and will not generate the end of the transmission */
	   while (!DataTransmittedFlg) {                                   /* Wait until OutData are transmitted */
	     I2C2_Main(MyI2CPtr);
	   }
	   DataTransmittedFlg = FALSE;

	   Error = I2C2_MasterReceiveBlock(MyI2CPtr, In, 1U, LDD_I2C_SEND_STOP); /* Receive DATA (1 byte) from the I2C bus and generates a stop condition to end transmission */
	   while (!DataReceivedFlg) {                                      /* Wait until InpData are received */
	     I2C2_Main(MyI2CPtr);
	   }
	   DataReceivedFlg = FALSE;
       //wait for stop condition on bus.
	   while(!(I2C0_FLT &= 0x40));		//DES Thanks Brad!

}

void _WHOAMI_VAL() {
	uint8_t out[1];
	uint8_t In[1];		//DES added

	DataTransmittedFlg=FALSE;
	//DES check WHOAMI...Address of device is inherent with the function call and was setup during initialization.
    out[0] = FXOS8700CQ_WHOAMI;		//DES REG_ADDRESS of register to access
	Error = I2C2_MasterSendBlock(MyI2CPtr, out, 1U, LDD_I2C_NO_SEND_STOP);	//DES Send REG_ADDRESS of register to access...with no stop!
	while (!DataTransmittedFlg) {											//DES Wait for transaction
	I2C2_Main(MyI2CPtr);
	}
	DataTransmittedFlg = FALSE;												//DES reset flag

	Error = I2C2_MasterReceiveBlock(MyI2CPtr, In, 1U, LDD_I2C_SEND_STOP);	//DES Receive DATA...with stop!
	while (!DataReceivedFlg) {												//DES Wait for transaction
	  I2C2_Main(MyI2CPtr);
	}
	DataReceivedFlg = FALSE;												//DES reset flag
    //wait for stop condition on bus.
	   while(!(I2C0_FLT &= 0x40));		//DES Thanks Brad!
}

void Init_FXOS8700(){			//DES out[0] gets filled with DATA/REG_ADDRESS pair
	uint8_t i,out[2];
	uint8_t In[2];

	uint8_t data[]={			//DES DATA/REG_ADDRESS pairs.
		0x40,	FXOS8700CQ_CTRL_REG2,		//DES ok...set to Reset Device
		0,		FXOS8700CQ_CTRL_REG1,		//DES ok...set to Standby mode
		0x2F,	FXOS8700CQ_M_CTRL_REG1,		//DES ok...OSR is 32(m_os[2:0]=7), hybrid mode(m_hms[1:0]=11)
		0x20,	FXOS8700CQ_M_CTRL_REG2,		//DES ok...Auto inc mode from 0x5->0x33(hyb_autoinc_mode=1)
		0x01,	FXOS8700CQ_XYZ_DATA_CFG,	//DES ok...Full Scale range is ±0.488 mg/LSB(fs[1:0]=1)
		0x0D,	FXOS8700CQ_CTRL_REG1,		//DES ok...50HZ(dr[2:0]=0), Normal Mode(Inoise=0), Active Mode(active=0)
		0, 0								//DES NULL terminated
	};

	i=0;																		//DES initialize index pointer
	while(data[i] || data[i+1]) {
#if 1		//DES 1=test(works), 0=default code
	//DES check WHOAMI...Address of device is inherent with the function call and was setup during initialization.
	   out[1] = data[i];		//DES Send DATA to register
	   out[0] = data[i+1];		//DES Send REG_ADDRESS of register to access
	   DataTransmittedFlg=FALSE;
	   Error = I2C2_MasterSendBlock(MyI2CPtr, out, 2U, LDD_I2C_SEND_STOP);	//DES Send REG_ADDRESS...with no stop!
	   if((out[0]==FXOS8700CQ_CTRL_REG2) && (out[1]==0x40))					//DES check if we are resetting device.
		   _Delay(10000000);												//DES if resetting device we need to wait >50msec...this works for default clocking mode.
	   else {
	     while (!DataTransmittedFlg) {											//DES Wait for transaction
	       I2C2_Main(MyI2CPtr);
	     }
		   DataTransmittedFlg = FALSE;												//DES reset flag
	       //wait for stop condition on bus.
		   while(!(I2C0_FLT &= 0x40));		//DES Thanks Brad!
	   }
	   i+=2;																	//DES increment index
#else
		//DES check WHOAMI...Address of device is inherent with the function call and was setup during initialization.
		   out[0] = data[i+1];		//DES Send REG_ADDRESS of register to access
		   DataTransmittedFlg=FALSE;
		   Error = I2C2_MasterSendBlock(MyI2CPtr, out, 1U, LDD_I2C_NO_SEND_STOP);	//DES Send REG_ADDRESS...with no stop!
		   while (!DataTransmittedFlg) {											//DES Wait for transaction
		     I2C2_Main(MyI2CPtr);
		   }
		   DataTransmittedFlg = FALSE;												//DES reset flag

		   out[0] = data[i];		//DES Send DATA to register
		   Error = I2C2_MasterSendBlock(MyI2CPtr, out, 1U, LDD_I2C_SEND_STOP);		//DES Send DATA...with stop!
		   while (!DataTransmittedFlg) {											//DES Wait for transaction
		     I2C2_Main(MyI2CPtr);
		   }
		   DataTransmittedFlg = FALSE;												//DES reset flag
		   i+=2;																	//DES increment index
	       //wait for stop condition on bus.
		   while(!(I2C0_FLT &= 0x40));		//DES Thanks Brad!
#endif

	}
}

void Get_XYZ() {			//DES In[14] gets filled with STATUS[0], OUT_X_MSB[1], OUT_X_LSB[2],..., OUT_Z_MSB[5], OUT_Z_LSB[6]
	uint8_t a,i,out[2];		//DES M_OUT_X_MSB[7], M_OUT_X_LSB[8],..., M_OUT_Z_MSB[11], M_OUT_Z_LSB[12]
	uint8_t In[14];		//DES added

	DataTransmittedFlg=FALSE;
	//DES Note...Address of device is inherent with the function call and was setup during initialization.
	out[0] = FXOS8700CQ_STATUS;		//DES REG_ADDRESS of register to access
	Error = I2C2_MasterSendBlock(MyI2CPtr, out, 1U, LDD_I2C_SEND_STOP);	//DES Send REG_ADDRESS of register to access...with no stop!
	while (!DataTransmittedFlg) {											//DES Wait for transaction
	  I2C2_Main(MyI2CPtr);
	}
	DataTransmittedFlg = FALSE;												//DES reset flag
    //wait for stop condition on bus.
	   while(!(I2C0_FLT &= 0x40));		//DES Thanks Brad!

	Error = I2C2_MasterReceiveBlock(MyI2CPtr, In, 13U, LDD_I2C_SEND_STOP);	//DES Receive DATA(Status, Accel X,Y,Z, and Mag X,Y,Z)...with stop!
	while (!DataReceivedFlg) {												//DES Wait for transaction
	  I2C2_Main(MyI2CPtr);
	}
	DataReceivedFlg = FALSE;												//DES reset flag
    //wait for stop condition on bus.
	   while(!(I2C0_FLT &= 0x40));		//DES Thanks Brad!

	// copy the 14 bit accelerometer byte data into 16 bit words
	AccelData.x = (int16_t)(((In[1] << 8) | In[2]))>> 2;
	AccelData.y = (int16_t)(((In[3] << 8) | In[4]))>> 2;
	AccelData.z = (int16_t)(((In[5] << 8) | In[6]))>> 2;
	// copy the magnetometer byte data into 16 bit words
	MagnData.x = (In[7] << 8) | In[8];
	MagnData.y = (In[9] << 8) | In[10];
	MagnData.z = (In[11] << 8) | In[12];

}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  //Read 6 bytes from accel.
  MyI2CPtr = I2C2_Init(NULL);		//DES added after setting Auto initialization to "no.

  //write 5 bytes to device to initialize (from FXOS8700 Ref. Man).
   Init_FXOS8700();
   while(1) {
	   _WHOAMI_VAL();
	   _Delay(1000);
	   Get_XYZ();
	   _Delay(1000);
	   _DR_STATUS_VAL();
	   _Delay(1000);
   }

  /* Read configuration of I2C BUS device(e.g. RTC) - Read Operation */
   OutData[0] = 0x00U;                                             /* Initialization of OutData buffer */
   Error = I2C2_MasterSendBlock(MyI2CPtr, OutData, 1U, LDD_I2C_NO_SEND_STOP); /* Send OutData (1 byte) on the I2C bus stop condition and will not generate the end of the transmission */
   while (!DataTransmittedFlg) {                                   /* Wait until OutData are transmitted */
     I2C2_Main(MyI2CPtr);
   }
   DataTransmittedFlg = FALSE;

   Error = I2C2_MasterReceiveBlock(MyI2CPtr, InpData, 16U, LDD_I2C_SEND_STOP); /* Receive InpData (16 bytes) from the I2C bus and generates a stop condition to end transmission */
   while (!DataReceivedFlg) {                                      /* Wait until InpData are received */
     I2C2_Main(MyI2CPtr);
   }
   DataReceivedFlg = FALSE;
   //wait for stop condition on bus.
   while(!(I2C0_FLT &= 0x40));		//DES Thanks Brad!


  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
