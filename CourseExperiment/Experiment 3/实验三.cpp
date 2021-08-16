# include <stdio.h>
# include <stdlib.h>
# include <cstdlib>


typedef int ElemType;
typedef struct LNode
{
	ElemType data ; 
    struct LNode *next ;
}LNode , *LinkList ;

typedef enum Bool
{
    FALSE,TRUE
}Bool; 

Bool CreateList_L(LinkList &L,int n) ;
void print(LinkList L) ;
Bool GetElem_L(LinkList L,int i, ElemType &e) ;
Bool ListInsert_L (LinkList &L,int i , ElemType e) ;
Bool ListDelete_L(LinkList &L ,int i ,ElemType &e) ;
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc) ;

//LZH_Create 

// 创建链表 
Bool CreateList_L(LinkList &L,int n){
	
	LinkList p ;
	L = (LinkList) malloc (sizeof (LNode))   ;
	L->next = NULL ;
	printf("请输入元素个数\n") ;
	for(int i=n ; i>0 ; --i) {
		p = (LinkList) malloc (sizeof(LNode)) ;
		printf("第%d个元素\n",i) ; 
		scanf("%d",&p->data) ;
		p->next = L->next ;
		L->next = p ; 
	}
	return TRUE ;
	
}

// 输出 

void print(LinkList L){
	LinkList p = L->next ;
	while(p!= NULL){
		printf("%d\t",p->data);
         p = p->next; 
	}
}


// 按位查找与获取 
Bool GetElem_L(LinkList L,int i, ElemType &e){
		LinkList p ;
		p = L->next ;
		int j =1 ;
		while(p&& j<i){
			p = p->next ;
			++j ; 
		}
		
		if(!p || j>i) return FALSE ;
		e = p->data ;
		return TRUE ;
} 
 
//  插入
Bool ListInsert_L (LinkList &L,int i , ElemType e){
	LinkList p ;
    LinkList s ;
	p = L ;
	int j = 0 ;
	while (p && j<i-1){
		p = p->next ;
		++j ;
	}
	
	if(!p || j> i-1) return FALSE ;
	s = (LinkList) malloc (sizeof(LNode)) ;
	s->data = e ;
	s->next = p->next ;
	p->next = s ;
	
	return TRUE ;
} 

// 删除
Bool ListDelete_L(LinkList &L ,int i ,ElemType &e){
		LinkList p ; 
		LinkList q ; 
		p = L ;
		int j = 0 ;
		while(p->next && j<i-1){
			p = p->next ;
			++j ;
		}
		
	if(! (p->next) || j>i-1 ) return FALSE ;
	q = p->next ;
	p->next= q->next ;
	e = q->data ;
	free(q) ;
	return TRUE ;	
} 

// 合并
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	LinkList pa;
	LinkList pb ;
	LinkList pc ;
	
	pa = La->next ;
	pb = Lb->next ;
	Lc = pc =La ;
	
	while(pa && pb){
		if(pa->data <= pb->data){
			pc->next = pa ;
			pc = pa ;
			pa = pa->next ;
		} else {
			pc->next = pb ;
			pc = pb ;
			pb = pb->next ;
		}
	}
	pc -> next = pa ? pa : pb ;
	free(Lb) ; 
} 

 
int main(){
    ElemType e;
    ElemType elem;
	LinkList L ; 
	LinkList L1 ; 
	LinkList L2 ; 
	LinkList L3 ; 
	int num,num1,num2,num3 ;
	
	
	printf("1、创建链表\n") ;
	if(!CreateList_L(L,5))
        printf("链表创建失败！\n");
    else
        printf("链表创建成功！\n");
	 //CreateList_L(L,5) ;
	printf("创建的链表表为\n") ;
	print(L) ;
	
	printf("\n\n") ;
	printf("2、链表的按位查找\n") ;
	printf("请输入要查找的位序\n") ;
	scanf("%d",&num) ; 
	GetElem_L(L,num,e) ;
	printf("\n\n") ;
	printf("顺序表L1的第%d个元素是%d",num,e);
	
	printf("\n\n") ;
	printf("3、链表的插入操作\n") ;
	printf("请输入要插入的位序与元素") ;
	scanf("%d%d",&num1,&num2)  ;
	ListInsert_L(L,num2,num2) ;
	print(L) ;
	
	printf("\n\n") ;
    printf("4、链表的删除操作\n") ;
	printf("请输入要删除的位序") ;
	scanf("%d",&num3)  ;
	ListDelete_L(L ,num3 ,elem) ;
	printf("删除元素是%d\n",elem);
	
	printf("\n\n") ;
	printf("5、有序链表的合并开始") ;
	printf("\n\n") ;
	printf("5.1、创建待合并的有序链表1\n") ; 
	CreateList_L(L1,5) ;
	//print(L) ;
	printf("\n\n") ;
	printf("有序链表1为\n") ;
	print(L1) ;
	
	printf("\n\n") ;
	printf("5.2、创建待合并的有序链表2\n") ; 
	CreateList_L(L3,5) ;
	printf("有序链表2为\n") ;
	print(L3) ;
	printf("\n\n") ;
	MergeList_L(L3,L1,L2) ;
	printf("5.3、合并结果为\n") ; 
	print(L2) ;
	
	
	
	
}



