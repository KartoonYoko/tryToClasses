#include <iostream>
#include <cassert>
#include "test.h"


using namespace std;

void test_ComplexClass_constructor() {
	
	{
		Complex num;
		assert((num.getRe() == 0) && (num.getIm() == 0));
	}

	{
		Complex num(2,5);
		assert((num.getRe() == 2) && (num.getIm() == 5));
	}

	{
		Complex num(2.5, 5.89);
		assert((num.getRe() == 2.5) && (num.getIm() == 5.89));
	}

	{
		Complex *num = new Complex;
		assert((num->getRe() == 0) && (num->getIm() == 0));
	}

	{
		Complex* num = new Complex(3,4);
		assert((num->getRe() == 3) && (num->getIm() == 4));
	}
	
	cout << "test_ComplexClass_constructor OK" << endl;
} 
void test_ComplexClass_ComplexMinusComplex_OperatorMinus() {

	{
		Complex num1(4, 2);
		Complex num2(2, 1);
		Complex result = num1 - num2;
		assert((result.getRe() == 2) && (result.getIm() == 1) && "ComplexMinusComplex_OperatorMinus Failed");
	}

	{
		Complex num1(0, 0);
		Complex num2(0, 0);
		Complex result = num1 - num2;
		assert((result.getRe() == 0) && (result.getIm() == 0) && "ComplexMinusComplex_OperatorMinus Failed");
	}

	{
		Complex num1(0, 0);
		Complex num2(-1, -19);
		Complex result = num1 - num2;
		assert((result.getRe() == 1) && (result.getIm() == 19) && "ComplexMinusComplex_OperatorMinus Failed");
	}

	cout << "test_ComplexClass_ComplexMinusComplex_OperatorMinus OK" << endl;
}
void test_ComplexClass_ComplexDivideComplex_OperatorDivision() {
	{
		Complex num1(4, 2);
		Complex num2(2, 1);
		Complex result = num1 / num2;
		assert((result.getRe() == 2) && (result.getIm() == 0) && "ComplexNumberDivideComplexNumber_OperatorDivision Failed");
	}

	{
		try {
			Complex num1(4, 2);
			Complex num2(0, 0);
			Complex result = num1 / num2;
			assert(0 && "(num2 = num1 / num2) Failed");
		}
		catch (ComplexException e) { ; }
	}

	cout << "test_ComplexClass_ComplexDivideComplex_OperatorDivision OK" << endl;
}
void test_ComplexClass_ComplexMultiplyComplex_OperatorMultiplication() {

	{
		Complex num1(4, 2);
		Complex num2(2, 1);
		Complex result = num1 * num2;
		assert((result.getRe() == 6) && (result.getIm() == 8) && "ComplexMultiplyComplex_OperatorMultiplication Failed");
	}

	{
		Complex num1(0, 0);
		Complex num2(0, 0);
		Complex result = num1 * num2;
		assert((result.getRe() == 0) && (result.getIm() == 0) && "ComplexMultiplyComplex_OperatorMultiplication Failed");
	}

	cout << "test_ComplexClass_ComplexMultiplyComplex_OperatorMultiplication OK" << endl;
}
void test_ComplexNumber_ComplexPlusComplex_OperatorPlus() {

	{
		Complex num1(4, 2);
		Complex num2(2, 1);
		Complex result = num1 + num2;
		assert((result.getRe() == 6) && (result.getIm() == 3) && "ComplexPlusComplex_OperatorPlus Failed");
	}

	{
		Complex num1(0, 0);
		Complex num2(-2, -1);
		Complex result = num1 + num2;
		assert((result.getRe() == -2) && (result.getIm() == -1) && "ComplexPlusComplex_OperatorPlus Failed");
	}

	{
		Complex num1(1.1,0 );
		Complex num2(2.1, 1.1);
		Complex result = num1 + num2;
		assert((result.getRe() == 3.2) && (result.getIm() == 1.1) && "ComplexPlusComplex_OperatorPlus Failed");
	}

	cout << "test_ComplexClass_ComplexPlusComplex_OperatorPlus OK" << endl;
}


void test_ComplexClass_ComplexMinusReal_OperatorMinus() {
	{
		Complex num1(4, 2);
		double num2 = 4;
		Complex result = num1 - num2;
		assert((result.getRe() == 0) && (result.getIm() == 2) && "ComplexMinusReal_OperatorMinus Failed");
	}

	{
		Complex num1(0, 0);
		double num2 = 4;
		Complex result = num1 - num2;
		assert((result.getRe() == -4) && (result.getIm() == 0) && "ComplexMinusReal_OperatorMinus Failed");
	}

	{
		Complex num1(-3, 0);
		double num2 = 4;
		Complex result = num1 - num2;
		assert((result.getRe() == -7) && (result.getIm() == 0) && "ComplexMinusReal_OperatorMinus Failed");
	}

	cout << "test_ComplexClass_ComplexMinusReal_OperatorMinus OK" << endl;
}
void test_ComplexClass_ComplexDivideReal_OperatorDivision() {
	{
		Complex num1(4, 2);
		double num2 = 4;
		Complex result = num1 / num2;
		assert((result.getRe() == 1) && (result.getIm() == 0.5) && "ComplexDivideReal_OperatorDivision Failed");
	}

	{
		try {
			Complex num1(4, 2);
			double num2 = 0;
			Complex result = num1 / num2;
			assert(0 && "ComplexDivideReal_OperatorDivision Failed");
		}
		catch (ComplexException e) { ; }
	}

	cout << "test_ComplexClass_ComplexDivideReal_OperatorDivision OK" << endl;
}
void test_ComplexClass_ComplexMultiplyReal_OperatorMultiplication() {

	{
		Complex num1(4, 2);
		double num2 = 4;
		Complex result = num1 * num2;
		assert((result.getRe() == 16) && (result.getIm() == 8) && "ComplexMultiplyReal_OperatorMultiplication Failed");
	}

	{
		Complex num1(0, 0);
		double num2 = 4;
		Complex result = num1 / num2;
		assert((result.getRe() == 0) && (result.getIm() == 0) && "ComplexMultiplyReal_OperatorMultiplication Failed");
	}

	cout << "test_ComplexClass_ComplexMultiplyReal_OperatorMultiplication OK" << endl;
}
void test_ComplexNumber_ComplexPlusReal_OperatorPlus() {

	{
		Complex num1(4, 2);
		double num2 = 4;
		Complex result = num1 + num2;
		assert((result.getRe() == 8) && (result.getIm() == 2) && "ComplexPlusReal_OperatorPlus Failed");
	}

	{
		Complex num1(0, 0);
		double num2 = 4;
		Complex result = num1 + num2;
		assert((result.getRe() == 4) && (result.getIm() == 0) && "ComplexPlusReal_OperatorPlus Failed");
	}

	{
		Complex num1(1.1, 0);
		double num2 = 4;
		Complex result = num1 + num2;
		assert((result.getRe() == 5.1) && (result.getIm() == 0) && "ComplexPlusReal_OperatorPlus Failed");
	}

	cout << "test_ComplexClass_ComplexPlusReal_OperatorPlus OK" << endl;
}

void test_ComplexClass_ComplexMinusComplex_MethodSub() {

	{
		Complex result(4, 2);
		Complex num2(2, 1);
		result.sub(num2);
		assert((result.getRe() == 2) && (result.getIm() == 1) && "ComplexMinusComplex_MethodSub Failed");
	}

	{
		Complex result(0, 0);
		Complex num2(0, 0);
		result.sub(num2);
		assert((result.getRe() == 0) && (result.getIm() == 0) && "ComplexMinusComplex_MethodSub Failed");
	}

	{
		Complex result(0, 0);
		Complex num2(-1, -19);
		result.sub(num2);
		assert((result.getRe() == 1) && (result.getIm() == 19) && "ComplexMinusComplex_MethodSub Failed");
	}

	cout << "test_ComplexClass_ComplexMinusComplex_MethodSub OK" << endl;
}
void test_ComplexClass_ComplexMultiplyComplex_MethodMult() {
	{
		Complex result(4, 2);
		Complex num2(2, 1);
		result.mult(num2);
		assert((result.getRe() == 6) && (result.getIm() == 8) && "ComplexMultiplyComplex_MethodMult Failed");
	}

	{
		Complex result(0, 0);
		Complex num2(0, 0);
		result.mult(num2);
		assert((result.getRe() == 0) && (result.getIm() == 0) && "ComplexMultiplyComplex_MethodMult Failed");
	}

	cout << "test_ComplexClass_ComplexMultiplyComplex_MethodMult OK" << endl;
}
void test_ComplexNumber_ComplexPlusComplex_MethodAdd() {
	{
		Complex result(4, 2);
		Complex num2(2, 1);
		result.add(num2);
		assert((result.getRe() == 6) && (result.getIm() == 3) && "ComplexPlusComplex_MethodAdd Failed");
	}

	{
		Complex result(0, 0);
		Complex num2(-2, -1);
		result.add(num2);
		assert((result.getRe() == -2) && (result.getIm() == -1) && "ComplexPlusComplex_MethodAdd Failed");
	}

	{
		Complex result(1.1, 0);
		Complex num2(2.1, 1.1);
		result.add(num2);
		assert((result.getRe() == 3.2) && (result.getIm() == 1.1) && "ComplexPlusComplex_MethodAdd Failed");
	}

	cout << "test_ComplexClass_ComplexPlusComplex_MethodAdd OK" << endl;
}

void test_ComplexClass_ComplexMinusReal_MethodSub() {
	{
		Complex result(4, 2);
		double num2 = 4;
		result.sub(num2);
		assert((result.getRe() == 0) && (result.getIm() == 2) && "ComplexMinusReal_MethodSub Failed");
	}

	{
		Complex result(0, 0);
		double num2 = 4;
		result.sub(num2);
		assert((result.getRe() == -4) && (result.getIm() == 0) && "ComplexMinusReal_MethodSub Failed");
	}

	{
		Complex result(-3, 0);
		double num2 = 4;
		result.sub(num2);
		assert((result.getRe() == -7) && (result.getIm() == 0) && "ComplexMinusReal_MethodSub Failed");
	}

	cout << "test_ComplexClass_ComplexMinusReal_MethodSub OK" << endl;
}
void test_ComplexClass_ComplexMultiplyReal_MethodMult() {
	{
		Complex result(4, 2);
		double num2 = 4;
		result.mult(num2);
		assert((result.getRe() == 16) && (result.getIm() == 8) && "ComplexMultiplyReal_MethodMult Failed");
	}

	{
		Complex result(0, 0);
		double num2 = 4;
		result.mult(num2);
		assert((result.getRe() == 0) && (result.getIm() == 0) && "ComplexMultiplyReal_MethodMult Failed");
	}

	cout << "test_ComplexClass_ComplexMultiplyReal_MethodMult OK" << endl;
}
void test_ComplexNumber_ComplexPlusReal_MethodAdd() {
	{
		Complex result(4, 2);
		double num2 = 4;
		result.add(num2);
		assert((result.getRe() == 8) && (result.getIm() == 2) && "ComplexPlusReal_OperatorPlus Failed");
	}

	{
		Complex result(0, 0);
		double num2 = 4;
		result.add(num2);
		assert((result.getRe() == 4) && (result.getIm() == 0) && "ComplexPlusReal_OperatorPlus Failed");
	}

	{
		Complex result(1.1, 0);
		double num2 = 4;
		result.add(num2);
		assert((result.getRe() == 5.1) && (result.getIm() == 0) && "ComplexPlusReal_OperatorPlus Failed");
	}

	cout << "test_ComplexClass_ComplexPlusReal_OperatorPlus OK" << endl;
}

void test_ComplexClass_FindingAbsoluteOfComplex() {
	{
		Complex num(2, 4);
		double result;
		result = num.abs();
		assert((result == 4.47) && "FindingAbsoluteOfComplex Failed");
	}

	{
		Complex num(-2, -4);
		double result;
		result = num.abs();
		assert((result == 4.47) && "FindingAbsoluteOfComplex Failed");
	}

	cout << "test_ComplexClass_FindingAbsoluteOfComplex OK" << endl;
}
void test_ComplexClass_FindingArgumentOfComplex() {
	{
		Complex num(2, 4);
		double result;
		result = num.arg();
		assert((result == 63.43) && "FindingArgumentOfComplex Failed");
	}

	{
		Complex num(-2, -4);
		double result;
		result = num.arg();
		assert((result == 243.43) && "FindingArgumentOfComplex Failed");
	}

	cout << "test_ComplexClass_FindingArgumentOfComplex OK" << endl;
}





void test_ComplexClass_all() {

	test_ComplexClass_constructor();

	test_ComplexClass_ComplexMinusComplex_OperatorMinus();
	test_ComplexClass_ComplexDivideComplex_OperatorDivision();
	test_ComplexClass_ComplexMultiplyComplex_OperatorMultiplication();
	test_ComplexNumber_ComplexPlusComplex_OperatorPlus();

	test_ComplexClass_ComplexMinusReal_OperatorMinus();
	test_ComplexClass_ComplexDivideReal_OperatorDivision();
	test_ComplexClass_ComplexMultiplyReal_OperatorMultiplication();
	test_ComplexNumber_ComplexPlusReal_OperatorPlus();

	test_ComplexClass_ComplexMinusComplex_MethodSub();
	test_ComplexClass_ComplexMultiplyComplex_MethodMult();
	test_ComplexNumber_ComplexPlusComplex_MethodAdd();

	test_ComplexClass_ComplexMinusReal_MethodSub();
	test_ComplexClass_ComplexMultiplyReal_MethodMult();
	test_ComplexNumber_ComplexPlusReal_MethodAdd();

	test_ComplexClass_FindingAbsoluteOfComplex();
	test_ComplexClass_FindingArgumentOfComplex();
}

