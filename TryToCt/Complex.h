#pragma once

#include <string>





class Complex {

private:

	double _im = 0;
	double _re = 0;

public:

	Complex();
	Complex(double re, double im);

	Complex operator = (const Complex& comNum2);

	void operator ++(int) ;

	Complex operator + (const Complex& comNum) const;

	double getRe() const;

	double getIm() const;

	std::string toString() const;

	void setRe(double futureRe);

	void setIm(double futureIm);

	void subCompex(const Complex &comNum);

	void addComplex(Complex &comNum);

	void multComplex(Complex &comNum);

	void subReal(double realNum);

	void addReal(double realNum);

	void multReal(double realNum);

	double abs() const;
};
