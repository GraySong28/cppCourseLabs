/*
��������������Vector� Matrix���  ��������  �  ���������  ����������� ��������� ��������, ��������������.
����������� ������� 2 ������������ ������ No1 � ������� ��������� �������.��� ������� �������� � ���� ������� �������.
� ���� �������� ��������� :
- ��������� � ������������ ������������ ������ ������������ ������������� � ������������
�������, ��������������.
- � ������ Vector����������� ������������������[].� ������ Matrix�������� ������ Tat(inti, intj) const
� setAt(inti, intj, Tval), ���������������� �������� � ���������� �������� ��������������� � ��������[i][j],
T���� ��� ��������� ������� �� ��������(int���double).
- ����������� ���������  ����������  �  ����������(���  �����������, ���  � ������������).
�����  ���������� / ���������� ����� �������  �����������  ����������� / ��������������������������������.
*/

#include <iostream>

class Vector {
public:
	Vector& operator++();
	Vector& operator--();
	Vector operator++(int);
	Vector operator--(int);
	int& operator[] (const int index);
	int* array1D = new int[15];

	Vector() {
		int* array1D = new int[15];
	}
	
	~Vector() {
		delete[] array1D;
		array1D = 0;
	}

	int* getArray() {
		return array1D;
	}

	void printTheArray1D() {
		// ����� ������������� �������
		for (int i = 0; i < 15; ++i)
		{
			std::cout << array1D[i] << " ";
		}
		std::cout << std::endl;
	}
};

Vector& Vector::operator++() {
	for (int i = 0; i < 15; i++) {
		++array1D[i];
	}
	return *this;
}

Vector Vector::operator++(int) {
	Vector V(*this);
	++*this;
	return V;
}

Vector& Vector::operator--() {
	for (int i = 0; i < 15; i++) {
		--array1D[i];
	}
	return *this;
}

Vector Vector::operator--(int) {
	Vector V(*this);
	--*this;
	return V;
}

int& Vector::operator[] (const int index){
	return array1D[index];
}

class Matrix {
public:
	const int SIZE = 5;
	int** array = new int* [SIZE];
	Matrix& operator++();
	Matrix& operator--();
	Matrix operator++(int);
	Matrix operator--(int);

	Matrix() {
		for (int i = 0; i < SIZE; ++i) {
			array[i] = new int[SIZE];
		}
	}

	~Matrix() {
		for (int i = 0; i < SIZE; ++i) {
			delete[] array[i];
		}
		delete[] array;
	}

	int fact(int i) {
		if (i == 0) return 1;
		else return i * fact(i - 1);
	}

	void fillingTheArray() {
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				*(*(array + i) + j) = fact(i + j);
			}
		}
	}

	void printTheArray2D() {
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				std::cout << array[i][j] << "\t";
			}
			std::cout << "\n";
		}
		std::cout << std::endl;
	}

	void arrayTranslation(int* array1D) {
		int clock = 0;
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				if ((i + 1) % 2 != 0) {
					array1D[clock] = array[i][j];
					clock++;
				}
			}
		}
	}

	int at(int i, int j) {
		if (i >= 0 && i <= 4 && j >= 0 && j <= 4) {
			return array[i][j];
		}
		else {
			std:: cout << "Value out of range";
		}
		
	}

	void setAt(int i, int j, int val) {
		if (i >= 0 && i <= 4 && j >= 0 && j <= 4) {
			array[i][j] = val;
		}
		else {
			std::cout << "Value out of range";
		}
	}
};

Matrix& Matrix::operator++() {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			++array[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator++(int) {
	Matrix M(*this);
	++* this;
	return M;
}

Matrix& Matrix::operator--() {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			--array[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator--(int) {
	Matrix M(*this);
	--* this;
	return M;
}

int main() {
	// ������ ������� �������
	Vector array1d;
	Matrix array2d;

	// �������� ������ 2�
	array2d.fillingTheArray();
	// ����� ������ 2�
	array2d.printTheArray2D();
	// ������� ������ 2� � 1�
	array2d.arrayTranslation(array1d.getArray());
	// ����� ������ 1�
	array1d.printTheArray1D();

	// ��������� �������� 2� ������� [4][4]
	int value = array2d.at(4, 4);
	std::cout << std::endl << value << std::endl << std::endl;
	// ��������� �������� 2� ������� [4][4]
	array2d.setAt(4, 4, 0);
	// ����� ������� ��� �������� ����������
	array2d.printTheArray2D();

	// �������� ����� ������� 1� � ��� �����
	++array1d;
	array1d.printTheArray1D();
	// ��������� ����� ������� 1� � ��� �����
	--array1d;
	array1d.printTheArray1D();
	std::cout << std::endl;
	// �������� ����� ������� 2� � ��� �����
	++array2d;
	array2d.printTheArray2D();
	// ��������� ����� ������� 2� � ��� �����
	--array2d;
	array2d.printTheArray2D();
}