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
	list.showForward();
	/*list.del(2);
	list.showForward();*/
	list.swap(1);
	list.showForward();
}
