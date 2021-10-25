#include <stdio.h>

struct student{
	
	int id ;
	char name[10];
	char sex ;
	
};



int main(){
	
	struct student s1  ;
	
	scanf("%d %s %c",&s1.id,&s1.name,&s1.sex) ;
    printf("%d %s %c",s1.id,s1.name,s1.sex) ;	
	return 0 ;
} 
