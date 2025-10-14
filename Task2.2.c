#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<locale.h>

/**
* @brief Рассчитывает значение первой функции
* @param x - значение параметра x
* @return Рассчитанное значение
*/
const double F1(const double x);

/**
* @brief Рассчитывает значение второй функции
* @param x - значение параметра x
* @return Рассчитанное значение
*/
const double F2(const double x);

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
    setlocale(LC_ALL, "");


    const double a = 2.3;
    printf("Введите x: ");
    double x = defValid();

    if (x < 2)
    {
        printf("y = %.6lf", F1(x));
    }
    else
    {
        printf("y = %.6lf", F2(x));
    }

    return 0;
}

double defValid()
{
    double valid = 0;
    if (!scanf_s("%lf", &valid))
    {
        printf("Error\n");
        abort();
    }
    return valid;
}

const double F1(const double x)
{
    return 1.5 * pow(cos(x), 2);
}

const double F2(const double x)
{
    return pow((x - 2), 2) + 6;
}
