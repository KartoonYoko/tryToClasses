#pragma once

#include <vector>

/*
		����� �������. ����� ������������ ������� ������� N x M, ��� N - ���-�� �����, M - ���-�� ��������.
	����� ����� ��������� �����������:
		- ������ � ������� ���������� ��������
		- ���������� ������� ��� �������� ���������, ��� � ���������� �������
		- ��������, ���������, ��������� ������
		- ��������� �� �����
		- ����������������
		- �������� ������������ ������� �� �������
		- ���������� ������������
		- ���������� �������� �������
*/


using namespace std;

enum MatrixException { InvalidValue, InvalidSize };

typedef double VecType; // ��� ��������� �������(�������)

class MyMatrix
{
private: 


	vector<vector<VecType>> _matrix;

	// ��� ���������� ��������������� ����������(����������� � ������ invertMatrix)
	VecType findAlgComp(const MyMatrix& matrix, const int& row, const int& col) {
		MyMatrix buf(matrix.getRow() - 1, matrix.getCol() - 1);
		VecType result = 0;
		int i1 = 0, j1 = 0;
		for (int i = 0; i < matrix.getRow(); i++)
			for (int j = 0; j < matrix.getRow(); j++) {
				if ((i != row) && (j != col)) {
					buf(i1, j1) = matrix.getItem(i, j);
					if (j1 == matrix.getCol() - 1) {
						j1 = 0;
						if (i1 == matrix.getRow() - 1) i1 = 0; else i1++;
					}
					else j1++;
				}
			}
		result = buf.determinant() * pow(-1, (row + col));
		return result;
	}

public:


	MyMatrix(); // ������� ������� ������� ������� 1�1
	MyMatrix(const int& row, const int& col); // ������� ������� ������� ������� row x col
	MyMatrix(const int& row, const int& col, const VecType& num); // ������� �������, ����������� ������ num, ������� row x col

	int getCol() const;  // �������� ���-�� ��������
	int getRow() const; //  �������� ���-�� �����

	void expand(const int& row, const int& col); // ��������� ������� �� ������� row x col � ��������� ����� ������ ������
	void expand(const int& row, const int& col, const VecType& num); // ��������� ������� �� ������� row x col � ��������� ����� ������ ������ num

	// ������ � ��������� ��������� ������� (������ ���������� � ����!)
	VecType getItem(const int& row, const int& col) const;	// ������ ������� ������� � ������� row x col
	void setItem(const int& row, const int& col, const VecType& num); // ������ num � ������� �� ������� row x col
	VecType& operator ()(const int& row, const int& col);	// ������ ������� ������� row x col �� ������ (��� �������� �������� �������� � �������)

	// ������ � ������� �������
	vector<VecType>& operator [](const int& index);

	// ���������� �������
	void fill(const VecType& num);	// ���������� ������� ����� ��������
	void fillRand();	// ���������� ������� ���������� �������
	void fillRand(const int& fromNum, const int& lastNum);	// ���������� ������� ���������� ������� �� fromNum �� lastNum(�������������� ����, �.�. ������ �������� ������ � ������), � ���������� ��������

	void operator =(const MyMatrix &rightMatrix); // � ����� ������� ��������� �������� ������ ������� (����� ��� ������������� ������)
	MyMatrix operator +(const MyMatrix& rightMatrix); // ��������� ������
	MyMatrix operator -(const MyMatrix& rightMatrix); // ��������� ������
	MyMatrix operator *(const VecType& num); // ��������� �� �����
	MyMatrix operator *(const MyMatrix& rightMatrix); // ��������� ������� �� �������
	void operator *=(const MyMatrix& rightMatrix);
	void operator *=(const VecType& num);
	void operator -=(const MyMatrix& rightMatrix);
	void operator +=(const MyMatrix& rightMatrix);

	void transpose();// ���������������� ������� �������
	void transpose(MyMatrix& matrix);// ���������������� �������, ��������� � matrix
	void diag();// �������� ������������ �������
	double determinant();// ���������� ������������
	MyMatrix invertMatrix(); // ���������� �������� �������
	
	void outputConsole();// ����� ������� � �������
};

