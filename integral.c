#include <math.h>
#include "functions.h"
double integral(double f(double), double a, double b, double eps2)
{
    int n = 32;
    double s = f(a) + f(b);
    double h = (b - a)/n;
    for(int i = 1; i < n; i++)
    {
        s += (2*(i%2) + 2) * f(a + i * h);
    }
    double s2 = s;
    s = h * s / 3;
    h /= 2;
    for(int i = 1; i < 2 * n; i++)

       s2 += (4*(i%2) - ((i + 1)%2)*(i % 4)) * f(a + i * h);


    s2 = h * s2 / 3;

    double d = fabs(s2 - s) / 15;


    while (d >= eps2)
    {
        n *= 2;
        s = s2;
        s2 = 3 * s2 / h;
        h /= 2;
        for(int i = 1; i < 2 * n; i++)
            s2 += (4*(i%2) - ((i + 1)%2)*(i % 4)) * f(a + i * h);
        s2 = h * s2 /3;
        d = fabs(s2 - s) / 15;
    }
    return s2;
}

