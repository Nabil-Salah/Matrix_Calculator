
#include "SolveEquationToolkit.h";
template <class dataType = double>
class GuassianElimination : public SolveEquationToolkit<dataType>
{
public:
    vector<vector<dataType>> echlonForm(Matrix<dataType>& matrix) {
        Matrix<dataType> augmantedMatrix{ matrix };
        int numOfRows = matrix.getNumOfRows();
        int numOfColumns = matrix.getNumOfColumns();
        for (int i = 0; i < numOfRows; i++)
        {
            this->interChange(augmantedMatrix,i, i);
            this->scalling(augmantedMatrix,i, i);
            this->replacement(augmantedMatrix,i, i);
        }
        vector<vector<dataType>> ret(numOfRows,vector<dataType>(numOfColumns));
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

