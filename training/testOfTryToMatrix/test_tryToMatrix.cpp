

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


	void test_ClassMyMatrix_all() {
		test_ClassMyMatrix_constructor();
		test_ClassMyMatrix_fill();
		test_ClassMyMatrix_expand();
	}