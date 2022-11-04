#pragma once
#include "Matrix.h"
template<class datatype = double>
class Determinant
{
private:
	Matrix<datatype> matrix;
public:
	Determinant(Matrix<datatype> matrix) {
		this->matrix = matrix;
	}
	int expandAlongColumnx(int x) {

	}
	int expandAlongRowx(int x) {

	}
	int getDeterminant(int n) {

	}
	void getCoFactor(vector<vector<datatype>>& cofactorMatrix, int row, int column,int n) {

	}
	void getAdjoint(vector<vector<datatype>>& adjoint) {

	}
	vector<vector<datatype>> inverseUsingDeterminant() {

	}
};

