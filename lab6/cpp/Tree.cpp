#include "Tree.h"
#include "func.h"

Tree::~Tree() {
	recursionDestructor(left);
	recursionDestructor(right);
}