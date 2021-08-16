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
	printf("ʵ��6 �����ѹ���洢��ϡ������ת��\n\n") ; 
	printf("������ԭ����Ĳ�����\n");
	printf("����������������� ");
	scanf("%d%d", &M.mu, &M.nu);
	printf("���������Ԫ�أ� ");
	scanf("%d", &M.tu);
	printf("���������Ӧѹ��ֵ��\n");
	printf("a.data \n");
	printf("i j v \n");
	for (int i = 1; i <= M.tu; ++i)
		scanf("%d%d%d", &M.data[i].i, &M.data[i].j, &M.data[i].e);
 
	FastTransposeSMatrix(M, T);
 
	printf("ת�ú�������������Ԫ�������ֱ�Ϊ��\n%d     %d     %d\n\n", T.mu, T.nu, T.tu);
	printf("\n");
	printf("b.data Ϊ \n");
	printf("| i     j     v |\n");
	for (int t = 1; t <= T.tu; ++t)
		printf("| %d     %d     %d |\n", T.data[t].i, T.data[t].j, T.data[t].e);

	return OK;
}
