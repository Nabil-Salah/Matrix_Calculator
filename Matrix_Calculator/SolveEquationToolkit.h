#pragma once
#include "Matrix.h"
template <class dataType = double>
class SolveEquationToolkit
{
public:
	void scalling(Matrix<dataType>& matrix,int row, int column) {
		int numOfColumns = matrix.getNumOfRows();
		if (matrix.getEntry(row, column) == 0)return;
		double scaller = 1 / matrix.getEntry(row, column);
		for (size_t i = 0; i < numOfColumns; i++)
		{
			matrix.getEntryreferance(row,i) *= scaller;
		}
	}
	void interChange(Matrix<dataType>& matrix, int row, int column) {
		int numOfRows = matrix.getNumOfRows();
		int position = -1;
		for (size_t i = row; i < numOfRows; i++)
		{
			if (matrix.getEntry(i, column) != 0) {
				position = i;
				break;
			}
		}
		if (position == -1)return;
		int numOfColumns = matrix.getNumOfColumns();
		for (size_t i = 0; i < numOfColumns; i++)
		{
			swap(matrix.getEntryreferance(row, i), matrix.getEntryreferance(position, i));
		}

	}
	void replacement(Matrix<dataType>& matrix,int row, int column) {
		int numOfRows = matrix.getNumOfRows();
		int numOfColumns = matrix.getNumOfColumns();
		for (int i = row+1; i < numOfRows; i++)
		{
			if (matrix.getEntry(i, column) != 0) {
				if (matrix.getEntry(row, column) == 0)continue;
				double scaller = -1*(matrix.getEntry(i, column) / matrix.getEntry(row, column));
				for (size_t j = 0; j < numOfColumns; j++)
				{
					matrix.getEntryreferance(i, j) = matrix.getEntry(i, j) + (scaller * matrix.getEntry(row, j));
				}
			}
		}
	}
	vector<vector<dataType>> virtual echlonForm(Matrix<dataType>& matrix) = 0;
	/*string checkSolve(Matrix<dataType> reducedmatrix) {
		int numOfRows = matrix.getNumOfRows();
		int numOfColumns = matrix.getNumOfColumns();
		int nonzerocnt = 0;
		for (int i = 0; i < numOfColumns; ++i)
		{
			if (augmantedMatrix[numOfRows - 1][i] != 0)
			{
				++nonzerocnt;
			}
		}
		if (nonzerocnt == 0)
		{
			return "INFINTYSOLUTION";
		}
		else if ((nonzerocnt == 1) && (augmantedMatrix[num_rows - 1][num_columns - 1] != 0))
		{
			return "NOSOLUTION";
		}
		else if ((nonzerocnt == 1) && (augmantedMatrix[num_rows - 1][num_columns - 1] == 0))
		{
			return "ONESOLUTION";
		}
		else if ((nonzerocnt == 2) && (augmantedMatrix[num_rows - 1][num_columns - 1] != 0))
		{
			return "ONESOLUTION";
		}
		else
		{
			return "NOSOLUTION";
		}
	}*/

};

