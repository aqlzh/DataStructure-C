#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OVERFLOW -1
#define num 100
#define OK 1


typedef int Status;
typedef char ElemType;

typedef struct node{
	ElemType data;
	struct node *lchild,*rchild;
}BinTNode,*BinTree;



Status CreateTree(BinTree &bt)
{
	//ABC##DE#G##F###
	char s;
	scanf("%c",&s);

	if(s=='#')  bt=NULL;
	else
	{
		if(!(bt=(BinTree )malloc(sizeof(BinTNode))))  exit(OVERFLOW);
		bt->data=s;
		CreateTree(bt->lchild);
		CreateTree(bt->rchild);
	}	
	return OK;

}


Status InOrder(BinTree bt)
{

	BinTree ptr[20];int top=-1;
	while(bt||top!=-1){
		while(bt){
			ptr[++top]=bt;
			bt=bt->lchild;
		
		}
		if(top!=-1){
			bt=ptr[top--];
				printf("%c",bt->data);
			bt=bt->rchild;
		
		}
	
	}
	
	return OK;

}

Status LevelOrder(BinTree bt)
{
    if (bt== NULL)      return OK;
    BinTree s[num];
    int front, rear;
    front = rear = 0; 
    s[rear++] = bt; 
    while (front != rear) // 当队列非空时
    {    
		printf("%c",s[front]->data); // 输出队头元素 
        if (s[front]->lchild)
        {       
            s[rear++] = s[front]->lchild; 
        }
        if (s[front]->rchild)
        {         
            s[rear++] = s[front]->rchild; 
        }
		front++;
    }
	return OK;
}

int main()
{		        

                BinTree bt ; 
	            printf("输入先序遍历序列进行创建二叉树：  \n");
				CreateTree(bt);
				printf("二叉树的链式存储结构建立完成！\n");
				printf("该二叉树的中序遍历序列是：");
				InOrder(bt);
				printf("\n");	
				printf("该二叉树的层序遍历序列是：");
				LevelOrder(bt);
				printf("\n");		
}

