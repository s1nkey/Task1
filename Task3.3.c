#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>

/**
* @brief Считывает значение введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double getValid_double();

/**
* @brief Проверяет промежуток на корректность ввода
* @param start - значение начала промежутка
* @param end - значения конца промежутка
*/
void checkStart_End(const double start, const double end);

/**
* @brief Проверяет шаг на корректность ввода
* @param step - значение шага
*/
void checkStep(const double step);

/**
* @brief Проверяет определена ли функция в точке x
* @param x - точка
* @return 1 - если функция опредлена, иначе 0
*/
bool OOF(const double x);

/**
* @brief Рассчитывает значение в точке x
* @param x - точка
* @return Рассчитанное значение
*/
const double function(const double x);

/**
* @brief Рассчитывает сумму ряда с заданное точностью
* @param x - точка, в которой ищется сумма ряда
* @param e - заданная точность
* @return Рассчитанное значение
*/
const double defSummE(const double x, const double e);

/**
* @brief Рассчитывает коэф. умножения для нахождения следующего элемента ряда последовательности
* @param x - точка
* @param n - текущий индекс
* @return Рассчитанный коэф.
*/
const double getRecurent(const double x, const int n);

/**
* @brief Проверяет являеться ли число положительным
* @param input - число
*/
void checkPlus(const double input);

int main(void)
{
    system("chcp 1251");
    system("CLS");

    printf("Введите начало промежутка: ");
    double start = getValid_double();
    printf("Введите конец промежутка: ");
    double end = getValid_double();
    checkStart_End(start, end);

    printf("Введите шаг: ");
    double step = getValid_double();
    checkStep(step);

    printf("С какой точностью будет вычислятся последовательность: ");
    double e = getValid_double();
    checkPlus(e);

    system("CLS");
    printf("%-10s%-25s%s\n", "x", "F", "Summ");
    for (double x = start; x < end + step; x += step)
    {
        if (OOF(x))
        {
            printf("%-10.2lf%-25.6lf%.6lf\n", x, function(x), defSummE(x, e));
        }
        else
        {
            printf("%-10.2lf%-25s%s\n", x, "Функция не определена", " ");
        }
    }

    return 1;
}

double getValid_double()
{
    double valid = 0;
    if (!scanf_s("%lf", &valid))
    {
        fprintf(stderr, "Error\n Ошибка ввода числа");
        exit(1);
    }
    return valid;
}

void checkStart_End(const double start, const double end)
{
    if (!(start < end))
    {
        fprintf(stderr, "Error\n Ошибка промежутка");
        exit(1);
    }
}

void checkStep(const double step)
{
    if (!(step > 0))
    {
        fprintf(stderr, "Error\n Ошибка ввода шага");
        exit(1);
    }
}

bool OOF(const double x)
{
    if (fabs(x - 1) <= DBL_EPSILON || fabs(x + 1) <= DBL_EPSILON || fabs(x) > 1)
    {
        return 0;
    }
    return 1;
}

const double function(const double x)
{
    return 1.0 / 4 * log((1 + x) / (1 - x)) + 1.0 / 2 * atan(x);
}

const double defSummE(const double x, const double e)
{
    double current = x;
    double result = 0;
    for (int n = 0; fabs(current) > e; n++)
    {
        result += current;
        current *= getRecurent(x, n);
    }
    return result;
}

const double getRecurent(const double x, const int n)
{
    return (4 * n * pow(x, 4) + pow(x, 4)) / (4 * n + 5);
}

void checkPlus(const double input)
{
    if (!(input > 0))
    {
        fprintf(stderr, "Error\n Ошибка ввода числа");
        exit(1);
    }
}
