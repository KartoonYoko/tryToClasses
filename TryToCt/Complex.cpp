
#include <iostream>
#include <math.h>
#include <string.h>
#include <sstream>


#include "Complex.h"



using namespace std;


Complex::Complex() {
	this->_im = 0;
	this->_re = 0;
}

Complex::Complex(double re, double im) {
	this->_im = im;
	this->_re = re;
}

Complex Complex::operator = (const Complex &comNum2) {
	this->_im = comNum2._im;
	this->_re = comNum2._re;
	return *this;
}

	void Complex::operator ++(int) {
		this->_re += 1;
	}


	Complex Complex::operator + (const Complex& comNum) const{
		Complex c;
		c._im = this->_im + comNum._im;
		c._re = this->_re + comNum._re;
		return c;
	}

	double Complex::getRe() const{
		return _re;
	}

	double Complex::getIm() const{
		return _im;
	}

	string Complex::toString() const{
		ostringstream ostr;
		string str = "";
		ostr << _re << " + " << _im << " * i";
		str += ostr.str();
		return str;
	}

	void Complex::setRe(double futureRe) {
		_re = futureRe;
	}

	void Complex::setIm(double futureIm) {
		_im = futureIm;
	}

	void Complex::subCompex(const Complex &comNum) {
		*this = *this + comNum;
	}

	void Complex::addComplex(Complex &comNum) {
		this->_im += comNum.getIm();
		_re += comNum.getRe();
	}

	void Complex::multComplex(Complex &comNum) {
		_im = _re * comNum.getRe() - _im * comNum.getIm();
		_re = _im * comNum.getRe() + _re * comNum.getIm();
	}

	void Complex::subReal(double realNum) {
		_re -= realNum;
	}

	void Complex::addReal(double realNum) {
		this->_re += realNum;
	}

	void Complex::multReal(double realNum) {
		_re *= realNum;
		_im *= realNum;
	}

	double Complex::abs() const{
		double a = sqrt(pow(_im, 2) + pow(_re, 2));
		return  a;
	}