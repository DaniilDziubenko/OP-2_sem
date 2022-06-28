#include "Tree.h"
#include "func.h"

Tree::~Tree() {
	recursionDestructor(right);
	recursionDestructor(left);
}