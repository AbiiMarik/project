#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int iters = 0;

int main(int count, char **key)
{
	int i = 0;
	double eps1 = 0.00001, eps2 = 0.00001;
	int iters1 = 0, iters2 = 0, iters3 = 0; //количество итераций на решени уравнений f1=f2, f2=f3, f3=f1
	while (++i < count) //цикл, в котором обрабатываются ключи
	{
	printf("\n");
	if(!strcmp(key[i], "-help")) //печать ключей
		printf("-help \n-test_root \n-test_integral \n-ans \n-roots \n-iters \n");
	 
	if(!strcmp(key[i], "-ans")) //подсчет и вывод искомой площади 
	{		
		iters = 0;
	        double q3 = root(f3, f1, 2.1, 3, eps1);
		iters1 = iters;
		iters = 0;
		double q2 = root(f2, f3, 3, 5, eps1);
		iters2 = iters;
                iters = 0;
		double q1 = root(f1, f2, 2, 7, eps1);
		iters3 = iters;
		double ans = integral(f3, q3, q2, eps2);
		ans += integral(f2, q2, q1, eps2);
		ans -= integral(f1, q3, q1, eps2);
	 	printf("%f\n", ans);
	}
		
	if(!strcmp(key[i], "-iters"))  //вывод количества итераций на решение уравнений
        {
	 	printf("f1, f2: %d\nf2, f3: %d\nf3, f1: %d\n", iters1 + 1, iters2 + 1, iters3 + 1);
	}
	if(!strcmp(key[i], "-roots")) //вывод точек пересечения кривых и подсчет итераций на их вычисление
        {
		iters = 0;
	        double q3 = root(f3, f1, 2.1, 3, eps1);
		iters1 = iters;
		iters = 0;
		double q2 = root(f2, f3, 3, 5, eps1);
		iters2 = iters;
                iters = 0;
		double q1 = root(f1, f2, 2, 7, eps1);
		iters3 = iters;
		printf("f1, f2: %f \nf2, f3: %f \nf3, f1: %f\n", q1, q2, q3);
	}
	if(!strcmp(key[i], "-test_root")) //тестирование функции root (пользователь задает номера функций и отрезок для поиска корней)
    	{
		i++;
		int n1 = atoi(key[i++]);
 		int n2 = atoi(key[i++]);
		double a = atof(key[i++]), b = atof(key[i]);
		if (n1 == 4 && n2 == 6)
	       	{
			 double q = root(f6, f4, a, b, eps1);
			 printf("%f\n", q);
		}
			 
		if (n1 == 5 && n2 == 6)
	       	{
			 double q = root(f6, f5, a, b, eps1);
			 printf("%f\n", q);
		}
		
	       if (n1 == 4 && n2 == 5)
	       	{
			 double q = root(f4, f5, a, b, eps1);
			 printf("%f\n", q);
		}
	}
	if(!strcmp(key[i], "-test_integral"))  //тестирование функции integral (пользователь задает номер функции и пределы интегрирования)
        {
		i++;
		int n1 = atoi(key[i++]);
		double a = atof(key[i++]), b = atof(key[i]);
		if (n1 == 4)
		{
			double w = integral(f4, a, b, eps2);
			printf("%f\n", w);
		}
		if (n1 == 5)
		{
			double w = integral(f5, a, b, eps2);
			printf("%f\n", w);
		}

		if (n1 == 6)
		{
			double w = integral(f6, a, b, eps2);
			printf("%f\n", w);
		}
	}
	}
return 0;
}



