#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Reverse(char str[]);
int main()
{
    char str[100];
    char t [100] ;
   
    gets(str);
    strcpy(t,str) ;
    Reverse(str);
    
    if(strcmp(t,str) == 0){
    	printf("%d",0) ;
	} else if(strcmp(t,str) == -1){
		printf("%d",-1) ;
	} else {
     	printf("%d",1) ;
	}
    
}
void Reverse(char str[]){
    int n=strlen(str);
    int i;
    char temp;
    for(i=0;i<(n/2);i++){
        temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
}
 
