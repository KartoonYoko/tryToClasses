

#include <iostream>
#include <cassert>
#include "test_tryToMatrix.h"


using namespace std;





	void test_ClassMyMatrix_constructor() {
		{
			MyMatrix a;
			assert((a(0,0) == 0) && "MyMatrix a;");
		}

		{
			MyMatrix a(2, 2);
			assert((a(1, 1) == 0) && "MyMatrix a(1, 1);");
		}

		{
			MyMatrix a(2, 2, 3);
			assert((a(1, 1) == 3) && "MyMatrix a(1, 1, 3);");
		}

		{
			try
			{
				MyMatrix a(-3, 4);
				assert(0 && "MyMatrix a(-3, 4); // it doesnt throw exeption");
			}
			catch (MatrixException e) {;}
		}

		{
			try
			{
				MyMatrix a(3, -4);
				assert(0 && "MyMatrix a(3, -4); // it doesnt throw exeption");
			}
			catch (MatrixException e) {;}
		}

		cout << "test_MyMatrix_constructor OK" << endl;
	}
	void test_ClassMyMatrix_fill() {
		
		{
			MyMatrix a;
			a.fillRand(2, 12);
			assert( (a(0, 0) <= 12) && (a(0, 0) >= 2) && a(0, 0) && "a.fill();" );
		}

		cout << "test_ClassMatrix_fill OK" << endl;
	}
	void test_ClassMyMatrix_expand() {
		{
			MyMatrix a(2, 2, 6);
			a.expand(4, 4, 3);
			assert(a(3, 3) == 3 && "a.expand(4, 4, 3);");
		}



		{
			try
			{
				MyMatrix a(2, 2, 6);
				a.expand(2, 2, 3);
				assert(0 && "dont catch exeption");
			}
			catch (MatrixException e) {;}
		}


		cout << "test_ClassMyMatrix_expand OK" << endl;
	}
	void test_ClassMyMatrix_MatrixMultMatrix() {
		{
			try
			{
				MyMatrix a(3, 2), b(3, 2);
				MyMatrix result = a * b;
				assert(0 && "dont catch exeption");
			}
			catch (MatrixException e) { ; }
		}


		{
			MyMatrix a(3, 2, 2), b(2, 2, 4);
			MyMatrix result = a * b;
			assert((result.getRow() == 3) && (result.getCol() == 2) &&  (result.getItem(0, 0) == 16) &&"");
		}


		cout << "test_ClassMyMatrix_MatrixMultMatrix OK" << endl;
	}
	void test_ClassMatrix_transpose() {
		
		{
			MyMatrix a(2, 2, 4);
			a(0, 0) = 2;
			a(0, 1) = 3;
			a(1, 0) = 5;
			a.outputConsole();
			cout << endl << "_____________" << endl ;
			a.transpose();
			a.outputConsole();
		}



		cout << "test_ClassMatrix_transpose OK" << endl;
	}


	void test_ClassMyMatrix_all() {
		test_ClassMyMatrix_constructor();
		test_ClassMyMatrix_fill();
		test_ClassMyMatrix_expand();
		test_ClassMyMatrix_MatrixMultMatrix();
		test_ClassMatrix_transpose();
	}