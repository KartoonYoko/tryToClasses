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
*/


using namespace std;

enum MatrixException { InvalidValue, InvalidSize };

typedef double VecType; // ��� ��������� �������(�������)

class MyMatrix
{
private: 


	vector<vector<VecType>> _matrix;

public:


	MyMatrix(); // ������� ������� ������� ������� 1�1
	MyMatrix(const int& row, const int& col); // ������� ������� ������� ������� row x col
	MyMatrix(const int& row, const int& col, const VecType& num); // ������� �������, ����������� ������ num, ������� row x col

	int getCol() const;  // �������� ���-�� ��������
	int getRow() const; //  �������� ���-�� �����

	void expand(const int& row, const int& col); // ��������� ������� �� ������� row x col � ��������� ����� ������ ������
	void expand(const int& row, const int& col, const VecType& num); // ��������� ������� �� ������� row x col � ��������� ����� ������ ������ num

	// ������ � ��������� ��������� �������
	VecType getItem(const int& row, const int& col) const;	// ������ ������� ������� �� ������� row x col
	void setItem(const int& row, const int& col, const VecType& num); // ������ num � ������� �� ������� row x col
	VecType& operator ()(const int& row, const int& col);	// ������ ������� ������� row x col �� ������ (��� �������� �������� �������� � �������)

	// ������ � ������� �������
	vector<VecType> operator [](const int& index);

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
	void diag();// �������� ������������ �������
	double determinant();// ���������� ������������
	
	void outputConsole();// ����� ������� � �������
};

