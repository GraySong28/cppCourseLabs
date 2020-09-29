/*
Написать программу, которая преобразует одномерный массив (1D) в двумерный (2D)
(или наоборот), в соответствии с вариантом. Необходимо оформить в отдельных
функциях код следующих действий: 1) инициализация массива; 2) вывод массива; 3)
преобразование массива (создание нового массива с другой структурой). Память под
массивы выделять динамически и для доступа к элементам использовать указатели.
Ввод-вывод данных организовать средствами iostream и iomanip.

Вариант 2

Преобразование: 2D → 1D. Двумерный массив 5х5 целых чисел необходимо выложить
в один ряд по элементам слева направо и сверху вниз, исключая все элементы на
четных строках.
Инициализация: заполнить массив факториалами: x[i][j] = ( i+j )! .
Вывод на экран: на каждый элемент массива отвести 8 позиций.
[ 1  1   2   6    24
  1  2   6   24   120
  2  6   24  120  720
  6  24  120 720  5040
  24 120 720 5040 40320 ]
=>
[1 1 2 6 24 2 6 24 120 720 24 120 720 5040 40320 ]
*/

#include <iostream>

const int SIZE = 5;

int fact(int i);
void fillingTheArray(int** array);
void printTheArray2D(int** array);
void arrayTranslation(int** array, int* array1D);

int main()
{
	// Создание динамического массива 5х5
	int** array = new int* [SIZE]; 
	for (int i = 0; i < SIZE; ++i)
	{     
		array[i] = new int[SIZE];
	}
	int* array1D = new int[15];
	// Вызов функции заполнения
	fillingTheArray(array);
	// Вывести массив 5х5
	printTheArray2D(array);
	// Преобразование массива и вывести
	arrayTranslation(array, array1D);
		
	// Удаление 2D массива
	for (int i = 0; i < SIZE; ++i)
	{
		delete [] array[i];
	}
	delete [] array;
	//Удаление 1D массива
	delete[] array1D;
	array1D = 0;
}

// Функция расчёта факториала
int fact(int i) {
	if (i == 0) return 1;
	else return i * fact(i - 1);
}

// Функция заполнения массива
void fillingTheArray(int** array)
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			*(*(array + i) + j) = fact(i + j);
		}
	}
}

// Функция вывода массива
void printTheArray2D(int** array)
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			std::cout << array[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

// Функция перевода массива из 2D -> 1D
void arrayTranslation(int** array, int* array1D)
{
	int clock = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if ((i+1) % 2 != 0)
			{
				array1D[clock] = array[i][j];
				clock++;
			}
		}
	}
	// Вывод получившегося массива
	for (int i = 0; i < 15; ++i)
	{
		std::cout << array1D[i] << " ";
	}
}