double big_pi;
long long int lngint;

#include <stdio.h>
#include <locale.h>


int main(int argc, char ** argv){
	setlocale(LC_ALL, "Rus");
	printf("Задача 1. Сумма трех чисел\n");
	
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d+%d+%d=%d\n", a, b, c, a+b+c);
	
	printf("Задача 2. Сумма и произведение трех чисел\n");
	
	scanf("%d %d %d", &a, &b, &c);
	printf("%d+%d+%d=%d\n", a, b, c, a+b+c);
	printf("%d*%d*%d=%d\n", a, b, c, a*b*c);
	
	printf("Задача 3. Разность двух чисел\n");
	
	scanf("%d %d", &a, &b);
	printf("%d",a-b);
}
