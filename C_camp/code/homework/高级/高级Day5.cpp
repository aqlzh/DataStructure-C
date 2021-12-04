#include  <stdio.h>


int main(){
	
	int arr[5] ={0} ;
	int res = 0 ;
	for(int i = 0 ; i< 5 ;i++){
		scanf("%d",&arr[i]) ;
	}

   	for(int i = 0 ; i< 5 ;i++){
	    res ^= arr[i] ;		 
	}
	printf("%d",res) ;
	
	return 0 ;
}
