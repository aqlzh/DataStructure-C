# include <stdio.h>
# include <stdlib.h>
# include <cstdlib>

#define MAXSIZE 20  //��ʼ���ֵ
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10 
#define OVERFLOW -1


typedef int ElemType;
typedef struct
{
	ElemType *elem ; 
    ElemType data[MAXSIZE];
    int length;  //��ǰ����
	int listsize ;  //��ǰ��������� 
}SqList;


// �����Ķ��� 
typedef enum Bool
{
    FALSE,TRUE
}Bool; 


// �������� 
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



// ���򴴽�˳��� 
Bool CreatList(SqList* L)
{
    int i;
    printf("�����봴����ĳ���(0-20)��\n");
    scanf("%d",&(L->length));
    if(L->length<0||L->length>MAXSIZE)
        return FALSE;
    for(i=1;i<=L->length;i++)
    {
        L->data[i-1]=i;
    }
    return TRUE;
} 

//��ʼ��˳��� 
Bool InitList(SqList* L){

	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType)) ;
	if(! L->elem)  exit(OVERFLOW);
	L->length = 0 ;
	L->listsize = LIST_INIT_SIZE ;
	return TRUE ;
} 

//��ʾ
void display(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
        printf("%d  ",L.data[i]);
       printf("\n");
} 

//��ʾ��
int  ListLength(SqList L)
{
    return L.length;
} 

int  Length( int arr1[])
{
    return sizeof(arr1) / sizeof(arr1[0]);
} 
//��λ����   ��λ��ȡԪ�� 
Bool GetElem(SqList L, int i, ElemType* e)
{
    if(L.length==0 || i<1|| i>L.length)
        return FALSE;

      *e=L.data[i-1];
       return TRUE ;
    
}

//��λ����
Bool ListInsert(SqList* L,int i,ElemType e)
{
    int k;
    if(L->length==MAXSIZE || i<1|| i>L->length+1)
        return FALSE;
    if(i<=L->length)
    {
        
        for(k=L->length-1;k>=i-1;k--)
            L->data[k+1]=L->data[k];// ����
    }
    L->data[i-1]=e;
    L->length++;
    return TRUE;
} 

//��λɾ��
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

// ��ֵ���� 
int  LocateElem(SqList L,ElemType e)
{
    int i=0;
    for(i=0;i<L.length;i++)
        if(L.data[i]==e)
            return i+1;
      return 0;
} 



//����
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

//�ϲ�

void MergeList_Sq(SqList L1,SqList L2,SqList &L4){
	int *pa,*pb,*pc,*pa_last,*pb_last ; 
	pa=L1.elem;
	pb=L2.elem;
	L4.listsize = L4.length = L1.length+L2.length ;

    pc = L4.elem =(ElemType*)malloc(L4.listsize*sizeof(ElemType));
	if(!L4.elem) exit(OVERFLOW);	//�洢����ʧ�� 
	pa_last = L1.elem +L1.length - 1;
	pb_last = L2.elem +L2.length - 1;
	while(pa<=pa_last && pb<=pb_last){//�鲢 
		if(*pa<=*pb) *pc++=*pa++;
		else *pc++=*pb++;
	}
	while(pa<=pa_last) *pc++=*pa++;//����La��ʣ��Ԫ�� 
	while(pb<=pb_last) *pc++=*pb++;//����Lb��ʣ��Ԫ�� 
}  




int main(){
   
   
   	ElemType e;
	int i,j,line,num,num1,num2,num3,num4,num5;
	SqList List;
	ElemType elem;
	SqList L1,L2,L3,L4;
	Bool flag ;
	
	
	//Ĭ�ϰ�˳���Զ�����˳���
	printf("1��˳���Զ���������˳���\n") ;
    if(!CreatList(&List))
        printf("˳�����ʧ�ܣ�\n");
    else
        printf("˳������ɹ���\n");
        
    printf("������˳���Ϊ\n") ;
    display(List);
	
	
	printf("\n\n"); 
	printf("2���Զ��崴������˳���\n") ;
	//�Զ��崴��˳��� 
	InitList(&L1);
	InitList(&L2);
	printf("������L1��ʼ���Ⱥͳ�ʼֵ"); 
	scanf("%d",&line); 
	for(i=1;i<=line;i++){
		scanf("%d",&e);
		ListInsert(&L1,i,e);
	}	
	printf("������L2��ʼ���Ⱥͳ�ʼֵ"); 
	scanf("%d",&line); 
	for(j=1;j<=line;j++){
		scanf("%d",&e);
		ListInsert(&L2,j,e);
	}
	printf("˳���L1Ϊ\n") ; 
    display(L1) ;
    printf("˳��� L2Ϊ\n") ; 
    display(L2) ;
    
    printf("\n\n");  
    printf("���²�������Ϊ˳���L1\n") ;
    printf("3��˳���İ�λ���Ҳ���ȡ\n") ;
    printf("������Ҫ���ҵ�λ��\n") ;
    scanf("%d",&num); 
	printf("\n\n") ;
    GetElem(L1,num,&elem);    
    printf("˳���L1�ĵ�%d��Ԫ����%d",num,elem);

    printf("\n\n"); 
    printf("4��˳���İ�Ԫ�ػ�ȡλ��\n") ;
    printf("������Ҫ���ҵ�Ԫ��\n") ;
    scanf("%d",&num4); 
    num5 = LocateElem(L1,num4)  ; 
    printf("%d��˳���ĵ�%d��Ԫ��",num4,num5);
    
    
    printf("\n\n"); 
    printf("5��˳���İ�λ����\n") ;
    printf("������Ҫ�����λ��\n") ;
    scanf("%d",&num1); 
    printf("������Ҫ�����Ԫ��\n") ;
     scanf("%d",&num2); 
    printf("��λ��Ϊ%d�ĵط�����%d\n",num1,num2)  ;
    ListInsert(&L1,num1,num2);
    printf("��������������") ;
    display(L1);
    
    
    printf("\n\n"); 
    printf("6��˳���İ�λɾ��\n") ;
    printf("������Ҫɾ��Ԫ�ص�λ��\n") ;
    scanf("%d",&num3); 
    ListDelete(&L1,num3,&elem) ;
    printf("ɾ����%d��Ԫ����%d\n",num3,elem);
    printf("ɾ����ñ�ĳ���Ϊ��%d\n",ListLength(L1)) ;
    printf("ɾ�������������") ;
    display(L1) ; 
    
   printf("\n\n"); 
   printf("7��˳���Ĳ���\n") ;
   flag=UnionList(&L1,&L2,&L3);
   if(!flag)
    printf("�ϲ���˳���ĳ��ȳ������Χ");
    printf("�ñ�ĳ���Ϊ:%d\n",ListLength(L3));
    display(L3);
    
    
    
    
    
    
    
   
} 

 
