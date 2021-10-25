#include <stdio.h>

int main(){
	int i ;
	char j ;
	double k ;
	scanf("%d %c %lf",&i,&j,&k) ;
	
	double temp_i = (double) i ;
	double temp_j = (double) j ;

//	printf("%lf\n",temp_i) ;
//	printf("%lf\n",temp_j) ;
//	printf("%lf\n",k) ;
//	printf("========") ;
	printf("%.2lf",temp_i+temp_j+k) ;
	return 0 ;
} 
