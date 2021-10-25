#include  <stdio.h>
#include <stdlib.h>
int main(){
	
	char * p;
	p = (char*)malloc(100) ;
	fgets(p,100,stdin) ;
	printf("%s",p) ; 
} 
