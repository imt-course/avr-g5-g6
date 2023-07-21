#include <stdio.h>

int main (void) {
	/*
	int n;
	printf("Please enter a number: ");
	scanf("%d", &n);
	if (n > 0)
	{
		printf("Positive");
	}
	if (n < 0)
	{
		printf("Negative");
	}
	if (n == 0)
	{
		printf("Equal 0");
	}
	*/
	
	/*
	int grade;
	printf("Please enter your grade: ");
	scanf("%d", &grade);
	if ((grade > 100) || (grade < 0))
	{
		printf("Invalid");
	}
	else if (grade >= 50)
	{
		printf("PASS");
	}
	else
	{
		printf("FAIL");
	}
	*/
	
	/*
	int grade;
	printf("Please enter your grade: ");
	scanf("%d", &grade);
	if ((grade >= 0) && (grade < 50))
	{
		printf("FAIL");
	}
	printf("Hello");
	else if ((grade >= 50) && (grade < 65))
	{
		printf("PASS");
	}
	else if ((grade >= 65) && (grade < 75))
	{
		printf("GOOD");
	}
	else if ((grade >= 75) && (grade < 85))
	{
		printf("VERY GOOD");
	}
	else if ((grade >= 85) && (grade <= 100))
	{
		printf("EXCELLENT");
	}
	else
	{
		printf("INVALID");
	}
	*/
	
	/*
	int hours, salary;
	printf("Please enter your hours: ");
	scanf("%d", &hours);
	if ((hours >= 0) && (hours < 40))
	{
		salary = hours*50*0.9;
	}
	else if (hours == 40)
	{
		salary = hours*50;
	}
	else if ((hours > 40) && (hours <= 60))
	{
		salary = 40*50 + (hours - 40)*60;
	}
	else if (hours > 60)
	{
		salary = 40*50 + (hours - 40)*55;
	}
	else 
	{
		printf("INVALID");
	}
	printf("Salary = %d", salary);	
	*/
	
	int x, y=1;
	printf("Please enter a day number: ");
	scanf("%d", &x);
	switch(x)
	{
		case 1:
			printf("----");
			printf("Saturday\n");
			break;
		case 2:
			printf("Sunday\n");
			break;
		case 3:
			printf("Monday\n");
			break;
		case 4:
			printf("Tuesday\n");
			break;
		case 5:
			printf("Wednesday\n");
			break;
		case 6:
			printf("Thursday\n");
			break;
		case 7:
			printf("Friday\n");
			break;
		default:
			printf("Invalid");
			break;
	}

}