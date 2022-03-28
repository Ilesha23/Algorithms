#include <iostream>
#include "Deque.h"
using namespace std;

int main()
{
	Deque d;
	/*d.push_front(1);
	d.push_front(2);
	d.push_front(3);
	d.push_front(4);*/
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);

	d.show();
}