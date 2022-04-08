#include <iostream>
#include "BinaryTree.h"
#include "RBTree.h"

using namespace std;

int main()
{
	Tree t;
	RBTree rb;

	int num, g;
	string name;
	int w, a = 0;
	do
	{
		t.show();
		cout << endl << endl;
		rb.p();
		cout << endl << setw(30) << "Add - 1" << endl;
		cout << setw(30) << "Pre-order walk - 2" << endl;
		cout << setw(30) << "Post order walk - 3" << endl;
		cout << setw(30) << "Symmetrical walk - 4" << endl;
		cout << setw(30) << "Delete tree - 5" << endl;
		cout << setw(30) << "Delete left tree - 6" << endl;
		cout << setw(30) << "Delete right tree - 7" << endl;
		cout << setw(30) << "Make tree by another key- 8" << endl;
		cout << setw(30) << "Add by num - 9" << endl;
		cout << setw(30) << "Colorize tree to RB - 10" << endl;
		cout << setw(30) << "Add - 11" << endl;
		cout << setw(30) << "Delete - 12" << endl;
		cout << setw(30) << "Add from file - 13" << endl;
		cout << setw(30) << "Save to file - 14" << endl;
		cout << "> "; cin >> w;
		switch (w)
		{
		case 1:
			cout << "Enter name: "; cin >> name;
			cout << "Enter number: "; cin >> num;
			cout << "Enter group: "; cin >> g;
			t.add(name, num, g);
			break;
		case 2:
			t.showPreOrder();
			break;
		case 3:
			t.showPostOrder();
			break;
		case 4:
			t.showSymm();
			break;
		case 5:
			t.delTree();
			break;
		case 6:
			t.delLeftTree();
			break;
		case 7:
			t.delRightTree();
			break;
		case 8:
			t.remake();
			break;
		case 9:
			cout << "Enter name: "; cin >> name;
			cout << "Enter number: "; cin >> num;
			cout << "Enter group: "; cin >> g;
			t.addByN(name, num, g);
			break;
		case 10:
			rb.makeRB(t);
			break;
		case 11:
			cout << "Enter name: "; cin >> name;
			cout << "Enter number: "; cin >> num;
			cout << "Enter group: "; cin >> g;
			rb.insert(num, g, name);
			break;
		case 12:
			cout << "Enter name: "; cin >> name;
			cout << "Enter number: "; cin >> num;
			cout << "Enter group: "; cin >> g;
			rb.remove(num, g, name);
			break;
		case 13:
			t.readFromFile("1.txt");
		case 14:
			t.saveToFile("1.txt");
			cout << "Saved" << endl;
			break;
		default:
			break;
		}
	} while (w <= 14 && w >= 1);

	return 0;
}