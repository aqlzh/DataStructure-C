#include  <stdio.h>
#include <stdlib.h>

int main(){
	
	char *p;
	int n ;
	char c ;
    scanf("%d",&n);
    p = (char *)malloc(n);
    scanf("%c",&c);//注意在scanf和gets中间使用scanf("%c",&c),去除换行
    gets(p);
    printf("%s",p) ;
    return 0 ;
} 
