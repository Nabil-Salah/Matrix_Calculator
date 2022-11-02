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
	Matrix(Matrix &otherMatrix) {
		matrix = otherMatrix.matrix;
		rows = otherMatrix.getNumOfRows();
		columns = otherMatrix.getNumOfColumns();
	}
	void operator=(Matrix& otherMatrix) {
		this(otherMatrix);
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
	void scalling(int number, int row) {
		int numOfColumns = this->getNumOfColumns();
		for (size_t i = 0; i < numOfColumns; i++)
		{
			matrix[row][i] *= number;
		}
	}
	vector<vector<dataType>> raiseToThePowerOfX(int x) {
		if (x == 1) {
			return matrix;
		}
		Matrix<dataType> result(*this);
		x -= 1;
		while (x--)
		{
			result *= (*this);
		}
		return result.matrix;
	}
	vector<vector<dataType>> diagonalMatrix(int x) {

	}
	vector<vector<dataType>> triangularMatrix(int x) {

	}
	bool isSymatric() {

	}
	bool isInvertable() {

	}
	vector<vector<double>> getInverse() {
		if (!this->isInvertable())
			throw invalid_argument("Matrix cannot be inverted");

	}
	Matrix<dataType> operator+(Matrix<dataType>& rightOp) {
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
		Matrix<dataType> result{ resultMatrixVector};
		return result;
	}
	Matrix<dataType> operator-(Matrix<dataType>& rightOp) {
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
		Matrix<dataType> result{ resultMatrixVector };
		return result;
	}
	Matrix<dataType> operator*(Matrix<dataType>& rightOp) {
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
		Matrix<dataType> result{ resultMatrixVector };
		return result;
	}
	void operator*=(Matrix<dataType>& rightOp) {
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
		matrix = resultMatrixVector;
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

