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

	void expand(const int& row, const int& col); // расширяет матрицу до размера row x col и заполняет новые ячейки нулями
	void expand(const int& row, const int& col, const VecType& num); // расширяет матрицу до оазмера row x col и заполняет новые ячейки числом num

	// доступ к отдельным элементам матрицы
	VecType getItem(const int& row, const int& col) const;	// вернет элемент матрицы на позицию row x col
	void setItem(const int& row, const int& col, const VecType& num); // внесет num в матрицу на позицию row x col
	VecType& operator ()(const int& row, const int& col);	// вернет адрес элемента матрицы row x col (для быстрого внесения значения в матрицу)

	// доступ к строкам матрицы
	vector<VecType> operator [](const int& index);

	// заполнение матрицы
	void fill(const VecType& num);	// заполнение матрицы одним значение
	void fillRand();	// заполнение матрицы случайными числами
	void fillRand(const int& fromNum, const int& lastNum);	// заполнение матрицы случайными числами от fromNum до lastNum(целочисленного типа, т.к. рандом работает только с целыми), с десятичным остатком

	void operator =(const MyMatrix &rightMatrix); // в левую матрицу заносятся значения правой матрицы (толко для одноразмерных матриц)
	MyMatrix operator +(const MyMatrix& rightMatrix); // сложениме матриц
	MyMatrix operator -(const MyMatrix& rightMatrix); // вычитание матриц
	MyMatrix operator *(const VecType& num); // умножение на число
	MyMatrix operator *(const MyMatrix& rightMatrix); // умножение матрицы на матрицу

	void transpose();// транспонирование текущей матрицы
	// создание диагональной матрицы
	// вычесление определителя
	// *=
	// -=
	// +=





	void outputConsole();// вывод матрицы в консоль
};

