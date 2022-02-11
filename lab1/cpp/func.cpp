#include "Header.h"

// Ввод многострочного текста с консоли 
vector<string> readConsoleText() {
	vector <string> text;
	string line;
	int code = 4;
	// Запуск итерационного цикла с проверкой условия нажатия сочетания клавиш Ctrl + D
	while (int(line[0]) != code) {
		getline(cin, line);
		text.push_back(line);
	} 
	// Удаление последнего рядка, который содержит "^D"
	text.pop_back();
	return text;
}

// Чтение текста с файла input.txt
vector<string> readFileText() {
	vector<string> text;
	string line;
	// Открытие файла input.txt в режиме чтения
	ifstream file("input.txt");
	// Чтение содержимого файла
	while (getline(file, line))
	{
		text.push_back(line);
	}
	// Закрытие файла
	file.close();
	return text;
}

// Вывод содержимого файла
void printFileText(string src) {
	// Открытие файла src в режиме чтения
	ifstream file(src);
	string line;
	// Вывод содержимого файла
	while (getline(file, line))
	{
		cout << line << endl;
	}
	// Закрытие файла
	file.close();
}

// Запись введенного текста в файл input.txt
void inputText(vector<string> text) {
	// Открытие файла input.txt для записи
	ofstream file("input.txt");
	// Запись введенного текста в файл
	for (int i = 0; i < text.size(); i++)
	{
		file << text[i] << endl;
	}
	// Закрытие файла
	file.close();
}

// Запись измененного текста в файл output.txt
void inputText(string text) {
	// Открытие файла output.txt для записи
	ofstream file("output.txt");
	// Запись измененного текста в файл
	file << text;
	// Закрытие файла
	file.close();
}

// Изменение текста согласно заданию
string changeFileText(vector<string> text) {
	string newText = "";
	for (int i = 0; i < text.size(); i++)
	{
		char max;
		int id;
		string numbers;
		// Создание строки, которая содержит исключительно цифры соответсвующей строки
		for (int j = 0; j < text[i].length(); j++)
		{
			if (isdigit(text[i][j]))
			{
				numbers += text[i][j];
			}
		}
		if (numbers.length()>0)
		{
			// Нахождение максимальной цифры в строке и её индекса
			max = numbers[0];
			id = 0;
			for (int j = 1; j < numbers.length(); j++)
			{
				if (int(max) <= int(numbers[j])) {
					max = numbers[j];
					id = j;
				}
			}
			// Создание нового текста, который начинается с самой большой цифры и потом через запятую содержит остальные цифры
			newText += max;
			for (int j = 0; j < numbers.length(); j++)
			{
				if (j != id)
				{
					newText += ", ";
					newText += char(numbers[j]);
				}
			}
			newText += '\n';
		}
	}
	return newText;
}