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

	void sub(const Complex &comNum);  // вычесть из текущего объекта Complex &comNum
	void add(const Complex &comNum); // сложить с текущим объектом Complex &comNum
	void mult(const Complex &comNum);// умножить текущий объект на Complex &comNum

	void sub(const double& realNum);  // вычесть из текущего объекта double& realNum
	void add(const double& realNum);  // сложить с текущим объектом double& realNum
	void mult(const double& realNum); // умножить текущий объект на double& realNum

	double abs() const; // вернет можуль числа с точностью до 0.01
	double arg() ; // вернет аргумент комплексного числа в градусах c точностью до 0.01
	
	
};
