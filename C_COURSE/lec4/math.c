

/* Function Defenition / Implementation */
unsigned int factorial (unsigned int number)
{
    int result = 1;
    while (number > 1)
    {
        result *= number;
        number--;
    }
    return result;
}

int add (int n1, int n2)
{
    return (n1+n2);
}

int sub (int n1, int n2)
{
    return (n1-n2);
}

int mul (int n1, int n2)
{
    return (n1*n2);
}

float div (int n1, int n2)
{
    float result = 0;
    if (n2 != 0)
    {
        result = (float)n1/n2;
    }
    return result;
}

int power (int number, unsigned int exp)
{
    int result = 1;
    if (number != 1)
    {
        while (exp > 0)
        {
            result *= number;
            exp--;
        }
    }
    return result;
}

unsigned int factorialReursion (unsigned int number)
{
    if ((number == 0) || (number == 1))
    {
        return 1;
    }
    else
    {
        return (number*factorialReursion(number-1));
    }
}

unsigned int fib (unsigned int number)
{
    int n0 = 0, n1 = 1;
    int temp;
    int counter = 2;
    if ((number == 0) || (number == 1))
    {
        return number;
    }
    else
    {
        while (1)
        {
            if (counter == number) {
                return (n0 + n1);
            }
            else {
                temp = n0 + n1;
                n0 = n1;
                n1 = temp;
                counter++;
            }
        }

    }
    
}


unsigned int fibRecursion (unsigned int number)
{
    if ((number == 0) || (number == 1))
    {
        return number;
    }
    else
    {
        return (fibRecursion(number-1) + fibRecursion(number-2));

    }
    
}