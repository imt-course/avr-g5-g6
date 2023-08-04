#include <stdio.h>
#include "math.h"

void printMyName (void);
void printNumber (int number);
int getTemperature (void);
void swap(void);
int isPrime(int number);
int reverseNumber (int number);
int x = 3, y = 5;

void swap(void)
{
    int temp = x;
    printf("function: BEFORE: x = %d, y = %d\n", x, y);
    x = y;
    y = temp;
    printf("function: AFTER: x = %d, y = %d\n", x, y);
}

int main (void) {
    int x;
    printf("Please enter number: ");
    scanf("%d", &x);
    printf("%d\n", fib(x));
    printf("%d\n", fibRecursion(x));

    /*
    printf("BEFORE: x = %d, y = %d\n", x, y);
    swap();
    printf("AFTER: x = %d, y = %d\n", x, y);
    */

    /*
    printMyName();
    printNumber(5);
    printNumber(getTemperature());
    */

    /*
    int x, y;
    printf("Please enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("%d! = %d\n", x, factorial(x));
    printf("%d! = %d\n", y, factorial(y));
    printf("%d + %d = %d\n", x, y, add(x,y));
    printf("%d - %d = %d\n", x, y, sub(x,y));
    printf("%d * %d = %d\n", x, y, mul(x,y));
    printf("%d / %d = %f\n", x, y, div(x,y));
    printf("%d power %d = %d\n", x, y, power(x,y));
    */
}

void printMyName (void) 
{
    printf("Ahmed Hassan\n");
}
void printNumber (int number)
{
    printf("%d\n", number);
}
int getTemperature (void)
{
    return 10;
}

int isPrime(int number)
{
    int result = 1;
    int i;
    for (i=2; i<number/2; i++)
    {
        if (number%i == 0)
        {
            result = 0;
            break;
        }
    }
    return result;
}

int reverseNumber (int number)
{
    int result = 0;
    while (number > 0)
    {
        result = (result*10) + (number%10);
        number /= 10;
    }
    return result;
}