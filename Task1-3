#include<stdio.h>
#include<math.h>
#include<locale.h>

/**
* @brief Вычисляет работу силы тока по формуле
* @param U - напряжение
* @param I - сила тока
* @param Time - время
* @return Рассчитанне значение
*/
double defResist(const double U, const double I, const double Time);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	setlocale(LC_ALL, "");

	const double Time = 1200;
	double I;
	double U;

	printf("Введите силу тока в цепи: ");
	scanf_s("%lf", &I);

	printf("Введите напряжение цепи: ");
	scanf_s("%lf", &U);

	printf("Работа электрического тока в электродвигателе = %.2lf Дж\n", defResist(U, I, Time));

	return 0;
}

double defResist(const double U, const double I, const double Time)
{
	return U * I * Time;
}
