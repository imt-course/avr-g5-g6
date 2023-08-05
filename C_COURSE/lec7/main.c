#include <stdio.h>
#include "StdTypes.h"

  extern u8 m;
static void func (void);

int main (void) 
{
    /*
    int x = 0xAABBCCDD;
    unsigned char* ptr = (unsigned char*)&x;
    printf("%p\n", ptr);
    printf("%x", *ptr);
    */

   /*
   unsigned char x = -1;
   if (x == 129)
   {
    printf("Signed Magnitude");
   }
   else if (x == 254)
   {
    printf("1's Complement");
   }
   else if (x == 255)
   {
    printf("2's Complement");
   }
   else 
   {
    printf("ERROR");
   }
   */

  /*
  printf("size of char              = %d\n", sizeof(char         ));
  printf("size of short int         = %d\n", sizeof(short int    ));
  printf("size of int               = %d\n", sizeof(int          ));
  printf("size of long int          = %d\n", sizeof(long int     ));
  printf("size of long long int     = %d\n", sizeof(long long int));
  printf("size of float             = %d\n", sizeof(float        ));
  printf("size of double            = %d\n", sizeof(double       ));
  printf("size of long double       = %d\n", sizeof(long double  ));
  printf("size of u32               = %d\n", sizeof(u32          ));
    */
/*
   const u8 x = 5;
   u8 y = 7;
   const u8* const ptr = &x;
   printf("x = %d\n", x);
   ptr = &y;
   *ptr = 10;
   x = 10;
   printf("x = %d\n", x);
   */
  printf("m = %d\n", m);
  func();
  func();
  func();
  func();
  func();
  func();
  func();
  func();

}

