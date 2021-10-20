#include <iostream>
#include <string>
#include <string.h>
using namespace std ;

int main(){
 
	char a[20] ;
	scanf("%s",a) ;
	
	char b[20]  ={0};
	int len = strlen(a) ;
	
	for(int i = len ; i > 0 ;i--){
		int j = 0 ;
		b[j] = a[i] ;
		j++ ;
 	}
	
    for(int i =0 ; i < len ;i++){
    	cout << b[i] << endl ;
    	
	} 
	return 0 ;
} 
