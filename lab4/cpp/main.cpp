#include <iostream>
#include <vector>
#include "header.h"
using namespace std;

void main() {
	Polynomial P1, P2, P3, P4;
	vector<double> P5;
	double point;
	cout << "Polynomial 1 was created by default constructor!\n";
	cout << "\nPolynomial 2:\n";
	P2 = createPolynomial();
	cout << "\nPolynomial 3 was created by copy constructor!\n";
	P3 = Polynomial(P2);

	P4 = P1 + P2;
	P5 = P2 * P3;

	cout << "\nEnter a point: ";
	cin >> point;

	cout << "\nPolynomial 1:\n";
	printPolynomial(P1);

	cout << "\nPolynomial 2:\n";
	printPolynomial(P2);

	cout << "\nPolynomial 3:\n";
	printPolynomial(P3);

	cout << "\nPolynomial 4:\n";
	printPolynomial(P4);
	cout << "Its value at given point: " << P4.calcPolynomialValueAtGivenPoint(point) << endl;

	cout << "\nPolynomial 5:\n";
	printPolynomial(P5);
	cout << "Its value at given point: " << calcPolynomialValueAtGivenPoint(point, P5) << endl;

	system("pause");
}