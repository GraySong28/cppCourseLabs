/*
Написать класс Fractionдля представления обыкновенных дробей(как отношения двух целых чиселx / y).
Перегрузить операторы + , -, *, / для дробей.Реализоватьметод voidreduce()для сокращения дроби, атакже статические 
методы : 
- int gcd(int n, int m) функция для нахождения наибольшего общего делителя чисел n и m;
- voidprintAsFraction(doubledecimal_fraction)
- voidprintAsFraction(char* decimal_fraction)
перегруженные методывыводадесятичной дроби  в  видеобыкновенной(например, при  значении decimal_fraction = 0.43 на  
экране  должно вывестись 43 / 100, при0.25–1 / 4и т.д.).Также  реализовать  в  виде  статического  
члена  класса  счетчик  всех созданныхна данный момент в программе экземпляров дробей.Продемонстрировать 
работу созданного класса.Создать несколько объектов дробей.Произвести операции сложения, вычитания, умножения и 
деления дробей.Вывести на экран результаты.Показать также результаты работы статических методов класса.
*/

#include <iostream>
#include<math.h>
#include<assert.h>

class Fraction {
	int n, m;
public:
	int count = 0;

	Fraction(int n) {
		this->n = n;
		m = 1;
	}

	Fraction(int n, int m) {
		assert(m != 0);
		this->n = n;
		this->m = m;
		++count;
	}

	~Fraction() { 
		--count; 
	}

	static int gcd(int n, int m) {
		while (n != 0 && m != 0) {
			if (n > m) {
				n = n % m;
			}
			else m = m % n;
		}
		return n + m;
	}

	void reduce() {
		int c = gcd(n, m);
		n /= c;
		m /= c;
	}

	Fraction operator+(const Fraction& F) const {
		assert(F.m != 0);
		return Fraction(n * F.m + m * F.n, m * F.m);
	}

	Fraction operator-(const Fraction& F) const {
		assert(F.m != 0);
		return Fraction(n * F.m - m * F.n, m * F.m);
	}

	Fraction operator*(const Fraction& F) const {
		assert(F.m != 0);
		return Fraction(n * F.n, m * F.m);
	}

	Fraction operator/(const Fraction& F) const {
		assert(F.n != 0 && F.m != 0);
		return Fraction(n * F.m, m * F.n);
	}

	void Print() {
		std::cout << n << '/' << m << std::endl;
	}

	static void printAsFraction(double decimal_fr) {
		Fraction fr1((int)decimal_fr);
		double q = decimal_fr - (int)decimal_fr;
		q *= 10;
		int p = 10;
		while (q - (int)q != 0) {
			q *= 10;
			p *= 10;
		}

		Fraction fr2((int)q, p);
		Fraction fr = fr1 + fr2;
		fr.reduce();
		fr.Print();

	}

	static void printAsFraction(char* decimal_fr) {
		char* ptr = decimal_fr;
		int count = 0;
		while (*ptr != '.') {
			++ptr;
			++count;
		}

		ptr = decimal_fr;
		double d = 0;
		while (*ptr != '\0') {
			if (*ptr != '.') {
				char c = *ptr;
				int i = (int)c;
				int i1 = c - 48;
				d += i1 * pow(10, count - 1);
				--count;
				++ptr;
			}
			else ++ptr;
		}
		printAsFraction(d);
	}
};

int main() {
	Fraction drob1(1, 6);
	Fraction drob2(6, 12);
	Fraction drob3(21, 9);
	Fraction drob4(21, 21);
	drob1.Print();
	drob2.Print();
	drob3.Print();
	drob4.Print();
	Fraction drob5 = drob1 + drob1;
	Fraction drob6 = drob2 - drob2;
	Fraction drob7 = drob3 * drob3;
	Fraction drob8 = drob4 / drob4;
	drob5.Print();
	drob6.Print();
	drob7.Print();
	drob8.Print();
	char dest[256];
	Fraction::printAsFraction(0.25);
}