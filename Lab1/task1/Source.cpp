/*
�������� ��������� ��������� ����������� ������� � n ����������, � ������������ �
��������� (���������� �). ����������� �������� ������ ������������� �
������� processArray(), ������������ ������������ �������� � �����������
��� ���� (��������) ������ ������ (��. ���� �������). ������ ��� �������
�������� ���������� (��������� ������� �������� � ������� main) � ��� ������� �
��������� ������������ �������. ����-����� ������ ������������ ���������� stdio

������� 2

�������� ������ �� n=20 ������������ �����, ������������������� ������. �������
processArray() ������ ��������� ������ ���������� ������� �� -20.0 �� 70.0, �
����� ������������� ������, �.�. �������� ������ ������� ������� �� ������������
�� ������ �������� � �������. ��� �������� ��� ����� ������ ������� �� ������.
������������ �������� ������������ ������, � ������� ��� ��������, ������� ��
������� ������������� �������� ������������, ��������� �������� ��������
�������, � ��������� ����� x (����� x ������ � ����������). ������� �� �����
�������������� �������.
*/

#include <stdio.h>
#include <random>
#include <math.h>
#include <time.h>

// ������ ��������
const int N = 20;

// ������� ��������� ��������
double processArray(double* array, double* result, double x);
// ������� ����� �������
void printArray(double* array);

int main()
{
	// ������������� ��������
	double array[N] = { 0.0 };
	double result[N] = { 0.0 };

	//������� �
	double x = 10.0;
	printf("Input X:");
	scanf_s("%lf", &x);

	// ����� ������������������� �������
	printf("Initial array:\n");
	printArray(array);

	// �������� ������� � � � �������
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
	// ���������� �������
	for (int i = 0; i < N; ++i)
	{
		array[i] = (rand() % 90) - 20;
	}
	// ����� ������������ �������
	printf("Populated array:\n");
	printArray(array);
	// ���������� ��� ���������� ������������� ��������
	double max = 0.0;
	int pos = 0;
	// ����� �������������
	max = fabs(array[0]);
	for (int i = 0; i < N; ++i)
	{
		if (fabs(array[i]) > max)
		{
			pos = i + 1;
			max = array[i];
		}
	}
	// ������������ �������
	for (int i = 0; i < N; ++i)
	{
		array[i] = array[i] / max;
	}
	// �������� ������
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