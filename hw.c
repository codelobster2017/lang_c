double big_pi;
long long int lngint;

#include <stdio.h>
#include <inttypes.h>
#include <math.h>


int main(int argc, char ** argv){
	
	int a, b;
	
	printf("1. The square of the number\n");
	scanf("%d %d", &a, &b);
	
	if((a <= 100 && b <= 100) && (a >= -100 && b >= -100))
	{
		int summ = 0;
		
		while(a <= b){
			summ += pow((double_t) a, 2);
			a++;
		}
		printf("Summ = %d\n", summ);
	}
	
	printf("2. Three digits\n");
	scanf("%d", &a);
	int count = 0;
	
	while(a > 0)
	{
		a /= 10;
		count++;
	}
	if(count == 3)
	{
		printf("YES\n");
	}
	else 
	{
		printf("NO\n");
	}
	
	printf("3. Digit parity\n");
	scanf("%d", &a);
	
	int8_t even = 1;
	
	while(a > 0)
	{
		
		int f;
		f = a % 10;
		a /= 10;
		if(f % 2 != 0)
		{
			even = 0;
			break;
		}
	}
	if (even)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
