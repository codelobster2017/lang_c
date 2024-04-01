#include <stdio.h>
#include <inttypes.h>
#include <math.h>

enum {SIZE = 5};
float average(int * a, int size)
{
	int summ = 0;
	for(int i = 0; i < size; i++)
	{
		summ += a[i];
	}
	return summ / size;
}

void scanf_in_int_array(int * arr, int size)
{
	for (int i = 0; i< size; i++)
	{
		scanf("%d", &arr[i]);
	}
}

int min_num(int * arr, int size)
{
	int start = arr[0];
	for(int i = 1; i < size; i++)
	{
		if(start > arr[i])
			start = arr[i];
	}
	return start;
}

int main(int argc, char ** argv){
	int a[5];
	
	printf("1. Average\n");
	scanf_in_int_array(a, SIZE);
	printf("%.3f\n", average(a, SIZE));
	
	printf("2. Min num\n");
	scanf_in_int_array(a, SIZE);
	printf("%d\n", min_num(a, SIZE));
	
	
	return 0;
}
