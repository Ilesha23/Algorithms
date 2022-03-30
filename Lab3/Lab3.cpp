#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
	Tree t;
	t.add("def", 5, 432);
	t.add("abc", 2, 254);
	t.add("aab", 3, 254);
	t.add("ghj", 1, 543);
	t.add("asc", 4, 234);
	t.add("bfd", 7, 534);
	t.add("iyu", 6, 543);
	t.add("dsa", 8, 423);
	t.show();
	return 0;
}