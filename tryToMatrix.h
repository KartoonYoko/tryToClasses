#pragma once

#include <vector>

/*
	Класс матрица.
*/


using namespace std;

enum MatrixException { InvalidValue, InvalidSize };

typedef double VecType; // тип элементов матрицы(вектора)

class MyMatrix
{
private: 


	vector<vector<VecType>> _matrix;

public:


	MyMatrix(); // создает нулевую матрицу размера 1х1
	MyMatrix(const int& row, const int& col); // создает нулевую матрицу размера row x col
	MyMatrix(const int& row, const int& col, const VecType& num); // создает матрицу, заполненную числом num, размера row x col

	int getCol() const;  // получить кол-во столбцов
	int getRow() const; //  получить кол-во строк

	void expand(const int& row, const int& col); // расширяет матрицу до оазмера row x col и заполняет новые ячейки нулями
	void expand(const int& row, const int& col, const VecType& num); // расширяет матрицу до оазмера row x col и заполняет новые ячейки числом num



	VecType& operator ()(const VecType& row, const VecType& col);	// доступ к отдельным элементам матрицы




	void fill(const VecType& num);	// заполнение матрицы одним значение
	void fillRand();	// заполнение матрицы случайными числами
	void fillRand(const int& fromNum, const int& lastNum);	// заполнение матрицы случайными числами от fromNum до lastNum, с десятичным остатком
	void operator =(const MyMatrix &rightMatrix); // толко для одноразмерных матриц
	MyMatrix operator +(const MyMatrix& rightMatrix);// сложениме матриц
	MyMatrix operator -(const MyMatrix& rightMatrix);// вычитание матриц
	// умножение на число
	// умножение матрицы на матрицу
	// транспонирование
	// создание диагональной матрицы
	// вычесление определителя
	// доступ к строкам матрицы
	// *=
	// -=
	// +=
};

