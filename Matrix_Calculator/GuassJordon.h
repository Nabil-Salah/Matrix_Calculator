#pragma once
#include "SolveEquationToolkit.h"
template <class datatype = double>
class GuassJordon :public SolveEquationToolkit<datatype>
{
public:
	GuassJordon(Matrix<datatype>matrix) :SolveEquationToolkit(matrix) {

	}
	void guassJordonExtension(int row, int column) {

	}
	vector<vector<dataType>> echlonForm(int row, int column) override {

	}
};

