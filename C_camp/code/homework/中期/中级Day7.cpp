#include <stdio.h>
#include <stdlib.h>



typedef char BiElemType ;

typedef struct BiTNode{
	BiElemType c;//c�����鼮�ϵ�data
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;


// ����
typedef struct tag{
	BiTree p;//����ĳһ�����ĵ�ֵַ
	struct tag *pnext;
}tag_t,*ptag_t;

//ջ��������ݽṹ
#define MaxSize 50
typedef BiTree ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack &S);
bool StackEmpty(SqStack &S);
bool Push(SqStack &S,ElemType x);
bool Pop(SqStack &S,ElemType &x);
bool GetTop(SqStack &S,ElemType &x);
 
//���е�������ݽṹ
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkNode;
typedef struct{
	LinkNode *front,*rear;
}LinkQueue;
void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q,ElemType x);
bool DeQueue(LinkQueue &Q,ElemType &x);


//��ͷ���Ķ���
void InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
}

bool IsEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)
		return true;
	else
		return false;
}

void EnQueue(LinkQueue &Q,ElemType x)
{
	LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
	s->data=x;s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
}

bool DeQueue(LinkQueue &Q,ElemType &x)
{
	if(Q.front==Q.rear) return false;
	LinkNode *p=Q.front->next;//ͷ���ʲô��û�棬����ͷ������һ���ڵ��������
	x=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
		Q.rear=Q.front;
	free(p);
	return true;
}
 
void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q,T);//�������
	while(!IsEmpty(Q))
	{
		DeQueue(Q,p);
		putchar(p->c);
		if(p->lchild!=NULL)
			EnQueue(Q,p->lchild);
		if(p->rchild!=NULL)
			EnQueue(Q,p->rchild);
	}
}
 
 
void preOrder(BiTree p)
{
	if(p!=NULL)
	{
		putchar(p->c);//�ȼ���visit����
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

//�������  hdibjeafcg
void InOrder(BiTree p)
{
	if(p!=NULL)
	{
		InOrder(p->lchild);
		putchar(p->c);
		InOrder(p->rchild);
	}
}
//hidjebfgca
void PostOrder(BiTree p)
{
	if(p!=NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->c);
	}
}
int main()
{
	BiTree pnew;
	int i,j,pos;
	char c;
	BiTree tree=NULL;//����
	ptag_t phead=NULL,ptail=NULL,listpnew,pcur;//phead���Ƕ���ͷ��ptail���Ƕ���β
	//abcdefghij
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='\n')
		{
			break;
		}
		pnew=(BiTree)calloc(1,sizeof(BiTNode));//calloc����ռ䲢�Կռ���г�ʼ������ֵΪ0
		pnew->c=c;//���ݷŽ�ȥ
		listpnew=(ptag_t)calloc(1,sizeof(tag_t));//�����н������ռ�
		listpnew->p=pnew;
		if(NULL==tree)
		{
			tree=pnew;//���ĸ�
			phead=listpnew;//����ͷ
			ptail=listpnew;//����β
			pcur=listpnew;
			continue;
		}else{
			ptail->pnext=listpnew;//�½���������ͨ��β�巨
			ptail=listpnew;//ptailָ�����β��
		}//pcurʼ��ָ��Ҫ����Ľ���λ��
		if(NULL==pcur->p->lchild)//��ΰ��½�������
		{
			pcur->p->lchild=pnew;//���½��ŵ�Ҫ����������
		}else if(NULL==pcur->p->rchild)
		{
			pcur->p->rchild=pnew;//���½��ŵ�Ҫ��������ұ�
			pcur=pcur->pnext;//���Ҷ����˽���pcurָ����е���һ��
		}
	}
    
	InOrder(tree);
	printf("\n");
    PostOrder(tree);
    printf("\n");
	LevelOrder(tree);
     
} 
