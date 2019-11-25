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

typedef double typeOfItem; // ��� ��������� �������(�������)

class MyMatrix
{
private: 


	vector<vector<typeOfItem>> _matrix;

	/*
		��� ���������� ��������������� ����������(����������� � ������ invertMatrix)
	���� � ������� matrix �������������� ���������� ��� row x col ��������
	*/
	double findAlgComp(const MyMatrix& matrix, const int& row, const int& col) { // todo: ������� ����� friend
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

	
	MyMatrix(); // ������� ������� ������� ������� 1�1
	MyMatrix(int row, int col); // ������� ������� ������� ������� row x col
	MyMatrix(int row, int col, const typeOfItem& num); // ������� �������, ����������� ������ num, ������� row x col

	int getColCount() const;  // �������� ���-�� ��������
	int getRowCount() const; //  �������� ���-�� �����

	void expand(int row, int col); // ��������� ������� �� ������� row x col � ��������� ����� ������ ������
	void expand(int row, int col, const typeOfItem& num); // ��������� ������� �� ������� row x col � ��������� ����� ������ ������ num

	// ������ � ��������� ��������� ������� (������ ���������� � ����)
	typeOfItem getItem(int row, int col) const;	// ������ ������� ������� � ������� row x col
	void setItem(int row, int col, const typeOfItem& num); // ������ num � ������� �� ������� row x col
	typeOfItem& operator ()(int row, int col);	// ������ ������� ������� row x col �� ������ (��� �������� �������� �������� � �������)

	// ������ � ������� �������
	vector<typeOfItem>& operator [](int index);

	// ���������� �������
	void fill(const typeOfItem& num);	// ���������� ������� ����� ��������
	void fillRand();	// ���������� ������� ���������� �������
	void fillRand(const int& fromNum, const int& lastNum);	// ���������� ������� ���������� ������� �� fromNum �� lastNum(�������������� ����, �.�. ������ �������� ������ � ������), � ���������� ��������

	void assign(const MyMatrix &rightMatrix); // � ����� ������� ��������� �������� ������ ������� (����� ��� ������������� ������)
	MyMatrix operator +(const MyMatrix& rightMatrix); // ��������� ������
	MyMatrix operator -(const MyMatrix& rightMatrix); // ��������� ������
	MyMatrix operator *(const typeOfItem& num); // ��������� �� �����
	MyMatrix operator *(const MyMatrix& rightMatrix); // ��������� ������� �� �������
	void operator *=(const MyMatrix& rightMatrix);
	void operator *=(const typeOfItem& num);
	void operator -=(const MyMatrix& rightMatrix);
	void operator +=(const MyMatrix& rightMatrix);

	void transpose();// ���������������� ������� �������
	void transpose(MyMatrix& matrix);// ���������������� �������, ��������� � matrix
	void diag();// �������� ������������ �������
	double determinant();// ���������� ������������
	MyMatrix invertMatrix(); // ���������� �������� �������
	
	void outputConsole();// ����� ������� � �������
};

