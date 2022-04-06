#include <iostream>
#include "BinaryTree.h"
#include "RBTree.h"

using namespace std;

int main()
{
	Tree t;
	RBTree rb;
	/*t.add("555", 5, 555);
	t.add("222", 2, 222);
	t.add("333", 3, 333);
	t.add("111", 1, 111);
	t.add("444", 4, 444);
	t.add("777", 7, 777);
	t.add("666", 6, 666);
	t.add("888", 8, 888);
	t.show();
	t.saveToFile("1.txt");*/
	/*t.readFromFile("1.txt");
	t.show();
	rb.makeRB(t);
	rb.p();*/

	/*int w, a = 0;
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
	} while (w <= 16 && w >= 1);*/

	/*t.add("555", 5, 555);
	t.add("222", 2, 222);
	t.add("333", 3, 333);
	t.add("111", 1, 111);
	t.add("444", 4, 444);
	t.add("777", 7, 777);
	t.add("666", 6, 666);
	t.add("888", 8, 888);
	t.show();
	cout << endl;*/

	
	/*rb.insert(5, 555, "555");
	rb.insert(2, 222, "222");
	rb.insert(3, 333, "333");
	rb.insert(1, 111, "111");
	rb.insert(4, 444, "444");
	rb.insert(7, 777, "777");
	rb.insert(6, 666, "666");
	rb.insert(8, 888, "888");*/
	/*rb.makeRB(t);
	rb.p();
	rb.postOrder();
	cout << endl;
	rb.preOrder();
	cout << endl;
	rb.inOrder();*/
	return 0;
}