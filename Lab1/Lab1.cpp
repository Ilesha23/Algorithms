#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List list;
	for (int i = 1; i < 11; i++)
	{
		list.insert(i);
	}
	//list.showBackward();
	//list.showForward();
	/*list.del(2);
	list.showForward();*/
	//list.swapptr(5);
	//list.showForward();

	List list2;
	list2.insert(3);
	list2.insert(4);
	list2.insert(5);
	list2.insert(6);
	list2.showForward();
	list.combine(list2);
	list.showForward();
}
