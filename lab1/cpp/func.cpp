#include "Header.h"

// ���� �������������� ������ � ������� 
vector<string> readConsoleText() {
	vector <string> text;
	string line;
	int code = 4;
	// ������ ������������� ����� � ��������� ������� ������� ��������� ������ Ctrl + D
	while (int(line[0]) != code) {
		getline(cin, line);
		text.push_back(line);
	} 
	// �������� ���������� �����, ������� �������� "^D"
	text.pop_back();
	return text;
}

// ������ ������ � ����� input.txt
vector<string> readFileText() {
	vector<string> text;
	string line;
	// �������� ����� input.txt � ������ ������
	ifstream file("input.txt");
	// ������ ����������� �����
	while (getline(file, line))
	{
		text.push_back(line);
	}
	// �������� �����
	file.close();
	return text;
}

// ����� ����������� �����
void printFileText(string src) {
	// �������� ����� src � ������ ������
	ifstream file(src);
	string line;
	// ����� ����������� �����
	while (getline(file, line))
	{
		cout << line << endl;
	}
	// �������� �����
	file.close();
}

// ������ ���������� ������ � ���� input.txt
void inputText(vector<string> text) {
	// �������� ����� input.txt ��� ������
	ofstream file("input.txt");
	// ������ ���������� ������ � ����
	for (int i = 0; i < text.size(); i++)
	{
		file << text[i] << endl;
	}
	// �������� �����
	file.close();
}

// ������ ����������� ������ � ���� output.txt
void inputText(string text) {
	// �������� ����� output.txt ��� ������
	ofstream file("output.txt");
	// ������ ����������� ������ � ����
	file << text;
	// �������� �����
	file.close();
}

// ��������� ������ �������� �������
string changeFileText(vector<string> text) {
	string newText = "";
	for (int i = 0; i < text.size(); i++)
	{
		char max;
		int id;
		string numbers;
		// �������� ������, ������� �������� ������������� ����� �������������� ������
		for (int j = 0; j < text[i].length(); j++)
		{
			if (isdigit(text[i][j]))
			{
				numbers += text[i][j];
			}
		}
		if (numbers.length()>0)
		{
			// ���������� ������������ ����� � ������ � � �������
			max = numbers[0];
			id = 0;
			for (int j = 1; j < numbers.length(); j++)
			{
				if (int(max) <= int(numbers[j])) {
					max = numbers[j];
					id = j;
				}
			}
			// �������� ������ ������, ������� ���������� � ����� ������� ����� � ����� ����� ������� �������� ��������� �����
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