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

// �������� 
Bool CreateList_L(LinkList &L,int n){
	
	LinkList p ;
	L = (LinkList) malloc (sizeof (LNode))   ;
	L->next = NULL ;
	printf("������Ԫ�ظ���\n") ;
	for(int i=n ; i>0 ; --i) {
		p = (LinkList) malloc (sizeof(LNode)) ;
		printf("��%d��Ԫ��\n",i) ; 
		scanf("%d",&p->data) ;
		p->next = L->next ;
		L->next = p ; 
	}
	return TRUE ;
	
}

// ��� 

void print(LinkList L){
	LinkList p = L->next ;
	while(p!= NULL){
		printf("%d\t",p->data);
         p = p->next; 
	}
}


// ��λ�������ȡ 
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
 
//  ����
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

// ɾ��
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

// �ϲ�
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
	
	
	printf("1����������\n") ;
	if(!CreateList_L(L,5))
        printf("������ʧ�ܣ�\n");
    else
        printf("�������ɹ���\n");
	 //CreateList_L(L,5) ;
	printf("�����������Ϊ\n") ;
	print(L) ;
	
	printf("\n\n") ;
	printf("2������İ�λ����\n") ;
	printf("������Ҫ���ҵ�λ��\n") ;
	scanf("%d",&num) ; 
	GetElem_L(L,num,e) ;
	printf("\n\n") ;
	printf("˳���L1�ĵ�%d��Ԫ����%d",num,e);
	
	printf("\n\n") ;
	printf("3������Ĳ������\n") ;
	printf("������Ҫ�����λ����Ԫ��") ;
	scanf("%d%d",&num1,&num2)  ;
	ListInsert_L(L,num2,num2) ;
	print(L) ;
	
	printf("\n\n") ;
    printf("4�������ɾ������\n") ;
	printf("������Ҫɾ����λ��") ;
	scanf("%d",&num3)  ;
	ListDelete_L(L ,num3 ,elem) ;
	printf("ɾ��Ԫ����%d\n",elem);
	
	printf("\n\n") ;
	printf("5����������ĺϲ���ʼ") ;
	printf("\n\n") ;
	printf("5.1���������ϲ�����������1\n") ; 
	CreateList_L(L1,5) ;
	//print(L) ;
	printf("\n\n") ;
	printf("��������1Ϊ\n") ;
	print(L1) ;
	
	printf("\n\n") ;
	printf("5.2���������ϲ�����������2\n") ; 
	CreateList_L(L3,5) ;
	printf("��������2Ϊ\n") ;
	print(L3) ;
	printf("\n\n") ;
	MergeList_L(L3,L1,L2) ;
	printf("5.3���ϲ����Ϊ\n") ; 
	print(L2) ;
	
	
	
	
}



