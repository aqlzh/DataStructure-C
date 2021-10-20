#include <stdio.h>

int main(){
	
	int a ;
	scanf("%d",&a) ;
	
	int tmp = a ;
	int res = 0 ; 
	
	while(tmp!=0){
		
	    res = res * 10 + tmp%10 ; 
	    tmp = tmp /10 ;
	}
	
	if(res == a){
		printf("yes") ;
	} else {
		printf("no") ;
	}
	
} 
