#include "func.h"

Tree* createTree() {
	int count;
	Tree* root = nullptr;
	string str;
	cout << "Enter string of symbols separated by one space:\n";
	getline(cin, str);
	while (!validateString(str)) {
		cout << "\nInvalid input string!\nEnter string again:\n";
		getline(cin, str);
	}
	for (int i = 0; i < str.length(); i++) {
		count = 0;
		if (str[i] != ' ' && !contains(root, str[i])) {
			for (int j = 0; j < str.length(); j++)
			{
				if (str[i] == str[j]) {
					count++;
				}
			}
			insert(root, str[i], count);
		}
	}
	return root;
}

bool validateString(string str) {
	if (str.length() >= 1) {
		for (int i = 0; i < str.length(); i++) {
			if (i % 2 == 0 && (str[i] == ' ' || str[i] < 65 || str[i] > 122 || (str[i] > 90 && str[i] < 97))) {
				return false;
			}
			else if (i % 2 != 0 && str[i] != ' ') {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

void insert(Tree*& tree, char ch, int count) {
	if (tree == nullptr) tree = new Tree(ch, count);
	else {
		if (tree->data < ch) insert(tree->right, ch, count);
		else insert(tree->left, ch, count);
	}
}

bool contains(Tree* tree, char ch) {
	if (tree == nullptr) return false;
	if (tree->data == ch) return true;
	if (tree->data < ch) return contains(tree->right, ch);
	if (tree->data > ch) return contains(tree->left, ch);
}

void printTree(Tree* tree, int count) {
	if (tree != nullptr) {
		string space = " ";
		for (int i = 0; i < count; i++)
		{
			space += "   ";
		}
		printTree(tree->right, count + 1);
		cout << space << tree->count << " " << tree->data << endl;
		printTree(tree->left, count + 1);
	}
}

void recursionDestructor(Tree* current) {
	if (current->right) recursionDestructor(current->right);
	if (current->left) recursionDestructor(current->left);
	delete current;
}