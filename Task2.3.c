#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double checkValid();

/**
* @brief Проверяет значение на условие
* @param input - проверяемое значение
*/
void checkValue(const double input);

/**
* @brief Считает значение времени, требующиеся на половину пути
* @param timeA - значение времени первого промежутка
* @param timeB - значение времени второго промежутка
* @param timeC - значение времени третьего промежутка
* @param speedA - значение скорости первого промежутка
* @param speedB - значение скорости второго промежутка
* @param speedC - значение скорости третьего промежутка
* @return рассчитанное значение
*/
const double defTask(const double timeA, const double timeB, const double timeC, const double speedA, const double speedB, const double speedC);

/**
* @brief Рассчитывает расстояние пройденного промежутка
* @param time - значение времени
* @param speed - значение скорости
* @return рассчитанное значение
*/
const double defPath(const double time, const double speed);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
    setlocale(LC_ALL, "");


    printf("Введите время t1 в часах: ");
    double timeOne = checkValid();
    checkValue(timeOne);
    printf("Введите скорость v1 в км/ч: ");
    double speedOne = checkValid();
    checkValue(speedOne);

    printf("\nВведите время t2 в часах: ");
    double timeTwo = checkValid();
    checkValue(timeTwo);
    printf("Введите скорость v2 в км/ч: ");
    double speedTwo = checkValid();
    checkValue(speedTwo);

    printf("\nВведите время t3 в часах: ");
    double timeThree = checkValid();
    checkValue(timeThree);
    printf("Введите скорость v3 в км/ч: ");
    double speedThree = checkValid();
    checkValue(speedThree);

    printf("Время, за которое он одолел первую половину пути = %.2lf", defTask(timeOne, timeTwo, timeThree, speedOne, speedTwo, speedThree));

    return 0;
}

double checkValid()
{
    double valid = 0;
    if (!scanf_s("%lf", &valid))
    {
        printf("Error");
        exit(1);
    }
    return valid;
}
const double defPath(const double time, const double speed)
{
    return time * speed;
}

void checkValue(const double input)
{
    if (input < 0)
    {
        printf("Error\n Значение должно быть неотрицательным");
        exit(1);
    }
}

const double defTask(const double timeA, const double timeB, const double timeC, const double speedA, const double speedB, const double speedC)
{
    const double half_allPath = ((defPath(timeA, speedA) + defPath(timeB, speedB) + defPath(timeC, speedC)) / 2.0);

    if (half_allPath - defPath(timeA, speedA) > 0)
    {
        if (half_allPath - defPath(timeA, speedA) - defPath(timeB, speedB) > 0)
        {
            return timeA + timeB + (half_allPath - defPath(timeA, speedA) - defPath(timeB, speedB)) / speedC;
        }

        else
        {
            return timeA + (half_allPath - defPath(timeA, speedA)) / speedB;
        }
    }

    else
    {
        return half_allPath / speedA;
    }
}
