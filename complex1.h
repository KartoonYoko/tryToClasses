#pragma once

#include <string>


enum ComplexException { InvalidValue };


class Complex {

private:

	double _im = 0;
	double _re = 0;

public:
	
	Complex();
	Complex(double re, double im);

	void operator ++(int);
	
	Complex operator - (const Complex& comNum);
	Complex operator / (const Complex& comNum);
	Complex operator = (const Complex& comNum);
	Complex operator + (const Complex& comNum);
	Complex operator * (const Complex& comNum);

	Complex operator - (const double& Num);
	Complex operator / (const double& Num);
	Complex operator + (const double& Num);
	Complex operator = (const double& Num);
	Complex operator * (const double& Num);

	double getRe() const;
	double getIm() const;

	std::string toString() const;

	void setRe(double futureRe);
	void setIm(double futureIm);

	void sub(const Complex &comNum);  // ������� �� �������� ������� Complex &comNum
	void add(const Complex &comNum); // ������� � ������� �������� Complex &comNum
	void mult(const Complex &comNum);// �������� ������� ������ �� Complex &comNum

	void sub(const double& realNum);  // ������� �� �������� ������� double& realNum
	void add(const double& realNum);  // ������� � ������� �������� double& realNum
	void mult(const double& realNum); // �������� ������� ������ �� double& realNum

	double abs() const; // ������ ������ ����� � ��������� �� 0.01
	double arg() ; // ������ �������� ������������ ����� � �������� c ��������� �� 0.01
	
	
};
