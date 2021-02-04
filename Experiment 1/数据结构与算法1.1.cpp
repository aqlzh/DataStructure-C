#include <stdio.h>
#include <math.h>
int main() 
{
	int x;
	double sum;
	printf("please input num\n") ;
	scanf("%d", &x);
	
	// 运用单循环 
	for(int n = 1; n <= x; n++)
	{
		sum += pow(-1, (n - 1)) * (1 / pow(x, (n-1))); 
	}
	
	printf("%0.3lf", sum); 
	return 0;
}

