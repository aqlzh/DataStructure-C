#include  <stdio.h>
#include <stdlib.h>

int main(){
	
	char *p;
	int n ;
	char c ;
    scanf("%d",&n);
    p = (char *)malloc(n);
    scanf("%c",&c);//ע����scanf��gets�м�ʹ��scanf("%c",&c),ȥ������
    gets(p);
    printf("%s",p) ;
    return 0 ;
} 
