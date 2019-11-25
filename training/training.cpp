// training.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "../tryToMatrix.h"
#include "testOfTryToMatrix/test_tryToMatrix.h"
#include <vector>
#include <math.h>
#include <ctime>
using namespace std;

int main()
{
	//test_ClassMyMatrix_all();

	setlocale(LC_ALL, "Russian");

	int i2 = 3; const int *const p3 = &i2;

	MyMatrix a(2, 2, 1);
	a(0, 1) = 2;
	a(1, 0) = 3;
	a(1, 1) = 4;
	cout << endl << "матрица a" << endl;
	a.outputConsole();
	MyMatrix b(2, 2, 1), c(2, 2);
	cout << endl << "Матрица b" << endl;
	b.outputConsole();
	cout << endl << "матрица c" << endl;
	c.outputConsole();

	// Сложение, умножение, вычитание матриц
	cout << endl << "// Сложение, умножение, вычитание матриц" << endl;
	cout << endl << "a + b" << endl;
	c = a + b;
	c.outputConsole();

	cout << endl << "a - b" << endl;
	c = a - b;
	c.outputConsole();

	cout << endl << "a * b" << endl;
	c = a * b;
	c.outputConsole();

	cout << endl << "a += b;" << endl;
	a += b;
	a.outputConsole();

	cout << endl << "a -= b;" << endl;
	a -= b;
	a.outputConsole();

	cout << endl << "a *= b;" << endl;
	a *= b;
	a.outputConsole();

	// Транспонирование матрицы
	cout << endl << "// Транспонирование матрицы" << endl;
	cout << endl << "a.transpose();" << endl;
	a.transpose();
	a.outputConsole();

	// Создание дигональной матрицы
	cout << endl << "// Создание дигональной матрицы" << endl;
	cout << endl << "a.diag();" << endl;
	a.diag();
	a.outputConsole();

	// Нахождение определителя
	cout << endl << "// Нахождение определителя" << endl;
	cout << endl << "double result = a.determinant();" << endl;
	double result = a.determinant();
	cout << result << endl;


	// Заполнение матрицы случайными числами
	cout << endl << "// Заполнение матрицы случайными числами" << endl;
	cout << endl << "a.fillRand(15, 28);" << endl;
	a.fillRand(15, 28);
	a.outputConsole();

	// Обратная матрица
	cout << endl << "// Обратная матрица" << endl;
	a.outputConsole();
	MyMatrix invert(4, 4);
	invert = a.invertMatrix();
	cout << "Invert: " << endl;
	invert.outputConsole();
	cout << "Test( Invert * a ): " << endl;
	invert = invert * a;
	invert.outputConsole();


	// Пример использования лямбда функции
	cout << endl << "// Пример использования лямбда функции" << endl;
	int i = 1, j = 1;
	a.setItem(i, j, ([](int i, int j) -> double{ return i * i * j; }(i, j)));
	a.outputConsole();
}

