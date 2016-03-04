#include "LSM303DLHC.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Library functions
void setI2C(I2C_s i2c){
	_I2C.read = i2c.read;
	_I2C.write = i2c.write;
}


//Magnetometer functions
int LSM303MagnetoInit(){
	setTempSensor(0);		//Turns sensor off
	MagDataOutputRate('H');		//Minimum output 220Hz
	changeGain(6);			//Change to highest gain
	changeMagMode(ContinuousConversion);
	
	return 0;
}

void MagDataOutputRate(char rate){
	uint8_t CRA_REG_M_val = _I2C.read(M_ADDRESS_READ, CRA_REG_M);

	switch(rate)
	{
		//0.75
		case 'A':
			
			//CRA_REG_M |= (0 << 4) | (0 << 3) | (0 << 2);
			CRA_REG_M_val &= ~(1 << 4) & ~(1<<3) & ~(1<<2);
			break;

		//1.5
		case 'B':
			CRA_REG_M_val &= ~(1 << 4) & ~(1 << 3);
			CRA_REG_M_val |= (1<<2);
			break;

		//3.0
		case 'C':
			CRA_REG_M_val &= ~(1 << 4) & ~(1 << 2);
			CRA_REG_M_val |= (1 << 3);
			break;

		//7.5
		case 'D':
			CRA_REG_M_val &= ~(1<<4);
			CRA_REG_M_val |= (1<<3) | (1<<2);
			break;
		
		//15
		case 'E':
			CRA_REG_M_val |= (1<<4);
			CRA_REG_M_val &= ~(1 << 3 ) & ~(1 << 2);
			break;

		//30
		case 'F':
			CRA_REG_M_val |= (1 << 4) | (1 << 2);
			CRA_REG_M_val &= (1 << 3);
			break;

		//75
		case 'G':
			CRA_REG_M_val |= (1 << 4) | (1 << 3);
			CRA_REG_M_val &= ~(1 << 2);
			break;

		//220
		case 'H':
			CRA_REG_M_val |= (1 << 4) | (1 << 3) | (1 << 2);
			break;

		default:
			//Sets default to 15 Hz
			CRA_REG_M_val |= (1 << 4);
			CRA_REG_M_val &= (1 << 3) & (1 << 2);
			break;
	}

	//Sent out I2C the val to the CRA_REG_M register
	_I2C.write(M_ADDRESS_WRITE, CRA_REG_M, CRA_REG_M_val);
}	

void setTempSensor(char state){
	uint8_t CRA = _I2C.read(M_ADDRESS_READ, CRA_REG_M);

	if (state == 1)
		CRA |= (1<<7);
	else if (state == 0)
		CRA &= ~(1<<7);
	else{}

	_I2C.write(M_ADDRESS_WRITE, CRA_REG_M, CRA);	
}

int getTempSensor(){
	uint8_t CRA = _I2C.read(M_ADDRESS_READ, CRA_REG_M);
	if (CRA/128 == 1){
		return 1;
	}
	else if (CRA/128 == 0){
		return 0;
	}
	else{}
	return 2;
}

int16_t getMagX(){
	int8_t High = _I2C.read(M_ADDRESS_READ, OUT_X_H_M);
	uint8_t Low = _I2C.read(M_ADDRESS_READ, OUT_X_L_M);
	int16_t MagX = ((int16_t)High<<8 | Low);
	return MagX;

}
int16_t getMagY(){
	int8_t High = _I2C.read(M_ADDRESS_READ, OUT_Y_H_M);
	uint8_t Low = _I2C.read(M_ADDRESS_READ, OUT_Y_L_M);
	int16_t MagY = ((int16_t)High<<8 | Low);
	return MagY;
}
int16_t getMagZ(){
	int8_t High = _I2C.read(M_ADDRESS_READ, OUT_Z_H_M);
	uint8_t Low = _I2C.read(M_ADDRESS_READ, OUT_Z_L_M);
	int16_t MagZ = ((int16_t)High<<8 | Low);
	return MagZ;
}

uint16_t getTemperature(){
	if (getTempSensor() == 1){
		uint8_t High = _I2C.read(M_ADDRESS_READ, TEMP_OUT_H_M);
		uint8_t Low = _I2C.read(M_ADDRESS_READ, TEMP_OUT_L_M);
		uint16_t Temp = ((uint16_t)High<<8 | Low);
		Temp = (Temp>>4);
		return Temp;
	}
	else{
		printf("Temperature Sensor isn't enabled");
		return 1;
	}
}

void changeGain(char option){
	uint8_t GA = _I2C.read(M_ADDRESS_READ, CRB_REG_M);
	switch(option)
	{
		case 0:						//001 +-1.3 Gauss			
			GA &= ~(1<<7) & ~(1<<6);
			GA |= (1<<5);
			break;

		case 1:						//010 +-1.9 Gauss
			GA &= ~(1<<7) & ~(1<<5);
			GA |= (1<<6);
			break;

		case 2:						//011 +-2.5 Gauss
			GA &= ~(1<<7);
			GA |= (1<<6) | (1<<5);
			break;

		case 3:						//100 +-4.0 Gauss
			GA |= (1<<7);
			GA &= ~(1<<6) & ~(1<<5);
			break;

		case 4:						//101 +-4.7 Gauss
			GA |= (1<<7) | (1<<5);
			GA &= ~(1<<6);
			break;
			
		case 5:						//110 +-5.6 Gauss
			GA |= (1<<7) | (1<<6);
			GA &= (1<<5);
			break;

		case 6:						//111 +-8.1 Gauss
			GA |= (1<<7) | (1<<6) | (1<<5);
			break;

		default:					//001 +-1.3 Gauss (default)
			GA &= ~(1<<7) & ~(1<<6);
			GA |= (1<<5);
			printf("Invalid 'option' parameter in changeGain method call, reverting to default gain value");
			break;
	}

	_I2C.write(M_ADDRESS_WRITE, CRB_REG_M, GA);
}

void changeMagMode(uint8_t Mode){
	if (Mode == ContinuousConversion || Mode == 0x00){
		_I2C.write(M_ADDRESS_WRITE, MR_REG_M, 0x00);
	}
	else if(Mode == SingleConversion || Mode == 0x01){
		_I2C.write(M_ADDRESS_WRITE, MR_REG_M, 0x01);
	}
	else if(Mode == Sleep || Mode == 0x02 || Mode == 0x03){
		_I2C.write(M_ADDRESS_WRITE, MR_REG_M, 0x03);
	}
	else{
		printf("Invalid 'Mode' parameter selected in changeMagMode call");
	}
}

char checkMagDRDY(){
	//Check if Mag_Lock is true, if so, break because a read is be
	//Or the register against the 0x01

	//If DRDY is set, change Mag_Lock to true,
	return 0;
}



/*
int TiltCompensatedHeading(){
	int MagX = getMagX();
	int MagY = getMagY();
	int MagZ = getMagZ();

	//get Accelerometer data too

	int Pitch;
	int Roll;
	int Yaw;

	int Ryaw[3][3] = {{cos(Yaw), sin(Yaw), 0},
					  {-sin(Yaw), cos(Yaw), 0},
					  {0, 0, 1}};

	int Rpitch[3][3] = {{cos(Pitch), 0, -sin(Pitch)},
						{0, 1, 0},
						{sin(Pitch), 0, cos(Pitch)}};

	int Rroll[3][3] = {{1, 0, 0}, 
					   {0, cos(Roll), sin(Roll)}, 
					   {0, -sin(Roll), cos(Roll)}};

	return 0;
}
*/

float SimpleHeading(){
	int16_t MagX = getMagX();
	int16_t MagY = getMagY();
	int16_t MagZ = getMagZ(); 	//Not used in code.  Chip will not generate new data until all registers are read.

	float Pi = 3.14159;
	double heading = (atan2((double)MagX, (double)MagY) * 180)/ Pi;

	return heading;
}
