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

	// ��������� ������� �� ������� row x col
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



	// ������ � ��������� ��������� �������
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

	// ���������� ������� ����� ��������
	void MyMatrix::fill(const VecType &num) {
		for (int i = 0; i < _matrix.size(); i++)
			for (int j = 0; j < _matrix[0].size(); j++) {
				_matrix[i][j] = num;
			}
	}
	// ���������� ������� ���������� ������� �� 0 �� 100, � ���������� ��������
	void MyMatrix::fillRand() {
		srand(time(NULL));
		for (int i = 0; i < _matrix.size(); i++)
			for (int j = 0; j < _matrix[0].size(); j++) {
				_matrix[i][j] = 0.1 * (rand() % 1000);
			}
	}
	// ���������� ������� ���������� ������� �� fromNum �� lastNum, � ���������� ��������
	void MyMatrix::fillRand(const int& fromNum, const int& lastNum) {
		srand(time(NULL));
		for (int i = 0; i < this->getRow(); i++)
			for (int j = 0; j < this->getCol(); j++) {
				_matrix[i][j] = 0.1 * (fromNum * 10 + rand() % ((lastNum - fromNum) * 10 + 1));
			}
	}
	
	
	// ������ � ������� �������
	vector<VecType> MyMatrix::operator [](const int& index) { return _matrix[index]; }

	
	void MyMatrix::operator =(const MyMatrix& rightMatrix) {
		if ((_matrix.size() != rightMatrix.getRow()) && (_matrix[0].size() != rightMatrix.getCol())) throw InvalidSize;
		else {
			for (int i = 0; i < _matrix.size(); i++)
				for (int j = 0; j < _matrix[0].size(); j++) {
					_matrix[i][j] = rightMatrix.getItem(i, j);
				}
		}
	}
	// ��������� ������
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
	// ��������� ������
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


	// ��������� �� �����
	MyMatrix MyMatrix::operator *(const VecType& num) {
		MyMatrix result(this->getRow(), this->getCol());
		for (int i = 0; i < _matrix.size(); i++)
			for (int j = 0; j < _matrix[0].size(); j++) {
				result(i, j) = _matrix[i][j] * num;
			}
		return result;
	}
	// ��������� ������� �� �������
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
	
	// ����������������
	void MyMatrix::transpose() {

		MyMatrix buf(this->getRow(), this->getCol());
		for (int i = 0; i < this->getRow(); i++)
			for (int j = 0; j < this->getCol(); j++) {
				buf(j, i) = this->getItem(i, j);
			}
		*this = buf;
	}
	// �������� ������������ �������
	// ���������� ������������
	
	// *=
	// -=
	// +=

	void MyMatrix::outputConsole() {
		for (int i = 0; i < this->getRow(); i++)
			for (int j = 0; j < this->getCol(); j++) {
				if (j == (this->getCol() - 1)) std::cout << this->getItem(i, j) << std::endl;
				else std::cout << this->getItem(i, j) << "	";
			}
	}

