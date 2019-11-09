// training.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "../tryToMatrix.h"
#include "testOfTryToMatrix/test_tryToMatrix.h"
#include <vector>
#include <ctime>
using namespace std;

int main()
{
	const int n = 5;

	test_ClassMyMatrix_all();
	vector<vector<double>> matrix;
	vector<vector<double>> matrix2(10, vector<double>(5, 1));
	cout << matrix.size() << endl;
	for(int i = 0; i < n; i++)
		matrix.push_back(vector<double>(5, 2));
	for (int i = 0; i < n; i++)
		matrix.push_back(vector<double>(5, 3));
	
}

