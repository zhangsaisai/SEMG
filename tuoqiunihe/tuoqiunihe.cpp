/*===========================================================================*/
//作用：椭球拟合（磁传感器三轴标定、校准）
//创建：张赛赛 @ 2016-03-28
//修改：张赛赛 @ 2016-03-28
/*===========================================================================*/
//以下为椭球拟合的基本原型，参见《基于椭球曲面拟合的三维磁罗盘误差补偿算法——朱建良等》-《中国惯性技术学报》
/*1.首先根据闭合形式解求出椭球拟合的初值参数估计
//2.采用最小二乘法或者总体最小二乘法计算误差参数，进而根据估计参数和误差参数得出准确参数。
//3.若误差参数达不到要求，则将2中计算得到的准确参数作为初值参数，进行牛顿迭代；直到得出准确参数。*/	
//参数说明：
//椭球的初始中心点坐标x_chu、y_chu、z_chu初始化为（0，0，0）
//椭球的三轴表示为a、b、c，A=a/b  B=a/c  R=a ,A\B\R均初始化为1
/*===========================================================================*/

#include "stdlib.h" 
#include "string.h" 
#include "math.h"
#include "stdio.h" 
#include <iostream> 

using namespace std;

#define LENGTH 2016//2016个磁传感器数据字节
#define ITERATION 3//求解椭球时的迭代次数
#define FIT_LEN  12//用FIT_LEN组数据进行椭球拟合

double  A=1;//椭球的初值参数
double  B=1;
double  R=1;
double  x_chu=0;
double  y_chu=0;
double  z_chu=0;

double  A_new=1;//椭球的更新参数
double  B_new=1;
double  R_new=1;
double  x_new=0;
double  y_new=0;
double  z_new=0;

//malloc的返回类型是void，需要在malloc之前进行强制转换(short ((*)[3]))
//short (*mag_data)[3] = (short ((*)[3]))malloc(sizeof(short)*(LENGTH/6)*3); //mag_data存储包含高低字节的磁传感器数据，length/6行，3列分别表示X、Y、Z
//double (*data)[3] = (double ((*)[3]))malloc(sizeof(double)*(LENGTH/6/10)*3); //data存储对mag_data中的每10个数据求平均的均值
//double *data_x = (double *)malloc(sizeof(double)*(LENGTH/6/10)); //保存求完平均后x轴的数据
//double *data_y = (double *)malloc(sizeof(double)*(LENGTH/6/10)); //保存求完平均后y轴的数据
//double *data_z = (double *)malloc(sizeof(double)*(LENGTH/6/10)); //保存求完平均后z轴的数据
short mag_data[LENGTH/6][3];//mag_data存储包含高低字节的磁传感器数据，length/6行，3列分别表示X、Y、Z
double data[LENGTH/6/10][3];//data存储对mag_data中的每10个数据求平均的均值
double data_x[LENGTH/6/10];//保存求完平均后x轴的数据
double data_y[LENGTH/6/10];//保存求完平均后y轴的数据
double data_z[LENGTH/6/10];//保存求完平均后z轴的数据
double fit_x[FIT_LEN];//椭球拟合时用到的12组值
double fit_y[FIT_LEN];
double fit_z[FIT_LEN];
int cnt_update = 0;//当前椭球迭代更新到第几次，初始值为0

unsigned char txt_data;//保存从txt文件中读取的磁传感器数据;存储为全局变量,销毁时不会出现问题
/*****************************************************************************
read_data()
功能：从txt文件中读取传感器数据，并将其保存在二维全局数组中
参数：txt文件中磁传感器的数据长度(length行磁数据)
返回：磁传感器数据的二维数组(十进制)
****************************************************************************/
int read_data()
{
	FILE *fp;
	unsigned int i=0,j=0,len=0;
    unsigned int file_size;//file_size表示文件大小

	unsigned char *raw_data = (unsigned char *)malloc(sizeof(unsigned char)*(LENGTH)); //mag_data存储从txt中读取到的原始磁传感器数据;
	
	if((fp=fopen("D:/kuaipan/SEMG/libusb/USB_DriverTest/sensordata.txt","r"))==NULL)//注意要使用转义字符，而不是目录中的\字符
	{
		printf("cannot open file");
		return -1;
	}
	else
		printf("file has been opened\n");

	fseek( fp, 0, SEEK_END );//定位文件指针到文件末尾，成功返回0，不成功返回-1；
	file_size = ftell( fp );//ftell：获得当前文件指针到文件首的大小
	fseek( fp, 0, SEEK_SET );//再定位文件指针到文件头

	while(!feof(fp))
	{
		fscanf(fp,"%x",&txt_data);
		if(len%2)
			raw_data[len/2] = txt_data;//不保存序号，只保存磁传感数据
		len++;
		//if(len==4031)
		//	printf("the second last\n");
		//if(len==4032)
		//	printf("the first last\n");
	}
	for(i=0;i<len/12;i++)//raw_data的数据维度是i/2,共有i/4个short型数据，有i/12组x、y、z传感数据
		for(j=0;j<6;j=j+2)
			//mag_data的每一行是一组磁传感器数据
			mag_data[i][j/2] =  (short) ((raw_data[i*6+j] << 8) + raw_data[i*6+j+1]) ;//每6个字节是一组x、y、z，所以i*6

	fclose(fp);   
	free(raw_data);
    return 0;
}


/*****************************************************************************
average_data()
功能：从二维全局数组mag_data中的三轴传感数据每10个进行求平均
参数：无
返回：无
****************************************************************************/
int average_data()
{
	int temp,sum,i;
	//每10个传感数据求平均
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
功能：暴力方法遍历一遍数组，比较2*N次求出最大值和最小值,并输出索引号
参数：pArr:数组名； nLength:数组长度; k:数组最大值的索引  l:数组最小值的索引
返回：无
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
功能：选取12组数据（6组最值和6组随机值）进行椭球拟合
参数： 无
返回：无
****************************************************************************/
int select_data()
{
	int x_index_max,x_index_min,y_index_max,y_index_min,z_index_max,z_index_min;//保存各轴最大值最小值的索引
	double temp;//用于保存调整最大值最小值位置时的临时数据

	//data[][0]、data[][1]、data[][2]对应x、y、z轴的数据，分别找出各轴数据的最大值和最小值
	FindMaxAndMin(data_x, LENGTH/6/10, x_index_max, x_index_min);
	FindMaxAndMin(data_y, LENGTH/6/10, y_index_max, y_index_min);
	FindMaxAndMin(data_z, LENGTH/6/10, z_index_max, z_index_min);

	//将x,y,z各轴对应的最大值和最小值，调整到data数组中的前六组位置
	//x取最大值时
	temp = data[0][0];
	data[0][0] = data[x_index_max][0];
	data[x_index_max][0] = temp;
	temp = data[0][1];
	data[0][1] = data[x_index_max][1];
	data[x_index_max][1] = temp;
	temp = data[0][2];
	data[0][2] = data[x_index_max][2];
	data[x_index_max][2] = temp;

	//x取最小值时
	temp = data[1][0];
	data[1][0] = data[x_index_min][0];
	data[x_index_min][0] = temp;
	temp = data[1][1];
	data[1][1] = data[x_index_min][1];
	data[x_index_min][1] = temp;
	temp = data[1][2];
	data[1][2] = data[x_index_min][2];
	data[x_index_min][2] = temp;

	//y取最大值时
	temp = data[2][0];
	data[2][0] = data[y_index_max][0];
	data[y_index_max][0] = temp;
	temp = data[2][1];
	data[2][1] = data[y_index_max][1];
	data[y_index_max][1] = temp;
	temp = data[2][2];
	data[2][2] = data[y_index_max][2];
	data[y_index_max][2] = temp;

	//y取最小值时
	temp = data[3][0];
	data[3][0] = data[y_index_min][0];
	data[y_index_min][0] = temp;
	temp = data[3][1];
	data[3][1] = data[y_index_min][1];
	data[y_index_min][1] = temp;
	temp = data[3][2];
	data[3][2] = data[y_index_min][2];
	data[y_index_min][2] = temp;

	//z取最大值时
	temp = data[4][0];
	data[4][0] = data[z_index_max][0];
	data[z_index_max][0] = temp;
	temp = data[4][1];
	data[4][1] = data[z_index_max][1];
	data[z_index_max][1] = temp;
	temp = data[4][2];
	data[4][2] = data[z_index_max][2];
	data[z_index_max][2] = temp;

	//z取最小值时
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
功能：选取FIT_LEN组数据（6组最值和之后的FIT_LEN-6组值）进行椭球拟合，得到椭球参数的初始值
参数： 无
返回：无
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
功能：前六组值为各轴的最大值最小值，选取6组随机值进行椭球拟合，并迭代更新这六组随机值
参数： 无
返回：无
****************************************************************************/
int update_data()
{
	int i = 0;
	//更新后六组数据
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
功能：两矩阵相加
参数：U V为m*n矩阵
返回：result为U+V；
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
功能：两矩阵相减
参数：U V为m*n矩阵
返回：result为U-V；
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
参数： a为待分解m*n矩阵，q用来回传Q阵
返回：R阵   满足a = QR
说明：算法采用施密特正交法，参考《高等数值算法与应用（三）》
****************************************************************************/
static double * qr_fraction(double *a, int m, int n, double **q)//m >= n,列满秩
{
	int i = 0;
	int j = 0;
	int k = 0;               
	//调用malloc()必须自己free()，不然多次调用就会内存泄露的
	double *Q = (double *)malloc(sizeof(double)*m*n); //Qm*n
    double *R = (double *)malloc(sizeof(double)*n*n); //Rn*n
	memset(R,0,sizeof(double)*n*n);
	for(i = 0; i < n; i++)   //A矩阵共n列
	{
		double tmp = 0;
		for(j = 0; j < m; j++)//求A矩阵各列的模,m个元素平方和，再开方
		{
			tmp += a[n*j + i]*a[n*j + i];   //  i = 0时， a[0] a[n] a[2*n] ... a[(m-1)*n]
		}
		tmp = sqrt(tmp);//得到矩阵列的模


		R[i*n + i] = tmp;//R[i][i] 即R矩阵的对角元
		/////////////////////////////
		//第一列的模得到后，就可以得到归一化的Q1(Q的第一列)
		for(j = 0; j < m; j++)//求A矩阵各列的模,m个元素平方和，再开方
		{
			Q[n*j + i] = a[n*j + i] / tmp;   //  i = 0时， a[0] a[n] a[2*n] ... a[(m-1)*n]
		}
		for(j = i + 1; j < n; j++)//
		{
			tmp = 0;
			for(k = 0; k < m; k++)     //R[i][j] = <qi, aj> qi与aj内积 Q的j列，A的k列
			{
                tmp += Q[n*k + i] * a[n*k + j];
			}
			R[n*i + j] = tmp;   //得到R[i][j]
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
参数： t指向n * n上三角阵
返回： 指向逆矩阵的指针
说明：上三角阵求逆具体算法见论文《三角矩阵求逆的一种方法》,不过论文里面有一个地方印刷错误，具体地方是：
      a[i][j] = -1/t[j][j] * (t[j][j] + sum() ,  应该为a[i][j] = -1/t[j][j] * (t[i][j] + sum() ),
****************************************************************************/
static double * up_tria_inv_n_ord(double *t,int n)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int m = 0;
	double tmp = 0;
	//调用malloc()必须自己free()，不然多次调用就会内存泄露的
	double *a = (double *)malloc(sizeof(double)*n*n); //an*n
    double *inv = (double *)malloc(sizeof(double)*n*n); //Rn*n
	memset(a,0,sizeof(double)*n*n);
	memset(inv,0,sizeof(double)*n*n);
	for(i = 0; i < n; i++)
	{
		inv[i*n + i] = 1/t[i*n + i];//即inv[i][i] = 1/t[i][i];
	}
	for(i = 0; i < n - 1; i++)//n - 1项,ai(i+1)  (i = 1，n - 1)
	{
		a[i*n + i + 1] = -inv[(i+1)*n + i + 1] * t[i*n + i + 1];//即inv[i][i] = 1/a[i][i];
	}
	m = 2;
	while(m < n)//这部分需要认真考虑，先算什么，再算什么
	{
		for(i = 0,j = i + m; i < n - 2; i++)//n - 2项
		{
			tmp = 0;
			for(k = i + 1; k < j; k++)
			{
				tmp += a[i*n + k] * t[k*n + j];
			}
			a[i*n + j] = -inv[j*n + j] * (t[i*n + j] + tmp);//即inv[i][i] = 1/a[i][i];
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
参数： A指向m*n矩阵，x指向向量，len为向量长度
返回：指针，指向向量y = Ax
****************************************************************************/
static double * array_mut(double *A, double *x, int m, int n)//m * n型
{
	int i = 0;
	int j = 0;
    double *y = (double *)malloc(sizeof(double)*m); //不会超过1000个点拟合一个点的
    
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
参数： A指向m*n矩阵
返回：指针，指向A的转置矩阵
****************************************************************************/
static double * array_trans(double *A, int m, int n)//m * n型
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
参数： A指向m*n矩阵，x指向向量，len为向量长度
返回：指针，指向向量y = A^T * x  即A的转置乘以x向量
****************************************************************************/
static double * array_trans_mut(double *A, double *x, int m, int n)//m * n型
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
 A*B的转置
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

// 求矩阵A的逆矩阵，函数返回后A保存其自身逆矩阵 
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

// 求矩阵的乘积 C = A.*B  
void brmul(double a[], double b[],int m,int n,int k,double c[])  
{  
    int i,j,l,u;  
    for (i=0; i<=m-1; i++)  
        for (j=0; j<=k-1; j++)  
        {  
            u=i*k+j; c[u]=0;  
            for (l=0; l<=n-1; l++)  
                c[u] += a[i*n+l]*b[l*k+j];  // 矩阵乘法，没什么好说的  
        }  
}  


/*****************************************************************************
void polyfit(double *x, double *y, double *z, int len)
功能：根据椭球上的八个点实现椭球的初值拟合
参数： x，y，z为待拟合的椭圆点
返回：coef为椭圆参数
****************************************************************************/
double * polyfit(double *x, double *y, double *z, int len)
{ 
	int i = 0;
	int j = 0;
	int colum = 6;//该矩阵共有六列
	double *D = (double *)malloc(sizeof(double)*len*colum); //D len 行 colum列，polyfit里的V矩阵
	double *C = (double *)malloc(sizeof(double)*1*len);//生成向量C
	double *trans_C = (double *)malloc(sizeof(double)*len*1);//生成向量C的转置
	double *trans_D = (double *)malloc(sizeof(double)*colum*len);;//D矩阵的转置
	double *trans_D_mul_D = (double *)malloc(sizeof(double)*colum*colum);//D矩阵的转置乘以D
	double *trans_D_mul_D_beifen = (double *)malloc(sizeof(double)*colum*colum);//D矩阵的转置乘以D

	double *trans_D_mul_D_mul_trans_D = (double *)malloc(sizeof(double)*colum*len);//逆矩阵乘以D矩阵的转置

	double danweijuzhen_beifen[36];//如果函数返回的是指针，则接受返回结果的变量就要设为指针；若为数组，接受变量就需要设为数组

	double *w = (double *)malloc(sizeof(double)*colum*1);

	//以下代码生成D矩阵,D其实为范德蒙行列式，最后一列为 1
	for(i = 0; i < len; i++) //i对应行
	{
		D[i*colum + 0] = -y[i]*y[i];//对应D矩阵的第一列
		D[i*colum + 1] = -z[i]*z[i];//对应D矩阵的第二列
		D[i*colum + 2] = 2*x[i];//对应D矩阵的第三列
		D[i*colum + 3] = 2*y[i];//对应D矩阵的第四列
		D[i*colum + 4] = 2*z[i];//对应D矩阵的第五列
		D[i*colum + 5] = 1.0;//对应D矩阵的最后一列 

	}//至此,D矩阵生成完毕
	//以下代码生成向量C
	for(i = 0; i < len; i++) 
	{
		C[i] = x[i] * x[i];
	}
	trans_C = array_trans(C, 1, len);

	trans_D = array_trans(D, len, colum);//D矩阵的转置
	//trans_D_mul_D = matrix_mul( trans_D, colum, len, D, colum);//该乘法算法不正确

	//trans_D_mul_D表示DT*D，即D矩阵的转置乘以D矩阵
	brmul( trans_D, D, colum, len, colum, trans_D_mul_D); 

	//v_trans_D_mul_D = inv(trans_D_mul_D, colum);//该求逆矩阵算法不正确

	for(i=0;i<colum;i++)
		for(j=0;j<colum;j++)
			trans_D_mul_D_beifen[i*colum+j] = trans_D_mul_D[i*colum+j];

	//trans_D_mul_D表示(DT*D)矩阵的逆矩阵
	brinv(trans_D_mul_D, colum);//求逆矩阵，之后通过原矩阵乘以逆矩阵是否等于单位矩阵，来验证逆矩阵求解正确
	brmul(trans_D_mul_D_beifen, trans_D_mul_D,colum,colum,colum,danweijuzhen_beifen) ;//该乘法正确

	//打印单位矩阵
	for (i=0; i<=5; i++)  
        {  
            for (j=0; j<=5; j++)  
                //printf("%13.3f",danweijuzhen_beifen[6*i+j]);  
            //printf("\n");  
				;
        } 
	
	//(DT*D)矩阵的逆矩阵 * D的转置矩阵 保存在 trans_D_mul_D_mul_trans_D
	brmul( trans_D_mul_D, trans_D, colum, colum, len, trans_D_mul_D_mul_trans_D); 

	//trans_D_mul_D_mul_trans_D * 矩阵C的转置生成w的初值
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
功能：根据椭球上的八个点实现椭球的更新拟合
参数： x,y为待拟合的椭球点
返回：u为椭球参数的差值
****************************************************************************/
double * polyfit_new(double *x1, double *y1, double *z1, int len1)
{ 
	int i = 0;
	int j = 0;
	int colum1 = 6;//该矩阵共有六列
	double *H = (double *)malloc(sizeof(double)*len1*colum1); //H len 行 colum列，polyfit里的V矩阵
	double *Y = (double *)malloc(sizeof(double)*1*len1);//生成向量Y
	//double H[48]={0};
	//double Y[8]={0};
	double *trans_Y = (double *)malloc(sizeof(double)*len1*1);//生成向量Y的转置
	double *trans_H = (double *)malloc(sizeof(double)*colum1*len1);;//H矩阵的转置
	double *trans_H_mul_H = (double *)malloc(sizeof(double)*colum1*colum1);//H矩阵的转置乘以H
	double *trans_H_mul_H_mul_trans_H = (double *)malloc(sizeof(double)*colum1*len1);;//逆矩阵乘以H矩阵的转置
	double *trans_H_mul_H_beifen = (double *)malloc(sizeof(double)*colum1*colum1);//H矩阵的转置乘以H
	double danweijuzhen_beifen[36];//如果函数返回的是指针，则接受返回结果的变量就要设为指针；若为数组，接受变量就需要设为数组


	double *u = (double *)malloc(sizeof(double)*colum1*1);

	//以下代码生成H矩阵,H其实为雅克比矩阵，最后一列为 2R
	//以下构造更新后的雅克比矩阵H
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
	//以下构造更新后的函数值Y
	for(i=0;i<len1;i++)
		Y[i] = pow( (x1[i]-x_chu) ,2) + A*A*pow( (y1[i]-y_chu) ,2) + B*B*pow( (z1[i]-z_chu) ,2) - pow(R,2);
	

	trans_Y = array_trans(Y, 1, len1);

	trans_H = array_trans(H, len1, colum1);//H矩阵的转置

	//trans_H_mul_H ： H矩阵的转置乘以H
	brmul( trans_H, H, colum1, len1, colum1, trans_H_mul_H); 

	for(i=0;i<colum1;i++)
		for(j=0;j<colum1;j++)
			trans_H_mul_H_beifen[i*colum1+j] = trans_H_mul_H[i*colum1+j];

	brinv(trans_H_mul_H, colum1);//求逆矩阵，验证逆矩阵是否正确

	//通过相乘结果是否为单位矩阵，来验证逆矩阵是否正确
	brmul(trans_H_mul_H_beifen, trans_H_mul_H,colum1,colum1,colum1,danweijuzhen_beifen) ;//该乘法正确
	
 
	//printf("\ below is unit matrix \n"); 
	//printf("\n");

	for (i=0; i<=5; i++)  
        {  
            for (j=0; j<=5; j++)  
                //printf("%13.4f",danweijuzhen_beifen[6*i+j]);  
            //printf("\n");  
				;
        }

	//(HT*H矩阵的逆矩阵 * H的转置矩阵 保存在 trans_H_mul_H_mul_trans_H
	brmul( trans_H_mul_H, trans_H, colum1, colum1, len1, trans_H_mul_H_mul_trans_H); 

	//以下生成delta u
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
	//前六组数据为最大值、最小值
	//以下12组数据为初值
	double  data_x[12]={337, -277, -126, -171, -158, -186, 157, 61, -264, -165, -163, -150};
	double  data_y[12]={247, -125, 355, -473, -196, -323, -416, -432, 26, 184, -411, -466};
	double  data_z[12]={-80, -322, 17, 113, 409, -331, -323, -327, -311, -300, 253, -141};
	*/

	//保存磁传感器数据
	short *mag = (short *)malloc(sizeof(short)*(LENGTH/6)*3); //mag_data存储包含高低字节的磁传感器数据，length/6行，3列分别表示X、Y、Z

	//以下定义系数变量，coef_new=coef+delta_u
	double  *coef = (double *)malloc(sizeof(double)*6*1);//椭球参数的初始值
	double  *coef_new = (double *)malloc(sizeof(double)*6*1);//椭球参数迭代后的新值
	double  *delta_u = (double *)malloc(sizeof(double)*6*1);//椭球参数的差值

	//从txt文档中读取磁传感器数据,并将short型数据保存在mag_data
	read_data();
	//将x、y、z各轴的数据每10个求解平均值
	average_data();
	//找出最大值和最小值
	select_data();
	//初始化要进行拟合的数据
	init_data();
    //第一次拟合
	coef = polyfit(fit_x, fit_y, fit_z, FIT_LEN);//这里生成椭圆参数的初值
	printf("\n"); 
	//std::cout<<coef[0]<<" "<<coef[1]<<" "<<coef[2]<<" "<<coef[3]<<" "<<coef[4]<<" "<<coef[5]<<" "<<std::endl;
	printf("The initial result:\n"); 
	//以下为初次估计得到的椭球初值参数
    A = sqrt(coef[0]);
	B = sqrt(coef[1]);
	x_chu = coef[2];
	y_chu = coef[3]/coef[0];
	z_chu = coef[4]/coef[1];
	R = sqrt(coef[5] + A*A*y_chu*y_chu + B*B*z_chu*z_chu + x_chu*x_chu);
	std::cout<<" x_chu = "<< x_chu << " y_chu = " << y_chu << " z_chu = " << z_chu << " A = " << A << " B = " << B <<" R = "<< R << std::endl;
	
	//传感器数据进行迭代
	for(int i=0;i<ITERATION;i++)
	{
		update_data();
		cnt_update++;//迭代次数加1
		//更新传感数据后，进行再次拟合，求解出参数的delta值
		delta_u = polyfit_new(fit_x, fit_y, fit_z, FIT_LEN);
		printf("\n");
		printf("The %d iteration:\n",cnt_update); 
		std::cout<<" delta_x = "<< delta_u[0] <<" delta_y = "<< delta_u[1] <<" delta_z = "<< delta_u[2] <<" delta_A = "<< delta_u[3] <<" delta_B = "<< delta_u[4] <<" delta_R = "<< delta_u[5] <<std::endl; 
		//以下为初次迭代得到的椭球初值参数
		//用迭代后修正后的值来代替之前的初值
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
