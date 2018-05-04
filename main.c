#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

extern double f1(double);
extern double f2(double);
extern double f3(double);
extern double f4(double);
extern double f5(double);
extern double f6(double);

int main(int argc, char **argv)
{
	while (argc > 1)
	{
	  double q3 = root(f4, f5, 0, 4, 0.0000000001);
double q2 = root(f4, f6, -1, 1 , 0.0000000001);
double q1 = root(f5, f6, 0, 2 , 0.0000000001);
double w1 = integral(f4, 0, 4, 0.0000000001);
double w2 = integral(f5,  0, 1 , 0.0000000001);
double w3 = integral(f6,  -2, 2 , 0.0000000001);


	  double w = integral(f1, 2, 4 ,0.00013);
	  printf(" %.6f %.6f %.6f %.6f ", q3, q1, q2, f4(-1));
 printf(" %.6f %.6f %.6f ", w3, w2, w1);
	  argc--;
	}
return 0;
}



