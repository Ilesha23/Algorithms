#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Deque.h"
using namespace std;

int main()
{
	Deque d;
	
	int w, a = 0;
	do
	{
		d.show();
		cout << endl << setw(30) << "Push back - 1" << endl; cout << setw(30) << "Push front - 2" << endl; cout << setw(30) << "Pop front - 3" << endl; cout << setw(30) << "Pop back - 4" << endl; cout << setw(30) << "Pop all - 5" << endl; cout << setw(30) << "Get front - 6" << endl; cout << setw(30) << "Get back - 7" << endl; cout << setw(30) << "Get by index - 8" << endl; cout << setw(30) << "Is empty? - 9" << endl; cout << setw(30) << "Insert from file - 10" << endl; cout << setw(30) << "Save to file - 11" << endl;
		cout << "> "; cin >> w;
		switch (w)
		{
		case 1:
			cout << "Enter number: ";
			cin >> a;
			cout << endl;
			d.push_back(a);
			break;
		case 2:
			cout << "Enter number: ";
			cin >> a;
			cout << endl;
			d.push_front(a);
			break;
		case 3:
			cout << endl;
			d.pop_front();
			break;
		case 4:
			cout << endl;
			d.pop_back();
			break;
		case 5:
			d.popAll();
			cout << endl;
			break;
		case 6:
			cout << endl << "Front is: " << d.getFront() << endl;
			break;
		case 7:
			cout << endl << "Front is: " << d.getBack() << endl;
			break;
		case 8:
			cout << "Enter index: ";
			cin >> a;
			cout << endl << "Element is: " << d.get(a) << endl;
			cout << endl;
			break;
		case 9:
			if (d.isEmpty())
			{
				cout << endl << "Empty" << endl;
			}
			else
			{
				cout << endl << "Not empty" << endl;
			}
			break;
		case 10:
			d.insertFromFile("Deque.txt");
			cout << endl;
			break;
		case 11:
			d.saveToFile("Deque.txt");
			cout << "Saved!" << endl;
			break;
		default:
			break;
		}
	} while (w <= 11 && w >= 1);

	return 0;

}