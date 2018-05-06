#include <math.h>

double integral(double f(double), double a, double b, double eps2)
{
    int n = 32;//начальное счисло разбиение отрезка 
    double Sab = f(a) + f(b);
    double h = (b - a)/n;
    double Sever = 0, Sodd = 0; //суммы значений функции fi=f(a+i*h) при четных и нечетных 0<i<n соответственно
    for (int i = 2; i < n - 1; i+=2)
        Sever += f(a + h * i);
    for (int i = 1; i < n; i+=2)
        Sodd += f(a + h * i);
    double In = (4 * Sodd + 2 * Sever + Sab) * h / 3; // вычисление значения суммы In
    n *= 2; // пересчет значений Sodd, Sever, h для суммы I2n
    h /= 2;
    Sever = Sodd + Sever; 
    Sodd = 0;
    for (int i = 1; i < n; i+=2)
        Sodd += f(a + h * i);
    double I2n = (4 * Sodd + 2 * Sever + Sab) * h / 3;
    double d = fabs(I2n - In); //разность между In и I2n
    eps2 *= 15;
    while (d >= eps2) //увеличиваем число разбиений, пока разность между In и I2n не станет меньше заданного числа
    {
        In = I2n;
        n *= 2;
        h /= 2;
        Sever = Sodd + Sever;
        Sodd = 0;
        for (int i = 1; i < n; i+=2)
            Sodd += f(a + h * i);
        I2n = (4 * Sodd + 2 * Sever + Sab) * h / 3;
        d = fabs(I2n - In);
    }
    return I2n;
}

