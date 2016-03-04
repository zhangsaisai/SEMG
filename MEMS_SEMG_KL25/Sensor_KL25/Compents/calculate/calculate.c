/*
 * calculate.c
 *
 *  Created on: Mar 24, 2015
 *      Author: lab
 */
#include "calculate.h"
#include <math.h>
#include "mpu6050.h"
#include "function.h"

extern short max_Mx,max_My,max_Mz,min_Mx,min_My,min_Mz;
extern float Mx_offset,My_offset,Mz_offset,Mx_gain,My_gain,Mz_gain;
extern float pitch,roll,yaw;
/*----------------------------------------------
x_gain=1
y_gain = x_gain * (y_max-y_min)/(x_max-x_min);
z_gain = x_gain * (z_max-z_min)/(x_max-x_min);
www.amobbs.com/thread-5483833-1-11.html
----------------------------------------------*/
void Calibration(void)
{
	short Mx,My,Mz;
	short cnt=0;
//     
    while( cnt<=10000 )
    {
       get_mag(&Mx,&My,&Mz);
       if ( (Mx>max_Mx)&&(Mx!=4096) ) max_Mx = Mx;
          else if ( (Mx<min_Mx)&&(Mx!=-4096) ) min_Mx = Mx;
       if ( (My>max_My)&&(My!=4096) ) max_My = My;
          else if ( (My<min_My)&&(My!=-4096) ) min_My = My;
       if ( (Mz>max_Mz)&&(Mz!=4096) )max_Mz = Mz;
          else if ( (Mz<min_Mz)&&(Mz!=-4096) )min_Mz = Mz;
       time_delay_us(100);
       cnt++;
    }
     
    Mx_offset = -(max_Mx + min_Mx)/2;
    My_offset = -(max_My + min_My)/2;
    Mz_offset = -(max_Mz + min_Mz)/2;
    Mx_gain = 1; 
    My_gain = Mx_gain * (max_My-min_My)/(max_Mx-min_Mx);
    Mz_gain = Mx_gain * (max_Mz-min_Mz)/(max_Mx-min_Mx);  
    //printf("Mx_offset=%lf,My_offset=%lf,Mz_offset=%lf,Mx_gain=%lf,My_gain=%lf,Mz_gain=%lf\n",Mx_offset,My_offset,Mz_offset,Mx_gain,My_gain,Mz_gain);     
}

void calculate_azimuth(void)
{
	short Ax,Ay,Az,Mx,My,Mz,Gx,Gy,Gz;
	float sum,init_ax,init_ay,init_az,Mx_,My_,Mz_,Hx,Hy,Hz;
	
	get_acc(&Ax,&Ay,&Az);
	get_mag(&Mx,&My,&Mz);
	get_gyro(&Gx,&Gy,&Gz);
	printf("Ax=%d,Ay=%d,Az=%d\r\n",Ax,Ay,Az);
	
	sum = (float)Ax*Ax+(float)Ay*Ay+(float)Az*Az;
	sum = sqrtf(sum);
	
	//reference:<Using LSM303DLH for a tilt compensated electronic compass>
	init_ax = (float)-Ax/sum;
	init_ay = (float)Ay/sum;   
	init_az = (float)Az/sum;
	Mx_ =  ( (float)Mx - (float)Mx_offset ) / (float)Mx_gain ;
	My_ =  ( (float)My - (float)My_offset ) / (float)My_gain ;
	Mz_ =  ( (float)Mz - (float)Mz_offset ) / (float)Mz_gain ;    
	
	/*<Using LSM303DLH for a tilt compensated electronic compass>
	 * MPU6050 accelerometer and gyro sensing axes:(Xam,Yam,Zam) 
	 *  Zam
	 *  |  /Yam 
	 *  | /                                          
	 *  |/     
	 *  ------Xam
	 *  MPU6050 handheld device body axes with forward-right-down configuration(Xb,Yb,Zb)  
	 *         ------Xb
	 *        /|
	 *       / |
	 *      /  |
	 *    Yb   Zb
	 *    especially for acc,  Xb down:+1g;   Yb down:+1g;   Zb down:+1g
	 *    IN now pcb,the sensing axes x,y,z of acc and gyro is overthrow,so Hx and Hx is contrary in the tilt compensating
	 *    Hy = My_*cos_fast(pitch/57.3) - Mz_*sin_fast(pitch/57.3);
	 *    Hx = My_*sin_fast(pitch/57.3)*sin_fast(roll/57.3) + Mx_*cos_fast(roll/57.3) + Mz_*sin_fast(roll/57.3)*cos_fast(pitch/57.3);
	 *    Different from the calculating in <Using LSM303DLH for a tilt compensated electronic compass> 
	 * */
	//<Using LSM303DLH for a tilt compensated electronic compass>
	pitch = 57.3 * asin_fast(-init_ax);
	roll  =  asin_fast( init_ay / (cos_fast(pitch/57.3) ) ) * 57.3;
	//using LSM303DLH for a tilt compensated electronic compass
	Hy = My_*cos_fast(pitch/57.3) - Mz_*sin_fast(pitch/57.3);
	Hx = My_*sin_fast(pitch/57.3)*sin_fast(roll/57.3) + Mx_*cos_fast(roll/57.3) + Mz_*sin_fast(roll/57.3)*cos_fast(pitch/57.3);
	Hz = -Mx_*cos_fast(roll/57.3)*sin_fast(pitch/57.3)+My_*sin_fast(roll/57.3)+Mz_*cos_fast(roll/57.3)*cos_fast(pitch/57.3);
	yaw  = atan_fast(My_ , Mx_) * 57.3;
	
	
	//<9DOF姿态融合 四元数 欧拉角转换>
	//roll  = atan_fast(init_ay,init_az) * 57.3;
	//pitch = -asin_fast(init_ax)  * 57.3;
	//yaw  = -atan_fast(Mx_*cos_fast(roll) + My_*sin_fast(roll)*sin_fast(pitch) + Mz_*sin_fast(roll)*cos_fast(pitch),My_*cos_fast(pitch) - Mz_*sin_fast(pitch));  
	//yaw = yaw * 57.3;
}
