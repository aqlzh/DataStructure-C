#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int TableLen;
}SSTable;

void ST_Init(SSTable &ST,int len)//����ռ䣬���������������
{
	ST.TableLen=len;
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	srand(time(NULL));
	for(i=0;i<ST.TableLen;i++)
	{
		ST.elem[i]=rand()%100;
	}
}
void ST_print(SSTable ST)
{
	for(int i=0;i<ST.TableLen;i++)
	{
		printf("%3d",ST.elem[i]);
	}
	printf("\n");
}
void swap(ElemType &a,ElemType &b)
{
	ElemType tmp;
	tmp=a;
	a=b;
	b=tmp;
}
void SelectSort(ElemType A[],int n)
{
	int i,j,min;//min��¼��С��Ԫ�ص��±�
	for(i=0;i<n-1;i++)//������Ϊ8
	{
		min=i;
		for(j=i+1;j<n;j++)//j������Ϊ9
		{
			if(A[j]<A[min])
				min=j;
		}
		if(min!=i)
		{
			swap(A[i],A[min]);
		}
	}
}
//����ĳ�����׽ڵ�
void AdjustDown(ElemType A[],int k,int len)
{
	int i;
	A[0]=A[k];
	for(i=2*k;i<=len;i*=2)
	{
		if(i<len&&A[i]<A[i+1])//���ӽڵ������ӽڵ�Ƚϴ�С
			i++;
		if(A[0]>=A[i])
			break;
		else{
			A[k]=A[i];
			k=i;
		}
	}
	A[k]=A[0];
}
//������ȥ��ʾ��   ��ν���
void BuildMaxHeap(ElemType A[],int len)
{
	for(int i=len/2;i>0;i--)
	{
		AdjustDown(A,i,len);
	}
}
void HeapSort(ElemType A[],int len)
{
	int i;
	BuildMaxHeap(A,len);//�����󶥶�
	for(i=len;i>1;i--)
	{
		swap(A[i],A[1]);
		AdjustDown(A,1,i-1);
	}
}
//��������
void AdjustDown1(ElemType A[], int k, int len)
{
	int dad = k;
	int son = 2 * dad + 1; //�����±�
	while (son<=len)
	{
		if (son + 1 <= len && A[son] < A[son + 1])//������û���Һ��ӣ��Ƚ����Һ���ѡ���
		{
			son++;
		}
		if (A[son] > A[dad])//�ȽϺ��Ӻ͸���
		{
			swap(A[son], A[dad]);
			dad = son;
			son = 2 * dad + 1;
		}
		else {
			break;
		}
	}
}
void HeapSort1(ElemType A[], int len)
{
	int i;
	//�����󶥶�
	for (i = len / 2; i >= 0; i--)
	{
		AdjustDown1(A, i, len);
	}
	swap(A[0], A[len]);//�����������������һ��Ԫ��
	for (i = len - 1; i > 0; i--)
	{
		AdjustDown1(A, 0, i);//ʣ��Ԫ�ص���Ϊ�����
		swap(A[0], A[i]);
	}
}

 
//ѡ�������������
int main()
{
	SSTable ST;
	//ElemType A[10]={ 12, 63, 58, 95, 41, 35, 65, 0, 38 ,44};
	ElemType A[10] ;
	for(int i = 0 ; i < 10 ;i++){
		scanf("%d",&A[i]) ;
	}
	
	ST_Init(ST,10);//��ʼ��
	memcpy(ST.elem,A,sizeof(A));

	SelectSort(ST.elem,10);
	ST_print(ST);
	 
	HeapSort1(ST.elem,9);//����Ԫ�ز�������
	ST_print(ST);
 
}
