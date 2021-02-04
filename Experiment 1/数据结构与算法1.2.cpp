#include <stdio.h>
int main() 
{
	int x;
	double y = 1, z;
	double sum;
	printf("please input num\n") ;
	scanf("%d", &x);
	
	
	// 运用双重for 循环 
	for(int n = 1; n <= x; n++)
	{
		if(n == 1) 
		{
			z = y;
		} else {
			for(int m = 1; m < n; m++) 
			{
				y *= (double) 1 / x;
			}
		}
		
		
		if(n % 2 == 1) 
		{ 
			z = y;
		} else {
			z = -1 * y; 
		}
		
		sum += z; 
	}
	
	printf("%0.3lf", sum); 
	return 0;
}

