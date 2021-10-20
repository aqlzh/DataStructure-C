#include  <stdio.h>

int change(int i)  ;

int main(){
	
	int i ;
	scanf("%d",&i) ;
	printf("%d",change(i)) ;
	
} 


int change(int i){
	return i/2 ;
}
