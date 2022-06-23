#pragma once
#include "Tree.h"

Tree* createTree();
void insert(Tree*&, char, int);
void printTree(Tree*, int);
bool contains(Tree*, char);
void recursionDestructor(Tree*);
bool validateString(string);