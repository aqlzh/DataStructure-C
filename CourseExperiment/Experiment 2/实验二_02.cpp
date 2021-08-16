#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0


//  构思二
 
typedef int Status;
typedef int ElemType;
typedef struct{
	ElemType* elem;
	int length;
	int listsize;
}SqList; 



// 初始化 
Status InitList_Sq(SqList &L){

	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);
	
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	printf("顺序表构造成功\n");
	return OK;
}


// 输出 
void ListPrint(SqList L){

	ElemType *m;
	printf("顺序表中的元素为：\n");
	for(m=L.elem ; m<L.length+L.elem ; m++){
	 printf("%d\t",*m);
	}
	printf("\n顺序表元素有%d个\n\n",L.length);
}


//插入 
Status ListInsert_Sq(SqList &L,int i,ElemType e){

	
	if(i<1||i>L.length+1) return ERROR; 
	if(L.length>=L.listsize){
		ElemType *newbase = (ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	
	int *q,*p;
	q = &(L.elem[i-1]);
	for(p=&(L.elem[L.length-1]); p>=q ; --p)    *(p+1) = *p;
	*q =e; 
	++L.length; 
	return OK;
}


//   删除 
Status ListDelete_Sq(SqList &L,int i,ElemType &e) {
	
	int *p,*q;
	if((i<1)||(i>L.length)) return ERROR; 
	p = &(L.elem[i-1]); 
	e = *p;
	q = L.elem + L.length -1; 
	for(++p;p<=q;++p) *(p-1) = *p; 
	--L.length;
	return OK;
} 


//  查询 
Status ListFind_Sq(SqList &L,ElemType &e){
	 
	for(int i;i<L.length;i++){
		if(L.elem[i]==e){
			return i+1;
		}
	}
	return ERROR;
}

void MergeList_Sq(SqList La,SqList Lb,SqList &Lc){

	int *pa,*pb,*pc,*pa_last,*pb_last;
	pa = La.elem; pb = Lb.elem;
	Lc.listsize = Lc.length = La.length+Lb.length; 
	pc = Lc.elem =(ElemType*)malloc(Lc.listsize*sizeof(ElemType));
	if(!Lc.elem) exit(OVERFLOW);	//存储分配失败 
	pa_last = La.elem +La.length - 1;
	pb_last = Lb.elem +Lb.length - 1;
	while(pa<=pa_last && pb<=pb_last){//归并 
		if(*pa<=*pb) *pc++=*pa++;
		else *pc++=*pb++;
	}
	while(pa<=pa_last) *pc++=*pa++;//插入La的剩余元素 
	while(pb<=pb_last) *pc++=*pb++;//插入Lb的剩余元素 
} 

void merge(){
	//将所有在线性表Lb中但不在La中的数据元素插入到La中		
	ElemType e;
	int i,j,line;
	//La和Lb创建和赋值 
	SqList La,Lb;
	InitList_Sq(La);
	InitList_Sq(Lb);
	printf("请输入La初始长度和初始值:"); 
	scanf("%d",&line); 
	for(i=1;i<=line;i++){
		scanf("%d",&e);
		ListInsert_Sq(La,i,e);
	}
	printf("请输入Lb初始长度和初始值:"); 
	scanf("%d",&line); 
	for(j=1;j<=line;j++){
		scanf("%d",&e);
		ListInsert_Sq(Lb,j,e);
	}
	ListPrint(La);
	ListPrint(Lb);
	
	for(i=0;i<Lb.length;i++){
		bool repate = false;//repate用来判断元素是否重复 
		for(j=0;j<La.length;j++){
			if(Lb.elem[i]==La.elem[j]){
				repate = true;	
			}
		}
		if(!repate){//if不重复，插入到La表尾 
			ListInsert_Sq(La,La.length+1.,e = Lb.elem[i]);
		}
	}
	ListPrint(La);
}

void merges(){
	ElemType e;
	int i,j,line;
	//La和Lb创建及赋值 
	SqList La,Lb,Lc;
	InitList_Sq(La);
	InitList_Sq(Lb);
	printf("请输入La初始长度和初始值:"); 
	scanf("%d",&line); 
	for(i=1;i<=line;i++){
		scanf("%d",&e);
		ListInsert_Sq(La,i,e);
	}	
	printf("请输入Lb初始长度和初始值:"); 
	scanf("%d",&line); 
	for(j=1;j<=line;j++){
		scanf("%d",&e);
		ListInsert_Sq(Lb,j,e);
	}
	ListPrint(La);
	ListPrint(Lb);	
	
	MergeList_Sq(La,Lb,Lc);
	ListPrint(Lc);
}


int main() {
//	ElemType e;
//	int i,j,line;
//	
//	//顺序表的创建和初始化 
//	SqList L;
//	InitList_Sq(L);
//	
//	//顺序表初始长度和初始赋值 
//	printf("请输入顺序表初始长度和初始值:"); 
//	scanf("%d",&line); 
//	for(i=1;i<=line;i++){
//		scanf("%d",&e);
//		ListInsert_Sq(L,i,e);
//	}
//	ListPrint(L);
//	
//	//将数据e插入到顺序表的第i位 
//	printf("请输入插入的位置:");	
//	scanf("%d",&i); 
//	printf("请输入要插入的数字:");
//	scanf("%d",&e); 
//	ListInsert_Sq(L,i,e);
//	ListPrint(L);
//	
//	//将第i位的数据删除，并且用e返回其值
//	printf("请输入删除数据的位置:") ; 
//	scanf("%d",&i);
//	ListDelete_Sq(L,i,e);
//	printf("删除的元素为%d\n",e);
//	ListPrint(L); 
//	
//	//数据查询，查询成功返回位置，失败返回ERROR
//	printf("请输入查询的值:");
//	scanf("%d",&e);
//	int Y = ListFind_Sq(L,e); 
//	//Y用来接收ListFind返回的值，用来判断是否查询成功 
//	if(Y==ERROR){
//		printf("顺序表中没有%d",e);
//	}else{
//		printf("%d在顺序表中的位置是%d",e,Y);
//	}

//	merge();//两个顺序表的并操作，不保留重复元素 
	merges();//两个有序表的合并，保留重复元素 
}





