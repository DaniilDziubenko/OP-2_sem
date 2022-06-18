#include "Classes.h"

int main() {
	srand(time(NULL));

	double a, b, sum, s;
	SquareMatrix2Order matrixB;
	SquareMatrix3Order matrixA;

	cout << "Matrix A:\n";
	matrixA.printMatrix();

	cout << "\nMatrix B:\n";
	matrixB.printMatrix();

	a = matrixA.getDeterminant();
	b = matrixB.getDeterminant();
	sum = matrixA.getSumOfElements();
	s = a + b + sum;

	cout << "\nDet A: " << a << endl;
	cout << "Det B: " << b << endl;
	cout << "Sum of elements Matrix A: " << sum << endl;
	cout << "\nS = " << s << endl;

	system("pause");
	return 0;
}