/*
Написать программу обработки одномерного массива с n элементами, в соответствии с
вариантом (приложение А). Необходимые действия должны производиться в
функции processArray(), возвращающей определенное значение и формирующей
еще один (выходной) массив данных (см. свой вариант). Память под массивы
выделять статически (объявлять массивы локально в функции main) и для доступа к
элементам использовать индексы. Ввод-вывод данных организовать средствами stdio

Вариант 2

Объявить массив из n=20 вещественных чисел, проинициализировать нулями. Функция
processArray() должна заполнить массив случайными числами от -20.0 до 70.0, а
затем отнормировать массив, т.е. поделить каждый элемент массива на максимальное
по модулю значение в массиве. Это значение она также должна вернуть на выходе.
Сформировать выходной вещественный массив, в котором все элементы, стоящие до
позиции максимального элемента включительно, повторяют элементы входного
массива, а остальные равны x (число x ввести с клавиатуры). Вывести на экран
результирующие массивы.
*/

#include <stdio.h>
#include <random>
#include <math.h>
#include <time.h>

// Размер массивов
const int N = 20;

// Функция обработки массивов
double processArray(double* array, double* result, double x);
// Функция вывод массива
void printArray(double* array);

int main()
{
	// Инициализация массивов
	double array[N] = { 0.0 };
	double result[N] = { 0.0 };

	//Считать х
	double x = 10.0;
	printf("Input X:");
	scanf_s("%lf", &x);

	// Вывод инициализированного массива
	printf("Initial array:\n");
	printArray(array);

	// Передача массиво и Х в функцию
	double max = processArray(array, result, x);
	printf("Normalized array\n");
	printArray(array); 
	printf("Real array\n");
	printArray(result);
	printf("X: %lf", max);

	return 0;
}

double processArray(double* array, double* result, double x)
{
	srand(time(NULL));
	// Заполнения массива
	for (int i = 0; i < N; ++i)
	{
		array[i] = (rand() % 90) - 20;
	}
	// Вывод заполненного массива
	printf("Populated array:\n");
	printArray(array);
	// Переменная для сохранения максимального значения
	double max = 0.0;
	int pos = 0;
	// Поиск максимального
	max = fabs(array[0]);
	for (int i = 0; i < N; ++i)
	{
		if (fabs(array[i]) > max)
		{
			pos = i + 1;
			max = array[i];
		}
	}
	// Нормирование массива
	for (int i = 0; i < N; ++i)
	{
		array[i] = array[i] / max;
	}
	// Выходной массив
	for (int i = 0; i < N; ++i)
	{
		if (i < pos)
		{
			result[i] = array[i];
		}
		else
		{
			result[i] = x;
		}
	}
	return max;
}

void printArray(double* array)
{
	for (int i = 0; i < N; ++i)
	{
		printf("%2.2lf", array[i]);
		printf(" ");
	}
	printf("\n");
}