#ifndef __PEimplementation_H
#define __PEimplementation_H

#include <stdlib.h>
#include "CI2C1.h"

typedef struct LSM303_TDataState
{
	volatile bool dataReceivedFlg;
	volatile bool dataTransmittedFlg;
	LDD_TDeviceData *handle;
}	LSM303_TDataState;


extern uint8_t LSM303_ReadReg(uint8_t, uint8_t);
extern void LSM303_WriteReg(uint8_t, uint8_t, uint8_t);
extern void LSM303_Init();
extern void LSM303_Deinit();

#endif /* __PEimplementation_H */
