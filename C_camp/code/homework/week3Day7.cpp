#include<stdio.h>

int fun(int a)  ;

int main(){
	
	int n ;
	scanf("%d",&n) ;
	printf("%d\n",fun(n))  ;
	return 0 ;
} 


int fun(int a){
	if(a == 1){
		return 1 ;
	} else {
		return a * fun(a-1) ; 
	}
 	
}
