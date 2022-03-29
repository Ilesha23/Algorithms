#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Queue.h"
using namespace std;

int main()
{
	Queue q;

	int w, a = 0;
	do
	{
		q.show();
		cout << endl << setw(30) << "Push - 1" << endl; cout << setw(30) << "Pop - 2" << endl; cout << setw(30) << "Pop all - 3" << endl; cout << setw(30) << "Get element - 4" << endl; cout << setw(30) << "Average - 5" << endl; cout << setw(30) << "Find min - 6" << endl; cout << setw(30) << "Find max - 7" << endl; cout << setw(30) << "Show before min - 8" << endl; cout << setw(30) << "Save to file - 9" << endl; cout << setw(30) << "Insert from file - 10" << endl;
		cout << "> "; cin >> w;
		switch (w)
		{
		case 1:
			cout << "Enter number: ";
			cin >> a;
			cout << endl;
			q.push(a);
			break;
		case 2:
			q.pop();
			cout << endl;
			break;
		case 3:
			cout << "Enter number: ";
			cin >> a;
			cout << endl;
			q.popAll();
			break;
		case 4:
			q.getElem();
			cout << endl;
			break;
		case 5:
			cout << "Average is: " << q.average() << endl;
			cout << endl;
			break;
		case 6:
			cout << "Min is: " << q.findMin()->data << endl;
			cout << endl;
			break;
		case 7:
			cout << "Max is: " << q.findMax()->data << endl;
			cout << endl;
			break;
		case 8:
			q.showBeforeMin();
			cout << endl;
			break;
		case 9:
			q.saveToFile("Queue.txt");
			cout << "Saved!" << endl;
			break;
		case 10:
			q.insertFromFile("Queue.txt");
			cout << endl;
			break;
		default:
			break;
		}
	} while (w <= 10 && w >= 1);

	return 0;
}
