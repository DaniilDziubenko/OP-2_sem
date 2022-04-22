#pragma once
#include <string>
#include <iostream>
#include <regex>
using namespace std;

class Persone {
	public:
		Persone(string name, string surname, string middleName, string birthDate);
		Persone();
		void setName(string name);
		void setSurname(string surname);
		void setMiddleName(string middleName);
		void setBirthDate(string birthDate);
		string getName();
		string getSurname();
		string getMiddleName();
		string getBirthDate();

	private:
		string name, surname, middleName, birthDate;
};

vector<Persone> inputInformation(vector<Persone> array, int n, string name, string surname, string middleName, string birthDate);
string checkInformation(string inf);
string checkDate(string date);
void printHappyDayPersone(vector<Persone> array, int n);