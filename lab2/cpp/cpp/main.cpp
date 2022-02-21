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

	// Ввод списка клиентов с клаватуры
	consoleText = readConsoleText(listOfTimes);

	// Запись текста в бинарный файл input.dot
	inputFileText(consoleText, "input.dot");

	// Чтение текста с бинарного файла
	fileText = readFileText();

	// Создание нового текста, который содержит нужные элементы
	changedFileText = changeText(fileText, listOfTimes);

	// Запись нового текста в бинарный файл output.dot
	inputFileText(changedFileText, "output.dot");

	// Вывод содержимого файла input.dot
	cout << "\nInput file text:\n";
	printFileText("input.dot");

	// Вывод содержимого файла output.dot
	cout << "\nOutput file text:\n";
	printFileText("output.dot");

	system("pause");
}