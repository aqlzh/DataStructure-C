#include <stdio.h>


// ±©Á¦Ã¶¾Ù 
int main(){
	
	int m ;
	int num =0 ; 
	for(int i=1 ; i<= 10;i++){
		for(int j = 1 ; j <= 20 ;j++){
			for(int k=1; k <= 50 ;k++){
		        m = 40 - i -j -k ;
				if(10*i+5*j+2*k + m == 100 && m>0){
					num++ ;
				}		
			}
		}
	}
	printf("%d",num) ;
	return  0 ;
}
