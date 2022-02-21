#include "Header.h"

// ���� ������ �������� � ���������
vector<string> readConsoleText(vector<string> & listOfTimes) {
	vector<string> text;
	vector<string> times;
	vector<string> durations;
	string line, name, surname, time, duration;
	char flag = 'y';

	while (flag == 'y')
	{
		// ���� ����� �������
		cout << "Enter a name of client: ";
		cin >> name;
		// �������� ����� �������
		name = checkInf(name);

		// ���� ������� �������
		cout << "Enter a surname of client: ";
		cin >> surname;
		// �������� ������� �������
		surname = checkInf(surname);

		// ���� ������� ������
		cout << "Enter a time of client: ";
		cin >> time;
		// �������� ������� ������
		time = checkTime(times, durations, time);
		times.push_back(time);

		// ���� ������������ ���������
		cout << "Enter a duration of the procedure in this format HH:MM : ";
		cin >> duration;
		// �������� ������������ ���������
		duration = checkDuration(times, durations, duration);
		durations.push_back(duration);

		// ������������ ������
		line = name + ' ' + surname + ", " + time + ", duration: " + duration + ";";
		text.push_back(line);

		// ������� ��������� ����� ������
		cout << "\nDo you want to continue input clients?[y/n]: ";
		cin >> flag;
	}
	listOfTimes = times;
	return text;
}

// �������� �����/�������
string checkInf(string in) {
	// �������� �� ������� ����
	bool dig = checkDig(in);
	// �������� �����/�������
	while (in.length() > 20 or in.length() <= 1 or dig)
	{
		cout << "Enter a name/surname again: ";
		cin >> in;
		dig = checkDig(in);
	}
	return in;
}

// �������� ������� ������
string checkTime(vector<string> times, vector<string> durations, string time) {
	bool flag = false, flag_times = false, flag_durations = false;
	// ������� �������� ������� �� ������
	flag = checkBasic(time);
	if (flag == false)
	{
		// �������� ������� �� ���������� � ��� ������������ �������
		flag_times = checkTimes(times, time);
		if (flag_times == false)
		{
			// �������� ������������ ��������� �� ������� ������� � �������
			flag_durations = checkDurations(times, durations, time);
		}
	}
	// �������� ������� ������
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

// �������� ������������ ���������
string checkDuration(vector<string> times, vector<string> durations, string duration) {
	// ������� �������� ������������ �� ������
	bool flag = checkBasic(duration);
	bool flag_duration = false;
	if (flag == false)
	{
		// �������� ������������ ��������� �� ������� ����� ������� � �������
		flag_duration = checkDurationDeep(times, duration);
	}
	// �������� ������������ ���������
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

// ������� �������� ������� �� ������
bool checkBasic(string line) {
	bool flag = false;
	if (line.length() == 5 and line[2] == ':')
	{
		// �������� ������� �� ��������� �������
		flag = checkTimeDeep(line);
	}
	return flag;
}

// �������� ������������ ��������� �� ������� ����� ������� � �������
bool checkDurationDeep(vector<string> times, string duration) {
	vector<string> biggerTime;
	bool flag = false;
	if (times.size() > 1)
	{
		string last = times[times.size() - 1];
		// ������ ������ �� �������, ������� ���� ����� ����
		for (int i = 0; i < times.size() - 1; i++)
		{
			if (stoi(times[i].substr(0,2)) > stoi(last.substr(0,2)) or ((stoi(times[i].substr(0, 2)) == stoi(last.substr(0, 2))) and (stoi(times[i].substr(3, 2)) > stoi(last.substr(3, 2)))))
			{
				biggerTime.push_back(times[i]);
			}
		}
		if (biggerTime.size()>0)
		{
			// ���� ��������� ��������� ������ � ��������� ������� �� �������
			string min = findMinTime(biggerTime);
			if ((stoi(last.substr(0,2)) + stoi(duration.substr(0,2))) > stoi(min.substr(0, 2)) or ((stoi(last.substr(0, 2)) + stoi(duration.substr(0, 2))) == stoi(min.substr(0, 2)) and ((stoi(last.substr(3, 2)) + stoi(duration.substr(3, 2))) > stoi(min.substr(3, 2)))))
			{
				flag = true;
			}
		}
	}
	return flag;
}

// ���� ��������� ��������� ������
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

// �������� ������� �� ���������� � ��� ������������ �������
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

// �������� ������������ ��������� �� ������� ������� � �������
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

// �������� ������� �� ��������� �������
bool checkTimeDeep(string time) {
	string hours = time.substr(0, 2);
	string minutes = time.substr(3, 2);
	// �������� ������� �� ������������
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

// �������� �� ������� ����
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

// ������ ������ � �������� ����
void inputFileText(vector<string> text, string path){
	ofstream file(path, ios::binary);
	for (int i = 0; i < text.size(); i++)
	{
		file << text[i] << "\n";
	}
	file.close();
}

// ������ ������ � ��������� �����
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

// �������� ������ ������, ������� �������� ������ ��������
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

// ����� ����������� ��������� �����
void printFileText(string path) {
	ifstream file(path, ios::binary);
	string i;
	while (getline(file, i))
	{
		cout << i << endl;
	}
	file.close();
}