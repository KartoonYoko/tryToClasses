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
	cout << matrix.size() << endl;
	for(int i = 0; i < n; i++)
		matrix.push_back(vector<double>(4, 0));
	for (int i = 0; i < n; i++)
		matrix.push_back(vector<double>(4, 0));
	cout << matrix.size() << "  " << matrix[7].size() << endl;


	int fromNum = 2;
	int lastNum = 12;
	srand(time(NULL));
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[0].size(); j++) {
			matrix[i][j] = 0.1 * (fromNum * 10 + rand() % ((lastNum - fromNum) * 10 + 1));
			cout << matrix[i][j] << "   ";
		}

}

