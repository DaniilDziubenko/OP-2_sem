#pragma once
#include <iostream>
#include <string>
using namespace std;

class Tree {
public:

	char data;
	int count;
	Tree* left, * right;

	Tree(char ch, int c, Tree* l = nullptr, Tree* r = nullptr) :data(ch), count(c), left(l), right(r) {};
	~Tree();

};