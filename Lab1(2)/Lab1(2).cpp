#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List list;
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);

	List list2;
	list2.insert(6);
	list2.insert(7);
	list2.insert(8);

	//list.combine(list2);
	list.swapptr(2);

	list.showForward();

	
	return 0;
}