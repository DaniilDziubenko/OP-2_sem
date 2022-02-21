#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> readConsoleText(vector<string> & listOfTimes);
vector<string> changeText(vector<string>, vector<string>);
vector<string> readFileText();
string checkInf(string);
string checkTime(vector<string>, vector<string>, string);
string checkDuration(vector<string>, vector<string>, string);
string findMinTime(vector<string>);
bool checkBasic(string);
bool checkDurationDeep(vector<string>, string);
bool checkTimes(vector<string>, string);
bool checkDurations(vector<string>, vector<string>, string);
bool checkTimeDeep(string);
bool checkDig(string);
void printFileText(string path);
void inputFileText(vector<string>, string path);