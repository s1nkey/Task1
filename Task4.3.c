#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/**
* @brief Считывает число с проверкой ввода и проверяет на условие
* @return Число
*/
const size_t getValidForSize();
/**
* @brief Считывает число с проверкой ввода
* @return Число
*/
int getValidForDigit();
/**
* @brief Проверяет промежуток на корректность
* @param min_ - начало промежутка
* @param max_ - конец промежутка
*/
void check_min_max(const int min_, const int max_);

/**
* @brief Проверяет лежит ли число в промежутке [min;max]
* @param value - число
* @param min - нижняя граница значения элемента
* @param max - верхняя граница значения элемента
*/
void checkMinMaxForDigit(const int value, const int min, const int max);

/**
* @brief Выделяет память под массив
* @param rows - количество строк массива
* @param columns - количесвто столбцов массива
* @return Массив
*/
int** getMakeArrays(const size_t rows, const size_t columns);

/**
* @brief Создаёт новый массив, идентинчый элементами прообразу
* @param arr - массив прообраз
* @param rows - количество строк массива
* @param columns - количесвто столбцов массива
* @return Новый массив
*/
int** getCopyArray(int** arr, const size_t rows, const size_t columns);

/**
* @brief Проверяет, корректно ли выделилась память под массив
* @param arr - массив
* @param rows - количество строк массива
*/
void checkArraysFromMemory(int** arr, const size_t columns);

/**
* @brief Выводит на экран полученный массив
* @param arr - массив
* @param rows - количество строк массива
* @param columns - количесвто столбцов массива
*/
void printArrays(int** arr, const size_t rows, const size_t columns);

/**
* @brief Заполняет массив элементами, который вводит пользователь
* @param arr - массив
* @param rows - количество строк массива
* @param columns - количесвто столбцов массива
* @param min - нижняя граница значения элемента
* @param max - верхняя граница значения элемента
*/
void getManual(int** arr, const size_t rows, const size_t size_m, const int min, const int max);

/**
* @brief Заполняет массив случайными элементами
* @param arr - массив
* @param rows - количество строк массива
* @param columns - количесвто столбцов массива
* @param min - нижняя граница значения элемента
* @param max - верхняя граница значения элемента
*/
void getRandom(int** arr, const size_t rows, const size_t columns, const int min, const int max);

/**
* @brief Очищает выделенную память под массив
* @param arr - массив
* @param rows - количество строк массива
*/
void freeArraysMemory(int** arr, const size_t rows);

/**
* @brief Выводит новый массив согласно заданию №1
* @param arr - массив
* @param rows - количество строк массива
* @param columns - количесвто столбцов массива
*/
void defTaskOne(int** arr, const size_t rows, const size_t columns);

/**
* @brief Выводит новый массив согласно заданию №2
* @param arr - массив
* @param rows - количество строк массива
* @param columns - количесвто столбцов массива
*/
void defTaskTwo(int** arr, const size_t rows, const size_t columns);

/**
* @param MANUAL - выбор ручного создания массива
* @param RANDOM - выбор автоматического создания массива
* @param TASK_ONE - выбор первого задания
* @param TASK_TWO - выбор второго задания
*/
enum { MANUAL = 1, RANDOM, TASK_ONE = 1, TASK_TWO };

/**
* @brief Находит максимальный элемент массива
* @param arr - массив
* @param rows - количество строк массива
* @param columns - количесвто столбцов массива
* @return максимальный элемент массива
*/
const int defMax(int** arr, const size_t rows, const size_t columns);

/**
* @brief Находит есть ли в строке максимальный элемент
* @param arr - массив
* @param rows - количество строк массива
* @param columns - количесвто столбцов массива
* @param max - максимальный элемент
* @return количество столбцов, содержащие максимальный элемент
*/
const int count_defMax(int** arr, const size_t rows, const size_t columns, const int max);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");
	printf("Введите количество строк массива: ");
	size_t rows = getValidForSize();
	printf("Введите количество столбцов массива: ");
	size_t columns = getValidForSize();

	printf("\nВведите минимальное значение элемента массива: ");
	const int min = getValidForDigit();
	printf("Введите максимальное значение элемента массива: ");
	const int max = getValidForDigit();
	check_min_max(min, max);

	printf("Элементы массива будут задаваться в промежутке [%d;%d]\n", min, max);

	int** mainArray = getMakeArrays(rows, columns);
	checkArraysFromMemory(mainArray, rows);

	printf("\nВыберите метод заполнение массива:\n%d - Ручное заполнение массива\n%d - Автоматическое заполнение массива\n", MANUAL, RANDOM);
	int firstChoise = getValidForDigit();
	switch (firstChoise)
	{
	case MANUAL:
		getManual(mainArray, rows, columns, min, max);
		break;
	case RANDOM:
		getRandom(mainArray, rows, columns, min, max);
		break;
	default:
		fprintf(stderr, "Error\n	Ошибка выбора");
		freeArraysMemory(mainArray, rows);
		exit(1);
	}
	int** newArray = getCopyArray(mainArray, rows, columns);
	checkArraysFromMemory(newArray, rows);
	printArrays(newArray, rows, columns);
	printf("\nВыберите выполняемую операцию с массивом:\n%d - Заменить максимальный элемент каждой строки на противоположный по знаку\n%d - Вставить после всех столбцов, содержащих максимальный элемент столбец из нулей\n", TASK_ONE, TASK_TWO);
	int secondChoise = getValidForDigit();
	switch (secondChoise)
	{
	case TASK_ONE:
		defTaskOne(newArray, rows, columns);
		break;
	case TASK_TWO:
		defTaskTwo(newArray, rows, columns);
		break;
	default:
		fprintf(stderr, "Error\n	Ошибка выбора");
		freeArraysMemory(newArray, rows);
		freeArraysMemory(mainArray, rows);
		exit(1);
	}
	freeArraysMemory(newArray, rows);
	freeArraysMemory(mainArray, rows);
	return 0;
}

const size_t getValidForSize()
{
	long int value = 0;
	if (!scanf_s("%ld", &value))
	{
		fprintf(stderr, "Error\n	Ошибка ввода размерности массива");
		exit(1);
	}
	if (value < 1)
	{
		fprintf(stderr, "Error\n	Ошибка ввода размерности массива");
		exit(1);
	}
	size_t output = (size_t)value;
	return output;
}

int getValidForDigit()
{
	int value = 0;
	if (!scanf_s("%d", &value))
	{
		fprintf(stderr, "Error\n	Ошибка ввода");
		exit(1);
	}
	return value;
}

void check_min_max(const int min_, const int max_)
{
	if (min_ >= max_)
	{
		fprintf(stderr, "Error\n	Ошибка ввода промежутка");
		exit(1);
	}
}

void checkMinMaxForDigit(const int value, const int min, const int max)
{
	if (value > max || value < min)
	{
		fprintf(stderr, "Error\n	Ошибка ввода, число вне промежутка");
		exit(1);
	}
}

int** getMakeArrays(const size_t rows, const size_t columns)
{
	int** arr = (int**)calloc(rows, sizeof(int*));

	if (arr == NULL)
	{
		fprintf(stderr, "Error\n	Ошибка выделения памяти под массив");
		exit(1);
	}

	for (size_t i = 0; i < rows; i++)
	{
		arr[i] = (int*)calloc(columns, sizeof(int));
	}
	return arr;
}

void checkArraysFromMemory(int** arr, const size_t rows)
{
	if (arr == NULL)
	{
		fprintf(stderr, "Error\n	Ошибка выделения памяти под массив");
		exit(1);
	}
	else
	{
		for (size_t i = 0; i < rows; i++)
		{
			if (arr[i] == NULL)
			{
				fprintf(stderr, "Error\n	Ошибка выделения памяти под массив");
				exit(1);
			}
		}
	}
}

void printArrays(int** arr, const size_t rows, const size_t columns)
{
	checkArraysFromMemory(arr, rows);
	printf("\nПолученный массив:\n");
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
}

void getManual(int** arr, const size_t rows, const size_t columns, const int min, const int max)
{
	checkArraysFromMemory(arr, rows);
	printf("\nВведите %zu элементов массива:\n", rows * columns);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			int num = getValidForDigit();
			checkMinMaxForDigit(num, min, max);
			printf("A[%zu][%zu] = %d\n", i, j, num);
			arr[i][j] = num;
		}
	}
}

void getRandom(int** arr, const size_t rows, const size_t columns, const int min, const int max)
{
	checkArraysFromMemory(arr, rows);
	srand(time(NULL));
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			arr[i][j] = rand() % (max - min + 1) + min;
		}
	}
}

void freeArraysMemory(int** arr, const size_t size_n)
{
	checkArraysFromMemory(arr, size_n);
	for (size_t i = 0; i < size_n; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

int** getCopyArray(int** arr, const size_t rows, const size_t columns)
{
	checkArraysFromMemory(arr, rows);
	int** array = getMakeArrays(rows, columns);
	checkArraysFromMemory(array, rows);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			array[i][j] = arr[i][j];
		}
	}
	return array;
}

void defTaskOne(int** arr, const size_t rows, const size_t columns)
{
	checkArraysFromMemory(arr, rows);

	for (size_t i = 0; i < rows; i++)
	{
		size_t idx = 0;
		int max = arr[i][0];

		for (size_t j = 0; j < columns; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				idx = j;
			}
		}

		arr[i][idx] = -arr[i][idx];
	}

	printArrays(arr, rows, columns);
}

void defTaskTwo(int** arr, const size_t rows, const size_t columns)
{
	checkArraysFromMemory(arr, rows);

	const int max = defMax(arr, rows, columns);
	const int count = count_defMax(arr, rows, columns, max);

	size_t newsize = columns + count;

	int** newarr = getMakeArrays(rows, newsize);
	checkArraysFromMemory(newarr, rows);

	int* arr_columns = (int*)calloc(columns, sizeof(int));

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			if (arr[i][j] == max)
			{
				arr_columns[j] = 1;
			}
		}
	}

	size_t idx = 0;
	for (size_t j = 0; j < columns; j++)
	{
		if (arr_columns[j] == 1)
		{
			for (size_t i = 0; i < rows; i++)
			{
				newarr[i][idx] = arr[i][j];
			}
			idx++;
			for (size_t i = 0; i < rows; i++)
			{
				newarr[i][idx] = 0;
			}
			idx++;
		}
		else
		{
			for (size_t i = 0; i < rows; i++)
			{
				newarr[i][idx] = arr[i][j];
			}
			idx++;
		}
	}

	printArrays(newarr, rows, newsize);
	free(arr_columns);
	freeArraysMemory(newarr, rows);
}

const int defMax(int** arr, const size_t rows, const size_t columns)
{
	checkArraysFromMemory(arr, rows);

	int max = arr[0][0];

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
	}

	return max;
}

const int count_defMax(int** arr, const size_t rows, const size_t columns, const int max)
{
	int count = 0;

	for (size_t j = 0; j < columns; j++)
	{
		for (size_t i = 0; i < rows; i++)
		{
			if (arr[i][j] == max)
			{
				count++;
				break;
			}
		}
	}

	return count;
}
