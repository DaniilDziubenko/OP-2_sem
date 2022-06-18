#include "header.h";

Persone::Persone(string name, string surname, string middleName, string birthDate) {
	this->name = name;
	this->surname = surname;
	this->middleName = middleName;
	this->birthDate = birthDate;
}

Persone::Persone() {}

void Persone::setName(string name) {
	this->name = name;
}

void Persone::setSurname(string surname) {
	this->surname = surname;
}

void Persone::setMiddleName(string middleName) {
	this->middleName = middleName;
}

void Persone::setBirthDate(string birthDate) {
	this->birthDate = birthDate;
}

string Persone::getName() {
	return name;
}

string Persone::getSurname() {
	return surname;
}

string Persone::getMiddleName() {
	return middleName;
}

string Persone::getBirthDate() {
	return birthDate;
}

vector<Persone> inputInformation(vector<Persone> array, int n) {
	string name, surname, middleName, birthDate;
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter name: ";
		cin >> name;
		name = checkInformation(name);

		cout << "Enter surname: ";
		cin >> surname;
		surname = checkInformation(surname);

		cout << "Enter middle name: ";
		cin >> middleName;
		middleName = checkInformation(middleName);

		cout << "Enter birth date: ";
		cin >> birthDate;
		birthDate = checkDate(birthDate);

		array.push_back(Persone(name, surname, middleName, birthDate));
	}
	return array;
}

string checkInformation(string inf) {
	string result = regex_replace(inf, regex("[a-zA-Z]"), "");
	bool flag = inf.length() > 2 && inf.length() < 20 && result.length() == 0;
	while (!flag)
	{
		cout << "Enter information again: ";
		cin >> inf;
		result = regex_replace(inf, regex("[a-zA-Z]"), "");
		flag = inf.length() > 2 && inf.length() < 20 && result.length() == 0;
	}
	return inf;
}

string checkDate(string date) {
	string result = regex_replace(date, regex("[0-3][0-9]-[0-1][0-9]-[0-9][0-9][0-9][0-9]"), "");
	bool flag = date.length() == 10 && result.length() == 0;
	while (!flag)
	{
		cout << "Enter birth date again: ";
		cin >> date;
		result = regex_replace(date, regex("[0-3][0-9]-[0-1][0-9]-[0-9][0-9][0-9][0-9]"), "");
		flag = date.length() == 10 && result.length() == 0;
	}
	return date;
}

void printHappyDayPersone(vector<Persone> array, int n) {
	string date;
	int day, month, year, counter = 0;
	cout << "\nPeople, who was born in a happy day:\n\n";
	for (int i = 0; i < n; i++)
	{
		date = array[i].getBirthDate();
		day = (date[0] - '0') + (date[1] - '0');
		month = (date[3] - '0') + (date[4] - '0');
		year = (date[6] - '0') + (date[7] - '0') + (date[8] - '0') + (date[9] - '0');
		if (day % 7 == month % 7 and month % 7 == year % 7)
		{
			cout << array[i].getName() + " " + array[i].getSurname() + " " + array[i].getMiddleName() + " was born " + array[i].getBirthDate() << endl;
			counter++;
		}
	}
	if (counter == 0)
	{
		cout << "\nNobody was born in a happy day!\n\n";
	}
	else {
		cout << endl;
	}
}