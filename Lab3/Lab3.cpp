#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
	Tree t;
	t.add("def", 5, 555);
	t.add("abc", 2, 222);
	t.add("aab", 3, 333);
	t.add("ghj", 1, 111);
	t.add("asc", 4, 444);
	t.add("bfd", 7, 777);
	t.add("iyu", 6, 666);
	t.add("dsa", 8, 888);
	//t.delRightTree();
	//t.delTree();
	t.show();
	t.remake(); cout << endl;
	t.show();
	return 0;
}