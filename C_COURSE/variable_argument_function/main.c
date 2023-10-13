#include <stdio.h>
#include <stdarg.h>

void print (char* str, ...);

int main (void)
{
    print("String: %d %d %d", 2, 5);
}

void print (char* str, ...)
{
    va_list var_list;
    va_start(var_list, str);
    while(*str != 0)
    {
        if (*str == '%')
        {
            str++;
            switch (*str)
            {
            case 'd':
                printf("%d", va_arg(var_list, int));
                break;
            case 'c':
                printf("%c", (char)va_arg(var_list, int));
                break;
            case 'f':
                printf("%f", (float)va_arg(var_list, double));
                break;
            default:
                break;
            }
        }
        else
        {
            print("%c", *str);
        }

        str++;
    }
}
