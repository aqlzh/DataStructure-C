#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;//存储元素的起始地址
	int TableLen;//元素个数
}SSTable;

void ST_Init(SSTable &ST,int len)
{
	ST.TableLen=len;
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	srand(time(NULL));//随机数生成，每一次执行代码就会得到随机的10个元素
	for(i=0;i<ST.TableLen;i++)
	{
		ST.elem[i]=rand()%100;//生成的是0-99之间
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
	for(i=0;i<n-1;i++)//i最多访问到8
	{
		flag=false;
		for(j=n-1;j>i;j--)//把最小值就放在最前面
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
	for (i=0;i<n-1;i++)//i是控制有多少个有序了
	{
		flag = 0;
		for (j = n-1; j>i;j--)//内层控制比较，交换
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
//比64小的放在左边，比64大的放在右边


// 挖坑法，王道书上使用的方法，最左边作为分割值
int Partition(ElemType A[],int low,int high)
{
	ElemType pivot=A[low];//把最左边的值暂存起来
	while(low<high)
	{
		while(low<high&&A[high]>=pivot)//让high从最右边找，找到比分割值小，循环结束
			--high;
		A[low]=A[high];
		while(low<high&&A[low]<=pivot)//让low从最左边开始找，找到比分割值大，就结束
			++low;
		A[high]=A[low];
	}
	A[low]=pivot;
	return low;
}
//交换法
int Partition1(int* arr, int left, int right)
{
	int k, i;//k记录要放入比分割值小的数据的位置
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
//交换法
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
//递归实现
void QuickSort(ElemType A[],int low,int high)
{
	if(low<high)
	{
		int pivotpos=Partition(A,low,high);//分割点左边的元素都比分割点要小，右边的比分割点大
		QuickSort(A,low,pivotpos-1);
		QuickSort(A,pivotpos+1,high);
	}
}

// 插入排序 
void InsertSort(ElemType A[],int n)
{
	int i,j;
	//24 66 94  2 15 74 28 51 22 18  2
	for(i=2;i<=n;i++)//第零个元素是哨兵，从第二个元素开始拿，往前面插入
	{
		if(A[i]<A[i-1])
		{
			A[0]=A[i];//放到暂存位置，A[0]即是暂存，也是哨兵
			for(j=i-1;A[0]<A[j];--j)//移动元素，内层循环控制有序序列中的每一个元素和要插入的元素比较
				A[j+1]=A[j];
			A[j+1]=A[0];//把暂存元素插入到对应位置
		}
	}
}
 
 // 折半插入
 
void MidInsertSort(ElemType A[],int n)
{
	int i,j,low,high,mid;
	for(i=2;i<=n;i++)
	{
		A[0]=A[i];
		low=1;high=i-1;//low有序序列的开始，high有序序列的最后
		while(low<=high)//先通过二分查找找到待插入位置
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
	ST_Init(ST,10);//初始化
	memcpy(ST.elem,A,sizeof(A));//内存copy接口，当你copy整型数组，或者浮点型时，要用memcpy

	//ST_print(ST);
	BubbleSort1(ST.elem,10);//冒泡排序
	ST_print(ST);
	QuickSort(ST.elem,0,9);
	ST_print(ST);
   //memcpy(ST.elem+1, A, sizeof(A));
//   	MidInsertSort(ST.elem,10);                     // 插入排序这里存在问题 
//	ST_print(ST);
	ST_print(ST);
 
}
