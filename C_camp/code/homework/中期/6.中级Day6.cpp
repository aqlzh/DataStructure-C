#include <stdio.h>
#define Maxsize 50
#define Maxsize2 5
typedef struct Sqstack {
	int data[Maxsize];
	int top;
}Sqstack;

bool Push(Sqstack& S,int x) {
	while (scanf("%d", &x)) {
		S.top++;
		S.data[S.top] = x;
		//if (S.top == 2)break;
		if (getchar() == '\n')break;
	}
	
	return true;
}
bool PoP(Sqstack& S) {

	if (-1 == S.top) {
		printf("false");
	}
	while (S.top > -1) {
		printf("%2d", S.data[S.top]);
		S.top--;
	}
	printf("\n");
	return true;
}

typedef struct {
	int rear, front;
	int data[Maxsize2];
}SqQueue;
bool InitQuee(SqQueue &S) {
	S.rear = S.front = 0;
	return true;
}
bool Insert(SqQueue &Q,int x) {
	if ((Q.rear + 1)%Maxsize2 == Q.front) {
		return false;
	}
	
	while (scanf("%d", &Q.data[Q.rear]))
	{	
		Q.rear++;
		
		if (Q.rear  % Maxsize2 == Q.front) {
			return false;
		}
		if (getchar() == '\n')break;
	}
	return true;
}
bool PrintSQ(SqQueue Q) {
	if (Q.rear == Q.front) {
		return false;
	}
	int x = Q.front;
	while (Q.front<Q.rear&&(Q.front+1)%Maxsize2!=x) {
		printf("%2d", Q.data[Q.front]);
		Q.front++;
	}
}
int main() {
	Sqstack S;
	S.top = -1;
	int x=0;
	Push(S,x);	
	SqQueue Q;
	InitQuee(Q);
	bool ret;

	
	PoP(S);
ret = Insert(Q, x);
	if (ret==false) {
		printf("false\n");
	}

	PrintSQ(Q);

}

