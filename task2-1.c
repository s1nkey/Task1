#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/**
 * @brief рассчитывает периметр прямоугольника
 * @param side1 - первая сторона прямоугольника
 * @param side2 - вторая сторона прямоугольника
 * @return возвращает рассчитанный Периметр
 */
double getPerimetr(const double side1, const double side2);

/**
 * @brief рассчитывает площадь прямоугольника
 * @param side1 - первая сторона прямоугольника
 * @param side2 - вторая сторона прямоугольника
 * @return возвращает рассчитанную площадь
 */
double getSquare(const double side1, const double side2);

/**
 * @brief рассчитывает диагональ 
 * @param side1 - первая сторона прямоугольника
 * @param side2 - вторая сторона прямоугольника
 * @return возвращает рассчитанную диагональ
 */
double getDiagonal(const double side1, const double side2);

/**
 * @brief считывает значение
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет,что переменная положительная
 * @param value - значение проверяемой переменной
 */
void checkValue(const double value);

/**
 * @brief Точка входа в программу
 * @return возвращает 0 если программма выполнена корректно
 */
int main(void)
{
    system("chcp 1251");

    printf("Введите первую сторону прямоугольника: ");
    double side1 = getValue();
    checkValue(side1);

    printf("Введите вторую сторону прямоугольника: ");
    double side2 = getValue();
    checkValue(side2);

    printf("Периметр равен %.2lf\n", getPerimetr(side1, side2));
    printf("Площадь равна %.2lf\n", getSquare(side1, side2));
    printf("Диагональ равна %.2lf\n", getDiagonal(side1, side2));

    return 0;
}

double getPerimetr(const double side1, const double side2)
{
    return 2 * (side1 + side2);
}

double getSquare(const double side1, const double side2)
{
    return side1 * side2;
}

double getDiagonal(const double side1, const double side2)
{
    return sqrt(pow(side1, 2) + pow(side2, 2));
}

double getValue()
{
    double value = 0;
    if (!scanf_s("%lf", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void checkValue(const double value)
{
    if (value <= 0)
    {
        printf("Value have to be positive\n");
        abort();
    }
}
