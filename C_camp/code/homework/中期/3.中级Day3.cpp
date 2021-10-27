#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
//静态分配
typedef struct{
	ElemType data[MaxSize];
	int length;//当前顺序表中有多少个元素
}SqList;
//动态分配
#define InitSize 100
typedef struct{
	ElemType *data;
	int capacity;//动态数组的最大容量
	int length;
}SeqList;
//i代表插入的位置，从1开始，e要插入的元素
bool ListInsert(SqList &L,int i,ElemType e)
{
	if(i<1||i>L.length+1)//判断要插入的位置是否合法
		return false;
	if(L.length>=MaxSize)//超出空间了
		return false;
	for(int j=L.length;j>=i;j--)//移动顺序表中的元素
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;//数组下标从零开始，插入第一个位置，访问的下标为0
	L.length++;
	return true;
}
//删除使用元素e的引用的目的是拿出对应的值
bool ListDelete(SqList &L,int i,ElemType &e)
{
	if(i<1||i>L.length)//如果删除的位置是不合法
		return false;
	e=L.data[i-1];//获取顺序表中对应的元素，赋值给e
	for(int j=i;j<L.length;j++)
		L.data[j-1]=L.data[j];
	L.length--;//删除一个元素，顺序表长度减1
	return true;
}
//查找成功，返回位置，位置从1开始，查找失败，返回0
int LocateElem(SqList L,ElemType e)
{
	int i;
	for(i=0;i<L.length;i++)
		if(L.data[i]==e)
			return i+1;//加1就是元素在顺序表中的位置
	return 0;
}
//打印顺序表元素
void PrintList(SqList &L)
{
	for(int i=0;i<L.length;i++)
	{
		printf("%4d",L.data[i]);
	}
	printf("\n");
}
int main()
{
	SqList L;//顺序表的名称
	bool ret;//查看返回值，布尔型是True,或者False
	ElemType del;//要删除的元素
	//首先手动在顺序表中赋值
	L.data[0]=1;
	L.data[1]=2;
	L.data[2]=3;
	L.length=3;//总计三个元素
	int n,m ;
	scanf("%d",&n) ;
	scanf("%d",&m) ;
    ListInsert(L,2,n);
    PrintList(L) ; 
	ret = ListDelete(L,m,del) ;

	if(ret==false){
		printf("false") ;
	}else {
    	PrintList(L) ; 
	}	 
	//ret=ListDelete(L,1,del);
	 
 
}

