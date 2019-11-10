// training.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "../tryToMatrix.h"
#include "testOfTryToMatrix/test_tryToMatrix.h"
#include <vector>
#include <ctime>
using namespace std;

int main()
{
	test_ClassMyMatrix_all();

	MyMatrix a(2, 2, 1);
	a(0, 1) = 2;
	a(1, 0) = 3;
	a(1, 1) = 4;
	a.outputConsole();

	// Нахождение определителя
	cout << endl << "double result = a.determinant();" << endl;
	double result = a.determinant();
	cout << result << endl;


	// Заполнение матрицы случайными числами
	cout << endl << "a.fillRand(15, 28);" << endl;
	a.fillRand(15, 28);
	a.outputConsole();

	// Сложение, умножение, вычитание матриц
	MyMatrix b(2, 2, 1), c(2, 2);
	cout << endl << "a + b" << endl;
	c = a + b;
	c.outputConsole();

	cout << endl << "a - b" << endl;
	c = a - b;
	c.outputConsole();

	cout << endl << "a * b" << endl;
	c = a * b;
	c.outputConsole();


	// Транспонирование матрицы
	cout << endl << "a.transpose();" << endl;
	a.transpose();
	a.outputConsole();

	// Создание дигональной матрицы
	cout << endl << "a.diag();" << endl;
	a.diag();
	a.outputConsole();

}

