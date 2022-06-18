#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class TMatrix {
public:
	TMatrix(int n, int m);
	virtual double getDeterminant() = 0;
	double getSumOfElements();
	void printMatrix();

protected:
	int n, m;
	double** matr;
};

class SquareMatrix2Order : public TMatrix {
public:
	SquareMatrix2Order():TMatrix(2, 2){};
	~SquareMatrix2Order();
	double getDeterminant() override;
};

class SquareMatrix3Order : public TMatrix {
public:
	SquareMatrix3Order():TMatrix(3, 3){};
	~SquareMatrix3Order();
	double getDeterminant() override;
};