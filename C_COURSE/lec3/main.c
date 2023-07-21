#include <stdio.h>

int main (void) {
	
	/*
	int x = 0;
	printf("%d ", x);
	x++;
	printf("%d ", x);
	x++;
	printf("%d ", x);
	x++;
	printf("%d ", x);
	x++;
	printf("%d ", x);
	x++;
	printf("%d ", x);
	x++;
	printf("%d ", x);
	x++;
	printf("%d ", x);
	x++;
	printf("%d ", x);
	x++;
	printf("%d ", x);
	x++;
	*/

	/*
	int x = 0;
	while (x <= 10) 
	{
		printf("%d\n", x);
		x++;
	}
	printf("After While");
	*/
	
	/*
	int n1, n2, result, right_result;
	printf("Enter two numbers: ");
	scanf("%d %d", &n1, &n2);
	right_result = n1*n2;
	printf("Enter %dx%d = ", n1, n2);
	scanf("%d", &result);
	while (result != right_result) 
	{
		printf("Wrong answer, try again: ");
		scanf("%d", &result);
	}
	printf("Right Answer");
	*/
	
	/*
	int x, n=1;
	printf("Please enter number: ");
	scanf("%d", &x);
	while (x < 1)
	{
		printf("Invalid number, enter another number: ");
		scanf("%d", &x);
	}
	while (n <= x)
	{
		printf("%dx%d = %d\n", x, n, x*n);
		n++;
	}
	*/
	
	/*
	int x, temp, result = 1;
	printf("Please enter number: ");
	scanf("%d", &x);
	temp = x;
	while (temp > 1)
	{
		result *= temp;
		temp--;
	}
	if (x >= 0)
	{
		printf("%d! = %d", x, result);
	}
	else
	{
		printf("Invalid number");
	}
	*/

	/*
	int x, temp;
	int decimal_count = 0;
	int binary_count = 0;
	int hex_count = 0;
	printf("Please enter number: ");
	scanf("%d", &x);
	if (x < 0) {
		x *= -1;
	}

	temp = x;
	do
	{
		temp /= 10;
		decimal_count++;
	} while (temp > 0);

	temp = x;
	do
	{
		temp >>= 1;
		binary_count++;
	} while (temp > 0);

	temp = x;
	do
	{
		temp >>= 4;
		hex_count++;
	} while (temp > 0);

	printf("Decimal Count = %d\n", decimal_count);
	printf("Binary Count = %d\n", binary_count);
	printf("Hex Count = %d\n", hex_count);
	*/

	/*
	int x;
	for (x = 0; x < 10; x++) {
		printf("%d\n", x);h
	}
	*/

	/*
	int number, i, count, sum = 0;

	printf("Enter numbers count: ");
	scanf("%d", &count);
	i=0;
	for (; i<count; i++){
		printf("Enter number %d: ", i+1);
		scanf("%d", &number);
		sum += number;
	}
	printf("Sum = %d\n", sum);
	printf("Avg = %.2f\n", (float)sum/count);
	*/

	/*
	int n1, n2, result, right_result;
	printf("Enter two numbers: ");
	scanf("%d %d", &n1, &n2);
	right_result = n1*n2;
	printf("Enter %dx%d = ", n1, n2);
	scanf("%d", &result);
	while (1) 
	{
		printf("Wrong answer, try again: ");
		scanf("%d", &result);
		if (result == right_result) {
			break;
		}
	}
	printf("Right Answer");
	*/

	int number, i, count, sum = 0;
	printf("Enter numbers count: ");
	scanf("%d", &count);
	/* adsadf */
	// scfsafd
	for (i=0; i<count; i++){
		printf("Enter number %d: ", i+1);
		scanf("%d", &number);
		sum += number;
	}
	printf("Sum = %d\n", sum);
	printf("Avg = %.2f\n", (float)sum/count);

}