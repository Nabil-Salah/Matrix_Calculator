#pragma once
#include "Matrix.h"
template <class dataType = double>
class SolveEquationToolkit
{
protected:
	Matrix<dataType> matrix;
public:
	SolveEquationToolkit(Matrix<dataType> matrix) {
		this->matrix = matrix;
	}
	vector<vector<dataType>> scalling(int number, int row) {
		int numOfColumns = this->getNumOfColumns();
		for (size_t i = 0; i < numOfColumns; i++)
		{
			matrix[row][i] *= number;
		}
	}
	vector<vector<dataType>> interChange(int row, int column) {

	}
	vector<vector<dataType>> replacement(int row, int column) {

	}
	vector<vector<dataType>> echlonForm(int row, int column) virtual = 0;
	int checkSolve() {

	}

};

