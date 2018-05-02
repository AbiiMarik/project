#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

extern double f1(double);
extern double f2(double);
extern double f3(double);

int main(void)
{
printf("hello");
  double q = root(f1, f2, 5, 7 , 0.0000000001);
  double w = integral(f2, 2, 4 ,0.00013);
  printf(" %.6f %f",0.345, w);
   printf("Hello world!\n");
    return 0;
}


