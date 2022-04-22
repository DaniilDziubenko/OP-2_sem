#include <iostream>;
#include "header.h";
#include <vector>
using namespace std;

void main() {
	int n;
	string name, surname, middleName, birthDate;
	cout << "Enter number of people: ";
	cin >> n;
	vector<Persone> array;
	array = inputInformation(array, n, name, surname, middleName, birthDate);
	printHappyDayPersone(array, n);

	system("pause");
}