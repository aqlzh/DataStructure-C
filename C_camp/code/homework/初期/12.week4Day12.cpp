#include <stdio.h>

int fun(int n){
	if(n==1 || n==0){
		return 1 ;
	}  
		return fun(n-1) + fun(n-2) ;
	 
}

int main(){
	
	int n ;
	scanf("%d",&n) ;
	printf("%d",fun(n)) ;
	
	
	return 0 ;
} 
