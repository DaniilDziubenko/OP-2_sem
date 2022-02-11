#include <iostream>
#include "Header.h"
using namespace std;

int main() {
	vector<string> consoleText;
	vector<string> mainText;
	string changedText;

	cout << "Enter your text:\n";
	
	// ���� �������������� ������ � ������� 
	consoleText = readConsoleText();

	// ������ ���������� ������ � ���� input.txt
	inputText(consoleText);

	// ������ ������ � ����� input.txt
	mainText = readFileText();

	// ��������� ������ �������� �������
	changedText = changeFileText(mainText);
	
	// ������ ����������� ������ � ���� output.txt
	inputText(changedText);

	// ����� ����������� ����� input.txt
	cout << "\nYour text:\n";
	printFileText("input.txt");

	// ����� ����������� ����� output.txt
	cout << "\nChanged text:\n";
	printFileText("output.txt");

	system("pause");
}