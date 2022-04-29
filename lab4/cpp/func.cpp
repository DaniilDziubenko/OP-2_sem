#include "header.h"

Polynomial::Polynomial(double first, double second, double third, double fourth) {
	first_coefficient = first;
	second_coefficient = second;
	third_coefficient = third;
	fourth_coefficient = fourth;
}

Polynomial::Polynomial(){
	first_coefficient = 1;
	second_coefficient = 2;
	third_coefficient = 3;
	fourth_coefficient = 4;
}

Polynomial Polynomial::operator+(Polynomial p) {
	Polynomial temp;
	temp.setFirstCoefficient(first_coefficient + p.getFirstCoefficient());
	temp.setSecondCoefficient(second_coefficient + p.getSecondCoefficient());
	temp.setThirdCoefficient(third_coefficient + p.getThirdCoefficient());
	temp.setFourthCoefficient(fourth_coefficient + p.getFourthCoefficient());
	return temp;
}

vector<double> Polynomial::operator*(Polynomial p) {
	vector<double> temp;
	double first, second, third, fourth, fifth, sixth, seventh;
	first = first_coefficient * p.getFirstCoefficient();
	second = first_coefficient * p.getSecondCoefficient() + second_coefficient * p.getFirstCoefficient();
	third = first_coefficient * p.getThirdCoefficient() + second_coefficient * p.getSecondCoefficient() + third_coefficient * p.getFirstCoefficient();
	fourth = first_coefficient * p.getFourthCoefficient() + second_coefficient * p.getThirdCoefficient() + third_coefficient * p.getSecondCoefficient() + fourth_coefficient * p.getFirstCoefficient();
	fifth = second_coefficient * p.getFourthCoefficient() + third_coefficient * p.getThirdCoefficient() + fourth_coefficient * p.getSecondCoefficient();
	sixth = third_coefficient * p.getFourthCoefficient() + fourth_coefficient * p.getThirdCoefficient();
	seventh = fourth_coefficient * p.getFourthCoefficient();
	temp.insert(temp.end(), {first, second, third, fourth, fifth, sixth, seventh});
	return temp;
}

void Polynomial::setFirstCoefficient(double coefficient) {
	first_coefficient = coefficient;
}

void Polynomial::setSecondCoefficient(double coefficient) {
	second_coefficient = coefficient;
}

void Polynomial::setThirdCoefficient(double coefficient) {
	third_coefficient = coefficient;
}

void Polynomial::setFourthCoefficient(double coefficient) {
	fourth_coefficient = coefficient;
}

double Polynomial::getFirstCoefficient(){
	return first_coefficient;
}

double Polynomial::getSecondCoefficient() {
	return second_coefficient;
}

double Polynomial::getThirdCoefficient() {
	return third_coefficient;
}

double Polynomial::getFourthCoefficient() {
	return fourth_coefficient;
}

double Polynomial::calcPolynomialValueAtGivenPoint(double point) {
	return first_coefficient * pow(point, 3) + second_coefficient * pow(point, 2) + third_coefficient * point + fourth_coefficient;
}

double calcPolynomialValueAtGivenPoint(double point, vector<double> p) {
	return p[0] * pow(point, 6) + p[1] * pow(point, 5) + p[2] * pow(point, 4) + p[3] * pow(point, 3) + p[4] * pow(point, 2) + p[5] * point + p[6];
}

Polynomial createPolynomial() {
	double first, second, third, fourth;
	cout << "Enter first coefficient: ";
	cin >> first;
	cout << "Enter second coefficient: ";
	cin >> second;
	cout << "Enter third coefficient: ";
	cin >> third;
	cout << "Enter fourth coefficient: ";
	cin >> fourth;
	Polynomial p = Polynomial(first, second, third, fourth);
	return p;
}

void printPolynomial(Polynomial p) {
	cout << "f(x) = (" << p.getFirstCoefficient() << ")x^3 + (" << p.getSecondCoefficient() << ")x^2 + (" << p.getThirdCoefficient() << ")x + (" << p.getFourthCoefficient() << ")\n";
}

void printPolynomial(vector<double> p) {
	cout << "f(x) = (" << p[0] << ")x^6 + (" << p[1] << ")x^5 + (" << p[2] << ")x^4 + (" << p[3] << ")x^3 + (" << p[4] << ")x^2 + (" << p[5] << ")x + (" << p[6] << ")\n";
}