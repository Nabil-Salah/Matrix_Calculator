#pragma once
#include "SolveEquationToolkit.h";
template <class datatype = double>
class GuassianElimination : public SolveEquationToolkit<datatype>
{
public:
	GuassianElimination(Matrix<datatype>matrix) :SolveEquationToolkit(matrix) {

	}
	vector<vector<dataType>> echlonForm(int row, int column) override {

	}
};

