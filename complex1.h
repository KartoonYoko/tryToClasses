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

	void subCompex(const Complex &comNum);
	void addComplex(const Complex &comNum);
	void multComplex(const Complex &comNum);

	void subReal(const double& realNum);
	void addReal(const double& realNum);
	void multReal(const double& realNum);

	double abs() const;
	double arg() ; // вернет аргумент в градусах
	
	
};
