/*
�������� ���� ������ ����������� ������� ��������� ����� �� ����� cstring, �
������������ � ���������.� ������� main �� �������� ������ ������������������
��������� ������ ��� ����������� �������, ��� � ����������� ������.���� - �����
������ ������������ ���������� cstdio.

������� 2

������� strcmp.
������ int strcmp(const char* s1, const char* s2).
������� ���������� ������ s1 �� ������� s2 � ������������������ �������. ���� s1<s2,
�� ��������� ����� -1, ���� s1=s2, �� 0, ���� s1>s2, �� 1.
*/

#include <cstdio>
#include <string.h>

int StrCmp(const char* s1, const char* s2);

int main()
{
	int result = 0;
	// ��� ���������� ��������� ��� �������
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
	// ��� ���������� ��������� ����������� �������
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
	// �������� ����� ����� �����
	size_t lenS1 = sizeof(s1) / sizeof(s1[0]);
	size_t lenS2 = sizeof(s2) / sizeof(s2[0]);
	int max = 0;
	int maxIs1 = 0;
	int maxIs2 = 0;
	// ����� �������
	if (lenS1 > lenS2) max = lenS1;
	else max = lenS2;
	for (int i = 0; i < max; ++i)
	{
		if (s1[i] > s2[i]) maxIs1++;
		if (s1[i] < s2[i]) maxIs2++;
	}
	// � ������������ �� ������ ����� ������� ���������
	if (maxIs1 > maxIs2) return 1;
	else if (maxIs1 < maxIs2) return -1;
	else return 0;
}