#include <stdio.h>

/**
* @brief переводит вес из граммов в унции
* param gram масса в граммах
* @return возвращает массу, переведенную в унции
*/
double getUn(const double gram);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
*/
int main(void)
{
	double gram;
	printf("Введи число");
	scanf("%lf", &gram);

	printf("Масса в грамах: %.2lf грамм\n", gram);
	printf("Масса в унциях: %.2lf унций\n", getUn(gram));

	return 0;
}

double getUn(const double gram)
{
	const double UNC = 28.3;
	return gram / UNC;
}
