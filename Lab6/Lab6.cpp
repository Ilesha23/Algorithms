#include <iostream>
#include "HashTable.h"
using namespace std;

int main()
{
	HashTable ht(20);

	int w, a = 0, b = 0;
	do
	{
		cout << endl;
		ht.Print();
		cout << endl << setw(15) << "Add - 1" << endl;
		cout << setw(15) << "Insert - 2" << endl;
		cout << setw(15) << "Search - 3" << endl;
		cout << setw(15) << "Delete - 4" << endl;
		cout << "> "; cin >> w;
		switch (w)
		{
		case 1:
			cout << "Enter: ";
			cin >> b;
			if (b == 1)
			{
				cout << "Enter number: ";
				cin >> a;
				cout << endl;
				ht.Add(a);
			}
			if (b == 2)
			{
				cout << "Enter number: ";
				cin >> a;
				cout << endl;
				ht.Add2(a);
			}
			if (b == 3)
			{
				cout << "Enter number: ";
				cin >> a;
				cout << endl;
				ht.Add3(a);
			}
			if (b == 4)
			{
				cout << "Enter number: ";
				cin >> a;
				cout << endl;
				ht.AddL(a);
			}
			break;
		case 2:
			cout << "Enter: ";
			cin >> b;
			if (b == 1)
			{
				ht.Insert();
			}
			if (b == 2)
			{
				ht.Insert2();
			}
			if (b == 3)
			{
				ht.Insert3();
			}
			if (b == 4)
			{
				ht.InsertL();
			}
			break;
		case 3:
			cout << "Enter: ";
			cin >> b;
			if (b == 1)
			{
				cout << "Enter number: ";
				cin >> a;
				cout << endl;
				ht.Search(a);
			}
			if (b == 2)
			{
				cout << "Enter number: ";
				cin >> a;
				cout << endl;
				ht.Search2(a);
			}
			if (b == 3)
			{
				cout << "Enter number: ";
				cin >> a;
				cout << endl;
				ht.Search3(a);
			}
			if (b == 4)
			{
				cout << "Enter number: ";
				cin >> a;
				cout << endl;
				ht.SearchL(a);
			}
			break;
		case 4:
			cout << "Enter: ";
			cin >> b;
			if (b == 1)
			{
				cout << "Enter number: ";
				cin >> a;
				cout << endl;
				ht.Delete(a);
			}
			if (b == 2)
			{
				cout << "Enter number: ";
				cin >> a;
				cout << endl;
				ht.Delete2(a);
			}
			if (b == 3)
			{
				cout << "Enter number: ";
				cin >> a;
				cout << endl;
				ht.Delete3(a);
			}
			if (b == 4)
			{
				cout << "Enter number: ";
				cin >> a;
				cout << endl;
				ht.DeleteL(a);
			}
			break;
		default:
			break;
		}
	} while (w <= 4 && w >= 1);

}