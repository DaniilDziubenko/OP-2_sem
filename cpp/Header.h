#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> readConsoleText();
vector<string> readFileText();
void printFileText(string src);
void inputText(vector<string>);
void inputText(string);
string changeFileText(vector<string>);