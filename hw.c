#include <stdio.h>
#include <inttypes.h>
#include <math.h>



void scanf_in_int_array(int * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
}

void scanf_in_int_array_unknown_size(int * arr, int *size)
{
	int i   = 0;
	
	while(1)
	{
		if(scanf("%d", &arr[i]) == 1)
		{
			i ++;
		}
		if(getchar() == '\n'){
			break;
		}
	}
	*size = i;
}

void printf_int_array(int * arr, int size)
{
	for (int i = 0; i< size; i++)
	{
		printf("%d ", arr[i]);
	}
}


void sort_array(int * a, int size)
{

	int temp = 1;
	int num_previous;
	while(temp){
		num_previous = a[0];
		temp = 0;
		for(int i = 1; i < size; i++)
		{
			
			if(num_previous > a[i])
			{
				temp = a[i];
				a[i] = num_previous;
				a[i-1] = temp;
				temp = 1;
				
			}
			else
			{
				num_previous = a[i];
			}
		}
	}

}


void even_begin(int * a, int size)
{
	int i         = 0;
	int temp      = 0;
	int temp_size = 0;
	int temp_arr[size];
	
	while (i < size)
	{
		if(a[i]%2 != 0)
		{
			temp_arr[0] = a[i];
			temp_size = 0;
			for(int j = i+1; j < size; j++)
			{
				if(a[j]%2==0)
				{
					a[i] = a[j];
					for (int n = 0; n <= temp_size; n++)
					{
						a[i+ n + 1] = temp_arr[n];
					}
					break;
				}
				else
				{
					temp_size++;
					temp_arr[temp_size] = a[j];
				}
			}
			temp++;
		}
		i++;
	}


}


int main(int argc, char ** argv){
	int a[5];
	int size = 5;
	printf("1. Sort array\n");
	scanf_in_int_array_unknown_size(a, &size);
	sort_array(a, size);
	printf_int_array(a, size);
	printf("\n");
	
	printf("2. Even begin\n");
	scanf_in_int_array_unknown_size(a, &size);
	even_begin(a, size);
	printf_int_array(a, size);

	return 0;
}
