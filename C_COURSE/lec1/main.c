#include <stdio.h>

int main (void)
{
	
	int x, y;
	printf("Please enter first number: ");
	scanf("%d", &x);
	printf("Please enter second number: ");
	scanf("%d", &y);
	printf("%d + %d = %d\n", x, y, x+y);
	printf("%d - %d = %d\n", x, y, x-y);
	printf("%d * %d = %d\n", x, y, x*y);
	printf("%d / %d = %f\n", x, y, x/(float)y);
	printf("%d %% %d = %d\n", x, y, x%y);
	printf("%d & %d = %d\n", x, y, x&y);
	printf("%d | %d = %d\n", x, y, x|y);
	printf("%d ^ %d = %d\n", x, y, x^y);
	printf("%d > %d = %d\n", x, y, x>y);
	printf("%d < %d = %d\n", x, y, x<y);
	printf("%d == %d = %d\n", x, y, x==y);
	
	
	
	//int x = 10;
	//int y;
	/*
		y = x;
		x = x+1;
	*/
	//y = x++; // x = (11) and y = (10)
	/*
		x = x+1;
		y = x;
	*/

	//y = ++x; // x = (12) and y = (12)
}
 