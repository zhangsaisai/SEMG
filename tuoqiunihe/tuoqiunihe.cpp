/*===========================================================================*/
//���ã�������ϣ��Ŵ���������궨��У׼��
//������������ @ 2016-03-28
//�޸ģ������� @ 2016-03-28
/*===========================================================================*/
//����Ϊ������ϵĻ���ԭ�ͣ��μ�����������������ϵ���ά�����������㷨�����콨���ȡ�-���й����Լ���ѧ����
/*1.���ȸ��ݱպ���ʽ�����������ϵĳ�ֵ��������
//2.������С���˷�����������С���˷��������������������ݹ��Ʋ������������ó�׼ȷ������
//3.���������ﲻ��Ҫ����2�м���õ���׼ȷ������Ϊ��ֵ����������ţ�ٵ�����ֱ���ó�׼ȷ������*/	
//����˵����
//����ĳ�ʼ���ĵ�����x_chu��y_chu��z_chu��ʼ��Ϊ��0��0��0��
//����������ʾΪa��b��c��A=a/b  B=a/c  R=a ,A\B\R����ʼ��Ϊ1
/*===========================================================================*/

#include "stdlib.h" 
#include "string.h" 
#include "math.h"
#include "stdio.h" 
#include <iostream> 

using namespace std;

#define LENGTH 2016//2016���Ŵ����������ֽ�
#define ITERATION 3//�������ʱ�ĵ�������
#define FIT_LEN  12//��FIT_LEN�����ݽ����������

double  A=1;//����ĳ�ֵ����
double  B=1;
double  R=1;
double  x_chu=0;
double  y_chu=0;
double  z_chu=0;

double  A_new=1;//����ĸ��²���
double  B_new=1;
double  R_new=1;
double  x_new=0;
double  y_new=0;
double  z_new=0;

//malloc�ķ���������void����Ҫ��malloc֮ǰ����ǿ��ת��(short ((*)[3]))
//short (*mag_data)[3] = (short ((*)[3]))malloc(sizeof(short)*(LENGTH/6)*3); //mag_data�洢�����ߵ��ֽڵĴŴ��������ݣ�length/6�У�3�зֱ��ʾX��Y��Z
//double (*data)[3] = (double ((*)[3]))malloc(sizeof(double)*(LENGTH/6/10)*3); //data�洢��mag_data�е�ÿ10��������ƽ���ľ�ֵ
//double *data_x = (double *)malloc(sizeof(double)*(LENGTH/6/10)); //��������ƽ����x�������
//double *data_y = (double *)malloc(sizeof(double)*(LENGTH/6/10)); //��������ƽ����y�������
//double *data_z = (double *)malloc(sizeof(double)*(LENGTH/6/10)); //��������ƽ����z�������
short mag_data[LENGTH/6][3];//mag_data�洢�����ߵ��ֽڵĴŴ��������ݣ�length/6�У�3�зֱ��ʾX��Y��Z
double data[LENGTH/6/10][3];//data�洢��mag_data�е�ÿ10��������ƽ���ľ�ֵ
double data_x[LENGTH/6/10];//��������ƽ����x�������
double data_y[LENGTH/6/10];//��������ƽ����y�������
double data_z[LENGTH/6/10];//��������ƽ����z�������
double fit_x[FIT_LEN];//�������ʱ�õ���12��ֵ
double fit_y[FIT_LEN];
double fit_z[FIT_LEN];
int cnt_update = 0;//��ǰ����������µ��ڼ��Σ���ʼֵΪ0

unsigned char txt_data;//�����txt�ļ��ж�ȡ�ĴŴ���������;�洢Ϊȫ�ֱ���,����ʱ�����������
/*****************************************************************************
read_data()
���ܣ���txt�ļ��ж�ȡ���������ݣ������䱣���ڶ�άȫ��������
������txt�ļ��дŴ����������ݳ���(length�д�����)
���أ��Ŵ��������ݵĶ�ά����(ʮ����)
****************************************************************************/
int read_data()
{
	FILE *fp;
	unsigned int i=0,j=0,len=0;
    unsigned int file_size;//file_size��ʾ�ļ���С

	unsigned char *raw_data = (unsigned char *)malloc(sizeof(unsigned char)*(LENGTH)); //mag_data�洢��txt�ж�ȡ����ԭʼ�Ŵ���������;
	
	if((fp=fopen("D:/kuaipan/SEMG/libusb/USB_DriverTest/sensordata.txt","r"))==NULL)//ע��Ҫʹ��ת���ַ���������Ŀ¼�е�\�ַ�
	{
		printf("cannot open file");
		return -1;
	}
	else
		printf("file has been opened\n");

	fseek( fp, 0, SEEK_END );//��λ�ļ�ָ�뵽�ļ�ĩβ���ɹ�����0�����ɹ�����-1��
	file_size = ftell( fp );//ftell����õ�ǰ�ļ�ָ�뵽�ļ��׵Ĵ�С
	fseek( fp, 0, SEEK_SET );//�ٶ�λ�ļ�ָ�뵽�ļ�ͷ

	while(!feof(fp))
	{
		fscanf(fp,"%x",&txt_data);
		if(len%2)
			raw_data[len/2] = txt_data;//��������ţ�ֻ����Ŵ�������
		len++;
		//if(len==4031)
		//	printf("the second last\n");
		//if(len==4032)
		//	printf("the first last\n");
	}
	for(i=0;i<len/12;i++)//raw_data������ά����i/2,����i/4��short�����ݣ���i/12��x��y��z��������
		for(j=0;j<6;j=j+2)
			//mag_data��ÿһ����һ��Ŵ���������
			mag_data[i][j/2] =  (short) ((raw_data[i*6+j] << 8) + raw_data[i*6+j+1]) ;//ÿ6���ֽ���һ��x��y��z������i*6

	fclose(fp);   
	free(raw_data);
    return 0;
}


/*****************************************************************************
average_data()
���ܣ��Ӷ�άȫ������mag_data�е����ᴫ������ÿ10��������ƽ��
��������
���أ���
****************************************************************************/
int average_data()
{
	int temp,sum,i;
	//ÿ10������������ƽ��
	for(i=0;i<(LENGTH/6)/10;i++)
	{
		temp = i*10;
		sum = mag_data[temp][0]+mag_data[temp+1][0]+mag_data[temp+2][0]+mag_data[temp+3][0]+mag_data[temp+4][0]+mag_data[temp+5][0]+mag_data[temp+6][0]+mag_data[temp+7][0]+mag_data[temp+8][0]+mag_data[temp+9][0];
		data[i][0] = ((double)sum)/10;
		data_x[i] = ((double)sum)/10;

		sum = mag_data[temp][1]+mag_data[temp+1][1]+mag_data[temp+2][1]+mag_data[temp+3][1]+mag_data[temp+4][1]+mag_data[temp+5][1]+mag_data[temp+6][1]+mag_data[temp+7][1]+mag_data[temp+8][1]+mag_data[temp+9][1];
		data[i][1] = ((double)sum)/10;
		data_y[i] = ((double)sum)/10;

		sum = mag_data[temp][2]+mag_data[temp+1][2]+mag_data[temp+2][2]+mag_data[temp+3][2]+mag_data[temp+4][2]+mag_data[temp+5][2]+mag_data[temp+6][2]+mag_data[temp+7][2]+mag_data[temp+8][2]+mag_data[temp+9][2];
		data[i][2] = ((double)sum)/10;
		data_z[i] = ((double)sum)/10;
	}
	return 0;
}

/*****************************************************************************
void FindMaxAndMin(int *pArr, int nLength, int &k, int &l) 
���ܣ�������������һ�����飬�Ƚ�2*N��������ֵ����Сֵ,�����������
������pArr:�������� nLength:���鳤��; k:�������ֵ������  l:������Сֵ������
���أ���
****************************************************************************/
void FindMaxAndMin(double *pArr, int nLength, int &k, int &l)  
{
	int i,j;
	double max=pArr[0],min=pArr[0];
	
	for(j=0;j<nLength;j++)
	{
	if(pArr[j]>=max)
	{
	max = pArr[j];
	k = j;
	}
	}
	for(i=0;i<nLength;i++)
	{
	if(pArr[i]<=min)
	{
	min = pArr[i];
	l = i;
	}
	}
}

/*****************************************************************************
select_data()
���ܣ�ѡȡ12�����ݣ�6����ֵ��6�����ֵ�������������
������ ��
���أ���
****************************************************************************/
int select_data()
{
	int x_index_max,x_index_min,y_index_max,y_index_min,z_index_max,z_index_min;//����������ֵ��Сֵ������
	double temp;//���ڱ���������ֵ��Сֵλ��ʱ����ʱ����

	//data[][0]��data[][1]��data[][2]��Ӧx��y��z������ݣ��ֱ��ҳ��������ݵ����ֵ����Сֵ
	FindMaxAndMin(data_x, LENGTH/6/10, x_index_max, x_index_min);
	FindMaxAndMin(data_y, LENGTH/6/10, y_index_max, y_index_min);
	FindMaxAndMin(data_z, LENGTH/6/10, z_index_max, z_index_min);

	//��x,y,z�����Ӧ�����ֵ����Сֵ��������data�����е�ǰ����λ��
	//xȡ���ֵʱ
	temp = data[0][0];
	data[0][0] = data[x_index_max][0];
	data[x_index_max][0] = temp;
	temp = data[0][1];
	data[0][1] = data[x_index_max][1];
	data[x_index_max][1] = temp;
	temp = data[0][2];
	data[0][2] = data[x_index_max][2];
	data[x_index_max][2] = temp;

	//xȡ��Сֵʱ
	temp = data[1][0];
	data[1][0] = data[x_index_min][0];
	data[x_index_min][0] = temp;
	temp = data[1][1];
	data[1][1] = data[x_index_min][1];
	data[x_index_min][1] = temp;
	temp = data[1][2];
	data[1][2] = data[x_index_min][2];
	data[x_index_min][2] = temp;

	//yȡ���ֵʱ
	temp = data[2][0];
	data[2][0] = data[y_index_max][0];
	data[y_index_max][0] = temp;
	temp = data[2][1];
	data[2][1] = data[y_index_max][1];
	data[y_index_max][1] = temp;
	temp = data[2][2];
	data[2][2] = data[y_index_max][2];
	data[y_index_max][2] = temp;

	//yȡ��Сֵʱ
	temp = data[3][0];
	data[3][0] = data[y_index_min][0];
	data[y_index_min][0] = temp;
	temp = data[3][1];
	data[3][1] = data[y_index_min][1];
	data[y_index_min][1] = temp;
	temp = data[3][2];
	data[3][2] = data[y_index_min][2];
	data[y_index_min][2] = temp;

	//zȡ���ֵʱ
	temp = data[4][0];
	data[4][0] = data[z_index_max][0];
	data[z_index_max][0] = temp;
	temp = data[4][1];
	data[4][1] = data[z_index_max][1];
	data[z_index_max][1] = temp;
	temp = data[4][2];
	data[4][2] = data[z_index_max][2];
	data[z_index_max][2] = temp;

	//zȡ��Сֵʱ
	temp = data[5][0];
	data[5][0] = data[z_index_min][0];
	data[z_index_min][0] = temp;
	temp = data[5][1];
	data[5][1] = data[z_index_min][1];
	data[z_index_min][1] = temp;
	temp = data[5][2];
	data[5][2] = data[z_index_min][2];
	data[z_index_min][2] = temp;

	return 0;

}
/*****************************************************************************
init_data()
���ܣ�ѡȡFIT_LEN�����ݣ�6����ֵ��֮���FIT_LEN-6��ֵ������������ϣ��õ���������ĳ�ʼֵ
������ ��
���أ���
****************************************************************************/
int init_data()
{
	int i;
	for(i=0;i<FIT_LEN;i++)
	{
		fit_x[i]=data[i][0];
		fit_y[i]=data[i][1];
		fit_z[i]=data[i][2];
	}
	return 0;
}

/*****************************************************************************
update_data()
���ܣ�ǰ����ֵΪ��������ֵ��Сֵ��ѡȡ6�����ֵ����������ϣ��������������������ֵ
������ ��
���أ���
****************************************************************************/
int update_data()
{
	int i = 0;
	//���º���������
	for(i=(FIT_LEN-6);i<FIT_LEN;i++)
	{
		fit_x[i]=data[FIT_LEN+6*(cnt_update-1)+i][0];
		fit_y[i]=data[FIT_LEN+6*(cnt_update-1)+i][1];
		fit_z[i]=data[FIT_LEN+6*(cnt_update-1)+i][2];
	}
	return 0;
}

/*****************************************************************************
static double *matrix_add(double *U, double *V, int m, int n)
���ܣ����������
������U VΪm*n����
���أ�resultΪU+V��
****************************************************************************/
static double *matrix_add(double *U, double *V, int m, int n)
{
	double *result = (double *)malloc(sizeof(double) * m * n);
	int i = 0;
	int j = 0;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
				*(result + i*m + j)  = (*(U + i*m + j)) + (*(V + i*m + j));
		}	
	}
	return result;
}


/*****************************************************************************
static double *matrix_sub(double *U, double *V, int m, int n)
���ܣ����������
������U VΪm*n����
���أ�resultΪU-V��
****************************************************************************/
static double *matrix_sub(double *U, double *V, int m, int n)
{
	double *result = (double *)malloc(sizeof(double) * m * n);
	int i = 0;
	int j = 0;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
				*(result + i*m + j)  = (*(U + i*m + j)) - (*(V + i*m + j));
		}	
	}
	return result;
}


/**************************************************************************/
/*****************************************************************************
double * qr_fraction(double *a, int m, int n, double **q)
������ aΪ���ֽ�m*n����q�����ش�Q��
���أ�R��   ����a = QR
˵�����㷨����ʩ�������������ο����ߵ���ֵ�㷨��Ӧ�ã�������
****************************************************************************/
static double * qr_fraction(double *a, int m, int n, double **q)//m >= n,������
{
	int i = 0;
	int j = 0;
	int k = 0;               
	//����malloc()�����Լ�free()����Ȼ��ε��þͻ��ڴ�й¶��
	double *Q = (double *)malloc(sizeof(double)*m*n); //Qm*n
    double *R = (double *)malloc(sizeof(double)*n*n); //Rn*n
	memset(R,0,sizeof(double)*n*n);
	for(i = 0; i < n; i++)   //A����n��
	{
		double tmp = 0;
		for(j = 0; j < m; j++)//��A������е�ģ,m��Ԫ��ƽ���ͣ��ٿ���
		{
			tmp += a[n*j + i]*a[n*j + i];   //  i = 0ʱ�� a[0] a[n] a[2*n] ... a[(m-1)*n]
		}
		tmp = sqrt(tmp);//�õ������е�ģ


		R[i*n + i] = tmp;//R[i][i] ��R����ĶԽ�Ԫ
		/////////////////////////////
		//��һ�е�ģ�õ��󣬾Ϳ��Եõ���һ����Q1(Q�ĵ�һ��)
		for(j = 0; j < m; j++)//��A������е�ģ,m��Ԫ��ƽ���ͣ��ٿ���
		{
			Q[n*j + i] = a[n*j + i] / tmp;   //  i = 0ʱ�� a[0] a[n] a[2*n] ... a[(m-1)*n]
		}
		for(j = i + 1; j < n; j++)//
		{
			tmp = 0;
			for(k = 0; k < m; k++)     //R[i][j] = <qi, aj> qi��aj�ڻ� Q��j�У�A��k��
			{
                tmp += Q[n*k + i] * a[n*k + j];
			}
			R[n*i + j] = tmp;   //�õ�R[i][j]
			for(k = 0; k < m; k++)     
			{
                a[n*k + j] = a[n*k + j] - Q[n*k + i] * R[n*i + j];//a[k][j] = a[k][j] - Q[k][i] * R[i][j]
			}
		}
	}
	*q = Q;
	return R;	
}
/*****************************************************************************
static double * up_tria_inv_n_ord(double *t,int n)
������ tָ��n * n��������
���أ� ָ��������ָ��
˵��������������������㷨�����ġ����Ǿ��������һ�ַ�����,��������������һ���ط�ӡˢ���󣬾���ط��ǣ�
      a[i][j] = -1/t[j][j] * (t[j][j] + sum() ,  Ӧ��Ϊa[i][j] = -1/t[j][j] * (t[i][j] + sum() ),
****************************************************************************/
static double * up_tria_inv_n_ord(double *t,int n)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int m = 0;
	double tmp = 0;
	//����malloc()�����Լ�free()����Ȼ��ε��þͻ��ڴ�й¶��
	double *a = (double *)malloc(sizeof(double)*n*n); //an*n
    double *inv = (double *)malloc(sizeof(double)*n*n); //Rn*n
	memset(a,0,sizeof(double)*n*n);
	memset(inv,0,sizeof(double)*n*n);
	for(i = 0; i < n; i++)
	{
		inv[i*n + i] = 1/t[i*n + i];//��inv[i][i] = 1/t[i][i];
	}
	for(i = 0; i < n - 1; i++)//n - 1��,ai(i+1)  (i = 1��n - 1)
	{
		a[i*n + i + 1] = -inv[(i+1)*n + i + 1] * t[i*n + i + 1];//��inv[i][i] = 1/a[i][i];
	}
	m = 2;
	while(m < n)//�ⲿ����Ҫ���濼�ǣ�����ʲô������ʲô
	{
		for(i = 0,j = i + m; i < n - 2; i++)//n - 2��
		{
			tmp = 0;
			for(k = i + 1; k < j; k++)
			{
				tmp += a[i*n + k] * t[k*n + j];
			}
			a[i*n + j] = -inv[j*n + j] * (t[i*n + j] + tmp);//��inv[i][i] = 1/a[i][i];
		}
		m++;
	}
	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			inv[i*n + j] = inv[i*n + i] * a[i*n + j];
		}
	}
	free(a);
	return inv;
}


/*****************************************************************************
double * array_mut(double *A, double *x, int len)
������ Aָ��m*n����xָ��������lenΪ��������
���أ�ָ�룬ָ������y = Ax
****************************************************************************/
static double * array_mut(double *A, double *x, int m, int n)//m * n��
{
	int i = 0;
	int j = 0;
    double *y = (double *)malloc(sizeof(double)*m); //���ᳬ��1000�������һ�����
    
	for(i = 0; i < m; i++)
	{
		y[i] = 0;       
		for(j = 0; j < n; j++)
		{
		  y[i] += A[n*i + j] * x[j]; 
		}
	}
    
	return y;
}

/*****************************************************************************
double * array_trans(double *A, int m, int n)
������ Aָ��m*n����
���أ�ָ�룬ָ��A��ת�þ���
****************************************************************************/
static double * array_trans(double *A, int m, int n)//m * n��
{
	int i = 0;
	int j = 0;
	double *y = (double *)malloc(sizeof(double)*n*m); 
	
	for(i = 0; i < n; i++) //n*m 
	{
		for(j = 0; j < m; j++)
		{
		  y[i*m + j] = A[n*j + i]; 
		}
	}
	return y;
}

/*****************************************************************************
double * array_trans_mut(double *A, double *x, int len)
������ Aָ��m*n����xָ��������lenΪ��������
���أ�ָ�룬ָ������y = A^T * x  ��A��ת�ó���x����
****************************************************************************/
static double * array_trans_mut(double *A, double *x, int m, int n)//m * n��
{
	int i = 0;
	int j = 0;
	double *y = (double *)malloc(sizeof(double)*n); 
	
	for(i = 0; i < n; i++) //n*m * n
	{
		y[i] = 0;
		for(j = 0; j < m; j++)
		{
		  y[i] += A[n*j + i] * x[j]; 
		}
	}
    
	return y;
}


/*****************************************************************************
 A*B��ת��
****************************************************************************/
static double *matrix_trans_mul(double *A, double *B,int order)
{
	double *result = (double *)malloc(sizeof(double) * order * order);
	int i = 0;
	int j = 0;
	int k = 0;
	double tmp = 0;
	for(i = 0; i < order; i++)
	{
		for(j = 0; j < order; j++)
		{
			tmp = 0;
			for(k = 0; k < order; k++)
			{
				//*(result + i*order + j) = (*(A + i*order + k)) * (*(B + j*order + k));
				tmp += (*(A + i*order + k)) * (*(B + j*order + k));
			}
			*(result + i*order + j) = tmp;
		}
		
	}
	return result;
}

// �����A������󣬺������غ�A��������������� 
int brinv(double a[], int n)  
{  
    int *is,*js,i,j,k,l,u,v;  
    double d,p;  
    is = new int[n];  
    js = new int[n];  
    for (k=0; k<=n-1; k++)  
    {  
        d=0.0;  
        for (i=k; i<=n-1; i++)  
        for (j=k; j<=n-1; j++)  
        {  
            l=i*n+j; p=fabs(a[l]);  
            if (p>d) { d=p; is[k]=i; js[k]=j;}  
        }  
        if (d+1.0==1.0)  
        {  
            free(is); free(js); printf("err**not inv\n");  
            return(0);  
        }  
        if (is[k]!=k)  
            for (j=0; j<=n-1; j++)  
            {  
                u=k*n+j; v=is[k]*n+j;  
                p=a[u]; a[u]=a[v]; a[v]=p;  
            }  
        if (js[k]!=k)  
            for (i=0; i<=n-1; i++)  
            {  
                u=i*n+k; v=i*n+js[k];  
                p=a[u]; a[u]=a[v]; a[v]=p;  
            }  
        l=k*n+k;  
        a[l]=1.0/a[l];  
        for (j=0; j<=n-1; j++)  
            if (j!=k)  
            { u=k*n+j; a[u]=a[u]*a[l];}  
        for (i=0; i<=n-1; i++)  
            if (i!=k)  
                for (j=0; j<=n-1; j++)  
        if (j!=k)  
        {  
            u=i*n+j;  
            a[u] -= a[i*n+k]*a[k*n+j];  
        }  
        for (i=0; i<=n-1; i++)  
            if (i!=k)  
            {  
                u=i*n+k;  
                a[u] = -a[u]*a[l];  
            }  
    }  
    for (k=n-1; k>=0; k--)  
    {  
        if (js[k]!=k)  
        for (j=0; j<=n-1; j++)  
        {  
            u=k*n+j; v=js[k]*n+j;  
        p=a[u]; a[u]=a[v]; a[v]=p;  
        }  
        if (is[k]!=k)  
        for (i=0; i<=n-1; i++)  
        {   
            u=i*n+k; v=i*n+is[k];  
            p=a[u]; a[u]=a[v]; a[v]=p;  
        }  
    }  
    free(is); free(js);  
    return(1);  
}  

// �����ĳ˻� C = A.*B  
void brmul(double a[], double b[],int m,int n,int k,double c[])  
{  
    int i,j,l,u;  
    for (i=0; i<=m-1; i++)  
        for (j=0; j<=k-1; j++)  
        {  
            u=i*k+j; c[u]=0;  
            for (l=0; l<=n-1; l++)  
                c[u] += a[i*n+l]*b[l*k+j];  // ����˷���ûʲô��˵��  
        }  
}  


/*****************************************************************************
void polyfit(double *x, double *y, double *z, int len)
���ܣ����������ϵİ˸���ʵ������ĳ�ֵ���
������ x��y��zΪ����ϵ���Բ��
���أ�coefΪ��Բ����
****************************************************************************/
double * polyfit(double *x, double *y, double *z, int len)
{ 
	int i = 0;
	int j = 0;
	int colum = 6;//�þ���������
	double *D = (double *)malloc(sizeof(double)*len*colum); //D len �� colum�У�polyfit���V����
	double *C = (double *)malloc(sizeof(double)*1*len);//��������C
	double *trans_C = (double *)malloc(sizeof(double)*len*1);//��������C��ת��
	double *trans_D = (double *)malloc(sizeof(double)*colum*len);;//D�����ת��
	double *trans_D_mul_D = (double *)malloc(sizeof(double)*colum*colum);//D�����ת�ó���D
	double *trans_D_mul_D_beifen = (double *)malloc(sizeof(double)*colum*colum);//D�����ת�ó���D

	double *trans_D_mul_D_mul_trans_D = (double *)malloc(sizeof(double)*colum*len);//��������D�����ת��

	double danweijuzhen_beifen[36];//����������ص���ָ�룬����ܷ��ؽ���ı�����Ҫ��Ϊָ�룻��Ϊ���飬���ܱ�������Ҫ��Ϊ����

	double *w = (double *)malloc(sizeof(double)*colum*1);

	//���´�������D����,D��ʵΪ����������ʽ�����һ��Ϊ 1
	for(i = 0; i < len; i++) //i��Ӧ��
	{
		D[i*colum + 0] = -y[i]*y[i];//��ӦD����ĵ�һ��
		D[i*colum + 1] = -z[i]*z[i];//��ӦD����ĵڶ���
		D[i*colum + 2] = 2*x[i];//��ӦD����ĵ�����
		D[i*colum + 3] = 2*y[i];//��ӦD����ĵ�����
		D[i*colum + 4] = 2*z[i];//��ӦD����ĵ�����
		D[i*colum + 5] = 1.0;//��ӦD��������һ�� 

	}//����,D�����������
	//���´�����������C
	for(i = 0; i < len; i++) 
	{
		C[i] = x[i] * x[i];
	}
	trans_C = array_trans(C, 1, len);

	trans_D = array_trans(D, len, colum);//D�����ת��
	//trans_D_mul_D = matrix_mul( trans_D, colum, len, D, colum);//�ó˷��㷨����ȷ

	//trans_D_mul_D��ʾDT*D����D�����ת�ó���D����
	brmul( trans_D, D, colum, len, colum, trans_D_mul_D); 

	//v_trans_D_mul_D = inv(trans_D_mul_D, colum);//����������㷨����ȷ

	for(i=0;i<colum;i++)
		for(j=0;j<colum;j++)
			trans_D_mul_D_beifen[i*colum+j] = trans_D_mul_D[i*colum+j];

	//trans_D_mul_D��ʾ(DT*D)����������
	brinv(trans_D_mul_D, colum);//�������֮��ͨ��ԭ�������������Ƿ���ڵ�λ��������֤����������ȷ
	brmul(trans_D_mul_D_beifen, trans_D_mul_D,colum,colum,colum,danweijuzhen_beifen) ;//�ó˷���ȷ

	//��ӡ��λ����
	for (i=0; i<=5; i++)  
        {  
            for (j=0; j<=5; j++)  
                //printf("%13.3f",danweijuzhen_beifen[6*i+j]);  
            //printf("\n");  
				;
        } 
	
	//(DT*D)���������� * D��ת�þ��� ������ trans_D_mul_D_mul_trans_D
	brmul( trans_D_mul_D, trans_D, colum, colum, len, trans_D_mul_D_mul_trans_D); 

	//trans_D_mul_D_mul_trans_D * ����C��ת������w�ĳ�ֵ
	brmul( trans_D_mul_D_mul_trans_D,trans_C, colum, len, 1, w );
	
	//printf("\n"); 
	//printf("\ below is w \n");  

	for (i=0; i<=5; i++)  
        {  
          
            //printf("%13.4f",w[i]);  
            //printf("\n");  
        }

	free(D);
	free(C);
	free(trans_C);
	free(trans_D);
	free(trans_D_mul_D);
	//free(danweijuzhen_beifen);
	free(trans_D_mul_D_beifen);
	free(trans_D_mul_D_mul_trans_D);
	return 	w;
}



/*****************************************************************************
void polyfit_new(double *x1, double *y1, double *z1, int len)
���ܣ����������ϵİ˸���ʵ������ĸ������
������ x,yΪ����ϵ������
���أ�uΪ��������Ĳ�ֵ
****************************************************************************/
double * polyfit_new(double *x1, double *y1, double *z1, int len1)
{ 
	int i = 0;
	int j = 0;
	int colum1 = 6;//�þ���������
	double *H = (double *)malloc(sizeof(double)*len1*colum1); //H len �� colum�У�polyfit���V����
	double *Y = (double *)malloc(sizeof(double)*1*len1);//��������Y
	//double H[48]={0};
	//double Y[8]={0};
	double *trans_Y = (double *)malloc(sizeof(double)*len1*1);//��������Y��ת��
	double *trans_H = (double *)malloc(sizeof(double)*colum1*len1);;//H�����ת��
	double *trans_H_mul_H = (double *)malloc(sizeof(double)*colum1*colum1);//H�����ת�ó���H
	double *trans_H_mul_H_mul_trans_H = (double *)malloc(sizeof(double)*colum1*len1);;//��������H�����ת��
	double *trans_H_mul_H_beifen = (double *)malloc(sizeof(double)*colum1*colum1);//H�����ת�ó���H
	double danweijuzhen_beifen[36];//����������ص���ָ�룬����ܷ��ؽ���ı�����Ҫ��Ϊָ�룻��Ϊ���飬���ܱ�������Ҫ��Ϊ����


	double *u = (double *)malloc(sizeof(double)*colum1*1);

	//���´�������H����,H��ʵΪ�ſ˱Ⱦ������һ��Ϊ 2R
	//���¹�����º���ſ˱Ⱦ���H
	for(i=0;i<len1;i++)
			for(j=0;j<6;j++)
			{
				switch(j)
				{
				case 0:
					H[i*6 + j] = 2*(x1[i] - x_chu);
					break;
				case 1:
					H[i*6 + j] = 2*A*A*(y1[i] - y_chu);
					break;
				case 2:
					H[i*6 + j] = 2*B*B*(z1[i] - z_chu);
					break;
				case 3:
					H[i*6 + j] = -2*A*(y1[i] - y_chu)*(y1[i] - y_chu);
					break;
				case 4:
					H[i*6 + j] = -2*B*(z1[i] - z_chu)*(z1[i] - z_chu);
					break;
				default:
					H[i*6 + j] = 2*R;
					break;
				}
			}
	//���¹�����º�ĺ���ֵY
	for(i=0;i<len1;i++)
		Y[i] = pow( (x1[i]-x_chu) ,2) + A*A*pow( (y1[i]-y_chu) ,2) + B*B*pow( (z1[i]-z_chu) ,2) - pow(R,2);
	

	trans_Y = array_trans(Y, 1, len1);

	trans_H = array_trans(H, len1, colum1);//H�����ת��

	//trans_H_mul_H �� H�����ת�ó���H
	brmul( trans_H, H, colum1, len1, colum1, trans_H_mul_H); 

	for(i=0;i<colum1;i++)
		for(j=0;j<colum1;j++)
			trans_H_mul_H_beifen[i*colum1+j] = trans_H_mul_H[i*colum1+j];

	brinv(trans_H_mul_H, colum1);//���������֤������Ƿ���ȷ

	//ͨ����˽���Ƿ�Ϊ��λ��������֤������Ƿ���ȷ
	brmul(trans_H_mul_H_beifen, trans_H_mul_H,colum1,colum1,colum1,danweijuzhen_beifen) ;//�ó˷���ȷ
	
 
	//printf("\ below is unit matrix \n"); 
	//printf("\n");

	for (i=0; i<=5; i++)  
        {  
            for (j=0; j<=5; j++)  
                //printf("%13.4f",danweijuzhen_beifen[6*i+j]);  
            //printf("\n");  
				;
        }

	//(HT*H���������� * H��ת�þ��� ������ trans_H_mul_H_mul_trans_H
	brmul( trans_H_mul_H, trans_H, colum1, colum1, len1, trans_H_mul_H_mul_trans_H); 

	//��������delta u
	brmul( trans_H_mul_H_mul_trans_H,trans_Y, colum1, len1, 1, u );
	
	//printf("\n"); 
	//printf("\ below is u \n");  

	for (i=0; i<=5; i++)  
        {  
          
            //printf("%13.4f",u[i]);  
            //printf("\n");  
        }

	free(trans_Y);
	free(trans_H);
	free(trans_H_mul_H);
	free(trans_H_mul_H_beifen);
	return 	u;
}


int main(void)
{
	/*
	//ǰ��������Ϊ���ֵ����Сֵ
	//����12������Ϊ��ֵ
	double  data_x[12]={337, -277, -126, -171, -158, -186, 157, 61, -264, -165, -163, -150};
	double  data_y[12]={247, -125, 355, -473, -196, -323, -416, -432, 26, 184, -411, -466};
	double  data_z[12]={-80, -322, 17, 113, 409, -331, -323, -327, -311, -300, 253, -141};
	*/

	//����Ŵ���������
	short *mag = (short *)malloc(sizeof(short)*(LENGTH/6)*3); //mag_data�洢�����ߵ��ֽڵĴŴ��������ݣ�length/6�У�3�зֱ��ʾX��Y��Z

	//���¶���ϵ��������coef_new=coef+delta_u
	double  *coef = (double *)malloc(sizeof(double)*6*1);//��������ĳ�ʼֵ
	double  *coef_new = (double *)malloc(sizeof(double)*6*1);//����������������ֵ
	double  *delta_u = (double *)malloc(sizeof(double)*6*1);//��������Ĳ�ֵ

	//��txt�ĵ��ж�ȡ�Ŵ���������,����short�����ݱ�����mag_data
	read_data();
	//��x��y��z���������ÿ10�����ƽ��ֵ
	average_data();
	//�ҳ����ֵ����Сֵ
	select_data();
	//��ʼ��Ҫ������ϵ�����
	init_data();
    //��һ�����
	coef = polyfit(fit_x, fit_y, fit_z, FIT_LEN);//����������Բ�����ĳ�ֵ
	printf("\n"); 
	//std::cout<<coef[0]<<" "<<coef[1]<<" "<<coef[2]<<" "<<coef[3]<<" "<<coef[4]<<" "<<coef[5]<<" "<<std::endl;
	printf("The initial result:\n"); 
	//����Ϊ���ι��Ƶõ��������ֵ����
    A = sqrt(coef[0]);
	B = sqrt(coef[1]);
	x_chu = coef[2];
	y_chu = coef[3]/coef[0];
	z_chu = coef[4]/coef[1];
	R = sqrt(coef[5] + A*A*y_chu*y_chu + B*B*z_chu*z_chu + x_chu*x_chu);
	std::cout<<" x_chu = "<< x_chu << " y_chu = " << y_chu << " z_chu = " << z_chu << " A = " << A << " B = " << B <<" R = "<< R << std::endl;
	
	//���������ݽ��е���
	for(int i=0;i<ITERATION;i++)
	{
		update_data();
		cnt_update++;//����������1
		//���´������ݺ󣬽����ٴ���ϣ�����������deltaֵ
		delta_u = polyfit_new(fit_x, fit_y, fit_z, FIT_LEN);
		printf("\n");
		printf("The %d iteration:\n",cnt_update); 
		std::cout<<" delta_x = "<< delta_u[0] <<" delta_y = "<< delta_u[1] <<" delta_z = "<< delta_u[2] <<" delta_A = "<< delta_u[3] <<" delta_B = "<< delta_u[4] <<" delta_R = "<< delta_u[5] <<std::endl; 
		//����Ϊ���ε����õ��������ֵ����
		//�õ������������ֵ������֮ǰ�ĳ�ֵ
		A = A + delta_u[3];
		B = B + delta_u[4];
		R = R + delta_u[5];
		x_chu = x_chu + delta_u[0];
		y_chu = y_chu + delta_u[1];
		z_chu = z_chu + delta_u[2];
		std::cout<<" x_new = "<< x_chu << " y_new = " << y_chu << " z_new = " << z_chu << " A = " << A << " B = " << B <<" R = "<< R << std::endl;
	}

	return 0 ;
}
