double big_pi;
long long int lngint;

#include <stdio.h>
#include <locale.h>


int main(int argc, char ** argv){
	setlocale(LC_ALL, "Rus");
	printf("������ 1. ����� ���� �����\n");
	
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d+%d+%d=%d\n", a, b, c, a+b+c);
	
	printf("������ 2. ����� � ������������ ���� �����\n");
	
	scanf("%d %d %d", &a, &b, &c);
	printf("%d+%d+%d=%d\n", a, b, c, a+b+c);
	printf("%d*%d*%d=%d\n", a, b, c, a*b*c);
	
	printf("������ 3. �������� ���� �����\n");
	
	scanf("%d %d", &a, &b);
	printf("%d",a-b);
}
