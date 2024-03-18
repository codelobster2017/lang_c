double big_pi;
long long int lngint;

#include <stdio.h>
#include <inttypes.h>


int main(int argc, char ** argv){
	
	int a, b, c, d, e, max, min;
	
	printf("1. Max\n");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	
	max = ((((a > b ? a : b) 
		> c ? (a > b ? a : b) : c) 
			> d ? ((a > b ? a : b) > c ? (a > b ? a : b) : c) : d)
				> e ? (((a > b ? a : b) > c ? (a > b ? a : b) : c) > d ? ((a > b ? a : b) > c ? (a > b ? a : b) : c) : d) : e);
	printf("%d\n", max);  
	
	printf("2. Min\n");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	min = ((((a < b ? a : b) 
		< c ? (a < b ? a : b) : c) 
			< d ? ((a < b ? a : b) < c ? (a < b ? a : b) : c) : d)
				< e ? (((a < b ? a : b) < c ? (a < b ? a : b) : c) < d ? ((a < b ? a : b) < c ? (a < b ? a : b) : c) : d) : e);
	printf("%d\n", min);  
	
	printf("3. Growth\n");
	scanf("%d %d %d", &a, &b, &c);
	if(a < b && b < c) 
		printf("YES\n");
	else
		printf("NO\n"); 
}
