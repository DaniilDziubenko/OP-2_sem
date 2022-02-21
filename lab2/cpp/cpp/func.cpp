#include "Header.h"

// Ввод списка клиентов с клаватуры
vector<string> readConsoleText(vector<string> & listOfTimes) {
	vector<string> text;
	vector<string> times;
	vector<string> durations;
	string line, name, surname, time, duration;
	char flag = 'y';

	while (flag == 'y')
	{
		// Ввод имени клиента
		cout << "Enter a name of client: ";
		cin >> name;
		// Проверка имени клиента
		name = checkInf(name);

		// Ввод фамилии клиента
		cout << "Enter a surname of client: ";
		cin >> surname;
		// Проверка фамилии клиента
		surname = checkInf(surname);

		// Ввод времени записи
		cout << "Enter a time of client: ";
		cin >> time;
		// Проверка времени записи
		time = checkTime(times, durations, time);
		times.push_back(time);

		// Ввод длительности процедуры
		cout << "Enter a duration of the procedure in this format HH:MM : ";
		cin >> duration;
		// Проверка длительности процедуры
		duration = checkDuration(times, durations, duration);
		durations.push_back(duration);

		// Формирование строки
		line = name + ' ' + surname + ", " + time + ", duration: " + duration + ";";
		text.push_back(line);

		// Условие остановки ввода списка
		cout << "\nDo you want to continue input clients?[y/n]: ";
		cin >> flag;
	}
	listOfTimes = times;
	return text;
}

// Проверка имени/фамилии
string checkInf(string in) {
	// Проверка на наличие цифр
	bool dig = checkDig(in);
	// Проверка имени/фамилии
	while (in.length() > 20 or in.length() <= 1 or dig)
	{
		cout << "Enter a name/surname again: ";
		cin >> in;
		dig = checkDig(in);
	}
	return in;
}

// Проверка времени записи
string checkTime(vector<string> times, vector<string> durations, string time) {
	bool flag = false, flag_times = false, flag_durations = false;
	// Базовая проверка времени на формат
	flag = checkBasic(time);
	if (flag == false)
	{
		// Проверка времени на совпадение с уже существующей записью
		flag_times = checkTimes(times, time);
		if (flag_times == false)
		{
			// Проверка длительности процедуры на наличие времени у мастера
			flag_durations = checkDurations(times, durations, time);
		}
	}
	// Проверка времени записи
	while (time.length() != 5 or time[2] != ':' or flag or flag_times or flag_durations)
	{
		cout << "Enter a time again: ";
		cin >> time;
		flag = checkBasic(time);
		if (flag == false)
		{
			flag_times = checkTimes(times, time);
			if (flag_times == false)
			{
				flag_durations = checkDurations(times, durations, time);
			}
		}
	}
	return time;
}

// Проверка длительности процедуры
string checkDuration(vector<string> times, vector<string> durations, string duration) {
	// Базовая проверка длительности на формат
	bool flag = checkBasic(duration);
	bool flag_duration = false;
	if (flag == false)
	{
		// Проверка длительности процедуры на наличие этого времени у мастера
		flag_duration = checkDurationDeep(times, duration);
	}
	// Проверка длительности процедуры
	while (duration.length() != 5 or duration[2] != ':' or flag or flag_duration)
	{
		cout << "Enter a duration again: ";
		cin >> duration;
		flag = checkBasic(duration);
		if (flag == false)
		{
			flag_duration = checkDurationDeep(times, duration);
		}
	}
	return duration;
}

// Базовая проверка времени на формат
bool checkBasic(string line) {
	bool flag = false;
	if (line.length() == 5 and line[2] == ':')
	{
		// Проверка времени на введенные символы
		flag = checkTimeDeep(line);
	}
	return flag;
}

// Проверка длительности процедуры на наличие этого времени у мастера
bool checkDurationDeep(vector<string> times, string duration) {
	vector<string> biggerTime;
	bool flag = false;
	if (times.size() > 1)
	{
		string last = times[times.size() - 1];
		// Создаём массив из записей, которые идут после этой
		for (int i = 0; i < times.size() - 1; i++)
		{
			if (stoi(times[i].substr(0,2)) > stoi(last.substr(0,2)) or ((stoi(times[i].substr(0, 2)) == stoi(last.substr(0, 2))) and (stoi(times[i].substr(3, 2)) > stoi(last.substr(3, 2)))))
			{
				biggerTime.push_back(times[i]);
			}
		}
		if (biggerTime.size()>0)
		{
			// Ищем ближайшую следующую запись и проверяем хватает ли времени
			string min = findMinTime(biggerTime);
			if ((stoi(last.substr(0,2)) + stoi(duration.substr(0,2))) > stoi(min.substr(0, 2)) or ((stoi(last.substr(0, 2)) + stoi(duration.substr(0, 2))) == stoi(min.substr(0, 2)) and ((stoi(last.substr(3, 2)) + stoi(duration.substr(3, 2))) > stoi(min.substr(3, 2)))))
			{
				flag = true;
			}
		}
	}
	return flag;
}

// Ищем ближайшую следующую запись
string findMinTime(vector<string> biggerTime) {
	string min = biggerTime[0];
	for (int i = 1; i < biggerTime.size(); i++)
	{
		if (stoi(min.substr(0,2)) > stoi(biggerTime[i].substr(0,2)) or ((stoi(min.substr(0, 2)) == stoi(biggerTime[i].substr(0, 2))) and (stoi(min.substr(3, 2)) > stoi(biggerTime[i].substr(3, 2))))) {
			min = biggerTime[i];
		}
	}
	return min;
}

// Проверка времени на совпадение с уже существующей записью
bool checkTimes(vector<string> times, string time) {
	bool flag = false;
	for (int i = 0; i < times.size(); i++)
	{
		if (times[i] == time) {
			flag = true;
			break;
		}
	}
	return flag;
}

// Проверка длительности процедуры на наличие времени у мастера
bool checkDurations(vector<string> times, vector<string> durations, string time) {
	bool flag = false;
	for (int i = 0; i < times.size(); i++)
	{
		if (((stoi(time.substr(0,2)) < stoi(times[i].substr(0, 2))) or (stoi(time.substr(0, 2)) == stoi(times[i].substr(0, 2)) and stoi(time.substr(3, 2)) <= stoi(times[i].substr(3, 2)))) or ((stoi(time.substr(0, 2)) > (stoi(times[i].substr(0, 2))) + stoi(durations[i].substr(0, 2))) or (stoi(time.substr(0, 2)) == (stoi(times[i].substr(0, 2)) + stoi(durations[i].substr(0, 2))) and stoi(time.substr(3, 2)) >= (stoi(times[i].substr(3, 2)) + stoi(durations[i].substr(3, 2)))))) {
			flag = false;
			//break;
		}
		else
		{
			flag = true;
			break;
		}
	}
	return flag;
}

// Проверка времени на введенные символы
bool checkTimeDeep(string time) {
	string hours = time.substr(0, 2);
	string minutes = time.substr(3, 2);
	// Проверка времени на корректность
	bool flag = false;
	if (isdigit(hours[0]) and isdigit(hours[1]))
	{
		if (stoi(hours) > 24)
		{
			flag = true;
		}
	}
	if (isdigit(minutes[0]) and isdigit(minutes[1]))
	{
		if (stoi(minutes) > 59)
		{
			flag = true;
		}
	}
	return flag;
}

// Проверка на наличие цифр
bool checkDig(string in) {
	bool dig = false;
	for (int i = 0; i < in.length(); i++)
	{
		if (isdigit(in[i])) {
			dig = true;
			break;
		}
	}
	return dig;
}

// Запись текста в бинарный файл
void inputFileText(vector<string> text, string path){
	ofstream file(path, ios::binary);
	for (int i = 0; i < text.size(); i++)
	{
		file << text[i] << "\n";
	}
	file.close();
}

// Чтение текста с бинарного файла
vector<string> readFileText() {
	vector<string> text;
	ifstream file("input.dot", ios::binary);
	string i;
	while (getline(file,i))
	{
		text.push_back(i);
	}
	file.close();
	return text;
}

// Создание нового текста, который содержит нужные элементы
vector<string> changeText(vector<string> fileText, vector<string> listOfTimes) {
	vector<string> text;
	for (int i = 0; i < listOfTimes.size(); i++)
	{
		if (stoi(listOfTimes[i].substr(0, 2)) > 16 or (stoi(listOfTimes[i].substr(0,2)) == 16 and stoi(listOfTimes[i].substr(3,2)) > 30)) {
			text.push_back(fileText[i]);
		}
	}
	return text;
}

// Вывод содержимого бинарного файла
void printFileText(string path) {
	ifstream file(path, ios::binary);
	string i;
	while (getline(file, i))
	{
		cout << i << endl;
	}
	file.close();
}