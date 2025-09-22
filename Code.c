#define _USE_MATH_DEFINES
#include <math.h>
#include<stdio.h>

/**
* @brief Рассчитывает значение функции A
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитанное значение
*/
double defA(double x, double y, double z);
/**
* @brief Рассчитывает значение функции B
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитанное значение
*/
double defB(double x, double y, double z);

/**
* @brief Точка входа в программу
* @return Возвращает если программа выполнена корректно
*/
int main(void)
{
	/*объявляем переменные*/
	const double x = -2.9;
	const double y = 15.5;
	const double z = 1.5;


	/*вывод с нужной точностью*/
	printf("defA = %.6f \n", defA(x, y, z));
	printf("defB = %.6f \n", defB(x, y, z));
	return 0;
}

double defA(double x, double y, double z)
{
	double a = (double)pow(x * x + y, 0.5) - y * y * ((x + z) / x);
	return a;
}

double defB(double x, double y, double z)
{
	double b = x * x * x - (x / (double)pow(z * z + y * y, 0.5));
	return b;
}


