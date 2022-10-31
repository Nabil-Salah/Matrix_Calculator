#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;
template <class dataType=double>
class Matrix
{
private:
	vector<vector<dataType>>matrix;
	int rows;
	int columns;
public:
	Matrix(vector<vector<dataType>>matrix) {
		this->matrix = matrix;
		this->rows = matrix.size();
		this->columns = matrix[0].size();
	}
	Matrix(int rows = 0,int columns = 0) {
		this->matrix = vector<vector<dataType>>(rows, vector<dataType>(columns,0));
		this->rows = rows;
		this->columns = columns;
	}
	Matrix() {
		this->rows = 0;
		this->columns = 0;
	}
	int getNumOfRows() {
		return rows;
	}
	int getNumOfColumns() {
		return columns;
	}
	vector<vector<dataType>> transpose() {
		
	}
	dataType getEntry(int i, int j) {
		return matrix[i][j];
	}
	int rank() {

	}
	void scalling(int number) {

	}
	vector<vector<dataType>> raiseToThePowerOfX(int x) {

	}
	vector<vector<dataType>> diagonalMatrix(int x) {

	}
	vector<vector<dataType>> triangularMatrix(int x) {

	}
	bool isSymatric() {

	}
	bool isInvertable() {

	}
	Matrix operator+(Matrix rightOp) {
		if (this->getNumOfRows() != rightOp.getNumOfRows()
			|| this->getNumOfColumns() != rightOp.getNumOfColumns()) {
			throw invalid_argument("Sizes are not compatible");
		}
		int rowSize = this->getNumOfRows();
		int columnSize = this->getNumOfColumns();
		vector<vector<dataType>>resultMatrixVector(rowSize,vector<dataType>(columnSize,0));
		for (size_t i = 0; i < rowSize; i++)
		{
			for (size_t j = 0; j < columnSize; j++)
			{
				resultMatrixVector[i][j] = this->getEntry(i, j) + rightOp.getEntry(i, j);
			}
		}
		Matrix result{ resultMatrixVector};
		return result;
	}
	Matrix operator-(Matrix rightOp) {
		if (this->getNumOfRows() != rightOp.getNumOfRows()
			|| this->getNumOfColumns() != rightOp.getNumOfColumns()) {
			throw invalid_argument("Sizes are not compatible");
		}
		int rowSize = this->getNumOfRows();
		int columnSize = this->getNumOfColumns();
		vector<vector<dataType>>resultMatrixVector(rowSize, vector<dataType>(columnSize, 0));
		for (size_t i = 0; i < rowSize; i++)
		{
			for (size_t j = 0; j < columnSize; j++)
			{
				resultMatrixVector[i][j] = this->getEntry(i, j) - rightOp.getEntry(i, j);
			}
		}
		Matrix result{ resultMatrixVector };
		return result;
	}
	Matrix operator*(Matrix rightOp) {
		if (this->getNumOfColumns() != rightOp.getNumOfRows()) {
			throw invalid_argument("Sizes are not compatible");
		}
		int rowSize = this->getNumOfRows();
		int columnSize = rightOp.getNumOfColumns();
		vector<vector<dataType>>resultMatrixVector(rowSize, vector<dataType>(columnSize, 0));
		for (size_t i = 0; i < rowSize; i++)
		{
			for (size_t j = 0; j < columnSize; j++)
			{
				dataType entry = 0;
				for (size_t k = 0; k < this->getNumOfColumns(); k++)
				{
					entry += this->getEntry(i, k) * rightOp.getEntry(k, j);
				}
				resultMatrixVector[i][j] = entry;
			}
		}
		Matrix result{ resultMatrixVector };
		return result;
	}
	void print() {
		for (size_t i = 0; i < this->getNumOfRows(); i++)
		{
			for (size_t j = 0; j < this->getNumOfColumns(); j++)
			{
				cout << this->getEntry(i, j) << " ";
			}
			cout << endl;
		}
	}
};

