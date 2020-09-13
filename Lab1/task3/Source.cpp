/*
Написать свой аналог стандартной функции обработки строк из файла cstring, в
соответствии с вариантом.В функции main на тестовых данных продемонстрировать
результат работы как стандартной функции, так и собственной версии.Ввод - вывод
данных организовать средствами cstdio.

Вариант 2

Функция strcmp.
Формат int strcmp(const char* s1, const char* s2).
Функция сравнивает строку s1 со строкой s2 в лексикографическом порядке. Если s1<s2,
то результат равен -1, если s1=s2, то 0, если s1>s2, то 1.
*/

#include <cstdio>
#include <string.h>

int StrCmp(const char* s1, const char* s2);

int main()
{
	int result = 0;
	// Как отображает результат моя функция
	printf("My function compares: 'Ab' 'AB': ");
	result = StrCmp("Ab", "AB");
	printf("%d", result);
	printf("\n");
	printf("My function compares: 'AB' 'Ab': ");
	result = StrCmp("AB", "Ab");
	printf("%d", result);
	printf("\n");
	printf("My function compares: 'AB' 'AB': ");
	result = StrCmp("AB", "AB");
	printf("%d", result);
	printf("\n");
	// Как отображает результат стандартная функция
	printf("strcmp function compares: 'Ab' 'AB': ");
	result = strcmp("Ab", "AB");
	printf("%d", result);
	printf("\n");
	printf("strcmp function compares: 'AB' 'Ab': ");
	result = strcmp("AB", "Ab");
	printf("%d", result);
	printf("\n");
	printf("strcmp function compares: 'AB' 'AB': ");
	result = strcmp("AB", "AB");
	printf("%d", result);
	printf("\n");
	return 0;
}

int StrCmp(const char* s1, const char* s2)
{
	// Получить длину обеих строк
	size_t lenS1 = sizeof(s1) / sizeof(s1[0]);
	size_t lenS2 = sizeof(s2) / sizeof(s2[0]);
	int max = 0;
	int maxIs1 = 0;
	int maxIs2 = 0;
	// Найти большую
	if (lenS1 > lenS2) max = lenS1;
	else max = lenS2;
	for (int i = 0; i < max; ++i)
	{
		if (s1[i] > s2[i]) maxIs1++;
		if (s1[i] < s2[i]) maxIs2++;
	}
	// В зависисмости от работы цыкла вернуть результат
	if (maxIs1 > maxIs2) return 1;
	else if (maxIs1 < maxIs2) return -1;
	else return 0;
}