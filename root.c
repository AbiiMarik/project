#include <stdio.h>
#include "functions.h"

double root(double f(double), double g(double), double a, double b, double eps1)
{
    double ep = 1e-10;
	printf("!");
    double c = (a + b) / 2;
    double Fa = f(a) - g(a);
    int za = 0, zc = 0;
    if (Fa > ep)
        za = 1;
    else
        {
            if (Fa < -ep)
                za = -1;
        }
    double Fc = f(c) - g(c);
    printf(" %f %f",g(1.5),g(0.2671));
    if (Fc > ep)
        zc = 1;
    else
        {
            if (Fc < -ep)
                zc = -1;
        }
    double len = b - a;
    while (len >= eps1)
    {
        if (!zc)
            break;
        if (za * zc < 0)
            b = c;
        else
        {
            za = zc;
            a = c;
        }
        c = (a + b) / 2;
        Fc = f(c) - g(c);
        len = b - a;
        if (Fc > ep)
            zc = 1;
        else
        {
            if (Fc < -ep)
                zc = -1;
            else
                zc  = 0;
        }
    }
    return c; 
}

