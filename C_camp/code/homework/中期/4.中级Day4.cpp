#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;
typedef struct lnode {

	Elemtype data;
	struct lnode* next;

}lnode ,*linklist;
linklist head(linklist  &L) {

	linklist s; //ͷ�巨
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
	int x; //β�巨
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
		printf("%d", L->data);//��ӡ��ǰ�������
        L = L->next;//ָ����һ�����
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
