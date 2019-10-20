#pragma once

#include <vector>


using namespace std;

class tryToMatrix
{
private: 
	int _col = 1;
	int _row = 1;

	vector<vector<double>> matrix(1, vector<double>(1, 0));

public:
	tryToMatrix() {
		this->_col = 1;
		this->_col = 1;
	}
	tryToMatrix(const int& row, const int& col) {
		int diffCol = col - this->_col;
		int diffRow = row - this->_row;
		for(int j = 0; j < this->_row; j++)
			for (int i = 0; i < diffCol; i++) {
				this->matrix[j].push_back(0);
			}
		this->_col = col;
		for (int j = 0; j < diffRow; j++) {
			matrix.push_back(vector<double>(this->_col, 0));
		}
		this->_row = row;
	}
	tryToMatrix(const int& row, const int& col, const double& num) {
		
	}

};

