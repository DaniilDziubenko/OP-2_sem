#include <iostream>
#include "Header.h"
using namespace std;

int main() {
	vector<string> consoleText;
	vector<string> mainText;
	string changedText;

	cout << "Enter your text:\n";
	
	// Ввод многострочного текста с консоли 
	consoleText = readConsoleText();

	// Запись введенного текста в файл input.txt
	inputText(consoleText);

	// Чтение текста с файла input.txt
	mainText = readFileText();

	// Изменение текста согласно заданию
	changedText = changeFileText(mainText);
	
	// Запись измененного текста в файл output.txt
	inputText(changedText);

	// Вывод содержимого файла input.txt
	cout << "\nYour text:\n";
	printFileText("input.txt");

	// Вывод содержимого файла output.txt
	cout << "\nChanged text:\n";
	printFileText("output.txt");

	system("pause");
}