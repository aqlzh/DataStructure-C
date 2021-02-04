l'l# include <stdio.h>
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


Bool ListInsert(SqList* L,int i,ElemType e) ; 
Bool InitList(SqList* L) ;
void MergeList_Sq(SqList La,SqList Lb,SqList &Lc) ;
void display(SqList L) ; 



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

Bool InitList(SqList* L){

	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType)) ;
	if(! L->elem)  exit(OVERFLOW);
	L->length = 0 ;
	L->listsize = LIST_INIT_SIZE ;
	return TRUE ;
} 

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)
{
	int *pa, *pb, *pc;
	int *pa_last, *pb_last;
	pa = La.elem;
	pb = Lb.elem;
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (int *)malloc(Lc.listsize * sizeof(int));
	if(!Lc.elem)exit(0);
	pa_last = &La.elem[La.length - 1];
	pb_last = &Lb.elem[Lb.length - 1];
	while(pa <= pa_last && pb <= pb_last)
	{
		if(*pa <= *pb)
			*pc ++ = *pa ++;
		else
			*pc ++ = *pb ++;
	}
	while(pa <= pa_last)
		*pc ++ = *pa ++;
	while(pb <= pb_last)
		*pc ++ = *pb ++;
		
	
	display(Lc) ;	
		
}

//
//void MergeList_Sq(SqList L1,SqList L2,SqList *L4){
//	
//	// L1 上没有 *L1  则引用用。   否则(是 *L1)用  -> 
//	
//
//	
//	L4->listsize = L4->length = L1.length+L2.length ;
//
//    L4->elem =(ElemType*)malloc(L4->listsize*sizeof(ElemType));
//	if(!L4->elem) exit(OVERFLOW);	
//	
//	
//	int i=0,j=0,k=0 ;
//    while(i<= L1.length && j<= L2.length){ 
//		if(L1.data[i] <= L2.data[j]) {
//			L4->data[k] = L1.data[i] ;
//			k++ ;
//			i++  ; 		
//		} else {
//			L4->data[k] = L1.data[j] ;
//			k++ ;
//			j++ ;
//		}
//		
//	}
//	while(i<=L1.length) L4->data[k] = L1.data[i];
//	while(j<=L1.length) L4->data[k] = L1.data[j];
//	
//	display(L1) ;
//	display(L2) ;
////	display(*L4) ; 
//}  


void display(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
        printf("%d  ",L.data[i]);
       printf("\n");
} 


int main(){
	
	
	
	ElemType e;
	int i,j,line,num,num1,num2,num3,num4,num5;
	SqList List;
	ElemType elem;
	SqList L1,L2,L3,L4,Lc;
	Bool flag ;
	
	
	
	printf("自定义创建创建顺序表\n") ;
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
    
    printf("合并的操作\n") ; 
    MergeList_Sq(L1,L2,Lc) ;
}
