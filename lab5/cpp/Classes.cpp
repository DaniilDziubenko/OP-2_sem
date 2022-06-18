#include "Classes.h"

TMatrix::TMatrix(int n, int m) {
	this->n = n;
	this->m = m;
	matr = new double* [n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new double[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matr[i][j] = rand() % 101 - 50;
		}
	}
}

void TMatrix::printMatrix() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(6) << matr[i][j];
		}
		cout << endl;
	}
}

double TMatrix::getSumOfElements() {
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum += matr[i][j];
		}
	}
	return sum;
}

SquareMatrix2Order::~SquareMatrix2Order() {
	delete[] matr;
};

double SquareMatrix2Order::getDeterminant() {
	return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
}

SquareMatrix3Order::~SquareMatrix3Order() {
	delete[] matr;
};

double SquareMatrix3Order::getDeterminant() {
	return matr[0][0] * matr[1][1] * matr[2][2] + matr[0][1] * matr[1][2] * matr[2][0] + matr[0][2] * matr[1][0] * matr[2][1] - matr[0][2] * matr[1][1] * matr[2][0] - matr[0][1] * matr[1][0] * matr[2][2] - matr[0][0] * matr[1][2] * matr[2][1];
}