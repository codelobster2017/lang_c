#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include <string.h>



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

void printf_char_array(char * arr, int size)
{
	for (int i = 0; i< size; i++)
	{
		printf("%c ", arr[i]);
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
	FILE *open;
	char word1[100];
	char word2[100];
	int r;
	char name[] = "file.txt";
	char name2[] = "file1.txt";
	
	open = fopen(name, "r");
	if(open == NULL)
		return 1;
	
	printf("1. input ");
	if((r = fscanf(open, "%s %s", word1, word2))>0)
	{
		printf("Word1 = %s Word2 = %s\n", word1, word2);
		char result[100];
		int k = 0;
		for(int i = 0; i<strlen(word1); i++)
		{
			int num = 0;
			for(int j = 0; j < strlen(word2); j++)
			{
				
				if(word1[i] == word2[j])
				{
					num++;
				}
				for(int n = 0; n < i; n++)
				{
					if(word1[i] == word1[n])
					{
						num++;
					}
				}
				for(int n = i+1; n < strlen(word1); n++)
				{
					if(word1[i] == word1[n])
					{
						num++;
					}
				}
			}

			if(num == 1)
			{
				result[k] = word1[i];
				k++;
			}
		}
		printf("result = ");
		printf_char_array(result, k);
	}
	
	open = fopen(name2, "r");
	if(open == NULL)
		return 1;
	printf("\n----------------------------------------");
	if((r = fscanf(open, "%s", word1))>0){
		printf("\n2. input word = %s", word1);
		for (int i = 0; i < strlen(word1); i++)
		{
			if(word1[i] == 'a')
				word1[i] = 'b';
			else if(word1[i] == 'A')
				word1[i] = 'B';
			else if(word1[i] == 'b')
				word1[i] = 'a';
			else if(word1[i] == 'B')
				word1[i] = 'A';
		}
		printf("\nresult        = %s", word1);
	}
	return 0;
}
