#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;
typedef struct lnode {

	Elemtype data;
	struct lnode* next;

}lnode ,*linklist;
linklist head(linklist  &L) {

	linklist s; //头插法
	int x;
	L = (linklist)malloc(sizeof(lnode));
	L->next = NULL;
	scanf("%d", &x);
	while (x!=9999)
	{
		s = (lnode*)malloc(sizeof(lnode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
linklist tail(linklist &B) {
	int x; //尾插法
	B = (linklist)malloc(sizeof(lnode));
	linklist s, r =B;
	scanf("%d", &x);
	while (x !=9999)
	{
		s= (lnode*)malloc(sizeof(lnode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);

	}
	r->next = NULL;
	return B;
}


void print(linklist L)

{
	L = L->next;
    while (L != NULL)

	{
		printf("%d", L->data);//打印当前结点数据
        L = L->next;//指向下一个结点
        if (L != NULL)

		{
			printf(" ");

		}

	}

	printf("\n");

}

int main (){

	linklist L;
	linklist B;
	head(L);
	tail(B);
	print(L);
	print(B);
	
	
}
