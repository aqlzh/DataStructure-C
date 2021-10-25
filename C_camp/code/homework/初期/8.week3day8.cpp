#include <stdio.h>

int main(){
	
	int n ;
	int a[100];
	int num ;
	scanf("%d\n",&n) ;
	
	for(int i =0 ;i<n;i++){
		scanf("%d",&a[i]) ;
	}
	
	for(int i=0 ;i<n;i++){
		if(a[i] ==2){
			num++;
		}
	}
	printf("%d",num) ;
	return 0 ;
} 
