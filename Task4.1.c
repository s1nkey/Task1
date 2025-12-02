#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#include <stdbool.h>

/**
* @brief проверяет корректно ли выделена память под массив
* @param arr - проверяемый массив
*/
void check_pointer(const int* arr);

/**
* @brief считывает значение введённое с клавиатуры, с проверкой ввода
* @return число
*/
int get_int(void);

/**
* @brief проверяет промежуток на корректность
* @param min - нижняя граница промежутка
* @param max - верхняя граница промежутка
*/
void check_min_max(const int min, const int max);

/**
* @brief заполняет массив элементами, которые задаёт пользователь
* @param arr - массив, который будет заполнен
* @param rows - размер массива
* @param min - нижняя граница промежутка, в котором будут заданы числа
* @param max - верхняя граница промежутка, в котором будут заданы числа
*/
void get_manual(int* arr, const size_t rows, const int min, const int max);

/**
* @brief заполняет массив случайными элементами
* @param arr - массив, который будет заполнен
* @param rows - размер массива
* @param min - нижняя граница промежутка, в котором будут заданы числа
* @param max - верхняя граница промежутка, в котором будут заданы числа
*/
void get_random(int* arr, const size_t rows, const int min, const int max);

/**
* @brief проверяет, лежит ли число в заданном промежутке
* @param input - число
* @param min - нижняя граница промежутка, в котором будут заданы числа
* @param max - верхняя граница промежутка, в котором будут заданы числа
*/
void check_int(const int input, const int min, const int max);

/**
* @brief выводит массив на экран
* @param arr - массив, который будет выведен
* @param rows - размер массива
*/
void print_arr(const int* arr, const size_t rows);

/**
* @brief копирует массив
* @param arr - массив, который будет скопирован
* @param rows - размер массива
* @return скопированный массив
*/
int* get_copyarray(const int* arr, const size_t rows);

/**
* @brief изменяет массив согласно условию №1
* @param arr - массив
* @param rows - размер массива
* @return изменённый массив
*/
int* def_task_one(int* arr, const size_t rows);

/**
* @brief изменяет массив согласно условию №2 и выводит его на экран
* @param arr - массив
* @param rows - размер массива
*/
void def_task_two(const int* arr, const size_t rows);

/**
* @brief изменяет массив согласно условию №3 и выводит его на экран
* @param arr - массив
* @param rows - размер массива
*/
void def_task_three(int* arr, const size_t rows);

/**
* @brief Проверяет что переменная не меньше единицы
* @param input - значение проверяемой переменной
*/
void checkValueForN(const int input);

/**
* @param CHOISE_ONE - выбор ручного заполнения
* @param CHOISE_TWO - выбор заполнения случайными числами
* @param TASK_ONE - выбор выполнения 1 задания
* @param TASK_TWO - выбор выполнения 2 задания
* @param TASK_THREE - выбор выполнения 3 задания
*/
enum { CHOISE_ONE = 1, CHOISE_TWO, TASK_ONE = 1, TASK_TWO, TASK_THREE };

/**
* @brief точка входа в программу
* @return 0 или 1 в зависимости от корректности выполнения
*/
int main(void)

{
    setlocale(LC_ALL, "");

    printf("Введите количество элементов массива: ");
    size_t rows = (size_t)get_int();
    checkValueForN(rows);

    int* main_array = (int*)calloc(rows, sizeof(int));
    check_pointer(main_array);

    printf("Введите минимальное возможное число в массиве: ");
    const int min = get_int();
    printf("Введите максимальное возможное число в массиве: ");
    const int max = get_int();
    check_min_max(min, max);

    system("CLS");
    printf("Массив из %zu строк будет заполнен числами в диапазоне [%d;%d]\n\n", rows, min, max);

    printf("Как будет заполнен массив?\n%d - Ручное заполнение\n%d - Автоматическое заполнение\n", CHOISE_ONE, CHOISE_TWO);
    int first_choise = get_int();

    switch (first_choise)
    {
    case CHOISE_ONE:
        get_manual(main_array, rows, min, max);
        break;

    case CHOISE_TWO:
        get_random(main_array, rows, min, max);
        break;

    default:
        fprintf(stderr, "Error Ошибка выбора\n");
        free(main_array);
        exit(1);
    }


    system("CLS");
    int* copy_array = get_copyarray(main_array, rows);
    check_pointer(copy_array);
    print_arr(copy_array, rows);

    printf("\nКакие будут преобразования?\n%d - Заменить последние k элементов массива на противоположные по знаку.\n%d - Вывести индексы тех элементов, значения которых кратны 3.\n%d - Определить, есть ли пара соседних элементов с суммой, равной заданному числу\n", TASK_ONE, TASK_TWO, TASK_THREE);
    int second_choise = get_int();

    switch (second_choise)
    {
    case TASK_ONE:
        def_task_one(copy_array, rows);
        print_arr(copy_array, rows);
        break;

    case TASK_TWO:
        def_task_two(copy_array, rows);
        break;

    case TASK_THREE:
        def_task_three(copy_array, rows);
        break;

    default:
        fprintf(stderr, "Error Ошибка выбора\n");
        free(main_array);
        free(copy_array);
        exit(1);
    }

    free(main_array);
    free(copy_array);
    return 0;
}

void check_pointer(const int* arr)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Error Ошибка выделения памяти\n");
        exit(1);
    }
}

int get_int(void)
{
    int output = 0;
    if (!scanf_s("%d", &output))
    {
        fprintf(stderr, "Error Ошибка ввода\n");
        exit(1);
    }
    return output;
}

void check_min_max(const int min, const int max)
{
    if (min >= max)
    {
        fprintf(stderr, "Error Ошибка ввода промежутка\n");
        exit(1);
    }
}

void get_manual(int* arr, const size_t rows, const int min, const int max)
{
    check_pointer(arr);

    for (size_t i = 0; i < rows; i++)
    {
        printf("\narr[%zu] = ", i);
        arr[i] = get_int();
        check_int(arr[i], min, max);
    }
}

void get_random(int* arr, const size_t rows, const int min, const int max)
{
    check_pointer(arr);
    srand(time(NULL));

    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}



void check_int(const int input, const int min, const int max)
{
    if (input<min || input>max)
    {
        fprintf(stderr, "Error Ошибка ввода числа, оно должно лежать в указаном промежутке\n");
        exit(1);
    }
}

void print_arr(const int* arr, const size_t rows)
{
    check_pointer(arr);

    printf("Массив: \n");
    for (size_t i = 0; i < rows; i++)
    {
        printf("%5d\n", arr[i]);
    }
}

int* get_copyarray(const int* arr, const size_t rows)
{
    check_pointer(arr);

    int* copyarr = (int*)calloc(rows, sizeof(int));
    check_pointer(copyarr);

    for (size_t i = 0; i < rows; i++)
    {
        copyarr[i] = arr[i];
    }

    return copyarr;
}

int* def_task_one(int* arr, const size_t rows)
{
    check_pointer(arr);

    printf("\nЗадайте число k: ");
    size_t k = get_int();
    checkValueForN(k);

    if (k > rows)
    {
        fprintf(stderr, "Error Число должно быть меньше, чем элементов массива\n");
        exit(1);
    }

    for (size_t i = rows - k; i < rows; i++)
    {
        arr[i] = -arr[i];
    }

    return arr;
}

void def_task_two(const int* arr, const size_t rows)
{
    check_pointer(arr);

    printf("\nИндексы элементов, значения которых кратны 3: ");
    bool check = 0;
    for (size_t i = 0; i < rows; i++)
    {
        if (arr[i] % 3 == 0)
        {
            printf("%zu ", i);
            check = 1;
        }
    }
    if (check == 0)
    {
        printf("\nТаких элементов в массиве нет\n");
    }
}

void def_task_three(const int* arr, const size_t rows)
{
    check_pointer(arr);

    printf("\nЗадайте число: ");
    int number = get_int();

    bool check = 0;
    for (size_t i = 0; i < rows - 1; i++)
    {
        if (arr[i] + arr[i + 1] == number)
        {
            check = 1;
        }
    }


    if (check == 0)
    {
        printf("\nПар соседних элементов, с суммой, равной заданному числу нет\n");
    }
    else
    {
        printf("\nЕсть пара соседних элементов, с суммой, равной заданному числу\n");
    }
}


void checkValueForN(const int input)
{
    if (input < 1)
    {
        fprintf(stderr, "Error\nЧисло должно быть не меньше 1");
        exit(1);
    }
}
