#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<float.h>
#include<locale.h>

/**
* @brief Рассчитывает значение функции в точке
* @param x - точка
* @return Рассчитанное значение
*/
const double function(const double x);

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

/**
* @brief Проверяет значения на условие
* @param end - значение конца промежутка
* @param start - значение начала промежутка
*/
void checkEndStart(const double start, const double end);

/**
* @brief Проверяет значение на условие
* @param step - значение шага
*/
void checkStep(const double step);

/**
* @brief Проверяет заначение на условие
* @param x - значение параметра x
* @return Возвращает 0 или 1 в зависимости от истинности выражения
*/
_Bool checkX(const double x);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
    setlocale(LC_ALL, "");

    printf("Введите начальное значение: ");
    double start = defValid();
    printf("Введите конечное значение: ");
    double end = defValid();
    checkEndStart(start, end);

    printf("Введите шаг: ");
    double step = defValid();
    checkStep(step);

    printf("\n%-10s %s\n", "x", "f(x)");
    for (double x = start; x < end + DBL_EPSILON; x += step)
    {
        if (checkX(x))
        {
            printf("%-10.2lf%s\n", x, "Функция не определена");
        }
        else
        {
            printf("%-10.2lf%.4lf\n", x, function(x));
        }

    }

    return 0;
}

const double function(const double x)
{
    return cos(2.0 / x) - 2 * sin(1.0 / x) + (1.0 / x);
}

double defValid()
{
    double valid = 0;
    if (!scanf_s("%lf", &valid))
    {
        printf("Error\n");
        exit(1);
    }
    return valid;
}

void checkEndStart(const double start, const double end)
{
    if (!(start < end))
    {
        printf("Error\n");
        exit(1);
    }
}

void checkStep(const double step)
{
    if (step <= DBL_EPSILON)
    {
        printf("Error\n");
        exit(1);
    }
}

_Bool checkX(const double x)
{
    return fabs(x) <= DBL_EPSILON;
}

