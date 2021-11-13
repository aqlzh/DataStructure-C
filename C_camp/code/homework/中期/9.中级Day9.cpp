#include <stdio.h>
#include <stdlib.h>


typedef int KeyType;
typedef struct BSTNode{
	KeyType key;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BiTree;
//54,20,66,40,28,79,58



int BST_Insert(BiTree &T,KeyType k)
{
	if(NULL==T)
	{	//Ϊ�½ڵ�����ռ�
		T=(BiTree)malloc(sizeof(BSTNode));
		T->key=k;
		T->lchild=T->rchild=NULL;
		return 1;//�������ɹ�
	}
	else if(k==T->key)
		return 0;//������ͬԪ�أ��Ͳ�����
	else if(k<T->key)
		return BST_Insert(T->lchild,k);
	else
		return BST_Insert(T->rchild,k);
}
//��������������
void Creat_BST(BiTree &T,KeyType str[],int n)
{
	T=NULL;
	int i=0;
	while(i<n)
	{
		BST_Insert(T,str[i]);
		i++;
	}
}
 
 int array[10] ={0} ;
void InOrder(BiTree T)
{
	if(T!=NULL)
	{
		InOrder(T->lchild);
		printf("%3d",T->key);
		InOrder(T->rchild);
	}
}
int InOrderStr(BiTree T,int pos ,int array[])
{
	if(T==NULL) return pos ;
	 
		pos = InOrderStr(T->lchild,pos,array);
		array[pos] =T->key ;
		return InOrderStr(T->rchild,pos+1,array);
	 
}
//void InOrder2(BiTree T)
//{
//	if(T!=NULL)
//	{
//		InOrder(T->lchild);
//		int * i = 0 ;
//		array[(*i)++] = T->key ; 
//		InOrder(T->rchild);
//	}
//}



// �۰����
int Binary_Search(int L [] ,KeyType key)
{
	int low=0,high=9,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(L[mid]==key)
			return mid;
		else if(L[mid] > key)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
} 
int main()
{
	BiTree T;
	BiTree parent;//�洢���׽��ĵ�ֵַ
	BiTree search;
	//KeyType str[10] ={87,7,60,80,59,34,86,99,21,3} ;//��Ҫ���������������Ԫ��ֵ
	KeyType str[10] ;
	for(int i = 0 ; i< 10 ;i++){
		scanf("%d",&str[i]) ;
	}
	
	Creat_BST(T,str,10);
	InOrder(T);
	printf("%\n") ;

	InOrderStr(T,0,array) ;
    int res = Binary_Search(array,21) ;
    printf("%d",res) ;
	return 0 ; 
	
}
