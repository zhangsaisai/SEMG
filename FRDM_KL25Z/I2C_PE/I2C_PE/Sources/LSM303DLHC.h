/* File foo.  */
#ifndef __LSM303DLHC_H
#define __LSM303DLHC_H

#include <stdlib.h>

#define A_ADDRESS_READ		0x33
#define A_ADDRESS_WRITE		0x32
#define M_ADDRESS_READ		0x3D
#define M_ADDRESS_WRITE		0x3C

//Linear Accelerometer Registers
#define CTRL_REG1_A 		0x20
#define CTRL_REG2_A 		0x21
#define CTRL_REG3_A			0x22
#define CTRL_REG4_A			0x23
#define CTRL_REG5_A			0x24
#define CTRL_REG6_A			0x25
#define REFERENCE_A			0x26
#define STATUS_REG_A		0x27
#define OUT_X_L_A			0x28
#define OUT_X_H_A			0x29
#define OUT_Y_L_A			0x2A
#define OUT_Y_H_A			0x2B
#define OUT_Z_L_A			0x2C
#define OUT_Z_H_A			0x2D
#define FIFO_CTRL_REG_A 	0x2E
#define FIFO_SRC_REG_A  	0x2F
#define INT1_CFG_A			0x30
#define INT1_SRC_A			0x31
#define INT1_THS_A			0x32
#define INT1_DURATION_A		0x33
#define INT2_CFG_A			0x34
#define INT2_SRC_A			0x35
#define INT2_THS_A			0x36
#define INT2_DURATION_A		0x37
#define CLICK_CFG_A			0x38
#define CLICK_SRC_A			0x39
#define CLICK_THS_A			0x3A
#define TIME_LIMIT_A		0x3B
#define TIME_LATENCY_A		0x3C
#define TIME_WINDOW_A		0x3D

//Acceleromter Register Field Macros
//CTRL_REG1_A
//ODR data rate selection macros
/*
#define POWER_DOWN_MODE		(0<<
#define Norm_1Hz			()	
#define Norm_100Hz			()
#define Norm_25Hz			()
#define Norm_50Hz			()
#define Norm_100Hz			()
#define Norm_200Hz			()
#define Norm_400Hz			()
#define LPM_1p620kHz		()
#define Norm_1p344kHz		()
#define LPM_5p376kHz		()
*/

//High-pass filter mode configuration
#define HPF_Normal_mode			00
#define HPF_Ref					01
#define HPF_Normal 				10
#define HPF_AutoReset			11

//Magnetormeter Registers
#define CRA_REG_M			0x00	//Fully Implemented
#define CRB_REG_M			0x01	//Fully Implemented
#define MR_REG_M			0x02 	//Fully Implemented
#define OUT_X_H_M			0x03 	//Partially implemented
#define OUT_X_L_M			0x04 	//Partially implemented
#define OUT_Y_H_M			0x05 	//Partially implemented
#define OUT_Y_L_M			0x06 	//Partially implemented
#define OUT_Z_H_M			0x07 	//Partially implemented
#define OUT_Z_L_M			0x08	//Partially implemented
#define SR_REG_M			0x09 	//
#define IR1_REG_M			0x0A 	//
#define IR2_REG_M			0x0B 	//
#define IR3_REG_M			0x0C 	//
#define TEMP_OUT_H_M		0x31 	//Partially implemented
#define TEMP_OUT_L_M		0x32 	//Partially implemented

//Magnetometer definitions

#define ContinuousConversion 0x00
#define SingleConversion	 0x01
#define Sleep				 0x03
#define Mag_Lock			 0


//Device independent implementation
/*
 These three typedefs will allow the users to implement the library using any device that has i2c
 The implmenter has to instantiate an I2C_s variable like so:
 
 I2C_s (variable name);
 (variable name).read = (name of their I2C read function)
 (variable name).write = (name of their I2C write function)

 The read function must return uint8_t and take in a single uint8_t parameter for address
 The write function must return uint8_t and take in two uint8_t parameters for address and data

 You may need the & sign in front of the assignment like &(name of their I2C...)
 Then call void setI2C(I2C_s); to set library I2C struct to avoid passing to all functions

 This must be done before the device may be used!
*/

typedef uint8_t (*i2c_read)(uint8_t device, uint8_t addr);
typedef void (*i2c_write)(uint8_t device, uint8_t addr, uint8_t data);
typedef struct I2C_s{
	i2c_read read;
	i2c_write write;
} I2C_s;
I2C_s _I2C;
void setI2C(I2C_s i2c);

//Overall functions
int TiltCompensatedHeading();		//Save for last
float SimpleHeading();				//Not fully Implemented



//Accelerometer Methods
//Implemented
//Not-implemented
int LSM303AccelInit();			//loads in user defaults for accelerometer
int AccelPwr(int Power_mode);	//return power mode, if called with 0 for parameter, will return current power mode
int AccelLowPower(int state);	//Enables disables LPM
int AccelAxisEnable(char axis);		//enables Acclerometer axis,  Z for Z, X for X, Y for Y, A for all
int AccelHPFmode(int mode);
int AccelHPFcutoff(int cutoff);
int AccelFilteredData(int toggle);
int AccelHPIS2(int toggle);
int AccelHPIS1(int toggle);


//Magnetometer Methods
//Implemented
void MagDataOutputRate(char rate);
void setTempSensor(char state);
int getTempSensor(void);
uint16_t getTemperature();
void changeGain(char option); //Check table 75 of LSM303DLHC datasheet for info
void changeMagMode(uint8_t Mode);




//Not Implemented

int LSM303MegnetoInit();		//loads in user defaults for magentometer
int16_t getMagX();
int16_t getMagY();
int16_t getMagZ();
char checkMagDRDY();

#endif /* __LSM303DLHC_H */
