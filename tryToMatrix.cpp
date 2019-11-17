#include "tryToMatrix.h"
#include <ctime>
#include <iostream>





	MyMatrix::MyMatrix() {
		_matrix.push_back(vector<VecType>(1, 0));
	}
	MyMatrix::MyMatrix(const int& row, const int& col) {
		if ((row < 0) || (col < 0)) throw InvalidSize;
		else
			for (int j = 0; j < row; j++) {
				_matrix.push_back(vector<VecType>(col, 0));
			}
	}
	MyMatrix::MyMatrix(const int& row, const int& col, const VecType& num) {
		if ((row < 0) || (col < 0)) throw InvalidSize;
		else
		for (int j = 0; j < row; j++) {
			_matrix.push_back(vector<VecType>(col, num));
		}
	}



	int MyMatrix::getCol() const{
		return _matrix[0].size();
	}
	int MyMatrix::getRow() const{
		return _matrix.size();
	}

	// расширяет матрицу до размера row x col
	void MyMatrix::expand(const int& row, const int& col) {
		if (_matrix.size() >= row && _matrix[0].size() >= col) throw InvalidSize;
		else {
			int diffCol = col - _matrix[0].size();
			int diffRow = row - _matrix.size();
			for (int j = 0; j < _matrix.size(); j++)
				for (int i = 0; i < diffCol; i++) {
					_matrix[j].push_back(0);
				}
			for (int j = 0; j < diffRow; j++) {
				_matrix.push_back(vector<VecType>(_matrix[0].size(), 0));
			}
		}
	}
	void MyMatrix::expand(const int& row, const int& col, const VecType& num) {
		if (_matrix.size() >= row && _matrix[0].size() >= col) throw InvalidSize;
		else {
			int diffCol = col - _matrix[0].size();
			int diffRow = row - _matrix.size();
			for (int j = 0; j < _matrix.size(); j++)
				for (int i = 0; i < diffCol; i++) {
					_matrix[j].push_back(0);
				}
			for (int j = 0; j < diffRow; j++) {
				_matrix.push_back(vector<VecType>(_matrix[0].size(), num));
			}
		}
	}



	// доступ к отдельным элементам матрицы
	VecType MyMatrix::getItem(const int &row, const int &col) const{
		if ((row < 0) || (col < 0) || (col >= this->getCol()) || (row >= this->getRow())) throw InvalidSize;
		else {
			return _matrix[row][col];
		}
	}
	void MyMatrix::setItem(const int& row, const int& col, const VecType& num) {
		if ((row < 0) || (col < 0) || (col >= this->getCol()) || (row >= this->getRow())) throw InvalidSize;
		else {
			_matrix[row][col] = num;;
		}
	}
	VecType& MyMatrix::operator ()(const int& row, const int& col) {
		if ((row < 0) || (col < 0) || (col >= this->getCol()) || (row >= this->getRow())) throw InvalidSize;
		else {
			return _matrix[row][col];
		}
	}

	// заполнение матрицы одним значение
	void MyMatrix::fill(const VecType &num) {
		for (int i = 0; i < _matrix.size(); i++)
			for (int j = 0; j < _matrix[0].size(); j++) {
				_matrix[i][j] = num;
			}
	}
	// заполнение матрицы случайными числами от 0 до 100, с десятичным остатком
	void MyMatrix::fillRand() {
		srand(time(NULL));
		for (int i = 0; i < _matrix.size(); i++)
			for (int j = 0; j < _matrix[0].size(); j++) {
				_matrix[i][j] = 0.1 * (rand() % 1000);
			}
	}
	// заполнение матрицы случайными числами от fromNum до lastNum, с десятичным остатком
	void MyMatrix::fillRand(const int& fromNum, const int& lastNum) {
		srand(time(NULL));
		for (int i = 0; i < this->getRow(); i++)
			for (int j = 0; j < this->getCol(); j++) {
				_matrix[i][j] = 0.1 * (fromNum * 10 + rand() % ((lastNum - fromNum) * 10 + 1));
			}
	}
	
	
	// доступ к строкам матрицы
	vector<VecType>& MyMatrix::operator [](const int& index) { return _matrix[index]; }

	
	void MyMatrix::operator =(const MyMatrix& rightMatrix) {
		if ((this->getRow() != rightMatrix.getRow()) && (this->getCol() != rightMatrix.getCol())) throw InvalidSize;
		else {
			for (int i = 0; i < _matrix.size(); i++)
				for (int j = 0; j < _matrix[0].size(); j++) {
					_matrix[i][j] = rightMatrix.getItem(i, j);
				}
		}
	}
	// сложениме матриц
	MyMatrix MyMatrix::operator +(const MyMatrix& rightMatrix) {
		if ((_matrix.size() != rightMatrix.getRow()) && (_matrix[0].size() != rightMatrix.getCol())) throw InvalidSize;
		else {
			MyMatrix result(rightMatrix.getRow(), rightMatrix.getCol());
			for (int i = 0; i < _matrix.size(); i++)
				for (int j = 0; j < _matrix[0].size(); j++) {
					result(i, j) = _matrix[i][j] + rightMatrix.getItem(i, j);
				}
			return result;
		}
	}
	void MyMatrix::operator +=(const MyMatrix& rightMatrix) { *this = *this + rightMatrix; }
	// вычитание матриц
	MyMatrix MyMatrix::operator -(const MyMatrix& rightMatrix) {
		if ((_matrix.size() != rightMatrix.getRow()) && (_matrix[0].size() != rightMatrix.getCol())) throw InvalidSize;
		else {
			MyMatrix result(rightMatrix.getRow(), rightMatrix.getCol());
			for (int i = 0; i < _matrix.size(); i++)
				for (int j = 0; j < _matrix[0].size(); j++) {
					result(i, j) = _matrix[i][j] - rightMatrix.getItem(i, j);
				}
			return result;
		}
	}
	void MyMatrix::operator -=(const MyMatrix& rightMatrix) { *this = *this - rightMatrix; }
	

	// умножение на число
	MyMatrix MyMatrix::operator *(const VecType& num) {
		MyMatrix result(this->getRow(), this->getCol());
		for (int i = 0; i < _matrix.size(); i++)
			for (int j = 0; j < _matrix[0].size(); j++) {
				result(i, j) = _matrix[i][j] * num;
			}
		return result;
	}
	void MyMatrix::operator *=(const VecType& num) { *this = (*this) * num; }
	// умножение матрицы на матрицу
	MyMatrix MyMatrix::operator *(const MyMatrix& rightMatrix) {
		if (this->getCol() != rightMatrix.getRow()) throw InvalidSize;
		else {
			MyMatrix result(this->getRow(), rightMatrix.getCol());
			for (int i = 0; i < result.getRow(); i++)
				for (int j = 0; j < result.getCol(); j++) {

					for (int k = 0; k < this->getCol(); k++) {
						result(i, j) = result(i, j) + (this->getItem(i, k) * rightMatrix.getItem(k, j));
					} 
				}
			return result;
		}
	}
	void MyMatrix::operator *=(const MyMatrix& rightMatrix) { *this = (*this) * rightMatrix;	}

	// транспонирование
	void MyMatrix::transpose() {

		MyMatrix buf(this->getRow(), this->getCol());
		for (int i = 0; i < this->getRow(); i++)
			for (int j = 0; j < this->getCol(); j++) {
				buf(j, i) = this->getItem(i, j);
			}
		*this = buf;
	}
	// транспонирование матрицы, результат в matrix
	void MyMatrix::transpose(MyMatrix& matrix) {
		if ((this->getRow() != matrix.getRow()) && (this->getCol() != matrix.getCol())) throw InvalidSize;
		else
		{
			for (int i = 0; i < this->getRow(); i++)
				for (int j = 0; j < this->getCol(); j++) {
					matrix(j, i) = this->getItem(i, j);
				}
		}
	}
	// создание диагональной матрицы
	void MyMatrix::diag() {
		for (int i = 0; i < this->getRow(); i++)
			for (int j = 0; j < this->getCol(); j++) {
				if (i != j) this->setItem(i, j, 0);
			}
	}
	// вычесление определителя
	double MyMatrix::determinant() {
		if (this->getCol() != this->getRow()) throw InvalidSize;
		else if (this->getCol() == 1) return this->getItem(0, 0);
		else {

			double sum = 0;

			for (int i = 0; i < this->getCol(); i++) {

				/*Создание матрицы для определения минора*/
				MyMatrix buf(this->getRow() - 1, this->getCol() - 1);
				
				if ((i != 0) && (i != this->getCol() - 1)) {
					/////// i1 - счетчик строк, j1 - счетчик столбцов
					for (int i1 = 0; i1 < buf.getRow(); i1++)
						for (int j1 = 0; j1 < i; j1++) {
							buf(i1, j1) = this->getItem(i1 + 1, j1);
						}
					for (int i1 = 0; i1 < buf.getRow(); i1++)
						for (int j1 = i; j1 < buf.getCol(); j1++) {
							buf(i1, j1) = this->getItem(i1 + 1, j1 + 1); 
						}
				}  //////
				else if (i != 0) { // if (i == this->getCol() - 1) // последняя итерация
					for (int i1 = 0; i1 < buf.getRow(); i1++)
						for (int j1 = 0; j1 < buf.getCol(); j1++) {
							buf(i1, j1) = this->getItem(i1 + 1, j1);
						}
				}
				else {
					for (int i1 = 0; i1 < buf.getRow(); i1++)		// if (i == 0) // первая итерация
						for (int j1 = 0; j1 < buf.getCol(); j1++) {
							buf(i1, j1) = this->getItem(i1 + 1, j1 + 1);
						}
				}

				/*Cумма произведений элементов ПЕРВОЙ строки на соответствующии алгебраические дополнения*/
				double ch = this->getItem(0, i);
				int asd = pow(-1, i);
				double dete = buf.determinant();
				sum += this->getItem(0, i) * pow(-1, i) * buf.determinant();
				
			}


			return sum;
		}
	}
	// возвращает обратную матрицу
	MyMatrix MyMatrix::invertMatrix() {

		// определитель > 0, матрица должна быть квадратная
		if ((this->determinant() == 0) || (this->getCol() != this->getRow())) throw InvalidValue;
		else {
			MyMatrix result(this->getRow(), this->getCol());
			for (int i = 0; i < this->getRow(); i++)
				for (int j = 0; j < this->getRow(); j++) {
					result(i, j) = findAlgComp(*this, i, j);
				}
			result.transpose();

			result *= (1 / this->determinant());
			return result;
		}
	}

	void MyMatrix::outputConsole() {
		for (int i = 0; i < this->getRow(); i++)
			for (int j = 0; j < this->getCol(); j++) {
				if (j == (this->getCol() - 1)) std::cout << this->getItem(i, j) << std::endl;
				else std::cout << this->getItem(i, j) << "	";
			}
	}

