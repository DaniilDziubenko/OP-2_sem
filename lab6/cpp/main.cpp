#include "Tree.h"
#include "func.h"

int main() {

	Tree* tree;
	tree = createTree();

	cout << "\nResulting binary tree:\n";
	printTree(tree, 0);

	system("pause");
	return 0;
}