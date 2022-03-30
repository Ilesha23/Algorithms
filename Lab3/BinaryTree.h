#pragma once
using namespace std;

struct Node {
	Node* Left, * Right, * Parent;
	int number, group;
	string name;
	Node(string s, int num, int g) {
		name = s;
		number = num;
		group = g;
		Left = Right = Parent = nullptr;
	}
	Node(){}
};

class Tree {
public:
	Node* Root;
	int count, tabs;
	Tree() {
		Root = nullptr;
		count = tabs =0;
	}
	void add(string n, int num, int g) {
		/*if (!Root)
		{
			Node* temp = new Node;
			temp->name = n;
			temp->number = num;
			temp->group = g;
			temp->Left = nullptr;
			temp->Right = nullptr;
			Root = temp;
		}
		else if()
		{

		}
		else
		{

		}*/
		Node* temp = new Node(n, num, g);
		Node* ptr,* ptr1;
		ptr = ptr1 = Root;
		while (ptr != 0)
		{
			ptr1 = ptr;
			if (temp->number < ptr->number)
			{
				ptr = ptr->Left;
			}
			else
			{
				ptr = ptr->Right;
			}
		}
		temp->Parent = ptr1;
		if (ptr1 == 0)
		{
			Root = temp;
		}
		else
		{
			if (temp->number < ptr1->number)
			{
				ptr1->Left = temp;
			}
			else
			{
				ptr1->Right = temp;
			}
		}
		count++;
	}
	void showForward(Node* n) {
		if (n != 0)
		{
			tabs++;
			showForward(n->Right);
			for (int i = 0; i < tabs; i++) cout << "	";
			cout << n->number << endl;// n->name << " " << n->number << " " << n->group << endl;
			showForward(n->Left);
			tabs--;
		}
	}
	void showF(Node* n) {
		if (n != 0)
		{
			cout << n->number << endl;// n->name << " " << n->number << " " << n->group << endl;
			showF(n->Left);
			showF(n->Right);
		}
	}
	void showBackward(Node* n) {
		if (n != 0)
		{
			showBackward(n->Right);
			showBackward(n->Left);
			for (int i = 0; i < tabs; i++) cout << "	";
			cout << n->number << endl;// n->name << " " << n->number << " " << n->group << endl;
		}
	}
	void showSymmetrically(Node* n) {
		if (n != 0)
		{
			showSymmetrically(n->Left);
			for (int i = 0; i < tabs; i++) cout << "	";
			cout << n->number << endl;// n->name << " " << n->number << " " << n->group << endl;
			showSymmetrically(n->Right);
		}
	}
	void show() {
		showForward(Root);
	}
};