#include <stdio.h>
#include <stdlib.h>

#define N 10
typedef int ElemType;
//49,38,65,97,76,13,27
void Merge(ElemType A[],int low,int mid,int high)
{
	ElemType B[N];//Ϊ�˽��Ͳ�������
	int i,j,k;
	for(k=low;k<=high;k++)//����Ԫ�ص�B��
		B[k]=A[k];
	for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++)//�ϲ�������������
	{
		if(B[i]<=B[j])
			A[k]=B[i++];
		else
			A[k]=B[j++];
	}
	while(i<=mid)//�����ʣ��Ԫ�أ����ŷ��뼴��
		A[k++]=B[i++];
	while(j<=high)
		A[k++]=B[j++];
}
//�鲢���������������鲢�����Ƕ���鲢
// 1 3 5 7 9
// 2 4
// 1 2 3 4 5 7 9  ��Ҫ�Ĵ����߼�
void MergeSort(ElemType A[],int low,int high)//�ݹ�ָ�
{
	if(low<high)
	{
		int mid=(low+high)/2;
		MergeSort(A,low,mid);
		MergeSort(A,mid+1,high);
		Merge(A,low,mid,high);
	}
}
void print(int* a)
{
	for(int i=0;i<N;i++)
	{
		printf("%3d",a[i]);
	}
	printf("\n");
}

// �鲢����
int main()
{
	int A[10];
	
	for(int i = 0 ; i < 10 ;i++){
		scanf("%d",&A[i]) ;
	}
	MergeSort(A,0,9);
	print(A);
	system("pause");
}
