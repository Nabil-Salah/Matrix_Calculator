#pragma once
#include "SolveEquationToolkit.h"
template <class dataType = double>
class GuassJordon :public SolveEquationToolkit<dataType>
{
public:
	void guassJordonExtension(Matrix<dataType>& matrix,int row, int column) {
        int numOfRows = matrix.getNumOfRows();
        int numOfColumns = matrix.getNumOfColumns();
        for (int i = row - 1; i >=0; i--)
        {
            if (matrix.getEntry(i, column) != 0) {
                if (matrix.getEntry(row, column) == 0)continue;
                double scaller = -1 * (matrix.getEntry(i, column) / matrix.getEntry(row, column));
                for (size_t j = 0; j < numOfColumns; j++)
                {
                    matrix.getEntryreferance(i, j) = matrix.getEntry(i, j) + (scaller * matrix.getEntry(row, j));
                }
            }
        }
	}
    vector<vector<dataType>> echlonForm(Matrix<dataType>& matrix) {
        Matrix<dataType> augmantedMatrix{ matrix };
        int numOfRows = matrix.getNumOfRows();
        int numOfColumns = matrix.getNumOfColumns();
        for (int i = 0; i < numOfRows; i++)
        {
            this->interChange(augmantedMatrix, i, i);
            this->scalling(augmantedMatrix, i, i);
            this->replacement(augmantedMatrix, i, i);
            guassJordonExtension(matrix, i, i);
        }
        vector<vector<dataType>> ret(numOfRows, vector<dataType>(numOfColumns));
        for (size_t i = 0; i < numOfRows; i++)
        {
            for (size_t j = 0; j < numOfColumns; j++)
            {
                ret[i][j] = augmantedMatrix.getEntry(i, j);
            }

        }
        return ret;
    }
};

