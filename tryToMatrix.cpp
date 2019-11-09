#include "tryToMatrix.h"
#include <ctime>





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


	void MyMatrix::expand(const int& row, const int& col) {
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
	void MyMatrix::expand(const int& row, const int& col, const VecType& num) {
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



	// ������ � ��������� ��������� �������
	VecType MyMatrix::operator ()(const VecType &row, const VecType &col) const{
			return _matrix[row][col];
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
				_matrix[i][j] = 0.1 * (rand() % 100);
			}
	}
	// ���������� ������� ���������� ������� �� fromNum �� lastNum, � ���������� ��������
	void MyMatrix::fillRand(const int & fromNum, const int& lastNum) {
		srand(time(NULL));
		for (int i = 0; i < _matrix.size(); i++)
			for (int j = 0; j < _matrix[0].size(); j++) {
				_matrix[i][j] = 0.1 * (fromNum * 10 + rand() % (lastNum * 10 + 1));
			}
	}

	// ��������� ������
	// ��������� ������
	// ��������� �� �����
	// ��������� ������� �� �������
	// ����������������
	// �������� ������������ �������
	// ���������� ������������
	// ������ � ������� �������
	// *=
	// -=
	// +=



