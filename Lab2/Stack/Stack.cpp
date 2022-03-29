#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Stack.h"
using namespace std;

int main()
{
	Stack s;

	int w, a = 0;
	do
	{
		s.show();
		cout << endl << setw(30) << "Push - 1" << endl; cout << setw(30) << "Pop - 2" << endl; cout << setw(30) << "Pop by index - 3" << endl; cout << setw(30) << "Pop all - 4" << endl; cout << setw(30) << "Pop every second - 5" << endl; cout << setw(30) << "Swap first last - 6" << endl; cout << setw(30) << "Turn over - 7" << endl; cout << setw(30) << "Show star - 8" << endl; cout << setw(30) << "Find max - 9" << endl; cout << setw(30) << "Find min - 10" << endl; cout << setw(30) << "Insert zero after max - 11" << endl; cout << setw(30) << "Delete min - 12" << endl; cout << setw(30) << "Delete all but first - 13" << endl; cout << setw(30) << "Delete all but last - 14" << endl; cout << setw(30) << "Save to file - 15" << endl;
		cout << setw(30) << "Insert from file - 16" << endl;		
		cout << "> "; cin >> w;
		switch (w)
		{
		case 1:
			cout << "Enter number: ";
			cin >> a;
			cout << endl;
			s.push(a);
			break;
		case 2:
			s.pop();
			cout << endl;
			break;
		case 3:
			cout << "Enter number: ";
			cin >> a;
			cout << endl;
			s.pop(a);
			break;
		case 4:
			s.popAll();
			cout << endl;
			break;
		case 5:
			s.popEverySecond();
			cout << endl;
			break;
		case 6:
			s.swapFirstLast();
			cout << endl;
			break;
		case 7:
			s.turnOver();
			cout << endl;
			break;
		case 8:
			s.showStar();
			cout << endl;
			break;
		case 9:
			cout << endl << "Max is: " << s.findMax()->data << endl;
			cout << endl;
			break;
		case 10:
			cout << endl << "Max is: " << s.findMin()->data << endl;
			cout << endl;
			break;
		case 11:
			s.insertZeroAfterMax();
			cout << endl;
			break;
		case 12:
			s.deleteMin();
			cout << endl;
			break;
		case 13:
			s.deleteAllButFirst();
			cout << endl;
		case 14:
			s.deleteAllButLast();
			cout << endl;
			break;
		case 15:
			s.saveToFile("Stack.txt");
			cout << endl << "Saved!" << endl;
			break;
		case 16:
			s.insertFromFile("Stack.txt");
			cout << endl;
			break;
		default:
			break;
		}
	} while (w <= 16 && w >= 1);

	return 0;
}