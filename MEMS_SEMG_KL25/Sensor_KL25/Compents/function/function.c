/*
 * function.c
 *
 *  Created on: Jan 14, 2015
 *      Author: lab
 */

#include <math.h>
#include "function.h"
//���º�����λ��Ϊ����
//���ټ������Һ�������������ģ��

float sin_fast(float x)
{
    
    float sin_y;
    sin_y = 4/PI * x + (-4)/(PI*PI) * x * fabs(x);
     
    sin_y = 0.225 * (sin_y * fabs(sin_y) - sin_y) + sin_y;
    
    return sin_y;
}

//���ټ������Һ�������������ģ��
float cos_fast(float x)
{
    float cos_y;
    
    cos_y = sin_fast( x + PI/2);
     
    return cos_y;
}
//���ټ��㷴���Һ�������������ģ��
//�ο���http://mathforum.org/library/drmath/view/54137.html
//������xΪ0~1���ȸߣ���-1~0���Ȳ��ߣ������溯������
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
			
			//��������Ƕ�
			base_angle = 3.14159265358979323846/4 * z - z * ( fabs(z) - 1 ) * (0.2477 + 0.0663 * fabs(z));

			//�Ի����ǶȽ��б任
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
	//��������ĺ�c�����е�atan2������ͬ���������꣨x,y����x������ļнǣ���ʱ��Ϊ֤��˳ʱ��Ϊ��
	return angle;
}

//��atan2��ȡֵת����0~360��
float atan_fast(float y,float x)
{
	float angle;
    
    angle = atan2_fast(y,x) ;
	if(angle >= 0)
		return angle;
	else
		return(2 * 3.14159265358979323846 + angle);//��-180~0�ĽǶ�ת��Ϊ180~360
}


