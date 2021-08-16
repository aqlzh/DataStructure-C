#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1250  
 
#define    OK      1  
#define    ERROR   0  
#define    TRUE    1  
#define    FLASE   0  
 
typedef    int     Status;
typedef    int     ElemType;
 
 
// LZH_Create
 
typedef struct{
	int   i, j;       
	ElemType e;         
}Triple;
 
typedef struct{
	Triple   data[MAXSIZE + 1];        
	int      mu, nu, tu;            
}TSMatrix;
 
Status FastTransposeSMatrix(TSMatrix M, TSMatrix &T)             
{                                                       
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu)
	{
		int col;
		int num[100], cpot[100];
		for (col = 1; col <= M.nu; ++col)
			num[col] = 0;                 
		for (int t = 1; t <= M.tu; ++t)
		
			++num[M.data[t].j];         
		cpot[1] = 1;
		for (col = 2; col <= M.nu; ++col)
			cpot[col] = cpot[col - 1] + num[col - 1];        
		int q;
		for (int p = 1; p <= M.tu; ++p)
		{
			
			col = M.data[p].j;
			q = cpot[col];
			T.data[q].i = M.data[p].j;
			T.data[q].j = M.data[p].i;
			T.data[q].e = M.data[p].e;
			++cpot[col];
		}  
	} 
	return OK;
}//FastTransposeSMatrix  
 
Status main()
{
	TSMatrix M;
	TSMatrix T;
	printf("实验6 矩阵的压缩存储：稀疏矩阵的转置\n\n") ; 
	printf("请输入原矩阵的参数：\n");
	printf("矩阵的行数、列数： ");
	scanf("%d%d", &M.mu, &M.nu);
	printf("请输入非零元素： ");
	scanf("%d", &M.tu);
	printf("输入各个对应压缩值：\n");
	printf("a.data \n");
	printf("i j v \n");
	for (int i = 1; i <= M.tu; ++i)
		scanf("%d%d%d", &M.data[i].i, &M.data[i].j, &M.data[i].e);
 
	FastTransposeSMatrix(M, T);
 
	printf("转置后行数、列数、元素总数分别为：\n%d     %d     %d\n\n", T.mu, T.nu, T.tu);
	printf("\n");
	printf("b.data 为 \n");
	printf("| i     j     v |\n");
	for (int t = 1; t <= T.tu; ++t)
		printf("| %d     %d     %d |\n", T.data[t].i, T.data[t].j, T.data[t].e);

	return OK;
}
