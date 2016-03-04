/*
 * PEimplementation.c
 *
 *  Created on: Nov 2, 2014
 *      Author: Student
 */
#include "PEimplementation.h"

#include "LSM303DLHC.h"



uint8_t _ReadData;
LSM303_TDataState deviceData;

uint8_t LSM303_ReadReg(uint8_t device, uint8_t addr){
	CI2C1_ClearStats(&deviceData);
	uint8_t res;
	res = CI2C1_MasterSendBlock(deviceData.handle, &addr, 8, LDD_I2C_NO_SEND_STOP);
	
	if(res!=ERR_OK){
		return ERR_FAILED;
	}
	int i;
	//while(!deviceData.dataTransmittedFlg) {}
	for(i = 0; i < 1000; i++){}
	deviceData.dataTransmittedFlg = FALSE;

	res = CI2C1_MasterReceiveBlock(deviceData.handle, &_ReadData, 8, LDD_I2C_SEND_STOP);

	if (res!=ERR_OK){
		return ERR_FAILED;
	}
	//while(!deviceData.dataReceivedFlg) {}
	for(i = 0; i < 1000; i++){}
	deviceData.dataReceivedFlg = FALSE;
	
	return _ReadData;

}

void LSM303_WriteReg(uint8_t device, uint8_t addr, uint8_t data){
	
	uint8_t buf[2];

	buf[0] = addr;
	buf[1] = data;
	
	CI2C1_ClearStats(&deviceData);
	CI2C1_MasterSendBlock(deviceData.handle, &buf, 2U, LDD_I2C_SEND_STOP);
	
	//while (!deviceData.dataTransmittedFlg){}
	int i;
	for(i = 0; i < 1000; i++){}
	deviceData.dataTransmittedFlg = FALSE;
	
}

void LSM303_Init(){
	deviceData.handle = CI2C1_Init(&deviceData);
	I2C_s PEi2c;
	PEi2c.read = LSM303_ReadReg;
	PEi2c.write= LSM303_WriteReg;
	
	setI2C(PEi2c);
	
}

void LSM303_Deinit(){
	CI2C1_Deinit(&deviceData);
}

