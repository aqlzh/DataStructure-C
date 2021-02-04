#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0


//  ��˼��
 
typedef int Status;
typedef int ElemType;
typedef struct{
	ElemType* elem;
	int length;
	int listsize;
}SqList; 



// ��ʼ�� 
Status InitList_Sq(SqList &L){

	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);
	
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	printf("˳�����ɹ�\n");
	return OK;
}


// ��� 
void ListPrint(SqList L){

	ElemType *m;
	printf("˳����е�Ԫ��Ϊ��\n");
	for(m=L.elem ; m<L.length+L.elem ; m++){
	 printf("%d\t",*m);
	}
	printf("\n˳���Ԫ����%d��\n\n",L.length);
}


//���� 
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


//   ɾ�� 
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


//  ��ѯ 
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
	if(!Lc.elem) exit(OVERFLOW);	//�洢����ʧ�� 
	pa_last = La.elem +La.length - 1;
	pb_last = Lb.elem +Lb.length - 1;
	while(pa<=pa_last && pb<=pb_last){//�鲢 
		if(*pa<=*pb) *pc++=*pa++;
		else *pc++=*pb++;
	}
	while(pa<=pa_last) *pc++=*pa++;//����La��ʣ��Ԫ�� 
	while(pb<=pb_last) *pc++=*pb++;//����Lb��ʣ��Ԫ�� 
} 

void merge(){
	//�����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��		
	ElemType e;
	int i,j,line;
	//La��Lb�����͸�ֵ 
	SqList La,Lb;
	InitList_Sq(La);
	InitList_Sq(Lb);
	printf("������La��ʼ���Ⱥͳ�ʼֵ:"); 
	scanf("%d",&line); 
	for(i=1;i<=line;i++){
		scanf("%d",&e);
		ListInsert_Sq(La,i,e);
	}
	printf("������Lb��ʼ���Ⱥͳ�ʼֵ:"); 
	scanf("%d",&line); 
	for(j=1;j<=line;j++){
		scanf("%d",&e);
		ListInsert_Sq(Lb,j,e);
	}
	ListPrint(La);
	ListPrint(Lb);
	
	for(i=0;i<Lb.length;i++){
		bool repate = false;//repate�����ж�Ԫ���Ƿ��ظ� 
		for(j=0;j<La.length;j++){
			if(Lb.elem[i]==La.elem[j]){
				repate = true;	
			}
		}
		if(!repate){//if���ظ������뵽La��β 
			ListInsert_Sq(La,La.length+1.,e = Lb.elem[i]);
		}
	}
	ListPrint(La);
}

void merges(){
	ElemType e;
	int i,j,line;
	//La��Lb��������ֵ 
	SqList La,Lb,Lc;
	InitList_Sq(La);
	InitList_Sq(Lb);
	printf("������La��ʼ���Ⱥͳ�ʼֵ:"); 
	scanf("%d",&line); 
	for(i=1;i<=line;i++){
		scanf("%d",&e);
		ListInsert_Sq(La,i,e);
	}	
	printf("������Lb��ʼ���Ⱥͳ�ʼֵ:"); 
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
//	//˳���Ĵ����ͳ�ʼ�� 
//	SqList L;
//	InitList_Sq(L);
//	
//	//˳����ʼ���Ⱥͳ�ʼ��ֵ 
//	printf("������˳����ʼ���Ⱥͳ�ʼֵ:"); 
//	scanf("%d",&line); 
//	for(i=1;i<=line;i++){
//		scanf("%d",&e);
//		ListInsert_Sq(L,i,e);
//	}
//	ListPrint(L);
//	
//	//������e���뵽˳���ĵ�iλ 
//	printf("����������λ��:");	
//	scanf("%d",&i); 
//	printf("������Ҫ���������:");
//	scanf("%d",&e); 
//	ListInsert_Sq(L,i,e);
//	ListPrint(L);
//	
//	//����iλ������ɾ����������e������ֵ
//	printf("������ɾ�����ݵ�λ��:") ; 
//	scanf("%d",&i);
//	ListDelete_Sq(L,i,e);
//	printf("ɾ����Ԫ��Ϊ%d\n",e);
//	ListPrint(L); 
//	
//	//���ݲ�ѯ����ѯ�ɹ�����λ�ã�ʧ�ܷ���ERROR
//	printf("�������ѯ��ֵ:");
//	scanf("%d",&e);
//	int Y = ListFind_Sq(L,e); 
//	//Y��������ListFind���ص�ֵ�������ж��Ƿ��ѯ�ɹ� 
//	if(Y==ERROR){
//		printf("˳�����û��%d",e);
//	}else{
//		printf("%d��˳����е�λ����%d",e,Y);
//	}

//	merge();//����˳���Ĳ��������������ظ�Ԫ�� 
	merges();//���������ĺϲ��������ظ�Ԫ�� 
}





