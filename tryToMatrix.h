#pragma once

#include <vector>

/*
		Класс матрица. Класс представляет матрицу размера N x M, где N - кол-во строк, M - кол-во столбцов.
	Класс имеет следующие возможности:
		- доступ к каждому отдельному элементу
		- заполнение матрицы как заданным значением, так и случайными числами
		- сложение, вычитание, умножение матриц
		- умножение на число
		- транспонирование
		- создание диагональной матрицы из текущей
		- нахождение определителя
		- нахождение обратной матрицы
*/


using namespace std;

enum MatrixException { InvalidValue, InvalidSize };

typedef double typeOfItem; // тип элементов матрицы(вектора)

class MyMatrix
{
private: 


	vector<vector<typeOfItem>> _matrix;

	/*
		Для нахождения алгебраического дополнения(понадобится в методе invertMatrix)
	Ищет в матрице matrix алгебраическое дополнение для row x col элемента
	*/
	double findAlgComp(const MyMatrix& matrix, const int& row, const int& col) { // todo: сделать через friend
		MyMatrix buf(matrix.getRowCount() - 1, matrix.getColCount() - 1);
		double result = 0;
		int i1 = 0, j1 = 0;
		for (int i = 0; i < matrix.getRowCount(); i++)
			for (int j = 0; j < matrix.getRowCount(); j++) {
				if ((i != row) && (j != col)) {
					buf(i1, j1) = matrix.getItem(i, j);
					if (j1 == matrix.getColCount() - 2) {
						j1 = 0;
						if (i1 == matrix.getRowCount() - 2) i1 = 0; else i1++;
					}
					else j1++;
				}
			}
		result = buf.determinant() * pow(-1, (row + col));
		return result;
	}

public:

	
	MyMatrix(); // создает нулевую матрицу размера 1х1
	MyMatrix(int row, int col); // создает нулевую матрицу размера row x col
	MyMatrix(int row, int col, const typeOfItem& num); // создает матрицу, заполненную числом num, размера row x col

	int getColCount() const;  // получить кол-во столбцов
	int getRowCount() const; //  получить кол-во строк

	void expand(int row, int col); // расширяет матрицу до размера row x col и заполняет новые ячейки нулями
	void expand(int row, int col, const typeOfItem& num); // расширяет матрицу до оазмера row x col и заполняет новые ячейки числом num

	// доступ к отдельным элементам матрицы (отсчет начинается с нуля)
	typeOfItem getItem(int row, int col) const;	// вернет элемент матрицы с позиции row x col
	void setItem(int row, int col, const typeOfItem& num); // внесет num в матрицу на позицию row x col
	typeOfItem& operator ()(int row, int col);	// вернет элемент матрицы row x col по ссылке (для быстрого внесения значения в матрицу)

	// доступ к строкам матрицы
	vector<typeOfItem>& operator [](int index);

	// заполнение матрицы
	void fill(const typeOfItem& num);	// заполнение матрицы одним значение
	void fillRand();	// заполнение матрицы случайными числами
	void fillRand(const int& fromNum, const int& lastNum);	// заполнение матрицы случайными числами от fromNum до lastNum(целочисленного типа, т.к. рандом работает только с целыми), с десятичным остатком

	void assign(const MyMatrix &rightMatrix); // в левую матрицу заносятся значения правой матрицы (толко для одноразмерных матриц)
	MyMatrix operator +(const MyMatrix& rightMatrix); // сложениме матриц
	MyMatrix operator -(const MyMatrix& rightMatrix); // вычитание матриц
	MyMatrix operator *(const typeOfItem& num); // умножение на число
	MyMatrix operator *(const MyMatrix& rightMatrix); // умножение матрицы на матрицу
	void operator *=(const MyMatrix& rightMatrix);
	void operator *=(const typeOfItem& num);
	void operator -=(const MyMatrix& rightMatrix);
	void operator +=(const MyMatrix& rightMatrix);

	void transpose();// транспонирование текущей матрицы
	void transpose(MyMatrix& matrix);// транспонирование матрицы, результат в matrix
	void diag();// создание диагональной матрицы
	double determinant();// вычесление определителя
	MyMatrix invertMatrix(); // возвращает обратную матрицу
	
	void outputConsole();// вывод матрицы в консоль
};

