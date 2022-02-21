#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
#include <vector>
using namespace std;

int main() {
	vector<string> consoleText;
	vector<string> fileText;
	vector<string> changedFileText;
	vector<string> listOfTimes;

	// ���� ������ �������� � ���������
	consoleText = readConsoleText(listOfTimes);

	// ������ ������ � �������� ���� input.dot
	inputFileText(consoleText, "input.dot");

	// ������ ������ � ��������� �����
	fileText = readFileText();

	// �������� ������ ������, ������� �������� ������ ��������
	changedFileText = changeText(fileText, listOfTimes);

	// ������ ������ ������ � �������� ���� output.dot
	inputFileText(changedFileText, "output.dot");

	// ����� ����������� ����� input.dot
	cout << "\nInput file text:\n";
	printFileText("input.dot");

	// ����� ����������� ����� output.dot
	cout << "\nOutput file text:\n";
	printFileText("output.dot");

	system("pause");
}