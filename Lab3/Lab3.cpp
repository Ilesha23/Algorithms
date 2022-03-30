#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
	Tree t;
	t.add("def", 3213, 4324);
	t.add("abc", 3123123, 5435345);
	t.add("ghj", 3123123, 5435345);
	t.show(t.Root);
	return 0;
}