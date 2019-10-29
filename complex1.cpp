
#include <iostream>
#include <math.h>
#include <string.h>
#include <sstream>
#include <cmath>
#include "complex1.h"

using namespace std;


	Complex::Complex() {
		this->_im = 0;
		this->_re = 0;
	}
	Complex::Complex(double re, double im) {
		this->_im = im;
		this->_re = re;
	}
	
	void Complex::operator ++(int) {
			this->_re += 1;
	}
	
	Complex Complex::operator = (const Complex& comNum) {
		this->_im = comNum.getIm();
		this->_re = comNum.getRe();
		return *this;
	}
	Complex Complex::operator - (const Complex& comNum) {
		Complex c;
		c.setIm(this->_im - comNum.getIm());
		c.setRe(this->_re - comNum.getRe());
		return c;
	}
	Complex Complex::operator / (const Complex& comNum) {
		Complex c;
		if (sqrt(comNum.getRe()) + sqrt(comNum.getIm()) == 0) throw InvalidValue; 
		else {
			c.setIm((comNum.getRe() * this->_im - this->_re * comNum.getIm()) / (pow(comNum.getRe(), 2) + pow(comNum.getIm(), 2)));
			c.setRe((this->_re * comNum.getRe() + this->_im * comNum.getIm()) / (pow(comNum.getRe(), 2) + pow(comNum.getIm(), 2)));
		}
		return c;
	}
	Complex Complex::operator * (const Complex& comNum) {
		Complex c = *this;
		c.setIm(this->_re * comNum.getIm() + this->_im * comNum.getRe());
		c.setRe(this->_re * comNum.getRe() - this->_im * comNum.getIm());
		return c;
	}
	Complex Complex::operator + (const Complex& comNum){
		Complex c;
		c.setIm(this->_im + comNum.getIm());
		c.setRe(this->_re + comNum.getRe());
		return c;
	}

	Complex Complex::operator - (const double& Num) {
		Complex c = *this;
		c.setRe(this->_re - Num);
		return c;
	}
	Complex Complex::operator * (const double& Num) {
		Complex c;
		c = *this;
		c.mult(Num);
		return c;
	}
	Complex Complex::operator / (const double& Num) {
		Complex c;
		if (Num == 0) throw InvalidValue;
		else {
			c.setRe(this->_re / Num);
			c.setIm(this->_im / Num);
		}
		return c;
	}
	Complex Complex::operator + (const double& Num) {
		Complex c;
		c = *this;
		c.add(Num);
		return c;
	}
	Complex Complex::operator = (const double& Num) {
		Complex c;
		c = *this;
		c.setRe(Num);
		c.setIm(0);
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

	void Complex::sub(const Complex &comNum) {
		*this = *this - comNum;
	} 
	void Complex::add(const Complex &comNum) {
		this->_im += comNum.getIm();
		_re += comNum.getRe();
	} 
	void Complex::mult(const Complex &comNum) {
		Complex c = *this;
		c._im = this->_re * comNum.getIm() + this->_im * comNum.getRe();
		c._re = this->_re * comNum.getRe() - this->_im * comNum.getIm();
		*this = c;
	} 

 	void Complex::sub(const double& realNum) {
		_re -= realNum;
	} 
	void Complex::add(const double& realNum) {
		this->_re += realNum;
	} 
	void Complex::mult	(const double& realNum) {
		_re *= realNum;
		_im *= realNum;
	}

	double Complex::abs() const{
		double a = floor(sqrt(pow(_im, 2) + pow(_re, 2)) * 100) / 100;
		return  a;
	} 
	double Complex::arg() {
		const double PI = 3.14159265;
		double argument;

		if ((this->_re == 0 && this->_im > 0)) argument = 90;
		else
			if ((this->_re == 0 && this->_im < 0)) argument = 270;

		if(this->_re > 0 || (this->_re > 0 && this->_im == 0))
			argument = floor(atan(this->_im / this->_re) * 180 / PI * 100) / 100;
		else
			if(this->_im > 0 || (this->_re < 0 && this->_im == 0))
				argument = floor(atan(this->_im / this->_re) * 180 / PI * 100) / 100 - 180;
			else
				argument = floor(atan(this->_im / this->_re) * 180 / PI * 100) / 100 + 180;
		return argument;
	}
	