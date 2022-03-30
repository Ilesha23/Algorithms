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
	int count;
	Tree() {
		Root = nullptr;
		count = 0;
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
			if (temp->name < ptr->name)
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
			if (temp->name < ptr1->name)
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
	void show(Node* n) {
		if (n != 0)
		{
			show(n->Left);
			cout << n->name << endl;
			cout << n->number << endl;
			cout << n->group << endl << endl;
			show(n->Right);
		}
	}
};