# include <stdio.h>
# include <stdlib.h>
# include <cstdlib>

#define MAXSIZE 20  //初始最大值
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10 
#define OVERFLOW -1


typedef int ElemType;
typedef struct
{
	ElemType *elem ; 
    ElemType data[MAXSIZE];
    int length;  //当前长度
	int listsize ;  //当前分配的容量 
}SqList;


// 布尔的定义 
typedef enum Bool
{
    FALSE,TRUE
}Bool; 


// 函数声明 
Bool CreatList(SqList* L) ;
Bool InitList(SqList* L)  ;
Bool GetElem(SqList L, int i, ElemType* e)  ;
void display(SqList L);
int  ListLength(SqList L) ; 
Bool ListDelete(SqList *L,int i,ElemType* e) ;
//int  LocateElemt(int A [4] ,ElemType e) ;
int  LocateElem(SqList L,ElemType e) ; 
Bool UnionList(SqList* L1,SqList* L2,SqList* L) ; 
void Merge() ; 
void MergeList_Sq(SqList La,SqList Lb,SqList &Lc) ;



// 有序创建顺序表 
Bool CreatList(SqList* L)
{
    int i;
    printf("请输入创建表的长度(0-20)？\n");
    scanf("%d",&(L->length));
    if(L->length<0||L->length>MAXSIZE)
        return FALSE;
    for(i=1;i<=L->length;i++)
    {
        L->data[i-1]=i;
    }
    return TRUE;
} 

//初始化顺序表 
Bool InitList(SqList* L){

	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType)) ;
	if(! L->elem)  exit(OVERFLOW);
	L->length = 0 ;
	L->listsize = LIST_INIT_SIZE ;
	return TRUE ;
} 

//显示
void display(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
        printf("%d  ",L.data[i]);
       printf("\n");
} 

//显示表长
int  ListLength(SqList L)
{
    return L.length;
} 

int  Length( int arr1[])
{
    return sizeof(arr1) / sizeof(arr1[0]);
} 
//按位查找   按位获取元素 
Bool GetElem(SqList L, int i, ElemType* e)
{
    if(L.length==0 || i<1|| i>L.length)
        return FALSE;

      *e=L.data[i-1];
       return TRUE ;
    
}

//按位插入
Bool ListInsert(SqList* L,int i,ElemType e)
{
    int k;
    if(L->length==MAXSIZE || i<1|| i>L->length+1)
        return FALSE;
    if(i<=L->length)
    {
        
        for(k=L->length-1;k>=i-1;k--)
            L->data[k+1]=L->data[k];// 倒序
    }
    L->data[i-1]=e;
    L->length++;
    return TRUE;
} 

//按位删除
Bool ListDelete(SqList *L,int i,ElemType* e){
	 int j ;
	 if(L->length > MAXSIZE || i<1 || L->length==0)
        return FALSE;
     *e=L->data[i-1] ;
     if(i<L->length){
        for(j=i-1 ; j<L->length-1 ;j++)
	 	L->data[j] = L->data[j+1] ;
	 }

	 	L->length -- ;

	   
	 return TRUE ;
} 

// 按值查找 
int  LocateElem(SqList L,ElemType e)
{
    int i=0;
    for(i=0;i<L.length;i++)
        if(L.data[i]==e)
            return i+1;
      return 0;
} 



//并集
Bool UnionList(SqList* L1,SqList* L2,SqList* L)
{
    int i,j;
    L->length=0;
    for(i=0;i<L1->length;i++)
    {
        L->data[i]=L1->data[i];
    }

    for(j=0;j<L2->length;j++)
        if(LocateElem(*L1,L2->data[j])==0)
        {
            if(i>=MAXSIZE)
                return FALSE;
            L->data[i]=L2->data[j];
            i++;
        }

    L->length=i;
    return TRUE;
} 

//合并

void MergeList_Sq(SqList L1,SqList L2,SqList &L4){
	int *pa,*pb,*pc,*pa_last,*pb_last ; 
	pa=L1.elem;
	pb=L2.elem;
	L4.listsize = L4.length = L1.length+L2.length ;

    pc = L4.elem =(ElemType*)malloc(L4.listsize*sizeof(ElemType));
	if(!L4.elem) exit(OVERFLOW);	//存储分配失败 
	pa_last = L1.elem +L1.length - 1;
	pb_last = L2.elem +L2.length - 1;
	while(pa<=pa_last && pb<=pb_last){//归并 
		if(*pa<=*pb) *pc++=*pa++;
		else *pc++=*pb++;
	}
	while(pa<=pa_last) *pc++=*pa++;//插入La的剩余元素 
	while(pb<=pb_last) *pc++=*pb++;//插入Lb的剩余元素 
}  




int main(){
   
   
   	ElemType e;
	int i,j,line,num,num1,num2,num3,num4,num5;
	SqList List;
	ElemType elem;
	SqList L1,L2,L3,L4;
	Bool flag ;
	
	
	//默认按顺序自动创建顺序表
	printf("1、顺序自动创建创建顺序表\n") ;
    if(!CreatList(&List))
        printf("顺序表创建失败！\n");
    else
        printf("顺序表创建成功！\n");
        
    printf("创建的顺序表为\n") ;
    display(List);
	
	
	printf("\n\n"); 
	printf("2、自定义创建创建顺序表\n") ;
	//自定义创建顺序表 
	InitList(&L1);
	InitList(&L2);
	printf("请输入L1初始长度和初始值"); 
	scanf("%d",&line); 
	for(i=1;i<=line;i++){
		scanf("%d",&e);
		ListInsert(&L1,i,e);
	}	
	printf("请输入L2初始长度和初始值"); 
	scanf("%d",&line); 
	for(j=1;j<=line;j++){
		scanf("%d",&e);
		ListInsert(&L2,j,e);
	}
	printf("顺序表L1为\n") ; 
    display(L1) ;
    printf("顺序表 L2为\n") ; 
    display(L2) ;
    
    printf("\n\n");  
    printf("以下操作对象为顺序表L1\n") ;
    printf("3、顺序表的按位查找并获取\n") ;
    printf("请输入要查找的位序\n") ;
    scanf("%d",&num); 
	printf("\n\n") ;
    GetElem(L1,num,&elem);    
    printf("顺序表L1的第%d个元素是%d",num,elem);

    printf("\n\n"); 
    printf("4、顺序表的按元素获取位置\n") ;
    printf("请输入要查找的元素\n") ;
    scanf("%d",&num4); 
    num5 = LocateElem(L1,num4)  ; 
    printf("%d是顺序表的第%d个元素",num4,num5);
    
    
    printf("\n\n"); 
    printf("5、顺序表的按位插入\n") ;
    printf("请输入要查入的位序\n") ;
    scanf("%d",&num1); 
    printf("请输入要查入的元素\n") ;
     scanf("%d",&num2); 
    printf("在位序为%d的地方插入%d\n",num1,num2)  ;
    ListInsert(&L1,num1,num2);
    printf("插入后的链表如下") ;
    display(L1);
    
    
    printf("\n\n"); 
    printf("6、顺序表的按位删除\n") ;
    printf("请输入要删除元素的位序\n") ;
    scanf("%d",&num3); 
    ListDelete(&L1,num3,&elem) ;
    printf("删除第%d个元素是%d\n",num3,elem);
    printf("删除后该表的长度为；%d\n",ListLength(L1)) ;
    printf("删除后的链表如下") ;
    display(L1) ; 
    
   printf("\n\n"); 
   printf("7、顺序表的并集\n") ;
   flag=UnionList(&L1,&L2,&L3);
   if(!flag)
    printf("合并后，顺序表的长度超过最大范围");
    printf("该表的长度为:%d\n",ListLength(L3));
    display(L3);
    
    
    
    
    
    
    
   
} 

 
