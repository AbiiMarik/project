#include "functions.h"

int iters; //количество итераций

double root(double f(double), double g(double), double a, double b, double eps1)
{
    double ep = 1e-10;
    double c = (a + b) / 2; //середина отрезка
    double Fa = f(a) - g(a); //значение функции  F(х) = f(х) - g(х) в точке а
    int za = 0, zc = 0; //знак функции  F(х) = f(х) - g(х) в точке а, с
    if (Fa > ep)
        za = 1;
    else
        {
            if (Fa < -ep)
                za = -1;
        }
    double Fc = f(c) - g(c); //значение функции  F(х) = f(х) - g(х) в точке с
    if (Fc > ep)
        zc = 1;
    else
        {
            if (Fc < -ep)
                zc = -1;
        }
    double len = b - a; //длина отрезка
    while (len >= eps1) //пока длина отрезка больше заданного значения, будем выполнять деление отрезка пополам и искать корень
    {
        if (!zc)
            break;
	iters++; //увеличение количества итераций для нахождения корня
        if (za * zc < 0) //выбираем подходящий отрезок из [a,c], [c, b]
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

