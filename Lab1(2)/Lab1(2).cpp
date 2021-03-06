#include <iostream>
#include <iomanip>
#include <conio.h>
#include "List.h"
using namespace std;

int main()
{
	List list1;
	List list2;

	int w, a = 0;
	do
	{
		cout << endl << setw(30) << "Insert - 1" << endl; cout << setw(30) << "Delete element - 2" << endl; cout << setw(30) << "Delete all list - 3" << endl; cout << setw(30) << "Swap data - 4" << endl; cout << setw(30) << "Swap using pointers - 5" << endl; cout << setw(30) << "Show forward - 6" << endl; cout << setw(30) << "Show backward - 7" << endl; cout << setw(30) << "Create 2nd list - 8" << endl; cout << setw(30) << "Combine two lists - 9" << endl; cout << setw(30) << "Insert from file to list1 - 10" << endl; cout << setw(30) << "Insert from file to list2 - 11" << endl; cout << setw(30) << "Save to file - 12" << endl;
		cout << "> "; cin >> w;
		switch (w)
		{
		case 1:
			cout << "Enter number: ";
			cin >> a;
			list1.insert(a);

			//system("cls");
			break;
		case 2:
			cout << "Enter number of element: ";
			cin >> a;
			list1.del(a);

			//system("cls");
			break;
		case 3:
			list1.delAllList();
			//system("cls");
			break;
		case 4:
			cout << "Enter number of element to swap with next: ";
			cin >> a;
			list1.swap(a);
			//system("cls");
			break;
		case 5:
			cout << "Enter number of element to swap with next: ";
			cin >> a;
			list1.swapptr(a);
			//system("cls");
			break;
		case 6:
			cout << "" << endl;
			list1.showForward();
			_getch();
			//system("cls");
			break;
		case 7:
			cout << "" << endl;
			list1.showBackward();
			_getch();
			//system("cls");
			break;
		case 8:
			cout << "How many elements do you want to add?: ";
			cin >> a; int b;
			cout << "Enter numbers: " << endl;
			for (int i = 0; i < a; i++)
			{
				cin >> b;
				list2.insert(b);
			}
			//system("cls");
			break;
		case 9:
			list1.combine(list2);
			cout << "Combined!" << endl;
			_getch();
			//system("cls");
			break;
		case 10:
			list1.insertFromFile("list1.txt");
			//system("cls");
			break;
		case 11:
			list2.insertFromFile("list2.txt");
			//system("cls");
			break;
		case 12:
			list1.saveToFile("list3.txt");
			//system("cls");
			break;
		default:
			break;
		}
	} while (w <= 12 && w >= 1);

	return 0;
}