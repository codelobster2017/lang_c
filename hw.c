double big_pi;
long long int lngint;

#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int amount(int num)
{
	return pow(2, num-1);
}

int GCF(int num1, int num2)
{
	int i = 1;
	int gcf;
	while(num1 >= i && num2 >= i)
	{
		if(num1 % i == 0 && num2 % i == 0)
		{
			gcf = i;
		}
		i++;
	}
	return gcf;
}

int is_happy_number(int n)
{
	
	int summ;
	int multiply = 1;
	
	while(n > 0)
	{
		int current = n % 10;
		summ += current;
		multiply *= current;
		n /= 10;
	}
	return summ == multiply;
}


int main(int argc, char ** argv){
	
	int a, b;
	printf("1. Amount seeds\n");
	scanf("%d", &a);
	printf("%d\n", amount(a));
	
	
	printf("2. GCF\n");
	scanf("%d %d", &a, &b);
	printf("%d\n", GCF(a, b));
	
	
	printf("3. Happy number\n");
	scanf("%d", &a);
	char* res = is_happy_number(a) ? "YES" : "NO";
	printf("%s", res);
}
