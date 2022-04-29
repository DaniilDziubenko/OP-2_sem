#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
	private:
		double first_coefficient, second_coefficient, third_coefficient, fourth_coefficient;
	public:
		Polynomial(double first, double second, double third, double fourth);
		Polynomial();
		Polynomial operator+(const Polynomial p);
		vector<double> operator*(const Polynomial p);
		void setFirstCoefficient(double coefficient);
		void setSecondCoefficient(double coefficient);
		void setThirdCoefficient(double coefficient);
		void setFourthCoefficient(double coefficient);
		double getFirstCoefficient();
		double getSecondCoefficient();
		double getThirdCoefficient();
		double getFourthCoefficient();
		double calcPolynomialValueAtGivenPoint(double point);
};

Polynomial createPolynomial();
void printPolynomial(Polynomial p);
void printPolynomial(vector<double> p);
double calcPolynomialValueAtGivenPoint(double point, vector<double> p);