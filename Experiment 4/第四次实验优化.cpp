# include <stdio.h>
# include <stdlib.h>
# include <cstdlib>

#define STACK_INIT_SIZE  100
#define STACKINCREMENT   10 
#define OVERFLOW -1

#define MAXQSIZE 10

typedef int SElemType;
typedef struct 
{
	SElemType * base ;
	SElemType * top  ;
	int stacksize ;
    
}SqStack ;

typedef int QElemType;
typedef struct {
	QElemType * base ;
	int front ;
	int rear ;
	
} SqQueue ;


typedef enum Bool
{
    FALSE,TRUE
}Bool; 


Bool InitStack(SqStack &s) ;
Bool Push (SqStack &S , SElemType e) ;
Bool Pop (SqStack & S,SElemType &e) ;
Bool StackEmpty (SqStack S) ;
void conversion () ;
Bool GetTop(SqStack S, SElemType &e) ;
Bool InitQueue (SqQueue &Q) ;
int QueueLength (SqQueue Q) ;
Bool EnQueue ( SqQueue &Q , QElemType e) ;
Bool DeQueue (SqQueue &Q , QElemType &e )  ;


//  LZH_Create
 
Bool InitStack(SqStack &S){
	
	S.base = (SElemType * )malloc(STACK_INIT_SIZE * sizeof(SElemType))  ;
	if(! S.base) exit (OVERFLOW) ;
	S.top = S.base ;
	S.stacksize = STACK_INIT_SIZE ;
	return  TRUE ;
}

Bool Push (SqStack &S , SElemType e){
	if(S.top - S.base >= S.stacksize){
		S.base = (SElemType * )realloc (S.base , (S.stacksize + STACKINCREMENT)* sizeof(SElemType)) ;
		if(! S.base) exit (OVERFLOW) ;
		S.top = S.base + S.stacksize ;
		S.stacksize += STACKINCREMENT ;
	}
	* S.top ++ = e ;
	return TRUE ;
}

Bool Pop (SqStack & S,SElemType &e){
	if(S.top == S.base) return FALSE ;
	e = * -- S.top ;
	return TRUE ;
}

Bool StackEmpty (SqStack S){
	if(S.top == S.base) return TRUE ;
}



Bool GetTop(SqStack S, SElemType &e){
	if(S.top == S.base ) return FALSE ;
	e = *(S.top - 1) ;
	return TRUE  ;
}

void conversion (){
	SqStack S ;
	int e,N ;
	
	InitStack(S) ;
	printf("������Ҫת����ʮ������\n") ;
	scanf("%d",&N) ;
	while(N){
		Push(S,N%8) ;
		N= N/8 ;  
	}
	    printf("ת��Ϊ�˽��ƵĽ��Ϊ\n") ; 
		while(StackEmpty(S) != TRUE) {
		Pop(S,e) ;
		printf("%d",e) ;
	}
}


// �����㷨
 


Bool InitQueue (SqQueue &Q){
	Q.base = (QElemType *) malloc (MAXQSIZE * sizeof(QElemType)) ;
	if(! Q.base) exit (OVERFLOW) ;
	Q.front = Q.rear = 0 ;
	return TRUE ;
} 

int QueueLength (SqQueue Q) {
	return (Q.rear -Q.front +MAXQSIZE) % MAXQSIZE ;
}

Bool EnQueue ( SqQueue &Q , QElemType e){
	if((Q.rear+1)%MAXQSIZE == Q.front ) return FALSE ;
	Q.base[Q.rear] = e ;
	Q.rear = (Q.rear+1) % MAXQSIZE ;
	return TRUE ;
}

Bool DeQueue (SqQueue &Q , QElemType &e ){
	if(Q.front == Q.rear) return FALSE ;
	e = Q.base[Q.front] ;
	Q.front = (Q.front + 1) % MAXQSIZE ;
	return TRUE ;
}
int main(){
	
   int num,e ;	
   conversion () ;
	
   printf("\n\n") ;
	
   SqQueue Q ;
   InitQueue(Q) ;
   
   if(QueueLength(Q) == 0){
   	printf("����Ϊ��\n\n") ;
   	
   }
   
   printf("������Ҫ��ӵ���Ԫ�ظ���\n") ;
   scanf("%d",&num) ;
   
   if(num > MAXQSIZE-1 ){
   	  printf("�������Χ\n") ;
   	  
   }  else{
   	
   	
   	 for(int i = 1 ; i <= num ;i++){
   printf("������%d��Ԫ��\n",i) ;
   scanf("%d",&e) ;
   
   
   
   
   EnQueue(Q,e) ;
   printf("%d ���\n",e) ;
   
    if(QueueLength(Q) == MAXQSIZE-1){
   	printf("����\n") ;
   }
   

	} 
	
	
	printf("\n\n") ;
	printf("���Ӳ�����ʼ\n") ;
	
	 
   for(int i = 0 ; i < num ;i++){

    DeQueue(Q,e) ;
    printf("%d ����\n\n",e) ;
    
    if(QueueLength(Q) == 0){
       	printf("����Ϊ��\n") ;
     }

	} 
   	
   }
   
  
   

}
