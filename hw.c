double big_pi;
long long int lngint;

#include <stdio.h>
#include <inttypes.h>
#include <math.h>

void print_num(int num)
{
	if(num/10 > 0)
		print_num(num/10);
	printf("%d ", num%10);
}

void print_from_a_to_b(int a, int b)
{
	if(a > b)
	{
		printf("%d ", b);
		b+=1;
		print_from_a_to_b(a, b);
	}
	else if(a < b)
	{
		printf("%d ", a);
		a+=1;
		print_from_a_to_b(a++, b);
	}
	else
		printf("%d ", a);
}

int main(int argc, char ** argv){
	
	int a, b;
	printf("1. void print_num \n");
	scanf("%d", &a);
	print_num(a);
	
	
	printf("\n2. From A to b\n");
	scanf("%d %d", &a, &b);
	print_from_a_to_b(a, b);
	return 0;
}
