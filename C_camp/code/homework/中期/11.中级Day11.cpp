#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;//�洢Ԫ�ص���ʼ��ַ
	int TableLen;//Ԫ�ظ���
}SSTable;

void ST_Init(SSTable &ST,int len)
{
	ST.TableLen=len;
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	srand(time(NULL));//��������ɣ�ÿһ��ִ�д���ͻ�õ������10��Ԫ��
	for(i=0;i<ST.TableLen;i++)
	{
		ST.elem[i]=rand()%100;//���ɵ���0-99֮��
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
// 64 94 95 79 69 84 18 22 12 78
// 12 64 94 95 79 69 84 18 22 78
void BubbleSort(ElemType A[],int n)
{
	int i,j;
	bool flag;
	for(i=0;i<n-1;i++)//i�����ʵ�8
	{
		flag=false;
		for(j=n-1;j>i;j--)//����Сֵ�ͷ�����ǰ��
		{
			if(A[j-1]>A[j])
			{
				swap(A[j-1],A[j]);
				flag=true;
			}
		}
		if(false==flag)
			return;
	}
}

void BubbleSort1(ElemType A[], int n)
{
	int i, j,flag;
	for (i=0;i<n-1;i++)//i�ǿ����ж��ٸ�������
	{
		flag = 0;
		for (j = n-1; j>i;j--)//�ڲ���ƱȽϣ�����
		{
			if (A[j - 1] > A[j])
			{
				swap(A[j - 1], A[j]);
				flag = 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
	}
}
// 64 94 95 79 69 84 18 22 12 78
//��64С�ķ�����ߣ���64��ķ����ұ�


// �ڿӷ�����������ʹ�õķ������������Ϊ�ָ�ֵ
int Partition(ElemType A[],int low,int high)
{
	ElemType pivot=A[low];//������ߵ�ֵ�ݴ�����
	while(low<high)
	{
		while(low<high&&A[high]>=pivot)//��high�����ұ��ң��ҵ��ȷָ�ֵС��ѭ������
			--high;
		A[low]=A[high];
		while(low<high&&A[low]<=pivot)//��low������߿�ʼ�ң��ҵ��ȷָ�ֵ�󣬾ͽ���
			++low;
		A[high]=A[low];
	}
	A[low]=pivot;
	return low;
}
//������
int Partition1(int* arr, int left, int right)
{
	int k, i;//k��¼Ҫ����ȷָ�ֵС�����ݵ�λ��
	for (i = left, k = left; i < right; i++)
	{
		if (arr[i] < arr[right])
		{
			swap(arr[k], arr[i]);
			k++;
		}
	}
	swap(arr[k], arr[right]);
	return k;
}
//������
int Partition2(int* arr, int left, int right)
{
	int k, i;
	for (k = i = left;i<right;i++)
	{
		if (arr[i] < arr[right])
		{
			swap(arr[i], arr[k]);
			k++;
		}
	}
	swap(arr[k], arr[right]);
	return k;
}
//�ݹ�ʵ��
void QuickSort(ElemType A[],int low,int high)
{
	if(low<high)
	{
		int pivotpos=Partition(A,low,high);//�ָ����ߵ�Ԫ�ض��ȷָ��ҪС���ұߵıȷָ���
		QuickSort(A,low,pivotpos-1);
		QuickSort(A,pivotpos+1,high);
	}
}

// �������� 
void InsertSort(ElemType A[],int n)
{
	int i,j;
	//24 66 94  2 15 74 28 51 22 18  2
	for(i=2;i<=n;i++)//�����Ԫ�����ڱ����ӵڶ���Ԫ�ؿ�ʼ�ã���ǰ�����
	{
		if(A[i]<A[i-1])
		{
			A[0]=A[i];//�ŵ��ݴ�λ�ã�A[0]�����ݴ棬Ҳ���ڱ�
			for(j=i-1;A[0]<A[j];--j)//�ƶ�Ԫ�أ��ڲ�ѭ���������������е�ÿһ��Ԫ�غ�Ҫ�����Ԫ�رȽ�
				A[j+1]=A[j];
			A[j+1]=A[0];//���ݴ�Ԫ�ز��뵽��Ӧλ��
		}
	}
}
 
 // �۰����
 
void MidInsertSort(ElemType A[],int n)
{
	int i,j,low,high,mid;
	for(i=2;i<=n;i++)
	{
		A[0]=A[i];
		low=1;high=i-1;//low�������еĿ�ʼ��high�������е����
		while(low<=high)//��ͨ�����ֲ����ҵ�������λ��
		{
			mid=(low+high)/2;
			if(A[mid]>A[0])
				high=mid-1;
			else
				low=mid+1;
		}
		for(j=i-1;j>=high+1;--j)
			A[j+1]=A[j];
		A[high+1]=A[0];
	}
} 
int main()
{
	SSTable ST;
	ElemType A[10]={12, 63, 58, 95, 41, 35, 65, 0, 38 ,44};
	ST_Init(ST,10);//��ʼ��
	memcpy(ST.elem,A,sizeof(A));//�ڴ�copy�ӿڣ�����copy�������飬���߸�����ʱ��Ҫ��memcpy

	//ST_print(ST);
	BubbleSort1(ST.elem,10);//ð������
	ST_print(ST);
	QuickSort(ST.elem,0,9);
	ST_print(ST);
   //memcpy(ST.elem+1, A, sizeof(A));
//   	MidInsertSort(ST.elem,10);                     // ������������������� 
//	ST_print(ST);
	ST_print(ST);
 
}
