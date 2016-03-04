/*
 * function.c
 *
 *  Created on: Jan 14, 2015
 *      Author: lab
 */

#include <math.h>
#include "function.h"
//以下函数单位均为弧度
//快速计算正弦函数，用抛物线模拟

float sin_fast(float x)
{
    
    float sin_y;
    sin_y = 4/PI * x + (-4)/(PI*PI) * x * fabs(x);
     
    sin_y = 0.225 * (sin_y * fabs(sin_y) - sin_y) + sin_y;
    
    return sin_y;
}

//快速计算余弦函数，用抛物线模拟
float cos_fast(float x)
{
    float cos_y;
    
    cos_y = sin_fast( x + PI/2);
     
    return cos_y;
}
//快速计算反正弦函数，用抛物线模拟
//参考：http://mathforum.org/library/drmath/view/54137.html
//仅仅对x为0~1精度高，对-1~0精度不高，采用奇函数性质
float asin_fast(float x)
{
    
    float asin_y;
    if(x > 0)
    {
        asin_y  = 1.5707288 + (-0.2121144) * x + 0.0742610 * x * x + (-0.0187293) * x * x *x; 
        asin_y = PI/2 - ( sqrtf( 1 - x ) ) * asin_y;
    }
    else 
    {
        x = -x;
        asin_y  = 1.5707288 + (-0.2121144) * x + 0.0742610 * x * x + (-0.0187293) * x * x *x; 
        asin_y = PI/2 - ( sqrtf( 1 - x ) ) * asin_y;
        asin_y = -asin_y;
    }
    return asin_y;
}


float my_abs(float f)
{
    if (f >= 0.0)
    {
        return f;
    } 
    return -f;
}


float atan2_fast(float y,float x)
{
	float x_abs,y_abs,z;
    float base_angle,angle;

	if ((y == 0.0) && (x == 0.0))
		angle = 0.0;
	else {
			/* normalize to +/- 45 degree range */
			y_abs = my_abs(y);
			x_abs = my_abs(x);
			//z = (y_abs < x_abs ? y_abs / x_abs : x_abs / y_abs);
			if (y_abs < x_abs)
				z = y_abs / x_abs;
			else
				z = x_abs / y_abs;
			
			//求出基本角度
			base_angle = 3.14159265358979323846/4 * z - z * ( fabs(z) - 1 ) * (0.2477 + 0.0663 * fabs(z));

			//对基本角度进行变换
			if (x_abs > y_abs)  /*  -45  -> 45 or 135  -> 225 */
			{              
				if (x >= 0.0) 
				{                     /* -45 -> 45 */
					if (y >= 0.0)
						angle = base_angle;     /* 0 -> 45, angle OK */
					else
						angle =  -base_angle;   /*  -45  -> 0, angle =  -angle */
				} 
				else /* 135  -> 180 or 180 -> -135 */
				{  
					angle = 3.14159265358979323846;
					if (y >= 0.0)
						angle -= base_angle;   /* 135 -> 180, angle = 180 -angle */
					else
						angle = base_angle  -  angle;     /* 180  ->  -135, angle = angle - 180 */
				}
			}
			else /* 45 -> 135 or -135 -> -45 */
			{
				if (y >= 0.0) /* 45 -> 135 */ 
				{                 
					angle = 1.57079632679489661923;
					if (x >= 0.0)
						angle  -= base_angle;   /* 45  -> 90, angle = 90  -  angle */
					else
						angle += base_angle;   /* 90  -> 135, angle = 90 + angle */
				} 
				else /*  -135  ->  -45 */
				{                                   
					angle = -1.57079632679489661923;
					if (x >= 0.0)
						angle += base_angle;   /* -90 -> -45, angle = -90 + angle */
					else
						angle  -= base_angle;   /*  -135  ->  -90, angle =  -90  -angle */
				}
			}
		}
	//以上所求的和c语言中的atan2意义相同，即是坐标（x,y）和x正半轴的夹角，逆时针为证，顺时针为负
	return angle;
}

//将atan2的取值转化到0~360；
float atan_fast(float y,float x)
{
	float angle;
    
    angle = atan2_fast(y,x) ;
	if(angle >= 0)
		return angle;
	else
		return(2 * 3.14159265358979323846 + angle);//将-180~0的角度转化为180~360
}


