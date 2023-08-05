#include <stdio.h>
#include "StdTypes.h"

u8 m = 3;

static void func (void)
{
    static u8 x = 0;
    x++;
    printf("%d\n", x);
}