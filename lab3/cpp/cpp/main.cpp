#include <iostream>;
#include "header.h";
#include <vector>
using namespace std;

void main() {
	int n;
	cout << "Enter number of people: ";
	cin >> n;
	vector<Persone> array;
	array = inputInformation(array, n);
	printHappyDayPersone(array, n);

	system("pause");
}